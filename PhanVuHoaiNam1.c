#include <stdio.h>
#include <string.h>

void bt1_1() {
    char xau1[100], xau2[100];

    printf("Nhap xau 1: ");
    scanf("%s", xau1);
    printf("Nhap xau 2: ");
    scanf("%s", xau2);

    char ki_tu_trung[100];
    int dem = 0;
    int i, j;

    for (i = 0; i < strlen(xau1); i++) {
        for (j = 0; j < strlen(xau2); j++) {
            if (xau1[i] == xau2[j]) {
                ki_tu_trung[i] = '*';
                dem++;
                break;
            }
        }

        if (j == strlen(xau2)) {
            ki_tu_trung[i] = xau1[i];
        }
    }
    ki_tu_trung[i] = '\0';

    printf("Xau 1: %s\n", xau1);
    printf("Xau 2: %s\n", xau2);
    printf("So ki tu giong nhau: %d\n", dem);
    printf("Xau sau khi thay the: %s\n", ki_tu_trung);
}
void modify_string(char string[], int n) {
    int char_count = strlen(string);

    if (char_count > n) {
        for (int i = n; i < char_count; i++) {
            string[i] = string[i + 1];
        }
    } else if (char_count < n) {
        int num_repeats = n - char_count;
        for (int i = 0; i < num_repeats; i++) {
            string[char_count + i] = string[i];
        }
        string[n] = '\0';
    }
}

void bt1_2() {
    char string[100];
    int n;

    printf("Nhap xau ki tu: ");
    scanf("%s", string);

    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    modify_string(string, n);

    printf("Xau ki tu sau khi chinh sua: %s\n", string);
}


int main() {
    bt1_1();
    bt1_2();

    return 0;
}

