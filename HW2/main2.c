#include <stdio.h>

int main() {
    FILE *fp;
    FILE *output;
    char c;
    int line_number = 1;
    fp = fopen(__FILE__, "r");
    output = fopen("main2.txt", "w");
    if (fp && output){
        fprintf(output,"%02d ", line_number);
        while ((c = getc(fp)) != EOF){
            fputc(c, output);
            if (c == '\n'){
                line_number++;
                fprintf(output,"%02d ", line_number);
            }
        }
        fclose(fp);
        fclose(output);
    }
    fprintf(output,"\n");
    return 0;
}
