#include <stdio.h>
#include <stdlib.h>

// Function to perform bubble sort
void BubbleSort(int* data, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    const char* inputFilename = "input.txt";
    const char* outputFilename = "output.txt";

    FILE* file = fopen(inputFilename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s for reading.\n", inputFilename);
        return 1;
    }

    int capacity = 10;
    int size = 0;
    int* data = (int*)malloc(capacity * sizeof(int));
    if (data == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    while (fscanf(file, "%d", &data[size]) == 1) {
        size++;
        if (size >= capacity) {
            capacity *= 2;
            int* temp = (int*)realloc(data, capacity * sizeof(int));
            if (temp == NULL) {
                printf("Error: Memory reallocation failed.\n");
                free(data);
                fclose(file);
                return 1;
            }
            data = temp;
        }
    }

    fclose(file);

    BubbleSort(data, size);

    file = fopen(outputFilename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", outputFilename);
        free(data); // Free allocated memory before exit
        return 1;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", data[i]);
    }

    fclose(file);

    printf("Sorted data:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", data[i]);
    }

    free(data);
    return 0;
}
