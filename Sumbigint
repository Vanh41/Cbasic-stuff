#include <stdio.h>
#include <string.h>
void reverse(int a[],int n){
	int l=0;
	int r=n-1;
	char tmp;
	while (l<r){
		tmp=a[l];
		a[l]=a[r];
		a[r]=tmp;
		l++;
		r--;
	}
}
void sum(char a[],char b[]){
	int n=strlen(a);
	int m=strlen(b);
	int count=0;
	int x[n];
	int y[n];
	int ans[n+1];
	for (int i=0;i<n;i++) x[i]=a[i]-'0';
	for (int i=0;i<m;i++) y[i]=b[i]-'0';
	reverse(x,n);
	reverse(y,m);
	int tmp=0;
	for (int i=0;i<n;i++){
		int z=x[i]+y[i]+tmp;
		tmp=z/10;
		ans[count++]=z%10;
	}
	if (tmp!=0) ans[count++]=tmp;	
	for (int i=count-1;i>=0;i--) printf("%d",ans[i]);
}


int main() {
    char a[1000];
    char b[1000];
    char c[1000];
    scanf("%s %s",a,b);
    sum(a,b);
    return 0;
}
