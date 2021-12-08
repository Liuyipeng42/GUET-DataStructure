#include <stdio.h>
int main() {
    int score[40], count[11] = {0};
    for (int i = 0; i < 40; i++) 
        scanf("%d", &score[i]);
    for (int j = 0; j < 40; j++) 
        count[score[j]]++;
    for (int k = 1; k < 11; k++) {
        printf("%d\t%d\t", k, count[k]);
        for (int l = 0; l < count[k]; l++) 
            printf("*");
        printf("\n");
    }
    return 0;
}
