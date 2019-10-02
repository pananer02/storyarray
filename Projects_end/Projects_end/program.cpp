#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

void lend_book(string student_id[10],string book_id[10],string lend_student_id[100],string lend_book_id[100],
int student_id_count,int book_count,bool lend_check[100],int book_item[10],int &lend_count,string time_out[100],string time_in[100]);

void book_input(string book_id[10], string book_name[10], string book_author[10], string book_publish[10],int book_item[10],int &book_count);

void student_information (string student_name[10] , string student_id[10] , string student_faculty [10] , string student_branch[10],
int &student_id_count);

void send_book(string lend_student_id[100],string lend_book_id[100],int lend_count,bool lend_check[100],string book_id[10],int book_item[10],int book_count,string time_out[100]);

void report(string student_id[10], string student_name[10],string student_faculty[10],string student_branch[10],string book_id[10],string book_name[10],string book_author[10],
string book_publish[10],string lend_student_id[100],string lend_book_id[100],bool lend_check[100],int student_id_count,
int book_count ,int lend_count,int book_item[10],string time_out[100],string time_in[100]);

int main(){

	int student_id_count = 2;

	string student_id[10];
	student_id[0] = "100001";
	student_id[1] = "100002";
	
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

	string book_id[10];
	book_id[0] = "123001";
	book_id[1] = "123002";

	string book_name[10];
	book_name[0] = "Programming";
	book_name[1] = "Intro to IT";

	string book_author[10];
	book_author[0] = "Teacher";
	book_author[1] = "Unknow";

	string book_publish[10];
	book_publish[0] = "thai";
	book_publish[1] = "English";

	int book_item[10];
	book_item[0] = 1;
	book_item[1] = 1;

	int lend_count = 3;

	string lend_student_id[100];
	lend_student_id[0] = "100001";
	lend_student_id[1] = "100002";
	lend_student_id[2] = "100001";

	string lend_book_id[100];
	lend_book_id[0] = "123002";
	lend_book_id[1] = "123001";
	lend_book_id[2] = "123001";

	bool lend_check[100];
	lend_check[0] = false;
	lend_check[1] = true;
	lend_check[2] = true;

	string time_in[100];
	time_in[0] = "September 1 ,2019";
	time_in[1] = "September 13 ,2019";
	time_in[2] = "September 4 ,2019";


	string time_out[100];
	time_out[0] = "-";
	time_out[1] = "September 15 ,2019";
	time_out[2] = "September 14 ,2019";

	string choose;
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
		if(choose == "1"){
			student_information (student_name,student_id,student_faculty , student_branch,student_id_count);
		}
		else if(choose =="2"){
			book_input(book_id, book_name,book_author,book_publish,book_item,book_count);
		}
		else if(choose == "3"){
			lend_book(student_id,book_id,lend_student_id,lend_book_id,student_id_count,book_count,lend_check,book_item,lend_count,time_out,time_in);
		}
		else if(choose == "4"){
			send_book(lend_student_id,lend_book_id,lend_count,lend_check,book_id,book_item,book_count,time_out);
		}
		else if(choose == "5"){
			report(student_id,student_name,student_faculty, student_branch, book_id, book_name, book_author,book_publish,lend_student_id,lend_book_id, lend_check,student_id_count,book_count ,lend_count,book_item,time_out, time_in);
		}
	}while(choose != "6");
}

void lend_book(string student_id[10],string book_id[10],string lend_student_id[100],string lend_book_id[100],
int student_id_count,int book_count,bool lend_check[100],int book_item[10],int &lend_count,string time_out[100],string time_in[100]){
	char date_string[100];
	char time_string[100];
	time_t curr_time;
	tm * curr_tm;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
	curr_tm = localtime(&curr_time);
	strftime(date_string, 50, " %B %d, %Y", curr_tm);
	string id;
	cout << "Input user student_id : ";
	cin >> id;
	int choose = 0;
	string lend_book;
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
		if(lend_book == "0"){
			cout << "Your lend " << time << " time " << endl;
			return;
		}
		else{
			int check_book = 0;
			for(int n = 0; n < book_count;n++){
				if(lend_book == book_id[n]){
					if(book_item[n] == 0){
						cout << "=========================" <<endl;
						cout << "Out of Book" << endl;
						cout << "=========================" <<endl;
					}
					else{
						book_item[n]--;
						check_book++; 
					}
				}
			}
			if(check_book != 1){
				cout << "===============================" << endl;
				cout << "Error input book" << endl;
				cout << "please try again" << endl;
				cout << "===============================" << endl;
			}
			else{
				lend_student_id[lend_count] = id;
				lend_book_id[lend_count] = lend_book;
				lend_check[lend_count] =false;
				time_in[lend_count] = date_string ;
				time_out[lend_count] = "-";
				time++;
				lend_count++;
			}
		}
		}while(time < 3);
		cout << "Your lend " << time << " time " << endl;
	}
	cout << endl;
}

