#include <iostream>
#include <string>
using namespace std;

void lend_book(long student_id[10],long book_id[10],long lend_student_id[100],long lend_book_id[100],
int student_id_count,int book_count,bool lend_check[100],int &lend_count);

void book_input(long book_id[10], string book_name[10], string book_author[10], string book_publish[10],int &book_count);

void student_information (string student_name[10] , long student_id[10] , string student_faculty [10] , string student_branch[10],
int &student_id_count);

void send_book(long lend_student_id[100],long lend_book_id[100],int lend_count,bool lend_check[100]);

void report(long student_id[10], string student_name[10],string student_faculty[10],string student_branch[10],long book_id[10],string book_name[10],string book_author[10],
string book_publish[10],int book_year[100],long lend_student_id[100],long lend_book_id[100],bool lend_check[100],int student_id_count,
int book_count ,int lend_count);

int main(){

	int student_id_count = 2;

	long student_id[10];
	student_id[0] = 100001;
	student_id[1] = 100002;
	
	string student_name[10];
	student_name[0] = "Panachai";
	student_name[1] = "Akaraphon";

	string student_faculty[10];
	student_faculty[0] = "IT";
	student_faculty[1] = "FITM";

	string student_branch[10];
	student_branch[0] = "IT";
	student_branch[1] = "INE";
	
	int book_count = 2;

	long book_id[10];
	book_id[0] = 123001;
	book_id[1] = 123002;

	string book_name[10];
	book_name[0] = "testing Programming";
	book_name[1] = "Intro to IT";

	string book_author[10];
	book_author[0] = "Teacher";
	book_author[1] = "Unknow";

	string book_publish[10];
	book_publish[0] = "thai";
	book_publish[1] = "English";

	int book_year[100];
	book_year[0] = 2554;
	book_year[1] = 2560;

	int lend_count = 2;

	long lend_student_id[100];
	lend_student_id[0] = 100001;
	lend_student_id[1] = 100002;

	long lend_book_id[100];
	lend_book_id[0] = 123002;
	lend_book_id[1] = 123001;

	bool lend_check[100];
	lend_check[0] = false;
	lend_check[1] = true;

	int choose;
	do{
		cout << "========Main Program=========" <<endl;
		cout << "1 ) register student " << endl;
		cout << "2 ) register book " << endl;
		cout << "3 ) lend book " << endl;
		cout << "4 ) sent book " << endl;
		cout << "5 ) report " << endl;
		cout << "6 ) Exit " << endl;
		cout << "choose program for work  : ";
		cin >> choose;
		if(choose == 1){
			student_information (student_name,student_id,student_faculty , student_branch,student_id_count);
		}
		else if(choose ==2){
			book_input(book_id, book_name,book_author,book_publish,book_count);
		}
		else if(choose == 3){
			lend_book(student_id,book_id,lend_student_id,lend_book_id,student_id_count,book_count,lend_check,lend_count);
		}
		else if(choose == 4){
			send_book(lend_student_id,lend_book_id,lend_count,lend_check);
		}
		else if(choose == 5){
			report(student_id,student_name,student_faculty, student_branch, book_id, book_name, book_author,book_publish,book_year,lend_student_id,lend_book_id, lend_check,student_id_count,book_count ,lend_count);
		}
	}while(choose != 6);
}

void lend_book(long student_id[10],long book_id[10],long lend_student_id[100],long lend_book_id[100],int student_id_count,int book_count,bool lend_check[100],int &lend_count){
	long id;
	cout << "Input user student_id : ";
	cin >> id;
	int choose = 0;
	long lend_book;
	for(int n = 0; n < student_id_count;n++){
		if(id == student_id[n]){
			choose++; 
		}
	}
	if(choose !=1){
		cout << "===============================" << endl;
		cout << "Your haven't student_id" << endl;
		cout << "please register student_id" << endl;
		cout << "===============================" << endl;
		return ;
	}
	else{
		int time = 0;
		do{
		cout << "===============================" << endl;
		cout << "input lend book (0 = exit): ";
		cin >> lend_book;
		if(lend_book == 0){
			cout << "Your lend " << time << " time " << endl;
			return;
		}
		else{
			int check_book = 0;
			for(int n = 0; n < book_count;n++){
				if(lend_book == book_id[n]){
				check_book++; 
				}
			}
			if(check_book != 1){
				cout << "===============================" << endl;
				cout << "Error input book" << endl;
				cout << "please try again" << endl;
				cout << "===============================" << endl;
			}
			else{
				lend_count++;
				lend_student_id[lend_count-1] = id;
				lend_book_id[lend_count-1] = lend_book;
				lend_check[lend_count-1] =false;
				time++;
			}
		}
		}while(time < 3);
		cout << "Your lend " << time << " time " << endl;
	}
	cout << endl;
}

