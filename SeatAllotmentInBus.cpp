#include<fstream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include <ctype.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
void WaitKey();
void gotoXY(int x, int y); 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
static int a;        //class specifications
class staff_login;
class student_login;
class register_now
{
	string name[10];
	public:
		int notice();
		int instructionsform();
		int registration_form();
		int confirmform();
		int routes();
		friend student_login;
		friend staff_login;
};
class student_login 
{
	public:
		int login();
		int allotmentform();
		int contactdetails();
		int complaints();
		friend register_now;
};
class staff_login 
{
	public:
		int login();
		int allotmentform();
		int complaintbox();
		int notice();
		int allot_staffr();
};
int staff_login::login()
{
	register_now r1;staff_login s1;student_login s2;
	int u;string a[100],user1,user2,user3;char line[80];
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n                    USERNAME:";
	cin>>user1;
	int i=0;char pwd[5];
	cout<<"                    PASSWORD:";
	while(i<4)	
	{pwd[i]=getch();
	putchar('*');++i;}
	int j=0;user2=pwd;
	user3=user1+user2;
	ifstream fil5;
	fil5.open("login.txt",ios::out);
	while(fil5)
	{
		fil5.getline(line,80);
		a[j]=line;
		j++;
	}
	for(int k=0;k<50;k++)
	{
		if(a[k]==user3)
		{
		while(1)
		{
			system("cls");
			cout<<"\n\n WELCOME TO "<<user1;
			cout<<"\n\n\n\n\n\n                     1.Allotment Details"<<"\n                     2.Complaint Box"<<"\n                     3.Edit notice";
			cout<<"\n                     4.Routes with alloted staff"; 
			cout<<"\n                     5.To LOGOUT";
			cout<<"\n\n\n Select your option : ";
			cin>>u;
			switch(u)
			{
				case 1:system("COLOR 5F");
				            s1.allotmentform();break;
				case 2:system("COLOR 5F");
				           s1.complaintbox(); break;
				case 3:system("COLOR 5F");
				           s1.notice();break;
				case 4:system("COLOR 5F");
				            s1.allot_staffr();break;
				case 5:system("COLOR 5F");
				system("cls");
						cout<<"\n\n\n\n\n\n\n           LOADING PLEASE WAIT ... ";
						Sleep(500);return 0;
				default:return 0;
			}}}}
	system("cls");
		cout<<"\n\n\n      SORRY,"
			<<"\n      invalid username or password";
		Sleep(700);
	return 1;}
