#include <stdio.h>
#include <cs50.h>

int main(void){
    int wm_stock = 5;
    int wm_price = 10000;
    int order = 3;

    printf("주문건수 : %d건\n", order);
    printf("기존 재고량 : %d개\n", wm_stock);
    printf("남은 재고량 : %d개\n", wm_stock - order);
    printf("매출액(부가세포함) : %.f원\n", wm_price * order * 1.1);
}
