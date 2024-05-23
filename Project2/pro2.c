#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int findInsertPosition(char** dictionary, int size, const char* newWord) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(dictionary[i], newWord) > 0) {
            return i;
        }
    }
    return size;
}

char** insertWord(char** dictionary, int size, const char* newWord) {
    int position = findInsertPosition(dictionary, size, newWord);

    char** newDictionary = (char**)malloc((size + 1) * sizeof(char*));
    if (newDictionary == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0, j = 0; i < size + 1; i++) {
        if (i == position) {
            newDictionary[i] = strdup(newWord);
            if (newDictionary[i] == NULL) {
                printf("Error: Memory allocation failed.\n");
                exit(1);
            }
        } else {
            newDictionary[i] = dictionary[j++];
        }
    }

    return newDictionary;
}

int main() {
    int size = 12;
    char* dictionary[] = {"Batarang", "DeLorean", "Excalibur", "Lightsaber", "Mjolnir", "Omnitrix", "Pokeball", "Protonpack", "Sonic", "Triforce", "Wand"};
    char newWord[MAX_WORD_LENGTH];

    printf("Enter the new word to insert: ");
    scanf("%s", newWord);

    char** newDictionary = insertWord(dictionary, size, newWord);

    printf("Dictionary after insertion:\n");
    for (int i = 0; i < size + 1; i++) {
        printf("%s\n", newDictionary[i]);
        free(newDictionary[i]);
    }

    free(newDictionary);
    return 0;
}
