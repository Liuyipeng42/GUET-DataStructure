#include <stdio.h>  //1900300922刘艺鹏
#include <string.h>

typedef struct student {
    char num[8];
    char name[8];
    int regular_grade;
    int test_grade;
    double total_grade;
} student;

int str_to_num(char s[]);
int str_to_list(char words[][8], char str[]);
void create_students(student s[], char words[][8], int k);
void get_and_save_total(student s[], int n);
void save_regular_test(student s[], int n);
void sort(student s[], int n);

int main() {
    student s[10];
    int k;
    char str[110], words[50][8];
    scanf("%s", str);
    k = str_to_list(words, str);
    create_students(s, words, k);
    get_and_save_total(s, k / 4);
    save_regular_test(s, k / 4);
    sort(s, k / 4);
    for (int i = 0; i < k / 4; i++) printf("%lf\n", s[i].total_grade);
    printf("\n");
    printf("%lf\n", s[0].total_grade);
    printf("%lf\n", s[k / 4 - 1].total_grade);

    return 0;
}

int str_to_list(char words[][8], char str[]) {
    char word[8] = {};
    int j = 0, k = 0;
    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] != ',' && str[i] != '\0') {
            word[j] = str[i];
            j++;
        } else {
            strcpy(words[k], word);
            k++;
            for (int l = 0; l < 8; l++) word[l] = '\0';
            j = 0;
        }
    }
    return k;
}

int str_to_num(char *p) {
    int num = 0;
    while (*p++) num = num * 10 + (int)*(p - 1) - 48;
    return num;
}

void create_students(student s[], char words[][8], int k) {
    int sn = 0;
    for (int i = 0; i < k; i++) {
        if (i % 4 == 0) strcpy(s[sn].num, words[i]);
        if (i % 4 == 1) strcpy(s[sn].name, words[i]);
        if (i % 4 == 2) s[sn].regular_grade = str_to_num(words[i]);
        if (i % 4 == 3) {
            s[sn].test_grade = str_to_num(words[i]);
            sn++;
        }
    }
}

void get_and_save_total(student s[], int n) {
    FILE *fp = fopen("T_data.txt", "w");
    for (int i = 0; i < n; i++) {
        s[i].total_grade = 0.2 * s[i].regular_grade + 0.8 * s[i].test_grade;
        fprintf(fp, "%.1lf\n", s[i].total_grade);
    }
}

void save_regular_test(student s[], int n) {
    FILE *fp = fopen("data.txt", "w");
    ;
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d %d\n", s[i].regular_grade, s[i].test_grade);
}

void sort(struct student s[], int n) {
    student temp;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (s[i].total_grade < s[j].total_grade) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

/*
测试输入1：1001,zs,78,65,1002,ls,80,89,1003,ww,90,85,1004,zs,80,60,1005,ls,82,85,1006,ww,96,88,1007,zs,70,76,1008,ls,83,87,1009,ww,60,84,1010,ww,69,74
预期输出1：
67.6
87.2
86.0
1002 ls
1001 zs

78  65
80  89
90  85
95  90
90  85
75  80
60  60
95  80
90  85
75  75


*/