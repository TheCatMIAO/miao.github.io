#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;            
struct lesson               	//课程结构体 
{
   float chinesegrade; 			//语文成绩 
   float mathgrade;         	//数学成绩 
   float englishgrade;     		//英语成绩 
};

struct student       			//学生结构体 
{
   char   name [10]; 			//姓名
   char   clas [20]; 			//班级
   int    num;       			//学号 
   float  sum;      			//总分 
   float  average;   			//均分 
   lesson less;      			//成绩
}m [100];						//学生结构体数组，最多100人

static int total = 0;			//全局变量，记录学生总数 

int welcome();    				// 系统欢迎界面 
void inputstu(); 				//录入学生信息 
void outputstu();  				//呈现学生信息 
void deletestu();  				//删除学生信息 
void namedeletestu();  			//按姓名删除学生信息 
void changegrade();    			//修改学生语数外成绩 
void changename();    			//修改学生姓名 
void findnamestu();  			//按姓名查找学生信息 
void findnumstu();   			//按学号查找学生信息 
void saveinfo();    			//保存学生信息成文本文件 


//主函数，先进入系统欢迎界面，通过switch实现相应的功能 
int main()
{
	int i=0;     				//功能选项 
	while(1)
	{
		i = welcome();			//进入欢迎界面，选择相应的功能 
		switch(i)
		{
			case 1:				//功能1输入学生信息 
				inputstu();    
				cout <<"     " << endl;
				cout<<"按任意键继续……"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
				break;
			case 2:				//功能2输出学生信息 
				outputstu(); 
				cout <<"     " << endl;
				cout<<"按任意键继续……"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
				break;
			case 3:				//功能3按学号删除学生信息 
            	deletestu();
            	cout <<"     " << endl;
            	cout<<"按任意键继续……"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;  
            case 4:				//功能4按姓名删除学生信息 
            	namedeletestu();
            	cout <<"     " << endl;
            	cout<<"按任意键继续……"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;
            case 5:				//功能5按学号修改学生语数外成绩 
            	changegrade();
            	cout <<"     " << endl;
            	cout<<"按任意键继续……"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;
            case 6:				//功能6按姓名修改学生语数外成绩 
            	changename();
            	cout <<"     " << endl;
            	cout<<"按任意键继续……"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;
            case 7:				// 功能7按姓名查找学生信息 
            	findnamestu();
            	cout <<"     " << endl;
            	cout<<"按任意键继续……"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;
            case 8:				//功能8按学号查找学生信息 
            	findnumstu();
            	cout <<"     " << endl;
            	cout<<"按任意键继续……"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;
             case 9:			//功能9保存录入的学生信息 
            	saveinfo();
            	cout <<"     " << endl;
            	cout<<"按任意键继续……"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;
            case 0:				//退出系统程序 
				return 0; 
			default:			//输入错误时重新回到系统 
				cout <<"请检查输入是否正确！！！"<< endl;
				cout <<"     " << endl;
            	cout<<"按任意键继续……"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
		}
		cout << endl;
	}
}

int welcome()       //欢迎界面 
{
	system("cls");  
	int i;  
	cout <<"\t\t\t                                                                             \n"<< endl;                                   
	cout <<"\t\t\t                         学生成绩管理系统  \n"<< endl;
	cout <<"\t\t\t******************************************************************************\n"<< endl;
	cout <<"\t\t\t*                1.  输入学生信息                                            *\n"<< endl;
	cout <<"\t\t\t*                2.  打印学生信息                                            *\n"<< endl;
	cout <<"\t\t\t*                3.  删除指定学号的学生信息                                  *\n"<< endl;
	cout <<"\t\t\t*                4.  删除指定姓名的学生信息                                  *\n"<< endl;
	cout <<"\t\t\t*                5.  修改学生成绩                                            *\n"<< endl;
	cout <<"\t\t\t*                6.  修改学生姓名                                            *\n"<< endl;
	cout <<"\t\t\t*                7.  按姓名查找学生信息                                      *\n"<< endl;
	cout <<"\t\t\t*                8.  按学号查找学生信息                                      *\n"<< endl;
	cout <<"\t\t\t*                9.  保存学生信息                                            *\n"<< endl;
	cout <<"\t\t\t*                0.  按0退出系统                                             *\n"<< endl;
	cout <<"\t\t\t******************************************************************************\n"<< endl;
	cout <<"\t\t\t   请选择:   "<< endl;
	cin >> i;
	return i;
}


