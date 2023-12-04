#include<stdio.h>
#include<stdbool.h>
#include<string.h>
typedef struct {
    int id;
    char name[50];
    float duration;
    char content[100];
    bool status;
}CD;
CD cdList[100];
int cdCount = 0;

void printCD(){
    for(int i = 0; i<cdCount ; i++){
        printf ("%s\n", cdList[i].name);
    }
}

void addCD() {
    printf("Nhap thong tin cho cd moi:\n");
    printf("Nhap id: ");
    scanf("%d", &cdList[cdCount].id);
    printf("Nhap ten: ");
    scanf("%s", cdList[cdCount].name);
    printf("Nhap thoi gian : ");
    scanf("%f", &cdList[cdCount].duration);
    printf("Nhap noi dung: ");
    scanf("%s", cdList[cdCount].content);
    printf("Nhap trang thai: ");
    scanf("%d", &cdList[cdCount].status);
    cdCount++;
}
void updateCD(){
    char name[50];
    printf("Nhap ten CD can cap nhat thong tin?");
    scanf("%s", name);
    for(int i = 0; i<cdCount; i++){
        if(strcmp(cdList[cdCount].name , name) == 0){
            printf("Nhap thong tin moi cho CD");
            printf("Nhap id moi");
            scanf("%d",&cdList[cdCount].id);
            printf("Nhap ten CD moi?\n");
            printf("%s", cdList[cdCount].name);
            printf("Nhap thoi gian phat hanh moi?\n");
            scanf("%.2f", cdList[cdCount].duration);
            printf("Nhap chu de CD moi?");
            scanf("%s",cdList[cdCount].content);
            printf("Nhap trang thai moi?");
            scanf("%d", cdList[cdCount].status);
            return ;
        }else{
            printf("Khong tim thay CD can tim");
        }
    }

}
void deleteCD(){
    char name[50];
    printf("Nhap ten CD can xoa ?");
    scanf("%s", name);
    for (int i = 0; i<cdCount; i++){
        if (strcmp(cdList[i].name, name) == 0) {
            for (int j = i; j < cdCount - 1; j++) {
                cdList[j] = cdList[j + 1];
            }
            cdCount--;
            return;
    }
    }
}
void searchCdByName(){
    char name[50];
    printf("Nhap ten CD can tim?");
    scanf("%s", name);
    int l = 0;
    int r = cdCount - 1;
    while (l <= r){
        int k = 1 + (r - 1) / 2;
        if(strcmp(cdList[k].name , name) == 0 ){
            printf("Thong tin CD: \n");
            printf("ID: %d",cdList[k].id);
            printf("Ten CD %s", cdList[k].name);
            printf("Thoi gian phat hanh CD: %.2f", cdList[k].duration);
            printf("Chu de CD: %s", cdList[k].content);
            printf("Trang Thai cua CD: %d", cdList[k].status);
        }
    }
}
void sortCDs() {
    for (int i = 1; i < cdCount; i++) {
        CD key = cdList[i];
        int j = i - 1;
        while (j >= 0 && cdList[j].duration > key.duration) {
            cdList[j + 1] = cdList[j];
            j = j - 1;
        }
        cdList[j + 1] = key;
    }
    printCD();
}
void searchCdByStatus(){
    int status;
    printf("Nhap trang thai muon tim cua cd: ");
    scanf("%d", &status);
    for (int i = 0; i < cdCount; i++) {
        if (cdList[i].status == status) {
            printf("Thong tin CD:\n");
            printf("Id: %d\n", cdList[i].id);
            printf("Ten: %s\n", cdList[i].name);
            printf("Thoi luong: %.2f\n", cdList[i].duration);
            printf("Noi dung: %s\n", cdList[i].content);
            printf("Trang thai: %d\n", cdList[i].status);
        }
    }
}

int main(){
    int choice;
    do{
    printf("MENU\n");
    printf("1. In ra danh sach CD trong CD list\n");
    printf("2. Them moi cd vao vi tri cuoi cung cua CD list\n");
    printf("3. Cap nhat thong tin CD trong CD list\n");
    printf("4. Xoa CD trong CD list\n");
    printf("5. Sap xep va in ra danh sach da duoc sap xep tang dan trong CD list\n ");
    printf("6. Tim kiem va in ra thong tin CD trong CD list theo ten \n");
    printf("7. Tim kiem va in ra toan bo thong tin CD theo trang thai\n");
    printf("8.Thoat\n");
    printf("Nhap lua chon cua ban");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
        printCD();
        break;
        case 2:
        addCD();
        break;
        case 3:
        updateCD();
        break;
        case 4:
        deleteCD();
        break;
        case 5:
        sortCDs();
        break;
        case 6:
        searchCdByName();
        break;
        case 7:
        searchCdByStatus();
        break;
        case 8:
        exit(0);
        return 0;
    default:
    printf("Lua chon khong hop le!\n");
        break;
    }
    }while (choice != 8);
}