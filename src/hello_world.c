#include <stdio.h>
#include <string.h>
#include <ctype.h>

void capitalize(char *str) {
    int i = 0;
    int new_word = 1;
    while (str[i]) {
        if (isspace(str[i])) {
            new_word = 1;
        } else if (new_word) {
            str[i] = toupper(str[i]);
            new_word = 0;
        }
        i++;
    }
}

int main() {
    char name[26];
    printf("Enter your name: \n");
    fgets(name, sizeof(name), stdin);

    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    } else {
        while (getchar() != '\n');
        printf("Input too long. Please enter a name up to 25 characters.\n");
        return 1;
    }

    capitalize(name);

    printf("Hello, %s!\n", name);
    return 0;
}