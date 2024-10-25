#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h> 

/**头文件 <stdio.h> <malloc.h> <stdbool.h> 
 * @brief 该函数用scanf输入个一个大数的位数与其字符串数组，在堆中存储，并返回一个指向该字符串数组的指针
 * 
 * @param void 无参数输入
 * 
 * @return 一个指向该字符串数组的指针
 */
char *getBigNumberPtr(void) {
    int digits, boolvalue; 
    printf("Digits:"); 
    scanf("%d", &digits); 
    printf("Negative?(0 for false, any other number for true)"); 
    scanf("%d", &boolvalue);
    if (boolvalue != 0){
        digits++;
    }

    char *bigNumber = malloc((digits+1)*sizeof(char)); 
    if (bigNumber == NULL) {
        printf("内存分配失败，程序错误");
        return NULL; 
    } 
    bigNumber[0] = '\0'; 
    printf("Number:"); 
    scanf("%s", bigNumber); 
    return bigNumber; 
} 

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
char *bigNumberAdd(char *bigNumber1, char *bigNumber2) { 
    if (bigNumber1[0] == '-' && bigNumber2[0] == '-') {
        bigNumber1++; 
        bigNumber2++;

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
        for (int i = 0; i < maxLength; i++) {
            int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
            int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            result[maxLength - i] = (sum % 10) + '0'; 
        }

        if (carry) {
            result[0] = carry + '0';  
            char *finalResult = malloc(129*sizeof(char)); 
            finalResult[0] = '-'; 
            strcpy(finalResult + 1, result); 
            result = finalResult;
        } else {
            result[0] = '-'; 
        }
        return result; 
    }
    
    if (bigNumber1[0] != '-' && bigNumber2[0] != '-') {
        int length1 = strlen(bigNumber1); //123\0 3
        int length2 = strlen(bigNumber2); //123\0 3
        int carry = 0;
        int maxLength = length1 > length2 ? length1 : length2; //3

    
        char *result = malloc((maxLength + 2) * sizeof(char)); //5 result[4]
        if (result == NULL) {
            printf("内存分配失败，程序错误\n");
            return NULL;
        }
        result[maxLength + 1] = '\0'; //result[4]

        for (int i = 0; i < maxLength; i++) {
            int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; //2 1 0
            int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; //2 1 0
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            result[maxLength - i] = (sum % 10) + '0'; //3 2 1
        }

        if (carry) {
            result[0] = carry + '0';
            return result;
        } 
        else {
        return result + 1; 
        }
    }
    
    if (bigNumber1[0] == '-' && bigNumber2[0] != '-') {
        bigNumber1++; 
        
        int length1 = strlen(bigNumber1); 
        int length2 = strlen(bigNumber2); 
        
        if (length1 > length2){
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
                for (int i = 0; i < maxLength; i++) {
                    int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
                    int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; 
                    int sum = num1 - num2 + carry;
                    carry = num1 >= num2 ? 0 : -1;
                    result[maxLength - i] = (sum % 10) + '0'; 
                } 
                for (int i = 0; i < maxLength; i++) { 
                    if (result[i] == '0'){
                        result++;
                    }
                    else{
                        break;
                    }
                } 
                if (carry) {
                    result[0] = carry + '0';  
                    char *finalResult = malloc(129*sizeof(char)); 
                    finalResult[0] = '-'; 
                    strcpy(finalResult + 1, result); 
                    result = finalResult;
                } 
                else {
                    result[0] = '-'; 
                }
                return result;
                } 
            }
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
            for (int i = 0; i < maxLength; i++) {
                int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; //2 1 0
                int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; //2 1 0
                int sum = num2 - num1 + carry;
                carry = num2 >= num1 ? 0 : -1;
                result[maxLength - i] = (sum % 10) + '0'; 
            }
            for (int i = 0; i < maxLength; i++) { 
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
                for (int i = 0; i < maxLength; i++) {
                    int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; 
                    int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; 
                    int sum = num1 - num2 + carry;
                    carry = num1 >= num2 ? 0 : -1;
                    result[maxLength - i] = (sum % 10) + '0'; 
                } 
                for (int i = 0; i < maxLength; i++) { 
                    if (result[i] == '0'){
                        result++;
                    }
                    else{
                        break;
                    }
                } 
                if (carry) {
                    result[0] = carry + '0';  
                    char *finalResult = malloc(129*sizeof(char)); 
                    finalResult[0] = '-'; 
                    strcpy(finalResult + 1, result); 
                    result = finalResult;
                } 
                else {
                    result[0] = '-'; 
                }
                return result;
                } 
                else if (bigNumber1[i] < bigNumber2[i]){ //正数 
                    char *result = malloc((maxLength + 2) * sizeof(char)); 
                    if (result == NULL) {
                    printf("内存分配失败，程序错误\n");
                    return NULL;
                    }
                result[maxLength + 1] = '\0'; 

                int carry = 0;
                for (int i = 0; i < maxLength; i++) {
                    int num1 = i < length1 ? bigNumber1[length1 - 1 - i] - '0' : 0; //2 1 0
                    int num2 = i < length2 ? bigNumber2[length2 - 1 - i] - '0' : 0; //2 1 0
                    int sum = num2 - num1 + carry;
                    carry = num2 >= num1 ? 0 : -1;
                    result[maxLength - i] = (sum % 10) + '0'; 
                }
                for (int i = 0; i < maxLength; i++) { 
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
        }
    } 

    if (bigNumber1[0] != '-' && bigNumber2[0] == '-') { 
        bigNumber2++; 
        
        int length1 = strlen(bigNumber2); 
        int length2 = strlen(bigNumber1); 
        
        if (length1 > length2){
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
                for (int i = 0; i < maxLength; i++) {
                    int num1 = i < length1 ? bigNumber2[length1 - 1 - i] - '0' : 0; 
                    int num2 = i < length2 ? bigNumber1[length2 - 1 - i] - '0' : 0; 
                    int sum = num1 - num2 + carry;
                    carry = num1 >= num2 ? 0 : -1;
                    result[maxLength - i] = (sum % 10) + '0'; 
                } 
                for (int i = 0; i < maxLength; i++) { 
                    if (result[i] == '0'){
                        result++;
                    }
                    else{
                        break;
                    }
                } 
                if (carry) {
                    result[0] = carry + '0';  
                    char *finalResult = malloc(129*sizeof(char)); 
                    finalResult[0] = '-'; 
                    strcpy(finalResult + 1, result); 
                    result = finalResult;
                } 
                else {
                    result[0] = '-'; 
                }
                return result;
                } 
            }
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
            for (int i = 0; i < maxLength; i++) {
                int num1 = i < length1 ? bigNumber2[length1 - 1 - i] - '0' : 0; //2 1 0
                int num2 = i < length2 ? bigNumber1[length2 - 1 - i] - '0' : 0; //2 1 0
                int sum = num2 - num1 + carry;
                carry = num2 >= num1 ? 0 : -1;
                result[maxLength - i] = (sum % 10) + '0'; 
            }
            for (int i = 0; i < maxLength; i++) { 
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
                for (int i = 0; i < maxLength; i++) {
                    int num1 = i < length1 ? bigNumber2[length1 - 1 - i] - '0' : 0; 
                    int num2 = i < length2 ? bigNumber1[length2 - 1 - i] - '0' : 0; 
                    int sum = num1 - num2 + carry;
                    carry = num1 >= num2 ? 0 : -1;
                    result[maxLength - i] = (sum % 10) + '0'; 
                } 
                for (int i = 0; i < maxLength; i++) { 
                    if (result[i] == '0'){
                        result++;
                    }
                    else{
                        break;
                    }
                } 
                if (carry) {
                    result[0] = carry + '0';  
                    char *finalResult = malloc(129*sizeof(char)); 
                    finalResult[0] = '-'; 
                    strcpy(finalResult + 1, result); 
                    result = finalResult;
                } 
                else {
                    result[0] = '-'; 
                }
                return result;
                } 
                else if (bigNumber2[i] < bigNumber1[i]){ //正数 
                    char *result = malloc((maxLength + 2) * sizeof(char)); 
                    if (result == NULL) {
                    printf("内存分配失败，程序错误\n");
                    return NULL;
                    }
                result[maxLength + 1] = '\0'; 

                int carry = 0;
                for (int i = 0; i < maxLength; i++) {
                    int num1 = i < length1 ? bigNumber2[length1 - 1 - i] - '0' : 0; //2 1 0
                    int num2 = i < length2 ? bigNumber1[length2 - 1 - i] - '0' : 0; //2 1 0
                    int sum = num2 - num1 + carry;
                    carry = num2 >= num1 ? 0 : -1;
                    result[maxLength - i] = (sum % 10) + '0'; 
                }
                for (int i = 0; i < maxLength; i++) { 
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
        }
    } 
}


int main(void) {
    char *bigNumber1 = getBigNumberPtr(); 
    if (bigNumber1 == NULL) return 1; 

    char *bigNumber2 = getBigNumberPtr(); 
    if (bigNumber2 == NULL) {
        freeBigNumberPtr(bigNumber1);
        return 1; 
    }

    char *sum = bigNumberAdd(bigNumber1, bigNumber2);
    if (sum == NULL) {
        freeBigNumberPtr(bigNumber1);
        freeBigNumberPtr(bigNumber2);
        return 1; 
    }

    printf("Sum = %s\n", sum);
    freeBigNumberPtr(bigNumber1);
    freeBigNumberPtr(bigNumber2);
    return 0;
}