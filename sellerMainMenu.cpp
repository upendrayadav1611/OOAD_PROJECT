// Contains product class
#include"classes/product.cpp"
Product newProduct;
// For registering products
void registerProduct();

// For Updating Product's Info
void updateProduct();
void showStock();

// To show Sellers main menu
void sellerMenu () {
    cout << '\t' << "1. Register Product" << '\n';
    cout << '\t' << "2. Update a Product" << '\n';
    cout << '\t' << "3. Show Stock"<<"\n";
        char choice;
    cin >> choice;
    cout << "\033[2J\033[1;1H";
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
    printf("Enter id of the product to be updataed: ");
    scanf("%s", id1);

    while(!feof(fp1))
    {   lno++;
        fscanf(fp1,"Id : %s | Name : %s | Price : %lf | Quantity : %d | Discount : %lf",id2,name1,&price1,&quantity1,&discount1);
        if(strcmp(id1,id2)==0)
        {   
            
            cout<<"Product id\t\tProduct Name\t\tPrice\t\tQuantity\t\tDiscount\n"; 
            cout<<id1<<"\t\t"<<name1<<" \t\t\t"<<price1<<" \t\t"<<quantity1<<" \t\t\t"<<discount1<<"\n";
            cout<<"Enter the updated details \n";
            cout<<"Product name: ";
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
void registerProduct()
{   
    int n;
    string id;
	string name;
	double price;
	int quantity;
	double discount;
    cout<<"Enter number of products you want to register\n";
    cin>>n;
    FILE * fp;
    fp = fopen("DATA.txt", "a");
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Product "<<i+1<<"details"<<"\n";
        cout<<"Product id: ";
        cin>>id;
        cout<<"Product name: ";
        cin>>name;
        cout<<"Price: ";
        cin>>price;
        cout<<"Quantity: ";
        cin>>quantity;
        cout<<"Discount: ";
        cin>>discount;
	    cout << "\033[2J\033[1;1H";
        newProduct.setDetails(id,name,price,quantity,discount);
        fprintf(fp, "Id : %s | Name : %s | Price : %lf | Quantity : %d | Discount : %lf", newProduct.getId().c_str(), newProduct.getName().c_str(), newProduct.getPrice(), newProduct.getQuantity(), newProduct.getDiscount());
        cout << "Yo!";
    }
    fclose(fp);
    //cout<<sizeof(newProduct)<<"\n";
}