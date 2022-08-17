#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class setup
{
	private:
		string name,password,user,pass,u,p;
		int choice;	
	public:
		void menu();
		void login();
		void signup();
};
void setup::menu()
{
	cout<<"\t\t-------------------------------     System     -------------------------------\n\n";
	cout<<"\t\t1-> Login \n"<<"\t\t2-> Signup\n"<<"\t\t3-> Exit\n";
	cout<<"\n\t\tSelect an option: ";
	system("Color 0A");//Color
	cin>>choice;
	system("cls");
	switch(choice)
	{
		case 1:
			login();
			break;
		case 2:
			signup();
			break;
		case 3:
			break;	
		default:
			cout<<"\n\t\tInvalid Input!\n";
			system("pause");
			system("cls");
			menu();	
			break;	
	}
}
void setup::signup()
{
	cout<<"\t\t-------------------------------     Signup System     -------------------------------\n\n";
	cout<<"\t\tEnter your Name: ";
	cin.ignore();
	getline(cin,name);
	cout<<"\n\t\tEnter your Password: ";
	getline(cin,password);
	fstream enter;
	enter.open("system.txt",ios::app|ios::out);
	enter<<name<<' '<<password<<endl;
	enter.close();
}
void setup::login()
{
	int count;
	fstream data;
	cout<<"\t\t-------------------------------     Login System     -------------------------------\n\n";
	cout<<"\t\tEnter your Name: ";
	cin.ignore();
	getline(cin,user);
	cout<<"\n\t\tEnter your Password: ";
	getline(cin,pass);
	data.open("system.txt",ios::in);
    while(data>>u>>p)
    {
        if(u==user && p==pass)
        {
            count=1;
            system("cls");
        }
    }
    data.close();
    if(count==1)
    {
    	cout<<"\n\n\t\t<LOGIN SUCCESSFUL>\n\n";
    	system("pause");
    	system("cls");
    	menu();
    }
    else
    {
        cout<<"\n\t\tWorng Data Enter!\n\t\tTry Again!\n";
        system("pause");
        system("cls");
        login();
    }
}
int main()
{
	setup l1;
	l1.menu();
}
