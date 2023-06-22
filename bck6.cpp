#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void nhap(char a[]){
	int cost=0;
	do{
		printf("Nhap vao string : ");
		fflush(stdin);
		gets(a);
		for(int j=0;j<strlen(a);j++){
			if(a[j]>='0'&&a[j]<='9'){
				cost++;
			}
		}
	}while(strlen(a)<6||cost<2||(a[0]<='z'&&a[0]>='a'));
}
void doi_xung(char a[]){
	int j=strlen(a)-1;
	int temp=0;
	for(int i=0;i<strlen(a);i++){
		if(a[i]==a[j]){
			temp++;
		}
		j--;
	}
	if(temp==strlen(a)){
		printf("string %s thoa man doi xung",a);
	}
	else{
		printf("string %s khong thoa man doi xung",a);
	}
}
void chuyen(char a[]){
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='a'&&a[i]<='z'){
			a[i]=a[i]-('a'-'A');
		}
		else if(a[i]>='A'&&a[i]<='Z'){
			a[i]=a[i]+('a'-'A');
		}
	}
	printf("string ket qua sau khi chuyen doi : %s",a);
	
}
int main(){
	char a[50];
	nhap(a);
	printf("\n");
	doi_xung(a);
	printf("\n");
	chuyen(a);
}
