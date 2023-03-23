#include <stdio.h>

void replaceChars(char *str, char find, char replace){
    while (*str != '\0'){
        if (*str == find){
            *str = replace;
        }
        str++;
    }
}

int main(){
    char str[100];
    printf("Old string: ");
    fgets(str, sizeof(str), stdin);
    replaceChars(str, 'a', 'A');
    printf("New string: %s", str);
    return 0;
}
