void showStocks();
void buyProducts();
void showGeneral();
void showGrocery();
void showFoodItems();
void showGarments();
void buyerMenu () {
    cout << "1.SHOW PRODUCTS " << '\n';
    cout << "2.BUY PRODUCTS " << '\n';
    cout << "3.EXIT "<<"\n";
    char choice;
    cin>>choice;
    cout << "\033[2J\033[1;1H";
    switch(choice)
    {
        case '1': showStocks();
                    break;
        case '2': buyProducts();
                    break;
        default : break;
    }
}
void showStocks()
{   
    
    char ch;
    cout<<"Chose the Type of Products yous want to see\n";
    cout<<"1. General \n";
    cout<<"2. Grocery \n";
    cout<<"3. Food Items \n";
    cout<<"4. Garments \n";
    cout<<"5. Exit\n";
    cin>>ch;
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
            cout<<"Product Name\t\tQuantity\t\tAmount\n";
            cout<<name<<"\t\t\t"<<qt<<" \t\t\t"<<(qt*(price-(0.01*discount*price)))<<"\n";
        }
    }
    fclose(fr);


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
        cout<<sname<<"\t\t\t"<<id<<"\t\t\t"<<name<<" \t\t\t"<<productType<<"\t\t\t"<<price<<" \t\t"<<quantity<<" \t\t\t"<<discount<<"\n";
    }
    fclose(fp);
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
}
