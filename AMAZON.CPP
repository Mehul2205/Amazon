/*

This code is created by Mehul Patni & Akshat Jain in Turbo c++
Last Modified date - 12/08/2019

A C++ program which implements same functions as that are in amazon.in using Graphics, file handling and Data Structure.

*/

#include <string.h>			
#include <graphics.h>		
#include <stdlib.h>			
#include <stdio.h>			
#include <conio.h>			
#include <dos.h>			
#include <iostream.h>		
#include <fstream.h>		
#include <process.h>		

void top();				
void Signup();
void Manager();
void modify();
void addproduct();
void deleteproduct();
void showallproduct();


void defaults()				// This function is used to set text color and backgound color
{
	graphdefaults();
	setbkcolor(3);
	setcolor(15);
}


void loading()				// This function is used to make a loading delay pretending to be waiting for data 
{
	int stangle=0,endangle=0;
	defaults();
	
	for(int j=0;j<720;j++)
	{
		outtextxy(250,150,"LOADING....");
		arc(350, 150, stangle-j, endangle+j,10);
		arc(350, 150, stangle-j, endangle+j,10.5);
		arc(350,150, stangle-j, endangle+j,11);
		arc(350, 150, stangle-j, endangle+j,11.5);
		delay(5);
		cleardevice();
	}
}


void searching()		// This function is called when user searches something causing delay to the program
{
	int stangle=0,endangle=0;
	defaults();
	
	for(int j=0;j<720;j++)
	{
		outtextxy(220,150,"SEARCHING....");
		arc(350, 150, stangle-j, endangle+j,10);
		arc(350, 150, stangle-j, endangle+j,10.5);
		arc(350,150, stangle-j, endangle+j,11);
		arc(350, 150, stangle-j, endangle+j,11.5);
		delay(8);
		cleardevice();
	}
}


void ERROR()			// This is the error function which is called everytime when user gives a wrong input or password
{
	top();
	settextstyle(TRIPLEX_FONT , HORIZ_DIR, 4);
	setusercharsize(1.8,1.2,1.8,1.2);
	setcolor(4);
	moveto(200,130);
	outtext("!OOps...");
	moveto(100,180);
	outtext("*##* AN ERROR OCCURED*##*");
	defaults();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tPress ENTER to Exit";
	getch();
	exit(0);
}



class Amazon_Acc		// This class's object used to store all the data of the customer like its name, password etc.
{
		char password1[10],Google_Acc[40],name[20];
	
	public:
		void sign_up()
		{
			cout<<"\n\n\n\n\n\n\n\n\n\tEnter Your Name ";
			cin>>name;
			cout<<"\n\n\tEnter Your Google ID ";
			gets(Google_Acc);
			cout<<"\n\n\tEnter Password ";
			gets(password1);
		}
		
		void Show_Data()
		{
			cout<<"Account";
			puts(Google_Acc);
			cout<<"Password";
			puts(password1);
		}
		
		char* goacc()
		{
			return(Google_Acc);
		}
		
		char* passw()
		{
			return(password1);
		}
};



class mobiles			// This class is used to store, view, update any the details of mobile phones 
{
		int nofmobile;
		long price;
		char mobile_name[20];
	
	public:
		void entermobiles()
		{
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
			setusercharsize(1.8,1.5,1.8,1.5);
			outtextxy(200,120,"Mobiles..");
			defaults();
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\tEnter Name of Mobile ";
			gets(mobile_name);
			cout<<"\n\t\tEnter Price of the Product ";
			cin>>price;
			cout<<"\n\t\tEnter no. of Mobile in the stock ";
			cin>>nofmobile;
		}
		
		void show_data()
		{
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
			setusercharsize(1.8,1.5,1.8,1.5);
			outtextxy(200,145,"Mobiles..");
			cout<<"\n\n\n\n\n\n\t\tName of Mobile is:-";
			cout<<mobile_name;
			cout<<"\n\t\tPrice of the Product is:-"<<price;

			if(nofmobile==1)
			{
				cout<<"\n\t\tNo. of Mobile in the Stock is:-"<<nofmobile;
				cout<<"\n\t\tHurry up!!..... only ONE Left";
			}
		}
		
		void Show_Data()
		{
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
			setusercharsize(1.8,1.5,1.8,1.5);
			outtextxy(200,145,"Mobiles..");
			cout<<"\n\n\n\n\n\n\n\n\t\tName of Mobile is:-";
			cout<<mobile_name;
			cout<<"\n\t\tPrice of the Product is:-"<<price;
			cout<<"\n\t\tNo. of Mobile in the Stock is:-"<<nofmobile;
		}
		
		char* m()
		{
			return(mobile_name);
		}
		
		int mp(int a)
		{
			price=a;
			return(price);
		}

		int ms()
		{
			return(nofmobile);
		}
		
		int update()
		{
			nofmobile--;
			return(nofmobile);
		}

		int mm(int a)
		{
			nofmobile=a;
			return(nofmobile);
		}
};



class accessories			// This class is used to store, view, update any the details of mobile accessories 
{
		int nofacc;
		long price;
		char acc_name[20];
	
	public:
		void enteracc()
		{
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
			setusercharsize(1.8,1.5,1.8,1.5);
			outtextxy(200,120,"Accessories..");
			defaults();
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\tEnter the Name of the Accessories ";
			gets(acc_name);
			cout<<"\n\t\tEnter Price of the Product ";
			cin>>price;
			cout<<"\n\t\tEnter no. of Product in the stock ";
			cin>>nofacc;
		}
		
