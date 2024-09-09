#include "stdio.h"
#pragma warning(disable:4996)

void First() {
    int a = 0, b = 0, i = 2, res = 0, min = 0;

    printf("input A = ");
    scanf("%d", &a);

    printf("input B = ");
    scanf("%d", &b);

    min = (a < b) ? a : b;
    for (i; i <= min; i++) {
        if (a % i == 0 && b % i == 0) {
            res += 1;
            break;
        }
    }
    printf((res == 0) ? "YES" : "NO");
}

void Second() {
    int a = 0, b = 0, c = 0, res = 0, min = 0, i = 1;
    printf("input a = ");
    scanf("%d", &a);

    printf("input b = ");
    scanf("%d", &b);

    printf("input c = ");
    scanf("%d", &c);

    min = (a > b && a > c) ? a : ((b > a && b > c) ? b : c);

    for (i; i <= min; i++) {
        if (a % i == 0 && b % i == 0 && c % i == 0) {
            res = i;
        }
    }
    printf("NOD = %d", res);
}

int main(void) {
    int n = 0;

    printf("Input number of Ex(1, 2): ");
    scanf("%d", &n);
    switch (n) {
    case 1:
        First();
        break;
    case 2:
        Second();
        break;
    default:
        printf("Number not in range");
        break;
    }
    return 0;
}