#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
void initial();
//**************************************************************************
//                    FUNCTION TO PRINT WELCOME
//**************************************************************************

void welcome()
{
int gd;
int gm,c;
gd=DETECT;
initgraph(&gd,& gm,"c://turboc3//bgi");
initial();
closegraph();
getch();
}

void initial()
{
for(int i=2;i<6;i++)
 {
sound(90*i);
cleardevice();
settextstyle(5,0,i-1);
setcolor(2);
outtextxy(150-20*i,100,"Student database Management System");
delay(350);
 }

for(i=6;i>2;i--)
 {
sound(50*i);
cleardevice();
settextstyle(5,0,i-1);
setcolor(5);
outtextxy(150-20*i,100,"Student database Management System");
delay(350);
nosound();
 }
for(int j=0;j<6;j++)
 {
sound(80*j);
cleardevice();
settextstyle(1,0,j);
setcolor(j);
outtextxy(300-10*j,250,"Efforts by");
delay(350);
 }
for(j=6;j>0;j--)
 {
sound(80*j);
cleardevice();
settextstyle(1,0,j);
setcolor(j);
outtextxy(300-10*j,250,"Efforts by");
delay(450);
nosound();
 }
for(int k=0;k<5;k++)
 {
sound(20*k);
cleardevice();
settextstyle(7,0,k);
setcolor(k+2);
outtextxy(250-5*k,380,"NAVDEEP,MONIKA,NAVJODH,NAGESH");
delay(500);
nosound();
 }
for(int l=6;l<12;l++)
 {
sound(50*l);
cleardevice();
settextstyle(5,0,2);
setcolor(l);
outtextxy(200,100,"Student database Management System");
settextstyle(1,0,2);
setcolor(l+1);
outtextxy(300,250,"Efforts by");
settextstyle(7,0,2);
setcolor(l+2);
outtextxy(200,380,"NAVDEEP,MONIKA,NAVJODH,NAGESH");
delay(500);
nosound();
 }
cleardevice();
settextstyle(7,0,2);
setcolor(RED);
outtextxy(140,200,"Enter any key to enter the program");
getch();
}

void pattern(char a);
class student
{
public:
		char n[50],fn[50],m[50],c[10],cr[10],ur[10],course[10],address[60];
		long int rn;
		void get()
		{
			cout<<"\n\n\n\n\t\t\t";
			cout<<"Enter Registration no. :";
			cin>>rn;
			cout<<"\t\t\tEnter Name :";
			gets(n);
			cout<<"\t\t\tEnter F.Name :";
			gets(fn);
			cout<<"\t\t\tEnter Class :";
			cin>>c;
			cout<<"\t\t\tEnter Class Roll no. :";
			cin>>cr;
			cout<<"\t\t\tEnter University Roll no. :";
			cin>>ur;
			cout<<"\t\t\tEnter Address :";
			gets(address);
			cout<<"\t\t\tEnter Phone no. :";
			cin>>m;
			cout<<"\t\t\tEnter Course :";
			gets(course);
		}
		void dis()
		{
			cout<<"\n\n\tRegistration no.:"<<rn<<endl;
			cout<<"\tName:"<<n<<endl;
			cout<<"\tF.Name:"<<fn<<endl;
			cout<<"\tClass:"<<c<<endl;
			cout<<"\tClass Roll no.:"<<cr<<endl;
			cout<<"\tUniversity Roll no.:"<<ur<<endl;
			cout<<"\tAddress:"<<address<<endl;
			cout<<"\tPhone no.:"<<m<<endl;
			cout<<"\tCourse:"<<course<<endl<<endl;
		}
};
void main()
{
clrscr();
welcome();
	while(1)
	 {
	clrscr();
	pattern('=');
	cout<<"\n\t\t\tSTUDENT DATABASE MANAGEMENT SYSTEM"<<endl;
	pattern('=');
	cout<<"\n\n\t\t\t1.Add Entry"<<endl;
	cout<<"\t\t\t2.Display Entry(s)"<<endl;
	cout<<"\t\t\t3.Delete Entry"<<endl;
	cout<<"\t\t\t4.Modify Entry"<<endl;
	cout<<"\t\t\t5.Exit"<<endl;
	cout<<"\n\n\n\t\t\tEnter your choice :";
	student s;
	int ch;
	cin>>ch;
	if(ch==1)
	{
		clrscr();
		 fstream s1("sdmss.dat",ios::in|ios::out|ios::binary|ios::app);
		s.get();
		fstream s8("sdmss.dat",ios::in|ios::out|ios::binary|ios::app);
		s1.write((char*)&s,sizeof(s));
		s1.close();
	}
	if(ch==2)
	{               clrscr();
			ifstream s2("sdmss.dat",ios::binary);
			s2.seekg(0,ios::beg);
			s2.read((char*)&s,sizeof(s));
			while(1)
			{
				if(s2.eof())
				break;
				s.dis();
				s2.read((char*)&s,sizeof(s));
			}
			s2.close();
			getch();
	}
	if(ch==4)
	{
		clrscr();
		fstream f6;
		f6.open("sdmss.dat",ios::in|ios::out|ios::binary);
		pattern('*');
		cout<<"\n\t\t\t\tMODIFY RECORD"<<endl;
		pattern('*');
		int no;
		cout<<"\n\n\nEnter record no. you want to update :";
		cin>>no;
		int pos;
		pos=((no-1)*sizeof(s));
		f6.seekp(pos,ios::beg);
		s.get();
		f6.write((char*)&s,sizeof(s));
		f6.close();
	}
	if(ch==3)
	{
	clrscr();
	int regno;
	student s;
	pattern('=');
	cout<<"\n\t\t\tDELETE ENTRY"<<endl;
	pattern('=');
	cout<<"\n\n\n\t\t\tEnter reg no. of student u want to delete :";
	cin>>regno;
	fstream f1("sdmss.dat",ios::in|ios::binary|ios::app);
	fstream f2("sdmsss.dat",ios::out|ios::binary|ios::app);
	f1.seekg(0,ios::beg);
	f1.read((char*)&s,sizeof(s));
	while(1)
	{
		if(regno!=s.rn)
		{
			f2.write((char*)&s,sizeof(s));
		}
		f1.read((char*)&s,sizeof(s));
		if(f1.eof())
		break;

	}
	f1.close();
	f2.close();
	remove("sdmss.dat");
	rename("sdmsss.dat","sdmss.dat");

	}
	if(ch==5)
	{

	break;
	}
	}

getch();
}
void pattern(char a)
{
	for(int i=0;i<80;i++)
	{
		cout<<a;
	}
}

