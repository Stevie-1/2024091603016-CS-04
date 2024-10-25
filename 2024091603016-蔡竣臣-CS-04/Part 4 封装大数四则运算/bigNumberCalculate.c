#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h> 

int a[1000],b[1000],c[1000];

/**头文件 <stdio.h> <malloc.h> 
 * @brief 该函数输入一个字符串数组的指针，释放其内存
 * 
 * @param char *bigNumber 输入一个字符串数组的指针
 * 
 * @return void 无参数输出
 */
void freeBigNumberPtr(char *bigNumber){
    free(bigNumber); 
    bigNumber = NULL; 
    return;
}

/**头文件 <stdio.h> <stdlib.h> <string.h>
 * @brief 该函数输入两个字符串数组的指针，将其相加，并返回一个指向和的字符串数组的指针
 * 
 * @param char *bigNumber1 输入一个字符串数组的指针 
 * @param char *bigNumber2 输入一个字符串数组的指针
 * 
 * @return char * 一个指向和的字符串数组的指针
 */
char *bigNumberAdd(char *bigNumber1, char *bigNumber2){ 
    if (bigNumber1[0] == '(' && bigNumber2[0] == '(') {
        bigNumber1 += 2; 
        int length_1 = strlen(bigNumber1); 
        bigNumber1[length_1 - 1] = '\0';

        bigNumber2 += 2; 
        int length_2 = strlen(bigNumber2); 
        bigNumber2[length_2 - 1] = '\0'; 

        int length1 = strlen(bigNumber1);
        int length2 = strlen(bigNumber2);
        int maxLength = length1 > length2 ? length1 : length2; 

        char *result = malloc((maxLength + 2) * sizeof(char)); 
        if (result == NULL) {
            printf("内存分配失败，程序错误\n");
            return NULL;
        }
        result[maxLength + 1] = '\0'; 

        int carry = 0;
        for (int i = 0; i <= maxLength; i++) {
            int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
            int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            result[maxLength - i] = (sum % 10) + '0'; 
        }

        for (int i = 0; i < maxLength;) { 
            if (result[i] == '0'){
                    result++;
                }
            else{
                break;
            }
        } 
        char *finalResult = malloc(129*sizeof(char)); 
        finalResult[0] = '-'; 
        strcpy(finalResult + 1, result); 
        result = finalResult;
        if (result[0] == '-' && result[1] == '\0'){
            result[0] = '0'; 
            result[1] = '\0';
        }
        return result; 
    }
    
    if (bigNumber1[0] != '(' && bigNumber2[0] != '(') {
        int length1 = strlen(bigNumber1); 
        int length2 = strlen(bigNumber2); 
        int carry = 0;
        int maxLength = length1 > length2 ? length1 : length2; 
        char *result = malloc((maxLength + 2) * sizeof(char)); 
        if (result == NULL) {
            printf("内存分配失败，程序错误\n");
            return NULL;
        }
        result[maxLength + 1] = '\0'; 

        for (int i = 0; i <= maxLength; i++) {
            int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
            int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; 
            int sum = num1 + num2 + carry;
            carry = sum / 10; 
            result[maxLength - i] = (sum % 10) + '0'; 
        }

        for (int i = 0; i < maxLength;) { 
            if (result[i] == '0'){
                result++;
            }
            else{
                break;
            }
        } 
        if (result[0] == '\0'){
            result[0] = '0'; 
            result[1] = '\0';
        }
        return result;
    }
    
    if (bigNumber1[0] == '(' && bigNumber2[0] != '(') { 
        bigNumber1 += 2; 
        int length_2 = strlen(bigNumber1); 
        bigNumber1[length_2 - 1] = '\0'; 
        
        int length1 = strlen(bigNumber1); 
        int length2 = strlen(bigNumber2); 
        
        if (length1 > length2){ 
            int maxLength = length1; 
            char *result = malloc((maxLength + 2) * sizeof(char));
            if (result == NULL) {
                printf("内存分配失败，程序错误\n");
                return NULL;
            }
                result[maxLength + 1] = '\0';
            int carry = 0;
            for (int i = 0; i <= maxLength; i++) {
                int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
                int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; 
                int sum = num1 - num2 + carry;
                carry = sum >= 0 ? 0 : -1; 
                sum = sum < 0? sum + 10 : sum;
                result[maxLength - i] = (sum % 10) + '0'; 
            } 
            for (int i = 0; i < maxLength;) { 
            if (result[i] == '0'){
                    result++;
                }
                else{
                break;
                }
            } 
            char *finalResult = malloc(129*sizeof(char)); 
            finalResult[0] = '-'; 
            strcpy(finalResult + 1, result); 
            result = finalResult;
            return result;
        } 
        else if(length1 < length2){
            int maxLength = length2; 
            char *result = malloc((maxLength + 2) * sizeof(char)); 
            if (result == NULL) {
                printf("内存分配失败，程序错误\n");
                return NULL;
            }
                result[maxLength + 1] = '\0'; 

            int carry = 0;
            for (int i = 0; i <= maxLength; i++) {
                int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
                int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; 
                int sum = num2 - num1 + carry;
                carry = sum >= 0 ? 0 : -1; 
                sum = sum < 0? sum + 10 : sum;
                result[maxLength - i] = (sum % 10) + '0'; 
            }
            for (int i = 0; i < maxLength;) { 
                if (result[i] == '0'){
                    result++;
                }
                else{
                    break;
                    }
                }                
                return result;
        } 
        else{ 
            int maxLength = length1;  
            for (int i = 0; i < maxLength; i++){
                if (bigNumber1[i] > bigNumber2[i]){ 
                    char *result = malloc((maxLength + 2) * sizeof(char));
                    if (result == NULL) {
                        printf("内存分配失败，程序错误\n");
                        return NULL;
                    }
                    result[maxLength + 1] = '\0';
                    int carry = 0;
                    for (int i = 0; i <= maxLength; i++) {
                        int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
                        int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; 
                        int sum = num1 - num2 + carry;
                        carry = sum >= 0 ? 0 : -1; 
                        sum = sum < 0? sum + 10 : sum;
                        result[maxLength - i] = (sum % 10) + '0'; 
                    } 
                    for (int i = 0; i < maxLength;) { 
                        if (result[i] == '0'){
                            result++;
                        }    
                        else{
                            break;
                        }
                    }
                    char *finalResult = malloc(129*sizeof(char)); 
                    finalResult[0] = '-'; 
                    strcpy(finalResult + 1, result); 
                    result = finalResult;
                    return result;
                } 
                else if (bigNumber1[i] < bigNumber2[i]){  
                    char *result = malloc((maxLength + 2) * sizeof(char)); 
                    if (result == NULL) {
                    printf("内存分配失败，程序错误\n");
                    return NULL;
                    }
                    result[maxLength + 1] = '\0'; 

                    int carry = 0;
                    for (int i = 0; i <= maxLength; i++) {
                        int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
                        int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; 
                        int sum = num2 - num1 + carry;
                        carry = sum >= 0 ? 0 : -1; 
                        sum = sum < 0? sum + 10 : sum;
                        result[maxLength - i] = (sum % 10) + '0'; 
                    }
                    for (int i = 0; i < maxLength;) { 
                        if (result[i] == '0'){
                            result++;
                        }
                        else{
                            break;
                        }
                    } 
                    return result;
                }
                else{
                    continue;
                } 
            } 
            char *result = malloc(2 * sizeof(char));
            result[0] = '0';
            result[1] = '\0';
            return result;
        }
    } 

    if (bigNumber1[0] != '(' && bigNumber2[0] == '(') { 
        bigNumber2 += 2; 
        int length_2 = strlen(bigNumber2); 
        bigNumber2[length_2 - 1] = '\0'; 
        
        int length1 = strlen(bigNumber2); 
        int length2 = strlen(bigNumber1); 
        
        if (length1 > length2){ 
            int maxLength = length1; 
            char *result = malloc((maxLength + 2) * sizeof(char));
            if (result == NULL) {
                printf("内存分配失败，程序错误\n");
                return NULL;
            }
                result[maxLength + 1] = '\0';
            int carry = 0;
            for (int i = 0; i <= maxLength; i++) {
                int num1 = i < length1 ? bigNumber2[length1 - 1 - i] - '0' : 0; 
                int num2 = i < length2 ? bigNumber1[length2 - 1 - i] - '0' : 0; 
                int sum = num1 - num2 + carry;
                carry = sum >= 0 ? 0 : -1; 
                sum = sum < 0? sum + 10 : sum;
                result[maxLength - i] = (sum % 10) + '0'; 
            } 
            for (int i = 0; i < maxLength;) { 
            if (result[i] == '0'){
                    result++;
                }
                else{
                break;
                }
            } 
            char *finalResult = malloc(129*sizeof(char)); 
            finalResult[0] = '-'; 
            strcpy(finalResult + 1, result); 
            result = finalResult;
            return result;
        } 
        else if(length1 < length2){ 
            int maxLength = length2; 
            char *result = malloc((maxLength + 2) * sizeof(char)); 
            if (result == NULL) {
                printf("内存分配失败，程序错误\n");
                return NULL;
            }
                result[maxLength + 1] = '\0'; 

            int carry = 0;
            for (int i = 0; i <= maxLength; i++) {
                int num1 = i < length1 ? bigNumber2[length1 - 1 - i] - '0' : 0; 
                int num2 = i < length2 ? bigNumber1[length2 - 1 - i] - '0' : 0; 
                int sum = num2 - num1 + carry;
                carry = sum >= 0 ? 0 : -1; 
                sum = sum < 0? sum + 10 : sum;
                result[maxLength - i] = (sum % 10) + '0'; 
            }
            for (int i = 0; i < maxLength;) { 
                if (result[i] == '0'){
                    result++;
                }
                else{
                    break;
                    }
                }                
                return result;
        } 
        else{  
            int maxLength = length1;  
            for (int i = 0; i < maxLength; i++){
                if (bigNumber2[i] > bigNumber1[i]){ 
                    char *result = malloc((maxLength + 2) * sizeof(char));
                    if (result == NULL) {
                        printf("内存分配失败，程序错误\n");
                        return NULL;
                    }
                    result[maxLength + 1] = '\0';
                    int carry = 0;
                    for (int i = 0; i <= maxLength; i++) {
                        int num1 = i < length1 ? bigNumber2[length1 - 1 - i] - '0' : 0; 
                        int num2 = i < length2 ? bigNumber1[length2 - 1 - i] - '0' : 0; 
                        int sum = num1 - num2 + carry;
                        carry = sum >= 0 ? 0 : -1; 
                        sum = sum < 0? sum + 10 : sum;
                        result[maxLength - i] = (sum % 10) + '0'; 
                    } 
                    for (int i = 0; i < maxLength;) { 
                        if (result[i] == '0'){
                            result++;
                        }    
                        else{
                            break;
                        }
                    }
                    char *finalResult = malloc(129*sizeof(char)); 
                    finalResult[0] = '-'; 
                    strcpy(finalResult + 1, result); 
                    result = finalResult;
                    return result;
                } 
                else if (bigNumber2[i] < bigNumber1[i]){  
                    char *result = malloc((maxLength + 2) * sizeof(char)); 
                    if (result == NULL) {
                    printf("内存分配失败，程序错误\n");
                    return NULL;
                    }
                    result[maxLength + 1] = '\0'; 

                    int carry = 0;
                    for (int i = 0; i <= maxLength; i++) {
                        int num1 = i < length1 ? bigNumber2[length1 - 1 - i] - '0' : 0; 
                        int num2 = i < length2 ? bigNumber1[length2 - 1 - i] - '0' : 0; 
                        int sum = num2 - num1 + carry;
                        carry = sum >= 0 ? 0 : -1; 
                        sum = sum < 0? sum + 10 : sum;
                        result[maxLength - i] = (sum % 10) + '0'; 
                    }
                    for (int i = 0; i < maxLength;) { 
                        if (result[i] == '0'){
                            result++;
                        }
                        else{
                            break;
                        }
                    } 
                    return result;
                }
                else{
                    continue;
                } 
            } 
            char *result = malloc(2 * sizeof(char));
            result[0] = '0';
            result[1] = '\0';
            return result;
        }
    } 
}

