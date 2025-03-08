#include <stdio.h>

int RomanValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int Roman_to_Arabic() {
    char current_char, next_char;
    int current_value, next_value;
    int result = 0;

    // Ignore leading whitespace
    while ((current_char = getchar()) == ' ' || current_char == '\t');

    if (current_char == EOF || current_char == '\n') return 0;

    while (1) {
        next_char = getchar();

        current_value = RomanValue(current_char);
        next_value = RomanValue(next_char);

        if (current_value == 0) break; // Invalid character, end of input

        if (next_value == 0 || current_value >= next_value) 
            result += current_value;
            
         else result -= current_value;
        

        if (next_value == 0 || next_char == '\n' || next_char == EOF) break;

        current_char = next_char;
    }

    return result;
}

int main() {
    printf("%d\n", Roman_to_Arabic());
    return 0;
}