		void show_data()
		{
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
			setusercharsize(1.8,1.5,1.8,1.5);
			outtextxy(200,145,"Accessories..");
			cout<<"\n\n\n\n\n\n\t\tAccessories :-";
			cout<<acc_name;
			cout<<"\n\t\tPrice of the Product is:-"<<price;
			if(nofacc==1)
			{
				cout<<"\n\t\tNo. of Product in the Stock is:-"<<nofacc;
				cout<<"\n\t\tHurry up only ONE Left";
			}
		}
		
		void Show_Data()
		{
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
			setusercharsize(1.8,1.5,1.8,1.5);
			outtextxy(200,145,"Accessories..");
			cout<<"\n\n\n\n\n\n\n\n\t\tAccessories :-";
			cout<<acc_name;
			cout<<"\n\t\tPrice of the Product is:-"<<price;
			cout<<"\n\t\tNo. of Product in the Stock is:-"<<nofacc;
		}
		
		char* a()
		{
			return(acc_name);
		}
		
		int ap(int a)
		{
			price=a;
			return(price);
		}
		
		int as()
		{
			return(nofacc);
		}
		
		int update()
		{
			nofacc--;
			return(nofacc);
		}
		
		int am(int a)
		{
			nofacc=a;
			return(nofacc);
		}
};



class laptop			// This class is used to store, view, update any the details of Laptop
{
		int noflaptop;
		long price;
		char laptop_name[20];
	
	public:
		void enterlaptop()
		{
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
			setusercharsize(1.8,1.5,1.8,1.5);
			outtextxy(200,120,"Laptops..");
			defaults();
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\tEnter Name of Laptop ";
			gets(laptop_name);
			cout<<"\n\t\tEnter Price of the Product ";
			cin>>price;
			cout<<"\n\t\tEnter no. of laptop in the stock ";
			cin>>noflaptop;
		}

		void show_data()
		{
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
			setusercharsize(1.8,1.5,1.8,1.5);
			outtextxy(200,145,"Laptops..");
			cout<<"\n\n\n\n\t\tName of Laptop is:-";
			cout<<laptop_name;
			cout<<"\n\t\tPrice of the Product is:-"<<price;
			if(noflaptop==1)
			{
				cout<<"\n\t\tNo. of Laptop in the Stock is:-"<<noflaptop;
				cout<<"\n\t\tHurry up only ONE Left";
			}
		}

		void Show_Data()
		{
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
			setusercharsize(1.8,1.5,1.8,1.5);
			outtextxy(200,145,"Laptops..");
			cout<<"\n\n\n\n\t\tName of Laptop is:-";
			cout<<laptop_name;
			cout<<"\n\t\tPrice of the Product is:-"<<price;
			cout<<"\n\t\tNo. of Laptop in the Stock is:-"<<noflaptop;
		}

		char* l()
		{
			return(laptop_name);
		}

		int lp(int a)
		{
			price=a;
			return(price);
		}

		int ls()
		{
			return(noflaptop);
		}

		int update()
		{
			--noflaptop;
			return(noflaptop);
		}

		int lm(int a)
		{
			noflaptop=a;
			return(noflaptop);
		}
};



class tablet			// This class is used to store, view, update any the details of tablet
{
		int noftab;
		long price;
		char tab_name[20];
	
	public:	
		void entertab()
		{
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
			setusercharsize(1.8,1.5,1.8,1.5);
			outtextxy(200,120,"Tablets..");
			defaults();
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\tEnter Name of Tablet ";
			gets(tab_name);
			cout<<"\n\t\tEnter Price of the Product ";
			cin>>price;
			cout<<"\n\t\tEnter no. of Tab in the Stock ";
			cin>>noftab;
		}
		
		void show_data()
		{
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
			setusercharsize(1.8,1.5,1.8,1.5);
			outtextxy(200,145,"Tablets..");
			cout<<"\n\n\n\n\n\n\t\tName of Tab is:-";
			cout<<tab_name;
			cout<<"\n\t\tPrice of the Product is:-"<<price;
			if(noftab==1)
			{
				cout<<"\n\t\tNo. of Tab in the Stock is:-"<<noftab;
				cout<<"\n\t\tHurry up only ONE Left";
			}
		}
		
		void Show_Data()
		{
			settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
			setusercharsize(1.8,1.5,1.8,1.5);
			outtextxy(200,145,"Tablets..");
			cout<<"\n\n\n\n\n\n\n\n\t\tName of Tab is:-";
			cout<<tab_name;
			cout<<"\n\t\tPrice of the Product is:-"<<price;
			cout<<"\n\t\tNo. of Tab in the Stock is:-"<<noftab;
		}
		
		char* t()
		{
			return(tab_name);
		}
		
		int tp(int a)
		{
			price=a;
			return(price);
		}
		
		int ts()
		{
			return(noftab);
		}
		
		int update()
		{
			noftab--;
			return(noftab);
		}
		
		int tm(int a)
		{
			noftab=a;
			return(noftab);
		}
};


Amazon_Acc Account;
mobiles mob;
accessories acc;
laptop lap;
tablet tab;


void sc1()			// This function is used to write "AMAZON" on the screen
{
	cleardevice();
	setbkcolor(3);
	setcolor(1);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	setusercharsize(1.8,1.5,1.8,1.5);
	moveto(200,100);
	outtext(" amazon.in");
	setcolor(6);
	arc(261,95,230,310,50);
	arc(261,96,230,310,50);
	arc(261,97,230,310,50);
	arc(261,98,230,310,50);
	moveto(279,121);
	outtext("7");
	setcolor(15);
}


