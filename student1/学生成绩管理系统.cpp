#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;            
struct lesson               	//�γ̽ṹ�� 
{
   float chinesegrade; 			//���ĳɼ� 
   float mathgrade;         	//��ѧ�ɼ� 
   float englishgrade;     		//Ӣ��ɼ� 
};

struct student       			//ѧ���ṹ�� 
{
   char   name [10]; 			//����
   char   clas [20]; 			//�༶
   int    num;       			//ѧ�� 
   float  sum;      			//�ܷ� 
   float  average;   			//���� 
   lesson less;      			//�ɼ�
}m [100];						//ѧ���ṹ�����飬���100��

static int total = 0;			//ȫ�ֱ�������¼ѧ������ 

int welcome();    				// ϵͳ��ӭ���� 
void inputstu(); 				//¼��ѧ����Ϣ 
void outputstu();  				//����ѧ����Ϣ 
void deletestu();  				//ɾ��ѧ����Ϣ 
void namedeletestu();  			//������ɾ��ѧ����Ϣ 
void changegrade();    			//�޸�ѧ��������ɼ� 
void changename();    			//�޸�ѧ������ 
void findnamestu();  			//����������ѧ����Ϣ 
void findnumstu();   			//��ѧ�Ų���ѧ����Ϣ 
void saveinfo();    			//����ѧ����Ϣ���ı��ļ� 


//���������Ƚ���ϵͳ��ӭ���棬ͨ��switchʵ����Ӧ�Ĺ��� 
int main()
{
	int i=0;     				//����ѡ�� 
	while(1)
	{
		i = welcome();			//���뻶ӭ���棬ѡ����Ӧ�Ĺ��� 
		switch(i)
		{
			case 1:				//����1����ѧ����Ϣ 
				inputstu();    
				cout <<"     " << endl;
				cout<<"���������������"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
				break;
			case 2:				//����2���ѧ����Ϣ 
				outputstu(); 
				cout <<"     " << endl;
				cout<<"���������������"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
				break;
			case 3:				//����3��ѧ��ɾ��ѧ����Ϣ 
            	deletestu();
            	cout <<"     " << endl;
            	cout<<"���������������"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;  
            case 4:				//����4������ɾ��ѧ����Ϣ 
            	namedeletestu();
            	cout <<"     " << endl;
            	cout<<"���������������"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;
            case 5:				//����5��ѧ���޸�ѧ��������ɼ� 
            	changegrade();
            	cout <<"     " << endl;
            	cout<<"���������������"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;
            case 6:				//����6�������޸�ѧ��������ɼ� 
            	changename();
            	cout <<"     " << endl;
            	cout<<"���������������"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;
            case 7:				// ����7����������ѧ����Ϣ 
            	findnamestu();
            	cout <<"     " << endl;
            	cout<<"���������������"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;
            case 8:				//����8��ѧ�Ų���ѧ����Ϣ 
            	findnumstu();
            	cout <<"     " << endl;
            	cout<<"���������������"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;
             case 9:			//����9����¼���ѧ����Ϣ 
            	saveinfo();
            	cout <<"     " << endl;
            	cout<<"���������������"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
            	break;
            case 0:				//�˳�ϵͳ���� 
				return 0; 
			default:			//�������ʱ���»ص�ϵͳ 
				cout <<"���������Ƿ���ȷ������"<< endl;
				cout <<"     " << endl;
            	cout<<"���������������"<< endl;
				cin.clear();
				cin.sync();
				cin.get();
		}
		cout << endl;
	}
}

int welcome()       //��ӭ���� 
{
	system("cls");  
	int i;  
	cout <<"\t\t\t                                                                             \n"<< endl;                                   
	cout <<"\t\t\t                         ѧ���ɼ�����ϵͳ  \n"<< endl;
	cout <<"\t\t\t******************************************************************************\n"<< endl;
	cout <<"\t\t\t*                1.  ����ѧ����Ϣ                                            *\n"<< endl;
	cout <<"\t\t\t*                2.  ��ӡѧ����Ϣ                                            *\n"<< endl;
	cout <<"\t\t\t*                3.  ɾ��ָ��ѧ�ŵ�ѧ����Ϣ                                  *\n"<< endl;
	cout <<"\t\t\t*                4.  ɾ��ָ��������ѧ����Ϣ                                  *\n"<< endl;
	cout <<"\t\t\t*                5.  �޸�ѧ���ɼ�                                            *\n"<< endl;
	cout <<"\t\t\t*                6.  �޸�ѧ������                                            *\n"<< endl;
	cout <<"\t\t\t*                7.  ����������ѧ����Ϣ                                      *\n"<< endl;
	cout <<"\t\t\t*                8.  ��ѧ�Ų���ѧ����Ϣ                                      *\n"<< endl;
	cout <<"\t\t\t*                9.  ����ѧ����Ϣ                                            *\n"<< endl;
	cout <<"\t\t\t*                0.  ��0�˳�ϵͳ                                             *\n"<< endl;
	cout <<"\t\t\t******************************************************************************\n"<< endl;
	cout <<"\t\t\t   ��ѡ��:   "<< endl;
	cin >> i;
	return i;
}


