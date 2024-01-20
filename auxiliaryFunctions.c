#ifndef INCLUDE_GAURD
#define INCLUDE_GAURD 1

#include <stdio.h>
#include "NumClass.h"

#endif

/* Returns the number of digits of an integer */
int getLength(int n) {
    int ans = 0;
    while (n != 0) {
        n /= 10;
        ans++;
    }
    return ans;
}

/* Returns n to the power of exp */
int myPow(int n, int exp) {
    if (exp == 0) {
        return 1;
    }
    int ans = 1;
    while (exp != 0) {
        ans *= n;
        exp--;
    }
    return ans;
}
