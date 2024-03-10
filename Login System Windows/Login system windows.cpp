#include <iostream>
#include <fstream>
#include <string>


bool IsLoggedIn() {
	std::string username, password, un, pass;

	std::cout << "Enter username: ";	std::cin >> username;
	std::cout << "Enter password: ";	std::cin >> password;

	std::ifstream read("c:\\" + username + ".txt");
	getline(read, un);
	getline(read, pass);

	if (un == username && pass == password) return true;
	else return false;
}


int main() {
	int choice;
	std::cout << "1: Register\n2: Login\nYour choise: "; std::cin >> choice;
	
	if (choice == 1) {
		std::string username, password;
		std::cout << "select a username: "; std::cin >> username;
		std::cout << "select a password: "; std::cin >> password;

		std::ofstream file;
		file.open("c:\\" + username + ".txt");
		file << username << std::endl << password;
		file.close();
		system("PAUSE");
		return 10;
	}

	else if (choice == 2) {
		bool status = IsLoggedIn();

		if (!status) {
			std::cout << "False Login!\n";
			system("PAUSE");
			return 0;
		}
		else {
			std::cout<< "Succesfully logged in!\n";
			system("PAUSE");
			return 1;
		}
	}
	else {
		std::cout << "Fatal Error\n"; return 404;
	}
}