/**头文件 <stdio.h> <stdlib.h> <string.h>
 * @brief 该函数输入两个字符串数组的指针，将其相减，并返回一个指向和的字符串数组的指针
 * 
 * @param char *bigNumber1 输入一个字符串数组的指针，作为被减数 
 * @param char *bigNumber2 输入一个字符串数组的指针，作为减数
 * 
 * @return char * 一个指向和的字符串数组的指针
 */
char *bigNumberSub(char *bigNumber1, char *bigNumber2){ 
    if (bigNumber1[0] == '(' && bigNumber2[0] == '(') {
        bigNumber1 += 2; 
        int length_1 = strlen(bigNumber1); 
        bigNumber1[length_1 - 1] = '\0';  
        bigNumber2 += 2; 
        int length_2 = strlen(bigNumber2); 
        bigNumber2[length_2 - 1] = '\0'; 
        
        int length1 = strlen(bigNumber1); 
        int length2 = strlen(bigNumber2); 
        
        if (length1 > length2){ 
            int maxLength = length1; 
            char *result = malloc((maxLength + 2) * sizeof(char));
            if (result == NULL) {
                printf("内存分配失败，程序错误\n");
                return NULL;
            }
                result[maxLength + 1] = '\0';
            int carry = 0;
            for (int i = 0; i <= maxLength; i++) {
                int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
                int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; 
                int sum = num1 - num2 + carry;
                carry = sum >= 0 ? 0 : -1; 
                sum = sum < 0? sum + 10 : sum;
                result[maxLength - i] = (sum % 10) + '0'; 
            } 
            for (int i = 0; i < maxLength;) { 
            if (result[i] == '0'){
                    result++;
                }
                else{
                break;
                }
            } 
            char *finalResult = malloc(129*sizeof(char)); 
            finalResult[0] = '-'; 
            strcpy(finalResult + 1, result); 
            result = finalResult;
            return result;
        } 
        else if(length1 < length2){
            int maxLength = length2; 
            char *result = malloc((maxLength + 2) * sizeof(char)); 
            if (result == NULL) {
                printf("内存分配失败，程序错误\n");
                return NULL;
            }
                result[maxLength + 1] = '\0'; 

            int carry = 0;
            for (int i = 0; i <= maxLength; i++) {
                int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
                int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; 
                int sum = num2 - num1 + carry;
                carry = sum >= 0 ? 0 : -1; 
                sum = sum < 0? sum + 10 : sum;
                result[maxLength - i] = (sum % 10) + '0'; 
            }
            for (int i = 0; i < maxLength;) { 
                if (result[i] == '0'){
                    result++;
                }
                else{
                    break;
                    }
                }                
                return result;
        } 
        else{ 
            int maxLength = length1;  
            for (int i = 0; i < maxLength; i++){
                if (bigNumber1[i] > bigNumber2[i]){ 
                    char *result = malloc((maxLength + 2) * sizeof(char));
                    if (result == NULL) {
                        printf("内存分配失败，程序错误\n");
                        return NULL;
                    }
                    result[maxLength + 1] = '\0';
                    int carry = 0;
                    for (int i = 0; i <= maxLength; i++) {
                        int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
                        int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; 
                        int sum = num1 - num2 + carry;
                        carry = sum >= 0 ? 0 : -1; 
                        sum = sum < 0? sum + 10 : sum;
                        result[maxLength - i] = (sum % 10) + '0'; 
                    } 
                    for (int i = 0; i < maxLength;) { 
                        if (result[i] == '0'){
                            result++;
                        }    
                        else{
                            break;
                        }
                    }
                    char *finalResult = malloc(129*sizeof(char)); 
                    finalResult[0] = '-'; 
                    strcpy(finalResult + 1, result); 
                    result = finalResult;
                    return result;
                } 
                else if (bigNumber1[i] < bigNumber2[i]){  
                    char *result = malloc((maxLength + 2) * sizeof(char)); 
                    if (result == NULL) {
                    printf("内存分配失败，程序错误\n");
                    return NULL;
                    }
                    result[maxLength + 1] = '\0'; 

                    int carry = 0;
                    for (int i = 0; i <= maxLength; i++) {
                        int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
                        int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; 
                        int sum = num2 - num1 + carry;
                        carry = sum >= 0 ? 0 : -1; 
                        sum = sum < 0? sum + 10 : sum;
                        result[maxLength - i] = (sum % 10) + '0'; 
                    }
                    for (int i = 0; i < maxLength;) { 
                        if (result[i] == '0'){
                            result++;
                        }
                        else{
                            break;
                        }
                    } 
                    return result;
                }
                else{
                    continue;
                } 
            } 
            char *result = malloc(2 * sizeof(char));
            result[0] = '0';
            result[1] = '\0';
            return result;
        }
    }        
        
    if (bigNumber1[0] != '(' && bigNumber2[0] != '(') {        
        int length1 = strlen(bigNumber2); 
        int length2 = strlen(bigNumber1); 
        
        if (length1 > length2){ 
            int maxLength = length1; 
            char *result = malloc((maxLength + 2) * sizeof(char));
            if (result == NULL) {
                printf("内存分配失败，程序错误\n");
                return NULL;
            }
                result[maxLength + 1] = '\0';
            int carry = 0;
            for (int i = 0; i <= maxLength; i++) {
                int num1 = i < length1 ? bigNumber2[length1 - 1 - i] - '0' : 0; 
                int num2 = i < length2 ? bigNumber1[length2 - 1 - i] - '0' : 0; 
                int sum = num1 - num2 + carry;
                carry = sum >= 0 ? 0 : -1; 
                sum = sum < 0? sum + 10 : sum;
                result[maxLength - i] = (sum % 10) + '0'; 
            } 
            for (int i = 0; i < maxLength;) { 
            if (result[i] == '0'){
                    result++;
                }
            else{
                break;
                }
            } 
            char *finalResult = malloc(129*sizeof(char)); 
            finalResult[0] = '-'; 
            strcpy(finalResult + 1, result); 
            result = finalResult;
            return result;
        } 
        else if(length1 < length2){ 
            int maxLength = length2; 
            char *result = malloc((maxLength + 2) * sizeof(char)); 
            if (result == NULL) {
                printf("内存分配失败，程序错误\n");
                return NULL;
            }
                result[maxLength + 1] = '\0'; 

            int carry = 0;
            for (int i = 0; i <= maxLength; i++) {
                int num1 = i < length1 ? bigNumber2[length1 - 1 - i] - '0' : 0; 
                int num2 = i < length2 ? bigNumber1[length2 - 1 - i] - '0' : 0; 
                int sum = num2 - num1 + carry;
                carry = sum >= 0 ? 0 : -1; 
                sum = sum < 0? sum + 10 : sum;
                result[maxLength - i] = (sum % 10) + '0'; 
            }
            for (int i = 0; i < maxLength;) { 
                if (result[i] == '0'){
                    result++;
                }
                else{
                    break;
                    }
                }                
                return result;
        } 
        else{  
            int maxLength = length1;  
            for (int i = 0; i < maxLength; i++){
                if (bigNumber2[i] > bigNumber1[i]){ 
                    char *result = malloc((maxLength + 2) * sizeof(char));
                    if (result == NULL) {
                        printf("内存分配失败，程序错误\n");
                        return NULL;
                    }
                    result[maxLength + 1] = '\0';
                    int carry = 0;
                    for (int i = 0; i <= maxLength; i++) {
                        int num1 = i < length1 ? bigNumber2[length1 - 1 - i] - '0' : 0; 
                        int num2 = i < length2 ? bigNumber1[length2 - 1 - i] - '0' : 0; 
                        int sum = num1 - num2 + carry;
                        carry = sum >= 0 ? 0 : -1; 
                        sum = sum < 0? sum + 10 : sum;
                        result[maxLength - i] = (sum % 10) + '0'; 
                    } 
                    for (int i = 0; i < maxLength;) { 
                        if (result[i] == '0'){
                            result++;
                        }    
                        else{
                            break;
                        }
                    }
                    char *finalResult = malloc(129*sizeof(char)); 
                    finalResult[0] = '-'; 
                    strcpy(finalResult + 1, result); 
                    result = finalResult;
                    return result;
                } 
                else if (bigNumber2[i] < bigNumber1[i]){  
                    char *result = malloc((maxLength + 2) * sizeof(char)); 
                    if (result == NULL) {
                    printf("内存分配失败，程序错误\n");
                    return NULL;
                    }
                    result[maxLength + 1] = '\0'; 

                    int carry = 0;
                    for (int i = 0; i <= maxLength; i++) {
                        int num1 = i < length1 ? bigNumber2[length1 - 1 - i] - '0' : 0; 
                        int num2 = i < length2 ? bigNumber1[length2 - 1 - i] - '0' : 0; 
                        int sum = num2 - num1 + carry;
                        carry = sum >= 0 ? 0 : -1; 
                        sum = sum < 0? sum + 10 : sum;
                        result[maxLength - i] = (sum % 10) + '0'; 
                    }
                    for (int i = 0; i < maxLength;) { 
                        if (result[i] == '0'){
                            result++;
                        }
                        else{
                            break;
                        }
                    } 
                    return result;
                }
                else{
                    continue;
                } 
            } 
            char *result = malloc(2 * sizeof(char));
            result[0] = '0';
            result[1] = '\0';
            return result;
        }
    }        
    
    if (bigNumber1[0] == '(' && bigNumber2[0] != '(') {
        bigNumber1 += 2; 
        int length_1 = strlen(bigNumber1); 
        bigNumber1[length_1 - 1] = '\0'; 

        int length1 = strlen(bigNumber1);
        int length2 = strlen(bigNumber2);
        int maxLength = length1 > length2 ? length1 : length2; 

        char *result = malloc((maxLength + 2) * sizeof(char)); 
        if (result == NULL) {
            printf("内存分配失败，程序错误\n");
            return NULL;
        }
        result[maxLength + 1] = '\0'; 

        int carry = 0;
        for (int i = 0; i <= maxLength; i++) {
            int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
            int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            result[maxLength - i] = (sum % 10) + '0'; 
        }
        
        for (int i = 0; i < maxLength;) { 
            if (result[i] == '0'){
                    result++;
                }
            else{
                break;
            }
        } 
        char *finalResult = malloc(129*sizeof(char)); 
        finalResult[0] = '-'; 
        strcpy(finalResult + 1, result); 
        result = finalResult; 
        if (result[0] == '-' && result[1] == '\0'){
            result[0] = '0'; 
            result[1] = '\0';
        }
        return result; 
    } 

    if (bigNumber1[0] != '(' && bigNumber2[0] == '(') {
        bigNumber2 += 2; 
        int length_2 = strlen(bigNumber2); 
        bigNumber2[length_2 - 1] = '\0'; 

        int length1 = strlen(bigNumber1); 
        int length2 = strlen(bigNumber2); 
        int carry = 0;
        int maxLength = length1 > length2 ? length1 : length2; 
        char *result = malloc((maxLength + 2) * sizeof(char)); 
        if (result == NULL) {
            printf("内存分配失败，程序错误\n");
            return NULL;
        }
        result[maxLength + 1] = '\0'; 

        for (int i = 0; i <= maxLength; i++) {
            int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
            int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; 
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            result[maxLength - i] = (sum % 10) + '0'; 
        }

        for (int i = 0; i < maxLength;) { 
            if (result[i] == '0'){
                result++;
            }
            else{
                break;
            }
        } 
        if (result[0] == '\0'){
            result[0] = '0'; 
            result[1] = '\0';
        }
        return result;
    }
} 

