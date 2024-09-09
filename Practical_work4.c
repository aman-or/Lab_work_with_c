#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#pragma warning(disable:4996)

#define N 5 // for First
#define M 6 // for First
#define found_size 3 // for First 

#define N_for_third 35

void Vvod(int* Arr, int size, int ex) {
    if (ex == 1) {
        for (int i = 0; i < size; i++)
            Arr[i] = 0 + rand() % 2;
    }

    if (ex == 2) {
        for (int i = 0; i < size; i++)
            Arr[i] = rand() % 100 - 50;
    }
}

void Vyvod(int* Arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%3d ", Arr[i]);
}

void First() {
    srand(time(NULL));
    int Matrix[N][M];
    int found = 0;

    for (int i = 0; i < N; i++) {
        Vvod(&Matrix[i][0], M, 1);
    }

    for (int i = 0; i < N; i++) {
        Vyvod(&Matrix[i][0], M);
        printf("\n");
    }

    for (int i = 0; i <= N - found_size; i++) {
        if (found) break;
        for (int j = 0; j < M - found_size; j++) {
            int isZero = 1;
            for (int k = 0; k < found_size; k++) {
                for (int l = 0; l < found_size; l++) {
                    if (Matrix[i + k][j + l] != 0) {
                        isZero = 0;
                        break;
                    }
                }
                if (isZero == 0) break;
            }
            if (isZero == 1) {
                printf("\nWe found matrix in size %d with starts index (%d, %d)\n", found_size, i, j);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("\nMatrix size %d - not found", found_size);
    }

}

void Second() {
    srand(time(NULL));
    int B[M][N], C[N][M];
    //Array B
    printf("Array B:\n");
    for (int i = 0; i < M; i++) {
        Vvod(&B[i][0], N, 2);
    }

    for (int i = 0; i < M; i++) {
        Vyvod(&B[i][0], N);
        printf("\n");
    }
    
    //Array C
    printf("\nArray C:\n");
    for (int i = 0; i < N; i++) {
        Vvod(&C[i][0], M, 2);
    }

    for (int i = 0; i < N; i++) {
        Vyvod(&C[i][0], M);
        printf("\n");
    }

    printf("Cols of Array B: ");
    for (int j = 0; j < N; j++) {
        int check = 0;
        for (int i = 0; i < M; i++) {
            if (B[i][j] < 0) check++;
        }
        if (check == 2) {
            printf("%d ", j + 1);
        }
    }

    printf("\nCols of Array C: ");
    for (int j = 0; j < M; j++) {
        int check = 0;
        for (int i = 0; i < N; i++) {
            if (C[i][j] < 0) check++;
        }
        if (check == 2) {
            printf("%d ", j + 1);
        }
    }
}


double f1(double x) {
    return sqrt(1 + x + pow(x, 2));
}

double f2(double x) {
    return x * sin(x);
}

double Integral(double (*fun)(double), double a, double b) {
    double h, res = 0;

    h = (b - a) / N_for_third;
    res += fun(a) / 2.0;
    res += fun(a) / 2.0;

    for (int i = 1; i < N_for_third; i++) {
        double x = a + i * h;
        res += fun(x);
    }
    return res * h;
}


//sqrt(1 + x + pow(x, 2)) dx
//x * sin(x) dx
// N = 35 - трапеция
void Third() {
    printf("Function 1: %lf\n", Integral(f1, -2, 2));
    printf("Function 2: %lf\n", Integral(f2, 0.5, 4));
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