#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50 // maximum number of words
#define WORD_LEN 20  // maximum length of each word

// function prototype for the comparison function used by qsort
int compare_words(const void *p, const void *q);

int main(void)
{
    char words[MAX_WORDS][WORD_LEN + 1]; // array of words
    char input[WORD_LEN + 2];            // buffer to hold user input
    int num_words = 0;                   // number of words entered by the user

    printf("Enter word: ");
    // read input from the user until the maximum number of words is reached,
    // fgets returns NULL, or the user enters an empty word
    while (num_words < MAX_WORDS && fgets(input, sizeof(input), stdin) != NULL && input[0] != '\n')
    {
        input[strcspn(input, "\n")] = '\0'; // remove newline character from input
        strcpy(words[num_words], input);    // copy input into words array
        num_words++;                        // increment number of words
        printf("Enter word: ");
    }

    qsort(words, num_words, sizeof(words[0]), compare_words); // sort the array of words

    printf("\nFirst: %s\n", words[0]);          // print the first word alphabetically
    printf("Last: %s\n", words[num_words - 1]); // print the last word alphabetically

    printf("\nIn sorted order: "); // print the sorted array of words
    for (int i = 0; i < num_words; i++)
        printf("%s ", words[i]);
    printf("\n");

    return 0;
}

// comparison function for qsort
int compare_words(const void *p, const void *q)
{
    return strcmp((char *)p, (char *)q);
}
