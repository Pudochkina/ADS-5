// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

TStack<char, 100> stack1;
TStack<int, 100> stack2;
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
   std::string out = "";
    for (int i = 0; i < inf.size(); i++) {
        if (inf.at(i) == ch0 || inf.at(i) == ch1 || inf.at(i) == ch2 || inf.at(i) == ch3 || inf.at(i) == ch4 || inf.at(i) == ch5 || inf.at(i) == ch6 || inf.at(i) == ch7 || inf.at(i) == ch8 || inf.at(i) == ch9) {
            out += inf.at(i) + " ";
        }
        if ((inf.at(i) == ch9Lsk || inf.at(i) == ch9Rsk || inf.at(i) == chP || inf.at(i) == chM || inf.at(i) == chMlt || inf.at(i) == chD  && getPrior(inf.at(i)) > getPrior(stack1.get())) || stack1.isEmpty()) {
            stack1.push(inf.at(i));
        }
        if ((inf.at(i) == ch9Lsk || inf.at(i) == ch9Rsk || inf.at(i) == chP || inf.at(i) == chM || inf.at(i) == chMlt || inf.at(i) == chD) && (getPrior(inf.at(i)) <= getPrior(stack1.get()))) {
            out += stack1.pop() + " ";
            if (stack1.get() == ch9Lsk) {
                stack1.pop();
            }
        }
    }
    while (!stack1.isEmpty()) {
        if (stack1.get() == ch9Lsk) {
            stack1.pop();
        }
        out += stack1.pop() + " ";
    }
    return out;
}

int eval(std::string pref) {
  // добавьте код
  return 0;
}
