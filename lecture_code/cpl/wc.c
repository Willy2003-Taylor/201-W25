// This program mimics the wc tool in bash
//wc outputs the number of the line, word, and characters of a document

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void count(FILE* file, int* lines, int* words, int* chars){
    char ch;
    bool in_word = false; /*
      To determine if the new word is obtained
      False indicates new word is obtained; otherwise, new word is not obtained
      */

      *lines = *words = *chars = 0;

      while ((ch = fgetc(file)) != EOF){
        (*chars)++;

        if (ch == '\n') (*lines)++;

        if(isspace(ch) || ch == '\n')
            if (in_word){
                (*words)++;
                in_word = false;
            }
        
        else in_word = true;
      }

      //This mimics the function of wc tool in bash
      if (in_word) (*words)++;

}

int main(int argc, char *argv[]) {
    if (argc == 1){
        // If the file is not provided, read from stdin

        int lines, words, chars;

        count(stdin, &lines, &words, &chars);

        printf("%d %d %d\n", lines, words, chars);
    }

    else{
        // If the file is provided, traverse the file
        for(int i = 1; i < argc; ++i){
            // the reason i starts from 1 is that argv[0] has a default value defined by system
            FILE* file = fopen(argv[i], "r");

            if(!file){
                perror(argv[i]);
                continue;
            }

            int lines, words, chars;

            count(file, &lines, &words, &chars);

            printf("%d %d %d\n", lines, words, chars);

            fclose(file);
        }
    }

    return 0;
}
