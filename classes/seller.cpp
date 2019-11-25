//#include"user.cpp"
class Seller : public User{
    private :
        string shopname;
    public :
        void setSellerDetails(User, string);
        string getShopname();
        void showDetails();
};

void Seller :: setSellerDetails (User newUser, string shopname) {
        struct debitCard temp;
    temp.cardNumber = newUser.getCardNumber();
    temp.cvv = newUser.getCvv();
    (*this).setDetails(newUser.getName(), newUser.getUserType(), newUser.getUsername(), newUser.getMobileNumber(), newUser.getPassword(), temp);
    this -> shopname = shopname;
}

string Seller :: getShopname () {
    return this -> shopname;
}

void Seller :: showDetails () {
    cout << "Name : " << (*this).getName() << '\n';
    cout << "Username : " << (*this).getUsername() << '\n';
    cout << "Mobile Number : " << (*this).getMobileNumber() << '\n';
    cout << "Usertype : " << (*this).getUserType() << '\n';
    cout << "Card Number : " << (*this).getCardNumber() << '\n';
    cout << "Shopname : " << (*this).getShopname() << '\n';
}