void student_information (string student_name[10] , string student_id[10] , string student_faculty [10] , string student_branch[10], int &student_id_count)
{
	 int test = 1;
	 string name; 
	 string id;
	 string faculty; 
	 string branch;  
	 cout << "Enter Your name : ";
	 cin  >> name;
	 cout << "Enter Your student code : ";
	 cin  >> id;
	 bool testnum = true;
	 for(int n = 0;n < id.length();n++){
		 if(isdigit(id.at(n))){
		 }
		 else{
			 testnum = false;
		 }
	 }
	 if(testnum){
		for(int a = 0;a < student_id_count;a++){
			 if(id == student_id[a]){
				 test++;
			 }
		 }
		 if(test == 1){
			 student_id_count++;
			 student_name[student_id_count-1] = name;
			 student_id[student_id_count-1] = id;
			 cout << "Enter Your faculty : ";
			 cin  >> faculty;
			 cout << "Enter Your branch : ";
			 cin  >> branch;
			 student_faculty[student_id_count-1] = faculty;
			 student_branch[student_id_count-1] = branch;
		  	 cout << endl;
		 }else{   
			cout << "can't use student it!" <<endl;
		 }
	 }else{
		 cout <<"Error input id student" <<endl;
	 }
 
}

void book_input(string book_id[10], string book_name[10], string book_author[10], string book_publish[10],int book_item[10],int &book_count )
{  
	int test = 1;
	string id;
	string name2, author, publish;
	cout << "Enter book id : ";
	cin >> id;
	bool testnum = true;
	for(int n = 0;n < id.length();n++){
		 if(isdigit(id.at(n))){
		 }
		 else{
			 testnum = false;
		 }
	 }
	 if(testnum){
		 for(int a = 0;a < book_count;a++){
			 if(id == book_id[a]){
				 test++;
			 }
		 }
		 if(test == 1){
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
		book_item[book_count-1] = 2;
		cout << endl;
		 }else{   
			cout << "can't use book it!" <<endl;
		 }
	 }else{
		 cout << "Error Input book it " <<endl;
	 }
}

