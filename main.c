#include <stdio.h>
#include <string.h>

struct MatHang {
    int maHang;
    char tenHang[50];
    int soLuong;
    float donGia;
};

int timKiemTheoMa(struct MatHang ds[], int n, int ma) {
    int i;
    for (i = 0; i < n; i++) {
        if (ds[i].maHang == ma) {
            return i;
        }
    }
    return -1;
}

void themMatHang(struct MatHang ds[], int *n) {
    if (*n >= 50) {
        printf("Danh sach da day\n");
        return;
    }

    int ma;
    printf("Nhap ma hang: ");
    scanf("%d", &ma);

    if (timKiemTheoMa(ds, *n, ma) != -1) {
        printf("Ma mat hang da ton tai\n");
        return;
    }

    ds[*n].maHang = ma;

    printf("Nhap ten hang: ");
    getchar();
    fgets(ds[*n].tenHang, sizeof(ds[*n].tenHang), stdin);
    int len = strlen(ds[*n].tenHang);
    if (len > 0 && ds[*n].tenHang[len - 1] == '\n') {
        ds[*n].tenHang[len - 1] = '\0';
    }

    do {
        printf("Nhap so luong (>= 0): ");
        scanf("%d", &ds[*n].soLuong);
        if (ds[*n].soLuong < 0) {
            printf("Gia tri khong hop le. Vui long nhap lai.\n");
        }
    } while (ds[*n].soLuong < 0);

    do {
        printf("Nhap don gia (> 0): ");
        scanf("%f", &ds[*n].donGia);
        if (ds[*n].donGia <= 0) {
            printf("Gia tri khong hop le. Vui long nhap lai.\n");
        }
    } while (ds[*n].donGia <= 0);

    (*n)++;
    printf("Them mat hang thanh cong\n");
}

void hienThiDanhSach(struct MatHang ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    printf("%-10s | %-25s | %-10s | %-12s | %-12s\n", "Ma", "Ten mat hang", "So luong", "Don gia", "Thanh tien");
    printf("------------------------------------------------------------------------------------\n");
    int i;
    for (i = 0; i < n; i++) {
        int thanhTien = ds[i].soLuong * ds[i].donGia;
        printf("%-10d | %-25s | %-10d | %-12.0f | %-12d\n", 
            ds[i].maHang, 
            ds[i].tenHang, 
            ds[i].soLuong, 
            ds[i].donGia, 
            thanhTien
        );
    }
}

void capNhatMatHang(struct MatHang ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    int ma;
    printf("Nhap ma hang can sua: ");
    scanf("%d", &ma);

    int idx = timKiemTheoMa(ds, n, ma);
    if (idx == -1) {
        printf("Khong tim thay mat hang\n");
        return;
    }

    printf("Nhap ten hang moi: ");
    getchar();
    fgets(ds[idx].tenHang, sizeof(ds[idx].tenHang), stdin);
    int len = strlen(ds[idx].tenHang);
    if (len > 0 && ds[idx].tenHang[len - 1] == '\n') {
        ds[idx].tenHang[len - 1] = '\0';
    }

    do {
        printf("Nhap so luong moi (>= 0): ");
        scanf("%d", &ds[idx].soLuong);
        if (ds[idx].soLuong < 0) {
            printf("Gia tri khong hop le. Vui long nhap lai.\n");
        }
    } while (ds[idx].soLuong < 0);

    do {
        printf("Nhap don gia moi (> 0): ");
        scanf("%f", &ds[idx].donGia);
        if (ds[idx].donGia <= 0) {
            printf("Gia tri khong hop le. Vui long nhap lai.\n");
        }
    } while (ds[idx].donGia <= 0);

    printf("Cap nhat thanh cong\n");
}

void xoaMatHang(struct MatHang ds[], int *n) {
    if (*n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    int ma;
    printf("Nhap ma hang can xoa: ");
    scanf("%d", &ma);

    int idx = timKiemTheoMa(ds, *n, ma);
    if (idx == -1) {
        printf("Khong tim thay mat hang\n");
        return;
    }

    int i;
    for (i = idx; i < *n - 1; i++) {
        ds[i] = ds[i + 1];
    }
    (*n)--;
    printf("Xoa thanh cong\n");
}

void timKiemTheoTen(struct MatHang ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    char ten[50];
    printf("Nhap ten can tim: ");
    getchar();
    fgets(ten, sizeof(ten), stdin);
    int len = strlen(ten);
    if (len > 0 && ten[len - 1] == '\n') {
        ten[len - 1] = '\0';
    }

    int count = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(ds[i].tenHang, ten) == 0) {
            if (count == 0) {
                printf("%-10s | %-25s | %-10s | %-12s | %-12s\n", "Ma", "Ten mat hang", "So luong", "Don gia", "Thanh tien");
                printf("------------------------------------------------------------------------------------\n");
            }
            int thanhTien = ds[i].soLuong * ds[i].donGia;
            printf("%-10d | %-25s | %-10d | %-12.0f | %-12d\n", 
                ds[i].maHang, 
                ds[i].tenHang, 
                ds[i].soLuong, 
                ds[i].donGia, 
                thanhTien
            );
            count++;
        }
    }

    if (count == 0) {
        printf("Khong tim thay mat hang\n");
    }
}




int main() {
    struct MatHang ds[50];
    int n = 0;
    int choice;

    do {
        printf("\n===== QUAN LY MAT HANG =====\n");
        printf("1. Them mat hang\n");
        printf("2. Hien thi danh sach mat hang\n");
        printf("3. Cap nhat mat hang theo ma\n");
        printf("4. Xoa mat hang theo ma\n");
        printf("5. Tim mat hang theo ten\n");
        printf("6. Thong ke kho hang\n");
        printf("0. Thoat\n");
        printf("Cho chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                themMatHang(ds, &n);
                break;
            case 2:
                hienThiDanhSach(ds, n);
                break;
            case 3:
                capNhatMatHang(ds, n);
                break;
            case 4:
                xoaMatHang(ds, &n);
                break;
            case 5:
                timKiemTheoTen(ds, n);
                break;
            case 6:
                thongKeKhoHang(ds, n);
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    } while (choice != 0);

    return 0;
}