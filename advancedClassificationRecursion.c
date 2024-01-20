#ifndef INCLUDE_GAURD
#define INCLUDE_GAURD 1

#include <stdio.h>
#include "NumClass.h"

#endif

#ifndef INCLUDE_GAURD2
#define INCLUDE_GAURD2 1

#include "auxiliaryFunctions.h"

#endif

/* Finds if a string (char array) is a palindrome recursively */
int isStringPalindrome(char arr[], int left, int right) {
    if (left >= right) {
        return 1; // true
    }
    if (arr[left] != arr[right]) {
        return 0; // false
    }
    return isStringPalindrome(arr, left + 1, right - 1);
}

int isPalindrome(int n) {
    if (n < 0) { // handle cases of negative n
        n *= -1;
    }
    int length = getLength(n); // find length of n
    char digits[length];
    sprintf(digits, "%d", n); // convert n into a char array 
    return isStringPalindrome(digits, 0, length - 1);
}

/* Calculates Armstrong-sum recursively */
int armStrongSum(int n, int length) {
    if (n == 0) {
        return 0;
    }
    return myPow((n % 10), length) + armStrongSum(n / 10, length);
}

int isArmStrong(int n) {
    int length = getLength(n); // find length of n
    int sum = armStrongSum(n, length);
    if (sum == n) {
        return 1; // true
    }
    return 0; // false
}