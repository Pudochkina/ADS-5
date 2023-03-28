// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

TStack<char, 100> stack1;
TStack<int, 100> stack2;

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
    // копируем символы строки inf в массив chars
    char chars[inf.length() + 1];
    inf.copy(chars, inf.length() + 1);
    for (int i = 0; i < chars.length(); i++) {
        if (chars[i] == "0" || chars[i] == "1"|| chars[i] == "2"|| chars[i] == "3"|| chars[i] == "4" || chars[i] == "5"|| chars[i] == "6"|| chars[i] == "7"|| chars[i] == "8"|| chars[i] == "9") {
            out += chars[i];
            //stack1.push(chars[i]);
        }
        if (chars[i] == "(" || chars[i] == ")" || chars[i] == "+" || chars[i] == "-" || chars[i] == "*" || chars[i] == "/" && getPrior(chars[i]) > getPrior(stack1.get()) || stack1.isEmpty()) {
            stack1.push(chars[i]);
        }
        if (chars[i] == "(" || chars[i] == ")" || chars[i] == "+" || chars[i] == "-" || chars[i] == "*" || chars[i] == "/" && getPrior(chars[i]) <= getPrior(stack1.get())) {
            out += stack1.pop();
            if (stack1.get() == "(") {
                stack1.pop();
            }
        }
    }
    while (stack1.isEmpty() == false) {
        out += stack1.pop();
        if (stack1.get() == "(") {
            stack1.pop();
        }
    }
    return out;
  return std::string("");
}

int eval(std::string pref) {
  // добавьте код
  return 0;
}
