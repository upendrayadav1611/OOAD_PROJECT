struct debitCard {
	long cardNumber;
	short cvv;
};

class User {
	private :
		char password[21];
		int userType;
	public :
		void setDetails(string, int, string, long, char [], struct debitCard);
		string getName();
		string getUsername();
		long getMobileNumber();
		long getCardNumber();
		short getCvv();
		int getUserType();
		char * getPassword();
	protected :
		string name;
		string username;
		long mobileNumber;
		struct debitCard card;
};

void User :: setDetails(string name, int userType, string username, long mobileNumber, char password[], struct debitCard card) {
	this -> name = name;
	this -> userType = userType;
	this -> username = username;
	this -> mobileNumber = mobileNumber;
	strcpy(this -> password,  password);
	this -> card.cardNumber = card.cardNumber;
	this -> card.cvv = card.cvv;
}

string User :: getName () {
	return this -> name;
}

string User :: getUsername () {
	return this -> username;
}

long User :: getMobileNumber () {
	return this -> mobileNumber;
}

long User :: getCardNumber () {
	return this -> card.cardNumber;
}

short User :: getCvv () {
	return this -> card.cvv;
}

int User :: getUserType () {
	return this -> userType;
}

char * User :: getPassword() {
	return this -> password;
}
