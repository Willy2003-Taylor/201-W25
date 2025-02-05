#include <stdio.h>

int readint() {
  /*
   * This function takes no parameters, reads in an integer
   * from the stdin stream (using the getchar function),
   * and returns that integer. This should skip over any leading
   * whitespace, and then stop reading the integer the first
   * time a non-digit character is read.
   */
  int num = 0;
  char input;

  for(input = getchar(); (input == ' ' || input == '\n' || input == '\r'); input = getchar());

  while(input >= '0' && input <= '9'){
   num = num * 10 + input - '0';
   input = getchar();
  }

  return num;
}

int main() {
  // This program reads one integer from the standard input stream
  // and prints out that integer multiplied by 3!
  int x = readint();
  printf("%d\n", x*3);
}
