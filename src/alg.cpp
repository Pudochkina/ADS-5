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
  for (char ch : inf) {
      if (ch == ch0 || ch == ch1 || ch == ch2 || ch == ch3
            || ch == ch4 || ch == ch5 || ch == ch6 || ch == ch7 
            || ch == ch8 || ch == ch9) {
       out += ch;
      } else if (ch == ch9Lsk) {
          stack1.push(ch);
      } else if (ch == ch9Rsk) {
      while (!stack1.isEmpty() && stack1.get() != ch9Lsk) {
        out += ' ';
        out += stack1.pop();
      }
      stack.pop();
      } else {
        while (!stack1.isEmpty() && stack1.top() != ch9Lsk
               && getPrior[ch] <= getPrior[stack1.get()]) {
        out += ' ';
        out += stack1.pop();
      }
      out += ' ';
      stack1.push(ch);
      }
  }
  while (!stack1.isEmpty()) {
    out += ' ';
    out += stack1.pop();
  }
      
}

//int eval(std::string pref) {
    
//}
