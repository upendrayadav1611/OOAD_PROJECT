void showStocks();
void buyProducts();
void buyerMenu () {
    cout << "1.SHOW PRODUCTS " << '\n';
    cout << "2.BUY PRODUCTS " << '\n';
    cout << "3.EXIT "<<"\n";
    char choice;
    cin>>choice;
    switch(choice)
    {
        case '1': showStocks();
                    break;
        case '2': buyProducts();
                    break;
        default : break;
    }
}
void buyProducts()
{

}
void showStocks()
{   
    char id[100],name[100];
    double price,discount;
    int quantity;
    FILE *fp;
    fp=fopen("DATA.txt","r");
    cout<<"Product id\t\tProduct Name\t\tPrice\t\tQuantity\t\tDiscount\n"; 
    while(!feof(fp))
    {    
        fscanf(fp,"Id : %s | Name : %s | Price : %lf | Quantity : %d | Discount : %lf",id,name,&price,&quantity,&discount);
        cout<<id<<"\t\t"<<name<<" \t\t\t"<<price<<" \t\t"<<quantity<<" \t\t\t"<<discount<<"\n";
    }
        fclose(fp);
}