void student_information (string student_name[10] , long student_id[10] , string student_faculty [10] , string student_branch[10], int &student_id_count)
{
  string name; 
  int id;
  string faculty; 
  string branch;  
  cout << "Enter Your name : ";
  cin  >> name;
  cout << "Enter Your student code : ";
  cin  >> id;
  cout << "Enter Your faculty :";
  cin  >> faculty;
  cout << "Enter Your branch : ";
  cin  >> branch;
  student_id_count++;
  student_name[student_id_count-1] = name;
  student_id[student_id_count-1] = id;
  student_faculty[student_id_count-1] = faculty;
  student_branch[student_id_count-1] = branch;
  cout << endl;
}

void book_input(long book_id[10], string book_name[10], string book_author[10], string book_publish[10],int &book_count )
{  
	long id;
	string name2, author, publish;
	cout << "Enter book id : ";
	cin >> id;
	cout << "Enter book name : ";
	cin >> name2;
	cout << "Enter book author : ";
	cin >> author;
	cout << "Enter book publish : ";
	cin >> publish;
	book_count++;
	book_id[book_count-1]=id;
	book_name[book_count-1]=name2;
	book_author[book_count-1]=author;
	book_publish[book_count-1]=publish;
	cout << endl;
}

void send_book(long lend_student_id[100],long lend_book_id[100],int lend_count,bool lend_check[100]){
	long student_id;
	long book_id;
	bool check = false;
	cout << "Input student_id for send_book : ";
	cin >> student_id;
	cout << "Input book_id for send_book : ";
	cin >> book_id;
	for(int n = 0 ; n < lend_count ; n++){
		if(student_id == lend_student_id[n] && book_id == lend_book_id[n]){
			if(lend_check[n] == true){
				cout << "========================" <<endl;
				cout << " this book sent " <<endl;
				cout << "========================" <<endl;
				cout << endl;
				return;
			}
			lend_check[n] = true;
			check = true;
		}
	}
	if(check == false){
		cout << "==============================" << endl;
		cout << "no data from lend_book " <<endl;
		cout << "==============================" <<endl;
	}
	else{
		cout << "==============================" << endl;
		cout << "success send_book " <<endl;
		cout << "==============================" << endl;
	}
	cout << endl;
}

void report(long student_id[10], string student_name[10],string student_faculty[10],string student_branch[10],long book_id[10],string book_name[10],string book_author[10],
string book_publish[10],int book_year[100],long lend_student_id[100],long lend_book_id[100],bool lend_check[100],int student_id_count,
int book_count ,int lend_count){
	cout << "=================================================" << endl;
	cout << "report lend book " << endl;
	cout << "=================================================" << endl;
	cout << "student_name\t\tbook_id\t\tcheck" << endl;
	cout << "=================================================" << endl;
	for( int n = 0 ; n < lend_count;n++){
		for(int i = 0;i < student_id_count; i++){
			if(student_id[i] == lend_student_id[n]){
				cout << student_name[i] << "\t\t" << lend_book_id[n] << "\t\t" << (bool)lend_check[n] << endl;
			}
		}
	}
	cout << "==================================================" << endl;
	cout << "report student lend " << endl;
	cout << "==================================================" << endl;
	cout << "student_name\t\tbook_id\t\tcheck" << endl;
	cout << "=================================================" << endl;
	for(int i = 0;i < student_id_count; i++){
		for( int n = 0 ; n < lend_count;n++){
			if(student_id[i] == lend_student_id[n]){
				cout << student_name[i] << "\t\t" << lend_book_id[n] << "\t\t" <<(bool)lend_check[n] << endl;
			}
		}	
		cout << "---------------------------------------------" <<endl;
	}
	cout << "==================================================" << endl;
	cout << "report book not yet lend " << endl;
	cout << "==================================================" << endl;
	cout << "student_name\t\tbook_id\t\tcheck" << endl;
	cout << "=================================================" << endl;
	for( int n = 0 ; n < lend_count;n++){
		for(int i = 0;i < student_id_count; i++){
			if(student_id[i] == lend_student_id[n]){
				if(lend_check[n] == false){
				cout << student_name[i] << "\t\t" << lend_book_id[n] << "\t\t" << (bool)lend_check[n] << endl;
				}
			}
		}
	}
	cout << endl;
}
