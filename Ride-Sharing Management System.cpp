#include<iostream>
#include<conio.h>
#include<windows.h>
#include<sstream>
using namespace std;
class bio{
public:
    string name;
    string age;
    string gender;
    string ph_number;
    string history;
    bio()
    {
        name="";
        age="";
        gender="";
        ph_number="";
        history="";
    }
};
class driver:public bio{
public:
    string color;
    string car_name;
    string car_number;
    string area;
};

class user:public driver{
public:
    int count;
    string users[10][5];
    int index;
    user()
    {
        count=0;
        index=0;
        add_users("ahmad","20", "male", "03361561978");
        add_users("nauman","20", "male", "03340000000");
        add_users("shehryar","20", "male", "03200000000");
    }
    void signup()
    {
        if(count<10)
        {
            cout<<"\n\tName         : ";
            getline(cin,name);
            cout<<"\n\tAge          : ";
            getline(cin,age);
            cout<<"\n\tGender       : ";
            getline(cin,gender);
            cout<<"\n\tPhone Number : ";
            getline(cin,ph_number);
            add_users(name,age,gender,ph_number);
            system("cls");
            cout<<"\n\tUser Added Successfully.Back to User Menu.\n\n";
           
        }
        else
            cout<<"\nNo more Space to add Users.\n";
    }
    void add_users(string name,string age,string gender,string ph_number)
    {
        users[count][0]=name;
        users[count][1]=age;
        users[count][2]=gender;
        users[count][3]=ph_number;
        users[count][4]="\nHistory:\n";
        count++;
    }
    bool login()
    {
        char a;
        cout<<"\n\tName      : ";
        getline(cin,name);
        cout<<"\n\tPh Number : ";
        getline(cin,ph_number);
        bool flag=false;
        for(int i=0; i<=count; i++)
        {
            if(users[i][0]==name)
            {
                if(users[i][3]==ph_number)
                {
                    index=i;
                    flag=true;
                    break;
                }
            }
        }
        return flag;
    }

void display()
    {
        for(int i=0;i<count;i++)
        {
            cout<<users[i][0]<<endl;
       }
   }
};

