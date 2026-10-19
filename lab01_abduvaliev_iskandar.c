#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void sort(int a[], int n) {
    int i, j, tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void print(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int a[MAX];
    int n, i;

    if (argc < 2) {
        printf("Введите числа: %s 5 3 8 1\n", argv[0]);
        return 1;
    }

    n = argc - 1;

    for (i = 0; i < n; i++) {
        a[i] = atoi(argv[i + 1]);
    }

    printf("До сортировки: ");
    print(a, n);

    sort(a, n);

    printf("После сортировки: ");
    print(a, n);

    return 0;
}