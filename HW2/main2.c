#include <stdio.h>

int main() {
    FILE *fp;
    char c;
    int line_number = 1;
    fp = fopen(__FILE__, "r");
    if (fp) {
        printf("%02d ", line_number);
        while ((c = getc(fp)) != EOF) {
            putchar(c);
            if (c == '\n') {
                line_number++;
                printf("%02d ", line_number);
            }
        }
        fclose(fp);
    }
    printf("\n");
    return 0;
}
