// Copyright 2021 NNTU-CS
#include <map>
#include "tstack.h"

int getPrior(char ch) {
    switch (ch) {
        case '(':
        return 0;
        case ')':
        return 1;
        case '+':
        return 2;
        case '-':
        return 2;
        case '*':
        return 3;
        case '/':
        return 3;
    }
    return -1;
}
std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stck1;
  std::string out = "";
  int res = 0;
  for (char s : inf) {
    bool flag = true;
    if (getPrior(s) == -1) {
      out += s;
      out += ' ';
      flag = false;
    }
    if (getPrior(s) == 0) {
      stck1.push(s);
      flag = false;
    }
    if (getPrior(s) > getPrior(stck1.pol())) {
      stck1.push(s);
      flag = false;
    }
    if (stck1.empty() && getPrior(s) != -1) {
      stck1.push(s);
      flag = false;
    }
    if (iter && s != ')') {
      while (getPrior(stck1.pol()) >= getPrior(s)) {
        out += stck1.pop();
        out += ' ';
      }
      stck1.push(s);
    }
    if (s == ')') {
      while (stck1.pol() != '(') {
        out += stck1.pop();
        out += ' ';
      }
      stck1.pop();
    }
    if (res == inf.size() - 1) {
      while (!stck1.empty()) {
        out += stck1.pop();
        if (stck1.pri() != -1) out += ' ';
      }
    }
    ++res;
  }
  return out;
}

int eval(std::string pref) {
  TStack<int, 100> stck2;
  for (char s : pref) {
    if (s == '+') {
      int tmp = stck2.pop();
      tmp = tmp + stck2.pop();
      stck2.push(tmp);
    }
    if (s == '-') {
      int tmp = stck2.pop();
      tmp = stck2.pop() - tmp;
      stck2.push(tmp);
    }
    if (s == '/') {
      int tmp = stck2.pop();
      tmp = stck2.pop() / tmp;
      stck2.push(tmp);
    }
    if (s == '*') {
      int tmp = stck2.pop();
      tmp = tmp * stck2.pop();
      stck2.push(tmp);
    }
    if (s == ' ') {
      continue;
    }
    if ((s - '0') > 0) {
      int tmp = s - '0';
      stck2.push(tmp);
    }
  }
  return stck2.pol();
}
