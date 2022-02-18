#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool is_number_valid(string n);
void rev_string(string str);
string get_card_brand(string n);

int main(void)
{
    string card_number = get_string("Please enter your card number: ");
    printf("%s\n", is_number_valid(card_number) ? get_card_brand(card_number) : "INVALID");
}

// Get card brand
string get_card_brand(string n)
{
    int len = strlen(n);
    rev_string(n);
    char c[1];
    c[0] = n[0];
    int x = atoi(c);

    char d[1];
    d[0] = n[1];
    int y = atoi(d);

    int xy = (x * 10) + y;

    if (x == 4 && (len == 13 || len == 16))
    {
        return "VISA";
    }
    if ((xy == 37 || xy == 34) && len == 15)
    {
        return "AMEX";
    }
    if (xy >= 51 && xy <= 55 && len == 16)
    {
        return "MASTERCARD";
    }
    return "INVALID";
}

// Luhn's algorithm
bool is_number_valid(string n)
{
    int total = 0;
    rev_string(n);
    for (int i = 0; i < strlen(n); i++)
    {
        char c[1];
        c[0] = n[i];
        int x = atoi(c);
        if (i % 2 == 1)
        {
            int tmp = x * 2;
            if (tmp >= 10)
            {
                total += ((tmp - 10) + 1);
            }
            else
            {
                total += tmp;
            }
        }
        else
        {
            total += x;
        }
    }

    return total % 10 == 0;
}

// Reverse string
void rev_string(string str)
{
    int n = strlen(str);

    for (int i = 0; i < n / 2; i++)
    {
        char ch = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = ch;
    }
}
