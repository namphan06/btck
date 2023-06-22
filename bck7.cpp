#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct nhap{
	char ten[100];
	int nam_sinh;
	float chieu_cao;
	float can_nang;
}a;
void nhap_thong_tin(a a[],int N){
	for(int i=0;i<N;i++){
		printf("Nhap ten : ");
		fflush(stdin);
		gets(a[i].ten);
		do{
			printf("Nhap nam sinh : ");
			scanf("%d",&a[i].nam_sinh);
		}while(a[i].nam_sinh<=1900||a[i].nam_sinh>=2020);
		do{
			printf("Nhap chieu cao : ");
			scanf("%f",&a[i].chieu_cao);
		}while(a[i].chieu_cao<0);
		do{
			printf("Nhap can nang : ");
			scanf("%f",&a[i].can_nang);
		}while(a[i].can_nang<0);
	}
}
void trung_nien(a a[],int N){
	int count=0;
	for(int i=0;i<N;i++){
		int tuoi = 2023-a[i].nam_sinh;
		if(tuoi>=45&&tuoi<=65){
			count++;
		}
	}
	printf("So khach hang trung nien la : %d\n",count);
}
void sap_xep(a a[],int N,float b[]){
	for(int i=0;i<N;i++){
		b[i]=a[i].can_nang/(pow(a[i].chieu_cao,2));
	}
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if(b[i]>b[j]){
				float temp=b[i];
				b[i]=b[j];
				b[j]=temp;
				struct nhap temp1=a[i];
				a[i]=a[j];
				a[j]=temp1;
			}
		}
	}
}
void bang(a a[],float b[]){
	int M;
	printf("Nhap so luong can in :");
	scanf("%d",&M);
	printf("+----+------------+--------+-----+\n");
	printf("|%-4s|%-12s|%-6s|%-5s|\n","STT","Ten","Nam sinh","BMI");
	printf("+----+------------+--------+-----+\n");
	for(int i=0;i<M;i++){
		printf("|%-4d|%-12s|%-8d|%-5.2f|\n",i+1,a[i].ten,a[i].nam_sinh,b[i]);
		printf("+----+------------+--------+-----+\n");
	}
}
int main(){
	a a[50];
	float b[50];
	int N;
	printf("Nhap so luong khac hang : ");
	scanf("%d",&N);
	nhap_thong_tin(a,N);
	trung_nien(a,N);
	sap_xep(a,N,b);
	 bang(a,b);
}

