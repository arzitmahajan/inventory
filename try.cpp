#include <iostream>
#include <string>
#define dap 5
using namespace std;
//for both customer and shopkeeper
void bill();
//for customer
void sold(int);
//for shopekeeper
void adding(int, int ,int,int,int);
//for shopekeeper
void upprc();
//for shopekeeper
void upqty();
//for shopekeeper
void addrmv();
//for shopekeeper
void remit();
//for shopekeeper
void stock(int,int);
void whenzero();

class A{
public:
	int glo,sold=0,count=0,olo, unistock;
	int g = 0;
	int bookId = 0;
	int prc = 0;
	int qty = 0;
	int gale = 0;
	int checker=0;
	//string glocuname;
	char glocuname[20];
	long long int glocusphun;
	void setBookId(int id) {
		bookId = id;
	}
	int getBookId() {
		return bookId;
	}
	void setprc(int cost) {
		prc = cost;
	}
	int getprc() {
		return prc;
	}
	void setqty(int quan) {
		qty = quan;
	}
	int getqty() {
		return qty;
	}
	int poz[5][3];
}obj[dap];

void whenzero() {
	printf("\t\t\t!!!!!!!!!!!!!!!!!!!Nothing Added In The Cart!!!!!!!!!!!!!!!!!!!\t\t\t\n");
}
void  working() {
	char ques[3];
	char use[3];
	int exit;
	int y = 0;
	int  d = 0, id = 0;
	int  choice = 0, e = 0, count = 0, f = 0;
	int cost = 0, quan = 0;
	printf("Enter your choice\n");
	printf("Enter 1 to ADD books in the store\nEnter 2 to buy books\nEnter 3 to view the stock\nEnter 4 to update price of book\nEnter 5 to update the BookID\nEnter 6 to remove books from the stock \nEnter 7 to upate the quantity\nEnter 8 to get the bill\nEnter 0 to exit\n");
	std::cin >> choice;
	switch (choice) {
	case 0:
		break;
	case 1:
		adding(d, id, cost, quan, count);
		break;
	case 2:
		sold(f);
		break;
	case 8:
		bill();
		break;
	case 3:
		stock(e, count);
		break;
	case 7:
		upqty();
		break;
	case 6:
		addrmv();
		break;
	case 5:
		remit();
		break;

	case 4:
		upprc();
		break;

	default:
		printf("Enter the valid choice\n");
		break;
	}

}
void minst() {
	int min = 0;
	printf("***STOCK***\n");
	printf("*BOOK IDS WERE\t*Cost of books\t*Quantity\n");
	for (min = 0; min < obj[dap].glo; min++) {
		std::cout << obj[min].getBookId() << "\t\t" << obj[min].getprc() << "\t\t" << obj[min].getqty() << "\n";
	}
}

void adding(int d,int id,int cost,int quan,int count) {
	int che;
	int indx = 0;
	int st = 0;
	int addstk = 0,round =0,t;
	int clo,ct=0;
	for (clo = 0; clo < 5;clo++) {
		if (obj[clo].getBookId() > 0) {
			ct++;
		}
	}
	printf("Enter the  number of books you want to buy\n");
	std::cin >>st;
	for (d = 0; d < st; d++) {
		printf("Enter the %d book id", d+1);
		std::cin >> id;
		printf("Enter the price of the book\n");
		std::cin >> cost;
		printf("Enter the quantity of the book\n");
		std::cin >> quan;
		for (t = 0; t < ct; t++) {
			if (id == obj[t].getBookId()) {                             
				addstk = obj[t].getqty();
				addstk += quan;
				round++;
				indx = t;
				break;
			}
		}
			if (round == 0) {
				//std::cout << "uniques \n";
				obj[ct].setBookId(id);
				obj[ct].setprc(cost);
				obj[ct].setqty(quan);
				ct++;
				obj[dap].checker++;
			}
			else {
				//std::cout << "Duplicate \n";
				obj[indx].setBookId(id);
				obj[indx].setprc(cost);
				obj[indx].setqty(addstk);
			}
			round = 0;
		}
	obj[dap].glo = ct;
	for (che = 0; che < ct;che++) {
		std::cout << "id=" <<obj[che].getBookId() <<"\t";
		std::cout << "qty=" << obj[che].getqty() <<"\t";
		std::cout << "prc=" << obj[che].getprc() << "\n";
	}
		obj[dap].sold = ct;
		if (obj[dap].checker>0) {
			working();
		}
		else {
			whenzero();
			working();
		}
}

