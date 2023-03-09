#include <stdio.h>

int main(){
    int a[] = {1,2,3};
    int a1[3];
    char b[] = "ABC";
    float c[] = {1.1,1.2,1.3};
    FILE* fp;
    fp = fopen("a.bin","wb+");
    fwrite(a , sizeof(int) , 3 ,fp);
    fseek(fp , 0 , SEEK_SET);
    fread(a1 , sizeof(a1) , 1 , fp);
    for(int i = 0 ; i < 3 ; i++){
        printf("%d", a1[i]);
    }
    return 0;
}
