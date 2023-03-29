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
  return std::string("");
    std::string out = "";
    TStack<char, 100> stack1;
    for (int i = 0; i < inf.size(); i++) {
        if (inf[i] == ch0 || inf[i] == ch1 || inf[i] == ch2 || inf[i] == ch3
            || inf[i] == ch4 || inf[i] == ch5 || inf[i] == ch6 || inf[i] == ch7 
            || inf[i] == ch8 || inf[i] == ch9) {
            out += inf[i];
            out += " ";
        }
            if (inf[i] == ch9Lsk || stack1.isEmpty() 
|| getPrior(inf[i]) > getPrior(stack1.get())) {
            stack1.push(inf[i]);
        } 
                if (inf[i] == ch9Rsk) {
                char ch = stack1.pop();
                while (ch != ch9Lsk) {
                    out += ch + " ";
                    ch = stack1.pop();
                }
            }  
if (getPrior(inf[i] <= stack1.get())) {
                while (getPrior(inf[i] <= stack1.get()) && !stack1.isEmpty()) {
                    char c = stack1.pop();
                    out += c;
                    out += " ";
                }
                stack1.push(inf[i]);
            }
        }
    }
    while (!stack1.isEmpty()) {
        char s = stack1.pop();
        post += s;
        post += " ";
    }
    out.pop_back();
    return out;
}

int eval(std::string pref) {
    TStack <int, 100> temp;
    for (char s : pref) {
        if (s == ' ')
            continue;
        if ((s <= '9') && (s >= '0')) {
            int z = static_cast<int>(s - '0');
            temp.push(z);
        } else {
            int zn;
            int first = temp.get();
            temp.pop();
            int second = temp.get();
            temp.pop();
            switch (s) {
            case '+':
                zn = second + first;
                break;
            case '-':
                zn = second - first;
                break;
            case '*':
                zn = second * first;
                break;
            case '/':
                zn = second / first;
                break;
            }
            temp.push(zn);
        }
    }
    return temp.pop();
}