// 
void inputstu()         //������Ϣ 
{
   int n ; 
   cout <<"������Ҫ����ѧ����Ϣ�ĸ�����  " << endl;   	//��ʾ�û�����ѧ���ĸ��� 
   cin >> n;   
   cout << "����������ѧ�� 1ѧ�ţ� 2������ 3�༶�� 4���ĳɼ��� 5��ѧ�ɼ��� 6Ӣ��ɼ��� " << endl;
   for (int i = 0; i < n; i++) 							//��forѭ�����ܼ��������ѧ����Ϣ��������ѧ���ṹ�����鵱�� 
   {
      cin >> m [total+i].num;
      cin >> m [total+i].name 
	  	  >> m [total+i].clas 
		  >> m [total+i].less.chinesegrade
		  >> m [total+i].less.mathgrade
          >> m [total+i].less.englishgrade;                  
   }
   cout <<"����ɹ�!" << endl;
   total = total+n; 									// ��¼ѧ�������� 
}


// ���ѧ�������Ϣ 
void outputstu()  
{
   //system("cls");  
   cout<<"   ����ѧ����Ϣ���£�"<<endl;                                                    
   for (int i = 0; i < total; i++)						//forѭ��������ʾѧ���ĸ�����Ϣ 
   {
      m [i].sum =										//���ܵ�ֻ��������ɼ���������������һ���ֺܷ�ƽ���� 
         (
            m [i].less.chinesegrade +
            m [i].less.englishgrade +
            m [i].less.mathgrade
         );                           

      m [i].average =
         (
            m [i].sum / 3
         );                            

      cout << "ѧ��" << m [i].num << "  "				//�����Ϣ 
           << "   ����" << m [i].name
           << "   �༶"<< m [i].clas
           << "   ���ĳɼ�"<< m [i].less.chinesegrade
           << "   ��ѧ�ɼ�" << m [i].less.mathgrade
           << "   Ӣ��ɼ�" << m [i].less.englishgrade
           << "   �ܳɼ�" << m [i].sum
           << "   ƽ����" << m [i].average<< endl;
   }
} 



// ɾ���ض�ѧ�ŵ�ѧ����Ϣ 
void deletestu()       
{
   outputstu();										//����ʾ����ѧ����Ϣ 
   cout << "   ɾ��ѧ����Ϣ��ѧ��Ϊ:     ";			//��ʾҪ�������Ϣ 
   int num;
   int flag = 0; 									//����һ��flag��������־�Ƿ�ɾ���ɹ� 
   cin >> num;
   for (int i = 0; i < total; i++)					//�ڽṹ����������Ѱ��ѧ�� 
   {
      if (num == m [i].num)							//�ҵ�ѧ�ž�ɾ�� 
      {
         int j;
         for (j = i; j < total - 1; j++)			//ɾ���Ĺ���ͨ������ǰ��ʵ�� 
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
		total--;									//ɾ��֮���ѧ��������һ 
		flag = 1;									//��־ɾ���ɹ� 

         for (i = 0; i < total ; i++)  			//��ӡ�ִ��ѧ����Ϣ 
         {
            cout << "ѧ��" << m [i].num
                 << "  ����" << m [i].name
                 << "  �༶" << m [i].clas
                 << "  ����" << m [i].less.chinesegrade
                 << "  ��ѧ" << m [i].less.mathgrade
                 << "  Ӣ��" << m [i].less.englishgrade
                 << "  �ܷ�" << m [i].sum
                 << "  ƽ����" << m [i].average <<endl;
         }
         cout << "---ɾ���ɹ�---" << endl;
         break;
      }
   }
    if (flag == 0)									//����û��ɾ���ɹ���������ʾ 
   	{
      cout << "---�޸�ѧ��---" << endl;
   	}
}



