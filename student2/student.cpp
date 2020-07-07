#include<iostream>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>   
#include <fcntl.h>  
using namespace std;

#define MAX_STUDENT 100 //���洢100��ѧ�� 
#define FILENAME "students.txt" //�ļ�����
 
typedef struct student{//ѧ���ṹ�� 
	char name[20];
	char no[20];
	int grade;
}STU;

typedef struct stuArr{//ѧ���ṹ�弯 
	STU stus[MAX_STUDENT]; 
	int len;
}STUA;

STUA stua; //ѧ���� 
bool find_flag = false;//���ұ�ʶ 
/*
*��ȡ�ļ����ݵ�ѧ���� 
*/
void read_file_data_to_student_set(){
	char buff[1024]; //������ 
	char grade[20];
	char *stop;
	FILE* pFile = NULL; 
	if((access(FILENAME,F_OK)) == -1) //�ж��ļ��Ƿ���ڣ��������򴴽�   
    {   
       pFile = fopen(FILENAME, "w");//�����ļ�
	   fclose(pFile);   
    }   
	
	pFile = fopen(FILENAME, "r");//�ļ������� 
	while(fgets(buff , sizeof(buff), pFile) != NULL){
		sscanf(buff , "%s %s %s" , stua.stus[stua.len].name , stua.stus[stua.len].no , grade);//���ļ��а���ʽ��ȡ���� 
		stua.stus[stua.len].grade = strtol(grade , &stop , 10); //���ַ���ת��Ϊ10�������֣�����ֵ��grade 
		stua.len++;				
	}	
	fclose(pFile);
}

/*
*��ʼ������ 
*@���������ָ�� 
*/
int initDesktop(){
	cout<<endl;
	cout<<"==================��������======================="<<endl;
	cout<<"\t\t 1.�Ǽ�ѧ����Ϣ"<<"\t\t\t|"<<endl;
	cout<<"\t\t 2.����ѧ����Ϣ"<<"\t\t\t|"<<endl;
	cout<<"\t\t 3.����ѧ����Ϣ"<<"\t\t\t|"<<endl;
	cout<<"\t\t 4.����"<<"\t\t\t\t|"<<endl;
	cout<<"\t\t 5.�޸�ѧ����Ϣ"<<"\t\t\t|"<<endl;
	cout<<"\t\t 6.ɾ��ѧ����Ϣ"<<"\t\t\t|"<<endl;
	cout<<"\t\t 7.�˳�"<<"\t\t\t\t|"<<endl;
	cout<<"================================================="<<endl;
	int num;
	cout<<"����ѡ��:";
	cin>>num; 
	
	return num;
}

/* 
*1.�Ǽ�ѧ����Ϣ 
*/ 
	/*
	*1.1 ������������Ƿ��ظ� 
	*@���ظ��򷵻� true
	*@���ظ��򷵻� false 
	*/
bool check_name_repeated(char name[]){
	int i = 0;
	bool flag = false;
	for(i = 0 ; i < stua.len ; i++){
		if(strcmp(stua.stus[i].name , name) == 0 && strlen(stua.stus[i].name) == strlen(name)){//�����ظ� 
			flag = true;
			break;
		}
	}
	return flag;
}
	/*
	*1.2 �������ѧ���Ƿ��ظ� 
	*@���ظ��򷵻� true
	*@���ظ��򷵻� false 
	*/
bool check_no_repeated(char no[]){
	int i = 0;
	bool flag = false;
	for(i = 0 ; i < stua.len ; i++){
		if(strcmp(stua.stus[i].no , no) == 0 && strlen(stua.stus[i].no) == strlen(no)){//�����ظ� 
			flag = true;
			break;
		}
	}
	return flag;
}


