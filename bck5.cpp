#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct nhap{
	char hang[10];
	char ma[20];
	char chip[5];
	int ram;
	float gia;
}a;
void nhap(a a[],int *n){
	do{
		do{
			printf("Hang : ");
			fflush(stdin);
			gets(a[*n].hang);
		}while(strlen(a[*n].hang)>10);
		printf("Chip i3,i5 hoac i7: ");
		fflush(stdin);
		gets(a[*n].chip);
		do{
			printf("Ram : ");
			scanf("%d",&a[*n].ram);
		}while(a[*n].ram%4!=0&&a[*n].ram<8);
		fflush(stdin);
		printf("Gia ban : ");
		scanf("%f",&a[*n].gia);
		fflush(stdin);
	    (*n)++;
		char c;
		printf("Ban co muon nha thong tin chiec may khav khong co-y khong-n: ");
		scanf("%c",&c);
		if(c=='n'){
			break;
		}


	}while(1);
}
void sap_xep(a a[],int n){
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].gia>a[j].gia){
				struct nhap temp = a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void khoi_tao_ma(a a[],int n){
	
	for(int i=0;i<n;i++){
		char ma[50]="";
		strcat(ma,a[i].hang);
		strcat(ma,".");
		strcat(ma,a[i].chip);
		strcat(ma,".");
		char ramtam[5];
		sprintf(ramtam,"%d",a[i].ram);
		strcat(ma,ramtam);
		strcpy(a[i].ma,ma);
	}
}
void in(a a[],int n){
	printf("%s-%s-%s-%s-%s\n","Stt","Ma","Chip","RAM","Gia");
	for(int i=1;i<n;i++){
		printf("%-d-%-3s-%-3s-%-d-%-3.2f\n",i,a[i].ma,a[i].chip,a[i].ram,a[i].gia);
	}
}
int main(){
	a a[50];
	int n=1;
	nhap(a,&n);

	sap_xep(a,n);
	khoi_tao_ma(a,n);
	in(a,n);
}