/**头文件 <stdio.h> <stdlib.h> <string.h>
 * @brief 该函数输入两个字符串数组的指针，将其相乘，并返回一个指向和的字符串数组的指针
 * 
 * @param char *bigNumber1 输入一个字符串数组的指针 
 * @param char *bigNumber2 输入一个字符串数组的指针
 * 
 * @return char * 一个指向和的字符串数组的指针
 */
char *bigNumberMul(char *bigNumber1, char *bigNumber2){ 
    if (bigNumber1[0] == '(' && bigNumber2[0] == '('){ 
        bigNumber1 += 2; 
        int length_1 = strlen(bigNumber1); 
        bigNumber1[length_1 - 1] = '\0';  
        bigNumber2 += 2; 
        int length_2 = strlen(bigNumber2); 
        bigNumber2[length_2 - 1] = '\0'; 
    
        int length1 = strlen(bigNumber1); 
        int length2 = strlen(bigNumber2); 
        char *result = malloc(length1*length2 + 1);  //free 
            if (result == NULL){
                printf("内存分配失败，程序错误");
                return NULL;
            }
            result[0] = '0'; 
            result[1] = '\0'; 

        for (int i = 0; i < length1; i++) {
            int mul1 = bigNumber1[length1 - 1 -i] - '0'; 
            int carry1 = 0; 
            char *inresult1 = malloc(length1*length2 + 1); 
            if (inresult1 == NULL){
                printf("内存分配失败，程序错误");
                return NULL;
            } 
            inresult1[length1*length2] = '\0';
            
            for (int j = 0; j < length1*length2; j++){ 
                int mul2 = j < length2 ? bigNumber2[length2 - 1 - j] - '0' : 0;
                int sum = mul1*mul2 + carry1; 
                carry1 = sum/10;
                sum = sum%10; 
                inresult1[length1*length2 - 1 - j] = sum + '0';
            } 

            int times = 0;
            for (int j = 0; j < length1*length2;){
                if (inresult1[j] == '0'){
                    inresult1++; 
                    times++;
                }
                else{
                    break;
                }
            } 
            char *inresult2 = malloc(length1*length2 + 1);  
            if (inresult2 == NULL){
                printf("内存分配失败，程序错误");
                return NULL;
            } 
            for (int j = 0; j < i; j++){
                inresult2[j] = '0';
            } 
            if (i >= 1){
                inresult2[i] = '\0'; 
            } 
            else{
                inresult2[0] = '\0';
            } 

            strcat(inresult1, inresult2); 
            char *bigNumber1 = result; 
            char *bigNumber2 = inresult1;
            int length1 = strlen(bigNumber1); 
            int length2 = strlen(bigNumber2); 
            int carry2 = 0;
            int maxLength = length1 > length2 ? length1 : length2; 
            char *inresult3 = malloc((maxLength + 2) * sizeof(char)); 
            if (inresult3 == NULL) {
                printf("内存分配失败，程序错误\n");
                return NULL;
            }
            inresult3[maxLength + 1] = '\0'; 

            for (int j = 0; j <= maxLength; j++) { 
                int num1 = j < length1 ? bigNumber1[length1 - 1 - j] - '0' : 0; 
                int num2 = j < length2 ? bigNumber2[length2 - 1 - j] - '0' : 0; 
                int sum = num1 + num2 + carry2;
                carry2 = sum / 10;
                inresult3[maxLength - j] = (sum % 10) + '0'; 
            }

            for (int j = 0; j < (maxLength+1);){
                if (inresult3[j] == '0'){
                    inresult3++;
                } 
                else{ 
                    break;
                }
            } 
            result = inresult3; 
            inresult1 -= times;
            //free(inresult1); 
            inresult1 = NULL;
            free(inresult2); 
            inresult2 = NULL; 
        } 
        return result;
    } 

    if (bigNumber1[0] != '(' && bigNumber2[0] != '('){ 
        int length1 = strlen(bigNumber1); 
        int length2 = strlen(bigNumber2); 
        char *result = malloc(length1*length2 + 1);  //free 
            if (result == NULL){
                printf("内存分配失败，程序错误");
                return NULL;
            }
            result[0] = '0'; 
            result[1] = '\0'; 

        for (int i = 0; i < length1; i++) {
            int mul1 = bigNumber1[length1 - 1 -i] - '0'; 
            int carry1 = 0; 
            char *inresult1 = malloc(length1*length2 + 1); 
            if (inresult1 == NULL){
                printf("内存分配失败，程序错误");
                return NULL;
            } 
            inresult1[length1*length2] = '\0';
            
            for (int j = 0; j < length1*length2; j++){ 
                int mul2 = j < length2 ? bigNumber2[length2 - 1 - j] - '0' : 0;
                int sum = mul1*mul2 + carry1; 
                carry1 = sum/10;
                sum = sum%10; 
                inresult1[length1*length2 - 1 - j] = sum + '0';
            } 

            int times = 0;
            for (int j = 0; j < length1*length2;){
                if (inresult1[j] == '0'){
                    inresult1++; 
                    times++;
                }
                else{
                    break;
                }
            } 
            char *inresult2 = malloc(length1*length2 + 1);  
            if (inresult2 == NULL){
                printf("内存分配失败，程序错误");
                return NULL;
            } 
            for (int j = 0; j < i; j++){
                inresult2[j] = '0';
            } 
            if (i >= 1){
                inresult2[i] = '\0'; 
            } 
            else{
                inresult2[0] = '\0';
            } 

            strcat(inresult1, inresult2); 
            char *bigNumber1 = result; 
            char *bigNumber2 = inresult1;
            int length1 = strlen(bigNumber1); 
            int length2 = strlen(bigNumber2); 
            int carry2 = 0;
            int maxLength = length1 > length2 ? length1 : length2; 
            char *inresult3 = malloc((maxLength + 2) * sizeof(char)); 
            if (inresult3 == NULL) {
                printf("内存分配失败，程序错误\n");
                return NULL;
            }
            inresult3[maxLength + 1] = '\0'; 

            for (int j = 0; j <= maxLength; j++) { 
                int num1 = j < length1 ? bigNumber1[length1 - 1 - j] - '0' : 0; 
                int num2 = j < length2 ? bigNumber2[length2 - 1 - j] - '0' : 0; 
                int sum = num1 + num2 + carry2;
                carry2 = sum / 10;
                inresult3[maxLength - j] = (sum % 10) + '0'; 
            }

            for (int j = 0; j < (maxLength+1);){
                if (inresult3[j] == '0'){
                    inresult3++;
                } 
                else{ 
                    break;
                }
            } 
            result = inresult3; 
            inresult1 -= times;
            //free(inresult1); 
            inresult1 = NULL;
            free(inresult2); 
            inresult2 = NULL; 
        } 
        return result;
    } 

    if (bigNumber1[0] == '(' && bigNumber2[0] != '('){ 
        bigNumber1 += 2; 
        int length_1 = strlen(bigNumber1); 
        bigNumber1[length_1 - 1] = '\0'; 

        int length1 = strlen(bigNumber1); 
        int length2 = strlen(bigNumber2); 
        char *result = malloc(length1*length2 + 1);  //free 
            if (result == NULL){
                printf("内存分配失败，程序错误");
                return NULL;
            }
            result[0] = '0'; 
            result[1] = '\0'; 

        for (int i = 0; i < length1; i++) {
            int mul1 = bigNumber1[length1 - 1 -i] - '0'; 
            int carry1 = 0; 
            char *inresult1 = malloc(length1*length2 + 1); 
            if (inresult1 == NULL){
                printf("内存分配失败，程序错误");
                return NULL;
            } 
            inresult1[length1*length2] = '\0';
            
            for (int j = 0; j < length1*length2; j++){ 
                int mul2 = j < length2 ? bigNumber2[length2 - 1 - j] - '0' : 0;
                int sum = mul1*mul2 + carry1; 
                carry1 = sum/10;
                sum = sum%10; 
                inresult1[length1*length2 - 1 - j] = sum + '0';
            } 

            int times = 0;
            for (int j = 0; j < length1*length2;){
                if (inresult1[j] == '0'){
                    inresult1++; 
                    times++;
                }
                else{
                    break;
                }
            } 
            char *inresult2 = malloc(length1*length2 + 1);  
            if (inresult2 == NULL){
                printf("内存分配失败，程序错误");
                return NULL;
            } 
            for (int j = 0; j < i; j++){
                inresult2[j] = '0';
            } 
            if (i >= 1){
                inresult2[i] = '\0'; 
            } 
            else{
                inresult2[0] = '\0';
            } 

            strcat(inresult1, inresult2); 
            char *bigNumber1 = result; 
            char *bigNumber2 = inresult1;
            int length1 = strlen(bigNumber1); 
            int length2 = strlen(bigNumber2); 
            int carry2 = 0;
            int maxLength = length1 > length2 ? length1 : length2; 
            char *inresult3 = malloc((maxLength + 2) * sizeof(char)); 
            if (inresult3 == NULL) {
                printf("内存分配失败，程序错误\n");
                return NULL;
            }
            inresult3[maxLength + 1] = '\0'; 

            for (int j = 0; j <= maxLength; j++) { 
                int num1 = j < length1 ? bigNumber1[length1 - 1 - j] - '0' : 0; 
                int num2 = j < length2 ? bigNumber2[length2 - 1 - j] - '0' : 0; 
                int sum = num1 + num2 + carry2;
                carry2 = sum / 10;
                inresult3[maxLength - j] = (sum % 10) + '0'; 
            }

            for (int j = 0; j < (maxLength+1);){
                if (inresult3[j] == '0'){
                    inresult3++;
                } 
                else{ 
                    break;
                }
            } 
            result = inresult3; 
            inresult1 -= times;
            //free(inresult1); 
            inresult1 = NULL;
            free(inresult2); 
            inresult2 = NULL; 
        } 
        char *finalResult = malloc(129*sizeof(char)); 
        finalResult[0] = '-'; 
        strcpy(finalResult + 1, result); 
        result = finalResult;
        return result;
    } 

    if (bigNumber1[0] != '(' && bigNumber2[0] == '('){ 
        bigNumber2 += 2; 
        int length_2 = strlen(bigNumber2); 
        bigNumber2[length_2 - 1] = '\0'; 

        int length1 = strlen(bigNumber1); 
        int length2 = strlen(bigNumber2); 
        char *result = malloc(length1*length2 + 1);  //free 
            if (result == NULL){
                printf("内存分配失败，程序错误");
                return NULL;
            }
            result[0] = '0'; 
            result[1] = '\0'; 

        for (int i = 0; i < length1; i++) {
            int mul1 = bigNumber1[length1 - 1 -i] - '0'; 
            int carry1 = 0; 
            char *inresult1 = malloc(length1*length2 + 1); 
            if (inresult1 == NULL){
                printf("内存分配失败，程序错误");
                return NULL;
            } 
            inresult1[length1*length2] = '\0';
            
            for (int j = 0; j < length1*length2; j++){ 
                int mul2 = j < length2 ? bigNumber2[length2 - 1 - j] - '0' : 0;
                int sum = mul1*mul2 + carry1; 
                carry1 = sum/10;
                sum = sum%10; 
                inresult1[length1*length2 - 1 - j] = sum + '0';
            } 

            int times = 0;
            for (int j = 0; j < length1*length2;){
                if (inresult1[j] == '0'){
                    inresult1++; 
                    times++;
                }
                else{
                    break;
                }
            } 
            char *inresult2 = malloc(length1*length2 + 1);  
            if (inresult2 == NULL){
                printf("内存分配失败，程序错误");
                return NULL;
            } 
            for (int j = 0; j < i; j++){
                inresult2[j] = '0';
            } 
            if (i >= 1){
                inresult2[i] = '\0'; 
            } 
            else{
                inresult2[0] = '\0';
            } 

            strcat(inresult1, inresult2); 
            char *bigNumber1 = result; 
            char *bigNumber2 = inresult1;
            int length1 = strlen(bigNumber1); 
            int length2 = strlen(bigNumber2); 
            int carry2 = 0;
            int maxLength = length1 > length2 ? length1 : length2; 
            char *inresult3 = malloc((maxLength + 2) * sizeof(char)); 
            if (inresult3 == NULL) {
                printf("内存分配失败，程序错误\n");
                return NULL;
            }
            inresult3[maxLength + 1] = '\0'; 

            for (int j = 0; j <= maxLength; j++) { 
                int num1 = j < length1 ? bigNumber1[length1 - 1 - j] - '0' : 0; 
                int num2 = j < length2 ? bigNumber2[length2 - 1 - j] - '0' : 0; 
                int sum = num1 + num2 + carry2;
                carry2 = sum / 10;
                inresult3[maxLength - j] = (sum % 10) + '0'; 
            }

            for (int j = 0; j < (maxLength+1);){
                if (inresult3[j] == '0'){
                    inresult3++;
                } 
                else{ 
                    break;
                }
            } 
            result = inresult3; 
            inresult1 -= times;
            //free(inresult1); 
            inresult1 = NULL;
            free(inresult2); 
            inresult2 = NULL; 
        } 
        char *finalResult = malloc(129*sizeof(char)); 
        finalResult[0] = '-'; 
        strcpy(finalResult + 1, result); 
        result = finalResult;
        return result;
    }
} 

