#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char paragraph[10000];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int frequency[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " \t\n.,!?;:");

    while (token != NULL) {
        toLowerCase(token);

        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                frequency[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[wordCount], token);
            frequency[wordCount]++;
            wordCount++;
        }

        token = strtok(NULL, " \t\n.,!?;:");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], frequency[i]);
    }

    return 0;
}