// 
void inputstu()         //输入信息 
{
   int n ; 
   cout <<"请输入要增加学生信息的个数：  " << endl;   	//提示用户输入学生的个数 
   cin >> n;   
   cout << "请依次输入学生 1学号： 2姓名： 3班级： 4语文成绩： 5数学成绩： 6英语成绩： " << endl;
   for (int i = 0; i < n; i++) 							//用for循环接受键盘输入的学生信息，保存在学生结构体数组当中 
   {
      cin >> m [total+i].num;
      cin >> m [total+i].name 
	  	  >> m [total+i].clas 
		  >> m [total+i].less.chinesegrade
		  >> m [total+i].less.mathgrade
          >> m [total+i].less.englishgrade;                  
   }
   cout <<"输入成功!" << endl;
   total = total+n; 									// 记录学生的总数 
}


// 输出学生相关信息 
void outputstu()  
{
   //system("cls");  
   cout<<"   现在学生信息如下："<<endl;                                                    
   for (int i = 0; i < total; i++)						//for循环依次显示学生的各种信息 
   {
      m [i].sum =										//接受的只有语数外成绩，所以主动计算一下总分和平均分 
         (
            m [i].less.chinesegrade +
            m [i].less.englishgrade +
            m [i].less.mathgrade
         );                           

      m [i].average =
         (
            m [i].sum / 3
         );                            

      cout << "学号" << m [i].num << "  "				//输出信息 
           << "   姓名" << m [i].name
           << "   班级"<< m [i].clas
           << "   语文成绩"<< m [i].less.chinesegrade
           << "   数学成绩" << m [i].less.mathgrade
           << "   英语成绩" << m [i].less.englishgrade
           << "   总成绩" << m [i].sum
           << "   平均分" << m [i].average<< endl;
   }
} 



// 删除特定学号的学生信息 
void deletestu()       
{
   outputstu();										//先显示所有学生信息 
   cout << "   删除学生信息的学号为:     ";			//提示要输入的信息 
   int num;
   int flag = 0; 									//设置一个flag变量，标志是否删除成功 
   cin >> num;
   for (int i = 0; i < total; i++)					//在结构体数组里面寻找学号 
   {
      if (num == m [i].num)							//找到学号就删除 
      {
         int j;
         for (j = i; j < total - 1; j++)			//删除的功能通过数组前移实现 
         {
            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
            m [j].num     = m [j + 1].num;
            m [j].sum     = m [j + 1].sum;
            m [j].average = m [j + 1].average;
         }
		total--;									//删除之后把学生数量减一 
		flag = 1;									//标志删除成功 

         for (i = 0; i < total ; i++)  			//打印现存的学生信息 
         {
            cout << "学号" << m [i].num
                 << "  姓名" << m [i].name
                 << "  班级" << m [i].clas
                 << "  语文" << m [i].less.chinesegrade
                 << "  数学" << m [i].less.mathgrade
                 << "  英语" << m [i].less.englishgrade
                 << "  总分" << m [i].sum
                 << "  平均分" << m [i].average <<endl;
         }
         cout << "---删除成功---" << endl;
         break;
      }
   }
    if (flag == 0)									//若是没有删除成功，给出提示 
   	{
      cout << "---无该学生---" << endl;
   	}
}



