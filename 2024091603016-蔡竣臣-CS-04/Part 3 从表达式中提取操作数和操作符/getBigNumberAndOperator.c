#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char expression[263];
    char operator;
    char *bigNumber1 = malloc(131 * sizeof(char));
    char *bigNumber2 = malloc(131 * sizeof(char));

    if (bigNumber1 == NULL || bigNumber2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("输入一个算式：");
    scanf("%262[^\n]", expression);

    int i; 
    int j;

    for (i = 0; i < strlen(expression); i++) {
        if (expression[i] == '+' || expression[i] == '*' || expression[i] == '/') {
            operator = expression[i];
            goto end;
        }         
    } 
    for (i = 1; i < (strlen(expression)-1); i++) { 
        if (expression[i-1] != '(' && expression[i] == '-') {
            operator = expression[i];
            break;
        }
    }

end:
    j = 0;
    for (int k = 0; k < i; k++) {
        if (expression[k] != ' ') {
            bigNumber1[j++] = expression[k];
        }
    }
    bigNumber1[j] = '\0'; 

    j = 0;
    for (int k = i + 1; k < strlen(expression); k++) {
        if (expression[k] != ' ') {
            bigNumber2[j++] = expression[k];
        }
    }
    bigNumber2[j] = '\0'; 



    if (bigNumber1[0] == '(' && bigNumber2[0] == '(') {
        bigNumber1 += 1; 
        int length_1 = strlen(bigNumber1); 
        bigNumber1[length_1 - 1] = '\0';

        bigNumber2 += 1; 
        int length_2 = strlen(bigNumber2); 
        bigNumber2[length_2 - 1] = '\0'; 
    }

    if (bigNumber1[0] == '(' && bigNumber2[0] != '(') {
        bigNumber1 += 1; 
        int length_1 = strlen(bigNumber1); 
        bigNumber1[length_1 - 1] = '\0'; 
    }
    
    if (bigNumber1[0] != '(' && bigNumber2[0] == '(') { 
        bigNumber2 += 1; 
        int length_2 = strlen(bigNumber2); 
        bigNumber2[length_2 - 1] = '\0'; 
    }

    printf("操作数1: %s\n", bigNumber1);
    printf("操作数2: %s\n", bigNumber2);
    printf("操作符: %c\n", operator);

    return 0;
}