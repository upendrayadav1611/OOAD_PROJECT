int pos=1;
void showStocks();
void buyProducts();
void showGeneral();
void showGrocery();
void showFoodItems();
void showGarments();
void onlinePayment();
void cashonDelivery();
void paymentMethod();
void buyerMenu () {
    cout << "1.SHOW PRODUCTS " << '\n';
    cout << "2.BUY PRODUCTS " << '\n';
    cout << "5.EXIT "<<"\n";
    char choice;
    cin>>choice;
    cout << "\033[2J\033[1;1H";
    switch(choice)
    {
        case '1': showStocks();
                    break;
        case '2': buyProducts();
                    break;
        case '5': exit(1);
                    break;
        default : break;
    }
}
void showStocks()
{   
    pos=0;
    char ch;
    cout<<"Chose the Type of Products yous want to see\n";
    cout<<"1. General \n";
    cout<<"2. Grocery \n";
    cout<<"3. Food Items \n";
    cout<<"4. Garments \n";
    cout<<"5. Exit\n";
    cin>>ch;
    system("clear");
    switch(ch)
    {
        case '1' :  showGeneral();
                    break;
        case '2' :  showGrocery();
                    break;
        case '3' :  showFoodItems();
                    break;
        case '4' :  showGarments();
                    break;
        default :   break; 
    }
    
}
void buyProducts()
{   
    pos=1;
    char ch;
    cout<<"Chose the Type of Products yous want to buy\n";
    cout<<"1. General \n";
    cout<<"2. Grocery \n";
    cout<<"3. Food Items \n";
    cout<<"4. Garments \n";
    cout<<"5. Exit\n";
    cin>>ch;
     cout << "\033[2J\033[1;1H";
    switch(ch)
    {
        case '1' :  showGeneral();
                    break;
        case '2' :  showGrocery();
                    break;
        case '3' :  showFoodItems();
                    break;
        case '4' :  showGarments();
                    break;
        default :   break; 
    }
    char productname[100],shname[100];
    cout<<"Enter Name of the product you want to Buy :";
    cin>>productname;
    char id[100],name[100],productType[100],sname[100];
    double price,discount;
    int quantity,qt;
    FILE *fp;
    fp=fopen("DATA.txt","r");
     cout << "\033[2J\033[1;1H";
    cout<<"Shop Name\t\tProduct id\t\tProduct Name\t\tProduct Type\t\tPrice\t\tQuantity\t\tDiscount\n"; 
    while(!feof(fp))
    {    
        fscanf(fp,"Shop Name : %s | Id : %s | Name : %s | Product Type : %s | Price : %lf | Quantity : %d | Discount : %lf",sname,id,name,productType,&price,&quantity,&discount);
        if(strcmpi(productname,name)==0)
        cout<<sname<<"\t\t\t"<<id<<"\t\t\t"<<name<<" \t\t\t"<<productType<<"\t\t\t"<<price<<" \t\t"<<quantity<<" \t\t\t"<<discount<<"\n";
    }
    fclose(fp);

    cout<<"Enter the name of the shop whose product you want to Buy:";
    cin>>shname;
    cout<<"Enter quantity:";
    cin>>qt;
     cout << "\033[2J\033[1;1H";
    FILE *fr;
    fr=fopen("DATA.txt","r");
    //cout<<"Shop Name\t\tProduct id\t\tProduct Name\t\tProduct Type\t\tPrice\t\tQuantity\t\tDiscount\n"; 
    while(!feof(fr))
    {    
        fscanf(fr,"Shop Name : %s | Id : %s | Name : %s | Product Type : %s | Price : %lf | Quantity : %d | Discount : %lf",sname,id,name,productType,&price,&quantity,&discount);
        if(strcmpi(shname,sname)==0&&strcmpi(productname,name)==0)
        {
            cout<<"Product Name\t\tQuantity\t\tAmount To Be Paid\n";
            cout<<name<<"\t\t\t"<<qt<<" \t\t\t"<<(qt*(price-(0.01*discount*price)))<<"\n";
        }
    }
    fclose(fr);
    getch();
    getch();
    system("clear");
    paymentMethod();
    buyerMenu();


}