int register_student_information(){
	if(stua.len >= MAX_STUDENT){//�ж��Ƿ�ﵽ���� 
		cout<<"ѧ�����ݼ���������ɾ��һЩ����ӣ�����"<<endl;
		return 0;
	}
	bool flag; 
	char name[100]; //���� 
	char no[100];  //ѧ�� 
	int grade;	//�ɼ� 
	int wordLen;
	cout<<"������ѧ������:";
	do{	
		cin>>name;
		wordLen = strlen(name);
		if(wordLen > 20){
			cout<<"����ѧ����������20�ֽڣ�����������:";
		}else{
			flag = check_name_repeated(name);//��������Ƿ��ظ� 
			if(flag)
				cout<<"����������ظ�������������:";
		}
	} while(wordLen > 20 || flag);
	
	
	cout<<"������ѧ��ѧ��:";
	do{	
		cin>> no;
		wordLen = strlen(no);
		if(wordLen > 20){
			cout<<"����ѧ��ѧ�ų���20�ֽڣ�����������:";
		}else{
			flag = check_no_repeated(no);//���ѧ���Ƿ��ظ�
			if(flag)
				cout<<"����ѧ���ظ�������������:";	
		}
	} while(wordLen > 20 || flag);
	
	cout<<"������ѧ���ɼ�:";
	do{
		cin>> grade;
		if(grade > 1000){
			cout<<"����ɼ�����1000�֣�����������:";
		}
	}while(grade > 1000);
	
	strcpy(stua.stus[stua.len].name , name);
	strcpy(stua.stus[stua.len].no , no);
	stua.stus[stua.len].grade = grade;
	stua.len++;
	return 1;
} 
/*
*2.����ѧ����Ϣ ������ģ����ѯ����ؼ��ʼ��ɣ� 
*/
	/*
	*2.1 ��ѧ���������� 
	*/
void find_by_student_name(char name[]){
	int i = 0;
	cout<<"����"<<"\tѧ��"<<"\t�ɼ�"<<endl; 
	for(i = 0 ; i < stua.len ; i++){
		if(strstr(stua.stus[i].name , name) != NULL){
			cout<<stua.stus[i].name;
			cout<<"\t"<<stua.stus[i].no;
			cout<<"\t"<<stua.stus[i].grade<<endl;
			find_flag = true;	
		}
	}
}	
	/*
	*2.2 ��ѧ�Ų��� 
	*/
void search_by_student_number(char no[]){
	int i = 0;
	cout<<"����"<<"\tѧ��"<<"\t�ɼ�"<<endl; 
	for(i = 0 ; i < stua.len ; i++){
		if(strstr(stua.stus[i].no , no) != NULL){
			cout<<stua.stus[i].name;
			cout<<"\t"<<stua.stus[i].no;
			cout<<"\t"<<stua.stus[i].grade<<endl;	
			find_flag = true;
		}
	}
		
} 
	/*
	*2.3 ���ɼ����� 
	*/
void find_by_grade(int grade){
	int i = 0;
	cout<<"����"<<"\tѧ��"<<"\t�ɼ�"<<endl; 
	for(i = 0 ; i < stua.len ; i++){
		if(stua.stus[i].grade == grade){
			cout<<stua.stus[i].name;
			cout<<"\t"<<stua.stus[i].no;
			cout<<"\t"<<stua.stus[i].grade<<endl;	
			find_flag = true;
		}
	}	
}

void find_student_information(){
	int cmd = 0;
	int i = 0;
	int wordLen;
	char name[100]; //�������� 
	char no[100];   //����ѧ�� 
	int grade;	   //����ɼ� 
	cout<<"1.����������"<<endl;
	cout<<"2.��ѧ�Ų���"<<endl;
	cout<<"3.���ɼ�����"<<endl;
	cout<<"����ѡ��:";
	cin>>cmd;
	switch(cmd){
		case 1:{//���������� 
			cout<<"��������Ҫ���ҵ�����:";	
			do{
				cin>>name;
				wordLen = strlen(name);
				if(wordLen > 20)
					cout<<"������ҵ���������������������:"; 
			}while(wordLen > 20);
			find_by_student_name(name);//���������� 
			break;
		}
		case 2:{//��ѧ�Ų��� 
			cout<<"��������Ҫ���ҵ�ѧ��:";
			do{
				cin>>no;
				wordLen = strlen(no);
				if(wordLen > 20)
					cout<<"������ҵ�ѧ�Ź���������������:"; 
			}while(wordLen > 20);
			search_by_student_number(no);//��ѧ�Ų��� 
			break;
		}
		case 3:{
			cout<<"��������Ҫ���ҵĳɼ�:";
			do{
				cin>>grade;
				if(grade > 1000)
					cout<<"������ҵĳɼ���������������:"; 
			}while(grade > 1000);
			find_by_grade(grade);//���ɼ����� 
			break;
		}
	}	


}

