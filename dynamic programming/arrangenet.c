#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int DP[1000];
int n;
int T[1000];
// Bài toán 2: Tại thời điểm 0, ông chủ một máy tính hiệu năng cao nhận được đơn đặt hàng thuê sử dụng máy của n khách hàng. Các khách hàng được đánh số từ 1 đến n. Khách hàng i cần sử dụng máy từ thời điểm di đến thời điểm ci (di, ci là các số nguyên và 0 < di < ci < 1000000000) và sẽ trả tiền sử dụng máy là pi (pi nguyên, 0 < p i ≤ 10000000). Bạn cần xác định xem ông chủ cần nhận phục vụ những khách hàng nào sao cho khoảng thời gian sử dụng máy của hai khách được nhận phục vụ bất kỳ không được giao nhau đồng thời tổng tiền thu được từ việc phục vụ họ là lớn nhất.
// Dữ liệu vào: Từ file văn bản THUE.INP
// Dòng đầu tiên ghi số n (0 < n =< 1000);
// - Dòng thứ i+1 trong số n dòng tiếp theo ghi 3 số di, ci, pi cách nhau bởi dấu trắng (i = 1, 2,... n).
// Kết quả: Ghi ra file văn bản THUE.OUT
// -Dòng đầu tiên ghi hai số nguyên dương theo thứ tự là số lượng khách hàng nhận phục vụ và tổng tiền thu được từ việc phục vụ họ.
// -Dòng tiếp theo ghi chỉ số của các khách hàng được nhận phục vụ.
// Ví dụ:
// THUE.INP
// THUE.OUT

// THUE.INP
// THUE.OUT
// 3
// 150 500 150
// 1 200 100
// 400 800 80
// out
// 2 180
// 2 3

// 4
// 400 821 800
// 200 513 500
// 100 325 200
// 600 900 600
// out
// 2 1100
// 2 4



typedef struct value{
    int a;  //start
    int b;  //end
    int c;  //weight
    int id; //stt
}value;

value net[10000];

int cmp(const void *ptr1,const void *ptr2){
    value *x=(value*)ptr1;
    value *y=(value*)ptr2;
    int xx=x->a;
    int yy=y->a;
    if (xx>yy) return 1;
    if (xx==yy&&x->b>y->b) return 1;
    return -1;
}

int max(int x,int y){
    if (x>y) return x;
    return y;
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d %d %d",&net[i].a,&net[i].b,&net[i].c);    
        net[i].id=i+1;
    };
    qsort(net,n,sizeof(value),cmp);
    //for (int i=0;i<n;i++) printf("%d %d %d\n",net[i].a,net[i].b,net[i].c);
    // cai dat
    for (int i=0;i<n;i++){
        DP[i]=net[i].c;
        for (int j=0;j<i-1;j++)
            if (net[j].b<=net[i].b&&DP[i]<DP[j]+net[i].c){
                DP[i]=max(DP[j]+net[i].c,DP[i-1]);
                T[i]=net[j].id;
            }
    }
    printf("%d",DP[n-1]);

}