int staff_login::notice()
{
	system("cls");
	fstream fin;
	fin.open("program.txt",ios::out | ios::app );
	fin<<endl;
	string mystr;
   	getline (cin, mystr);
  	cout << "Enter the Notice :";
  	getline (cin, mystr);
  	fin<<mystr;
  	cout<<"\n\n\n\nEnter any key to return main menu";
  	getch();
  	return 1;
}
int staff_login::allotmentform()
{
	system("cls");
	string j,tem[10];
	int i,d;
	cout<<"Enter your Username :";
	cin>>j;
	ifstream f9;
	f9.open("list_of_students.txt",ios::in);
	f9.seekg(0,ios::beg);
	while(!f9.eof())
    {
        i++;
        string temp;
        f9 >> temp;
        if(temp == j)
        {
            d=f9.tellg();
            break;
        }}
	int y=d+6;
	int l=0;
	while(d!=y)
	{
		d++;
		string temp;
		f9>>temp;
		tem[l]=temp;
		l++;
	}
	system("cls");
	cout.setf(ios::left,ios::adjustfield);
	cout<<"\n NAME :"<<tem[0];
	cout<<"\n FATHER NAME :"<<tem[1];
	cout<<"\n PH_NO:"<<tem[2];
	cout<<"\n ADDRESS:"<<tem[3];
	cout<<"\n Alloted seat Number:"<<tem[4];
	cout<<"\n Total amount DUE : Rs "<<tem[5]<<"|-"<<endl<<endl<<"Student/Staff Sign";
   	cout<<"\n Enter any key to retun back to menu ";
	getch();
	return 1;
}
int staff_login::complaintbox()
{
	char ch;
	system("cls");
	ifstream fin6;
	fin6.open("complaintbox.cpp",ios::in);
	while(fin6)
	{
		fin6.get(ch);
		cout<<ch;
	} 
	cout<<"\n\n\n\n\n\n   Enter the any key to return to main menu";
	getch();
	return 1;
}
int staff_login::allot_staffr()
{
	system("cls");
	char ch;
	ifstream fin6;
	fin6.open("allotedstaff.cpp",ios::in);
	while(fin6)
	{
		fin6.get(ch);
		cout<<ch;
	} 
	cout<<"\n\n\n\n\n\n 1.BIT-Erode->Mr.G.Nitheesh\n 2.BIT-Bannari->Mr.C.Muralidharan\n 3.BIT-Sathyamangalam-Mr.S.Hari Prasanth\n 4.BIT-TiruppurMr.N.Naveen Kumar\n 5.BIT-Athani-Mr.M.Prem Kumar\n Enter the any key to return to main menu";
	getch();
	return 1;
}
int student_login::login()
{
	register_now r1;
	staff_login s1;
	student_login s2;
	int u;
	string a[100],user1,user2,user3;
	char line[80];
	system("cls");
	cout<<"\n USERNAME:";
	cin>>user1;
	int i=0;char ch;
	char pwd[5];
	cout<<"                    PASSWORD:";
	while(i<4)	
	{
		pwd[i]=getch();
		putchar('*');
		++i;
	}
	int j=0;
	user2=pwd;
	user3=user1+user2;
	ifstream fil5;
	fil5.open("login.txt",ios::out);
	while(fil5)
	{
		fil5.getline(line,80);
		a[j]=line;
		j++;
	}
		for(int k=0;k<50;k++)
		{
		if(a[k]==user3)
		{
		while(1)
		{
			system("cls");
			cout<<"\n\n WELCOME TO "<<user1;
			cout<<"\n 1.Allotment form\n2.Complaint\n3.Staff contact details\n 4.To LOGOUT";
			cout<<"\n\n\n\n\n\n Select your option :";
			cin>>u;
			switch(u)
				{
				case 1:s2.allotmentform();break;
				case 2:s2.complaints();break;
				case 3:s2.contactdetails();break;
				case 4:system("cls");
						cout<<"\n\n\n\n\n\n\n            PLEASE WAIT ... LOADING";
						Sleep(500);
						return 0;
				default:exit;
				}}}}
		system("cls");
		cout<<"\n\n\n      SORRY,"
			<<"\n      Invalid username and password";
		Sleep(700);
	return 1;
}
int student_login::allotmentform()
{
	system("cls");
	string j,tem[10];
	int i,d;
	cout<<"Enter your Username :";
	cin>>j;
	ifstream f8;
	f8.open("list_of_students.txt",ios::in);
	f8.seekg(0,ios::beg);
	while(!f8.eof())
    {i++;
        string temp;
        f8 >> temp;
        if(temp == j)
        {
            d=f8.tellg();
            break;
        }}
	int y=d+6;int l=0;
	while(d!=y)
	{
		d++;
		string temp;
		f8>>temp;
		tem[l]=temp;
		l++;
	}
	system("cls");
	cout.setf(ios::left,ios::adjustfield);
	cout<<"\n NAME :"<<tem[0];
	cout<<"\n FATHER NAME :"<<tem[1];
	cout<<"\n PH_NO:"<<tem[2];
	cout<<"\n ADDRESS:"<<tem[3];
	cout<<"\n Alloted seat Number:"<<tem[4];
	cout<<"\n Total amount DUE : Rs "<<tem[5]<<"|-"<<endl<<endl<<"Student/Staff Sign";
   	cout<<"\n Enter any key to retun back to menu ";
	getch();return 1;
}
int student_login::complaints()
{	char ch;
	system("cls");
	ofstream fin9;
	fin9.open("complaintbox.cpp",ios::app);
	fin9<<endl;
	string mystr;
   	getline (cin, mystr);
  	cout << "Enter the Complaint :";
  	getline (cin, mystr);
  	fin9<<mystr;
  	cout<<"\n\n\n Enter any key to retun back to menu";
	getch();return 1;
}
int student_login::contactdetails()
{
	system("cls");
	cout<<"\n\n\n Dr.Sasikala,\n Dept Of Computer Science,\n Bannari Amman Institute Of Technology,"<<"\n Sathyamangalam,\n Erode-638401."<<"\n Phone Number:1234567890";
	cout<<"\n For Further Details contact Management.";
	cout<<"\n\n\n\n Enter any key to retun back to menu ";
	getch();
	return 1;
}
int register_now::instructionsform() 
{
	system("cls");
	cout<<"\n          ";
	char b[]="Read the following Instructions :\n";
	
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];
	}
	char ch;char a;ifstream ins1;
	ins1.open("instructions.txt",ios::in);
		while(ins1) 
		{
			ins1.get(ch);
			cout<<ch;
		}
	cout<<"\n-> Arrive at the stop five minutes earlier than scheduled loading time.\n-> Remain out of the street and respect the property and owner of the property where the stop is located."
	    <<"\n-> When the bus approaches,stay away from the curb and the front wheels of the bus.\n-> Get in line when the bus approaches and wait until the bus has come to a complete stop and the driver signals before crossing and boarding."
	    <<"\n-> Board carefully and use the handrail.\n-> Be courteous and do not push or shove while moving to your assigned seat.\n To accept the above instructions press Y : ";
	cin>>a;
		if(a == 'y' || a == 'Y')
		{
			registration_form();
		}
	 	else 
		{
			system("cls");
			cout<<"\n\n\n\n\n   SORRY,YOU ENTERED A WRONG CHOICE.....";
			Sleep(1000);
			system("cls");
		}
}
int register_now::registration_form()
{
	string password;
	char pwd[5];
	int i=0;
	system("cls");
	a++;
	fstream fil5;
	fil5.open("login.txt",ios::out|ios::app);
	cout<<"              \n";
	char b[]="REGISTRATION FORM\n";
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];
	}
	cout<<endl<<endl<<"NAME :";
	cin>>name[0];
	cout<<endl<<"FATHER NAME :";
	cin>>name[1];
	cout<<endl<<"Ph_no:";
	cin>>name[2];
	cout<<endl<<"ADDRESS:";
	cin>>name[3];
	cout<<endl<<"Select seat Number:"<<endl;
	int count=1;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(j==3)
			{
			cout<<"   ";
			}cout<<setw(4)<<count<<"  ";
			count++;
		}
		cout<<endl;
	}
	cout<<" ";
	for(int i=51;i<=60;i++)
	{
		cout<<setw(3)<<i;
	}
	string user4;
	cout<<"\n Enter the required seat number : ";
	cin>>name[4];
	cout<<"\nStaff or Student : ";
	cin>>user4;
	if(user4=="student"||"STUDENT")
	{
	cout<<endl<<endl<<"Your username :";
	cout<<"BIT"<<a;
	cout<<endl<<"PASSWORD :";
	while(i<4)	
	{
		pwd[i]=getch();
		putchar('*');
		++i;
	}
	password=pwd;
	fil5<<"BIT"<<a;
	fil5<<password<<"\n";
	name[5]="17000";
	fil5.close();
	fstream fil2;
	fil2.open("list_of_students.txt",ios::in | ios::out | ios::app);
	fil2.seekg(74);
	fil2<<"BIT"<<a<<"          ";
	//fil2.setf(ios::left,ios::adjustfield);
	for(int i=0;i<6;i++)
	{
	fil2.setf(ios::left,ios::adjustfield);
	fil2<<setw(20)<<name[i];
	count++;
	}
	fil2<<endl;
	Sleep(500);
}
	else
	{
		if(user4=="staff"||"STAFF")
		{
				cout<<endl<<endl<<"Your username :";
	cout<<"STAFF"<<a;
	cout<<endl<<"PASSWORD :";
	while(i<4)	
	{
		pwd[i]=getch();
		putchar('*');
		++i;
	}
	password=pwd;
	fil5<<"STAFF"<<a;
	fil5<<password<<"\n";
	name[5]="17000";
	fil5.close();
	fstream fil3;
	fil3.open("list_of_staff.txt",ios::in | ios::out | ios::app);
	fil3.seekg(74);
	fil3<<"STAFF"<<a<<"          ";
	//fil3.setf(ios::left,ios::adjustfield);
	for(int i=0;i<6;i++)
	{
	fil3.setf(ios::left,ios::adjustfield);
	fil3<<setw(20)<<name[i];
	count++;
	}
	fil3<<endl;
	Sleep(500);
	}
}
	confirmform();
}
int register_now::confirmform()
{
	char ch;
	system("cls");
	char sentzz[]="          ***************CONFIRM FORM*****************";
	int x;int size; size=strlen(sentzz);
    for(x=0;x<size;x++)
    {   
        Sleep(50); 
        cout<<sentzz[x];
    }
    cout.setf(ios::left,ios::adjustfield);
	cout<<endl<<"     NAME :"<<name[0];
	cout<<endl<<"FATHER NAME :"<<name[1];
	cout<<endl<<"     Ph_no:"<<name[2];
	cout<<endl<<"ADDRESS:"<<name[3];
	cout<<endl<<"     Alloted seat Number:"<<name[4];
	//cout<<endl<<endl<<"     Your username :"<<"BIT"<<a;
	cout<<endl<<endl<<endl<<"            Total amount to be paid : Rs 17,000|- on or before 25th October"<<endl
	<<endl<<endl<<"                                                              Student/Staff Sign";
   /*fil2.seekg(0,ios::end);
    int b=fil2.tellg();
    fil2.seekg(-100,ios::end);
    while(fil2)
    {
    	int a=fil2.tellg(); 
    	cout<<"NAME:";
		if(a!=b)
    	{
			fil2.get(ch);
    		cout<<ch;
    	}*/
    	int a;
    	Sleep(400);
    	  cout<<endl<<endl<<"    Enter any key to return back to main menu";
    	getch();
    	return 1;
	}
