#include<stdio.h>

double add(double x, double y){
    return x + y;
}
double dif(double x, double y){
    return x - y;
}
double mul(double x, double y){
    return x * y;
}
double divi(double x, double y){
    return x / y;
}

double calc(double (*func_ptr)(double, double), double x, double y){
    return func_ptr(x , y);
}
int main(){
    printf("sum = %.1f\n",calc(add, 69, 420));
    printf("dif = %.2f\n",calc(dif, 69, 420));
    printf("product = %.3f\n",calc(mul, 69, 420));
    printf("quotient = %.4f\n",calc(divi, 69, 420));
    return 0;
}
