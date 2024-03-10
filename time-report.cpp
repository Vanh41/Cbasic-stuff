#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>


//NOT OPTIMIZED

int main(){
  char time[10000][100];
  char hour[10000];
  char name[10000];
  char count[10000][100];
  int i=0;
  while (time[i][0]!='*'){
  	scanf("%s",&time[i]);
  	if (time[i][0]=='*') break;
  	scanf("%s %s %s",hour,name,&count[i]);
  	i++;
  }
  int n=i;
  for (int i=0;i<n-1;i++)
   for (int j=i+1;j<n;j++)
   if (strcmp(time[i],time[j])>0){
   	char temp[100];
   	strcpy(temp,time[i]);
   	strcpy(time[i],time[j]);
   	strcpy(time[j],temp);
   }
//   printf("%d",n);
//   for (int i=0;i<n;i++) printf("%s\n",time[i]);
  int qcount=1;
  char mark[1000];
  strcpy(mark,time[0]);
  for (int i=1;i<=n;i++){
    if (strcmp(mark,time[i])==0) qcount++;
	else {
	    printf("%s %d\n",mark,qcount);
	    qcount=1;
	    strcpy(mark,time[i]);
	} 
  }

   
}
/*
Cần thống kê xem mỗi ngày có bao nhiêu lượt sinh viên làm trắc nghiệm.
Input
Thông tin về sinh viên làm trắc nghiệm ôn tập được cho theo các dòng định dạng như sau:
<yyyy-mm-dd> <hh:mm:ss> <user_id> <question_id>: trong đó sinh viên có mã <user_id> làm câu hỏi <question_id> vào ngày giờ là <yyyy-mm-dd> <hh:mm:ss>
Kết thúc dữ liệu là 1 dòng chứa dấu *
Output
Mỗi dòng ghi <yyyy-mm-dd> <cnt>: trong đó <cnt> là số lượt sinh viên làm trắc nghiệm trong ngày <yyyy-mm-dd>
(chú ý: các dòng được sắp xếp theo thứ tự tăng dần của ngày thống kê, ngày thống kê nào mà không có lượt sinh viên làm trắc nghiệm thì không in ra)
Example
Input
2022-01-02 10:30:24 dungpq question1
2022-01-03 11:30:24 dungpq question1
2022-02-01 03:30:20 viettq question2
2022-02-01 03:35:20 viettq question1
2022-03-01 03:30:20 viettq question7
2022-01-02 11:20:24 viettq question2
*
Output
2022-01-02 2
2022-01-03 1
2022-02-01 2
2022-03-01 1
  */
