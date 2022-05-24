#include<iostream>
using namespace std;



struct record
{
	int roll_No;
	char name[50];
	char division[50];
	char address[50];

public:

	void Get_Data();
	void Display();
};

void record::Get_Data()
{
	cout << "Enter roll number : ";
	cin >> roll_No;
	cin.ignore(10000, '\n');
	cout << "Enter name : ";
	cin.getline(name, 100, '\n');
	cout << "Enter division : ";
	cin.getline(division, 100, '\n');
	cout << "Enter the address : ";
	cin.getline(address, 100, '\n');
}
void record::Display()
{
	cout << "Roll number : ";
	cout << roll_No << "\n";
	cout << "Name : " << name << "\n";
	cout << "Division : " << division << "\n";
	cout << "Address : " << address << "\n";
}

int main()
{	
	int index[10];
	record* File[100];
	record student;

	for (int i = 0; i < 10; i++)
		index[i] = i * 10;
	
	for (int i = 0; i < 100; i++)
		File[i] = NULL;

	cout << "Enter new record press 'w' :\n";
	cout << "Delete record press 'd' :\n";
	cout << "Search record press 's' :\n";
	cout << "To Exit press 'e' : \n";

	char op = 0;
	bool pos = 0;
	int r = 0;
	int hashed = -1;
	int ind = -1;
	while (op != '@')
	{
		r = 0;
		pos = 0;
		cout << "\nInput : ";
		cin >> op;
		switch (op)
		{
		case 'w':
			student.Get_Data();
			hashed = student.roll_No % 100;
			ind = -1;
			for (int i = 0; i < 10; i++)
			{
				int hash = i * 10;
				if (hashed < hash)
				{
					ind = hash - 10;
				}
			}

			for (int i = ind; i < (ind + 100); i++)
			{
				if (File[i%100] == NULL)
				{
					File[i%100] = new record();
					*File[i%100] = student;
					cout << "Student record written.....\n";
					pos = 1;
					break;
				}
			}
			if (!pos)cout << "File is Full.....\n";
			break;

		case 's':
			cout << "Enter the roll no : ";
			cin >> r;

			hashed = r % 100;

			for (int i = 0; i < 10; i++)
			{
				int hash = i * 10;
				if (hashed < hash)
				{
					ind = hash - 10;
				}
			}
			for (int i = ind; i < (ind + 100); i++)
			{
				if (File[i % 100] != NULL && File[i%100]->roll_No == r)
				{
					
					cout << "Student record "<<r<<" found.....\n";
					File[i % 100]->Display();
					cout << "\n";
					pos = 1;
				}
			}
			if (!pos)cout << "Student record " << r << " Not found\n";
			break;

		case 'd':
			cout << "Enter the roll no : ";
			cin >> r;

			hashed = r % 100;

			for (int i = 0; i < 10; i++)
			{
				int hash = i * 10;
				if (hashed < hash)
				{
					ind = hash - 10;
				}
			}
			for (int i = ind; i < (ind + 100); i++)
			{
				if (File[i % 100] != NULL && File[i % 100]->roll_No == r)
				{
					delete File[i % 100];
					File[i % 100] = NULL;
					cout << "Student record"<< r << "Delete.....\n";
					cout << "\n";
				}
			}

			break;

		case 'e':
			op = '@';
			break;

		default:
			break;
		}
	}

	return 0;
}
