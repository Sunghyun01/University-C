#include <stdio.h>
#include <stdlib.h>

struct info{
    char name[30]; // �л��̸� 
    char department[30]; // �а� 
    char num[20]; // �ֹε�Ϲ�ȣ 
    int date; // ������� 
    char yoon[10]; // ����
    char gender[20]; // ����
    char country[20]; // ���� 
    int year; // ���� ����   
};

int main(){
    //����ü �迭 ����
    struct info p[3]; 
    
    printf("3���� �л� ������ �Է��Ͻÿ�\n");
    // compare �Լ� �� ��  
    int compare(const void *a, const void *b);
    int i;
    //���� �迭 ���� 
    char *country[] = {"���ѹα�", "���ѹα�","���ѹα�","���ѹα�","���ѹα�","�ܱ���","�ܱ���","�ܱ���","�ܱ���","���ѹα�"};
    
    //3���� �л����� �Է¹ޱ�  
    for(i=0;i<3;i++){
        printf("----------------------\n");
        printf("�л��̸�:");
        scanf("%s",p[i].name);
        printf("�а� : ");
        scanf("%s",p[i].department);
        printf("�ֹε�Ϲ�ȣ : ");
        scanf("%s",p[i].num);
        
        //�ֹι�ȣ ���ڸ� ù��° ���� 
        int r = p[i].num[6] - (int) '0';
        
        //����⵵ ���� ��  
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
        	strcpy(p[i].gender, "����");
        }else{
            strcpy(p[i].gender, "����");
        }
        
        //���� ���ϱ�  
        if(p[i].year % 4 == 0 && p[i].year % 100 != 0 || p[i].year % 400 == 0){
            strcpy(p[i].yoon,"����");
        }else{
            strcpy(p[i].yoon ,"���� �ƴ�");
        }
		//�л����� ���   
        printf("%s, %d�� %c%c�� %c%c��, %s, %s, %s, %s \n",p[i].name,p[i].year,p[i].num[2],p[i].num[3],p[i].num[4],p[i].num[5],p[i].yoon,p[i].country,p[i].gender,p[i].department );
       
	    //�����������  
        p[i].date = p[i].year * 10000 + (((int) p[i].num[2] - (int) '0') * 1000) + (((int) p[i].num[3] - (int) '0') * 100) + (((int) p[i].num[4] - (int) '0') * 10) + ((int) p[i].num[5] - (int) '0');
    }
    
    printf("=====================\n");
    printf("�Է¹��� 3���� ������ ������� �������� �������� ���� \n");
    printf("=====================\n");
    
    //qsort ���̺귯�� ��� �������� ����
    qsort(p,3,sizeof(struct info),compare);
    
    for(i=0; i<3; i++){
        printf("%s, %d�� %c%c�� %c%c��, %s, %s, %s, %s \n",p[i].name,p[i].year,p[i].num[2],p[i].num[3],p[i].num[4],p[i].num[5],p[i].yoon,p[i].country,p[i].gender,p[i].department );
    }
}
int compare(const void *A, const void  *B){
    struct info* ptrA = (struct info*)A;
    struct info* ptrB = (struct info*)B;

    if (ptrA->date < ptrB->date) return -1;
    else if (ptrA->date == ptrB->date) return 0;
    else return 1;
}
