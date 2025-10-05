#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"


void Delete(char** mas, int index, int n) {
    if (n == 1)
    {
        free(mas[0]);
        return;

    }
    for (int i = index; i < n-1; i++)
    {
        strcpy_s(mas[i], sizeof(mas[i]), mas[i + 1]);
    }
    return;
}

int main() {
    int n;
    scanf_s("%d", &n);
    getchar();
    char** mas;
    mas = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        mas[i] = (char*)malloc(256 * sizeof(char));

    }
    for (int i = 0; i < n; i++) {
        fgets(mas[i], sizeof(mas[i]), stdin);
    }

    for (int i = 0; i < n; i++) {
        while (strchr("eyuioa", mas[i][0]) != NULL and i < n) {
            Delete(mas, i, n);
            n--;
        }
    }
    printf_s("\n\n");

    for (int i = 0; i < n; i++)
    {
        printf_s("%s", mas[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        free(mas[i]);
    }
    free(mas);
    return 0;
}