// ��������ɾ��ѧ����Ϣ 
void namedeletestu()       
{
   outputstu();										//��չʾѧ����Ϣ 
   cout << "   ɾ��ѧ����Ϣ������Ϊ:     ";			//��ʾ�û���������� 
   string name;
   int flag = 0;									//���ñ�־λ�������Ƿ�ɾ���ɹ� 
   cin >> name;
   for (int i = 0; i < total; i++)					//����ѧ���ṹ������ 
   {
      if (name == m [i].name)						//���Ҷ�Ӧ���ֵ�ѧ�� 
      {
         int j;
         for (j = i; j < total - 1; j++)			//������ǰ��ʵ��ɾ�� 
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
		total--;									//��������һ 
		flag = 1;									//��־λ��Ϊ1����ʾɾ���ɹ� 

         for (i = 0; i < total - 1; i++)			//��ʾʣ��ѧ����Ϣ 
         {
            cout << "ѧ��" << m [i].num
                 << "  ����" << m [i].name
                 << "  �༶" << m [i].clas
                 << "  ����" << m [i].less.chinesegrade
                 << "  ��ѧ" << m [i].less.mathgrade
                 << "  Ӣ��" << m [i].less.englishgrade
                 << "  �ܷ�" << m [i].sum
                 << "  ƽ����" << m [i].average <<endl;
         }
         cout << "---ɾ���ɹ�---" << endl;
         break;
      }
   }
   if (flag == 0)									//����û��ɾ���ɹ�������ʾ��Ϣ 
   	{
      cout << "---�޸�ѧ��---" << endl;
   	}
} 



// �޸�ѧ������ 
void changegrade()     
{
   outputstu();										//��չʾѧ����Ϣ 
   cout << "��Ҫ�޸ķ�����ѧ����Ϣ��ѧ��Ϊ:     ";  //��ʾ�û�������Ҫ�޸ĳɼ���ѧ��ѧ�� 
   int num;
   int flag = 0;									//���ñ�־λ 
   cin >> num;
   for (int i = 0; i < total; i++)					//����ѧ������ 
   {
      if (num == m [i].num)							//���ָ�ѧ�� 
      {
         int grade;
		 cout <<"�޸����ĳɼ�����1���޸���ѧ�ɼ�����2���޸�Ӣ��ɼ�����3." <<endl;  //��ʾ��Ҫ�޸ĵĿ�Ŀ 
         cin >> grade; 
         float x;
         switch (grade)								//ʹ��switch��ѡ������޸ĵ�ѧ���ɼ���Ŀ 
         {											//һ��������� 
         	case 1:
         		
				cout <<"�����ĳɼ��޸�Ϊ��   "<<endl;	//��ʾ 
         		cin >> x;								//�����µķ��� 
         		m [i].less.chinesegrade = x;			//��ֵ�޸� 
         		flag = 1;								//��־λ����Ϊ�޸ĳɹ� 
         		break;									//���� 
         	case 2:
         		//float x;
				cout <<"����ѧ�ɼ��޸�Ϊ��   "<<endl;
         		cin >> x;
         		m [i].less.mathgrade = x;
         		flag = 1;
         		break;
         	case 3:
			  	//float x;
				cout <<"��Ӣ��ɼ��޸�Ϊ��   "<<endl;
         		cin >> x;
         		m [i].less.englishgrade = x;
         		flag = 1;
         		break;
         	default:
         		cout <<"�������"<< endl;				//���������ʾ��Ϣ 
		 }
        cout << "ѧ��" << m [i].num						//��ӡ�޸ĺ��ѧ����Ϣ 
             << "  ����" << m [i].name
             << "  �༶" << m [i].clas
             << "  ����" << m [i].less.chinesegrade
             << "  Ӣ��" << m [i].less.englishgrade
             << "  ��ѧ" << m [i].less.mathgrade
             << "  �ܷ�" << m [i].sum
             << "  ƽ����" << m [i].average <<endl;
         cout << "---�޸ĳɹ�---" << endl;   
         break;
      }
   }
   if (flag == 0)										//����û���޸ĳɹ���������ʾ 
   	{
      cout << "---�޸�ѧ��---" << endl;
   	}
} 


