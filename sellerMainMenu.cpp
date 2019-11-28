// Contains product class
#include"classes/product.cpp"
Product newProduct;
// For registering products
void registerProduct();
void sellerMenu();
// For Updating Product's Info
void updateProduct();
void showStock();
void sellerShopName();
char shopname[100];
// To show Sellers main menu
void sellerShopName () {
    
    
    cout<<"\t\t\t====================You are Logged In as a Seller============================\n";
    cout<<"Enter Your Shop Name: ";
    cin>>shopname;
    system("clear");
    sellerMenu();
}
void sellerMenu()
{
    cout << '\t' << "1. Register Product" << '\n';
    cout << '\t' << "2. Update a Product" << '\n';
    cout << '\t' << "3. Show Stock"<<"\n";
    cout << '\t' << "5. Exit"<<"\n";
        char choice;
    cin >> choice;
    system("clear");
    switch(choice) {
        case '1' :
            registerProduct();
            break;
        case '2' :
            updateProduct();
            break;
        case '3':
            showStock();
            break;
        case '5': exit(1);
        default :
            break;
    }
}



void updateProduct() {
    FILE*fp1, *fp2;
    char id1[100],id2[100],name1[100],name2[100];
    double price1,price2 , discount1,discount2;
    int quantity1,quantity2;
    int lno=0,linectr=0; 
    fp1 = fopen("DATA.txt","r");
    fp2= fopen("Temp.txt","w");
    //fp2 = fopen("DATA.txt","w");
    printf("Enter id of the product to be updated: ");
    scanf("%s", id1);

    while(!feof(fp1))
    {   lno++;
        fscanf(fp1,"Shop name : %s | Id : %s | Name : %s | Price : %lf | Quantity : %d | Discount : %lf",shopname,id2,name1,&price1,&quantity1,&discount1);
        if(strcmp(id1,id2)==0)
        {   
            
            cout<<"Shop Name\t\tProduct id\t\tProduct Name\t\tPrice\t\tQuantity\t\tDiscount\n"; 
            cout<<shopname<<"\t\t"<<id1<<"\t\t"<<name1<<" \t\t\t"<<price1<<" \t\t"<<quantity1<<" \t\t\t"<<discount1<<"\n";
            cout<<"Enter the updated details \n";
            cout<<"Product name: ";
            cout<<"Enter Product Type";
            cin>>name2;
            cout<<"Price: ";
            cin>>price2;
            cout<<"Quantity: ";
            cin>>quantity2;
            cout<<"Discount: ";
            cin>>discount2;
            while(!feof(fp1)) 
            {
                fscanf(fp1,"Id : %s | Name : %s | Price : %lf | Quantity : %d | Discount : %lf",id2,name1,&price1,&quantity1,&discount1);
                if (!feof(fp1)) 
                {
                    linectr++;
                    if (linectr != lno) 
                    {
                        fprintf(fp2, "Id : %s | Name : %s | Price : %lf | Quantity : %d | Discount : %lf", id1, name1, price1, quantity1, discount1);
                    } 
                    else 
                    {
                        fprintf(fp2, "Id : %s | Name : %s | Price : %lf | Quantity : %d | Discount : %lf", id1, name2, price2, quantity2, discount2);
                    }
                }
            }
            fclose(fp1);
            fclose(fp2);
            remove("DATA.txt");
            rename("Temp.txt", "DATA.txt");
            break;
        }
         
    }
    fclose(fp1);
    //fclose(fp2);

    /*fp2 = fopen("TemporaryTextFile.txt","r"){
    }
    fp1 = fopen("OriginalTextFile.txt","w"){
    }
    while(!feof(fp2))
    {
    fscanf(fp2,"%s %s %d", fname,lname,age);
    fprintf(fp1,"%s %s %d", fname,lname,age);
    }
    fclose(fp1);
    fclose(fp2);

    getch();
    }*/

}
void showStock()
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
        if(strcmpi(sname,shopname)==0)
        cout<<sname<<"\t\t\t"<<id<<"\t\t\t"<<name<<" \t\t\t"<<productType<<"\t\t\t"<<price<<" \t\t"<<quantity<<" \t\t\t"<<discount<<"\n";
    }
    fclose(fp);
    getch();
    //cout << "\033[2J\033[1;1H";
    getch();
    system("clear");
    sellerMenu();
}
void registerProduct()
{   
    int n;
    string id;
	string name;
    string productType;
	double price;
	int quantity;
	double discount;
    cout<<"Enter number of products you want to register: ";
    cin>>n;
    FILE * fp;
    fp = fopen("DATA.txt", "a");
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Product "<<i+1<<" details"<<"\n";
        cout<<"Product id: ";
        cin>>id;
        cout<<"Product name: ";
        cin>>name;
        cout<<"Product Type: ";
        cin>>productType;
        cout<<"Price: ";
        cin>>price;
        cout<<"Quantity: ";
        cin>>quantity;
        cout<<"Discount: ";
        cin>>discount;
	    cout << "\033[2J\033[1;1H";
        newProduct.setDetails(id,name,productType,price,quantity,discount);
        fprintf(fp, "Shop Name : %s | Id : %s | Name : %s | Product Type : %s | Price : %lf | Quantity : %d | Discount : %lf", shopname, newProduct.getId().c_str(), newProduct.getName().c_str(),newProduct.getproductType().c_str(), newProduct.getPrice(), newProduct.getQuantity(), newProduct.getDiscount());
    }
    fclose(fp);
    cout<<"\t\t\t====================================Products registered!!!============================================\n";
    cout<<"\t\t\t===============================Press enter to continue!!==============================================\n";
    getch();
    getch();
    system("clear");
    sellerMenu();
    //cout<<sizeof(newProduct)<<"\n";
}