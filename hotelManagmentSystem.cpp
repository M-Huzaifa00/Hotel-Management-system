#include<iostream> // TO USE INPUT AND OUTPUT STEAMS LIKE COUT AND CIN
#include<iomanip> // TO SET WIDTH LIKE SPACES MANUALLY LIKE SETW()
#include<math.h> // TO PERFORM MATHS OPERATIONS LIKE POW();
#include<fstream> //TO PERFORM FILE HANDLING
#include <unistd.h> // TO ADD DELAY IN ELSE FUNCTION (SLEEP FUN FROM THIS LIBRARY)
#include<stdio.h> // TO RENAME AND REMOVE FILE
using namespace std ;// namespace standards 
struct ExitMessage{ // implementation of structure or userDefineDataType

char exit[11] = "...EXIT..."; // implementation of array

} exitDisplay; // name of userDefine data type
 
int choiceForAdminAndUserPanel; // check which panel does user want to access
void userEmptyRoomDetailsGiver(); // This is for user function that contain all code about managing and checking empty room
void emptyRoomDetailsGiver(); // same as user but bit secured 
void hMS();// hostel managment system display code store in it
void adminUser(); //  admin display store in it
void beforeAdminPanel(); // this is for security purpose to check is relly admin is loggin in
void adminPanel();// contain admin display and admin see it after passing beforeAdminPanel
void userPanel(); // contain display of user
void adminRecordAdding(); // this function operates by admin to add user record
void adminCheckRecord(); // only for admin to check all records
void adminSearchRoomByName(); // admin search any room by his customer name
void searchRoomByNameUser(); // this fun is for user to search nroom no by their name
void adminDeleteRec(); // this func is only available for admin to delete records when user check out
void rooMPricingAndCategory(); // this is for user to see room prising acc to room category
void totalPaymentManager(); // this fun is sot of back bone which manage all payment it mostly communicate with global varies
int roomSelection = 0 ; //Golobal varibal in which user select room and admin can see through it in assign room panel if user select room admin can give it if it free other wise any room of that catagory
int adminChecker = 0 ; // making global variable to update it for functions as well as main function
int totalPayment = 0 ; // Gb to use it in multiple functions for increment and decrement 
int paymentOfUser1 = 0 ; // Gb to use it in multiple functions for increment and decrement 
int paymentOfUser2 = 0 ; // Gb to use it in multiple functions for increment and decrement 
int paymentOfUser3 = 0 ; // Gb to use it in multiple functions for increment and decrement 
int paymentOfUser4 = 0 ; // Gb to use it in multiple functions for increment and decrement 
int emptyRoom = 0 ; // Gb to use it in multiple functions for increment and decrement 
int gChoice , uChoice  ; // Gb to communicate throgh multiple functions 
int totalRoom = 20 ; // Gb to use it in multiple functions for increment and decrement 
int normalRoom = 0 , acRoom = 0 , masterRoom = 0 , luxuaryRoom = 0 ; // Gb to use it in multiple functions for increment and decrement 
int main(){
 hMS();
 adminUser(); // display basic menu 
 if ( choiceForAdminAndUserPanel == 1 ) // for admin
 {
	beforeAdminPanel(); // security to check is u are real admin or not
	if ( adminChecker == 1 ) // successfull check if u are admin
	{
		cout << " log-In Successfull...!\a" << endl ; // a escape seq-for-beep sound
		sleep(1); // time delay 
		bool flag = true ;
		while ( flag ) // for the sake of user Control
		{ 
			system("cls");  // clears previous screen to make neat and clean
			adminPanel(); // here is ur admin panel cz u successfully pass admin test
			switch (gChoice) // global variable and check which action admin wants to perform
		 {
		  case 0 : // to exit admin panel and back to home screen
		  system("cls");
		  return main();
		  break;
		  case 3 : // for record adding
		  adminRecordAdding();
		  break;
		  case 1: // for checking all records
		  adminCheckRecord(); 
		  break;
		  case 4: // for searching user by his name
		  adminSearchRoomByName();
		  break;
		  case 2: // for deletion of records
		 adminDeleteRec();
		 break;
		 case 6: // for checking payments
		totalPaymentManager();
		break;
		case 5 : // for checking empty rooms to assign correct room
		emptyRoomDetailsGiver();
		break;

		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls"); // for cleaning previous code 
			continue;  // moving control back to loop start
			break; // switch break 
		}
		}
		
	}
	else // if u do not pass beforeAdminpPanel u will he here
	{ 
        cout << "Invalid ID or Password " << endl ;
		int choice ;
		bool flag = true ;
		bool mainBreakChecker = true ;
		int loginCheck = 0 ;
		while (flag) // Used to deal with admin login failed error
		{  
			cout << endl ;
			cout << "Press 1 to enter ID or Paasowrd again" << endl ;
		    cout << "Press 0 to enter go back " << endl ;
			cin >> choice ;
			if ( choice == 1 )
	    	{
			system("cls");
			beforeAdminPanel(); // to check u r admin or not 
			if (adminChecker == 1 )
			{  
				loginCheck = 1 ;
				break; // if u are admin then this loop breaks here and u will go directly out of loop code which is admin panel
			}
		 }
		 else if(choice == 0 ) // for moving  back to home screen
		 {
			mainBreakChecker = false ;
			break;
			
		 }
		 else{
			cout << " wrong entry try again!";
			continue;
		 }
		}

		if(  mainBreakChecker == false )
		{
			system("cls");
			 main();
		}
		if ( loginCheck==1 )
		{
			 while ( true ) // if u pass beforeAdminPanel
		{  
			system("cls");
			adminPanel(); // this is same as up just here to control user flow nicely
			switch (gChoice)
		 {
		  case 0 :
		  system("cls");
		  main();
		  break;
		  case 3 :
		  adminRecordAdding();
		  break;
		  case 1:
		  adminCheckRecord();
		  break;
		  case 4:
		  adminSearchRoomByName();
		  break;
		  case 2:
		 adminDeleteRec();
		 break;
		 case 6:
		totalPaymentManager();
		break;
		case 5 :
		emptyRoomDetailsGiver();
		break;

		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls");
			continue;
			break;
		}
		}
		 
		}
		
		 
	}
 }
 else if ( choiceForAdminAndUserPanel == 2 ) // for userPanel
 {  
	
	while ( true ) // to control userFlow
	{
	system("cls"); // used to clear previous things from screen  
	userPanel(); // func thats display choices to user
	switch ( uChoice  )
	{
	case 1: // On pressing 1 from keyboard 
    searchRoomByNameUser();  // user gets this fun functionalites
	break;
	case 0: // On pressing 0 from keyboard 
	system("cls");
	return main(); // user move back to home screen
	break;
	case 3: // On pressing 3 from keyboard 
	rooMPricingAndCategory(); // user gets this fun functionalites
	break;
	case 2 : // On pressing 2 from keyboard 
	userEmptyRoomDetailsGiver(); // user gets this fun functionalites
	break;
	default:
	cout << "Invalid-Entry!" << endl ;
	cout << " Try-Again...!";
	sleep(1); // Used to add time delay to display error message and then clear old screen
	system("cls");
	continue; // move control start of loop to show again userPanel
	break;
   }
	}
	
 }
 else if (choiceForAdminAndUserPanel == 0) // to exit program
 {
	int i = 0 ;
	while (exitDisplay.exit != '\0')
	{
		sleep(1);
		cout << exitDisplay.exit[i];
		i++;
		if(exitDisplay.exit == '\0')
		{
			break;
		}
	}
	exit(0); // 0 incicates successfully termination of program so exit(0) terminate or close code without executing rest of code || force exit
 }
 else
 {
	cout << "No Panel available For your Entry " << endl ;
	cout << "Invalid Entry ! " << endl ;
	cout << "Try-Again......" << endl ;
	sleep(1); // Give us one second of delay...
	system("cls");
	main();
 }
	return 0;
}
void hMS(){ // just a interface 
	cout << "\t\t\t\t________________________________" << endl ;
	cout << endl;
	cout << "\t\t\t       |                                |" << endl ;
	cout << "\t\t\t       |                                |" << endl ;
	cout << "\t\t\t       |         WELLCOME---COME        |" << endl ;
	cout << "\t\t\t       |                 TO             |" << endl ;
	cout << "\t\t\t       |      HOTEL-MANAGMENT-SYSTEM    |" << endl ;
	cout << "\t\t\t       |                                |" << endl ;
	cout << "\t\t\t       |                                |" << endl ;
	cout << "\t\t\t\t________________________________" << endl ;
}
void adminUser(){ // gets input from both user and admin to make sure he/she is admin or user
	cout << "\t\t\t\t Press 1 to access Admin-Panel " << endl ;
	cout << "\t\t\t\t Press 2 to access User-Panel " << endl ;
	cout << "\t\t\t\t Press 0 to Exit " << endl ;
	cout << "\t\t\t\t Choose one of them: " << endl ;
	cin >> choiceForAdminAndUserPanel ;
}
void adminPanel(){ // gets choice from admin to perform tasks for admin
	cout << "\t\t\t_______ADMIN-PANEL______ " << endl ;
	cout << "\t\t\t Press 1 to check record " << endl ;
	cout << "\t\t\t Press 2 to delete specfic record " << endl ;
	cout << "\t\t\t Press 3 to assign room to customer " << endl ;
	cout << "\t\t\t Press 4 to find room-no of customer " << endl ;
	cout << "\t\t\t Press 5 to view empty rooms " << endl ;
	cout << "\t\t\t Press 6 to check total payment " << endl ;
	cout << "\t\t\t Press 0 to go back " << endl ;
	cout << "\t\t\t Select one ot these:";
	cin >> gChoice ;
}
void beforeAdminPanel(){ // this func make sure only admin can access admin panel sot of security check
	ofstream adminCreate("admin.txt");
	adminCreate <<"IAmAdmin"<<" "<<"12345"<<endl;
	adminCreate.close();
	ifstream readAdmin("admin.txt",ios::in);
	string adminID,adminPassword,AID,APass;
	cout << "Enter Admin User-Name to login Admin panel:";
	cin >> adminID;
	cout << "Enter Admin Password to login Admin panel:";
	cin >> adminPassword ;
	while ( readAdmin >> AID >> APass)
	{
		if ( adminID == AID && adminPassword == APass )
		{
			adminChecker = 1;
		}
	}
	readAdmin.close();
}
void userPanel(){ // for getting choice from user 
	cout << "\t\t\t_______USER-PANEL________________ " << endl ;
	cout << "\t\t\t Press 1 to check Room-No by Name " << endl ;
	cout << "\t\t\t Press 2 to view Empty room " << endl ;
	cout << "\t\t\t Press 3 to see Catagory and Room Prices " << endl ;
	cout << "\t\t\t Press 0 to go back " << endl ;
	cout << "\t\t\t select one of these " << endl ;
	cin >> uChoice ;
}
void adminRecordAdding(){ // for admin use only to add records
	ofstream recordMake;
	recordMake.open("records.txt",ios::app|ios::out);
	string name,id;
	int roomNo,days;
	bool flag = true ;
	int roomChecker = 0 ;
	if (recordMake.is_open())
	{
		while ( flag )
	{ 
		roomChecker++;
		if ( roomChecker == 20 )
		{
			cout << "No more room left...!" << endl ;
			cout << "Wait for Customer CheckOut " << endl ;
			sleep(2);
			system("cls");
			main();
		}
		cout << "Enter Name of Customer:";
		cin >> name ;
		cout << "Enter ID of customer:";
		cin >> id ;
		cout << "Assign Room-No to Customer:";
		cin >> roomNo ;
		cout << "Enter how many days he wants to stay:";
		cin >> days ;
		if( roomNo>20 ){
			cout << "Wrong input because your hotel has only 20 rooms"<<endl;
			sleep(2);//To add time delay
			main();
		}
		if (roomNo>=1 && roomNo<=5)
		{
			const int roomOneToFive = 3000 ; // room price
			paymentOfUser1 = days*roomOneToFive;
			totalPayment += paymentOfUser1;
			emptyRoom++; // 
			normalRoom++;
			recordMake<<id<<' '<<name<<' '<<roomNo<<' '<<paymentOfUser1<<endl;
		}
		else if (roomNo>5 && roomNo<=10)
		{
			const int roomOneToFive = 6000 ; // room price
			paymentOfUser2 = days*roomOneToFive; // room price calculator 
			totalPayment += paymentOfUser2;
			emptyRoom++;
			acRoom++;
			recordMake<<id<<' '<<name<<' '<<roomNo<<' '<<paymentOfUser2<<endl;
		}
		else if (roomNo>10 && roomNo<=15)
		{
			const int roomOneToFive = 9000 ; // room price
			paymentOfUser3 = days*roomOneToFive; // room price calculator 
			totalPayment += paymentOfUser3;
			emptyRoom++;
			masterRoom++;
			recordMake<<id<<' '<<name<<' '<<roomNo<<' '<<paymentOfUser3<<endl;
		}
		else if (roomNo>15 && roomNo<=20)
		{
			const int roomOneToFive = 12000 ; // room price
			paymentOfUser4 = days*roomOneToFive; // room price calculator 
			totalPayment += paymentOfUser4;
			emptyRoom++;
			luxuaryRoom++;
			recordMake<<id<<' '<<name<<' '<<roomNo<<' '<<paymentOfUser4<<endl;
		}
		cout << " Record Added successfully! " << endl ;
		int choice;
		cout << "Press 1 to add more records " << endl ;
		cout << "Press 2 to exit " << endl ;
		cin >> choice ;
		if ( choice==1 )
		{
			continue;
		}
		else{
			system("cls");
			while ( true )
		{  
			adminPanel();
			switch (gChoice)
		 {
		  case 0 :
		  system("cls");
		  main();
		  break;
		  case 3 :
		  adminRecordAdding();
		  break;
		  case 1:
		  adminCheckRecord();
		  break;
		  case 4:
		  adminSearchRoomByName();
		  break;
		  case 2:
		 adminDeleteRec();
		 break;
		 case 6:
		totalPaymentManager();
		break;
		case 5 :
		emptyRoomDetailsGiver();
		break;

		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls");
			continue;
			break;
		}
		}
		}
	}
	recordMake.close();
	}
	else
	{
		cout << "File opening error!";
	}
	
}
void adminCheckRecord(){
	ifstream recordReader;
	recordReader.open("records.txt",ios::in);
	string tempName,tempID;
	int tempRN,cusPay;
	cout <<"\t\t\t\t" << "Cus-ID" <<setw(15)<< "Cus-Name" <<setw(15)<< "Cus-RoomNo" <<setw(15)<<"Cus-Payment"<< endl ;
	while (recordReader>>tempID>>tempName>>tempRN>>cusPay)
	{
		cout<<"\t\t\t\t"<<tempID<<setw(16)<<tempName<<setw(14)<<tempRN<<setw(15)<<cusPay<<endl ;
		
	}
	recordReader.close();
	while(true){
	cout << endl;
	cout <<"Press 1 to go back " << endl ;
	int option;
	cin>>option;
	if ( option == 1)
	{
		while ( true )
		{ 
			system("cls"); 
			adminPanel();
			switch (gChoice)
		 {
		  case 0 :
		  system("cls");
		  main();
		  break;
		  case 3 :
		  adminRecordAdding();
		  break;
		  case 1:
		  adminCheckRecord();
		  break;
		  case 4:
		  adminSearchRoomByName();
		  break;
		  case 2:
		 adminDeleteRec();
		 break;

		
		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls");
			continue;
			break;
		}
		}
	}
	else{
		cout << "wrong entry!" << endl;
		cout << "Try again" ;
		sleep(2);
		system("cls");
		continue;
	}
	}
}
 void adminSearchRoomByName(){
	ifstream searching;
	int signal = 0 ;
	searching.open("records.txt",ios::in);
	string tempName,tempID,tempCusName;
	int tempRoomNo;
	cout << "Enter customer name to find Room-No of particular customer:";
	cin>>tempCusName;
	while (searching>>tempID>>tempName>>tempRoomNo)
	{
		if (tempName==tempCusName)
		{ 
			cout << endl ;
			cout << "Room-No of ["<<tempName<<"] is:"<<tempRoomNo<<endl;
			signal = 1 ;
			sleep(5);
			system("cls");
		}
	}
	if ( signal == 0 )
	{
		cout << "No Customer find with the name:" << tempCusName ;
		sleep(3);
		system("cls");
		
	}
}
void searchRoomByNameUser(){
	ifstream searching; // Used to read records from file
	int signal = 0 ;
	searching.open("records.txt",ios::in); // iso | input output and in stands for input 
	string tempName,tempID,tempCusName; 
	int tempRoomNo;
	cout << "Enter your name to find your room-no:";
	cin>>tempCusName;
	while (searching>>tempID>>tempName>>tempRoomNo) // searching is obj name in which rec file is open and transfring data from rec vars
	{
		if (tempName==tempCusName)
		{ 
			cout << endl ;
			cout << "Your Room-No is:"<<tempRoomNo<<endl;
			signal = 1 ;
		}
	}
	if ( signal == 0 )
	{
		cout << "Invalid name....!" << tempCusName ;
		sleep(3);
		system("cls");
		while ( true )
	{
	userPanel();
	switch ( uChoice  )
	{
	case 1:
    searchRoomByNameUser();
	break;
	case 0:
	main();
	break;
	case 3:
	rooMPricingAndCategory();
	break;
	case 2 :
	emptyRoomDetailsGiver();
	break;
	default:
	cout << "Invalid-Entry!" << endl ;
	cout << " Try-Again...!";
	sleep(1); // Used to add time delay to display error message and then clear old screen
	system("cls");
	continue;
	break;
   }
	}
	}
}
void adminDeleteRec(){
	ofstream tempHolder; // temp file for holding all data expect of which we want to delet
	tempHolder.open("temp.txt",ios::out|ios::app); // out : output and app means append its help to dont overwrite again and again
	ifstream read;
	read.open("records.txt",ios::in); 
	string iD,name,rN,tempName;
	int tempRNo;
	cout << "Enter name of which you wanna delete record:";
	cin >> tempName ;
	cout << "Enter name of whome you want to delete record:";
	cin>>tempRNo;
	if(tempRNo <= 20 ){
		if (tempRNo>=1 && tempRNo<=5 )
		{
		
			normalRoom--;
			totalRoom--;

		}
		else if (tempRNo>5 && tempRNo<=10 )
		{

			acRoom--;
			totalRoom--;
		}
		else if (tempRNo>10 && tempRNo<=15 )
		{
			
			masterRoom--;
			totalRoom--;


		}
		else if (tempRNo>15 && tempRNo<=20 )
		{
			luxuaryRoom--;
			totalRoom--;
	
		};
	}
	else {
		cout << "invalid entry !" ;
		sleep(3);
		system("cls");
		main();
	}
	bool userFoundChecker = true ;
	while ( read>>iD>>name>>rN )
	{
		if( tempName == name ){
			cout << "Record-Deleted-Successfully...!";
			sleep(2);
			system("cls");
			userFoundChecker = false ;
		}
		else{
			tempHolder<<iD<<" "<<name<<" "<<rN<<endl;
		}
	}
	if ( userFoundChecker == true )
	{
		cout << " No such userFound in Data-Base...!";
		sleep(4);
		system("cls");
			while ( true )
		{  
			adminPanel();
			switch (gChoice)
		 {
		  case 0 :
		  system("cls");
		  main();
		  break;
		  case 3 :
		  adminRecordAdding();
		  break;
		  case 1:
		  adminCheckRecord();
		  break;
		  case 4:
		  adminSearchRoomByName();
		  break;
		  case 2:
		 adminDeleteRec();
		 break;
		 case 6:
		totalPaymentManager();
		break;
		case 5 :
		emptyRoomDetailsGiver();
		break;

		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls");
			continue;
			break;
		}
		}
	}
	
	tempHolder.close();
	read.close();
	remove("records.txt"); // after extracting all records from this to temp then deleting it
	rename("temp.txt","records.txt"); // and renaming temp into recs to perform this agation each time
}
void rooMPricingAndCategory(){ // this func is for user panel to display prices 
	cout << "\t\t\t\t\t Total-20-Rooms" << endl ;
	cout << "\t\t\t Normal-Rooms[ 1 - 5 ] || Price-Per-Night = 3000-[PKR] " << endl ;
	cout << "\t\t\t AC-Rooms [ 6 - 10 ]   || Price-Per-Night = 6000-[PKR]" << endl ;
	cout << "\t\t\t Master-Rooms[ 11 - 15 || Price-Per-Night = 9000-[PKR] " << endl ;
	cout << "\t\t\t Luxury-Rooms[ 16 - 20]|| Price-Per-Night = 12000-[PKR] " << endl ;
	cout << "\t\t\t Press 0 to go back" ;
	int optionInRPAC ;
	cin >> optionInRPAC ;
	if ( optionInRPAC == 0 )
	{
		while ( true )
	{
	system("cls");
	userPanel();
	switch ( uChoice  )
	{
	case 1:
    searchRoomByNameUser();
	break;
	case 0:
	system("cls");
	main();
	break;
	case 3:
	rooMPricingAndCategory();
	break;
	case 2 :
	emptyRoomDetailsGiver();
	break;
	default:
	cout << "Invalid-Entry!" << endl ;
	cout << " Try-Again...!";
	sleep(1); // Used to add time delay to display error message and then clear old screen
	system("cls");
	continue;
	break;
   }
	}
	
	}
	else{
		system("cls");
		main();
	}
	

}
void totalPaymentManager(){
cout <<"\t\t\t Total-Payment till now is:"<<totalPayment<<endl;
cout <<"\t\t\t Press 1 to reset Total payment"<<endl;
cout <<"\t\t\t Press 2 to remove payment according to Room-Check out"<<endl;
cout <<"\t\t\t Press 0 to go back"<<endl;
while ( true )
{
	int choice;
	cin>>choice;
	if(choice == 1 )
	{
		totalPayment = 0 ;
		cout << " Reset-Successfully..!"<<endl;
		sleep(3);

		while ( true )
		{  
			system("cls");
			adminPanel();
			switch (gChoice)
		 {
		  case 0 :
		  system("cls");
		  main();
		  break;
		  case 3 :
		  adminRecordAdding();
		  break;
		  case 1:
		  adminCheckRecord();
		  break;
		  case 4:
		  adminSearchRoomByName();
		  break;
		  case 2:
		 adminDeleteRec();
		 break;
		 case 6:
		totalPaymentManager();
		break;
		case 5 :
		emptyRoomDetailsGiver();
		break;

		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls");
			continue;
			break;
		}
		}
	}
	else if (choice==2)
	{
		cout << "Enter room from which user check out:";
		int roomN;
		cin >> roomN;
		if (roomN>=1 && roomN<=5 )
		{
			totalPayment - paymentOfUser1 ;
			cout << "Total payment becomes:"<<totalPayment;
			normalRoom--;
			sleep(3);
			system("cls");
			while ( true )
		{  
			adminPanel();
			switch (gChoice)
		 {
		  case 0 :
		  system("cls");
		  main();
		  break;
		  case 3 :
		  adminRecordAdding();
		  break;
		  case 1:
		  adminCheckRecord();
		  break;
		  case 4:
		  adminSearchRoomByName();
		  break;
		  case 2:
		 adminDeleteRec();
		 break;
		 case 6:
		totalPaymentManager();
		break;
		case 5 :
		emptyRoomDetailsGiver();
		break;

		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls");
			continue;
			break;
		}
		}

		}
		else if (roomN>5 && roomN<=10 )
		{
			totalPayment - paymentOfUser2 ;
			cout << "Total payment becomes:"<<totalPayment;
			acRoom--;
			sleep(3);
			system("cls");
			while ( true )
		{  
			adminPanel();
			switch (gChoice)
		 {
		  case 0 :
		  system("cls");
		  main();
		  break;
		  case 3 :
		  adminRecordAdding();
		  break;
		  case 1:
		  adminCheckRecord();
		  break;
		  case 4:
		  adminSearchRoomByName();
		  break;
		  case 2:
		 adminDeleteRec();
		 break;
		 case 6:
		totalPaymentManager();
		break;
		case 5 :
		emptyRoomDetailsGiver();
		break;

		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls");
			continue;
			break;
		}
		}

		}
		else if (roomN>10 && roomN<=15 )
		{
			totalPayment - paymentOfUser3 ;
			cout << "Total payment becomes:"<<totalPayment;
			masterRoom--;
			sleep(3);
			system("cls");
			while ( true )
		{  
			adminPanel();
			switch (gChoice)
		 {
		  case 0 :
		  system("cls");
		  main();
		  break;
		  case 3 :
		  adminRecordAdding();
		  break;
		  case 1:
		  adminCheckRecord();
		  break;
		  case 4:
		  adminSearchRoomByName();
		  break;
		  case 2:
		 adminDeleteRec();
		 break;
		 case 6:
		totalPaymentManager();
		break;
		case 5 :
		emptyRoomDetailsGiver();
		break;

		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls");
			continue;
			break;
		}
		}

		}
		else if (roomN>15 && roomN<=20 )
		{
			totalPayment - paymentOfUser4 ;
			cout << "Total payment becomes:"<<totalPayment;
			luxuaryRoom--;
			sleep(3);
			system("cls");
			while ( true )
		{  
			adminPanel();
			switch (gChoice)
		 {
		  case 0 :
		  system("cls");
		  main();
		  break;
		  case 3 :
		  adminRecordAdding();
		  break;
		  case 1:
		  adminCheckRecord();
		  break;
		  case 4:
		  adminSearchRoomByName();
		  break;
		  case 2:
		 adminDeleteRec();
		 break;
		 case 6:
		totalPaymentManager();
		break;
		case 5 :
		emptyRoomDetailsGiver();
		break;

		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls");
			continue;
			break;
		}
		}
		}
		else{
			cout << "You enter more than 20 while your hotel has only 20 rooms!";
			sleep(5);
			system("cls");
			while ( true )
		{  
			adminPanel();
			switch (gChoice)
		 {
		  case 0 :
		  system("cls");
		  main();
		  break;
		  case 3 :
		  adminRecordAdding();
		  break;
		  case 1:
		  adminCheckRecord();
		  break;
		  case 4:
		  adminSearchRoomByName();
		  break;
		  case 2:
		 adminDeleteRec();
		 break;
		 case 6:
		totalPaymentManager();
		break;
		case 5 :
		emptyRoomDetailsGiver();
		break;

		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls");
			continue;
			break;
		}
		}
		}
	}
	else if (choice == 0)
	{
		system("cls");
		while ( true )
		{  
			adminPanel();
			switch (gChoice)
		 {
		  case 0 :
		  system("cls");
		  main();
		  break;
		  case 3 :
		  adminRecordAdding();
		  break;
		  case 1:
		  adminCheckRecord();
		  break;
		  case 4:
		  adminSearchRoomByName();
		  break;
		  case 2:
		 adminDeleteRec();
		 break;
		 case 6:
		totalPaymentManager();
		break;
		case 5 :
		emptyRoomDetailsGiver();
		break;

		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls");
			continue;
			break;
		}
		}
	}
	else{
		cout << "Invalid entry"<<endl;
		cout << " Try again!";
		continue;
     }

}
}
void emptyRoomDetailsGiver() // this func is only for admin cz its contain info that is not for user 
{
	int currentAvailableRoom = totalRoom - emptyRoom ;
    int allRoom = 5 ;;
	int NR = allRoom - normalRoom ;
	int acR = allRoom - acRoom ;
	int MR = allRoom - masterRoom ;
	int luxR = allRoom - luxuaryRoom ;
	cout << "Total-Rooms : 20" << endl ; 
	cout << "Total Empty Room  Left : " << currentAvailableRoom << endl ;
	cout << "Total Normal Room Left : " << NR << endl ;
	cout << "Total AC Room Left : " << acR << endl ;
	cout << "Total Master Room Left : " << MR << endl ;
	cout << "Total Luxuary Room Left : " << luxR << endl ;
	cout << "Press 0 to exit :" ;
		int back ;
	cin >> back ;
	if( back== 0 )
	{
	 while ( true )
		{  system("cls");
			adminPanel();
			switch (gChoice)
		 {
		  case 0 :
		  system("cls");
		  main();
		  break;
		  case 3 :
		  adminRecordAdding();
		  break;
		  case 1:
		  adminCheckRecord();
		  break;
		  case 4:
		  adminSearchRoomByName();
		  break;
		  case 2:
		 adminDeleteRec();
		 break;
		 case 6:
		totalPaymentManager();
		break;
		case 5 :
		emptyRoomDetailsGiver();
		break;

		    default:
			cout << "Invalid-Entry!" << endl ;
			cout << " Try-Again...!";
			sleep(1); // Used to add time delay to display error message and then clear old screen
			system("cls");
			continue;
			break;
		}
		}
	}
	else{
		system("cls");
		main();
	}
}
void userEmptyRoomDetailsGiver() // this is for user panel
{
	int currentAvailableRoom = totalRoom - emptyRoom ;
    // int allRoom = 5 ;
	int NR = 5 - normalRoom ;
	int acR = 5 - acRoom ;
	int MR = 5 - masterRoom ;
	int luxR = 5 - luxuaryRoom ;
	cout << "Total-Rooms : 20" << endl ; 
	cout << "Total Empty Room  Left : " << currentAvailableRoom << endl ;
	cout << "Total Normal Room Left : " << NR << endl ;
	cout << "Total AC Room Left : " << acR << endl ;
	cout << "Total Master Room Left : " << MR << endl ;
	cout << "Total Luxuary Room Left : " << luxR << endl ;
	cout << "Press 0 to exit :" ;
	int back ;
	cin >> back ;
	if( back == 0 )
	{
	while ( true )
	{
	system("cls");
	userPanel();
	switch ( uChoice  )
	{
	case 1:
    searchRoomByNameUser();
	break;
	case 0:
	system("cls");
	main();
	break;
	case 3:
	rooMPricingAndCategory();
	break;
	case 2 :
	userEmptyRoomDetailsGiver();
	break;
	default:
	cout << "Invalid-Entry!" << endl ;
	cout << " Try-Again...!";
	sleep( 2 ); // Used to add time delay to display error message and then clear old screen
	system("cls");
	continue;
	break;
   }
	}
	}
	else{
		system("cls");
		main();
	}
}