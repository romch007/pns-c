#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>

double log16(double x) {
    return log(x) / log(16);
}

void printf_own(const char format[], ...) {
    va_list vars;
    va_start(vars, format);
    size_t format_len = strlen(format);

    for (size_t i = 0; i < format_len; i++) {
        if (format[i] == '%') {
            if (format[i + 1] == 'd') {
                int v = va_arg(vars, int);
                int digit;

                if (v == 0) {
                    putchar('0');
                } else {
                    digit = pow(10, 1 + floor(log10(v)));
                    while (digit /= 10) {
                        int c = '0' + ((v / digit) % 10);
                        putchar(c);
                    }
                }
            } else if (format[i + 1] == 'x') {
                int v = va_arg(vars, int);
                int digit;

                if (v == 0) {
                    putchar('0');
                } else {
                    digit = pow(16, 1 + floor(log16(v)));
                    while (digit /= 16) {
                        int real_val = ((v / digit) % 16);
                        int c;
                        if (real_val < 10) {
                            c = '0' + real_val;
                        } else {
                            c = 'a' + (real_val - 10);
                        }
                        putchar(c);
                    }
                }
            } else if (format[i + 1] == 'f') {
                // TODO: maybe better?
                double val = va_arg(vars, double);
                char buffer[64] = {0};
                sprintf(buffer, "%f", val);

                for (size_t i = 0; i < strlen(buffer); i++) {
                    putchar(buffer[i]);
                }
            } else if (format[i + 1] == 'c') {
                int c = va_arg(vars, int);
                putchar(c);
            } else if (format[i + 1] == 's') {
                char* str = va_arg(vars, char*);
                for (size_t j = 0; j < strlen(str); j++)  {
                    putchar(str[j]);
                }
            } else if (format[i + 1] == '%') {
                putchar('%');
            } else {
                putchar(format[i]);
                putchar(format[i + 1]);
            }
            i++;
        } else {
            putchar(format[i]);
        }
    }

    va_end(vars);
}

int main() {
    printf_own("DEBUT\n%s%c c'est moi.\nTest nombres: 0x%x et %d et un négatif %d\n",
          "salut", ',', 161, 123, -12);
    printf_own("Trois nombres sur la même ligne: %d %f %d\n", 1, 2.0, 3);
    printf_own("Affichage d'un '%c' et encore un d'une autre façon '%%'\n", '%');
    printf_own("Affichage d'un %% non suivi d'un caractère spécial ==> %z...\n");
    printf_own("Attention au %% en fin de la chaîne format ==> %");
    printf_own("\nFIN\n");
    return 0;
}