int register_now::routes()
{
	char ch;
	system("cls");
	fstream fil4;
	fil4.open("ROUTES.cpp",ios::in);
	while(fil4) 
		{
			fil4.get(ch);
			cout<<ch;
		}
}
int register_now::notice()
{
	system("cls");char ch;ifstream f2;
	f2.open("program.txt",ios::in );
		while(f2) 
		{f2.get(ch);
	                cout<<ch;}
	cout<<"\n\n\n Enter any to return back to menu";
	getch();
	return 1;
}
int main() 
{
	char ch;system("COLOR 2C");
	while(1)
	{
		system("cls");
		cout<<endl<<endl;
		fstream f2;
		f2.open("sysmbol.txt",ios::in);
		while(f2) 
		{
			f2.get(ch);
			cout<<ch;
		}
	Sleep(1000);
	system("COLOR 8F");
		char a[]="$$$$$$$$$$$ BIT BUS SERVICE WELCOMES YOU $$$$$$$$$$$";
		int size;size=strlen(a);
		for(int i=0;i<size;i++)
		{Sleep(25);
		cout<<a[i];int c=1;
		cout<<endl<<endl;
		Sleep(0);
		cout<<"\n1.REGISTER NOW \n2.STAFF LOGIN \n3.STUDENT LOGIN \n4.NOTICES”;
                             cout<<”\n5.EXIT";
	for(int i=0;i<1;i++)
    {
    	int x = 16;
    	int y = 10;
    	for (y=10;y<19;y++)  
   		{
    	  gotoXY(x,y);
    	  cout << "*";
    	  Sleep(100); // gotoXY(x,y);  // cout << "                                                     "; 
  		}
  		y=19;
  		for (x=16;x<63;x++)  
   		{
    	  gotoXY(x,y);
    	  cout << "*"; Sleep(20);// gotoXY(x,y);  // cout << "                                                     "; 
  		}
  		for (y=10;y<20;y++)  
   		{
    	  gotoXY(x,y);
    	  cout << "*";
    	  Sleep(100);
    	 // gotoXY(x,y); 
		 // cout << "                                                     "; 
  		}}
	for(int i=0;i<1;i++)
    {
    	int x = 1,y = 20;
    	for (x=40;x>1;x--)  
   		{ gotoXY(x,y);
    	  cout << "Thank you to our Friends and Staff who helped in this Mini Project";
    	  Sleep(100);
    	  gotoXY(x,y); 
		  cout << "                                                         "; 
                            }
  		cout <<endl<<"       Thank you to our Friends and Staff who helped in this Mini Project"<<endl;
	}
   register_now r1;
   staff_login s1;
   student_login s2;
   int ch;	
	cout<<"\n Select your option :";
	cin>>ch;fstream f1;
	switch(ch)
	{
		case 1:system("COLOR 1F");
		           r1.instructionsform();break;
		case 2:system("COLOR 1F");
		           s1.login();break;
		case 3:system("COLOR 1F");
		           s2.login();break;
		case 4:system("COLOR 1F");
		           r1.notice();break;
		case 5:exit(0);break;
		default:cout<<"ssssss";break;
	}}
	getch();return 0;	
}
void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}
