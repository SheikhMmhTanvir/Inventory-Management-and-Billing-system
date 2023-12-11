#include<bits/stdc++.h>
using namespace std;

class supermarket
{
	public:
	int xz;

	supermarket()
	{xz=0;}
	int itemNumber;
	string name;
	float price,quantity,tax,dis;
	void AddProduct();
	void ShowProduct();
	void InputFile();
	void Display();
	void DisplaySpecific(int n);
	void Update();
	void Delete();
	void menu();
	void AdminMenu();
	void PlaceOrder();
	void intro();

};

fstream f;
supermarket s;

void supermarket::AddProduct()
{
cout<<"\nEnter the Item no. of the Product		:	";
cin>>itemNumber;
cout<<"\nEnter the Name of the Product			:	";
cin>>name;
cout<<"\nEnter the Price of the Product			:	";
cin>>price;
cout<<"\nEnter the Discount (%) of the Product	:	";
cin>>dis;
xz=xz+1;
}

void supermarket::ShowProduct()
{
cout<<"\nThe Item no. of The Product	: "<<itemNumber;
cout<<"\nThe Name of The Product 		: ";
cout<<name;
cout<<"\nThe Price of The Product 		: "<<price;
cout<<"\nDiscount : "<<dis;
}

void supermarket::InputFile()
{
f.open("Store.txt",ios::out|ios::app);
s.AddProduct();
f.write((char*)&s,sizeof(supermarket));
f.close();
cout<<"\n\nThe Product Has Been Created \n";
}

void supermarket::Display()
{
system("cls");
cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
f.open("Store.txt",ios::in);
int flag;
flag=0;
while(flag==0)
{
if(!f.eof())
{
flag==0;
f.read((char*)&s,sizeof(supermarket));
s.ShowProduct();
cout<<"\n\n====================================\n";
}
else
flag==1;
}
f.close();
}

void supermarket::DisplaySpecific(int n)
{
int flag=0;
f.open("Store.txt",ios::in);
while(f.read((char*)&s,sizeof(supermarket)))
{
if(s.itemNumber==n)
{
system("cls");
s.ShowProduct();
flag=1;
}
}
f.close();
if(flag==0)
cout<<"\n\nrecord not exist";
}

void supermarket::Update()
{
int no,found;
found=0;
system("cs");
cout<<"\n\n\tTo Modify ";
cout<<"\n\n\tEnter The Item No. of The Product	: ";
cin>>no;
f.open("Store.txt",ios::in|ios::out);
while(f.read((char*)&s,sizeof(supermarket)) && found==0)
{
if(s.itemNumber==no)
{
s.ShowProduct();
cout<<"\nEnter The New Details of Product"<<endl;
s.AddProduct();
int pos=1*sizeof(s);
f.seekp(pos,ios::cur);
f.write((char*)&s,sizeof(supermarket));
cout<<"\n\n\t Record Updated";
found=1;
}
}
f.close();
if(found==0)
cout<<"\n\n Record Not Found ";
}

void supermarket::Delete()
{
int no;
system("cls");
cout<<"\n\n\n\tDelete Record";
cout<<"\nEnter The Item no of The Product You Want To Delete  : ";
cin>>no;
f.open("Store.txt",ios::in|ios::out);
fstream f2;
f2.open("Temp.txt",ios::out);
f.seekg(0,ios::beg);
while(f.read((char*)&s,sizeof(supermarket)))
{
if(s.itemNumber!=no)
{
f2.write((char*)&s,sizeof(supermarket));
}
}
f2.close();
f.close();
remove("Store.txt");
rename("Temp.txt","Store.txt");
cout<<"\n\tRecord Deleted ..";
}

void supermarket::menu()
{
system("cls");
f.open("Store.txt",ios::in);
if(!f)
{
cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n Go To Admin Menu to create File";
cout<<"\n\n\n Program is closing ....";
exit(0);
}
cout<<"\n\n\t\tProduct MENU\n\n";
cout<<"====================================================\n";
cout<<"ITEM.NO.\t\tNAME\t\tPRICE\n";
cout<<"====================================================\n";
while(f.read((char*)&s,sizeof(supermarket)))
{
cout<<s.itemNumber<<"\t\t"<<s.name<<"\t\t"<<s.price<<endl;
}
f.close();
}

