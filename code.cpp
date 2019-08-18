#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int i = 0; //global variable
class hotel
{
	int rooms, room_no, days, cost;

	char name[30];      //customer name
	char address[50];   //customer address
	char phone[11];     //customer phone number
	char room_type[10]; //customer room type selection
    public:
    hotel()             //default constructor for initialising values
    {  cost = 0;            //one night cost of room type
       rooms = 100;
       name[0] = '\0' ;
       address[0] = '\0';
       phone[0] = '\0';
       room_type[0] = '\0';
       room_no = 0;             //customer room number
       days = 0;                //duration of stay
    }
    hotel(int x)                //parameterized constructor
    {
        rooms = x;
    }
    friend void main_menu(hotel * );    //friend function for menu
	static int counter ;//to keep a count of the number of rooms booked
	void add(hotel *);		//to book a room
	void display();	//to display the customer record
	void hotel_rooms();	//to display alloted rooms
	void edit(hotel *, int);	//to edit the customer record
	void delete_rec(hotel *, int);	//to delete the record
    friend void cost(hotel *); //to calculate cost of stay
    inline void operator +=(hotel );   //operator overloading of +=, it is an inline function
    friend int check(hotel *, int );    //non member function (friend) to check whether room to be alloted is vacated or not
};

inline void hotel ::operator+=(hotel x)//inline function hence function call will be directly replaced with this block of code
{

    cost = cost + (x.days*x.cost);  //calculates the cost of stay
}
int hotel ::counter = 0; //initialising static variable
void occupied() // non member function for displaying the number of occupied rooms
{
    cout<<"\n\n\n\n\tNumber of occupied rooms are :"<<"\t"<<hotel ::counter<<"\n\n\n\n";
}
int check(hotel *k, int r)
{
    int flag = 1;
    for(int j =0; j< hotel::counter;j++)
        if(k[j].room_no == r)
    {
        flag = 0; //setting flag varibale to 0 if room exists
    }
    return flag; // value of flag variable decided whether room is booked or not
}
void main_menu(hotel *h)
{
	int choice, r, j =0 ;

	while(choice!=8)
	{
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\t\t\t\t* MAIN MENU *"; //displaying all the possible functions that could be carried out in this program
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\n\n\t\t\t1.Book A Room";
		cout<<"\n\t\t\t2.Customer Record";
		cout<<"\n\t\t\t3.Rooms Allotted";
		cout<<"\n\t\t\t4.Edit Record";
		cout<<"\n\t\t\t5.Delete Record";
		cout<<"\n\t\t\t6.Calculate cost of the stay";
		cout<<"\n\t\t\t7.Display number of occupied rooms";
		cout<<"\n\t\t\t8.Exit";

		cout<<"\n\n\t\t\tEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1: h[i++].add(h); //Booking rooms one by one
                    cout<<"\n\n\n\n\n";
					break;
			case 2: cout<<"\n Enter Room No."; //displaying customer record for a particular room number
                    cin>>r;
                    for(j = 0; j< hotel ::counter; j++)
                        if(h[j].room_no == r) //if room no. found in the array then break from the loop
                            break;
                    h[j].display();
                    if(j >= hotel ::counter) // this condition means that loop stopped on its own without intervention of break which means if clause not reached
                        cout<<"\n Room no. not found";
                    cout<<"\n\n\n\n\n";
                    break;
			case 3: if(hotel::counter == 0)
                    {
                        cout<<"\n\n No records found";
                    }
                    else
                    {
                    cout<<"\n\t\t\tList Of Rooms Allotted";
                    cout<<"\n\t\t\t*********************";
                    cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\t\tDays\t\tRoom Type\n";
                    for(j = 0; j < hotel ::counter; j++) //displaying all the customer records in a table format
                        h[j].hotel_rooms();
                    }
                    cout<<"\n\n\n\n\n";
                    break;
			case 4: cout<<"\n Enter Current room no.";
                    cin>>r;
                    for(j = 0; j <hotel ::counter; j++)
                        if(h[j].room_no == r)
                            break;
                    if(j>= hotel::counter)
                        cout<<"\n Room no. has not been booked";
                    else
                        {h[j].edit(h,j);}
                    cout<<"\n\n\n\n\n";
					break;
            case 5: cout<<"\n Enter Current room no."; //vacating a room
                    cin>>r;
                    for(j = 0; j <hotel ::counter; j++)
                        if(h[j].room_no == r)
                            break;
                    if(j>=hotel ::counter)
                        cout<<"\n\nNo record found";
                    else
                    {
                    h[j].delete_rec(h,j);
                    }

                    cout<<"\n\n\n\n\n";
                    break;
            case 6: cost(h);break; //calculating the cost of stay for a particular customer
            case 7 : occupied();break;
			case 8: break; // exit function from the program

			default:
					{
						cout<<"\n\n\t\t\tWrong choice!!!";
						cout<<"\n\t\t\tPress any key to continue!!";
						cout<<"\n\t\t\t Press 5 to exit";

					}
		}

	}

}

