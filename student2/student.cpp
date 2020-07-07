#include<iostream>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>   
#include <fcntl.h>  
using namespace std;

#define MAX_STUDENT 100 //最多存储100个学生 
#define FILENAME "students.txt" //文件名称
 
typedef struct student{//学生结构体 
	char name[20];
	char no[20];
	int grade;
}STU;

typedef struct stuArr{//学生结构体集 
	STU stus[MAX_STUDENT]; 
	int len;
}STUA;

STUA stua; //学生集 
bool find_flag = false;//查找标识 
/*
*读取文件数据到学生集 
*/
void read_file_data_to_student_set(){
	char buff[1024]; //缓冲区 
	char grade[20];
	char *stop;
	FILE* pFile = NULL; 
	if((access(FILENAME,F_OK)) == -1) //判断文件是否存在，不存在则创建   
    {   
       pFile = fopen(FILENAME, "w");//创建文件
	   fclose(pFile);   
    }   
	
	pFile = fopen(FILENAME, "r");//文件读操作 
	while(fgets(buff , sizeof(buff), pFile) != NULL){
		sscanf(buff , "%s %s %s" , stua.stus[stua.len].name , stua.stus[stua.len].no , grade);//从文件中按格式获取数据 
		stua.stus[stua.len].grade = strtol(grade , &stop , 10); //将字符串转化为10进制数字，并赋值给grade 
		stua.len++;				
	}	
	fclose(pFile);
}

/*
*初始化桌面 
*@返回输入的指令 
*/
int initDesktop(){
	cout<<endl;
	cout<<"==================基本操作======================="<<endl;
	cout<<"\t\t 1.登记学生信息"<<"\t\t\t|"<<endl;
	cout<<"\t\t 2.查找学生信息"<<"\t\t\t|"<<endl;
	cout<<"\t\t 3.保存学生信息"<<"\t\t\t|"<<endl;
	cout<<"\t\t 4.排序"<<"\t\t\t\t|"<<endl;
	cout<<"\t\t 5.修改学生信息"<<"\t\t\t|"<<endl;
	cout<<"\t\t 6.删除学生信息"<<"\t\t\t|"<<endl;
	cout<<"\t\t 7.退出"<<"\t\t\t\t|"<<endl;
	cout<<"================================================="<<endl;
	int num;
	cout<<"输入选项:";
	cin>>num; 
	
	return num;
}

/* 
*1.登记学生信息 
*/ 
	/*
	*1.1 检查输入姓名是否重复 
	*@有重复则返回 true
	*@无重复则返回 false 
	*/
bool check_name_repeated(char name[]){
	int i = 0;
	bool flag = false;
	for(i = 0 ; i < stua.len ; i++){
		if(strcmp(stua.stus[i].name , name) == 0 && strlen(stua.stus[i].name) == strlen(name)){//姓名重复 
			flag = true;
			break;
		}
	}
	return flag;
}
	/*
	*1.2 检查输入学号是否重复 
	*@有重复则返回 true
	*@无重复则返回 false 
	*/
bool check_no_repeated(char no[]){
	int i = 0;
	bool flag = false;
	for(i = 0 ; i < stua.len ; i++){
		if(strcmp(stua.stus[i].no , no) == 0 && strlen(stua.stus[i].no) == strlen(no)){//姓名重复 
			flag = true;
			break;
		}
	}
	return flag;
}


int register_student_information(){
	if(stua.len >= MAX_STUDENT){//判断是否达到上限 
		cout<<"学生数据集已满，请删除一些再添加！！！"<<endl;
		return 0;
	}
	bool flag; 
	char name[100]; //姓名 
	char no[100];  //学号 
	int grade;	//成绩 
	int wordLen;
	cout<<"请输入学生姓名:";
	do{	
		cin>>name;
		wordLen = strlen(name);
		if(wordLen > 20){
			cout<<"输入学生姓名超过20字节，请重新输入:";
		}else{
			flag = check_name_repeated(name);//检查姓名是否重复 
			if(flag)
				cout<<"输入的姓名重复，请重新输入:";
		}
	} while(wordLen > 20 || flag);
	
	
	cout<<"请输入学生学号:";
	do{	
		cin>> no;
		wordLen = strlen(no);
		if(wordLen > 20){
			cout<<"输入学生学号超过20字节，请重新输入:";
		}else{
			flag = check_no_repeated(no);//检查学号是否重复
			if(flag)
				cout<<"输入学号重复，请重新输入:";	
		}
	} while(wordLen > 20 || flag);
	
	cout<<"请输入学生成绩:";
	do{
		cin>> grade;
		if(grade > 1000){
			cout<<"输入成绩大于1000分，请重新输入:";
		}
	}while(grade > 1000);
	
	strcpy(stua.stus[stua.len].name , name);
	strcpy(stua.stus[stua.len].no , no);
	stua.stus[stua.len].grade = grade;
	stua.len++;
	return 1;
} 
/*
*2.查找学生信息 （采用模糊查询输入关键词即可） 
*/
	/*
	*2.1 按学生姓名查找 
	*/