void cart()			// This function is used to make a moving cart on the first screen
{
	for(int i=0;i<=100;i=i+2)
	{
		defaults();
		sc1();
		settextstyle(SANS_SERIF_FONT , HORIZ_DIR, 2);
		outtextxy(200,360,"Created By:-");
		outtextxy(220,390,"1. Akshat Jain");
		outtextxy(220,410,"2. Mehul Patni");
		line(230+i,150,240+i,150);
		line(240+i,150,250+i,200);
		line(250+i,200,300+i,200);
		line(300+i,200,308+i,160);
		pieslice(260+i,210,0,360,5);
		pieslice(292+i,210,0,360,5);
		setlinestyle(1,1,3);
		line(242+i,160,308+i,160);
		line(245+i,175,305+i,175);
		line(248+i,190,302+i,190);
		delay(50);
	}
	loading();
}


void top()				// This function implement the top part of the home screen
{
	clrscr(); cleardevice();
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	setusercharsize(1.5,1,1.5,1);
	moveto(80,3);
	setcolor(1);
	outtext("         amazon.in");
	setcolor(6);
	arc(270,-2,230,310,50);
	arc(270,-1,230,310,50);
	arc(270,0,230,310,50);
	arc(270,1,230,310,50);
	moveto(288,24);
	outtext("7");
	defaults();
	line(585,20,590,20);
	line(590,20,595,40);
	line(595,40,610,40);
	line(610,40,614,24);
	pieslice(598,45,0,360,2);
	pieslice(607,45,0,360,2);
	moveto(600,30);
	setcolor(6);
	outtext("0");
	moveto(570,50);
	setcolor(15);
	outtext("My Order");
	line(0,110,670,110);
	line(0,65,670,65);
	moveto(10,80);
	outtext("Shop by");
	moveto(10,90);
	outtext("CATEGORY");
	circle(140,85,8);
	circle(140,85,8.5);
	circle(140,85,9);
	line(147,92,152,97);
	moveto(155,85);
	outtext("Amazon.in");
	rectangle(120,70,550,105);
	line(155,95,162,95);
	moveto(10,120);
	outtext("HELLO!");
}


void home()				// This is the code of the home screen.
{
	top();
	moveto(580,87);
	outtext("EXIT");
	line(588,96,595,96);

	moveto(570,120);
	outtext("SIGN IN>");	
	line(610,130,617,130);

	moveto(570,135);
	outtext("SIGN UP>");	
	line(610,145,617,145);
	
	moveto(10,165);
	outtext("Products");
	
	moveto(12,180);
	outtext("* Mobiles");
	line(44,190,51,190);

	moveto(12,195);
	outtext("* Tablets");	
	line(28,205,35,205);

	moveto(12,210);
	outtext("* Laptops");
	line(28,220,35,220);

	moveto(12,225);
	outtext("* Accessories");
	line(83,235,90,235);

	moveto(90,250);
	outtext("Special Deals");

	moveto(130,280);
	outtext("LENOVO VIBE K5");

	moveto(145,295);
	outtext("* 128GB Internal Storage");

	moveto(145,310);
	outtext("* 5GB RAM");

	moveto(145,325);
	outtext("* 21MP Camera");

	moveto(145,340);
	outtext("* Price $1999");

	moveto(385,280);
	outtext("mi MAX");

	moveto(400,295);
	outtext("* 64GB Internal Storage");

	moveto(400,310);
	outtext("* 3GB RAM");

	moveto(400,325);
	outtext("* 16MP Camera");

	moveto(400,340);
	outtext("* Price $1499");

	moveto(130,370);
	outtext("Apple MacBook Air 13");

	moveto(145,385);
	outtext("* 5th Genration Laptop");

	moveto(145,400);
	outtext("* 4GB RAM");

	moveto(145,415);
	outtext("* 2TB Flash Storage");

	moveto(145,430);
	outtext("* Price $2999");

	moveto(385,370);
	outtext("SanDisk 64GB Flash Drive");

	moveto(400,385);
	outtext("* High Capacity Drive");

	moveto(400,400);
	outtext("* File Backup");

	moveto(400,415);
	outtext("* Price $99");

	moveto(10,450);
	outtext("# Management");
	line(58,460,65,460);

	moveto(50,465);
	outtext("CEO");

	cout<<"\n\n\n\n\n\n\n\n\t\t\tEnter Your Choice Here--> ";
}


