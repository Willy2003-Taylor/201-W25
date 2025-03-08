#include<stdio.h>

void luhns_algorithm(){
    char acc_digit;
    int sum1 = 0, sum2 = 0;
    int check_digit = 0;
    int digit1, digit2;
    int double_flag1 = 1, double_flag2 = 0;
    int check_digit_doubled1, check_digit_doubled2;

    /*Do 2 calculations: 1st: Start from doubling the 1st digit and alternative
    2nd: Start from not doubling the 1st digit and alternative*/

    while((acc_digit = getchar()) != EOF){
        if(acc_digit >= '0' && acc_digit <= '9'){
            digit1 = acc_digit - '0';
            digit2 = acc_digit - '0';
        }

        else break;

        if(double_flag2){
            int doubled2 = digit2 * 2;

            if(doubled2 >= 10) doubled2 -= 9;

            sum2 += doubled2;

            double_flag2 = !double_flag2;
            if(double_flag1 ^ double_flag2){
                check_digit = digit1;
                continue;
            }
        }

        if(!double_flag1){
            sum1 += digit1;
            double_flag1 = !double_flag1;
            if(double_flag1 ^ double_flag2){
                check_digit = digit1;
                continue;
            }
        }

        if(double_flag1){
            int doubled1 = digit1 * 2;

            if(doubled1 >= 10) doubled1 -= 9;

            sum1 += doubled1;

            double_flag1 = !double_flag1;
            if(double_flag1 ^ double_flag2){
                check_digit = digit1;
                continue;
            }
        }

        if(!double_flag2){
            sum2 += digit2;
            double_flag2 = !double_flag2;
            if(double_flag1 ^ double_flag2){
                check_digit = digit1;
                continue;
            } 
        }
    }

    double_flag1 = !double_flag1;
    double_flag2 = !double_flag2;

    check_digit_doubled1 = double_flag1;
    check_digit_doubled2 = double_flag2;

    if(!check_digit_doubled1){
        sum1 -= check_digit;
        int finalsum1 = sum1 * 9;

        if(finalsum1 % 10 == check_digit){
            printf("Valid\n");
            return;
        }
        
        else {
            printf("Invalid\n"); 
            return;
        }

    }

    if(!check_digit_doubled2){
        sum2 -= check_digit;
        int finalsum2 = sum2 * 9;

        if(finalsum2 % 10 == check_digit){
            printf("Valid\n");
            return;
        }

        else {
            printf("Invalid\n");
            return;
        }
    }
}

int main(){
    luhns_algorithm();
    return 0;
}