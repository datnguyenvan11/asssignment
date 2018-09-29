#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char masv[10];
    char name[40];
    char phonenumber[40];
} struc;

void themmoisv(int i, struc sinhvien[]) {
    int a;
    printf(" mời thêm thông tin sinh viên(tối đa 10 sinh viên) \n");
    for (int j = 0; j < 10; ++j) {
        printf("nhập tên của sinh viên  %d:", j + 1);
        getc(stdin);
        gets(sinhvien[i].name);
        while (1) {
            printf("nhập mã của sinh viên  %d:", j + 1);
            gets(sinhvien[i].masv);
            if (strlen(sinhvien[i].masv) != 5) {
                printf("Nhập lại mã sinh viên(mã sinh viên phải có 5 kí tự) %d:\n", j + 1);
            } else break;
        }
        printf("nhập số điện thoại của sinh viên %d:", i + 1);
        gets(sinhvien[i].phonenumber);
        i++;
        printf("nhấn '0'nếu muốn dừng lại | nhấn '1'để tiếp tục thêm sinh viên: ");
        scanf("%d", &a);
        if (a == 0)break;
    }
    printf(" danh sách sinh viên đã  \n");

}

void hienthidssv(int i, struc sinhvien[]) {
    printf("-%-25s%-15s%-23s%-15s%s", "Mã sinh viên", "|", "Tên sinh viên", "|", "Điện thoại");
    for (int j = 0; j < 10; ++j) {
        printf("\n-%-23s%-13s%-23s%-13s%s", sinhvien[j].masv, "|", sinhvien[j].name, "|", sinhvien[j].phonenumber);
        i++;
    }
    printf("\n");

}

void infile(int i, struc sinhvien[], FILE *fp) {
    fprintf(fp, "-%-25s%-15s%-23s%-15s%s", "Mã sinh viên", "|", "Tên sinh viên", "|", "Điện thoại");
    for (int j = 0; j < 10; ++j) {
        fprintf(fp, "\n-%-23s%-13s%-23s%-13s%s", sinhvien[j].masv, "|", sinhvien[j].name, "|", sinhvien[j].phonenumber);
        i++;
    }
    printf("danh sách sinh viên đã được lưu vào file\n");
}

void docfile(FILE *fp) {
    printf(" ========READ-FILE-DATA=========\n");
    int buffersize = 255;
    char buffer[buffersize];
    fp = fopen("danhsachsinhvien.txt", "r");
    while (fgets(buffer, 255, fp) != NULL) {
        printf("%s", buffer);

    }
    printf("\n");
}

int main() {
    struc sinhvien[10];
    int i = 0;
    int c;
    FILE *fp = fopen("danhsachsinhvien.txt", "w+");
    while (1) {
        printf("-----(^_^)-----Menu-----(^_^)------\n");
        printf("1. Thêm mới sinh viên. \n");
        printf("2. Hiển thị danh sách sinh viên.\n");
        printf("3. Lưu danh sách sinh viên ra file.\n");
        printf("4. Đọc danh sách sinh viên từ file.\n");
        printf("5. Thoát chương trình.\n");
        printf("chọn chương trình:");
        scanf("%d", &c);
        switch (c) {
            case 1:
                themmoisv(i, sinhvien);
                break;
            case 2:
                hienthidssv(i, sinhvien);
                break;
            case 3:
                infile(i, sinhvien, fp);
                fclose(fp);
                break;
            case 4:
                docfile(fp);
        }
        if(c==5){
            break;
        }
    }
}
