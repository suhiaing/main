#include <stdio.h>
#include <string.h>

unsigned int amount = 0;
int num_of_digits = 0;
char digits[10];

void change_int_character(unsigned int num_to_change);

int main()
{
    printf("enter your amount:");
    scanf("%u", &amount);
    change_int_character(amount);

    return 0;
}

void change_int_character(unsigned int num_to_change)
{
    num_of_digits = 0;
    unsigned int temp_num = num_to_change;

    while (temp_num != 0) {
        num_of_digits++;
        temp_num /= 10;
    }

    char digits[num_of_digits];

    for (int i = num_of_digits - 1; i >= 0; i--) {
        int digit = num_to_change % 10;
        digits[i] = '0' + digit;
        num_to_change /= 10;
    }

    for (int i = 0; i < num_of_digits; i++) {
        printf("%c", digits[i]);
    }

}
