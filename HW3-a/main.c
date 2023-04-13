#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char buffer[80];

void hanoi(FILE* fp, int n, char A, char B, char C) {
    static int step = 1;
    if (n == 1) {
        time_t rawtime;
        struct tm* timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, 80, "(%Y %m%d %H:%M:%S)", timeinfo);
        char sheet_name[3];
        sprintf(sheet_name, "%dP", n);
        fprintf(fp, "Step %d: Current system time is %s. Move sheet %s from %c to %c\n",
        step, buffer, sheet_name, A, C);
        step++;
    }else{
        hanoi(fp, n - 1, A, C, B);
        char sheet_name[3];
        sprintf(sheet_name, "%dP", n);
        fprintf(fp, "Step %d: Current system time is %s. Move sheet %s from %c to %c\n", step, buffer,sheet_name, A, B);
        step++;
        hanoi(fp, n - 1, B, A, C);
    }
}

int main() {
    int n;
    printf("Please enter the number of disks: ");
    scanf("%d", &n);
    FILE* fp = fopen("Hanoi.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    hanoi(fp, n, 'A', 'B', 'C');
    fclose(fp);
    printf("Output written to file Hanoi.txt\n");
    return 0;
}
