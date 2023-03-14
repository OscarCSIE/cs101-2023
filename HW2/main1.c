#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

FILE* fp;
int num[7];

void get_rand(){
    for(int i = 0 ; i < 6 ; i++){
        num[i] = rand() % 69 + 1;
        for(int j = 0 ; j < i ; j++){
            if(num[i] == num[j]){
                num[i]++;
            }
        }
    }
    qsort(num , 6 , sizeof(int) , cmpfunc);
    for(int i = 0 ; i < 6 ; i++){
        if(num[i] == 68){
            num[i] -= 6 - i;
        }
    }
    for(int i = 0 ; i < 6 ; i++){
        fprintf(fp,"%02d ",num[i]);
    }
}

int main(){
    int n;
    srand(time(NULL));
    printf("歡迎光臨長庚樂透購買機台\n");
    printf("請問您要購買幾組樂透: ");
    scanf("%d", &n);
    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
    fp = fopen("lotto.txt", "w+");
    fprintf(fp, " ========= lotto649 =========\n");
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char date[100];
    strftime(date, 100, " = %a %b %01d %H:%M:%S %Y =", tm_info);
    //date[11];
    if((int)date[11] == 0){
        for(int i = 0 ; i < 11 ; i++){
            fprintf(fp,"%c",date[i]);
        }
        for(int i = 12 ; i < 100 ; i++){
            if(date[i]='\0'){
                break;
            }
            fprintf(fp,"%c",date[i]);
        }
    }else{
        fprintf(fp,"%s", date);
    }
    fprintf(fp,"\n");
    for(int i = 0 ; i < 5 ; i++){
        if(i < n){
            fprintf(fp," [%d]:  ", i + 1);
            get_rand();
            num[7] = rand()%9 + 1;
            if((num[7] == num[0]) && num[0] != 1){
                num[7]--;
            }else if((num[7] == num[0]) && num[0] == 1){
                num[7]++;
            }
            fprintf(fp,"%02d\n",num[7]);
        }else{
            fprintf(fp," [%d]: -- -- -- -- -- -- --\n", i + 1);
        }
    }
    fprintf(fp," ========= csie@CGU =========\n");
    return 0;
}