// This function used to execute all possible choice of user input in the home screen.
/*
Choice A - Searching
Choice B - Buy a Mobile
Choice R - Buy a Mobile
Choice L - Buy a Laptop
Choice T - Buy a Tablet
Choice I - Login
Choice U - Sign-Up
Choice X - Exit
Choice G - Manager
else 	 - ERROR
*/
void choose(char x)				
{
	char ch='y';
	int f=0;
	
	if(x=='a'|| x=='A')
	{
		while(ch=='y' || ch=='Y')
		{
			fstream fsm("Mobile.txt",ios::in | ios::out | ios::binary | ios::app);
			fstream fsa("Accessories.txt",ios::in | ios::out | ios::binary | ios::app);
			fstream fsl("Laptop.txt",ios::in | ios::out | ios::binary | ios::app);
			fstream fst("Tablet.txt",ios::in| ios::out | ios::binary | ios::app);
			top();
			settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
			outtextxy(200,140,"SEARCH PRODUCT");
			setusercharsize(1.8,1.5,1.8,1.5);
			defaults();
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\tEnter the name of Product you want to Search\t";
			char search[20];
			gets(search);
			
			while(fsm.read((char*)&mob,sizeof(mob)))
			{
				if(strcmpi(search,mob.m())==0)
				{
					cout<<"\n\n\n\n\n";
					searching();
					top();
					cout<<"\n\n\n\n\n\n\n";
					mob.Show_Data();
					getch();
					f=1;
				}
			}
			
			while(fsa.read((char*)&acc,sizeof(acc)))
			{
				if(strcmpi(search,acc.a())==0)
				{
					cout<<"\n\n\n\n\n";
					searching();
					top();
					cout<<"\n\n\n\n\n\n\n";
					acc.Show_Data();
					getch();
					f=1;
				}
			}
			
			while(fsl.read((char*)&lap,sizeof(lap)))
			{
				if(strcmpi(search,lap.l())==0)
				{
					cout<<"\n\n\n\n\n";
					searching();
					top();
					cout<<"\n\n\n\n\n\n\n";
					lap.Show_Data();
					getch();
					f=1;
				}
			}
			
			while(fst.read((char*)&tab,sizeof(tab)))
			{
				if(strcmpi(search,tab.t())==0)
				{
					cout<<"\n\n\n\n\n";
					searching();
					top();
					cout<<"\n\n\n\n\n\n\n";
					tab.Show_Data();
					getch();
					f=1;
				}
			}
			
			fsm.close();
			fsa.close();
			fsl.close();
			fst.close();
			
			if(f==0)
			{
				searching();
				top();
				cout<<"\n\n\n\n\n\n\n\n\t\Product Not Found..!!";
			}
			
			cout<<"\nDo You Want to Search Again?\n\t\tEnter Your Choice--> ";
			cin>>ch;
		}
	}
	else if(x=='b' || x=='B')
	{
		int f=0;
		fstream fsm1("Mobile.txt",ios::in | ios::out | ios::binary);
		int pos;

		while(fsm1.read((char*)&mob,sizeof(mob)))
		{
			top();
			pos=fsm1.tellg();
			cout<<"\n\n\n\n\n\n\n\n";
			mob.show_data();
			cout<<"\n\tDo you want to buy Product? Enter Your Choice--> ";
			cin>>ch;
			
			if(ch=='y' ||ch=='Y' && mob.update()>0)
			{
				cout<<"\n\nThe Item will be delivered to you Soon\n\tThanks For Purchasing..!!";
				mob.update();
				fsm1.seekp(pos-1*sizeof(mob));
				fsm1.write((char*)&mob,sizeof(mob));
				f=1;
				getch();
				break;
			}
			else if(ch=='y'||ch=='Y' && mob.update()<=0)
			{
				cout<<"\n\nSorry The Product is out of Stock..!!";
				getch();
			}
			getch();
			top();
			
			if(f==1)
				break;
		}
		fsm1.close();
	}
	else if(x=='r'|| x=='R')
	{
		int f=0;
		double pos;
		fstream fsa1("Accessories.txt",ios::in | ios::out | ios::binary);
		
		while(fsa1.read((char*)&acc,sizeof(acc)))
		{
			top();
			pos=fsa1.tellg();
			cout<<"\n\n\n\n\n\n\n\n";
			acc.show_data();
			cout<<"\nDo you want to buy Product? Enter Your Choice--> ";
			cin>>ch;
			
			if(ch=='y' ||ch=='Y' && acc.update()>0)
			{
				cout<<"\n\nThe Item will be delivered to you Soon\n\tThanks For Purchasing..!!";
				acc.update();
				fsa1.seekp(pos-1*sizeof(acc));
				fsa1.write((char*)&acc,sizeof(acc));
				f=1;
			}
			else if(ch=='y'||ch=='Y' && acc.update()<=0)
			{
				cout<<"\n\nSorry The Product is out of Stock..!!";
				getch();
			}
			getch();
			top();
			
			if(f==1)
				break;
		}
		fsa1.close();
	}
	else if(x=='l'|| x=='L')
	{
		int f=0;
		double  pos;
		fstream fsl1("Laptop.txt",ios::in | ios::out | ios::binary);
		top();
		
		while(fsl1.read((char*)&lap,sizeof(lap)))
		{
			pos=fsl1.tellg();
			cout<<"\n\n\n\n\n\n\n\n";
			lap.show_data();
			cout<<"\nDo you want to buy Product? Enter Your Choice--> ";
			cin>>ch;
			
			if(ch=='y' ||ch=='Y' && lap.update()>0)
			{
				cout<<"\n\nThe Item will be delivered to you Soon\n\tThanks For Purchasing..!!";
				lap.update();
				fsl1.seekp(pos-1*sizeof(lap));
				fsl1.write((char*)&lap,sizeof(lap));
				f=1;
				break;
			}
			else if(ch=='y'||ch=='Y' && lap.update()<=0)
			{
				cout<<"\n\nSorry The Product is out of Stock..!!";
				getch();
			}
			getch();
			top();
		
			if(f==1)
				break;
		}
		fsl1.close();
	}
	else if(x=='t'|| x=='T')
	{
		int f=0;
		double pos;
		fstream fst1("Tablet.txt",ios::in | ios::out | ios::binary);
		top();
	
		while(fst1.read((char*)&tab,sizeof(tab)))
		{
			pos=fst1.tellg();
			cout<<"\n\n\n\n\n\n\n\n";
			tab.show_data();
			cout<<"\n\tDo you want to buy Product? Enter Your Choice--> ";
			cin>>ch;
		
			if(ch=='y' ||ch=='Y' && tab.update()>0)
			{
				cout<<"\n\nThe Item will be delivered to you Soon\n\tThanks For Purchasing..!!";
				tab.update();
				fst1.seekp(pos-1*sizeof(tab));
				fst1.write((char*)&tab,sizeof(tab));
				f=1;
				break;
			}
			else if(ch=='y'||ch=='Y' && tab.update()<=0)
			{
				cout<<"\n\nSorry The Product is out of Stock..!!";
				getch();
			}
			getch();
			top();
			if(f==1)
				break;
		}
		fst1.close();
	}
	else if(x=='i'|| x=='I')
	{
		fstream fss("signup.txt",ios::in | ios::out | ios::binary);
		top();
		settextstyle(TRIPLEX_FONT , HORIZ_DIR, 2);
		outtextxy(230,130,"LOGIN");
		char google[20],password[20];
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tEnter Your Google Account ";
		cin>>google;
		
		while(fss.read((char*)&Account,sizeof(Account)))
		{
			if(strcmpi(google,Account.goacc())==0)
			{
				cout<<"\n\n\t\tEnter Password ";
				cin>>password;
				if(strcmp(password,Account.passw())==0)
				{
					loading();
					top();
					cout<<"\n\n\n\n\n\n\n\n\t\t\tYour are Now Signed In..!!!";
					getch();
				}
			}
			else
				ERROR();
		}
		fss.close();
	}
	else if(x=='u'|| x=='U')
	{
		top();
		Signup();
	}
	else if(x=='x'|| x=='X')
	{
		top();
		cout<<"\n\n\n\n\n\n\n\n\n\tThanks FOR visiting..!!!!";
		cout<<"\n\n\t\tPress ENTER to EXIT";
		getch();
		exit(0);
	}
	else if (x=='g' || x=='G')
	{
		top();
		Manager();
	}
	else
		ERROR();
}


