#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSafe(int *array, int num);
int getTestDataFrmFile();
int doubleCheckSafe(int *array, int num);

int main(void) {
    printf("Hello, World!\n");
    printf("sum:%d",getTestDataFrmFile());
    return 0;
}

int getTestDataFrmFile(){
    int sum  = 0;
    FILE *fp = fopen("data.txt", "r");
    if (!fp) {
        perror("Open file failed");
    }
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        int numbers[100];
        int n = 0;
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            numbers[n++] = atoi(token);
            token = strtok(NULL, " \t\n");
        }
        if (isSafe(numbers,n) == 0) {
            if (doubleCheckSafe(numbers,n) == 1) {
                sum += 1;
            }
        } else {
            sum += 1;
        }
    }
    fclose(fp);
    return sum;
}

int isSafe(int *array, int num){
    if (num < 2) return 1;
    if (num == 2) return 1;
    signed int firstGap = *(array + 1) - *array;
    if (firstGap == 0)  return 0;
    int flag = 1;
    if(firstGap > 0){
        for (int index = 0; index <= num - 2; index++) {
            if ((*(array+index) >= *(array + index + 1)) || (abs(*(array+index) - *(array + index + 1)) > 3)){
                flag = 0;
                break;
            }
        }
    } else if(firstGap < 0){
        for (int index = 0; index <= num - 2; index++) {
            if ((*(array+index) <= *(array + index + 1)) || (abs(*(array+index) - *(array + index + 1)) > 3)) {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

int doubleCheckSafe(int *array, int num){
    int flag = 0;
    for (int index = 0; index <= num - 1; index++) {
        int newArr[num - 1];
        int* p = newArr;
        for (int innerIndex = 0; innerIndex <= num -1; innerIndex++) {
            if (innerIndex != index) {
                *p = *(array + innerIndex);
                p++;
            }
        }
        if (isSafe(newArr, num - 1) == 1) {
            flag = 1;
            break;
        }
    }
    return flag;
}
