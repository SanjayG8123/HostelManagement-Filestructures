#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<iomanip>

using namespace std;

class HOSTEL 
{
	private:
	  int room_no;
	  char name[30];
	  char address[50];
	  char phone[15];
	  long month;
	  long cost;
	  char floor[30];
	  long pay;

	public:
	  void main_menu();	 	  //to dispay the main menu
	  void add();			  //to book a room
	  void display(); 		  //to display the specific customer information
	  void rooms();			  //to display alloted rooms
	  void edit();			  //to edit the customer by calling modify or delete
	  int check(int);		  //to check room status
	  void modify();		  //to modify the customer information
	  void delete_rec();              //to check out the customer
	  void modify_name(int);          //to modify name of guest
	  void modify_address(int);       //to modify address of guest
	  void modify_phone(int);         //to modify phone number of guest
	  void modify_days(int);          //to modify month of stay of guest
	  void hello();
}h;

void HOSTEL::main_menu()
{
	int choice;
	while(choice!=6)
	{
		system("cls");
		cout<<"\n\t\t\t\t\t\t ********************";
		cout<<"\n\t\t\t\t\t\t * HOSTEL MAIN MENU *";
		cout<<"\n\t\t\t\t\t\t ********************";
		cout<<"\n\n\n\t\t\t\t\t\t1. Book A Room";
		cout<<"\n\t\t\t\t\t\t2. Student Information";
		cout<<"\n\t\t\t\t\t\t3. Rooms Allotted";
		cout<<"\n\t\t\t\t\t\t4. Edit Student Details";
		cout<<"\n\t\t\t\t\t\t5. Exit";
		cout<<"\n\n\t\t\t\t\t\tEnter Your Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:	add();
				break;
			case 2: display();
				break;
			case 3: rooms();
				break;
			case 4:	edit();
				break;
			case 5: return;
			default:
				{
					cout<<"\n\n\t\t\tWrong choice.";
					cout<<"\n\t\t\tPress any key to continue.";
					getchar();
				}
		}
	}
}

void HOSTEL::add()
{
	system("cls");
	int r,flag;
	ofstream fout("Record.txt",ios::app|ios::binary);
	cout<<"\n\t\t\t +-----------------------+";
	cout<<"\n\t\t\t | Rooms  |   Floor no   |";
	cout<<"\n\t\t\t +-----------------------+";
	cout<<"\n\t\t\t |   1-50 |      1       |";
	cout<<"\n\t\t\t |  51-80 |      2       |";
	cout<<"\n\t\t\t | 81-100 |      3       |";
	cout<<"\n\t\t\t +-----------------------+";
	cout<<"\n\n ENTER STUDENT DETAILS";
	cout<<"\n ----------------------";
	cout<<"\n\n Room Number: ";
	cin>>r;
	flag=check(r);
	if(flag==1)
		cout<<"\n Sorry, Room is already booked.\n";
	else
	{
	   if(flag==2)
		   cout<<"\n Sorry, Room does not exist.\n";
	   else
	   {
		   room_no=r;
		   cout<<" Name: ";
		   cin>>name;
		   cout<<" Address: ";
		   cin>>address;
		   cout<<" Phone Number: ";
		   cin>>phone;
		   cout<<" Number of Months: ";
		   cin>>month;
		   if(room_no>=1&&room_no<=50)
		   {
		      strcpy(floor,"1st-floor");
		      cost=month*10000;
		   }
		   else
		   {
		      if(room_no>=51&&room_no<=80)
		      {
			 strcpy(floor,"2nd-floor");
			 cost=month*10000;
		      }
		      else
		      {
			 if(room_no>=81&&room_no<=100)
			 {
			    strcpy(floor,"3rd-floor");
			    cost=month*10000;
			 }
		      }
		   }
		   fout.write((char*)this, sizeof(HOSTEL));
		   cout<<"\n Room has been booked.";
	   }
	}
	cout<<"\n Press any key to continue.";
	getchar();
	getchar();
	fout.close();
}