void Signup()			// This function will be used to sign up your account
{
	fstream fss("signup.txt",ios::binary | ios::in | ios::out | ios::app);
	char password2[10];
	settextstyle(TRIPLEX_FONT , HORIZ_DIR, 2);
	outtextxy(230,130,"CREATE YOUR ACCOUNT");
	cout<<"\n\n";
	Account.sign_up();
	cout<<"\n\tConfirm your Password ";
	gets(password2);
	
	if(strcmp(Account.passw(),password2)==0)
	{
		fss.write((char*)&Account,sizeof(Account));
		loading();
		top();
		cout<<"\n\n\n\n\n\n\n\n\n\t\tYour Account has been Sucessfully created..!! ";
		cout<<"\n\t\t\tYou are now a member of amazon.in!!";
		cout<<"\n\t\t\t\tPress ENTER";
		getch();
	}
	else
		ERROR();
	
	fss.close();
}


void OPTION()			// This function is used to provide options to the user
{
	cout<<"\n\t1. Mobile";
	cout<<"\n\t2. Accessories";
	cout<<"\n\t3. Laptop";
	cout<<"\n\t4. Tablets ";
}


void option()			// This function is used to provide options to the user
{
	cout<<"\n\t1. Mobile";
	cout<<"\n\t2. Accessories";
	cout<<"\n\t3. Laptop";
	cout<<"\n\t4. Tablets\n\tEnter Your Choice--> ";
}


void Manager()			// This function is used to perform all manager's task
{
	char ch1[20],ch2[20],ch3[20];
	top();
	settextstyle(TRIPLEX_FONT , HORIZ_DIR, 2);
	outtextxy(230,130,"MANAGER LOGIN");
	defaults();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\tEnter Your Name\t";
	gets(ch1);
	
	if(strcmp(ch1,"Mehul&Akshat")==0)
	{
		cout<<"\n\n\tEnter Your ID No.\t";
		gets(ch2);
		
		if(strcmp(ch2,"15047785")==0)
		{
			cout<<"\n\n\tEnter Code\t";
			gets(ch3);
		
			if(strcmp(ch3,"a")==0)
			{
				loading();
				top();
				cout<<"\n\n\n\n\n\n\n\tWELCOME..!! "<<ch1;
				cout<<"\n\n\t\t\t\tChoose An Option";
				cout<<"\n\t\t\t1. Add new Product";
				cout<<"\n\t\t\t2. Show the list of Products";
				cout<<"\n\t\t\t3. Edit Product in the Stock";
				cout<<"\n\t\t\t4. Delete the Product from the Stock ";
				cout<<"\n\t\t\t5. Log Out\n\t\tEnter Your Choice--> ";
				int ch;
				cin>>ch;
				switch(ch)
				{
					case 3:
						modify();
						break;
					case 1:
					{
						cout<<"\n\n\n\n\n\n\n";
						addproduct();
					}
						break;
					case 4:
					{
						cout<<"\n\n\n\n\n\n\n";
						deleteproduct();
					}
						break;
					case 2:
						showallproduct();
						break;
					case 5:
					{
						loading();
						top();
						cout<<"\n\n\n\n\n\n\n\n\tSucessfully Logged Out..!!";
						getch();
					}
						break;
					default:
						ERROR();
				}
			}
			else
			{
				ERROR();
			}
		}
		else
		{
		ERROR();
		}
	}
	else
	{
		ERROR();
	}
}


