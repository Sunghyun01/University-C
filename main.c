#include <stdio.h>
#include <stdlib.h>

struct info{
    char name[30];
    char department[30];
    char num[20];
    int date;
};

int main(){
    //구조체 배열 선언
    struct info p[4];
    printf("3명의 학생 정보를 입력하시오\n");
    int compare(const void *a, const void *b);
    int i;
    int year;
    char *country[] = {"대한민국", "대한민국","대한민국","대한민국","대한민국","외국인","외국인","외국인","외국인","대한민국"};
    
    
    for(i=0;i<3;i++){
        printf("----------------------\n");
        printf("학생이름:");
        scanf("%s",p[i].name);
        printf("학과 : ");
        scanf("%s",p[i].department);
        printf("주민등록번호 : ");
        scanf("%s",p[i].num);
        
        int r = p[i].num[6] - (int) '0';
        
        
        if(r == 1 || r == 2 || r == 5 || r == 6 ){
            year = 19;
        }else if (r == 3 || r == 4 || r == 7 || r == 8 ){
            year = 20;
        }else{
            year = 18;
        }
        year = (year*100) + (((int) p[i].num[0] - (int) '0') * 10) + ((int) p[i].num[1] - (int) '0');
        
        char* yoon = "윤년 아님";
        if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
            yoon = "윤년";
        }
                
        printf("%s, %d년 %c%c월 %c%c일, %s, %s, %s, %s \n",p[i].name,year,p[i].num[2],p[i].num[3],p[i].num[4],p[i].num[5],yoon,country[r],r%2==0?"여자":"남자",p[i].department );
        
        p[i].date = year * 10000 + (((int) p[i].num[2] - (int) '0') * 1000) + (((int) p[i].num[3] - (int) '0') * 100) + (((int) p[i].num[4] - (int) '0') * 10) + ((int) p[i].num[5] - (int) '0');
    }
    printf("=====================\n");
    printf("입력받은 3명의 정보를 생년월일 기준으로 오름차순 정렬 \n");
    printf("=====================\n");
    qsort(p,3,sizeof(struct info),compare);
    for(i=0; i<3; i++){
        int r = p[i].num[6] - (int) '0';
        if(r == 1 || r == 2 || r == 5 || r == 6 ){
            year = 19;
        }else if (r == 3 || r == 4 || r == 7 || r == 8 ){
            year = 20;
        }else{
            year = 18;
        }
        year = (year*100) + (((int) p[i].num[0] - (int) '0') * 10) + ((int) p[i].num[1] - (int) '0');
        
        char* yoon = "윤년 아님";
        if(year % 4 == 0 && year % 100 != 0 ){
            if( year % 400 == 0){
            yoon = "윤년";
            }
        }
                
        printf("%s, %d년 %c%c월 %c%c일, %s, %s, %s, %s \n",p[i].name,year,p[i].num[2],p[i].num[3],p[i].num[4],p[i].num[5],yoon,country[r],r%2==0?"여자":"남자",p[i].department );
        
    }
}
int compare(const void *A, const void  *B){
    struct info* ptrA = (struct info*)A;
    struct info* ptrB = (struct info*)B;

    if (ptrA->date < ptrB->date) return -1;
    else if (ptrA->date == ptrB->date) return 0;
    else return 1;
}
