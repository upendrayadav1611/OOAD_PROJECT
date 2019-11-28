#include "getchAndGetche.cpp"
#include "classes/user.cpp"
#include "classes/seller.cpp"
#include "classes/buyer.cpp"

int  loginMain();
int login();
int signup();
int authenticate(char[], char []);
string nameofShop(char[],char[]);
int loginMain () {
		//bool isAuthentic = false;
	cout << "1. Login" << endl;
	cout << "2. Signup" << endl;
	cout << "5. Exit"<<endl;
		char choice;
	cin >> choice;
	cout << "\033[2J\033[1;1H";
	switch(choice) {
		case '1' :
			return login();
			break;
		case '2' :
			return signup();
			break;
		case '5': exit(1);
		default :
			break;
	}
	return 0;
}

int  login () {
//	system("clear");
	cout << "Enter your Login Info :" << endl;
	cout << '\t' << "UserName :" << '\t';
			char username[100];
	cin >> username;

	// To clear input Buffer | taken from geeksforgeeks
    cin.ignore(numeric_limits<streamsize> :: max(), '\n');
	
	cout << '\t' << "Password :" << '\t';
		char password[21];
		char temp;
	for(int i = 0; i < 20; i++) 
	{
		temp = getch();
		if(temp == 10) 
		{
			password[i] = '\0';
			cout << endl;
			break;
		}
		else 
		{
			password[i] = temp;
			cout << '*';
		}
	}
	cout << "\033[2J\033[1;1H";
	return authenticate(username,password);
	
	
	//return 1; // Would be returning usertype in future
}

int signup () 
{
//	system("clear");
		User newUser;

	cout << '\t' << "Enter Name :" << '\t';
	string name;
	// To clear input buffer
	cin.ignore(numeric_limits<streamsize> :: max(), '\n');
	getline(cin, name);

	cout << '\t' << "Choose User Type (0-Buyer | 1-Seller):" << '\t';
	int userType;
	cin>>userType;
	cout << "\033[2J\033[1;1H";
	cout << '\t' << "Enter Username :" << '\t';
	char username[100];
	cin >> username;

	cout << '\t' << "Enter mobile Number :" << '\t';
	long mobileNumber;
	cin >> mobileNumber;

	cout << '\t' << "Enter Password :" << '\t';
	char password[21];
	// To clear input Buffer | taken from geeksforgeeks
    cin.ignore(numeric_limits<streamsize> :: max(), '\n');
	scanf("%[^\n]s", password);

	cout << '\t' << "Enter Debit Card Number :" << '\t';
	struct debitCard card;
	cin >> card.cardNumber;

	cout << '\t' << "Enter CVV :" << '\t';
	cin >> card.cvv;

	newUser.setDetails(name, userType, username, mobileNumber, password, card);
	cout << "\033[2J\033[1;1H";
	FILE *fp;
	fp=fopen("User.txt","a");
	fprintf(fp, "Name : %s | userType : %d | Username : %s | Mobile No : %ld | Password : %s | Card Number : %ld | CVV : %i", newUser.getName().c_str(), newUser.getUserType(), newUser.getUsername().c_str(), newUser.getMobileNumber(), newUser.getPassword(), newUser.getCardNumber(),newUser.getCvv());
	fclose(fp);
	if(newUser.getUserType()) {
			Seller newSeller;
		cout << '\t' << "Enter Shopname :" << '\t';
			string shopname;
		cin >> shopname;
		newSeller.setSellerDetails(newUser, shopname);
		FILE *fp;
		fp=fopen("Seller.txt","w");
		fprintf(fp,"Shop name : %s | Name : %s | Username : %s | Mobile No : %ld | Password : %s | Card Number : %ld | CVV : %i", newSeller.getShopname().c_str(), newUser.getName().c_str(), newUser.getUsername().c_str(), newUser.getMobileNumber(),newUser.getPassword(), newUser.getCardNumber(), newUser.getCvv());
		fclose(fp);
//		newSeller.showDetails();
		
	}else {
			Buyer newBuyer;
		cout << '\t' << "Enter House number :" << '\t';
			Address add;
		cin >> add.houseNo;

		// To clear input Buffer | taken from geeksforgeeks
		cin.ignore(numeric_limits<streamsize> :: max(), '\n');
		cout<<'\t'<<"Enter Locality :"<<"\t";
		cin>>add.locality;
		cout << '\t' << "Enter City :" << '\t';
		cin >> add.city;

		cout << '\t' << "Enter State :" << '\t';
		cin >> add.state;

		cout << '\t' << "Enter PinCode :" << '\t';
		cin >> add.pinCode;

		newBuyer.setBuyerDetails(newUser, add);
		FILE *fp;
		fp=fopen("Buyer.txt","w");
		fprintf(fp,"Name : %s | username : %s |  Mobile No. : %ld | Password : %s | Card Number : %ld | CVV : %hi | House No. : %s | Locality : %s | City : %s | State : %s | Pincode : %d",newUser.getName().c_str(),newUser.getUsername().c_str(), newUser.getMobileNumber(),newUser.getPassword(), newUser.getCardNumber(), newUser.getCvv(),newBuyer.getHouseNo().c_str(),newBuyer.getLocality().c_str(),newBuyer.getCity().c_str(),newBuyer.getState().c_str(),newBuyer.getPincode());
		fclose(fp);
//		newBuyer.showBuyerDetails();
	}

	cout << '\n' << "Account Created!" << endl;
	strcpy(globalUser,username);
//	system("clear");
	return userType;
}

int  authenticate (char Username[], char Password[]) 
{
	FILE *fp;
	char password[21];
	int userType;
	char name[100];
	char username[100];
	long mobileNumber;
	long cardNumber;
	short cvv;
	fp=fopen("User.txt","r");
	while(!feof(fp))
	{
		fscanf(fp, "Name : %s | userType : %d | Username : %s | Mobile No : %ld | Password : %s | Card Number : %ld | CVV : %hi", name,&userType, username, &mobileNumber,password ,&cardNumber,&cvv);
		if(strcmp(username,Username)==0&&strcmp(Password,password)==0)
		{
			strcpy(globalUser,username);
			return userType;
		}
	}
	return -1;
}

/*string nameofShop(char Username[] , char Password[])
{
	FILE *fp;
	char shopname[100];
	char password[21];
	int userType;
	char name[100];
	char username[100];
	long mobileNumber;
	long cardNumber;
	short cvv;
	fp=fopen("Seller.txt","r");
	while(!feof(fp))
	{
		fscanf(fp, "Shop Name : %s | Name : %s | Username : %s | Mobile No : %ld | Password : %s | Card Number : %ld | CVV : %hi", shopname,name, username, &mobileNumber,password ,&cardNumber,&cvv);
		if(strcmp(username,Username)==0&&strcmp(Password,password)==0)
		{
			return shopname;
		}
	}
	return NULL;
	
}*/