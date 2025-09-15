#include <stdio.h>
#include <stdlib.h>

void quickSort(int* pointer);
int distance(int* fst, int* snd);

int main(void) {
    FILE *fp = fopen("data.txt", "r");
    if (!fp) {
        perror("Open file failed");
        return 1;
    }

    int fst[1000], snd[1000];
    int n = 0;
    while (fscanf(fp, "%d %d", &fst[n], &snd[n]) == 2) {
        n++;
    }
    fclose(fp);
    quickSort(fst);
    quickSort(snd);
    printf("sum: %d",distance(fst,snd));
    return 0;
}

void quickSort(int* pointer){
    int length =  1000;
    for (int round = 0; round < length -1; round ++) {
        for(int index = 0; index < length - round - 1; index ++){
            if (*(pointer+index) > *(pointer + index + 1)) {
                int temp = *(pointer + index);
                *(pointer + index) = *(pointer + index + 1);
                *(pointer + index + 1) = temp;
            }
        }
    }
}

int distance(int* fst, int* snd){
    int sum  = 0;
    int length =  1000;
    for (int index =0; index < length; index++) {
        sum += abs(*(fst + index) - *(snd + index));
    }
    return sum;
}