/*
*3.����ѧ����Ϣ
*/
int save_student_information(){
	int i= 0; 
	char buff[1024]; //������ 
	FILE* pFile = fopen(FILENAME, "w");//�ļ��������򴴽�
	for(i = 0 ; i < stua.len ; i++){
		sprintf(buff , "%s %s %d\n" , stua.stus[i].name , stua.stus[i].no , stua.stus[i].grade);	
		fputs(buff , pFile);
	}
	fclose(pFile);
	return 3;
}


/*
*4.ѧ����Ϣ���� 
*/
	/*
	*4.1 ���������򣨲������� 
	*/
void sort_by_name(){
	STU temp; //��ʱѧ���ṹ��	
	int i = 0 , j = 0;	
	for (i = 1 ; i < stua.len ; i++){
	    //����Ԫ��С���������е����һ��Ԫ��ʱ����ǰ����
	    if (strcmp(stua.stus[i].name , stua.stus[i - 1].name) < 0){
	        temp = stua.stus[i]; //ǰһ���Ƚϴ��򽫵�i���ṹ�帳����ʱ���� 
	        for (j = i ; j >= 0 ; j--){
	            if (j > 0 && strcmp(stua.stus[j - 1].name , temp.name) > 0) {
	                stua.stus[j]=stua.stus[j-1];
	            }else {
	                stua.stus[j]=temp;
	                break;
	            }
	        }
	    }
    }
}
	/*
	*4.2 ��ѧ������ 
	*/
void sort_by_student_number(){
	STU temp; //��ʱѧ���ṹ��	
	int i = 0 , j = 0;	
	for (i = 1 ; i < stua.len ; i++){
	    //����Ԫ��С���������е����һ��Ԫ��ʱ����ǰ����
	    if (strcmp(stua.stus[i].no , stua.stus[i - 1].no) < 0){
	        temp = stua.stus[i]; //ǰһ���Ƚϴ��򽫵�i���ṹ�帳����ʱ���� 
	        for (j = i ; j >= 0 ; j--){
	            if (j > 0 && strcmp(stua.stus[j - 1].no , temp.no) > 0) {
	                stua.stus[j]=stua.stus[j-1];
	            }else {
	                stua.stus[j]=temp;
	                break;
	            }
	        }
	    }
    }	
}
	/*
	*4.3 ���ɼ����� 
	*/
void sort_by_grade(){
	STU temp; //��ʱѧ���ṹ��	
	int i = 0 , j = 0;	
	for (i = 1 ; i < stua.len ; i++){
	    //����Ԫ��С���������е����һ��Ԫ��ʱ����ǰ����
	    if (stua.stus[i].grade < stua.stus[i - 1].grade){
	        temp = stua.stus[i]; //ǰһ���Ƚϴ��򽫵�i���ṹ�帳����ʱ���� 
	        for (j = i ; j >= 0 ; j--){
	            if (j > 0 && stua.stus[j - 1].grade > temp.grade) {
	                stua.stus[j]=stua.stus[j-1];
	            }else {
	                stua.stus[j]=temp;
	                break;
	            }
	        }
	    }
    }	
}
int student_information_sorting(){
	int cmd = 0;
	cout<<"1.����������"<<endl;
	cout<<"2.��ѧ������"<<endl;
	cout<<"3.���ɼ�����"<<endl;
	cin>>cmd;
	switch(cmd){
		case 1:{//���������� 
			sort_by_name();
			break;
		}
		case 2:{//��ѧ������ 
			sort_by_student_number();
			break;
		}
		case 3:{//���ɼ�����
			sort_by_grade(); 
			break;
		}
	}
	return 4;	
}