void addrmv() {
	int q,bkid,qt,cut;
	char reopt[5];
		printf("Enter the Book Id which you want to remove from the cart\n");
		std::cin >> bkid;
		for (q = 0; q < obj[dap].glo; q++) {
			if (bkid == obj[q].getBookId()) {
				cut = q;
				std::cout<<"Are you sure to remove full stack of book("<<bkid<<")\n\t yes or no\n";
				std::cin >> reopt;
				break;
			}
		}
		if (strcmp(reopt,"yes")==0) {
			for (qt =cut ; qt < obj[dap].glo - 1;qt++) {
				obj[qt].setBookId(obj[qt+1].getBookId());
				obj[qt].setprc(obj[qt+1].getprc());
				obj[qt].setqty(obj[qt+1].getqty());
				std::cout << obj[qt].getBookId()<<"\n";
				std::cout << obj[qt].getprc()<<"\n";
				std::cout << obj[qt].getqty()<<"\n";

			}
			obj[obj[5].glo - 1].setBookId(0);
			obj[obj[5].glo-1].setprc(0);
			obj[obj[5].glo-1].setqty(0);
			minst();
		}
		else {
	    }
	if (obj[dap].checker > 0) {
		working();
	}
	else {
		whenzero();
		working();

	}
}

void sold(int f) {
	int stck,infi;
	char nes[2];
	int saleid,l,salequan,op,ct=0,j;
	printf("Enter the number of Books you want to buy\n");
	std::cin >> infi;
	obj[dap].olo = infi;
	if (obj[dap].checker > 0) {
		int row = 0, prc = 0, indx = 0;
		for (l = 0; l < infi; l++) {
			printf("Enter the BOOK ID\n");
			std::cin >> saleid;
			for (j = 0; j < obj[dap].glo; j++) {
				if (saleid == obj[j].getBookId()) {
					ct++;
					prc = obj[j].getprc();
					stck = obj[j].getqty();
					indx = j;
					break;
				}
			}
			if (ct > 0) {

				printf("Enter the Quantity of books\n");
				std::cin >> salequan;
				if (salequan <= stck) {
					stck -= salequan;
					
					//poz[][].se=stck;
					obj[5].poz[row][0] = saleid;
					obj[5].poz[row][1] = salequan;
					obj[5].poz[row][2] = prc;
					row++;
					obj[indx].setqty(stck);

					printf("BOOKS ADDED TO CART \n");

				}
				else {
					printf("NOT IN STOCK\n");
					break;
				}
			}
			else {
				printf("Wrong Id \n");
			}
			ct = 0;
		}
		printf("Enter your name please!\n");
		std::cin >> obj[dap].glocuname;
		
		/*cout<<"Enter your name please!\n";
		getline(cin, obj[5].glocuname);
		cout << obj[dap].glocuname;*/
		
		printf("Enter your Phone number\n");
		std::cin >> obj[dap].glocusphun;
		working();
	}
	else {
		whenzero();
		working();

	}

}

