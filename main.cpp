#include"headerFilesAndGlobalVariables.cpp"
#include"loginPage.cpp"
#include"sellerMainMenu.cpp"
#include"buyerMainMenu.cpp"

int main () {
char pass[10],pass2[10];
	int i,j;
	system("clear");
	cout<<" \t\t\t\t\t\t|============ WELCOME TO DELIVERY MANAGEMENT SYSTEM ============|";
	getch();
	cout << "\033[2J\033[1;1H";
	cout<<"\n\t\t\t\t\t   DELIVERY MANAGEMENT SYSTEM\n";	
	cout<<"\t\t\t============================================================="<<"\n";
	do
	{
		int ch=loginMain();
		cout << "\033[2J\033[1;1H";
		if(ch==0)
		{
			buyerMenu();
		}
		else if(ch==1)
		{
			sellerShopName();
		}
		else if(ch==-1)
		{
			cout<<"\t\t\t\tIncorrect Login Credentials!!!Please enter correct Login credentials or signup\n\n\n\n";
			//ch=loginMain();
		}
	}while(1);
	
	return 0;
}

