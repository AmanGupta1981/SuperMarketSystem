#include<iostream>
#include<fstream>
using namespace std;

class shoping{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
			
};


void shoping :: menu(){
	m:
	int choice;
	string email;
	string password;
	cout<<"\t\t\t\t____________________________________\n";
	cout<<"\t\t\t\t                                    \n";
	cout<<"\t\t\t\t       supermarket Main Menu          ";
	cout<<"\t\t\t\t                                    \n";
	cout<<"\t\t\t\t____________________________________\n";
	cout<<"\t\t\t\t                                    \n";
	cout<<"\t\t\t\t\t|  1)Administrator    |\n";
	cout<<"\t\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t\t|  2)Buyer            |\n";
	cout<<"\t\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t\t|  3)Exit             |\n";
	cout<<"\t\t\t\t\t|                     |\n";
	cout<<"\n\t\t\t\t Please Select:";
	cin>>choice;
	
	switch(choice){
		case 1:
			cout<<"\t\t\t  Please Login \n";
			cout<<"\t\t\t  Enter Email: ";
			cin>>email;
			cout<<"\t\t\t  Password:    ";
			cin>>password;
			
			if(email=="amangupta7030@gmail.com" && password=="Aman@123"){
				 administrator();
			}
			else{
				cout<<"Invalid email/password";
			}
			break;
		
		
			case 2:
		{
			buyer();
		}
		
	case 3:
		{
				exit(0);
		}
	
	default:
		{
			cout<<"Please Select From The Given Option";
		}
			
		
			
	}
	
	
goto m;	
}


void shoping::administrator(){
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Administrator menu";
	cout<<"\n\t\t\t|____1)Add the Product____|";
	cout<<"\n\t\t\t|                         |";
	cout<<"\n\t\t\t|____2)Modify the Product_|";
	cout<<"\n\t\t\t|                         |";
	cout<<"\n\t\t\t|____3)Delete the Product_|";
	cout<<"\n\t\t\t|                         |";
	cout<<"\n\t\t\t|____4)Back to Main Menu__|";
	
	cout<<"\n\n\t Please enter your choice: ";
	cin>>choice;
	
	switch(choice){
		case 1:
			add();
			break;
		case 2:
		    edit();
			break;
		case 3:
		    rem();
			break;
			
		case 4:
		   menu();
		   break;
		
		default	:
		cout<<"invalid choice!";	
			
	}
		
goto m;	
	
}