void upprc() {
	int od,ki,latcos;
	char hop[3];
	char game[3];
	int goat=0;
	printf("Enter the book id for which you want to update the price\n");
	std::cin>> od;
		for (ki = 0; ki <obj[dap].glo; ki++) {
			if (od == obj[ki].getBookId()) {
				std::cout << "Enter the new cost for  BOOK(" << obj[ki].getBookId() << ")\tInital price of the book is " << obj[ki].getprc() << "\n";
				std::cin >> latcos;
				obj[ki].setprc(latcos);
				minst();
				goat++;
			}
			
		}
		if(goat==0) {
		printf("Book id Invalid!\n");
			}

		if (obj[dap].checker > 0) {
			working();
		}
		else {
			whenzero();
			working();
		}
}

void upqty(){
int oka,gui,upstk,evy;
	char all[5];
	printf("If you want to update each book quantity(Enter 'all')\nIf you want to update quantity to specific book id(Enter 'spec')\n");
	std::cin >> all;
	if (strcmp(all, "spec") == 0) {
		printf("Enter the book id for which you want to update the quantity\n");
		std::cin >> oka;
		for (gui = 0; gui < obj[dap].glo; gui++) {
			if (oka==obj[gui].getBookId()) {
				printf("How many books you want to get in stock\n");
				std::cin >> upstk;
				obj[gui].setqty(upstk);
				minst();
				break;
			}
			else {
				printf("Enter valid Book id\n");
			}
		}
	}
	if (strcmp(all,"all")==0) {
		printf("Enter the quantity which you want to set for every BOOK\n");
		std::cin >>evy;
		for (gui = 0; gui < obj[dap].glo;gui++) {
			obj[gui].setqty(evy);
		}
		minst();
	}
	if (strcmp(all, "") != 0) {
		printf("Enter valid choice\n");
	}
	if (obj[dap].checker > 0) {
		working();
	}
	else {
		whenzero();
		working();

	}
}
void remit() {
	int remit = 0, ok, sid,remid;
	printf("Enter the book id for which you want to UPDATE!\n");
	std::cin >> sid;
	for (ok = 0; ok < obj[dap].glo; ok++) {
		if (sid == obj[ok].getBookId()) {
			std::cout<<"Enter the NEW Book id!!\tPrevious BOOK ID was ->"<<obj[ok].getBookId()<<"\n";
			std::cin >>remid;
			obj[ok].setBookId(remid);
		}
		else {
			"Enter the valid BOOK ID.\n";
		}
	}
	minst();
	if (obj[dap].checker > 0) {
		working();
	}
	else {
		whenzero();
		working();

	}
}

void stock(int e,int count) {
		printf("**********************************************************STOCK LIST******************************************************************\n");
		std::cout << "BOOK IDt\t" << " Cost of each book \t\t" << "\t\tQuantity\n";
		for (e = 0; e < obj[dap].glo; e++) {
			std::cout << obj[e].getBookId() << "\t\t\t\t" << obj[e].getprc() << " \t\t\t\t" << obj[e].getqty() << "\n";
		}
		printf("*********************************************************************************************************************************************\n");
		if (obj[dap].checker > 0) {
			working();
		}
		else {
			whenzero();
			working();
		}
}
void bill() {
	int fin,tmount,dim=0,sumto=0;
	int r1=0;
	printf("\t\t\t\t\*****YOUR BILL*****\n");
	std::cout<<"Customer name\t\tcustomer Phone Number\n"<<obj[dap].glocuname<<"\t\t\t"<<obj[dap].glocusphun<<"\n";
	std::cout << "BOOK ID " << "\t\tQuantity\t\t" << " Cost of each book \t\t" << "Cost of all books\n";
	for (fin = 0; fin < obj[dap].olo; fin++) {
		tmount = obj[dap].poz[fin][1]*obj[dap].poz[fin][2];
		std::cout << obj[dap].poz[fin][0]<< "\t\t\t\t" << obj[dap].poz[fin][1] << " \t\t\t\t" << obj[dap].poz[fin][2] << "\t\t\t\t" << tmount<<"\n";
		sumto += tmount;
	}
	std::cout << "Total amount = " << sumto << "\n";

	working();
}

int main() {

	working();
	return 0;
}
