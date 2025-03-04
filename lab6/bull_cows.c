#include <stdio.h>
#include <string.h>

int count_bulls(const char* guess, const char* codeword){
  int bulls = 0;

  for(int i = 0; guess[i] != '\0' && codeword[i] != '\0'; ++i)
    if(guess[i] == codeword[i]) bulls++;

  return bulls;
}

int count_cows(const char* guess, const char* codeword){
  int cows = 0;
  int codeword_count[175] = {0};
  int guess_count[175] = {0};

  for(int i = 0; guess[i] != '\0'; ++i)
    guess_count[guess[i]]++;

  for(int i = 0; codeword[i] != '\0'; ++i)
    codeword_count[codeword[i]]++;

  for(int i = 0; i < 175; ++i)
    cows += (guess_count[i] <= codeword_count[i]? guess_count[i] : codeword_count[i]);
  cows -= count_bulls(guess, codeword);

  return cows;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <codeword>\n", argv[0]);
    return 1;
  }
  if (strlen(argv[1]) > 10) {
    fprintf(stderr, "Error: codeword can be at most 10 characters\n");
    return 1;
  }
  const char * const codeword = argv[1];

  int guess_count = 0;
  char guess[11];

  while(guess_count < 6){
    if(fgets(guess, sizeof(guess), stdin) == NULL)
      break;
    
    guess[strcspn(guess, "\n")] = '\0';

    if(strlen(codeword) != strlen(guess)){
      printf("Error: length of guess must always match codeword\n Invalid Guess was \"%s\" and code word is \"%s\" ", guess, codeword);
      return 1;
    }

    int bulls = count_bulls(guess, codeword);
    int cows = count_cows(guess, codeword);

    printf("%d bulls, %d cows\n", bulls, cows);

    if(bulls == strlen(codeword)){
      printf("%d bulls, %d cows\n", bulls, cows);
      printf("Congratulations, you won!\n");
      return 0;
    }

    guess_count++;
  }

  printf("Sorry, you lost. The codeword was %s\n", codeword);
  return 0;
}
