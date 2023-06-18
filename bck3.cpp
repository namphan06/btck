#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nhap{
	char ten[50];
	int soluong;
	char size;
	float gia;
}a;
void dien(a a[],int N){
	for(int i=0;i<N;i++){
		do{
			printf("Nhap ten san pham :");
			fflush(stdin);
			gets(a[i].ten);
		}while(strlen(a[i].ten)>10);
		do{
			printf("Nhap so luong san pham :");
			scanf("%d",&a[i].soluong);
		}while(a[i].soluong<=0);
		int c;
		do{
		printf("Nhap size cua san pham 1-S,2-M,3-L:");
		scanf("%d",&c);
		switch(c){
			case 1:
				a[i].size='S';
				break;
			case 2:
				a[i].size='M';
				break;
			case 3:
			    a[i].size='L';	
			    break;
			default:
				a[i].size='N';
				break;
		}
	}while(a[i].size=='N');
	printf("Nhap gia cua san pham :");
	scanf("%f",&a[i].gia);
}
}
void in(a a[],int N){
	printf("+---+------------+--------+----+--------------+\n");
	printf("|%-3s|%-8s|%-4s|%-3s|%-10s|\n","STT","Ten san pham","So luong","Size","Gia ban(k VND)");
	printf("+---+------------+--------+----+--------------+\n");
	for(int i=0;i<N;i++){
		printf("|%-3d|%-12s|%-8d|%-4c|%-14.2f|\n",i,a[i].ten,a[i].soluong,a[i].size,a[i].gia);
		printf("+---+------------+--------+----+--------------+\n");
	}
}
void sap_xep(a a[],int N){
	for(int i=0;i<N-1;i++){
	   for(int j=i+1;j<N;j++){
	   	if(a[i].gia<a[j].gia){
	   		struct nhap temp=a[i];
	   		a[i]=a[j];
	   		a[j]=temp;
		   }
	   }
	}
	int sum=0;
	printf("+---+------------+--------+----+--------------+\n");
	printf("|%-3s|%-8s|%-4s|%-3s|%-10s|\n","STT","Ten san pham","So luong","Size","Gia ban(k VND)");
	printf("+---+------------+--------+----+--------------+\n");
	for(int i=0;i<N;i++){
		printf("|%-3d|%-12s|%-8d|%-4c|%-14.2f|\n",i,a[i].ten,a[i].soluong,a[i].size,a[i].gia);
		sum+=a[i].gia;
		printf("+---+------------+--------+----+--------------+\n");
	}
	printf("Tong gia tien cua hang ton kho la : %d",sum);
}
void tim(a a[],int N){
	int c;float d;char f;
	do{
		printf("Nhap size cua san pham 1-S,2-M,3-L:");
		scanf("%d",&c);
		switch(c){
			case 1:
				f='S';
				break;
			case 2:
				f='M';
				break;
			case 3:
			    f='L';	
			    break;
			default:
				f='N';
				break;
		}
	}while(f=='N');
	printf("Nhap gia cua san pham :");
	scanf("%f",&d);
	for(int i=0;i<N;i++){
	if(a[i].size==f&&a[i].gia==d){
	printf("+---+------------+--------+----+--------------+\n");
	printf("|%-3s|%-8s|%-4s|%-3s|%-10s|\n","STT","Ten san pham","So luong","Size","Gia ban(k VND)");
	printf("+---+------------+--------+----+--------------+\n");	
    for(int i=0;i<N;i++){
    	if(a[i].size==f&&a[i].gia==d){
    		printf("|%-3d|%-12s|%-8d|%-4c|%-14.2f|\n",i,a[i].ten,a[i].soluong,a[i].size,a[i].gia);
		    printf("+---+------------+--------+----+--------------+\n");
		}
}
	}
	else{
		printf("Khong tim thay ket qua ");
	}
}
}

int main(){
	a a[50];
	int N;
	printf("Nhap so luong san pham cua ban :");
	scanf("%d",&N);
	dien(a,N);
	printf("\n");
	in(a,N);
	printf("\n");
	sap_xep(a,N);
	printf("\n");
	tim(a,N);
	
}
