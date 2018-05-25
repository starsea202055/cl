#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class Book{
public:	
	void addbook(int n,char *I,char *sn,char *sp,char *sa)//增加图书 
	{
		being=1;
		number=n;//编号 
		strcpy(ISBN,I);
		strcpy(name,sn);//名称 
		strcpy(press,sp);//出版社 
		strcpy(author,sa);//作者  
	}
	void showbook()//输出图书信息 
	{
		cout<<"编号"<<" "<<"ISBN"<<" "<<"名称"<<" "<<"出版社"<<" "<<"作者"<<" "<<"在库情况"<<endl; 
		cout<<number<<" "<<ISBN<<" "<<name<<" "<<press<<" "<<author<<" "<<being<<endl;
	}
	void clear()//减少图书 
	{
		being=10;
	}
	int getnumber()//获取名字 
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
	void changeISBN(char I[])//改变图书的ISBN 
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
	int number;// 编号 
	char ISBN[30];//ISBN 
	char name[30];//名称 
	char press[30];//出版社 
	char author[30];//作者 
	int ifEbook;//1表示是电子书 
	int being;//1表示在库，0表示在借，10表示异常 
	char keeper[30];//现保存者 
};

class changebook:public Book
{ 
public:	
changebook();//构造函数 
void addbook(int n,char *I,char *sn,char *sp,char *sa)//添加图书 
{
	Book *l=search1(n);
	if(l==NULL)
	{
		book[i].addbook(n,I,sn,sp,sa);
		i++;
		cout<<"添加成功"<<endl;
		return ;
	}
	cout<<"添加失败"<<endl; 
}
Book *search1(int num)//按编号查找 
{
	for(int j=0;j<i;j++)
	{
		if(book[j].getnumber()==num&&book[j].getbeing()!=10)
		return &book[j];
	} 
	return NULL;
}
Book *search2(char isbn[])//按ISBN查找 
{
	for(int j=0;j<i;j++)
	{
		if(strcmp(book[j].getISBN(),isbn)==0&&book[j].getbeing()!=10)
		return &book[j];
	} 
	return NULL;
}
Book *search3(char nam[])//按名字查找 
{
	for(int j=0;j<i;j++)
	{
		if(strcmp(book[j].getname(),nam)==0&&book[j].getbeing()!=10)
		return &book[j];
	} 
	return NULL;
}
void perform1();//执行窗口 
~changebook()//析构函数 
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
int i;//书籍数量 
Book book[200];	
};
changebook::changebook()//构造函数 
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
void changebook::perform1()//执行窗口 
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
	cout<<"图书信息"<<endl; 
	cout<<"1.新增"<<endl;
	cout<<"2.删除"<<endl; 
	cout<<"3.更改"<<endl; 
	cout<<"4.查找"<<endl;
	cout<<"5.返回"<<endl;
	cout<<"请选择:"<<endl; 
	cin>>choice;
	switch(choice)
	{
	case 1:
	cout<<"请输入编号"<<endl; 
	cin>>number1;
	cout<<"请输入ISBN"<<endl;
	cin>>ISBN1; 
	cout<<"请输入名字"<<endl;
	cin>>name1;
	cout<<"请输入出版社"<<endl;
	cin>>press1;
	cout<<"请输入作者"<<endl;	
	cin>>author1;
	addbook(number1,ISBN1,name1,press1,author1);
	break;
	case 2:
	cout<<"请输入编号"<<endl;
	cin>>number2; 
	u=search1(number2);
	if(u==NULL)
	{
		cout<<"该书不存在"<<endl;
		break; 
	}
	u->clear();
	cout<<"删除成功"<<endl; 
	break;
	case 3:
	cout<<"请输入图书编号"<<endl;
	cin>>number2;
	u=search1(number2);
	if(u==NULL)
	{
		cout<<"该书不存在"<<endl;
		break; 
	}
	else
	{
	int a=0;
	cout<<"1.修改ISBN"<<endl; 
	cout<<"2.修改名字"<<endl;
	cout<<"3.修改出版社"<<endl;
	cout<<"4.修改作者"<<endl;
	cout<<"5.返回"<<endl;
	cout<<"请选择:"<<endl; 
	cin>>a;
	switch(a)
	{
	case 1:
	cout<<"请输入新的ISBN"<<endl;
	cin>>ISBN1;
	u->changeISBN(name1);
	cout<<"修改成功"<<endl;
	break;		
	case 2:
	cout<<"请输入新的名字"<<endl;
	cin>>name1;
	u->changename(name1);
	cout<<"修改成功"<<endl;
	break;	
	case 3:
	cout<<"请输入新的出版社"<<endl;
	cin>>press1;
	u->changepress(press1);
	cout<<"修改成功"<<endl;
	break;
	case 4:
	cout<<"请输入新的作者"<<endl;
	cin>>author1;
	u->changeauthor(author1);
	cout<<"修改成功"<<endl;
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
	cout<<"1.按编号查找"<<endl; 
	cout<<"2.按ISBN查找"<<endl;
	cout<<"3.按名字查找"<<endl;
	cout<<"请选择:"<<endl;	
	cin>>a;
	switch(a)
	{
	case 1:
	cout<<"请输入编号"<<endl;
	cin>>number1;
	u=search1(number1);	
	if(u==NULL)
	{
		cout<<"不存在"<<endl; 
	}
	else
	{
		u->showbook();
	}
	break;
	case 2:
	cout<<"请输入ISBN"<<endl;
	cin>>ISBN1;
	u=search2(ISBN1);
	if(u==NULL)
	{
		cout<<"不存在"<<endl; 
	}
	else
	{
		u->showbook();
	}
	break;
	case 3:	
	cout<<"请输入名字"<<endl;
	cin>>name1;
	u=search3(name1);
	if(u==NULL)
	{
		cout<<"不存在"<<endl; 
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

class Ebook:public changebook//电子书 ,其余功能与 Book类图书功能类似 
{
public:
	void perform2()
	{
	int a=0;
	do{	
	cout<<"1.在线阅读"<<endl;
	cout<<"2.下载"<<endl;
	cout<<"3.返回"<<endl; 
	cout<<"请选择:"<<endl;; 
	cin>>a;
	switch(a)
	{
	case 1://在线阅读 
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
	case 2://下载 
	{
	char ch;
	ifstream file("F:/1.txt");
	char location[30];
	/*cout<<"请输入下载的地址"<<endl;
	cin>>location; */
	ofstream file1("F:/2.txt",ios::app);//创建文本文件
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
	void borrowbook(int numb1)//借书 
	{
		numb+=numb1;
	}
	void returnbook(int numb2)//还书 
	{
		numb-=numb2;
	}
	void adduser(int ro,char na[],char un[],char pa[])//添加用户 
	{
		d=1;
		numb=0;
		role=ro;
		strcpy(name,na);
		strcpy(username,un);
		strcpy(passport,pa);
	}
	void deleteuser(char na[])//删除用户 
	{
		d=0;
	}
	char *getname()//获取名字 
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
		cout<<"姓名"<<" "<<"用户名"<<" "<<"借书数量"<<endl;
		cout<<name<<" "<<username<<" "<<numb<<endl;
	}
	//~user();
private:	
	char name[30];//姓名 
	char username[30];// 用户名 
	char passport[30];//密码 
	int role;//0表示普通用户，1表示管理员
	int numb; //借书数量 
	int d;//d=0表示已删除
};

class account:public user
{
public:	
account();//构造函数 
void addUser()//添加用户 
{
	user user1;
	int role1;
	char name1[30];
	char username1[30];
	char passport1[30];
	cout<<"管理员请按1，普通用户请按0"<<endl;
	cin>>role1; 
	cout<<"请输入名字"<<endl;
	cin>>name1; 
	cout<<"请输入用户名"<<endl;
	cin>>username1;
	cout<<"请输入密码"<<endl;	
	cin>>passport1;
	user1.adduser(role1,name1,username1,passport1);
	users[h]=user1; 
	h++;
}
user *check(char name2[])//按姓名查找用户 
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
user *check2(char username2[])//按用户名查找用户 
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
void perform();//用户选择主页面 
void updateUser();//更新用户信息 
void deleteUser();//删除用户 
void lookupUser();
~account()//析构函数 
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
account::account()// 构造函数 
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
void account::updateUser()//更新用户信息 
{
	char name1[30],username1[30],passport1[30];
	user *r;
	cout<<"请输入用户姓名"<<endl;
	cin>>name1;
	r=check(name1);
	if(r==NULL)
	{
	cout<<"不存在"<<endl; 
	return;
	} 
	else 
	{
		int p;
		cout<<"1.更新用户名"<<endl;
		cout<<"2.更新密码"<<endl;
		cout<<"请选择:"<<endl;
		cin>>p;
		switch(p) 
		{
			case 1:
			cout<<"请输入新的用户名"<<endl;
			cin>>username1;
			r->setusername(username1);
			break; 
			case 2:
			cout<<"请输入新的密码"<<endl;
			cin>>passport1;
			r->setpassport(passport1);
			break;
			default:
			break;	
		}
	}	
}
void account::lookupUser()//查找用户 
{
	char name2[30];
	cout<<"请输入姓名"<<endl;
	cin>>name2;
	user *r;
	r=check(name2);
	if(r==NULL)
	{
		cout<<"不存在"<<endl; 
	} 
	else
	{
		r->showuser();
	} 
}
void account::deleteUser()//删除用户 
{
	char name3[30];
	user *r;
	cout<<"请输入要删除的用户姓名"<<endl;
	cin>>name3;
	r=check(name3); 
	if(r==NULL)
	{
		cout<<"该用户不存在"<<endl;
		return; 
	}
	else 
	{
		r->deleteuser(name3);
		cout<<"删除成功"<<endl; 
	}		
}  
void account::perform()//用户选择主页面 
{
	int l;
	do
	{
		cout<<"1.添加用户"<<endl;
		cout<<"2.更新用户"<<endl;
		cout<<"3.删除用户"<<endl;
		cout<<"4.查找用户"<<endl; 
		cout<<"5.返回"<<endl;
		cout<<"请选择:"<<endl;
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
	cout<<"欢迎登录图书管理系统~"<<endl; 
	cout<<"管理员请按1"<<endl;
	cout<<"普通用户请按2"<<endl;
	int f;
	cin>>f;
	switch(f)
	{
	case 1:	
	cout<<"请输入管理员密码"<<endl;
	cin>>pass;
	if(strcmp(pass,"2017")==0)
	{
		cout<<"登陆成功"<<endl; 
	}
	else
	{
		cout<<"登录失败"<<endl;
		return 0;
	}
	break;
	case 2: 
	cout<<"请输入学号和密码"<<endl; 
	cin>>identifier;
	cin>>pass;
	break;
	default:
	break;	
	}
	do
	{
	cout<<"1.图书"<<endl;
	cout<<"2.电子书"<<endl;
	cout<<"3.借书与还书"<<endl;
	cout<<"4.用户"<<endl; 
	cout<<"退出请按0"<<endl; 
	cout<<"请选择:"<<endl; 
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
	cout<<"请输入姓名"<<endl;
	cin>>name4;
	e=account1.check(name4);
	if((e==NULL)||(e->getd()==0))
	{
		cout<<"该用户不存在"<<endl;
		break; 
	}
	else
	{
		cout<<"1.借书"<<endl;
		cout<<"2.还书"<<endl;
		int q;
		cin>>q;
		int x;
		switch(q)
		{
		case 1:
		cout<<"请输入借书本书"<<endl;
		cin>>x;
		for(int g=0;g<x;g++)
		{
		char name6[30];
		cout<<"请输入书籍名字"<<endl;
		cin>>name6;
		o=change1.search3(name6);
		if(o==NULL)
		{
			cout<<"该书不存在"<<endl;
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
		cout<<"请输入还书本书"<<endl;
		cin>>x;
		for(int g=0;g<x;g++)
		{ 
		char name7[30];
		cout<<"请输入书籍名字"<<endl;
		cin>>name7;
		o=change1.search3(name7);
		if(o==NULL)
		{
			cout<<"该书不存在"<<endl;
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