class admin:public user{
public:
    int counter;
    string drivers[10][9];
    admin()
    {
        counter=0;
        set_driver_data("ahmad","20","male","03361561978","Honda Civic 2012","7223","model town","Black");
        set_driver_data("haris","20","male","123456789","Toyota Corolla 2015","5984","iqbal town","White");
        set_driver_data("hamza","20","male","03240000000","Toyota Vitz 2015","2221","johar town","Red");
    }
    void set_driver_data(string name,string age,string gender,string ph_number,string car_name,string car_number,string area,string color)
    {
        drivers[counter][0]="Name: "+name;
        drivers[counter][1]="Age: "+age;
        drivers[counter][2]="Gender: "+gender;
        drivers[counter][3]="Phone Number: "+ph_number;
        drivers[counter][4]="Car Name: "+car_name;
        drivers[counter][5]="Color: "+color;
        drivers[counter][6]="Car Number: "+car_number;
        drivers[counter][7]=area;
        drivers[counter][8]="0";
        counter++;
    }
    void input()
    {
        if(counter<10)
        {
        	system("cls");
        	cout<<"\n\n\t\t\tGive Driver Information for add : \n";
            cout<<"\n   Driver name        : ";
            getline(cin,name);
            cout<<"\n   Age                : ";
            getline(cin,age);
            cout<<"\n   Gender             : ";
            getline(cin,gender);
            cout<<"\n   Phone Number       : ";
            getline(cin,ph_number);
            //Car information start
            cout<<"\n   Car Name and Model : ";
            getline(cin,car_name);
            cout<<"\n   Car Color          : ";
            getline(cin,color);
            cout<<"\n   Car Number         : ";
            getline(cin,car_number);
            cout<<"\n   Present Area       : ";
            getline(cin,area);
            system("cls");
            cout<<"\n\t\t\tDriver Added Successfully.";
            cout<<"\n\nt\t   _________________________________________________\n\n\n";
            set_driver_data(name,age,gender,ph_number,car_name,car_number,area,color);
        }
        else
            cout<<"\n   No more space to add Drivers.\n";
    }
    void display_drivers()
    {
    	cout<<"\n\t\t\tDRIVERS INFORMATION : \n\n";
        for(int i=0; i<counter; i++)
        {
            for(int j=0; j<9; j++)
                cout<<"\n"<<drivers[i][j]<<endl;
            cout<<"\n       *****************************\n\n";
        }

    }
    int cc()
    {
        return counter;
    }
    void deletedriver()
    {
        cout<<"\nDriver Phone Number: ";
        cin>>ph_number;
        bool flag=false;
        string temp="Phone Number: "+ph_number;
        string del;
        for(int i=0; i<counter; i++)
        {
            if(drivers[i][3]==temp)
            {
            	del=drivers[i][0];
                counter--;
                swap(drivers[i][0],drivers[counter][0]);
                swap(drivers[i][1],drivers[counter][1]);
                swap(drivers[i][2],drivers[counter][2]);
                swap(drivers[i][3],drivers[counter][3]);
                swap(drivers[i][4],drivers[counter][4]);
                swap(drivers[i][5],drivers[counter][5]);
                swap(drivers[i][6],drivers[counter][6]);
                swap(drivers[i][7],drivers[counter][7]);
                swap(drivers[i][8],drivers[counter][8]);
                flag=true;
                system("cls");
                cout<<"\n\tDriver "<<del<<" Deleted Successfully.\n";
                cin.ignore();
                break;
            }
        }
        if(flag==false)
        {
           system("cls");
            cout<<"\n\t\tNo driver Found.\n\n";
        }
    }
};
int main()
{
    admin admn;
    user usr;
	dis_start:
    cout<<"\n\n\n\t\t\t\t  MALAI APP\n\t\t\t\t_____________\n\n";
	cout<<"\t====================== WELCOME TO UBER ======================";
    cout<<"\n\n\n\t  Main Menu :\n\t________________\n\n\t\t1)  Admin\n\t\t2)  User\n\t\t3)  Exit.";
    char a;
    cout<<"\n\n\tChoose any Option   ";
    a=getche();
    if(a=='1')
    {
        cout<<"\n\n\tEnter Password :    ";
        int i=0;
        bool flag=false;
        string password="";
        while(true)
        {
            a=getch();
            if(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9')
            {
                cout<<"*";
                password=password+a;
                i++;
            }
            else if(a!='1'||a!='2'||a!='3'||a!='4'||a!='5'||a!='6'||a!='7'||a!='8'||a!='9'||a!='0')
            {
            	system("cls");
                cout<<"\n\tEnter Only Numbers.\n\tYou are back to Main Menu.\n";
                goto dis_start;
            }
            if(i==5)
            {
                if(password=="11229")
                {
                   	system("cls");
                    cout<<"\n\n\t\tlogin Successfully.\n";
                    flag=true;
                    break;
                }
                else
                {
                   cout<<"\n\n\t\tInvalid Password. Try Again....\n\n   Password :   ";
                    password="";
                    i=0;
                }
            }
        }
        //*****************************************************************Password Ended
        if(flag)
        {
admin_start:
            cout<<"\n\n\n\t\t  ADMIN MENU : \n\t\t________________\n\n\n\t1)  Add driver\n\t2)  View Drivers\n\t3)  User History\n\t";
            cout<<"4)  Delete Drivers\n\t5)  Logout\n\n\n\tChoose an Option   ";
            a=getche();
            cout<<endl;
            if(a=='1')
                admn.input();
            else if(a=='2')
            {
               system("cls");
                admn.display_drivers();
                cout<<"\n\n\tEnter any key to go back to Admin Menu   ";
                a=getch();
                system("cls");
                goto admin_start;
            }

            else if(a=='3')
            {
            	 cout<<"\n\t\tUsers List:\n\n";
                usr.display();
                cout<<"\n\t\tName: ";
                string name;
                getline(cin,name);
                bool flag=false;
                for(int i=0; i<usr.count; i++)
                {
                    if(usr.users[i][0]==name)
                    {
                            for(int j=0; j<5; j++)
                                cout<<usr.users[i][j]<<endl;
                            flag=true;
                            break;
                    }
                }
                if(flag==false)
                {
                	system("cls");
                    cout<<"\n   No Such User Found.Back to Admin Menu.";
                }

            }
            else if(a=='4')
                admn.deletedriver();
            else if(a=='5')
            {
                system("cls");
                cout<<"\n\t\tYou Are Logout. Back to Main Menu.\n\n\n";
                goto dis_start;
            }
            else
                cout<<"\n\t\tWrong Input. Try Again : \n";
            goto admin_start;

        }
    }

    else if(a=='2')
    {
usr_start:
        cout<<"\n\n\t\t\t\t  USER MENU :\n\t\t\t\t_______________\n\n\t\t\t\t\t1)  Login and Ride \n\t\t\t\t\t";
        cout<<"2)  Sign up\n\t\t\t\t\t3)  Back To Main Menu\n\n\t\t\t\tChoose an Option   ";
        a=getche();
        cout<<endl;
        if(a=='1')
        {
            bool flg=usr.login();
            if(flg==true)
            {
                string drop="";
                string pickup="";
                system("cls");
                cout<<"\n\n\tYou are Login.\n"<<endl;
                cout<<"\n\t\tEnter Your Drop off Location :  ";
                getline(cin,drop);
                cout<<"\n\t\tEnter Your Pick Up Location  :  ";
                getline(cin,pickup);
                cout<<"\n\n\tFinding Driver";
                for(int i=0; i<5; i++)
                {
                    Sleep(1000);
                    cout<<".";
                }
                int cot=admn.cc();
                int index=0;
                bool flag=false;
                for(int i=0; i<cot; i++)
                {
                    if(admn.drivers[i][7]==pickup)
                    {
                        index=i;
                        flag=true;
                        break;
                    }
                }
                if(flag)
                {
                    cout<<"\n\n\t\t   Driver found\n\n\tDriver Information :\n\n";
                    cout<<"\t\t\t\t"<<admn.drivers[index][0]<<endl;
                    cout<<"\t\t\t\t"<<admn.drivers[index][2]<<endl;
                    cout<<"\t\t\t\t"<<admn.drivers[index][3]<<endl;
                    cout<<"\t\t\t\t"<<admn.drivers[index][4]<<endl;
                    cout<<"\t\t\t\t"<<admn.drivers[index][5]<<endl;
                    cout<<"\t\t\t\t"<<admn.drivers[index][6]<<endl;
                    cout<<"\n\tFare : 12rs/km.";
                    cout<<"\n\nPress Any Key if you want this Ride.\nOr Press ESC for Cancel this Ride and go back to Main Menu.  ";
                    a=getch();
                    if(a!=27)
                    {
					system("cls");
                    cout<<"\n\n\tDriver is on his way  \n\n";
                    for(int i=30; i>=0; i--)
                    {
                        Sleep(1000);
                        cout<<"\r\t\t\t\tPlease Wait for: "<<i<<" Sec";
                    }
                    cout<<"\n\n\t  Driver is Arrived : \n\nMeet At Pickup Point and press any key when you enter in the car.... ";
                    a=getch();
                    cout<<"\n\n\tRide start : \n";
                    for(int i=0; i<8; i++)
                    {
                        Sleep(1000);
                        cout<<"\t\t\t\t*"<<endl;
                    }
                    cout<<"\n\n\tYou are on your drop off location.";
                    cout<<"\n\n\tEnter Kilometers :  ";
                    admn.drivers[index][7]=drop;
                    int meters=0;
                    cin>>meters;
                    cout<<"\n\t\tYour Bill : "<<meters*12;
                    a=getch();
                    string tep;
                    stringstream ss;
                    ss<<meters*12;
                    tep=ss.str();
                    usr.users[usr.index][4]=usr.users[usr.index][4]+pickup+" to "+drop+" \nPaid: "+tep+"\n";
                    cout<<"\nBill Paid.\n\n\t\tYour ride is over.Thank You for using our App.\n\n   Press any key to go back to Main Menu.....";
                    a=getch();
                    cin.ignore();
                    system("cls");
                    goto dis_start;
                }
                else
                {
                	system("cls");
                	goto dis_start;
				}
              }
                else
                   
				 cout<<"\n\n   No driver found in your location. Enter any key to go back to User Menu...\n";
                    a=getch();
                    cin.ignore();
                    system("cls");
                goto usr_start;

            }
            else
            {
            	system("cls");
                cout<<"\n\t\tNo Such User Found. Back to User Menu.\n\n";
                goto usr_start;
            }
        }
        else if(a=='2')
        {
            usr.signup();
            goto usr_start;
        }
        else if(a=='3')
        {
            system("cls");
            goto dis_start;
        }
        else
        {
          system("cls");
           cout<<"\n\t\tInvalid Option. Try Again : \n";
          goto usr_start;
        }
    }
    else if(a=='3')
    {
    	system("cls");
    	cout<<"\n\n\tThank You For Using Our App.\n\t\tGood Bye! ";
    	return 0;
	}

    else
    {
    system("cls");
    cout<<"\n\t\tInvalid Option. Try Again : \n";
    goto dis_start;
   }
}

