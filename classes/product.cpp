class Product 
{
    public :
		string id;
		string name;
		double price;
		int quantity;
		double discount;
	
		void setDetails(string, string, double, int, double);
		string getId();
		string getName();
		double getPrice();
		int getQuantity();
		double getDiscount();
		void showDetails();
		void getProductDetails();
		void registerProduct();

};

void Product :: setDetails (string id, string name, double price, int quantity, double discount = 0.00) {
	this -> id = id;
	this -> name = name;
	this -> price = price;
	this -> quantity = quantity;
	this -> discount = discount;
	
}

string Product :: getId () {
	return &(this -> id[0]);
}
string Product :: getName () {
	return &(this -> name[0]);
}

double Product :: getPrice() {
	return this -> price;
}

int Product :: getQuantity () {
	return this -> quantity;
}

double Product :: getDiscount () {
	return this -> discount;
}

void Product :: showDetails () {
	cout << "Id : " << this -> id << '\n';
	cout << "Name : " << this -> name << '\n';
	cout << "Price : " << this -> price << '\n';
	cout << "Quantity : " << this -> quantity << '\n';
	cout << "Discount % : " << this -> discount << '\n';
}
void Product :: getProductDetails()
{
	
	

}
