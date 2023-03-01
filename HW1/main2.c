#include <stdio.h>

int main() {
    char input[] = "A2B3C4d3";
    char output[100] = "";
    int i, j = 0;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            int num = input[i] - '0';
            while (num--) {
                output[j++] = input[i-1];
            }
        }
    }
    printf("%s\n", output);
    return 0;
}
