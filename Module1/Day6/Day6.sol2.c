#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

void readComplex(struct Complex* num) {
    printf("Enter real part: ");
    scanf("%f", &num->real);
    printf("Enter imaginary part: ");
    scanf("%f", &num->imaginary);
}

void writeComplex(struct Complex num) {
    printf("Complex number: %.2f + %.2fi\n", num.real, num.imaginary);
}

struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex sum;
    sum.real = num1.real + num2.real;
    sum.imaginary = num1.imaginary + num2.imaginary;
    return sum;
}

struct Complex multiplyComplex(struct Complex num1, struct Complex num2) {
    struct Complex product;
    product.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
    product.imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
    return product;
}

int main() {
    struct Complex num1, num2, sum, product;

    printf("Reading Complex Number 1:\n");
    readComplex(&num1);

    printf("Reading Complex Number 2:\n");
    readComplex(&num2);

    printf("\n");

    printf("Complex Number 1:\n");
    writeComplex(num1);

    printf("Complex Number 2:\n");
    writeComplex(num2);

    printf("\n");

    sum = addComplex(num1, num2);
    printf("Sum of Complex Numbers:\n");
    writeComplex(sum);

    product = multiplyComplex(num1, num2);
    printf("Product of Complex Numbers:\n");
    writeComplex(product);

    return 0;
}