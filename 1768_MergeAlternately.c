#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mergeAlternately(const char* word1, const char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int mergedLen = len1 + len2;

    char* result = (char*)malloc((mergedLen + 1) * sizeof(char)); // +1 for the null terminator

    int i = 0, j = 0, k = 0;

    while (i < len1 && j < len2) {
        result[k++] = word1[i++];
        result[k++] = word2[j++];
    }

    // If one word is longer than the other, add the remaining characters
    while (i < len1) {
        result[k++] = word1[i++];
    }

    while (j < len2) {
        result[k++] = word2[j++];
    }

    result[k] = '\0'; // Null-terminate the result

    return result;
}

int main() {
    const char* word1 = "abc";
    const char* word2 = "xyz";

    char* merged = mergeAlternately(word1, word2);

    printf("Merged: %s\n", merged);

    free(merged); // Don't forget to free the allocated memory

    return 0;
}


// from chatgpt