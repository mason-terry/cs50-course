#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string encrypt_string(string str, string key);
char get_encrypted_value(char c, string key);
int valid_key(string key);
int has_dups(string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    if (argc != 2 || has_dups(key) || !valid_key(key))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int keyLen = strlen(key);
    if (keyLen != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plainText = get_string("plaintext: ");

    printf("ciphertext: ");
    encrypt_string(plainText, key);
    return 0;
}

string encrypt_string(string str, string key)
{
    string encrypted = "";
    for (int i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i]) || !isalpha(str[i]))
        {
            printf("%c", str[i]);
        }
        if (isupper(str[i]))
        {
            char c = toupper(get_encrypted_value(str[i], key));
            printf("%c", c);
        }
        if (islower(str[i]))
        {
            char c = tolower(get_encrypted_value(toupper(str[i]), key));
            printf("%c", c);
        }
    }
    printf("\n");

    return encrypted;
}

char get_encrypted_value(char c, string key)
{
    char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i < 26; i++)
    {
        if (c == LETTERS[i])
        {
            return key[i];
        }
    }
    return c;
}

int valid_key(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int has_dups(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key) - j; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                return 1;
            }
        }
    }
    return 0;
}
