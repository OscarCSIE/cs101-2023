#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "AABBBCCCCddd";
    int count = 1;
    int j = 0;
    int len = (int)sizeof(str) / (int)sizeof(char) - 1;
    char encoded[len];
    for (int i = 0; i < len; i++) {
        if (str[i] == str[i + 1]) {
            count++;
        }
        else {
            encoded[j++] = str[i];
            if (count > 1) {
                sprintf(encoded + j, "%d", count);
                j += strlen(encoded + j);
                count = 1;
            }
        }
    }
    printf("%s\n", encoded);
    return 0;
}
