#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class Book{
public:	
	void addbook(int n,char *I,char *sn,char *sp,char *sa)//����ͼ�� 
	{
		being=1;
		number=n;//��� 
		strcpy(ISBN,I);
		strcpy(name,sn);//���� 
		strcpy(press,sp);//������ 
		strcpy(author,sa);//����  
	}
	void showbook()//���ͼ����Ϣ 
	{
		cout<<"���"<<" "<<"ISBN"<<" "<<"����"<<" "<<"������"<<" "<<"����"<<" "<<"�ڿ����"<<endl; 
		cout<<number<<" "<<ISBN<<" "<<name<<" "<<press<<" "<<author<<" "<<being<<endl;
	}
	void clear()//����ͼ�� 
	{
		being=10;
	}
	int getnumber()//��ȡ���� 
	{
		return number;
	}
	char *getISBN()
	{
		return ISBN; 
	}
	char *getname()
	{
		return name; 
	}
	int getbeing()
	{
		return being;
	}	
	void changeISBN(char I[])//�ı�ͼ���ISBN 
	{
		strcpy(ISBN,I);
	}
	void changename(char sn[])
	{
		strcpy(name,sn);
	}
	void changepress(char sp[])
	{
		strcpy(press,sp);
	}
	void changeauthor(char sa[])
	{
		strcpy(author,sa);
	}
	void changekeeper(char keeper1[])
	{
		strcpy(keeper,keeper1);
	}
	void changebeing(int be)
	{
		being=be;
	} 

private:
	int number;// ��� 
	char ISBN[30];//ISBN 
	char name[30];//���� 
	char press[30];//������ 
	char author[30];//���� 
	int ifEbook;//1��ʾ�ǵ����� 
	int being;//1��ʾ�ڿ⣬0��ʾ�ڽ裬10��ʾ�쳣 
	char keeper[30];//�ֱ����� 
};

