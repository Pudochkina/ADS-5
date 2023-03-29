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
