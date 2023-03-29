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

int eval(std::string pref) {
  
    TStack <int, 100> stack2;
    char p = ' ';
    for (int i = 0; i < pref.length(); i++) {
        
        if (pref[i] == ch0 || pref[i] == ch1
          || pref[i] == ch2 || pref[i] == ch3 || pref[i] == ch4
          || pref[i] == ch5 || pref[i] == ch6 || pref[i] == ch7
          || pref[i] == ch8 || pref[i] == ch9) {
            char ch = pref[i];
            int arg = static_cast<int>(ch - '0');
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
    return stack2.pop();
}