// This function modify the data in any of the following class's :- Mobile, Accesseories, Laptop, Tablet
// Step 1 : Select the category from which you want to modify a product
// Step 2 : Enter the name of product you want to edit
// Step 3 : It will ask for new Price and the number of products if you want to update then type respective values and if not then type -1
// Step 4 : At last it will you if you want to edit more products or not.
void modify()
{
	int ch1,newprice,newproduct;
	char name[20],ch='y';
	long pos;
	
	while(ch=='y'||ch=='Y')
	{
		top();
		cout<<"\n\n\n\n\n\n\n\n\t\tEnter the category in which you want to Edit-->";
		option();
		cin>>ch1;
		top();
		cout<<"n\n\n\n\n\n\n\n\t\t\Enter the name of Product you want to edit ";
		gets(name);
	
		switch(ch1)
		{
			case 1:
			{
				double pos;
				int f=0;
				fstream f1("Mobile.txt",ios::binary | ios::in | ios::out);
				
				while(f1.read((char*)&mob,sizeof(mob)))
				{
					pos=f1.tellg();
					
					if(strcmpi(name,mob.m())==0)
					{
						cout<<"\n Enter New Price(If you DON'T want to change Price write -1)\t";
						cin>>newprice;
						cout<<"\n Enter new no. of Product Arrived in the Stock\n(If you DON'T want to change No. of Product write -1)\t";
						cin>>newproduct;
						
						if(newprice!=-1)
							mob.mp(newprice);
						
						if(newproduct!=-1)
							mob.mm(newproduct);
						
						f=1;
						f1.seekp(pos-1*sizeof(mob));
						f1.write((char*)&mob,sizeof(mob));
						cout<<"\n\tProduct Sucessfully Updated..!!";
						getch();
						break;
					}
				}
				f1.close();
    			
				if(f==0)
    			{
					top();
					cout<<"\n\n\n\n\n\nProduct Not Found..!!";
					getch();
    			}
    		}
    			break;
			case 2:
			{
				int f=0;
				double pos;
				fstream f2("Accessories.txt",ios::in | ios::out | ios::binary );
				
				while(f2.read((char*)&acc,sizeof(acc)))
				{
					pos=f2.tellg();
					
					if(strcmpi(name,acc.a())==0)
					{
						cout<<"\n Enter New Price(If you DON'T want to change Price write -1)\t";
						cin>>newprice;
						cout<<"\n Enter New no. of Product Arrived in the Stock\n(If you DON'T want to change No. of Product write -1)\t";
						cin>>newproduct;
						
						if(newprice!=-1)
							acc.ap(newprice);
		
						if(newproduct!=-1)
							acc.am(newproduct);
			
						f=1;
						f2.seekp(pos-1*sizeof(acc));
						f2.write((char*)&acc,sizeof(acc));
						cout<<"\n\tProduct Sucessfully Updated..!!";
						getch();
						break;
					}
				}
    			f2.close();
    			
				if(f==0)
    			{
    				top();
    				cout<<"\n\n\n\n\n\nProduct Not Found..!!";
    			}
    		}
				break;
			case 3:
    		{
				double pos;
				int f=0;
				fstream f3("Laptop.txt",ios::in | ios::out | ios::binary );
	
				while(f3.read((char*)&lap,sizeof(lap)))
				{
					pos=f3.tellg();
					
					if(strcmpi(name,lap.l())==0)
					{
						cout<<"\n Enter New Price(If you DON'T want to change Price write -1)\t";
						cin>>newprice;
						cout<<"\n Enter New no. of Product Arrived in the Stock\n(If you DON'T want to change No. of Product write -1)\t";
						cin>>newproduct;
					
						if(newprice!=-1)
							lap.lp(newprice);
						
						if(newproduct!=-1)
							lap.lm(newproduct);
					
						f=1;
						f3.seekp(pos-1*sizeof(lap));
						f3.write((char*)&lap,sizeof(lap));
						cout<<"\n\tProduct Sucessfully Updated..!!";
						getch();
						break;
					}
				}
    			f3.close();
    			
				if(f==0)
    			{
    				top();
    				cout<<"\n\n\n\n\n\nProduct Not Found..!!";
    			}
    		}
    			break;
			case 4:
		    {
				double pos;
				int f=0;
				fstream f4("Tablet.txt",ios::in | ios::out | ios::binary );
				
				while(f4.read((char*)&tab,sizeof(tab)))
				{
					pos=f4.tellg();
					
					if(strcmpi(name,tab.t())==0)
					{
						cout<<"\n Enter New Price(If you DON'T want to change Price write -1)\t";
						cin>>newprice;
						cout<<"\n Enter New no. of Product Arrived in the Stock\n(If you DON'T want to change No. of Product write -1)\t";
						cin>>newproduct;
					
						if(newprice!=-1)
							tab.tp(newprice);
						
						if(newproduct!=-1)
							tab.tm(newproduct);
					
						f=1;
						f4.seekp(pos-1*sizeof(tab));
						f4.write((char*)&tab,sizeof(tab));
						cout<<"\n\tProduct Sucessfully Updated..!!";
						getch();
						break;
					}
				}
				f4.close();
			
				if(f==0)
				{
					top();
					cout<<"\n\n\n\n\n\nProduct Not Found..!!";
				}
			}
				break;
			default: ERROR();
		}
		cout<<"\n\tDo you want to edit again?\n\tEnter Your Choice--> ";
		cin>>ch;
	}
}


