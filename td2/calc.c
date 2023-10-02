#include <stdio.h>

int main() {
    for (;;) {
        double a, b;
        char op;
        scanf("%lf%c%lf", &a, &op, &b);

        double res;

        switch (op) {
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
            case '*':
                res = a * b;
                break;
            case '/':
                res = a / b;
                break;
            default:
                continue;
        }

        printf("= %.3f\n", res);
    }
}