class changebook:public Book
{ 
public:	
changebook();//���캯�� 
void addbook(int n,char *I,char *sn,char *sp,char *sa)//���ͼ�� 
{
	Book *l=search1(n);
	if(l==NULL)
	{
		book[i].addbook(n,I,sn,sp,sa);
		i++;
		cout<<"��ӳɹ�"<<endl;
		return ;
	}
	cout<<"���ʧ��"<<endl; 
}
Book *search1(int num)//����Ų��� 
{
	for(int j=0;j<i;j++)
	{
		if(book[j].getnumber()==num&&book[j].getbeing()!=10)
		return &book[j];
	} 
	return NULL;
}
Book *search2(char isbn[])//��ISBN���� 
{
	for(int j=0;j<i;j++)
	{
		if(strcmp(book[j].getISBN(),isbn)==0&&book[j].getbeing()!=10)
		return &book[j];
	} 
	return NULL;
}
Book *search3(char nam[])//�����ֲ��� 
{
	for(int j=0;j<i;j++)
	{
		if(strcmp(book[j].getname(),nam)==0&&book[j].getbeing()!=10)
		return &book[j];
	} 
	return NULL;
}
void perform1();//ִ�д��� 
~changebook()//�������� 
{
fstream file("F:\\book.txt",ios::out);
for(int j=0;j<i;j++)
{
	if(book[j].getbeing()!=10)
	{
		file.write((char *)&book[j],sizeof(book[j]));
	}
	file.close();
}		
}
private:	
int i;//�鼮���� 
Book book[200];	
};
changebook::changebook()//���캯�� 
{
Book k;
i=0;
fstream file("F:\\book.txt",ios::in);
for(;;)
{
	file.read((char *)&k,sizeof(k));
	if(!file)
	{
		break;
	}
	book[i]=k;
	i++;
} 
file.close();
}
void changebook::perform1()//ִ�д��� 
{
	int choice=0;
	int number1,number2;
	char ISBN1[30];
	char name1[30]; 
	char press1[30];
	char author1[30];
	Book *u;
while(choice!=5)
{
	cout<<"ͼ����Ϣ"<<endl; 
	cout<<"1.����"<<endl;
	cout<<"2.ɾ��"<<endl; 
	cout<<"3.����"<<endl; 
	cout<<"4.����"<<endl;
	cout<<"5.����"<<endl;
	cout<<"��ѡ��:"<<endl; 
	cin>>choice;
	switch(choice)
	{
	case 1:
	cout<<"��������"<<endl; 
	cin>>number1;
	cout<<"������ISBN"<<endl;
	cin>>ISBN1; 
	cout<<"����������"<<endl;
	cin>>name1;
	cout<<"�����������"<<endl;
	cin>>press1;
	cout<<"����������"<<endl;	
	cin>>author1;
	addbook(number1,ISBN1,name1,press1,author1);
	break;
	case 2:
	cout<<"��������"<<endl;
	cin>>number2; 
	u=search1(number2);
	if(u==NULL)
	{
		cout<<"���鲻����"<<endl;
		break; 
	}
	u->clear();
	cout<<"ɾ���ɹ�"<<endl; 
	break;
	case 3:
	cout<<"������ͼ����"<<endl;
	cin>>number2;
	u=search1(number2);
	if(u==NULL)
	{
		cout<<"���鲻����"<<endl;
		break; 
	}
	else
	{
	int a=0;
	cout<<"1.�޸�ISBN"<<endl; 
	cout<<"2.�޸�����"<<endl;
	cout<<"3.�޸ĳ�����"<<endl;
	cout<<"4.�޸�����"<<endl;
	cout<<"5.����"<<endl;
	cout<<"��ѡ��:"<<endl; 
	cin>>a;
	switch(a)
	{
	case 1:
	cout<<"�������µ�ISBN"<<endl;
	cin>>ISBN1;
	u->changeISBN(name1);
	cout<<"�޸ĳɹ�"<<endl;
	break;		
	case 2:
	cout<<"�������µ�����"<<endl;
	cin>>name1;
	u->changename(name1);
	cout<<"�޸ĳɹ�"<<endl;
	break;	
	case 3:
	cout<<"�������µĳ�����"<<endl;
	cin>>press1;
	u->changepress(press1);
	cout<<"�޸ĳɹ�"<<endl;
	break;
	case 4:
	cout<<"�������µ�����"<<endl;
	cin>>author1;
	u->changeauthor(author1);
	cout<<"�޸ĳɹ�"<<endl;
	break;	
	case 5:
	break;	
	default:
	break;
	}
	}
	break;
	case 4:
	int a;
	cout<<"1.����Ų���"<<endl; 
	cout<<"2.��ISBN����"<<endl;
	cout<<"3.�����ֲ���"<<endl;
	cout<<"��ѡ��:"<<endl;	
	cin>>a;
	switch(a)
	{
	case 1:
	cout<<"��������"<<endl;
	cin>>number1;
	u=search1(number1);	
	if(u==NULL)
	{
		cout<<"������"<<endl; 
	}
	else
	{
		u->showbook();
	}
	break;
	case 2:
	cout<<"������ISBN"<<endl;
	cin>>ISBN1;
	u=search2(ISBN1);
	if(u==NULL)
	{
		cout<<"������"<<endl; 
	}
	else
	{
		u->showbook();
	}
	break;
	case 3:	
	cout<<"����������"<<endl;
	cin>>name1;
	u=search3(name1);
	if(u==NULL)
	{
		cout<<"������"<<endl; 
	}
	else
	{
		u->showbook();
	}
	break;
	}
	break;	
	case 5:
	break;	
	default: 
	break;	
	}		
}	 
}

class Ebook:public changebook//������ ,���๦���� Book��ͼ�鹦������ 
{
public:
	void perform2()
	{
	int a=0;
	do{	
	cout<<"1.�����Ķ�"<<endl;
	cout<<"2.����"<<endl;
	cout<<"3.����"<<endl; 
	cout<<"��ѡ��:"<<endl;; 
	cin>>a;
	switch(a)
	{
	case 1://�����Ķ� 
	{ifstream ifs("F:\\1.txt");
	char str[300];
	while(!ifs.eof())
	{
	ifs.getline(str,299);
	cout<<str;		
	}
	cout<<endl;
	ifs.close();
	}
	break;	
	case 2://���� 
	{
	char ch;
	ifstream file("F:/1.txt");
	char location[30];
	/*cout<<"���������صĵ�ַ"<<endl;
	cin>>location; */
	ofstream file1("F:/2.txt",ios::app);//�����ı��ļ�
	while(file.get(ch))
	{
		file1<<ch;
	}
	file.close(); 
	file1.close();
	cout<<endl;
	}
	break;
	case 3:
	break;	
	default:
	break; 	
	}	
	}while(a!=3);	
	}
private:
	int number;
	char topic[30];	
	char author[10][30];
	char journal[30];
	char time[30];
};


