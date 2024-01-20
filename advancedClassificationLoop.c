#ifndef INCLUDE_GAURD
#define INCLUDE_GAURD 1

#include <stdio.h>
#include "NumClass.h"

#endif

#ifndef INCLUDE_GAURD2
#define INCLUDE_GAURD2 1

#include "auxiliaryFunctions.h"

#endif

int isPalindrome(int n) {
    if (n < 0) { // handle cases of negative n
        n *= -1;
    }
    int length = getLength(n); // find length of n
    int digits[length];
    for (int i = 0;i < length;i++) {
        digits[i] = n % 10;
        n /= 10;
    }
    for (int i = 0;i < length / 2;i++) {
        if (digits[i] != digits[length - 1 - i]) {
            return 0; // false
        }
    }
    return 1; // true
}

int isArmStrong(int n) {
    int length = getLength(n); // find length of n
    int nCopy = n, sum = 0;
    while (nCopy != 0) { // armstrong-summing n's digits
        sum += myPow(nCopy % 10, length);
        nCopy /= 10;
    }
    if (sum == n) {
        return 1; // true
    }
    return 0; // false
}