void supermarket::PlaceOrder()
{
int order[50],quan[50],c=0;
float amt,damt,total=0;
char ch='Y';
menu();
cout<<"\n============================";
cout<<"\n PLACE YOUR ORDER";
cout<<"\n============================\n";
do{
cout<<"\nEnter The Product No. Of The Product : ";
cin>>order[c];
cout<<"Quantity in number : ";
cin>>quan[c];
c++;
cout<<"\nDo You Want To Order Another Product ? (y/n)";
cin>>ch;
}while(ch=='y' ||ch=='Y');
cout<<"\n\nThank You For Placing The Order";
system("cls");
cout<<"\n\n*********************************************INVOICE**********************************************\n";
cout<<"\nItem No."<<setw(15)<<"Item Name"<<setw(20)<<"Quantity "<<setw(10)<<"Price" <<setw(15)<<"Amount" <<setw(30)<<"Amount after discount\n";
for(int x=0;x<=c;x++)
{
f.open("Store.txt",ios::in);
f.read((char*)&s,sizeof(supermarket));
while(!f.eof())
{
if(itemNumber==order[x])
{
amt=s.price*quan[x];
damt=amt-(amt*s.dis/100);
cout<<"\n"<<setw(15)<<left<<order[x]
    <<setw(20)<<left<<s.name
    <<setw(13)<<left<<quan[x]
    <<setw(16)<<left<<s.price
    <<setw(10)<<left<<amt
    <<setw(15)<<right<<damt;
total+=damt;
}
f.read((char*)&s,sizeof(supermarket));
}
f.close();
}
cout<<"\n\n\t\t\t\t\tTOTAL = "<<total<<" BDT";
cout<<"\n**************************************************************************************************\n";
}

void supermarket::intro()
{
system("cls");
cout<<"PROJECT : Inventory Management && Billing system";
cout<<"\n\nMADE BY : Team HoneyBear!! (2HM) "<<endl;
cout<<"Author : \n\t[ Arfin jawad walid]\n\t[  Sheikh Tanvir   ]\n\t[       Wasif      ]\n\t[    Jahiat Efaz   ]"<<endl;
}

void supermarket::AdminMenu()
{
system("cls");
char ch2;
cout<<"\n\n\n\tADMIN MENU";
cout<<"\n\n\t1.CREATE PRODUCT";
cout<<"\n\n\t2.DISPLAY ALL PRODUCTS";
cout<<"\n\n\t3.QUERY ";
cout<<"\n\n\t4.MODIFY PRODUCT";
cout<<"\n\n\t5.DELETE PRODUCT";
cout<<"\n\n\t6.VIEW PRODUCT MENU";
cout<<"\n\n\t7.BACK TO MAIN MENU";
cout<<"\n\n\tPlease Enter Your Choice (1-7) ";
cin>>ch2;
switch(ch2)
{
case '1': system("cls");
		InputFile();
		break;
case '2': Display();break;
case '3':int num;
		system("clear");
		cout<<"\n\n\tEnter The Product No. : ";
		cin>>num;
		DisplaySpecific(num);
		break;
case '4': Update();break;
case '5': Delete();break;
case '6': menu();
case '7': break;
default:cout<<"\a";AdminMenu();
}
}

//Driver code
int main()
{
char ch;
s.intro();
do
{
cout<<"\n\n\n\tMAIN MENU";
cout<<"\n\n\t01. CUSTOMER";
cout<<"\n\n\t02. ADMINISTRATOR";
cout<<"\n\n\t03. EXIT";
cout<<"\n\n\tPlease Select Your Option (1-3) ";
cin>>ch;
switch(ch)
{
case '1': system("cls");
		s.PlaceOrder();
		break;
case '2': 	s.AdminMenu();
		break;
case '3':exit(0);
default :cout<<"\a";
}
}while(ch!='3');
return 0;
}
