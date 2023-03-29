// Copyright 2021 NNTU-CS
#include <map>
#include "tstack.h"

char ch0 = '0', ch1 = '1', ch2 = '2', ch3 = '3', ch4 = '4', ch5 = '5',
ch6 = '6', ch7 = '7', ch8 = '8', ch9 = '9', chM = '-',
chP = '+', chD = '/', chMlt = '*', ch9Rsk = ')', ch9Lsk = '(';
int getPrior(char ch) {
    switch(ch) {
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
   TStack<char, 100> stack1;
   std::string out = "";
    for (int i = 0; i < inf.length(); i++) {
        if (inf[i] == ch0 || inf[i] == ch1 || inf[i] == ch2 || inf[i] == ch3
            || inf[i] == ch4 || inf[i] == ch5 || inf[i] == ch6 || inf[i] == ch7 
|| inf[i] == ch8 || inf[i] == ch9) {
            out += inf[i] + " ";
        }
        else if (inf[i] == ch9Lsk || stack1.isEmpty() 
|| getPrior(inf[i]) > getPrior(stack1.get())) {
            stack1.push(inf[i]);
        } else if (getPrior(inf[i] <= stack1.get())) {
                while (getPrior(inf[i] <= stack1.get()) && !stack1.isEmpty()) {
                    out +=  stack1.pop() + " ";
                }
                stack1.push(inf[i]);
            }
        /*else if (getPrior(inf[i]) <= getPrior(stack1.get())) {
            out += stack1.get() + " ";
            stack1.pop();
            if (stack1.get() == ch9Lsk) {
                stack1.pop();
            }
            if (inf[i]!=ch9Lsk) {
                stack1.push(inf[i]);
            }
        }*/
        
         else if (inf[i] == ch9Rsk) {
                char ch = stack1.pop();
                while (ch != ch9Lsk) {
                    out += ch + " ";
                    ch = stack1.pop();
                }
            } 
    }
    while (!stack1.isEmpty()) {
        if (stack1.get() == ch9Lsk) {
            stack1.pop();
        } else {
        out += stack1.get() + " ";
        stack1.pop();
        }
    }
    return out;
}

int eval(std::string pref) {
  TStack<int, 100> stack2;
  int result;
  char p = ' ';
  for (int i = 0; i < pref.length(); i++) {
      if (pref[i] == ch0 || pref[i] == ch1 || pref[i] == ch2 || pref[i] == ch3 
|| pref[i] == ch4
          || pref[i] == ch5 || pref[i] == ch6 || pref[i] == ch7 || pref[i] == ch8 
|| pref[i] == ch9) {
          int arg = 0;
          char ch = pref[i];
          arg = static_cast<int>(ch - '0');
          stack2.push(arg);
      }
      if (pref[i] == p) {
      continue;
      } 
      if (pref[i] == chM) {
          int arg1 = stack2.get();
          stack2.pop();
          int arg2 = stack2.get();
          stack2.pop();
          int res = arg1-arg2;
          stack2.push(res);
      }
      if (pref[i] == chP) {
          int arg1 = stack2.get();
          stack2.pop();
          int arg2 = stack2.get();
          stack2.pop();
          int res = arg1+arg2;
          stack2.push(res);
      }
      if (pref[i] == chMlt) {
          int arg1 = stack2.get();
          stack2.pop();
          int arg2 = stack2.get();
          stack2.pop();
          int res = arg1*arg2;
          stack2.push(res);
      }
      if (pref[i] == chD) {
          int arg1 = stack2.get();
          stack2.pop();
          int arg2 = stack2.get();
          stack2.pop();
          int res = arg1/arg2;
          stack2.push(res);
      }
  }
  result = stack2.get();
  stack2.pop();
  return result;
}
