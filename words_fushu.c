#include <stdio.h>
#include <string.h>

void fushu(char *word);
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char word[20] = {};
        scanf("%s", word);
        fushu(word);
        printf("%s\n", word);
    }
}

void fushu(char *word) {
    unsigned long long len = strlen(word);
    if (word[len - 1] == 'y') {
        word[len - 1] = 'i';
        word[len] = 'e';
        word[len + 1] = 's';
    } else if (word[len - 1] == 'o' || word[len - 1] == 's' || word[len - 1] == 'x' ||
               ((word[len - 2] == 'c' || word[len - 2] == 's') && word[len - 1] == 'h')) {
        word[len] = 'e';
        word[len + 1] = 's';
    } else {
        word[len] = 's';
    }
}

/*
7
country
abcs
defgx
hijklch
mnopqrsh
tuvwo
yzz
  */
