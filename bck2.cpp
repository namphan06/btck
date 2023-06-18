#include <stdio.h>
#include <math.h>
void nhap_mang(int a[][10],int m,int n){
    int j=0;
	printf("Nhap mang so nguyen cua ban :\n");
	do{
		for(int i=0;i<n;i++){
			printf("a[%d][%d]=",j,i);
			scanf("%d",&a[j][i]);
		}
		j++;
	}while(j<m);
	
}
void xuat_mang(int a[][10],int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d\t",a[i][j]);		
		}
		printf("\n");
	}
}
void xet_nguyen(int a[][10],int m,int n){
	int count=0;
	printf("Cac so nguyen trong mang la :\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			for(int z=2;z<=sqrt(a[i][j]);z++){
				count =0;
				if(a[i][j]%z==0){
					count++;

				}
			}
			if(count!=0){
				continue;
			}
			else{
				printf("a[%d][%d]=%d\t",i,j,a[i][j]);
			}
		}
	}
}
int main(){
	int a[10][10],m,n;
	printf("Nhap vao do dai hang m: ");
	scanf("%d",&m);
	printf("Nhap vao do dai cot n : ");
	scanf("%d",&n);
	nhap_mang(a,m,n);
	printf("\n");
	xuat_mang(a,m,n);
	printf("\n");
	xet_nguyen(a,m,n);
}
