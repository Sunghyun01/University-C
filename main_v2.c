#include <stdio.h>
#include <stdlib.h>

struct info{
    char name[30]; // 학생이름 
    char department[30]; // 학과 
    char num[20]; // 주민등록번호 
    int date; // 생년월일 
    char yoon[10]; // 윤년
    char gender[20]; // 성별
    char country[20]; // 국가 
    int year; // 생일 연도   
};

int main(){
    //구조체 배열 선언
    struct info p[3]; 
    
    printf("3명의 학생 정보를 입력하시오\n");
    // compare 함수 선 언  
    int compare(const void *a, const void *b);
    int i;
    //국가 배열 선언 
    char *country[] = {"대한민국", "대한민국","대한민국","대한민국","대한민국","외국인","외국인","외국인","외국인","대한민국"};
    
    //3명의 학생정보 입력받기  
    for(i=0;i<3;i++){
        printf("----------------------\n");
        printf("학생이름:");
        scanf("%s",p[i].name);
        printf("학과 : ");
        scanf("%s",p[i].department);
        printf("주민등록번호 : ");
        scanf("%s",p[i].num);
        
        //주민번호 뒷자리 첫번째 숫자 
        int r = p[i].num[6] - (int) '0';
        
        //출생년도 구하 기  
        if(r == 1 || r == 2 || r == 5 || r == 6 ){
            p[i].year = 19;
        }else if (r == 3 || r == 4 || r == 7 || r == 8 ){
            p[i].year = 20;
        }else{
            p[i].year = 18;
        }
        p[i].year = (p[i].year*100) + (((int) p[i].num[0] - (int) '0') * 10) + ((int) p[i].num[1] - (int) '0');
        
        strcpy(p[i].country,country[r]);
        
        if(r%2==0){
        	strcpy(p[i].gender, "여자");
        }else{
            strcpy(p[i].gender, "남자");
        }
        
        //윤년 구하기  
        if(p[i].year % 4 == 0 && p[i].year % 100 != 0 || p[i].year % 400 == 0){
            strcpy(p[i].yoon,"윤년");
        }else{
            strcpy(p[i].yoon ,"윤년 아님");
        }
		//학생정보 출력   
        printf("%s, %d년 %c%c월 %c%c일, %s, %s, %s, %s \n",p[i].name,p[i].year,p[i].num[2],p[i].num[3],p[i].num[4],p[i].num[5],p[i].yoon,p[i].country,p[i].gender,p[i].department );
       
	    //생년월일저장  
        p[i].date = p[i].year * 10000 + (((int) p[i].num[2] - (int) '0') * 1000) + (((int) p[i].num[3] - (int) '0') * 100) + (((int) p[i].num[4] - (int) '0') * 10) + ((int) p[i].num[5] - (int) '0');
    }
    
    printf("=====================\n");
    printf("입력받은 3명의 정보를 생년월일 기준으로 오름차순 정렬 \n");
    printf("=====================\n");
    
    //qsort 라이브러리 사용 오름차순 정렬
    qsort(p,3,sizeof(struct info),compare);
    
    for(i=0; i<3; i++){
        printf("%s, %d년 %c%c월 %c%c일, %s, %s, %s, %s \n",p[i].name,p[i].year,p[i].num[2],p[i].num[3],p[i].num[4],p[i].num[5],p[i].yoon,p[i].country,p[i].gender,p[i].department );
    }
}
int compare(const void *A, const void  *B){
    struct info* ptrA = (struct info*)A;
    struct info* ptrB = (struct info*)B;

    if (ptrA->date < ptrB->date) return -1;
    else if (ptrA->date == ptrB->date) return 0;
    else return 1;
}