void hotel::add(hotel *h)
{
    int ch, flag = 1,r;
    hotel ::counter ++;
    if(counter > rooms)
       {
        cout<<"\n We are full, sorry for the inconvenience: \n"; // checking full house condition
        hotel ::counter --;
       }
    else
	{

	cout<<"\n Enter Customer Detalis"; // taking customer details
	cout<<"\n **********************";
    gets(name);
    cout<<" \n\n\n Name: ";
    gets(name);
    cout<<" Address: ";
    gets(address);
    cout<<" Phone No: ";
    gets(phone);
    while(strlen(phone) != 10)//checking validity of phone number
    {
        cout<<"\n Invalid Phone Number entered\n Enter  Phone No. again\t";
        gets(phone);
    }
    cout <<" Duration of stay:";
    cin>>days;
    cout<<"\n\n\t\t***** TYPES OF ROOMS *****\t\t\n\n";
    cout<<"\n\t1.\tSingle";
    cout<<"\n\t2.\tDouble";
    cout<<"\n\t3.\tDeluxe\n\n";
    cout<<"\n\t What is your choice of room ?\t"; // taking customer room choice as input using switch case
    cin>>ch;
	}
    switch(ch)
    {
        case 1: cost = 500 ;strcpy(room_type, "Single");break;
        case 2: cost = 1000;strcpy(room_type, "Double");break;
        case 3: cost = 2000;strcpy(room_type, "Deluxe");break;
        default: cout<<"\n wrong choice !!!!!!";flag = 0; //if none of the options are selected then room_type is null by default
    }

if(flag)
{
      if(strcmp(room_type, "Single")== 0) //the manager enters the room no. based on the room choice selection
        {
            cout<<"\n\n Enter a number between 300 and 350\t\t";
            cin>>r;
            while(r<300 || r>350)
            {
                cout<<"\n\n\n Invalid room no. entered, enter again\t\t";
                cin>>r;
            }
        }
        else if(strcmp(room_type, "Double")== 0) //the manager enters the room no. based on the room choice selection
        {
            cout<<"\n\n Enter a number between 400 and 435\t\t";
            cin>>r;
            while(r<400 || r>435)
            {
                cout<<"\n\n\n Invalid room no. entered, enter again\t\t";
                cin>>r;
            }
        }
        else if(strcmp(room_type, "Deluxe")== 0) //the manager enters the room no. based on the room choice selection
        {
            cout<<"\n\n Enter a number between 500 and 515\t\t";
            cin>>r;
            while(r<500 || r>515)
            {
                cout<<"\n\n\n Invalid room no. entered, enter again\t\t";
                cin>>r;
            }
        }
        flag = check(h, r); //checking whether room already alloted or not
     if(flag)
        {
            room_no = r;
        cout<<"\n Room has been booked!!! Have a pleasant stay !";
        }
     else
     {
         cout<<"\n Room is already booked, choose a new room\n\n\n\n\n";
         hotel ::counter--;
     }
}
cout<<"\n Press any key to continue!!";
}


void hotel::display() //displaying for one particular room number
{   if(room_no == 0)
{
    cout<<"\n Room has been Vacated";
}
else
{
    cout<<"\n Room no:"<<room_no;
    cout<<"\n Customer Name:"<<name;
    cout<<"\n Customer Address:"<<address;
    cout<<"\n Phone No.:"<<phone;
    cout<<"\n Duration of Stay:"<<days;
    cout<<"\n Type of Room:"<<room_type;
    cout<"\n\n Press Any key to continue";
}
}
void hotel::hotel_rooms() //listng out all customer records
{
    cout<<"\n\n "<<room_no<<"\t\t"<<name;
    cout<<"\t\t"<<address<<"\t\t"<<phone<<"\t\t"<<days<<"\t\t"<<room_type;


}

