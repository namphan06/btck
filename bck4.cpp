#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void nhap(char a[],char b[]){
	char d[50];
	int i=0;
	printf("Nhap chuoi thu nhat :");
	fflush(stdin);
	gets(a);
	printf("Nhap chuoi thu hai :");
	fflush(stdin);
	gets(b);
	for(int i=0;i<strlen(a);i++){
		for(int j=0;j<strlen(b);j++){
			if(a[i]==b[j]){
				a[i]='-';
				break;
			}
			else{
				continue;
			    
			}
		}
	}
	printf("Ket qua cau 1/:%s",a);
}

void xoa(char a[]){
    char d[50];
    int f=0;
	for(int i=0;i<strlen(a);i++){
			if(a[i]=='-'){
				continue;
			}
			else{
				d[f]=a[i];
				f++;
			}
	}

	printf("Ket qua cau 2/ neu xoa dau'-':%s",d);
}
int main(){
	char a[50],b[50];
	nhap(a,b);
	printf("\n");
	xoa(a);
}
