#include"headerFilesAndGlobalVariables.cpp"
#include"loginPage.cpp"
#include"sellerMainMenu.cpp"
#include"buyerMainMenu.cpp"

int main () {
char pass[10],pass2[10];
	int i,j;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO DELIVERY MANAGEMENT SYSTEM ============|";
	getch();
	cout << "\033[2J\033[1;1H";
	cout<<"\n\t\t   DELIVERY MANAGEMENT SYSTEM\n";	
	cout<<"============================================================="<<"\n";
	int ch=loginMain();
	cout << "\033[2J\033[1;1H";
	if(ch==0)
	{
		buyerMenu();
	}
	else if(ch==1)
	{
		sellerMenu();
	}
	else if(ch==-1)
	{
		cout<<"Incorrect Login Credentials!!!Please enter correct Login credentials of signup\n";
		
	}
	
	return 0;
}