// 根据姓名删除学生信息 
void namedeletestu()       
{
   outputstu();										//先展示学生信息 
   cout << "   删除学生信息的姓名为:     ";			//提示用户输入的内容 
   string name;
   int flag = 0;									//设置标志位，代表是否删除成功 
   cin >> name;
   for (int i = 0; i < total; i++)					//遍历学生结构体数组 
   {
      if (name == m [i].name)						//查找对应名字的学生 
      {
         int j;
         for (j = i; j < total - 1; j++)			//用数组前移实现删除 
         {
            strcpy(m [j].name, m [j + 1].name);
            strcpy(m [j].clas, m [j + 1].clas);
            m [j].less.chinesegrade = m [j + 1].less.chinesegrade;
            m [j].less.mathgrade    = m [j + 1].less.mathgrade;
            m [j].less.englishgrade = m [j + 1].less.englishgrade;
            m [j].num     = m [j + 1].num;
            m [j].sum     = m [j + 1].sum;
            m [j].average = m [j + 1].average;
         }
		total--;									//总数量减一 
		flag = 1;									//标志位设为1，表示删除成功 

         for (i = 0; i < total - 1; i++)			//显示剩余学生信息 
         {
            cout << "学号" << m [i].num
                 << "  姓名" << m [i].name
                 << "  班级" << m [i].clas
                 << "  语文" << m [i].less.chinesegrade
                 << "  数学" << m [i].less.mathgrade
                 << "  英语" << m [i].less.englishgrade
                 << "  总分" << m [i].sum
                 << "  平均分" << m [i].average <<endl;
         }
         cout << "---删除成功---" << endl;
         break;
      }
   }
   if (flag == 0)									//若是没有删除成功给出提示信息 
   	{
      cout << "---无该学生---" << endl;
   	}
} 



// 修改学生分数 
void changegrade()     
{
   outputstu();										//先展示学生信息 
   cout << "需要修改分数的学生信息的学号为:     ";  //提示用户输入需要修改成绩的学生学号 
   int num;
   int flag = 0;									//设置标志位 
   cin >> num;
   for (int i = 0; i < total; i++)					//遍历学生数组 
   {
      if (num == m [i].num)							//发现该学生 
      {
         int grade;
		 cout <<"修改语文成绩输入1，修改数学成绩输入2，修改英语成绩输入3." <<endl;  //提示需要修改的科目 
         cin >> grade; 
         float x;
         switch (grade)								//使用switch来选择具体修改的学生成绩科目 
         {											//一共三种情况 
         	case 1:
         		
				cout <<"将语文成绩修改为：   "<<endl;	//提示 
         		cin >> x;								//接收新的分数 
         		m [i].less.chinesegrade = x;			//赋值修改 
         		flag = 1;								//标志位更改为修改成功 
         		break;									//结束 
         	case 2:
         		//float x;
				cout <<"将数学成绩修改为：   "<<endl;
         		cin >> x;
         		m [i].less.mathgrade = x;
         		flag = 1;
         		break;
         	case 3:
			  	//float x;
				cout <<"将英语成绩修改为：   "<<endl;
         		cin >> x;
         		m [i].less.englishgrade = x;
         		flag = 1;
         		break;
         	default:
         		cout <<"输入错误！"<< endl;				//输入错误提示信息 
		 }
        cout << "学号" << m [i].num						//打印修改后的学生信息 
             << "  姓名" << m [i].name
             << "  班级" << m [i].clas
             << "  语文" << m [i].less.chinesegrade
             << "  英语" << m [i].less.englishgrade
             << "  数学" << m [i].less.mathgrade
             << "  总分" << m [i].sum
             << "  平均分" << m [i].average <<endl;
         cout << "---修改成功---" << endl;   
         break;
      }
   }
   if (flag == 0)										//若是没有修改成功，给出提示 
   	{
      cout << "---无该学生---" << endl;
   	}
} 


