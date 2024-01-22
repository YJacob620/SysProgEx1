#include <stdlib.h>

#ifndef INCLUDE_GAURD
#define INCLUDE_GAURD 1

#include <stdio.h>
#include "NumClass.h"

#endif

int main() {
    int start, end;
    scanf("%d%d", &start, &end);
    if (start>end) { // invalid inputs case
        printf("Error: Invalid range");
        return 0;
    }

    int currentSize1 = 0, currentSize2 = 0, currentSize3 = 0, currentSize4 = 0;
    int maxSize1 = 100, maxSize2 = 100, maxSize3 = 100, maxSize4 = 100;

    int* armstrongsDynamicArray = (int*)malloc(maxSize1 * sizeof(int));
    int* palindromesDynamicArray = (int*)malloc(maxSize2 * sizeof(int));
    int* primesDynamicArray = (int*)malloc(maxSize3 * sizeof(int));
    int* strongsDynamicArray = (int*)malloc(maxSize4 * sizeof(int));


    for (int i = start;i <= end;i++) {
        if (isArmStrong(i) == 1) {
            if (currentSize1 >= maxSize1) { // if dynamic array is full
                maxSize1 *= 2; // increase dynamic array size
                armstrongsDynamicArray = (int*)realloc(armstrongsDynamicArray, maxSize1 * sizeof(int));
            }
            armstrongsDynamicArray[currentSize1++] = i;
        }
        if (isPalindrome(i) == 1) {
            if (currentSize2 >= maxSize2) {
                maxSize2 *= 2;
                palindromesDynamicArray = (int*)realloc(palindromesDynamicArray, maxSize2 * sizeof(int));
            }
            palindromesDynamicArray[currentSize2++] = i;
        }
        if (isPrime(i) == 1) {
            if (currentSize3 >= maxSize3) {
                maxSize3 *= 2;
                primesDynamicArray = (int*)realloc(primesDynamicArray, maxSize3 * sizeof(int));
            }
            primesDynamicArray[currentSize3++] = i;
        }
        if (isStrong(i) == 1) {
            if (currentSize4 >= maxSize4) {
                maxSize4 *= 2;
                strongsDynamicArray = (int*)realloc(strongsDynamicArray, maxSize4 * sizeof(int));
            }
            strongsDynamicArray[currentSize4++] = i;
        }
    }

    printf("The Armstrong numbers are:");
    for (int i = 0;i < currentSize1;i++) {
        printf(" %d", armstrongsDynamicArray[i]);
    }

    printf("\nThe Palindromes are:");
    for (int i = 0;i < currentSize2;i++) {
        printf(" %d", palindromesDynamicArray[i]);
    }

    printf("\nThe Prime numbers are:");
    for (int i = 0;i < currentSize3;i++) {
        printf(" %d", primesDynamicArray[i]);
    }

    printf("\nThe Strong numbers are:");
    for (int i = 0;i < currentSize4;i++) {
        printf(" %d", strongsDynamicArray[i]);
    }

    free(primesDynamicArray);
    free(armstrongsDynamicArray);
    free(strongsDynamicArray);
    free(palindromesDynamicArray);

    return 0;
}