void HOSTEL::display()
{
	system("cls");
	ifstream fin("Record.txt",ios::in|ios::binary);
	int r,flag;
	cout<<"\n Enter Room Number: ";
	cin>>r;
	while(fin.read((char*)this,sizeof(HOSTEL)))
	{
		if(room_no==r)
		{
			system("cls");
			cout<<"\n Student Details";
			cout<<"\n ----------------";
			cout<<"\n\n Room Number: "<<room_no;
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone Number: "<<phone;
			cout<<"\n Staying for "<<month<<" month(s).";
			cout<<"\n Floor no: "<<floor;
			cout<<"\n Total cost of stay: "<<cost;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Room is Vacant.";
	cout<<"\n\n Press any key to continue.";
	getchar();
	getchar();
	fin.close();

}


void HOSTEL::rooms()
{
	system("cls");
	const char separator=' ';
	const int NoWidth=8;
	const int GuestWidth=17;
	const int AddressWidth=16;
	const int RoomWidth=13;
	const int ContactNoWidth=13;
	ifstream fin("Record.txt",ios::in|ios::binary);
	cout<<"\n\t\t\t    LIST OF ROOMS ALLOTED";
	cout<<"\n\t\t\t   -----------------------";
	cout<<"\n\n +---------+------------------+-----------------+--------------+--------------+";
	cout<<"\n | Room No.|   Student Name   |      Address    |   Floor no   |  Contact No. |";
	cout<<"\n +---------+------------------+-----------------+--------------+--------------+";
	while(fin.read((char*)this,sizeof(HOSTEL)))
	{
		cout<<"\n |"<<setw(NoWidth)<<setfill(separator)<<room_no<<" |";
		cout<<setw(GuestWidth)<<setfill(separator)<<name<<" |";
		cout<<setw(AddressWidth)<<setfill(separator)<<address<<" |";
		cout<<setw(RoomWidth)<<setfill(separator)<<floor<<" |";
		cout<<setw(ContactNoWidth)<<setfill(separator)<<phone<<" |";
	}
	cout<<"\n +---------+------------------+-----------------+--------------+--------------+";
	cout<<"\n\n\n\t\t\tPress any key to continue.";
	getchar();
	getchar();
	fin.close();
}

void HOSTEL::edit()
{
	system("cls");
	int choice,r;
	cout<<"\n EDIT MENU";
	cout<<"\n ---------";
	cout<<"\n\n 1. Modify Student Information.";
	cout<<"\n 2. Student Check Out.";
	cout<<"\n Enter your choice: ";
	cin>>choice;
	system("cls");
	switch(choice)
	{
		case 1:	modify();
			break;
		case 2:	delete_rec();
			break;
		default: cout<<"\n Wrong Choice.";
			 break;
	}
	cout<<"\n Press any key to continue.";
	getchar();
}


int HOSTEL::check(int r)
{
	int flag=0;
	ifstream fin("Record.txt",ios::in|ios::binary);
	while(fin.read((char*)this,sizeof(HOSTEL)))
	{
		if(room_no==r)
		{
			flag=1;
			break;
		}
		else
		{
		  if(r>100)
		  {
			flag=2;
			break;
		  }
		}
	}
	fin.close();
	return(flag);
}


void HOSTEL::modify()
{
	system("cls");
	int ch,r;
	cout<<"\n MODIFY MENU";
	cout<<"\n -----------";
	cout<<"\n\n\n 1. Modify Name";
	cout<<"\n 2. Modify Address";
	cout<<"\n 3. Modify Phone Number";
	cout<<"\n 4. Modify Number of Months of Stay";
	cout<<"\n Enter Your Choice: ";
	cin>>ch;
	system("cls");
	cout<<"\n Enter Room Number: ";
	cin>>r;
	switch(ch)
	{
		case 1: modify_name(r);
			break;
		case 2: modify_address(r);
			break;
		case 3: modify_phone(r);
			break;
		case 4: modify_days(r);
			break;
		default: cout<<"\n Wrong Choice";
				 getchar();
				 getchar();
			 break;
	}
}

void HOSTEL::modify_name(int r)
{
	long pos,flag=0;
	fstream file("Record.txt",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOSTEL));
		if(room_no==r)
		{
			cout<<"\n Enter New Name: ";
			cin>>name;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOSTEL));
			cout<<"\n Customer Name has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOSTEL::modify_address(int r)
{
	long pos,flag=0;
	fstream file("Record.txt",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOSTEL));
		if(room_no==r)
		{
			cout<<"\n Enter New Address: ";
			cin>>address;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOSTEL));
			cout<<"\n Customer Address has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOSTEL::modify_phone(int r)
{
	long pos,flag=0;
	fstream file("Record.txt",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOSTEL));
		if(room_no==r)
		{
			cout<<"\n Enter New Phone Number: ";
			cin>>phone;
			file.seekg(pos);
			file.write((char*)this,sizeof(HOSTEL));
			cout<<"\n Customer Phone Number has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}

void HOSTEL::modify_days(int r)
{
	long pos,flag=0;
	fstream file("Record.txt",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(HOSTEL));
		if(room_no==r)
		{
			cout<<" Enter New Number of month(s) of Stay: ";
			cin>>month;
			if(room_no>=1&&room_no<=50)
			{
				strcpy(floor,"1st-floor");
				cost=month*10000;
			}
			else
			{
				if(room_no>=51&&room_no<=80)
				{
				   strcpy(floor,"2nd-floor");
				   cost=month*10000;
				}
				else
				{
					if(room_no>=81&&room_no<=100)
					{
					   strcpy(floor,"3rd-floor");
					   cost=month*15000;
					}
				}
			}
			file.seekg(pos);
			file.write((char*)this,sizeof(HOSTEL));
			cout<<"\n Student information is modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	file.close();
}

void HOSTEL::delete_rec()
{
	int r,flag=0;
	char ch;
	cout<<"\n Enter Room Number: ";
	cin>>r;
	ifstream fin("Record.txt",ios::in|ios::binary);
	ofstream fout("temp.DAT",ios::out|ios::binary);
	while(fin.read((char*)this,sizeof(HOSTEL)))
	{
		if(room_no==r)
		{
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone Number: "<<phone;
			cout<<"\n Floor-No: "<<floor;
			cout<<"\n Your total bill is: Rs. "<<cost;
			cout<<"\n\n Do you want to check out this student(y/n): ";
			cin>>ch;
			if(ch=='n')
			   fout.write((char*)this,sizeof(HOSTEL));
			else
			   cout<<"\n Student Checked Out.";
			flag=1;
		}
		else
			fout.write((char*)this,sizeof(HOSTEL));
	}
	fin.close();
	fout.close();
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	else
	{
		remove("Record.txt");
		rename("temp.dat","Record.txt");
	}
	getchar();
	getchar();
}


void HOSTEL::hello()
{
	system("cls");
	cout<<"\n\t\t\t\t\t\t ****************************";
	cout<<"\n\t\t\t\t\t\t * HOSTEL MANAGEMENT SYSTEM *";
	cout<<"\n\t\t\t\t\t\t ****************************";
	cout<<"\n\n\t\t\tMade By : Prajwal K V and Sanjay G from 6th sem ISE department !!!";
	cout<<"\n\n\t\t\tPress enter to continue !!!";
	getchar();
}

int main()
{
	h.hello();
	system("cls");
	h.main_menu();
	return 0;
}

