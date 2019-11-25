struct Address {
    string houseNo;
    string locality;
    string city;
    string state;
    int pinCode;
};

class Buyer:public User {   
    private:
        Address buyerAddress;
    public:
    void setBuyerDetails(User, Address);
    void showBuyerDetails();
};

void Buyer :: setBuyerDetails (User newUser, Address add) {
        debitCard temp;
    temp.cardNumber = newUser.getCardNumber();
    temp.cvv = newUser.getCvv();
    this -> buyerAddress = add;
    (*this).setDetails(newUser.getName(), newUser.getUserType(), newUser.getUsername(), newUser.getMobileNumber(), newUser.getPassword(), temp);
}

void Buyer::showBuyerDetails() {
    cout<<"Name:  "<<this->getName()<<"\n";
    cout<<"Mobile no:  "<<this->getMobileNumber()<<"\n";
    cout<<"Address: "<<"\n"<<this->buyerAddress.houseNo<<" "<<this->buyerAddress.locality<<"\n"<<this->buyerAddress.city<<", "<<this->buyerAddress.state<<"\n"<<this->buyerAddress.pinCode<<"\n";
}