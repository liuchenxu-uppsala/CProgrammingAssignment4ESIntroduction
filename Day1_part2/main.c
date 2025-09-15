#include <stdio.h>
int individualValue(int value, int* snd);
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
    int sum = 0;
    for (int index = 0; index < 1000; index++) {
        sum += individualValue(*(fst + index), snd);
    }
    printf("%d",sum);

    return 0;
}

int individualValue(int value, int* snd){
    int times = 0;
    for (int index = 0; index < 1000; index++) {
        if (*(snd + index) == value) {
            times++;
        }
    }
    return value * times;
}