class user{
public:
	//user(); 
	void borrowbook(int numb1)//���� 
	{
		numb+=numb1;
	}
	void returnbook(int numb2)//���� 
	{
		numb-=numb2;
	}
	void adduser(int ro,char na[],char un[],char pa[])//����û� 
	{
		d=1;
		numb=0;
		role=ro;
		strcpy(name,na);
		strcpy(username,un);
		strcpy(passport,pa);
	}
	void deleteuser(char na[])//ɾ���û� 
	{
		d=0;
	}
	char *getname()//��ȡ���� 
	{
		return name;
	}
	char *getusername()
	{
		return username;
	}
	char *getpassport()
	{
		return passport;
	}
	void setusername(char m[])
	{
		strcpy(username,m);
	}
	void setpassport(char m[])
	{
		strcpy(passport,m);
	}
	int getd()
	{
		return d;
	}
	void showuser()
	{
		cout<<"����"<<" "<<"�û���"<<" "<<"��������"<<endl;
		cout<<name<<" "<<username<<" "<<numb<<endl;
	}
	//~user();
private:	
	char name[30];//���� 
	char username[30];// �û��� 
	char passport[30];//���� 
	int role;//0��ʾ��ͨ�û���1��ʾ����Ա
	int numb; //�������� 
	int d;//d=0��ʾ��ɾ��
};