/*
*5.�޸�ѧ����Ϣ
*/
int modify_student_information(){
	int i = 0;
	int cmd;
	char name[100]; //����
	char no[100];//ѧ��
	int grade;//�ɼ� 
	int wordLen; //��ʱ�����ַ����� 
	bool flag;//�ظ���־ 
	cout<<"��������Ҫ�޸���һ�еı��:";
	do{
		cin>>cmd;
		if(cmd < 1 || cmd > stua.len)
			cout<<"������������ȷ�ı��:";	
	}while(cmd < 1 || cmd > stua.len); 
	
	cout<<"�������µ�����(����#�����޸�):";
	do{	
		cin>>name;
		wordLen = strlen(name);
		if(wordLen > 20){
			cout<<"����ѧ����������20�ֽڣ�����������:";
		}else{
			flag = check_name_repeated(name);//��������Ƿ��ظ� 
			if(flag)
				cout<<"����������ظ�������������:";
		}
	} while(wordLen > 20 || flag);
		
	cout<<"�������µ�ѧ��(����#�����޸�):";
	do{	
		cin>>no;
		wordLen = strlen(no);
		if(wordLen > 20){
			cout<<"����ѧ����������20�ֽڣ�����������:";
		}else{
			flag = check_no_repeated(no);//���ѧ���Ƿ��ظ� 
			if(flag)
				cout<<"����������ظ�������������:";
		}
	} while(wordLen > 20 || flag);
	
	cout<<"�������³ɼ�(����-1���޸�):";
	cin>>grade;
	//�޸����� 
	if(strcmp(name , "#") != 0){
		strcpy(stua.stus[cmd - 1].name , name);
	}
	//�޸�ѧ��
	if(strcmp(no , "#") != 0){
		strcpy(stua.stus[cmd - 1].no , no);
	} 
	//�޸ĳɼ�
	if(-1 != grade){
		stua.stus[cmd - 1].grade = grade;
	} 
	return 5; 
}

/*
*6.ɾ��ѧ����Ϣ
*/
int delete_student_information(){
	char buff[1024];
	int i = 0;
	int cmd; 
	do{
		cout<<"��������Ҫɾ������һ�еı��:";
		cin>>cmd;
		if(cmd <= 0 || cmd > stua.len)
			cout<<"���벻�ڷ�Χ������������!!!"<<endl;	
	}while(cmd <= 0 || cmd > stua.len);
	for(int j = cmd ; j < stua.len ; j++){
		stua.stus[j - 1] = stua.stus[j];
	}
	stua.len--;
	return 6;	
}
/*
*�鿴����ѧ����Ϣ 
*/ 
void view_all_student_information(){
	int i = 0;
	cout<<"==================ѧ��������Ϣ==================="<<endl; 
	cout<<"���"<<"\t����"<<"\tѧ��"<<"\t�ɼ�"<<"\t\t\t|"<<endl; 
	for(i = 0 ; i < stua.len ; i++){
		cout<<i+1<<"\t";
		cout<<stua.stus[i].name;
		cout<<"\t"<<stua.stus[i].no;
		cout<<"\t"<<stua.stus[i].grade<<"\t\t\t|"<<endl;
	}
	if(stua.len <= 0)
		cout<<"ռʱû��ѧ����Ϣ����Ǽǣ�����"<<endl;
	cout<<"================================================="<<endl; 
}

//����չʾ
void experience_display(int num){
	switch(num){
		case 1:
			cout<<"�Ǽǳɹ�������"<<endl;
			break;
		case 3:
			cout<<"����ѧ����Ϣ�ɹ�������"<<endl;
			break;
		case 4:
			cout<<"ѧ����Ϣ������ɣ�����"<<endl;
			break; 
		case 5:
			cout<<"�޸�ѧ����Ϣ��ɣ�����"<<endl;
			break;
		case 6:
			cout<<"ɾ��ѧ����Ϣ��ɣ�����"<<endl;
			break;	
	}
}


int main(int argc , char *argv[]){
	int cmd = 0;
	int num = 0;
	stua.len = 0;//��ʼ��ѧ�������� 
	read_file_data_to_student_set(); //���ļ���ȡ���ݵ�ѧ�����ݼ� 
	while(cmd != 7){
		view_all_student_information(); 
		cmd = initDesktop(); 
		num = 0;
		switch(cmd){
			case 1://�Ǽ�ѧ����Ϣ 
				num = register_student_information();
				break;
			case 2://����ѧ����Ϣ 
				find_flag = false; //���ò��ұ�� 
				find_student_information();
				if(!find_flag){
					cout<<"û�д������ݣ�����"<<endl;
				}
				break;
			case 3://����ѧ����Ϣ 
				num = save_student_information();
				break;
			case 4://ѧ����Ϣ���� 
				num = student_information_sorting();
				break;
			case 5://�޸�ѧ����Ϣ 
				num = modify_student_information();
				break;
			case 6://ɾ��ѧ����Ϣ 
				num = delete_student_information();
				break;
			case 7:
				cout<<"��ӭ����������"<<endl;
				break;		
			default:
				cout<<"������(1-7)�����֣�����"<<endl;		
		}
		experience_display(num);
		//��ͣһ�� 
		system("pause");
		//���� 
		system("cls");
	}

	return 0;
}