void hotel::edit(hotel*h, int j) // Editing a customer record
{
    int ch,r,flag;
    char type[10];
    strcpy(type,room_type);
    cout<<"\n Enter New Details";
    cout<<"\n *****************";
    cout<<"\n Name: ";
    gets(name);
    gets(name);
    cout<<" Address: ";
    gets(address);
    cout<<" Phone no: ";
    gets(phone);
    while(strlen(phone) != 10)//checking validity of phone number
    {
        cout<<"\n Invalid Phone Number entered\n Enter  Phone No. again\t";
        gets(phone);
    }
    cout<<"\n Duration of stay ?\t";
    cin >>days;
    cout<<"\n\n\t\t***** TYPES OF ROOMS *****\t\t\n\n";
    cout<<"\n\t1.\tSingle";
    cout<<"\n\t2.\tDouble";
    cout<<"\n\t3.\tDeluxe\n\n";
    cout<<"\n\t What is your choice of room ?\t";
    cin>>ch;
    switch(ch)
    {
        case 1: cost = 500 ;strcpy(room_type, "Single");break;
        case 2: cost = 1000;strcpy(room_type, "Double");break;
        case 3: cost = 2000;strcpy(room_type, "Deluxe");break;
        default: cout<<"\n wrong choice";
    }
    if(strcmp(type, room_type) != 0)//if room_choice is same as before then room no. is not changed
    {
       if(strcmp(room_type, "Single")== 0) //the manager enters the room no. based on the room choice selection
        {
            cout<<"\n\n Enter a number between 300 and 350\t";
            cin>>r;
            while(r<300 || r>350)
            {
                cout<<"\n\n\n Invalid room no. entered, enter again\t";
                cin>>r;
            }
        }
        else if(strcmp(room_type, "Double")== 0) //the manager enters the room no. based on the room choice selection
        {
            cout<<"\n\n Enter a number between 400 and 435\t";
            cin>>r;
            while(r<400 || r>435)
            {
                cout<<"\n\n\n Invalid room no. entered, enter again\t";
                cin>>r;
            }
        }
        else if(strcmp(room_type, "Deluxe")== 0) //the manager enters the room no. based on the room choice selection
        {
            cout<<"\n\n Enter a number between 500 and 515\t";
            cin>>r;
            while(r<500 || r>515)
            {
                cout<<"\n\n\n Invalid room no. entered, enter again\t";
                cin>>r;
            }
        }
        flag = check(h, r); //checking whether room already alloted or not
     if(flag)
        {
        room_no = r;
        cout<<"\n Record is modified!!";
        }
     else
     {
         cout<<"\n Room is already booked, choose a new room\n\n\n\n\n";
         hotel ::counter--;
     }

    }
     else
     {
         cout<<"\n Modified, room number is same as before";
     }


}

void hotel::delete_rec(hotel *p, int x )
{
	int flag=0;
	char choose ;


    cout<<"\n Name: "<<this->name;
    cout<<"\n Address: "<<this->address;
    cout<<"\n Pone No: "<<this->phone;
    cout<<"\n\n Do you want to delete this record(y/n): ";//ensuring that the user has not selected the wrong function
    cin>>choose;

			if(choose =='y')
			{
                int n = hotel ::counter;
                //shifting all the array elemnts starting with the array element whose room_no is equal to the required room number towards left, overwriting the array element to be deleted
                for(int k = x; k<n; k++)
                        p[k] = p[k+1];

                hotel ::counter --; // decrementing the counter variable since room has been vacated
                cout<<"\n\n Record Deleted !!";
			}
			else if(choose == 'n')//if user chooses not to delete then do nothing
            {
                cout<<"\n\n\n OK Press any key to continue";
            }
}

void cost (hotel *h)//friend function for calculating the cost of stay
{   char name[100],x[100];
    hotel k[100], m;
    int e =0, sum = 0;
    cout<<"\n Enter name \t";
    gets(x);
    gets(name);
    for(int j = 0; j<hotel::counter;j++)
        if(strcmpi(name, h[j].name) == 0)//if a customer has booked multiple rooms then calculates the total amount of money the customer should pay
            k[e++] = h[j];
    for(int j =0; j< e; j++)
        m += k[j]; //calling operator += function
    cout<<"\n The total cost of stay is :"<<"\t"<<m.cost;
}

int main()
{
	hotel h[100]; // creating and array of 100 elemts of class hotel
	cout<<"\n\t\t\t****************************";
	cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
	cout<<"\n\t\t\t****************************";
	cout<<"\n\n\n\n\t\tMade By:";
	cout<<" Anisha Pal";
	cout<<"\n\n\n\n\n\t\t\t\tPress any key to continue!!";
	main_menu(h); //calling the friend function of class hotel named main_menu
	return 0;
}


