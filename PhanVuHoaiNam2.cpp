#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char hangSanXuat[21];
    char ma[21];
    char loaiXe[21];
    float dungTich;
    int soGhe;
    float giaBan;
} Oto;


void nhapThongTinOto(Oto *oto) {
    printf("Nhap thong tin oto:\n");
    
    printf("Hang san xuat (toi da 20 ky tu): ");
    scanf("%20s", oto->hangSanXuat);
    
    printf("Ma (toi da 20 ky tu): ");
    scanf("%20s", oto->ma);
    
    printf("Loai xe (Vios, City, Camry, BMW i7, ...): ");
    scanf("%20s", oto->loaiXe);
    
    printf("Dung tich xi-lanh: ");
    scanf("%f", &(oto->dungTich));
    
    printf("So ghe ngoi (5 hoac 9): ");
    scanf("%d", &(oto->soGhe));
    
    printf("Gia ban (don vi trieu VND): ");
    scanf("%f", &(oto->giaBan));
    
    printf("\n");
}


int chiChuaChuCai(char *chuoi) {
    int i;
    for (i = 0; i < strlen(chuoi); i++) {
        if (!((chuoi[i] >= 'a' && chuoi[i] <= 'z') || (chuoi[i] >= 'A' && chuoi[i] <= 'Z'))) {
            return 0;
        }
    }
    return 1;
}

void khoiTaoMa(Oto *oto) {
    char ma[50] = "";
    strcat(ma, oto->hangSanXuat);
    strcat(ma, ".");
    strcat(ma, oto->loaiXe);
    strcat(ma, ".");
    

    char dungTich[10];
    sprintf(dungTich, "%.1f", oto->dungTich);
    strcat(ma, dungTich);
    
    strcpy(oto->ma, ma);
}


void sapXepGiamDanTheoGia(Oto *danhSach, int n) {
    int i, j;
    Oto temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (danhSach[j].giaBan < danhSach[j + 1].giaBan) {
                temp = danhSach[j];
                danhSach[j] = danhSach[j + 1];
                danhSach[j + 1] = temp;
            }
        }
    }
}


void inThongTinOto(Oto oto, int stt) {
    printf("%d - %s - %s - %.1f - %d - %.2f\n", stt, oto.ma, oto.loaiXe, oto.dungTich, oto.soGhe, oto.giaBan);
}

int main() {
    Oto danhSachOto[100];
    int soLuongOto = 0;
    char tiepTuc;
    

    do {
        nhapThongTinOto(&danhSachOto[soLuongOto]);
        khoiTaoMa(&danhSachOto[soLuongOto]);
        soLuongOto++;
        
        printf("Ban co muon nhap thong tin oto khac? (y/n): ");
        scanf(" %c", &tiepTuc);
        printf("\n");
    } while (tiepTuc == 'y' || tiepTuc == 'Y');
    
    
    sapXepGiamDanTheoGia(danhSachOto, soLuongOto);
    

    int i;
    for (i = 0; i < soLuongOto; i++) {
        inThongTinOto(danhSachOto[i], i + 1);
    }
    
    return 0;
}