// This function is used to add a product
// Step 1 : Select the category to which you want to add a product
// Step 2 : Enter details of the product after that it will ask if you want to add more products of the same category Y - for yes and N - for no.
void addproduct()
{
	top();
	int ch;
	char ch1='y';
	cout<<"\n\n\n\n\n\n\n\n\n";
	OPTION();
	moveto(20,50);
	cout<<"\n\n\n\tIn Which Category do you want to Add Product?\n\tEnter Your Choice--> ";
	cin>>ch;
	
	switch(ch)
	{
		case 1:
		{
			fstream fs("Mobile.txt",ios::in | ios::out | ios::binary | ios::app);
		
			while(ch1=='y' || ch1=='Y')
			{
				top();
				mob.entermobiles();
			
				if(mob.ms()<0)
					ERROR();
				else
					fs.write((char*)&mob,sizeof(mob));
				
				cout<<"\n\n\nProduct Sucessfully Added..!!";
				cout<<"\nDo you want to Enter more Mobile? Enter Your Choice--> ";
				cin>>ch1;
			}
		}
			break;
		case 2:
		{
			fstream ffs("Accessories.txt",ios::in | ios::out | ios::binary | ios::app);
			
			while(ch1=='y' || ch1=='Y')
			{
				top();
				acc.enteracc();
			
				if(acc.as()<0)
					ERROR();
				else
					ffs.write((char*)&acc,sizeof(acc));
			
				cout<<"\n\n\nProduct Sucessfully Added..!!";
				cout<<"\nDo you want to Enter more Accessories? Enter Your Choice--> ";
				cin>>ch1;
			}
		}
			break;
		case 3:
		{
			fstream fffs("Laptop.txt",ios::in | ios::out | ios::binary | ios::app);
		
			while(ch1=='y' || ch1=='Y')
			{
				top();
				lap.enterlaptop();
			
				if(lap.ls()<0)
					ERROR();
				else
					fffs.write((char*)&lap,sizeof(lap));
			
				cout<<"\n\n\nProduct Sucessfully Added..!!";
				cout<<"\nDo you want to Enter more Laptop? Enter Your Choice--> ";
				cin>>ch1;
			}
		}
			break;
		case 4:
		{
			fstream ffffs("Tablet.txt",ios::in | ios::out | ios::binary | ios::app);
		
			while(ch1=='y' || ch1=='Y')
			{
				top();
				tab.entertab();
			
				if(tab.ts()<0)
					ERROR();
				else
					ffffs.write((char*)&tab,sizeof(tab));
			
				cout<<"\n\n\nProduct Sucessfully Added..!!";
				cout<<"\nDo you want to Enter more Tablet? Enter Your Choice--> ";
				cin>>ch1;
			}
		}
			break;
		default:ERROR();
	}
}


