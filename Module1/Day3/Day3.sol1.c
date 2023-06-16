#include <stdio.h>

void printIncreasing(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
    }
}

void printSpaces(int n) {
    for (int i = 1; i <= n; i++) {
        printf(" ");
    }
}

void printDecreasing(int n) {
    for (int i = n; i >= 1; i--) {
        printf("%d", i);
    }
}

int main() {
    int n = 5;

    for (int i = n; i >= 1; i--) {
        printIncreasing(i);
        printSpaces(2 * (n - i));
        printDecreasing(i);
        printf("\n");
    }

    return 0;
}