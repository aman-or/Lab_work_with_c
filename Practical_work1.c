#include "stdio.h"
#include "math.h"
#pragma warning(disable:4996)

void First() {
    double a = 0, res = 0, res_1 = 0, res_2 = 0, res_3 = 0;
    printf("Input a: ");
    scanf("%lf", &a);

    if (a <= 0) {  
        printf("Error: a must be greater than 0.\n");

    } else {
        res_1 = cos((pow(a, 2) + sqrt(a)) / (1 + (pow(sin(a), 2) / (2 * a))));
        res_2 = 2.5 / (2 * log(a));  
        res_3 = res_1 + res_2;
        if (res_3 < 0) {
            printf("Error: Result inside square root is negative.\n");
        } else {
            res = sqrt(res_3);
            printf("Result: %lf\n", res);
        }
    }
}

void Second() {
    float x = 0, z = 0, f = 0;
    printf("Input x: ");
    scanf("%f", &x);

    printf("Input z: ");
    scanf("%f", &z);

    f = (x > z && z > 1) ? ((x - z) / (z - 1)) : ((x <= 0 && z < 0) ? (2 * x * z) : (x + 1));
    printf("f = %f", f);
}

#include <stdio.h>
#include <math.h>

void Third() {
    float r = 0, a = 0, d = 0, s_circle = 0, s_triangle = 0, s_square = 0;
    const float pi = 3.14159265359; 
    float res = 0;
    const char* res_name; // Используем const char* для указателя на строку

    // радиус
    printf("Input R: ");
    scanf("%f", &r);

    // сторона треугольника
    printf("Input a: ");
    scanf("%f", &a);

    // квадрат
    printf("Input d: ");
    scanf("%f", &d);

    s_circle = pi * r * r;
    s_triangle = (a * a * sqrt(3)) / 4;
    s_square = d * d;

    res = (s_circle > s_square && s_circle > s_triangle) ? s_circle :
        ((s_square > s_circle && s_square > s_triangle) ? s_square : s_triangle);
    res_name = (s_circle == res) ? "Circle" : ((s_square == res) ? "Square" : "Triangle");

    printf("Max area is %s = %f\n", res_name, res); 
}


int main(void) {
    int n = 0;
    printf("Input number of Ex(1, 2, 3): ");
    scanf("%i", &n);
    switch (n) {
        case 1:
            First();
            break;
        case 2:
            Second();
            break;
        case 3:
            Third();
            break;
        default:
            printf("Number not in range");
            break;
    }
    return 0;
}