// This function is used to delete a product
// Step 1 : Select the category from which you want to delete a product
// Step 2 : Enter the name of a product, then it will display the details of the product and ask for your confirmation.
// Step 3 : Type Y/N if you want to delete or remain that product as it is respectively. Then it will ask if you want to delete more products or not.
void deleteproduct()				
{
	char ch='y',confirm;
	char name[20];
	int ch1;

	while(ch=='y'||ch=='Y')
	{
		top();
		cout<<"\n\n\n\n\n\n\n\n\n\n\tEnter the Choice you want to delete in-->";
		option();
		cin>>ch1;
		top();
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\tEnter the name of Product you want to Delete ";
		gets(name);
		switch(ch1)
		{
			case 1:
			{
				char found='f';
				fstream fs("Mobile.txt",ios::in | ios::out | ios::binary | ios::app);
				ofstream mah1("temp.txt",ios::binary);
			
				while(fs.read((char*)&mob,sizeof(mob)))
				{
				
					if(strcmp(name,mob.m())==0)
					{
						found='t';
						mob.show_data();
						cout<<"\n Are you sure you want to delete Product? Enter Your Choice--> ";
						cin>>confirm;
					
						if(confirm=='n' || confirm=='N')
						{
							mah1.write((char*)&mob,sizeof(mob));
							cout<<"\n\nProduct Is not Deleted..!!";
							getch();
						}
						else if(confirm=='Y' || confirm=='y')
						{
							cout<<"\n\nProduct Sucessfully Deleted..!!";
							getch();
						}
					}
					else
						mah1.write((char*)&mob,sizeof(mob));
				}
				
				if(found=='f')
				{
					cout<<"\n\tProduct Not Found..!!";
					getch();
				}
			
				fs.close();
				mah1.close();
				remove("mobile.txt");
				rename("temp.txt","mobile.txt");
			}
				break;
			case 2:
			{
				char found='f';
				fstream ffs("Accessories",ios::in | ios::out | ios::binary | ios::app);
				ofstream mah2("temp.txt",ios::binary);
			
				while(ffs.read((char*)&acc,sizeof(acc)))
				{
				
					if(strcmp(name,acc.a())==0)
					{
						found='t';
						cout<<"\n Are you sure you want to delete Product? Enter Your Choice--> ";
						cin>>confirm;
				
						if(confirm=='n' || confirm=='N')
						{
							mah2.write((char*)&acc,sizeof(acc));
							cout<<"\n\nProduct Is not Deleted..!!";
							getch();
						}
						else if(confirm=='Y' || confirm=='y')
						{
							cout<<"\n\nProduct Sucessfully Deleted..!!";
							getch();
						}
					}
					else
						mah2.write((char*)&acc,sizeof(acc));
				}
			
				if(found=='f')
				{
					cout<<"\n\tProduct Not Found..!!";
					getch();
				}
			
				ffs.close();
				mah2.close();
				remove("Accessories.txt");
				rename("temp.txt","Accessories.txt");
			}
				break;
			case 3:
			{
				char found='f';
				fstream fffs("Laptop",ios::in | ios::out | ios::binary | ios::app);
				ofstream mah3("temp.txt",ios::binary);
				
				while(fffs.read((char*)&lap,sizeof(lap)))
				{
			
					if(strcmp(name,lap.l())==0)
					{
						found='t';
						cout<<"\n Are you sure you want to delete Product? Enter Your Choice--> ";
						cin>>confirm;
					
						if(confirm=='n' || confirm=='N')
						{
							mah3.write((char*)&lap,sizeof(lap));
							cout<<"\n\nProduct Is not Deleted..!!";
							getch();
						}
						else if(confirm=='Y' || confirm=='y')
						{
							cout<<"\n\nProduct Sucessfully Deleted..!!";
							getch();
						}
					}
					else
						mah3.write((char*)&lap,sizeof(lap));
				}
				
				if(found=='f')
				{
					cout<<"\n\tProduct Not Found..!!";
					getch();
				}
			
				fffs.close();
				mah3.close();
				remove("laptop.txt");
				rename("temp.txt","laptop.txt");
			}
				break;
			case 4:
			{
				char found='f';
				fstream ffffs("Tablet.txt",ios::in | ios::out | ios::binary | ios::app);
				ofstream mah4("temp.txt",ios::binary);
		
				while(ffffs.read((char*)&tab,sizeof(tab)))
				{
			
					if(strcmp(name,tab.t())==0)
					{
						found='t';
						cout<<"\n Are you sure you want to delete Product? Enter Your Choice--> ";
						cin>>confirm;
					
						if(confirm=='n'|| confirm=='N')
						{
							mah4.write((char*)&tab,sizeof(tab));
							cout<<"\n\nProduct Is not Deleted..!!";
							getch();
						}
						else if(confirm=='Y' || confirm=='y')
						{
							cout<<"\n\nProduct Sucessfully Deleted..!!";
							getch();
						}
					}
					else
						mah4.write((char*)&tab,sizeof(tab));
				}
				if(found=='f')
				{
					cout<<"\n\tProduct Not Found..!!";
					getch();
				}
		
				ffffs.close();
				mah4.close();
				remove("Tablet.txt");
				rename("temp.txt","Tablet.txt");
			}
				break;
			default: ERROR();
		}
		cout<<"\n\n\tDo you Want to Delete More Product? Enter Your Choice--> ";
		cin>>ch;
	}
}


void showallproduct()				// To show all products present in the database and the sequence is : mobile -> Accessories -> Laptop -> Tablet
{
	int ch;
	fstream fs("Mobile.txt",ios::in | ios::out | ios::binary );
	fstream ffs("Accessories.txt",ios::in | ios::out | ios::binary );
	fstream fffs("Laptop.txt",ios::in | ios::out | ios::binary );
	fstream ffffs("Tablet.txt",ios::in| ios::out | ios::binary );
	while(!fs.eof() && fs.read((char*)&mob,sizeof(mob)))
	{
		top();
		cout<<"\n\n\n\n\n\n";
		mob.Show_Data();
		getch();
	}

	while(!ffs.eof() && ffs.read((char*)&acc,sizeof(acc)))
	{
		top();
		cout<<"\n\n\n\n\n\n";
		acc.Show_Data();
		getch();
	}

	while(!fffs.eof() && fffs.read((char*)&lap,sizeof(lap)))
	{
		top();
		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t";
		lap.Show_Data();
		getch();
	}

	while(!ffffs.eof() && ffffs.read((char*)&tab,sizeof(tab)))
	{
		top();
		cout<<"\n\n\n\n\n\n";
		tab.Show_Data();
		getch();
	}

	ffffs.close();
	fffs.close();
	ffs.close();
	fs.close();
}


void main()
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "bgi/");		//Initgraph initializes the graphics system by loading a graphics driver from disk, and putting the system into graphics mode.
	char ch='m',ch1,ch2;
	cart();										// First Screen.
	sleep(3);

	while(ch=='m'|| ch=='M')
	{
		home();									// This is the home screen.
		cin>>ch1;
		a:
		choose(ch1);							
		top();
		cout<<"\n\n\n\n\n\n\n\n\n\n\t# To Go To Previous Screen (PRESS P)\n\t# To Go To Home Screen (PRESS H)\n\t# To Exit the Program (PRESS E)\n\t\tEnter Your Choice Here--> ";
		cin>>ch2;								// Ask for a task to perform
	
		if(ch2=='p'|| ch2=='P')					// To go at previous screen
		{
			goto a;
		}
		else if(ch2=='e'|| ch2=='E')			// To exit execution
		{
			exit(0);
		}
		else if(ch2=='H' || ch2=='h')			// To go at home screen
		{
			ch='m';
		}
		else									// Any other input leads to error page
			ERROR();
	}
	
	getch();
	exit(0);
	closegraph();
	
}
