#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<stdlib.h>
using namespace std;
int stoi(string s );

void search_record()
{


	fstream fin;


	fin.open("data.csv", ios::in);


	int rollnum, roll2, count = 0;
	cout << "Enter The Roll Number "
		<< "Of The Student To Display Details: ";
	cin >> rollnum;


	vector<string> row;
	string line, word, temp;

	while (fin >> temp) {

		row.clear();


		getline(fin, line);


		stringstream s(line);


		while (getline(s, word,',')) {


			row.push_back(word);

		}


		roll2 = stoi(row[1]);


		if (roll2 == rollnum) {


			count = 1;
			cout << "Details of Roll " << row[1] << " : \n";
			cout << "Name: " << row[0] << "\n";
			cout << "STANDARD: " << row[2] << "\n";

			break;
		}
	}
	if (count == 0)
		cout << "Record not found\n";
}

void create_record()
{

	fstream fout;


	fout.open("data.csv", ios::out | ios::app);



	int  roll;
	string name, standard;


        cout << "ENTER NAME: ";
		cin >> name;
		cout << "ENTER ROLL NO: ";
		cin  >> roll;
		cout << "ENTER STANDARD: ";
        cin  >> standard;


		fout<< "data" << ", "
            << name << ", "
			<< roll << ", "
			<< standard << "\n";
	}

void update_recode()
{


	fstream fin, fout;


	fin.open("data.csv", ios::in);


	fout.open("datanew.csv", ios::out);

	int rollnum, roll1, marks, count = 0, i;
	char choice;
	int index;
	string new_marks;
	string line, word;
	vector<string> row;


	cout << "Enter the roll number "
		<< "of the record to be updated: ";
	cin >> rollnum;


	cout << "WHAT DO YOU WANT TO UPDATE "
         << "(NAME=N/n STD=S/s ROLLNO=R/r) ";
	cin >> choice;


	if (choice == 'N' || choice == 'n')
		index = 1;
	else if (choice == 'S' || choice == 's')
		index = 3;
	else if (choice == 'R' || choice == 'r')
		index = 2;
	else {
		cout << "Wrong choice.Enter again\n";

	}


	cout << "Enter New Detail: ";
	cin >> new_marks;


	while (!fin.eof()) {

		row.clear();

		getline(fin, line);
		stringstream s(line);

      while (getline(s, word,',')) {
			row.push_back(word);
		}

		roll1 = stoi(row[2]);

		int row_size = row.size();

		if (roll1 == rollnum) {
			count = 1;
			stringstream convert;


			convert << new_marks;


			row[index] = convert.str();

			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {


					fout << row[i] << ", ";
				}

				fout << row[row_size - 1] << "\n";
			}
		}
		else {
			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {


					fout << row[i] << ", ";
				}


				fout << row[row_size - 1] << "\n";
			}
		}
		if (fin.eof())
			break;
	}
	if (count == 0)
		cout << "Record not found\n";

	fin.close();
	fout.close();


	remove("data.csv");


	rename("datanew.csv", "data.csv");
}

void view_record()
{
    cout << "\n";

 ifstream ip("data.csv");


 if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string data;
    string name;
    string rollno;
    string stand;

  while(ip.good()){
    getline(ip,data,',');
    getline(ip,name,',');
    getline(ip,rollno,',');
    getline(ip,stand,'\n');

   std::cout << "Name: "<<name<<  '\n';

    std::cout << "Rollno: "<<rollno << '\n';

    std::cout << "Std: "<<stand << '\n';

    std::cout << "-------------------" << '\n';
  }


  ip.close();

}

void delete_record()
{


	fstream fin, fout;


	fin.open("data.csv", ios::in);


	fout.open("datanew.csv", ios::out);

	int rollnum, roll1, count = 0, i;
	string line, word;
	vector<string> row;


	cout << "Enter The Roll Number "
		<< "Of The Record To Be Deleted: ";
	cin >> rollnum;


	while (!fin.eof()) {

		row.clear();
		getline(fin, line);
		stringstream s(line);

		while (getline(s, word,',')) {
			row.push_back(word);
		}

		int row_size = row.size();
		roll1 = stoi(row[2]);


		if (rollnum != roll1) {
			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {
					fout << row[i] << ", ";
				}
				fout << row[row_size - 1] << "\n";
			}
		}
		else {
			count = 1;
		}
		if (fin.eof())
			break;
	}
	if (count == 1)
		cout << "Record deleted\n";
	else
		cout << "Record not found\n";


	fin.close();
	fout.close();


	remove("data.csv");


	rename("datanew.csv", "data.csv");
}

int main()
{
    int i;
    loop:do
    {
    system("cls");
        cout << "-----------------" << endl;
    cout << "-----------------" << endl;
    cout << "STUDENT MANAGMENT" << endl;
    cout << "-----------------" << endl;
    cout << "VERSION 2.0" << endl;
    cout << "-----------------" << endl;
    cout << "CREATED BY ABDUL MANNAN" << endl;
   // cout << " CREATED BY AB.MANNAN" << endl;
    cout << "-----------------" << endl;
    cout << "-----------------" << endl;
    cout << "\n" << endl ;

    int option;


    cout << "1] SEARCH RECORD" << endl;
    cout << "2] NEW RECORD" << endl;
    cout << "3] REMOVE RECORD" << endl;
    cout << "4] UPDATE RECORD" << endl;
    cout << "5] VIEW ALL RECORD" << endl;
    cout << "\nENTER YOUR CHOICE:  ";
    cin >> option ;
    switch(option){
    case 1:
        {
            search_record();
            break;
        }
    case 2:
        {
            create_record();
            break;
        }
    case 3:
        {
            delete_record();
            break;
        }
    case 4:
        {
            update_recode();
            break;
        }
    case 5:
        {
            view_record();
            break;
        }


}
    cout << "Do You Want To Continue(Y/N): ";
    char choice ;
    cin >> choice;
    if(choice =='y' || choice=='Y')
   {
       goto loop;
   }
    else
    {
        exit(EXIT_SUCCESS);
    }
   }while(i<100);

return 0;
}
int stoi(string s)
{
    stringstream ss(s);

    int num;
    ss>>num;
    return num;
}
