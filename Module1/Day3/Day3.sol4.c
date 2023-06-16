#include <stdio.h>

int findLargestNumber(int num) {
    int largest = 0;

    // Convert the number to an array of digits
    int digits[4];
    digits[0] = num % 10;
    digits[1] = (num / 10) % 10;
    digits[2] = (num / 100) % 10;
    digits[3] = (num / 1000) % 10;

    // Iterate through each digit and remove it once
    for (int i = 0; i < 4; i++) {
        int currentNum = 0;

        // Construct the number without the current digit
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                currentNum = currentNum * 10 + digits[j];
            }
        }

        // Update the largest number if the current number is larger
        if (currentNum > largest) {
            largest = currentNum;
        }
    }

    return largest;
}

int main() {
    int num1 = 5872;
    int num2 = 9856;

    int largest1 = findLargestNumber(num1);
    int largest2 = findLargestNumber(num2);

    printf("Largest number by deleting a single digit from %d: %d\n", num1, largest1);
    printf("Largest number by deleting a single digit from %d: %d\n", num2, largest2);

    return 0;
}