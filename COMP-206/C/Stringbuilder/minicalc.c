#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>



char const * const COMMANDS[] = {
        "sqrt",
        "gcd",
        "anagram"
};

int stringLength(const char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int string_eq(char const *str1, char const *str2)
{
        int i = 0;
        while (str1[i] != 0 && str2[i] != 0) {
                if (str1[i] != str2[i])
                        return 0;
                i++;
        }

        return !(str1[i] != 0 || str2[i] != 0);
}

int gcd(int a, int b) {
        while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
        }
        return a;
}

int gcd_many(int len, long arr[])
{
        int result = (int)arr[0];
        for (int i = 1; i < len; i++) {
                result = gcd(result, (int) arr[i]);
                if (result == 1) {
                return 1;
        }
    }
    return result;
}
int main(int argc, char * argv[])
{
        if (argc < 2){
                printf("Argument not given correctly\n");
                return 1;
        }

        char *command = argv[1];

        int const len = sizeof(COMMANDS)/sizeof(COMMANDS[0]);


        for (int i = 0; i < len+1; i++) {
                if (i == len){
                        printf("Command non-existant\n");
                        return 1;
                }
                if (string_eq(command, COMMANDS[i])) {
                        break;
                }
        }

        if (string_eq(command,COMMANDS[0])){
                if (argc != 3){
                        printf("Invalid input\n");
                        return 2;
                }
                char *endptr;
                double input = strtod(argv[2], &endptr);
                if (endptr == argv[2] || *endptr != '\0'){
                        printf("arguments are not entirely number\n");
                        return 3;
                }
                if (input < 0){
                        printf("Cannot sqrt negative number\n");
                        return 3;
                }
                double result = sqrt(input);
                printf("The result of square root is: %.2f\n", result);
                return 0;
        }
        else if(string_eq(command,COMMANDS[1])){
                if (argc < 3){
                        printf("Invalid input\n");
                        return 2;
                }
                long input[argc-2];
                int j = 0;
                for (int i = 2; i < argc; i++) {
                        char *endptr;
                        input[j] = strtol(argv[i], &endptr, 10);

                        if (endptr == argv[i] || *endptr != '\0'){
                                printf("arguments are not entirely numbers\n");
                                return 3;
                        }
                        if (input[j]<= 0){
                                printf("Error, arguments are not strictly greater than zero\n");
                                return 3;
                        }
                        j += 1;
                }

                printf("The greatest common divisor is: %d\n", gcd_many(argc-2, input));
                return 0;
        }
        else if(string_eq(command,COMMANDS[2])){
                if (argc != 4){
                        printf("Invalid input\n");
                        return 2;
                }

                const char *S1 = argv[2];
                const char *S2 = argv[3];
                int length1 = stringLength(S1);
                int length2 = stringLength(S2);
                for (int i = 0; i<length1; i++){
                        if (!islower(S1[i])){
                                printf("Error, the argument is not lowercase\n");
                                return 3;
                        }
                }
                for (int i = 0; i<length2; i++){
                        if (!islower(S2[i])){
                                printf("Error, the argument is not lowercase\n");
                                return 3;
                        }
                }
                if (length1 != length2){
                        printf("false\n");
                        return 0;
                }

                int list1[26] = {0};
                int list2[26] = {0};
                for (int i = 0; i<length1; i++){
                        list1[(int)S1[i]-97]+=1;
                        list2[(int)S2[i]-97]+=1;
                }

                for (int i = 0; i<26; i++){
                        if (list1[i] != list2[i]){
                                printf("false\n");
                                return 0;
                        }
                }

                printf("true\n");
                return 0;


        }
