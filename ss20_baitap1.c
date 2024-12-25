#include <stdio.h>
#include <string.h>

typedef struct{
	int id;
	char name[50];
	char author[50];
	float price;
} Book;

void createBook(Book book[], int bookNum){
	for(int i = 0; i < bookNum; i++){
		printf("Sach %d\n", i+1);
		printf("nhap id sach: ");
		scanf("%d", &book[i].id);
		fflush(stdin);
		printf("Nhap ten: ");
		fgets(book[i].name, 50, stdin);
		book[i].name[strcspn(book[i].name, "\n")] = '\0';
		fflush(stdin);
		printf("nhap ten tac gia: ");
		fgets(book[i].author, 50, stdin);
		book[i].author[strcspn(book[i].author, "\n")] = '\0';
		fflush(stdin);
		printf("nhap gia sach: ");
		scanf("%f", &book[i].price);
		fflush(stdin);
	}
}

void printBook(Book book[], int bookNum){
	printf("Danh sach sach.\n");
	for(int i = 0; i < bookNum; i++){
		printf("id: %d, Ten: %s, Tac gia: %s, Gia: %.2f\n", 
		book[i].id, book[i].name, book[i].author, book[i].price);
	}
}

void addBook(Book book[], int *bookNum, int newIndex){
	if(newIndex >= 0 && newIndex <= *bookNum){
		if(newIndex == *bookNum){
			
		}else{
			for(int i = (*bookNum)--; i >= newIndex; i--){
				book[i] = book[i+1];
			}	
		}
		printf("Sach %d\n", newIndex+1);
		printf("nhap id sach: ");
		scanf("%d", &book[newIndex].id);
		fflush(stdin);
		printf("Nhap ten: ");
		fgets(book[newIndex].name, 50, stdin);
		book[newIndex].name[strcspn(book[newIndex].name, "\n")] = '\0';
		fflush(stdin);
		printf("nhap ten tac gia: ");
		fgets(book[newIndex].author, 50, stdin);
		book[newIndex].author[strcspn(book[newIndex].author, "\n")] = '\0';
		fflush(stdin);
		printf("nhap gia sach: ");
		scanf("%f", &book[newIndex].price);
		fflush(stdin);
		(*bookNum)++;	
	}else{
		printf("vi tri trong khoang tu 0 den %d. Moi nhap lai!!\n", *bookNum);
	}
}
int main(){
	int choose, bookNum;
	Book books[100];
	do{
		printf("MENU\n");
		printf("1. Nhap so luong va thong tin sach.\n");
		printf("2. Hien thi thong tin sach.\n");
		printf("3. Them sach vao vi tri.\n");
		printf("Chon: ");
		scanf("%d", &choose);
		fflush(stdin);
		switch(choose){
			case 1:
				printf("Moi nhap so luong sach muon them: ");
				scanf("%d", &bookNum);
				fflush(stdin);
				if(bookNum > 0 && bookNum <= 100){
					createBook(books, bookNum);
				}else{
					printf("So luong sach trong khoang 1-100. Moi nhap lai!!\n");
				}
				break;
			case 2:
				if(bookNum > 0 && bookNum <= 100){
					printBook(books, bookNum);
				}else{
					printf("So luong sach trong khoang 1-100. Moi nhap lai!!\n");
				}
				break;
			case 3:
				if(bookNum > 0 && bookNum <= 100){
					int newIndex;
					printf("Moi nhap vi tri muon them: ");
					scanf("%d", &newIndex);
					fflush(stdin);
					addBook(books, &bookNum, newIndex);
				}else{
					printf("So luong sach trong khoang 1-100. Moi nhap lai!!\n");
				}
				break;	
				
			case 8:
				printf("Thoat chuong trinh.\n");
				break;
			default:
				printf("Nhap sai moi nhap lai.\n");
				break;	
		};
		
	}while(choose != 8);
	return 0;
}