void find_by_student_name(char name[]){
	int i = 0;
	cout<<"姓名"<<"\t学号"<<"\t成绩"<<endl; 
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
	*2.2 按学号查找 
	*/
void search_by_student_number(char no[]){
	int i = 0;
	cout<<"姓名"<<"\t学号"<<"\t成绩"<<endl; 
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
	*2.3 按成绩查找 
	*/
void find_by_grade(int grade){
	int i = 0;
	cout<<"姓名"<<"\t学号"<<"\t成绩"<<endl; 
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
	char name[100]; //输入姓名 
	char no[100];   //输入学号 
	int grade;	   //输入成绩 
	cout<<"1.按姓名查找"<<endl;
	cout<<"2.按学号查找"<<endl;
	cout<<"3.按成绩查找"<<endl;
	cout<<"输入选项:";
	cin>>cmd;
	switch(cmd){
		case 1:{//按姓名查找 
			cout<<"请输入需要查找的姓名:";	
			do{
				cin>>name;
				wordLen = strlen(name);
				if(wordLen > 20)
					cout<<"输入查找的姓名过长，请重新输入:"; 
			}while(wordLen > 20);
			find_by_student_name(name);//按姓名查找 
			break;
		}
		case 2:{//按学号查找 
			cout<<"请输入需要查找的学号:";
			do{
				cin>>no;
				wordLen = strlen(no);
				if(wordLen > 20)
					cout<<"输入查找的学号过长，请重新输入:"; 
			}while(wordLen > 20);
			search_by_student_number(no);//按学号查找 
			break;
		}
		case 3:{
			cout<<"请输入需要查找的成绩:";
			do{
				cin>>grade;
				if(grade > 1000)
					cout<<"输入查找的成绩过大，请重新输入:"; 
			}while(grade > 1000);
			find_by_grade(grade);//按成绩查找 
			break;
		}
	}	


}

/*
*3.保存学生信息
*/
int save_student_information(){
	int i= 0; 
	char buff[1024]; //缓冲区 
	FILE* pFile = fopen(FILENAME, "w");//文件不存在则创建
	for(i = 0 ; i < stua.len ; i++){
		sprintf(buff , "%s %s %d\n" , stua.stus[i].name , stua.stus[i].no , stua.stus[i].grade);	
		fputs(buff , pFile);
	}
	fclose(pFile);
	return 3;
}


/*
*4.学生信息排序 
*/
	/*
	*4.1 按姓名排序（插入排序） 
	*/
void sort_by_name(){
	STU temp; //临时学生结构体	
	int i = 0 , j = 0;	
	for (i = 1 ; i < stua.len ; i++){
	    //待排元素小于有序序列的最后一个元素时，向前插入
	    if (strcmp(stua.stus[i].name , stua.stus[i - 1].name) < 0){
	        temp = stua.stus[i]; //前一个比较大，则将第i个结构体赋给临时变量 
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
	*4.2 按学号排序 
	*/
void sort_by_student_number(){
	STU temp; //临时学生结构体	
	int i = 0 , j = 0;	
	for (i = 1 ; i < stua.len ; i++){
	    //待排元素小于有序序列的最后一个元素时，向前插入
	    if (strcmp(stua.stus[i].no , stua.stus[i - 1].no) < 0){
	        temp = stua.stus[i]; //前一个比较大，则将第i个结构体赋给临时变量 
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
	*4.3 按成绩排序 
	*/
void sort_by_grade(){
	STU temp; //临时学生结构体	
	int i = 0 , j = 0;	
	for (i = 1 ; i < stua.len ; i++){
	    //待排元素小于有序序列的最后一个元素时，向前插入
	    if (stua.stus[i].grade < stua.stus[i - 1].grade){
	        temp = stua.stus[i]; //前一个比较大，则将第i个结构体赋给临时变量 
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
	cout<<"1.按姓名排序"<<endl;
	cout<<"2.按学号排序"<<endl;
	cout<<"3.按成绩排序"<<endl;
	cin>>cmd;
	switch(cmd){
		case 1:{//按姓名排序 
			sort_by_name();
			break;
		}
		case 2:{//按学号排序 
			sort_by_student_number();
			break;
		}
		case 3:{//按成绩排序
			sort_by_grade(); 
			break;
		}
	}
	return 4;	
}

/*
*5.修改学生信息
*/
int modify_student_information(){
	int i = 0;
	int cmd;
	char name[100]; //名字
	char no[100];//学号
	int grade;//成绩 
	int wordLen; //临时保存字符长度 
	bool flag;//重复标志 
	cout<<"请输入需要修改哪一行的编号:";
	do{
		cin>>cmd;
		if(cmd < 1 || cmd > stua.len)
			cout<<"请重新输入正确的编号:";	
	}while(cmd < 1 || cmd > stua.len); 
	
	cout<<"请输入新的名字(输入#号则不修改):";
	do{	
		cin>>name;
		wordLen = strlen(name);
		if(wordLen > 20){
			cout<<"输入学生姓名超过20字节，请重新输入:";
		}else{
			flag = check_name_repeated(name);//检查姓名是否重复 
			if(flag)
				cout<<"输入的姓名重复，请重新输入:";
		}
	} while(wordLen > 20 || flag);
		
	cout<<"请输入新的学号(输入#号则不修改):";
	do{	
		cin>>no;
		wordLen = strlen(no);
		if(wordLen > 20){
			cout<<"输入学生姓名超过20字节，请重新输入:";
		}else{
			flag = check_no_repeated(no);//检查学号是否重复 
			if(flag)
				cout<<"输入的姓名重复，请重新输入:";
		}
	} while(wordLen > 20 || flag);
	
	cout<<"请输入新成绩(输入-1则不修改):";
	cin>>grade;
	//修改姓名 
	if(strcmp(name , "#") != 0){
		strcpy(stua.stus[cmd - 1].name , name);
	}
	//修改学号
	if(strcmp(no , "#") != 0){
		strcpy(stua.stus[cmd - 1].no , no);
	} 
	//修改成绩
	if(-1 != grade){
		stua.stus[cmd - 1].grade = grade;
	} 
	return 5; 
}

/*
*6.删除学生信息
*/
int delete_student_information(){
	char buff[1024];
	int i = 0;
	int cmd; 
	do{
		cout<<"请输入需要删除的那一行的编号:";
		cin>>cmd;
		if(cmd <= 0 || cmd > stua.len)
			cout<<"输入不在范围内请重新输入!!!"<<endl;	
	}while(cmd <= 0 || cmd > stua.len);
	for(int j = cmd ; j < stua.len ; j++){
		stua.stus[j - 1] = stua.stus[j];
	}
	stua.len--;
	return 6;	
}
/*
*查看所有学生信息 
*/ 
void view_all_student_information(){
	int i = 0;
	cout<<"==================学生基本信息==================="<<endl; 
	cout<<"编号"<<"\t姓名"<<"\t学号"<<"\t成绩"<<"\t\t\t|"<<endl; 
	for(i = 0 ; i < stua.len ; i++){
		cout<<i+1<<"\t";
		cout<<stua.stus[i].name;
		cout<<"\t"<<stua.stus[i].no;
		cout<<"\t"<<stua.stus[i].grade<<"\t\t\t|"<<endl;
	}
	if(stua.len <= 0)
		cout<<"占时没有学生信息，请登记！！！"<<endl;
	cout<<"================================================="<<endl; 
}

//体验展示
void experience_display(int num){
	switch(num){
		case 1:
			cout<<"登记成功！！！"<<endl;
			break;
		case 3:
			cout<<"保存学生信息成功！！！"<<endl;
			break;
		case 4:
			cout<<"学生信息排序完成！！！"<<endl;
			break; 
		case 5:
			cout<<"修改学生信息完成！！！"<<endl;
			break;
		case 6:
			cout<<"删除学生信息完成！！！"<<endl;
			break;	
	}
}


int main(int argc , char *argv[]){
	int cmd = 0;
	int num = 0;
	stua.len = 0;//初始化学生集长度 
	read_file_data_to_student_set(); //从文件读取数据到学生数据集 
	while(cmd != 7){
		view_all_student_information(); 
		cmd = initDesktop(); 
		num = 0;
		switch(cmd){
			case 1://登记学生信息 
				num = register_student_information();
				break;
			case 2://查找学生信息 
				find_flag = false; //重置查找标记 
				find_student_information();
				if(!find_flag){
					cout<<"没有此项数据！！！"<<endl;
				}
				break;
			case 3://保存学生信息 
				num = save_student_information();
				break;
			case 4://学生信息排序 
				num = student_information_sorting();
				break;
			case 5://修改学生信息 
				num = modify_student_information();
				break;
			case 6://删除学生信息 
				num = delete_student_information();
				break;
			case 7:
				cout<<"欢迎再来！！！"<<endl;
				break;		
			default:
				cout<<"请输入(1-7)的数字！！！"<<endl;		
		}
		experience_display(num);
		//暂停一下 
		system("pause");
		//清屏 
		system("cls");
	}

	return 0;
}