// �޸�ѧ������ 
void changename()
{
   outputstu();											//��չʾѧ����Ϣ 
   cout << " ��Ҫ�޸�����ѧ����Ϣ��ѧ��Ϊ:     ";		//������ʾ 
   int num;
   int flag = 0; 										//���ñ�־λ 
   cin >> num;
   for (int i = 0; i < total; i++)						//�������� 
   {
      if (num == m [i].num)								//�ҵ���Ӧ��ѧ�� 
      {
		cout <<"��Ҫ�������޸�Ϊ��  " <<endl; 			//��ʾ�������Ϣ 
        cin >> m [i].name;								//ֱ���޸�������Ϣ 
        flag = 1;										//���ñ�־λΪ�޸ĳɹ� 
		
		cout << "ѧ��" << m [i].num						//��ʾ�޸ĺ��ѧ����Ϣ 
		         << "  ����" << m [i].name
		         << "  �༶" << m [i].clas
		         << "  ����" << m [i].less.chinesegrade
		         << "  ��ѧ" << m [i].less.mathgrade
		         << "  Ӣ��" << m [i].less.englishgrade
		         << "  �ܷ�" << m [i].sum
		         << "  ƽ����" << m [i].average <<endl;
		cout << "---�޸ĳɹ�---" << endl;
		break;
    	}
   }
    if (flag == 0)										//����û���޸ĳɹ���������ʾ 
   	{
      cout << "---�޸�ѧ��---" << endl;
   	}
}


//����������ѧ��
void findnamestu()        								//��ɾ��ѧ����Ϣ���ӹ��� 
{
   cout << " ��Ҫ����ѧ����Ϣ������Ϊ:     ";
   string name;
   int flag = 0; 
   cin >> name;
   for (int i = 0; i < total; i++)
   {
      if (name == m [i].name)
      {
		cout <<"��Ϣ���£�  " <<endl; 
        flag = 1;
		
		cout << "ѧ��" << m [i].num
		         << "  ����" << m [i].name
		         << "  �༶" << m [i].clas
		         << "  ����" << m [i].less.chinesegrade
		         << "  ��ѧ" << m [i].less.mathgrade
		         << "  Ӣ��" << m [i].less.englishgrade
		         << "  �ܷ�" << m [i].sum
		         << "  ƽ����" << m [i].average <<endl;
		cout << "---���ҳɹ�---" << endl;
		break;
    	}
   }
    if (flag == 0)
   	{
      cout << "---�޸�ѧ��---" << endl;
   	}
}



//��ѧ�Ų���ѧ�� 
void findnumstu()        									//��ɾ��ѧ����Ϣ���ӹ��� 
{
   cout << " ��Ҫ����ѧ����Ϣ��ѧ��Ϊ:     ";
   int num;
   int flag = 0; 
   cin >> num;
   for (int i = 0; i < total; i++)
   {
      if (num == m [i].num)
      {
		cout <<"ѧ����Ϣ���£�  " <<endl; 
        flag = 1;
		
		cout << "ѧ��" << m [i].num
		         << "  ����" << m [i].name
		         << "  �༶" << m [i].clas
		         << "  ����" << m [i].less.chinesegrade
		         << "  ��ѧ" << m [i].less.mathgrade
		         << "  Ӣ��" << m [i].less.englishgrade
		         << "  �ܷ�" << m [i].sum
		         << "  ƽ����" << m [i].average <<endl;
		cout << "---���ҳɹ�---" << endl;
		break;
    	}
   }
    if (flag == 0)
   	{
      cout << "---�޸�ѧ��---" << endl;
   	}
}


//����ѧ���������Ϣ 
void saveinfo()    
{
   int i;
   ofstream outfile("Student.txt", ios::out);      		//��������ļ������� 
   outfile <<"ѧ����Ϊ��"<< total << endl;		  		// �Ƚ�ѧ������д���ļ��� 
   for (i = 0; i < total; i++)							//���ν�����ѧ����Ϣд���ļ� 
   {
      outfile <<"ѧ�ţ�" << m [i].num << ' ';
      outfile <<"������" << m [i].name << ' ';
      outfile <<"�༶��" << m [i].clas << ' ';
      outfile <<"���ĳɼ���" << m [i].less.chinesegrade << ' ';
      outfile <<"��ѧ�ɼ���" << m [i].less.mathgrade << ' ';
      outfile <<"Ӣ��ɼ���" << m [i].less.englishgrade << ' ';
      outfile <<"�ܳɼ���" << m [i].sum << ' ';
      outfile <<"ƽ���֣�" << m [i].average << ' ';
      outfile << endl;
   }
   outfile.close();										//�ر��ļ� 
   cout << endl;
   cout << "---����ɹ�,����Student.txt�ļ��в鿴---" << endl;
}


