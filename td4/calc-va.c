#include <stdarg.h>
#include <stdio.h>

int evaluer(char operateur, int operande, ...) {
    va_list nbs;
    va_start(nbs, operande);
    int result = operande;

    while ((operande = va_arg(nbs, int)) != -1) {
        switch (operateur) {
            case '+':
                result += operande;
                break;
            case '-':
                result -= operande;
                break;
            case '*':
                result *= operande;
                break;
            case '/':
                result /= operande;
                break;
            default:
                printf("unknown operator '%c'\n", operateur);
                return -1;
        }
    }

    va_end(nbs);

    return result;
}

int main() {
    int r1 = evaluer('+', 1, 2, 3, -1);
    printf("%d\n", r1);
    int r2 = evaluer('-', 10, evaluer('*', 2, 2, 2, -1), 2, -1);
    printf("%d\n", r2);
}