class account:public user
{
public:	
account();//���캯�� 
void addUser()//����û� 
{
	user user1;
	int role1;
	char name1[30];
	char username1[30];
	char passport1[30];
	cout<<"����Ա�밴1����ͨ�û��밴0"<<endl;
	cin>>role1; 
	cout<<"����������"<<endl;
	cin>>name1; 
	cout<<"�������û���"<<endl;
	cin>>username1;
	cout<<"����������"<<endl;	
	cin>>passport1;
	user1.adduser(role1,name1,username1,passport1);
	users[h]=user1; 
	h++;
}
user *check(char name2[])//�����������û� 
{
	for(int j=0;j<h;j++)
	{
		if(strcmp(users[j].getname(),name2)==0&&users[j].getd()!=0)
		{
			return &users[j];
		}
	}
	return NULL;
}
user *check2(char username2[])//���û��������û� 
{
	for(int j=0;j<h;j++)
	{
		if(strcmp(users[j].getusername(),username2)==0&&users[j].getd()!=0)
		{
			return &users[j];
		}
	}
	return NULL;
}
void perform();//�û�ѡ����ҳ�� 
void updateUser();//�����û���Ϣ 
void deleteUser();//ɾ���û� 
void lookupUser();
~account()//�������� 
{
fstream file("F:\\user.txt",ios::out);
h=0;
for(int j=0;j<h;j++)
{
	if(users[j].getd()!=0)
	{
		file.write((char *)&users[j],sizeof(users[j]));
	}
	file.close();
}		
}
private:
	user users[200];
	int h;
};
account::account()// ���캯�� 
{
	user us;
	fstream file("F:\\user.txt",ios::in);
for(;;)
{
	file.read((char *)&us,sizeof(us));
	if(!file)
	{
		break;
	}
	users[h]=us;
	h++;
} 
file.close();
} 
void account::updateUser()//�����û���Ϣ 
{
	char name1[30],username1[30],passport1[30];
	user *r;
	cout<<"�������û�����"<<endl;
	cin>>name1;
	r=check(name1);
	if(r==NULL)
	{
	cout<<"������"<<endl; 
	return;
	} 
	else 
	{
		int p;
		cout<<"1.�����û���"<<endl;
		cout<<"2.��������"<<endl;
		cout<<"��ѡ��:"<<endl;
		cin>>p;
		switch(p) 
		{
			case 1:
			cout<<"�������µ��û���"<<endl;
			cin>>username1;
			r->setusername(username1);
			break; 
			case 2:
			cout<<"�������µ�����"<<endl;
			cin>>passport1;
			r->setpassport(passport1);
			break;
			default:
			break;	
		}
	}	
}
void account::lookupUser()//�����û� 
{
	char name2[30];
	cout<<"����������"<<endl;
	cin>>name2;
	user *r;
	r=check(name2);
	if(r==NULL)
	{
		cout<<"������"<<endl; 
	} 
	else
	{
		r->showuser();
	} 
}
void account::deleteUser()//ɾ���û� 
{
	char name3[30];
	user *r;
	cout<<"������Ҫɾ�����û�����"<<endl;
	cin>>name3;
	r=check(name3); 
	if(r==NULL)
	{
		cout<<"���û�������"<<endl;
		return; 
	}
	else 
	{
		r->deleteuser(name3);
		cout<<"ɾ���ɹ�"<<endl; 
	}		
}  
void account::perform()//�û�ѡ����ҳ�� 
{
	int l;
	do
	{
		cout<<"1.����û�"<<endl;
		cout<<"2.�����û�"<<endl;
		cout<<"3.ɾ���û�"<<endl;
		cout<<"4.�����û�"<<endl; 
		cout<<"5.����"<<endl;
		cout<<"��ѡ��:"<<endl;
		cin>>l;
		switch(l)
		{
		case 1:
		addUser();
		break;	
		case 2:
		updateUser();
		break;
		case 3:
		deleteUser();
		break;
		case 4:
		lookupUser();	
		case 5:
		break;	
		default:
		break;
		} 
	}while(l!=4);
}	
int main()
{
	char pass[20];
	long long identifier;
	int z;	
	changebook change1;
	Book *o;
	Ebook ebook1;
	user *e;
	account account1;
	cout<<"��ӭ��¼ͼ�����ϵͳ~"<<endl; 
	cout<<"����Ա�밴1"<<endl;
	cout<<"��ͨ�û��밴2"<<endl;
	int f;
	cin>>f;
	switch(f)
	{
	case 1:	
	cout<<"���������Ա����"<<endl;
	cin>>pass;
	if(strcmp(pass,"2017")==0)
	{
		cout<<"��½�ɹ�"<<endl; 
	}
	else
	{
		cout<<"��¼ʧ��"<<endl;
		return 0;
	}
	break;
	case 2: 
	cout<<"������ѧ�ź�����"<<endl; 
	cin>>identifier;
	cin>>pass;
	break;
	default:
	break;	
	}
	do
	{
	cout<<"1.ͼ��"<<endl;
	cout<<"2.������"<<endl;
	cout<<"3.�����뻹��"<<endl;
	cout<<"4.�û�"<<endl; 
	cout<<"�˳��밴0"<<endl; 
	cout<<"��ѡ��:"<<endl; 
	cin>>z;
	switch(z)
	{
	case 0:
	break; 
	case 1:
	change1.perform1();
	break;
	case 2:
	ebook1.perform2();
	ebook1.perform1();
	break;	
	case 3:
	char name4[30];
	cout<<"����������"<<endl;
	cin>>name4;
	e=account1.check(name4);
	if((e==NULL)||(e->getd()==0))
	{
		cout<<"���û�������"<<endl;
		break; 
	}
	else
	{
		cout<<"1.����"<<endl;
		cout<<"2.����"<<endl;
		int q;
		cin>>q;
		int x;
		switch(q)
		{
		case 1:
		cout<<"��������鱾��"<<endl;
		cin>>x;
		for(int g=0;g<x;g++)
		{
		char name6[30];
		cout<<"�������鼮����"<<endl;
		cin>>name6;
		o=change1.search3(name6);
		if(o==NULL)
		{
			cout<<"���鲻����"<<endl;
			break; 
		}
		else
		{
		o->changekeeper(name4);
		e->borrowbook(x);
		o->changebeing(0);
		}
		}
		break;
		case 2:
		cout<<"�����뻹�鱾��"<<endl;
		cin>>x;
		for(int g=0;g<x;g++)
		{ 
		char name7[30];
		cout<<"�������鼮����"<<endl;
		cin>>name7;
		o=change1.search3(name7);
		if(o==NULL)
		{
			cout<<"���鲻����"<<endl;
			break; 
		}
		else
		{
		o->changebeing(1); 
		e->returnbook(x);
		}
		}
		break;	
		default:
		break;
		} 
	}
	case 4:
	account1.perform();
	break;
	default:
	break;	
	}	
	}while(z!=0);
	return 0;
}
