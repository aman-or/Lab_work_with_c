#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define N 50
#define m 8

void First() {
    int array[N], res_array[N], t = 0;


    for (int i = 0; i < N; i++) {
        array[i] = 1 + rand() % 100;
    }

    printf("Base array: \n [");
    for (int i = 0; i < N; i++) {
        printf("%i ", array[i]);
    }
    printf("]");
    for (int i = 0; i < N; i++) {
        if (array[i] % 3 != 0 && array[i] % 5 != 0) {
            res_array[t] = array[i];
            t++;
        }
    }

    printf("\nResult array: \n [");
    for (int i = 0; i < t; i++) {
        printf("%i ", res_array[i]);
    }
    printf("]");
}

void Second() {

    int A[m][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = 1 + rand() % 100;
        }
    }

    printf("Base matrix: \n ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("\t%i ", A[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] -= A[m-1][j];
        }
    }

    printf("Result matrix: \n ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("\t%i ", A[i][j]);
        }
        printf("\n");
    }
}

void Third() {
    int** DynMatrix, dyn_m = 0, dyn_n = 0, res_max = -99, max = -99, temp = 1;
    printf("Input m: ");
    scanf("%i", &dyn_m);

    printf("Input n: ");
    scanf("%i", &dyn_n);

    DynMatrix = (int**)malloc(dyn_m * sizeof(int*));
    
    for (int i = 0; i < dyn_m; i++) {
        DynMatrix[i] = (int*)malloc(dyn_n * sizeof(int));
    }

    //find max
    for (int i = 0; i < dyn_m; i++) {
        for (int j = 0; j < dyn_n; j++) {
            DynMatrix[i][j] = 1 + rand() % 20;
            max = DynMatrix[i][j];
            if (res_max < max) {
                res_max = max;
            }
        }
    }

    for (int i = 0; i < dyn_m; i++) {
        for (int j = 0; j < dyn_n; j++) {
            printf("\t%i ", DynMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Max = %i\n", res_max);

    //find max index
    printf("Indexes: \n");
    for (int i = 0; i < dyn_m; i++) {
        for (int j = 0; j < dyn_n; j++) {
            if (DynMatrix[i][j] == res_max) {
                printf("[%i; %i]\n", i, j);
            }
        }
    }
   

    for (int i = 0; i < dyn_m; i++) {
        free(DynMatrix[i]);  // Освобождение каждой строки
    }
    free(DynMatrix);  // Освобождение массива указателей

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