#include <stdio.h> 
#include <malloc.h> 

/**头文件 <stdio.h> <malloc.h> 
 * @brief 该函数用scanf输入个一个大数的位数与其字符串数组，在堆中存储，并返回一个指向该字符串数组的指针
 * 
 * @param void 无参数输入
 * 
 * @return 一个指向该字符串数组的指针
 */
char *getBigNumberPtr(void) {
    int digits; 
    printf("Digits:"); 
    scanf("%d", &digits); 

    char *bigNumber = malloc((digits+1)*sizeof(char));  
    if (bigNumber == NULL) 
    {
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

int main(void) {
    char *bigNumber = getBigNumberPtr(); 
    printf("The Big Number:%s\n", bigNumber); 
    free(bigNumber); 
    return 0;
}