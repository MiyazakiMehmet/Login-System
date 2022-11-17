#include "Login_system.h"

void Application::introduction() {
	cout << "\t\t\t|_________________________Welcome to logining system_________________________|" << endl;
	cout << "\t\t\t|____________________________________________________________________________|" << endl;
	cout << "\t\t\t|____________________________________________________________________________|" << endl;
	cout << "\t\t\t|_____________________________________Main___________________________________|\n" << endl;
	cout << "\t\t\t|___________________________Please select an option__________________________|\n" << endl;
	cout << "\t\t\t1-)Login\n\t\t\t2-)Registiration\n\t\t\t3-)Exit" << endl;
	cout << "\t\t\tPlease enter your selection here: ";
}
void Application::main() {
	int selection;
	Application::introduction();
	cin >> selection;
	reset:
	switch (selection) {
	case 1:
		Application::login();
		break;
	case 2:
		Application::registiration();
		break;
	case 3:
		cout << "OK, bye! \n";
		break;
	default:
		do {
			cout << "Please enter a valid number: ";
			cin >> selection;
		}while(!(selection > 0 && selection <= 3));
		goto reset;
	}

}

void Application::login() {
	system("cls");
	string input_id, input_pass, id, pass;
	bool correct = false;
	char select, forgot;
	int attempt = 3;
	ifstream file("C:\\Users\\PC\\Desktop\\Trial.txt", ios::in);
	cout << "Username: ";
	cin >> input_id;
	cout << "\nPassword: ";
	cin >> input_pass;
	reset:
	while (file >> id >> pass) {
		if (input_id == id && input_pass == pass) {
			correct = true;
			system("cls");
			break;
		}
	}
	if (correct) {
		cout << "\nSuccessfully logged in!";

	}
	else {
		while(input_id != id && input_pass != pass && attempt) {
			system("cls");
			cout << "\nYour username or password is incorrect, please try again(remaining attempt: " << attempt << ")" <<endl;
			cout << "\nUsername: ";
			cin >> input_id;
			cout << "\nPassword: ";
			cin >> input_pass;
			attempt--;
			goto reset;
		}
		system("cls");
		cout << "Forgot your password? (Y/N) ";
		cin >> forgot;
		if (toupper(forgot) == 'Y') {
			Application::main();
		}
		else {
			system("cls");
			cout << "Do you want to register? (Y/N) ";
			cin >> forgot;
			if (toupper(forgot) == 'Y') {
				Application::registiration();
			}
		}
	}
	file.close();
}
void Application::registiration() {
	system("cls");
	string input_id, input_pass,input_pass2;
	cout << "Username: ";
	cin >> input_id;
	cout << "\nPassword: ";
	cin >> input_pass;
	do {
		cout << "\nPassword again: ";
		cin >> input_pass2;
	} while (input_pass != input_pass2);
	ofstream file1("C:\\Users\\PC\\Desktop\\Trial.txt", ios::ate);
	file1 << input_id << ' ' << input_pass << endl;
	cout << "Successfully registered!";
	system("cls");
	Application::main();

}