void send_book(string lend_student_id[100],string lend_book_id[100],int lend_count,bool lend_check[100],string book_id[10],int book_item[10],int book_count,string time_out[100]){
	char date_string[100];
	time_t curr_time;
	tm * curr_tm;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
	curr_tm = localtime(&curr_time);
	strftime(date_string, 50, " %B %d, %Y", curr_tm);
	time_t t;
	time(&t);
	string student_id;
	string book_id_send;
	bool check = false;
	cout << "Input student_id for send_book : ";
	cin >> student_id;
	do{
		check = false;
		cout << "Input book_id for send_book ( 0 to exit) : ";
		cin >> book_id_send;
		if(book_id_send == "0"){
		return;
	}
	for(int n = 0 ; n < lend_count ; n++){
		if(student_id == lend_student_id[n] && book_id_send == lend_book_id[n]){
			if(lend_check[n] == true){
				cout << "========================" <<endl;
				cout << " can't send book again " <<endl;
				cout << "========================" <<endl;
			}
			else{
				for(int i = 0 ; i < book_count;i++){
					if(book_id_send == book_id[i]){
						book_item[i]++;
					}
				}
				time_out[n] = date_string;
				lend_check[n] = true;
				check = true;
			}
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
	}while(book_id_send != "0");
	cout << endl;
}

void report(string student_id[10], string student_name[10],string student_faculty[10],string student_branch[10],string book_id[10],string book_name[10],string book_author[10],
string book_publish[10],string lend_student_id[100],string lend_book_id[100],bool lend_check[100],int student_id_count,
int book_count ,int lend_count,int book_item[10],string time_out[100],string time_in[100]){
	cout << setfill('=') << setw(165) <<"="<<setfill(' ') <<endl;
	cout << setw(60) << "report lend book" << endl;
	cout << setfill('=') << setw(165)<<"="<< endl;
	cout << setfill(' ')<<setw(10)<< "student code"<<setw(15)<< "student_name"<<setw(10)<<"faculty"<<setw(10)<<"branch"<<setw(15)<<"book id"<<setw(15)<<"book name"<<setw(10)<<"check" << setw(20) << "day lend" << setw(30) <<"day send" <<endl;
	cout << setfill('-') << setw(165)<<"-" << setfill(' ')<< endl;
	for( int n = 0 ; n < lend_count;n++){
		for(int i = 0;i < student_id_count; i++){ 
			for(int a = 0;a < book_count; a++){
			if(student_id[i] == lend_student_id[n] && lend_book_id[n] == book_id[a]){
				cout << setw(10)<<student_id[i]<<setw(15)<<student_name[i]<<setw(10)<< student_faculty[i] << setw(13)<< student_branch[i] << setw(12)<< book_id[a] <<setw(17)<< book_name[a] <<  setw(10)<<  boolalpha << lend_check[n] << setw(25) << time_in[n] <<setw(30)<<time_out[n];
				cout << endl << endl;;
				}
			}
		}
	}
	cout << endl << endl;
	cout << setfill('=') << setw(165) <<"="<<setfill(' ') << endl;
	cout << setw(60)<<"report student lend  " << endl;
	cout << setfill('=') << setw(165)<<"=" << endl;
	cout << setfill(' ')<<setw(10)<< "student code"<<setw(15)<< "student_name"<<setw(10)<<"faculty"<<setw(10)<<"branch"<<setw(15)<<"book id"<<setw(15)<<"book name"<<setw(10)<<"check" << setw(20) << "day lend" << setw(30) <<"day send" <<endl;
	cout << setfill('-') << setw(165)<<"-" << setfill(' ')<< endl;
	for(int i = 0;i < student_id_count; i++){
		for( int n = 0 ; n < lend_count;n++){
			for(int a = 0;a < book_count; a++){
			if(student_id[i] == lend_student_id[n] && lend_book_id[n] == book_id[a]){
				cout << setw(10)<<student_id[i]<<setw(15)<<student_name[i]<<setw(10)<< student_faculty[i] << setw(13)<< student_branch[i] << setw(12)<< book_id[a] <<setw(17)<< book_name[a] <<  setw(10)<<  boolalpha << lend_check[n] << setw(25) << time_in[n] <<setw(30)<<time_out[n];
				cout << endl << endl;
				}
			}
		}	
		cout << setfill('-') << setw(165) <<"-" << setfill(' ') << endl;
	}
	cout << endl << endl;
	cout << setfill('=') << setw(165)<<"="<<setfill(' ')  << endl;
	cout << setw(60) << "report book not yet lend" << endl;
	cout << setfill('=') << setw(165)<<"=" << endl;
	cout << setfill(' ')<<setw(10)<< "student code"<<setw(15)<< "student_name"<<setw(10)<<"faculty"<<setw(10)<<"branch"<<setw(15)<<"book id"<<setw(15)<<"book name"<<setw(10)<<"check" << setw(20) << "day lend" << setw(30) <<"day send" <<endl;
	cout << setfill('-') << setw(165)<<"-" << setfill(' ') << endl;
	for( int n = 0 ; n < lend_count;n++){
		for(int i = 0;i < student_id_count; i++){
			for(int a = 0;a < book_count; a++){
			if(student_id[i] == lend_student_id[n]  && lend_book_id[n] == book_id[a]){
					if(lend_check[n] == false){	
					cout << setw(10)<<student_id[i]<<setw(15)<<student_name[i]<<setw(10)<< student_faculty[i] << setw(13)<< student_branch[i] << setw(12)<< book_id[a] <<setw(17)<< book_name[a] <<  setw(10)<<  boolalpha << lend_check[n] << setw(25) << time_in[n] <<setw(30)<<time_out[n];	
					cout << endl << endl;
					}
				}
			}
		}
	}
	cout << endl << endl;
	cout << setfill('=') << setw(165)<<"="<<setfill(' ')  << endl;
	cout << setw(60) << "book list" << endl;
	cout << setfill('=') << setw(165)<<"=" << endl;
	cout << setfill(' ')<<setw(10)<<"book id"<< setw(15)<<"book name"<<setw(15)<<"book author" << setw(15) <<"book publish"<<setw(15)<<"Num of book" <<endl;
	cout << setfill('-') << setw(165)<<"-" << setfill(' ') << endl;
	for(int n = 0 ;n < book_count;n++){
		cout <<setw(10)<<book_id[n] <<setw(17)<< book_name[n]  <<  setw(12)<<book_author[n] << setw(12) << book_publish[n] << setw(12) << book_item[n] << endl;
		cout <<endl;

	}
	cout << endl;
}
