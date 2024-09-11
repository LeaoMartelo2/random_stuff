#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

bool is_valid_format_specifier(char specifier) {
    return (specifier == 'd' || specifier == 'f');
}

void print_int(int num) {

    // explicitly take care of 0
    if (num == 0) {
        putchar('0');
        return;
    }

    // take care of negative numbers, make it positive at the end for easily converting it on a char
    if (num < 0) {
        putchar('-');
        num = -num;
    }

    // find the highest power of ten, less or equal to num
    int power_of_ten = 1;
    while (num / power_of_ten >= 10) {
        power_of_ten *= 10;
    }

    // print the chars
    while (power_of_ten > 0) {
        int digit = num / power_of_ten;
        putchar('0' + digit);
        num %= power_of_ten;
        power_of_ten /= 10;
    }
}

void print_double(double num) {
    // negatives
    if (num < 0) {
        putchar('-');
        num = -num;
    }

    // split the entire and fractionary parts
    int int_part = (int)num;
    double frac_part = num - int_part;

    // print the int part
    print_int(int_part);
    putchar('.');

    // print fractionary part up to 6 digits;
    for (int i = 0; i < 6; i++) {
        frac_part *= 10;
        int frac_digit = (int)frac_part;
        putchar('0' + frac_part);
        frac_part -= frac_digit;
    }
}

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    for (const char *p = format; *p != '\0'; p++) {
        if (*p == '%' && is_valid_format_specifier(*(p + 1))) {
            switch (*(p + 1)) {

            case 'd': {
                int num = va_arg(args, int);
                print_int(num);
                break;
            }

            case 'f': {
                double num = va_arg(args, double);
                print_double(num);
                break;
            }

            default:
                putchar('%');
                putchar(*(p + 1));
                break;
            }

            p++;
        } else {
            putchar(*p);
        }
    }

    va_end(args);
}

int main() {
    int integer = -10;
    float floater = -10.05f;
    double doubler = -100000;
    my_printf("hello guys, this is a int %d, %d %d %d \n", integer, 10, -100, 100);
    return 0;
}