int setZero(int*num,int len){
	for(int i=0;i<len;i++)
		num[i]=0;
}

int compare(int*num1,int*num2){
	int i,j;
	for(i=999;num1[i]==0;i--);
	for(j=999;num2[j]==0;j--);
	if(i<j)return -1;
	else if(i>j)return 1;
	else{
		for(;i>=0;i--){
			if(num1[i]>num2[i])
				return 1;
			else if(num1[i]<num2[i])
				return -1;
		}
		return 0;
	}
} 

int copy(int*num1,int*num2){
	int i,j;
	for(i=0;i<1000;i++)
		num1[i]=0;
	for(i=999;num2[i]==0;i--);
	for(j=0;j<=i;j++)
		num1[j]=num2[j];
	return i+1;
}

/**头文件 <stdio.h> <stdlib.h> <string.h>;   函数 setZero(), compare(), copy();  全局变量 a[1000], b[1000], c[1000];
 * @brief 该函数输入两个字符串数组的指针，将其相除，输出结果
 * 
 * @param char *bigNumber1 输入一个字符串数组的指针，为被除数
 * @param char *bigNumber2 输入一个字符串数组的指针，为除数
 */
void bigNumberDiv(char *str1, char *str2){ 
    if (str1[0] == '(' && str2[0] == '('){
        str1 += 2; 
        int length_1 = strlen(str1); 
        str1[length_1 - 1] = '\0';  
        str2 += 2; 
        int length_2 = strlen(str2); 
        str2[length_2 - 1] = '\0'; 


		setZero(a,1000);
		setZero(b,1000);
		setZero(c,1000);
		
		int i,j,tmp,tmp2=0,borrow=0,temp[1000]={0},temp2[1000]={0};
		int len1=strlen(str1),len2=strlen(str2); //3
		for(i=0;i<len1;i++)
			a[i]=str1[len1-1-i]-'0'; //321
		for(i=0;i<len2;i++)
			b[i]=str2[len2-1-i]-'0';
		
		if(compare(a,b)<0){
			printf("0\n");
			return;
		}
		
		while(compare(a,b)>=0){			
			tmp=len1-len2;
			if(tmp==tmp2&&tmp>0)
				tmp--;
			tmp2=tmp;
			
			setZero(temp2,1000);
			for(i=len1-1;i>=tmp;i--)
				temp2[i]=b[i-tmp];
			copy(temp,a);
			
			if(compare(temp,temp2)<0)
					continue;
			for(j=1;;j++){
				borrow=0;
				for(i=tmp;i<len1;i++){
					temp[i]=a[i]-temp2[i]-borrow;
					if(temp[i]<0){
						borrow=1;
						temp[i]+=10;
					}
					else
						borrow=0;
				}
				
				len1=copy(a,temp);			
				c[tmp]=j;
				if(compare(temp,temp2)<0)
					break;
			}
		}

        printf("Result: ");
		for(i=999;c[i]==0;i--);
		for(;i>=0;i--)
			printf("%d",c[i]);
		printf("\n");
	} 

	if (str1[0] != '(' && str2[0] != '('){ 
		setZero(a,1000);
		setZero(b,1000);
		setZero(c,1000);
		
		int i,j,tmp,tmp2=0,borrow=0,temp[1000]={0},temp2[1000]={0};
		int len1=strlen(str1),len2=strlen(str2); //3
		for(i=0;i<len1;i++)
			a[i]=str1[len1-1-i]-'0'; //321
		for(i=0;i<len2;i++)
			b[i]=str2[len2-1-i]-'0';
		
		if(compare(a,b)<0){
			printf("0\n");
			return;
		}
		
		while(compare(a,b)>=0){			
			tmp=len1-len2;
			if(tmp==tmp2&&tmp>0)
				tmp--;
			tmp2=tmp;
			
			setZero(temp2,1000);
			for(i=len1-1;i>=tmp;i--)
				temp2[i]=b[i-tmp];
			copy(temp,a);
			
			if(compare(temp,temp2)<0)
					continue;
			for(j=1;;j++){
				borrow=0;
				for(i=tmp;i<len1;i++){
					temp[i]=a[i]-temp2[i]-borrow;
					if(temp[i]<0){
						borrow=1;
						temp[i]+=10;
					}
					else
						borrow=0;
				}
				
				len1=copy(a,temp);			
				c[tmp]=j;
				if(compare(temp,temp2)<0)
					break;
			}
		}
		
        printf("Result: ");
		for(i=999;c[i]==0;i--);
		for(;i>=0;i--)
			printf("%d",c[i]);
		printf("\n");
	} 

    if (str1[0] == '(' && str2[0] != '('){ 
        str1 += 2; 
        int length_1 = strlen(str1); 
        str1[length_1 - 1] = '\0'; 


		setZero(a,1000);
		setZero(b,1000);
		setZero(c,1000);
		
		int i,j,tmp,tmp2=0,borrow=0,temp[1000]={0},temp2[1000]={0};
		int len1=strlen(str1),len2=strlen(str2); //3
		for(i=0;i<len1;i++)
			a[i]=str1[len1-1-i]-'0'; //321
		for(i=0;i<len2;i++)
			b[i]=str2[len2-1-i]-'0';
		
		if(compare(a,b)<0){
			printf("0\n");
			return;
		}
		
		while(compare(a,b)>=0){			
			tmp=len1-len2;
			if(tmp==tmp2&&tmp>0)
				tmp--;
			tmp2=tmp;
			
			setZero(temp2,1000);
			for(i=len1-1;i>=tmp;i--)
				temp2[i]=b[i-tmp];
			copy(temp,a);
			
			if(compare(temp,temp2)<0)
					continue;
			for(j=1;;j++){
				borrow=0;
				for(i=tmp;i<len1;i++){
					temp[i]=a[i]-temp2[i]-borrow;
					if(temp[i]<0){
						borrow=1;
						temp[i]+=10;
					}
					else
						borrow=0;
				}
				
				len1=copy(a,temp);			
				c[tmp]=j;
				if(compare(temp,temp2)<0)
					break;
			}
		} 

        printf("Result: ");
		printf("-");
		for(i=999;c[i]==0;i--);
		for(;i>=0;i--)
			printf("%d",c[i]);
		printf("\n");
    } 

    if (str1[0] != '(' && str2[0] == '('){ 
        str2 += 2; 
        int length_2 = strlen(str2); 
        str2[length_2 - 1] = '\0'; 

		setZero(a,1000);
		setZero(b,1000);
		setZero(c,1000);
		
		int i,j,tmp,tmp2=0,borrow=0,temp[1000]={0},temp2[1000]={0};
		int len1=strlen(str1),len2=strlen(str2); //3
		for(i=0;i<len1;i++)
			a[i]=str1[len1-1-i]-'0'; //321
		for(i=0;i<len2;i++)
			b[i]=str2[len2-1-i]-'0';
		
		if(compare(a,b)<0){
			printf("0\n");
			return;
		}
		
		while(compare(a,b)>=0){			
			tmp=len1-len2;
			if(tmp==tmp2&&tmp>0)
				tmp--;
			tmp2=tmp;
			
			setZero(temp2,1000);
			for(i=len1-1;i>=tmp;i--)
				temp2[i]=b[i-tmp];
			copy(temp,a);
			
			if(compare(temp,temp2)<0)
					continue;
			for(j=1;;j++){
				borrow=0;
				for(i=tmp;i<len1;i++){
					temp[i]=a[i]-temp2[i]-borrow;
					if(temp[i]<0){
						borrow=1;
						temp[i]+=10;
					}
					else
						borrow=0;
				}
				
				len1=copy(a,temp);			
				c[tmp]=j;
				if(compare(temp,temp2)<0)
					break;
			}
		} 

        printf("Result: ");
		printf("-");
		for(i=999;c[i]==0;i--);
		for(;i>=0;i--)
			printf("%d",c[i]);
		printf("\n");



	}
}



int main(void){ 
    char expression[263];
    char operator;
    char *bigNumber1 = malloc(131 * sizeof(char));
    char *bigNumber2 = malloc(131 * sizeof(char));

    if (bigNumber1 == NULL || bigNumber2 == NULL) {
        printf("内存分配失败，程序错误\n");
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

    char *result = NULL;
    if (operator == '+'){
        result = bigNumberAdd(bigNumber1, bigNumber2);
        if (result == NULL) {
            return 1; 
        }
    } 
    else if (operator == '-'){
        result = bigNumberSub(bigNumber1, bigNumber2);
        if (result == NULL) {
            return 1; 
        }
    }
    else if (operator == '*'){
        result = bigNumberMul(bigNumber1, bigNumber2);
        if (result == NULL) {
            return 1;
        }
    } 
    else if (operator == '/'){
        bigNumberDiv(bigNumber1, bigNumber2);
    } 

    if (result != NULL) {
        printf("Result: %s\n", result);
        return 0;
    }
}