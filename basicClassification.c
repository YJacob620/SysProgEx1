#ifndef INCLUDE_GAURD
#define INCLUDE_GAURD 1

#include <stdio.h>
#include "NumClass.h"

#endif

int isStrong(int n) {
    if (n == 0) {
        return 0; // false
    }
    int factorials[] = { 1,1,2,6,24,120,720,5040,40320,362880 }; // 0!, 1!, ... , 9!
    int sum = 0, nC = n;
    while (nC != 0) {
        sum += factorials[(nC % 10)];
        nC /= 10;
    }
    if (sum == n) {
        return 1; // true
    }
    return 0; // false
}

int isPrime(int n) {
    if (n < 1) {
        return 0; // false
    }
    for (int i = 2;i <= n / 2;i++) {
        if (n % i == 0) {
            return 0; // false
        }
    }
    return 1; // true
}