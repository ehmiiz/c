#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEFAULT_LENGTH 16
#define DEFAULT_AMOUNT 1

char *generate_password(int length, int upper, int lower, int numeric, int special)
{
    char upper_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower_chars[] = "abcdefghijklmnopqrstuvwxyz";
    char numeric_chars[] = "0123456789";
    char special_chars[] = "!@#$%^&*()";
    char all_chars[100];
    strcpy(all_chars, "");

    if (upper)
        strcat(all_chars, upper_chars);
    if (lower)
        strcat(all_chars, lower_chars);
    if (numeric)
        strcat(all_chars, numeric_chars);
    if (special)
        strcat(all_chars, special_chars);

    int all_chars_length = strlen(all_chars);
    char *password = malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        password[i] = all_chars[rand() % all_chars_length];
    }

    password[length] = '\0';
    return password;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int length = DEFAULT_LENGTH;
    int amount = DEFAULT_AMOUNT;
    int upper = 0, lower = 0, numeric = 0, special = 0;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-upper") == 0)
        {
            upper = 1;
        }
        else if (strcmp(argv[i], "-lower") == 0)
        {
            lower = 1;
        }
        else if (strcmp(argv[i], "-numeric") == 0)
        {
            numeric = 1;
        }
        else if (strcmp(argv[i], "-special") == 0)
        {
            special = 1;
        }
        else if (strcmp(argv[i], "-length") == 0 && i + 1 < argc)
        {
            length = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-amount") == 0 && i + 1 < argc)
        {
            amount = atoi(argv[++i]);
        }
    }

    if (upper == 0 && lower == 0 && numeric == 0 && special == 0)
    {
        upper = lower = numeric = special = 1;
    }

    for (int i = 0; i < amount; i++)
    {
        char *password = generate_password(length, upper, lower, numeric, special);
        printf("%s\n", password);
        free(password);
    }

    return 0;
}