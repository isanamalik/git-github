 #include<iostream>
#include<ctime>
#include<string.h>
#include<math.h>
#include<conio.h>
#include <fstream>
#include <sstream>
#include<stdlib.h>
using namespace std;
class LOGIN
{
protected:
	string username;
private:
	string password;
	string user,pass;
	int count;
public:
	void reg()
	{
		cout << "\nEnter username: ";
		cin >> username;
		cout << "\nEnter password: ";
		cin >> password;
		check(username,password);
		
		
	}
	void check(string u, string p)
	{
		cout << "\nRe-enter user name: "; cin >> user;
		cout << "\nRe-enter password: "; cin >> pass;		
		if (user == username && pass == password)
			{
				ofstream Register("login.txt", ios::app);
				Register << username << endl;
				Register << password<<endl;
				Register.close();
				system("cls");
				cout<<"\nRegistration is sucessful ";
			}
		else
			{
			cout<<"\nunmatched user name or password! ";
			exit(1);
		}
	}
	void login()
	{
		string name_L, pass_L;
		cout << "\nEnter username: ";cin >> name_L;
		cout << "\nEnter password: "; cin >> pass_L;
		ifstream read("login.txt");
		while (read >> username>>password )
		{
			if (name_L==username && pass_L==password)
			{
				count = 1;
				break;
			}
			else
				count=0;
			
		}
		read.close();
		if (count == 1)
		cout << "\nSucessfully logged in!!";
		else
		{
		cout << "\nlogin error!!";
		exit(1);}
	}
};

class expenses
{public:
int cat=0, no_of_cat=0,sum=0;
float amount[100];
int new_amount=0;
string cat_name[100];
int saving;
int income;


void getincome()
{cout<<"\nPlease enter total income or allowance: ";
cin>>income;
fstream file("income.txt",ios :: in | ios :: out |ios:: app); 

file<<endl<<income;
file.seekg(0);
string line;
}
void getcategory()
{
cout << "\nEnter the number of categories : "; 
cin>>no_of_cat;
cin.ignore();
cout<<"\nEnter the name of your categories\n";
fstream file("catagories.txt",ios :: in | ios :: out |ios:: app);


for (int i=0;i<no_of_cat;i++)
{
cout<<"category # "<<i+1<<": ";
getline(cin,cat_name[cat+i]);

file<<endl<<cat_name[cat+i];
file.seekg(0);
}
}
void getexpenses()
{  
  cout<<"\nThe categories stored before: \n";
for (int j=0;j<no_of_cat; j++)
{
cout<<"\ncategory "<< j+1 <<" : "<< cat_name[j];
}	  
cout<<endl;
cout<<"\nEnter the amount of money you spent on the following categories: \n";
fstream file("EXP.txt",ios :: in | ios :: out |ios:: app);
for(int k=0;k<no_of_cat;k++)
{
cout<<"Amount of money spent on "<<cat_name[k]<<": ";
cin>>amount[k];
file<<endl<<amount[k];
file.seekg(0);

}
}
int getincome2(void)
{
	string line2;
	int x=0;
  ifstream myfile ("income.txt");
  if (myfile.is_open())
  {
   
    while (! myfile.eof() )
    {
      
      getline (myfile,line2);
      stringstream geek(line2); 
      geek>>x;
     
    }
     
    myfile.close();
  }
	return x;
}
void showexpenses()
{

string line2;
  ifstream myfile ("catagories.txt");
  ifstream myfile2 ("EXP.txt");
  if (myfile.is_open() && myfile2.is_open())
  {
    sum=0;
    while (! myfile.eof() && ! myfile2.eof() )
    {
      cout<<"*"<<" CATEGORY ";
      getline (myfile,line2);
      cout<<line2<<"  =  ";
      getline (myfile2,line2);
      stringstream geek(line2); //converting string to int
      int x=0;
      geek>>x;
      sum=sum+x;
      cout<<x<<endl;
     
      
    }
     
    myfile.close();
    myfile2.close();
  }
	
	 income=getincome2();
saving = income - sum ;

}
};

class savings : public expenses
{  
public: 
void getincome()
{expenses::getincome();
}
void getsaving()
{expenses::getcategory();}

void takesaving(){
expenses::getexpenses();}

void showsaving(){
cout<<"\n*CURRENT BUDGET STATUS*\n-----------------------------------------";
income=getincome2();
cout<<"\n\nTOTAL INCOME  =  "<<income;
cout<<"\n\nTHE DETAILS OF EXPENSES:";
expenses::showexpenses();

cout<<"\n\nTOTAL EXPENSES  = "<<sum;
cout<<"\n\nCURRENT BALANCE = "<<saving; 
cout<<"\n\n-----------------------------------------\n\n"  ;
}
}; 

int main()
{
// current date/time based on current system
time_t now = time(0);
// convert now to string form
char* dt = ctime(&now);
cout << "The local date and time is: " << dt << endl;
cout<<"\n\t\tBUDGET TRACKER  \n";


	LOGIN login;
	int choice;
	char ch;
savings a;
char proceed;
int action;
	cout << "\n\n\t\t Welcome to login page \n\n";
		cout << "1.Register" << endl;
		cout << "2.Login" << endl;
		cout << "\nEnter your choice :";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			login.reg();
			break;
		case 2:
			login.login();
			break;
		default:
			system("cls");
			cout << "Error detected, try again!\n" << endl;
			main();
		}
	do
	{

	cout<<"\n\n\n1 : FOR ENTERING INCOME.\n2 : FOR ENTERING CATEGORIES and FOR"; 
	cout<<"ENTERING EXPENSES : \n3 : FOR VIEWING BUDGET STATUS: \n4. TO EXIT ";
	cout<<"\nWHAT WOULD YOU LIKE TO DO ? ";
	cin>>action;
	cout<<endl;
	switch(action)
	{
		case 1:
			a.getincome();
			break;
		case 2:
			a.getsaving();
		    a.takesaving();
			break;
		case 3:
			a.showsaving();
			break;
		case 4:
				exit(1);
				break;
			default:
				system("cls");
				cout<<"\nNOT A VALID INPUT\n";
				main();
	}
cout<<"\nDO YOU WANT TO CONTINUE : (PRESS y TO CONTINUE) : ";
cin>>proceed;
system("cls");
}while(proceed=='y'||proceed=='Y' );
 getch();
system("pause");
 return 0;
}
