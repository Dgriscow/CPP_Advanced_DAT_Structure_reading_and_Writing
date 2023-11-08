#include "InvoiceCreator.h"

void InvoiceCreator::createNewUser()
{

	Info newUser; // new user to be created
	
	char response;

	string input; //important input from the user 

	fstream userFile("people.dat", ios::out | ios::binary);

	if (!userFile) {
		cout << "Error Opening File\n";
		exit(-1);
	}

	//do while loop for getting users input and asking the user if they want to add more
	do {

		cout << "Enter person information:\n";
		cout << "Name: ";
		getline(cin, input);
		strcpy_s(newUser.name, input.c_str()); //copies the array of chars to a string
		cout << "Age: ";
		cin >> newUser.age;
		cin.ignore(); // Skip over remaining newline
		cout << "Address line 1: ";
		getline(cin, input);
		strcpy_s(newUser.address1, input.c_str());
		cout << "Address line 2: ";
		getline(cin, input);
		strcpy_s(newUser.address2, input.c_str());
		cout << "Phone: ";
		getline(cin, input);
		strcpy_s(newUser.phone, input.c_str());
		userFile.write(reinterpret_cast<char*>(&newUser),
			sizeof(newUser));
		cout << "Do you want to enter another record? ";
		cin >> response;
		cin.ignore();

	} while (toupper(response) == 'Y');


}

void InvoiceCreator::pullUsers()
{
	Info persons;

	char response; //users Reponse 

	fstream usersFile("people.dat", ios::in | ios::binary);

	if (!usersFile) {
		cout << "Error Opening the File, aborting program";
		exit(-1);
	}

	cout << "Here are the Users Currently Stored\n\n\n";

	int recordSize = sizeof(persons); //Size of The Record

	cout << "Record Size: " << recordSize << endl << endl;


	// Read one structure at a time and echo to screen
	usersFile.read(reinterpret_cast<char*>(&persons), recordSize); 


	while (!usersFile.eof()) {

		cout << "Name: ";
		cout << persons.name << endl;
		cout << "Age: ";
		cout << persons.age << endl;
		cout << "Address line 1: ";
		cout << persons.address1 << endl;
		cout << "Address line 2: ";
		cout << persons.address2 << endl;
		cout << "Phone: ";
		cout << persons.phone << endl;
		cout << "\nStrike any key to see the next record.\n";

		cin.get(response);

		usersFile.read(reinterpret_cast<char*>(&persons),
			recordSize); //after reading a user, ask the USER if they want to read another one



	}
	cout << "That's all the information in the file!\n";
	usersFile.close();
	





}