void shoping::buyer(){
	m:
	int choice;
	cout<<"\t\t\t      Buyer     \n";
	cout<<"\t\t\t________________\n";
	cout<<"                      \n";
	cout<<"\t\t\t 1) Buy Product \n";
	cout<<"                      \n";
	cout<<"\t\t\t 2) Go Back     \n";
	cout<<"                      \n";
	
	cout<<"\t\t\t 3)Enter Your Choice:  ";
	
	cin>>choice;
	
	switch(choice){
		case 1:
			receipt();
			break;
		case 2:
	    	menu();
	    	
		default :
			cout<<"invalid choice";
			
	}
	
goto m;
}


 void shoping::add(){
 	m:
 	fstream data;
 	int c;
 	int token=0;
 	float p;
 	float d;
 	string n;
 	
 	cout<<"\n\n\t\t\t Add new product";
 	
 	cout<<"\n\n\t Product code of the product :";
 	cin>>pcode;
 	cout<<"\n\n\t Name of the product :";
 	cin>>pname;
 	cout<<"\n\n\t Price of the product :";
 	cin>>price;
 	cout<<"\n\n\t Discout on the product :";
 	cin>>dis;
 	
 	//checking for the file exist or not
 	data.open("database.txt",ios::in);
 	
 	//if file does not exist then creating and writing to the file
 	if(!data){
 			data.open("database.txt",ios::app|ios::out);
 			data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
 			data.close();
 			
	 }
	 else{ 
	 
	 	data>>c>>n>>p>>d; //reading data from the file
	 	while(!data.eof()){
	 		//looking for duplicate product
	 		if(c==pcode){
	 			token++;
			 }
			 data>>c>>n>>p>>d;
		 }
		 data.close();
	 
 	if(token==1)
	 goto m;
	 else{
	 	data.open("database.txt",ios::app|ios::out);
 			data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
 			data.close();
 			
	 }
}
 	
 	cout<<"\n\n\t\t Record inserted";
 }
 
 
 void shoping::edit(){
 	fstream data,data1;// Declare file stream objects for input (data) and output (data1)
 	int pkey;// Variable to hold the product code to be edited
 	int token=0;     // Flag to check if the record was found and edited
 	int c;
 	float p;
 	float d;
 	string n;
 	
 	cout<<"\n\t\t\t Modify the record";
 	cout<<"\n\t\t\t Product code :";
 	cin>>pkey; // Take the product code of the product to be edited from user input
 	
 	data.open("database.txt",ios::in);// Open the original database file for reading
 	if(!data){// Check if the file was successfully opened
 		cout<<"\n\n File doesn't exist";	
	 }
	 else{
	 	data1.open("database1.txt",ios::app|ios::out);// Open a temporary file to write the updated records
	 	data>>pcode>>pname>>price>>dis;// Read the first record from the database file

	 	while(!data.eof()){
	 		if(pkey==pcode){// Check if the current record matches the product code to be edited
	 			cout<<"\n\\t\t Product new code:";
	 			cin>>c; // Get the new product code from user input
	 			cout<<"\n\t\t Name of the product:";
	 			cin>>n;
	 			cout<<"\n\t\t Price:";
	 			cin>>p;
	 			cout<<"\n\t\t Discount :";
	 			cin>>d;
	 			data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n"; // Write the updated record to the temporary file
	 			cout<<"\n\n\t\t Record edited";
	 			token++;  // Set the token flag to indicate that a record was found and edited
			 }
			 else{ // If no match, copy the record to the temporary file
			 	data1<<" "<<pcode<<pname<<" "<<price<<" "<<dis<<"\n";
			 }
			 data>>pcode>>pname>>price>>dis; // Read the next record from the database file
		 }
		 
		 data.close();
		 data1.close();
		 remove("database.txt");// Delete the original database file
		 rename("database1.txt","database.txt"); // Rename the temporary file to the original file name
		 
		 if(token==0){
		 	cout<<"\n\n Record not found sorry";
		 }
		 
	 }
 }
 
 void shoping::rem(){
 	fstream data,data1;
 	int pkey;
 	int token=0;
 	cout<<"\n\n\t Delete product";
 	cout<<"\n\n\t Product code:";
 	cin>>pkey; // Take the product code of the product to be deleted from user input
 	data.open("database.txt",ios::in); // Open the original database file for reading
 	if(!data){
 		cout<<"File Doesn't Exist";
	 }
	 else{
	 	data1.open("database1.txt",ios::app|ios::out); // Open a temporary file to write the remaining records
	 	data>>pcode>>pname>>price>>dis; // Read the first record from the database file
	 	while(!data.eof()){
	 		if(pcode==pkey){
	 			cout<<"\n\n\t Product deleted succesfully";
	 			token++;
			 }
			 else{
			 	data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			 	
			 }
			 data>>pcode>>pname>>price>>dis;
		 }
		 data.close();
		 data1.close();
		 remove("database.txt");
		 rename("database1.txt","database.txt");
		 if(token==0){
		 	cout<<"\n\n Record not found";
		 }
	 }
 	
 }
 
 void shoping::list(){
 	fstream data;
 	data.open("database.txt",ios::in); // Open the database file for reading
 	cout<<"\n\n___________________________________\n";
 	cout<<"proNo\t\tName\t\tPrice\n";
 	cout<<"\n\n___________________________________\n";
 	data>>pcode>>pname>>price>>dis; // Read the first record from the file
 	while(!data.eof()){
 		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";  // Print the product code, name, and price
 		data>>pcode>>pname>>price>>dis;
	 }
	 data.close();
 	
 }
 void shoping::receipt() {
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float discount = 0;
    float total = 0;

    cout << "\n\n\t\t\t RECEIPT";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty database";
    } else {
        data.close();
        list();
        cout << "\n____________________________\n";
        cout << "\n|                          |\n";
        cout << "\n    Please place the order  \n";
        cout << "\n____________________________\n";
        cout << "\n|                          |\n";

        do {
            m:
            cout << "\n\n Enter product code:";
            cin >> arrc[c];
            cout << "\n\n Enter the product quantity:";
            cin >> arrq[c];

            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n Duplicate product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? If yes then press y else no:";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n\t\t\t__________________RECEIPT___________________________________\n";
        cout << "\nProduct No\t Product Name\t Product Quantity\t Price\t Amount\t Amount with discount\n";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> discount;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    float finalAmount = amount - (amount * discount / 100);
                    total += finalAmount;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << finalAmount;
                }
                data >> pcode >> pname >> price >> discount;
            }
            data.close();
        }

        cout << "\n\n______________________________________";
        cout << "\n Total Amount : " << total;
    }
}

 int main(){
 	shoping s;
 	s.menu();
 }
 