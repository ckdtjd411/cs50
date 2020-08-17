#include <stdio.h>
#include <cs50.h>

int main(void) {
    int principal = get_int("목표금액 : ");
    printf("만기시 : %.f\n", principal * 1.012);
}
