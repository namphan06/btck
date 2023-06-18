#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void nhap(char a[]){
	int so=0,chu=0;
	do{
		printf("Nhap chuoi ki tu :");
		fflush(stdin);
		gets(a);
		for(int i=0;i<strlen(a);i++){
			if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
				chu++;
			}
			else if(a[i]>='0'&&a[i]<='9'){
				so++;
			}
		}
	}while(chu==0||so==0||(a[0]!='p'&&a[0]!='P'));
}
void xet(char a[]){
	int so=0,chu=0;
		for(int i=0;i<strlen(a);i++){
			if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
				chu++;
			}
			else if(a[i]>='0'&&a[i]<='9'){
				so++;
			}
		}
		printf("So ki tu la so la :%d\n",so);
		printf("So ki tu la chu la :%d\n",chu);
}
void xoa_ki_tu(char a[]){
	char b[50];
	int j=0;
		for(int i=0;i<strlen(a);i++){
			if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
				b[j]=a[i];
				j++;
			}
			else if(a[i]>='0'&&a[i]<='9'){
				b[j]=a[i];
				j++;
			}
			else {
				continue;
			}
		}
		printf("Ket qua sau khi xoa ki tu dac biet la :%s",b);
}
int main(){
	char a[50];
	nhap(a);
	xet(a);
	xoa_ki_tu(a);
}
