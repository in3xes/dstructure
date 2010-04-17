#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define MAX_ROW	5
#define MAX_COL 5

class Matrix {
	
	private:
	int Data[MAX_ROW][MAX_COL];
	int Prices[MAX_COL];

	public:	
	void intialize(); //done
	void enter_data(); //done
	void view_data(); //done
	void view_customer_details(); //done
	void view_product_details(); //done
	void create_prices(); //done
	int view_total_amount(); //done
	int view_customer_pay(); //done
	void print_menu(); //done
	void view_pricelist(); //done

	Matrix() {
//		Data ={{0},{0}};
		intialize();
		create_prices();
	}
};

void Matrix::view_data() {
	for(int i=0; i < MAX_ROW; i++) {
		for(int j = 0; j < MAX_COL; j++) {
			cout << Data[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Matrix::intialize() {
	for(int i=0; i < MAX_ROW; i++) {
		for(int j = 0; j < MAX_COL; j++) {
			 Data[i][j] = 0;
		}
	}
}

void Matrix::enter_data() {
	int p, c, q;
	cout <<"Enter Customer number :		";
	cin >> c;
	cout <<"\nEnter Product number :	";
	cin >> p;
	cout << "\nEnter Quntity:		";
	cin >> q;

	Data[c-1][p-1] = q;
}

void Matrix::view_customer_details() {
	int c;
	cout <<"Enter the Customer number:	";
	cin >> c;
	cout <<"   \t";
	for(int i = 0; i < MAX_COL; i++) {
		cout <<"prdct"<<i << "  ";
	}
	cout << "\n\n";
	cout <<"Quntity ";
	for(int i = 0; i< MAX_COL; i++) {
		cout << "   " << Data[c-1][i] << "\t";
	}
	cout << endl;
}

void Matrix::view_product_details() {
	int p;
	cout <<"Enter the Product number to view details :	";
	cin >> p;
	cout << "\t         Quantity\n";
	for(int i = 0; i < MAX_ROW; i++) {
		cout << "Customer no " << i << "        " <<Data[i][p-1] << endl;
	}
	cout << endl;
}

void Matrix::create_prices() {
	for(int i = 0; i < MAX_COL; i++) {
	Prices[i] = rand() % 500;
	srand(time(0));
	}
}

int Matrix::view_total_amount() {
	int amount = 0;
	for(int i=0; i < MAX_ROW; i++) {
		for(int j = 0; j < MAX_COL; j++) {
			amount = amount + Data[i][j] * Prices[j];
		}
	}
	
	return amount;
}
int Matrix::view_customer_pay() {
	int c;
	cout <<"Enter the Customer number to view the pay:	";
	cin >> c;
	int pay = 0;
	for(int i=0; i < MAX_COL; i++) {
		pay = pay + Data[c][i] * Prices[i];
	}
	
	return pay;
}

void Matrix::print_menu() {
	cout <<"Enter \"v\" to view the data matrix.	\n";
	cout <<"Enter \"e\" to enter details.		\n";
	cout <<"Enter \"c\" to view the customer details.	\n";
	cout <<"Enter \"p\" to view the product details.	\n";
	cout <<"Enter \"t\" to view the todays\'s total amount.	\n";
	cout <<"Enter \"r\" to view the customer\'s payment.	\n";
	cout <<"Enter \"l\" to view price list.	\n";
	cout <<"Enter \"q\" to quit.	\n";
}

void Matrix::view_pricelist() {
	for(int i = 0; i < MAX_COL; i++) {
		cout << "Price of item " << i << " is\t" << Prices[i] << endl;
	}
	cout << endl;
}

void option() {
	cout <<"\nEnter \"m\" for menu \"q\" to quit.	\n";
}
int main()
{
	Matrix M;
//	M.intialize();
//	M.create_prices();
	int done = 0;
	char todo = '\n';
	while(!done) {
		option();
		cin >> todo;
		switch(todo) {
			case 'm':
				M.print_menu();
				break;
			case 'e':
				M.enter_data();
				break;
			case 'v':
				M.view_data();
				break;
			case 'l':
				M.view_pricelist();
				break;
			case 'p':
				M.view_product_details();
				break;
			case 'c':
				M.view_customer_details();
				break;
			case 't':
				cout <<"Total amount for the tillnow is " <<  M.view_total_amount() << endl;
				break;
			case 'r':
				cout <<"Customer nned to pay " << M.view_customer_pay() << endl;
				break;
			case 'q':
				cout << "Qutting...\n";
				done = 1;
		}
	}

	return 1;
}	
