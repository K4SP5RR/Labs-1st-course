#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

const int MAX_DISKS = 15; 

int towers[3][MAX_DISKS]; //матрица, содержащая размеры дисков на каждой из башен
int top[3]; //массив, содержащий количество дисков
int num_disks; //текущий диск
int count = 0; //текущий ход

void clear_screen() {
    system("cls");
}

void init_towers() {
    for (int i = 0; i < num_disks; i++) {
        towers[0][i] = num_disks - i;
        towers[1][i] = 0;
        towers[2][i] = 0;
    }
    top[0] = num_disks;
    top[1] = 0;
    top[2] = 0;
}

void draw_disk(int size) {
    if (size == 0) {
        printf("%*s|%*s", num_disks + 1, "", num_disks, "");
        return;
    }
    char disk_str[MAX_DISKS + 1];
    int i;
    for (i = 0; i < size; i++) {
        disk_str[i] = '=';
    }
    disk_str[i] = '\0';
    printf("%*s%s|%s%*s", num_disks - size + 1, "", disk_str, disk_str, num_disks - size, "");
}

void draw_towers() {
    clear_screen();
    printf("\n--- Ход %d ---\n", count++);
    for (int i = num_disks - 1; i >= 0; i--) {
        printf(" ");
        draw_disk(towers[0][i]);
        printf(" ");
        draw_disk(towers[1][i]);
        printf(" ");
        draw_disk(towers[2][i]);
        printf("\n");
    }
    int base_width = (num_disks * 2 + 1) * 3 + 4;
    for (int i = 0; i < base_width; i++) {
        printf("-");
    }
    printf("\n\n");
}

void move_and_draw(int from, int to) {
    int disk = towers[from][top[from] - 1];
    towers[to][top[to]] = disk;
    towers[from][top[from] - 1] = 0;
    top[from]--;
    top[to]++;

    draw_towers();
    Sleep(2000);
}

void hanoi_graphic(int n, int from, int to, int aux) {
    if (n == 0) {
        return;
    }
    hanoi_graphic(n - 1, from, aux, to);
    move_and_draw(from, to);
    hanoi_graphic(n - 1, aux, to, from);
}


int main() {
    setlocale(LC_ALL, "Russian");
    printf("Введите количество дисков (1-%d): ", MAX_DISKS);
    scanf_s("%d", &num_disks);
    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Неверное количество дисков.\n");
        return 1;
    }

    init_towers();
    draw_towers();
    Sleep(1500);
    hanoi_graphic(num_disks, 0, 2, 1);

    return 0;
}