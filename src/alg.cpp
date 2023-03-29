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
//std::string infx2pstfx(std::string inf) {
//}
int eval(std::string pref) {
    TStack <int, 100> stack2;
    for (char ch : pref) {
        if (ch == ' ')
            continue;
        if (ch == ch0 || ch == ch1
          || ch == ch2 || ch == ch3 || ch== ch4
          || ch == ch5 || ch == ch6 || ch == ch7
          || ch == ch8 || ch == ch9) {
           int arg = static_cast<int>(ch - '0');
           stack2.push(arg);
        } 
          if (ch == chM) {
          int arg1 = stack2.get();
          stack2.pop();
          int arg2 = stack2.get();
          stack2.pop();
          int res = arg2-arg1;
          stack2.push(res);
      }
      if (ch == chP) {
          int arg1 = stack2.get();
          stack2.pop();
          int arg2 = stack2.get();
          stack2.pop();
          int res = arg1+arg2;
          stack2.push(res);
      }
      if (ch == chMlt) {
          int arg1 = stack2.get();
          stack2.pop();
          int arg2 = stack2.get();
          stack2.pop();
          int res = arg2*arg1;
          stack2.push(res);
      }
      if (ch == chD) {
          int arg1 = stack2.get();
          stack2.pop();
          int arg2 = stack2.get();
          stack2.pop();
          int res = arg2/arg1;
          stack2.push(res);
      }
    }
    return stack2.pop();
}