// 修改学生姓名 
void changename()
{
   outputstu();											//先展示学生信息 
   cout << " 需要修改姓名学生信息的学号为:     ";		//给出提示 
   int num;
   int flag = 0; 										//设置标志位 
   cin >> num;
   for (int i = 0; i < total; i++)						//遍历数组 
   {
      if (num == m [i].num)								//找到相应的学生 
      {
		cout <<"需要将姓名修改为：  " <<endl; 			//提示输入的信息 
        cin >> m [i].name;								//直接修改数组信息 
        flag = 1;										//设置标志位为修改成功 
		
		cout << "学号" << m [i].num						//显示修改后的学生信息 
		         << "  姓名" << m [i].name
		         << "  班级" << m [i].clas
		         << "  语文" << m [i].less.chinesegrade
		         << "  数学" << m [i].less.mathgrade
		         << "  英语" << m [i].less.englishgrade
		         << "  总分" << m [i].sum
		         << "  平均分" << m [i].average <<endl;
		cout << "---修改成功---" << endl;
		break;
    	}
   }
    if (flag == 0)										//若是没有修改成功，给出提示 
   	{
      cout << "---无该学生---" << endl;
   	}
}


//按姓名查找学生
void findnamestu()        								//是删除学生信息的子功能 
{
   cout << " 需要查找学生信息的姓名为:     ";
   string name;
   int flag = 0; 
   cin >> name;
   for (int i = 0; i < total; i++)
   {
      if (name == m [i].name)
      {
		cout <<"信息如下：  " <<endl; 
        flag = 1;
		
		cout << "学号" << m [i].num
		         << "  姓名" << m [i].name
		         << "  班级" << m [i].clas
		         << "  语文" << m [i].less.chinesegrade
		         << "  数学" << m [i].less.mathgrade
		         << "  英语" << m [i].less.englishgrade
		         << "  总分" << m [i].sum
		         << "  平均分" << m [i].average <<endl;
		cout << "---查找成功---" << endl;
		break;
    	}
   }
    if (flag == 0)
   	{
      cout << "---无该学生---" << endl;
   	}
}



//按学号查找学生 
void findnumstu()        									//是删除学生信息的子功能 
{
   cout << " 需要查找学生信息的学号为:     ";
   int num;
   int flag = 0; 
   cin >> num;
   for (int i = 0; i < total; i++)
   {
      if (num == m [i].num)
      {
		cout <<"学生信息如下：  " <<endl; 
        flag = 1;
		
		cout << "学号" << m [i].num
		         << "  姓名" << m [i].name
		         << "  班级" << m [i].clas
		         << "  语文" << m [i].less.chinesegrade
		         << "  数学" << m [i].less.mathgrade
		         << "  英语" << m [i].less.englishgrade
		         << "  总分" << m [i].sum
		         << "  平均分" << m [i].average <<endl;
		cout << "---查找成功---" << endl;
		break;
    	}
   }
    if (flag == 0)
   	{
      cout << "---无该学生---" << endl;
   	}
}


//保存学生的相关信息 
void saveinfo()    
{
   int i;
   ofstream outfile("Student.txt", ios::out);      		//定义输出文件流对象 
   outfile <<"学生数为："<< total << endl;		  		// 先将学生总数写进文件中 
   for (i = 0; i < total; i++)							//依次将所有学生信息写入文件 
   {
      outfile <<"学号：" << m [i].num << ' ';
      outfile <<"姓名：" << m [i].name << ' ';
      outfile <<"班级：" << m [i].clas << ' ';
      outfile <<"语文成绩：" << m [i].less.chinesegrade << ' ';
      outfile <<"数学成绩：" << m [i].less.mathgrade << ' ';
      outfile <<"英语成绩：" << m [i].less.englishgrade << ' ';
      outfile <<"总成绩：" << m [i].sum << ' ';
      outfile <<"平均分：" << m [i].average << ' ';
      outfile << endl;
   }
   outfile.close();										//关闭文件 
   cout << endl;
   cout << "---保存成功,请在Student.txt文件中查看---" << endl;
}