void paymentMethod()
{
    cout<<"Choose The Mode of Payment \n";
    cout<<"1. Online Payment\n";
    cout<<"2. Cash on Delivery\n";
    char c;
    cin>>c;
    switch(c)
    {
        case '1': onlinePayment();
                    break;
        case '2': cashonDelivery();
                    break;
        default :  break;

    }
}
void showGeneral()
{   
    char id[100],name[100],productType[100],sname[100];
    double price,discount;
    int quantity;
    FILE *fp;
    fp=fopen("DATA.txt","r");
    cout<<"Shop Name\t\tProduct id\t\tProduct Name\t\tProduct Type\t\tPrice\t\tQuantity\t\tDiscount\n"; 
    while(!feof(fp))
    {    
        fscanf(fp,"Shop Name : %s | Id : %s | Name : %s | Product Type : %s | Price : %lf | Quantity : %d | Discount : %lf",sname,id,name,productType,&price,&quantity,&discount);
        if(strcmpi("general",productType)==0)
        cout<<sname<<"\t\t"<<id<<"\t\t\t"<<name<<" \t\t\t"<<productType<<"\t\t\t"<<price<<" \t\t"<<quantity<<" \t\t\t"<<discount<<"\n";
    }
    fclose(fp);
    getch();
    getch();
    
    if(pos==0)
    {
        system("clear");
        buyerMenu();
    }
}
void showFoodItems()
{
    char id[100],name[100],productType[100],sname[100];
    double price,discount;
    int quantity;
    FILE *fp;
    fp=fopen("DATA.txt","r");
    cout<<"Shop Name\t\tProduct id\t\tProduct Name\t\tProduct Type\t\tPrice\t\tQuantity\t\tDiscount\n"; 
    while(!feof(fp))
    {    
        fscanf(fp,"Shop Name : %s | Id : %s | Name : %s | Product Type : %s | Price : %lf | Quantity : %d | Discount : %lf",sname,id,name,productType,&price,&quantity,&discount);
        if(strcmpi("fooditem",productType)==0)
        cout<<sname<<"\t\t\t"<<id<<"\t\t\t"<<name<<" \t\t\t"<<productType<<"\t\t\t"<<price<<" \t\t"<<quantity<<" \t\t\t"<<discount<<"\n";
    }
    fclose(fp);
    getch();
    getch();
    if(pos==0)
    {
        system("clear");
        buyerMenu();
    }
}
void showGrocery()
{
    char id[100],name[100],productType[100],sname[100];
    double price,discount;
    int quantity;
    FILE *fp;
    fp=fopen("DATA.txt","r");
    cout<<"Shop Name\t\tProduct id\t\tProduct Name\t\tProduct Type\t\tPrice\t\tQuantity\t\tDiscount\n"; 
    while(!feof(fp))
    {    
        fscanf(fp,"Shop Name : %s | Id : %s | Name : %s | Product Type : %s | Price : %lf | Quantity : %d | Discount : %lf",sname,id,name,productType,&price,&quantity,&discount);
        if(strcmpi("grocery",productType)==0)
        cout<<sname<<"\t\t\t"<<id<<"\t\t\t"<<name<<" \t\t\t"<<productType<<"\t\t\t"<<price<<" \t\t"<<quantity<<" \t\t\t"<<discount<<"\n";
    }
    fclose(fp);
    getch();
    getch();
    if(pos==0)
    {
        system("clear");
        buyerMenu();
    }
}
void showGarments()
{
    char id[100],name[100],productType[100],sname[100];
    double price,discount;
    int quantity;
    FILE *fp;
    fp=fopen("DATA.txt","r");
    cout<<"Shop Name\t\tProduct id\t\tProduct Name\t\tProduct Type\t\tPrice\t\tQuantity\t\tDiscount\n"; 
    while(!feof(fp))
    {    
        fscanf(fp,"Shop Name : %s | Id : %s | Name : %s | Product Type : %s | Price : %lf | Quantity : %d | Discount : %lf",sname,id,name,productType,&price,&quantity,&discount);
        if(strcmpi("garment",productType)==0)
       cout<<sname<<"\t\t\t"<<id<<"\t\t\t"<<name<<" \t\t\t"<<productType<<"\t\t\t"<<price<<" \t\t"<<quantity<<" \t\t\t"<<discount<<"\n";
    }
    fclose(fp);
    getch();
    getch();
    if(pos==0)
    {
        system("clear");
        buyerMenu();
    }
}


void onlinePayment()
{   
    char Name[100],name[100],houseno[100],city[100],state[100],password[100],username[100],locality[100];
    long int moblieNo,cardno;
    short int cvv,CVV;
    int pincode,flag;
    cout<<"Enter Your Name: ";
    cin>>name;
    cout<<"Enter CVV of the card resgistered in the system: ";
    cin>>CVV;
    FILE *fp;
    fp=fopen("Buyer.txt","r");
    while(!feof(fp))
    {  
        fscanf(fp,"Name : %s | username : %s |  Mobile No. : %ld | Password : %s | Card Number : %ld | CVV : %hi | House No. : %s | Locality : %s | City : %s | State : %s | Pincode : %d",Name,username,&moblieNo,password, &cardno,&cvv,houseno,locality,city,state,&pincode);
        if(strcmpi(name,Name)==0&&cvv==CVV&&strcmp(globalUser,username)==0)
        {   
            flag=1;
            cout<<"\t\t\t=======================Payment Successful!!!========================\n";
            cout<<"Your Order will be Delivered to the given address:\n";
            cout<<houseno<<"\n"<<locality<<","<<city<<"\n"<<state<<"\n"<<pincode<<"\n";
            break;
        }
    }
    if(flag!=1)
    {
        cout<<"\t\t\t========================Incorrect Details!!!=========================\n";
        getch();
        getch();
        paymentMethod();
    }
}
void cashonDelivery()
{   
    char Name[100],name[100],houseno[100],city[100],state[100],password[100],username[100],locality[100];
    long int moblieNo,cardno;
    short int cvv,CVV;
    int pincode;
    FILE *fp;
    fp=fopen("Buyer.txt","r");
    while(!feof(fp))
    {  
        fscanf(fp,"Name : %s | username : %s |  Mobile No. : %ld | Password : %s | Card Number : %ld | CVV : %hi | House No. : %s | Locality : %s | City : %s | State : %s | Pincode : %d",Name,username,&moblieNo,password, &cardno,&cvv,houseno,locality,city,state,&pincode);
        if(strcmp(globalUser,username)==0)
        {   
            cout<<"\t\t\t==============Please Make payment after the delivery!!!=============\n";
            cout<<"Your Order will be Delivered to the given address:\n";
            cout<<houseno<<"\n"<<locality<<","<<city<<"\n"<<state<<"\n"<<pincode<<"\n";
            break;
        }
    }
}