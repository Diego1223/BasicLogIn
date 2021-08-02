#include <iostream>
#include <string.h>
#include <conio.h> //To use the getch method
using namespace std;

int main() {
	const int len = 80;
	char user[len], password[len];
	int attempts = 0;
	bool getInto = false;
	char character;
	int i = 0;

	do {
		system("cls");
		i = 0;
		cout << "\n\t\t\t\t\t\t\tLog In" << endl;
		cout << "\t\t\t\t\t\t\t------" << endl;

		cout << "\n\t\tUser => "; cin.getline(user, 20, '\n');
		cout << "\n\t\tPassword => ";

		//In Visual studio, we can't use getch, we've to use _getch()
		while (character = _getch()) {
			//13 -> Enter key
			if (character == 13) {
				//Null character -> '\0';
				//This character indicates the end of a string -> '\0'
				password[i] = '\0';
				break;
			}
			//This is the backSpace key / Tecla de borrado
			else if (character == 8) {
				if (i > 0) {
					i--;
					//'\b', it moves the cursor to the right
					cout << "\b \b";
				}
			}
 			else {
				if (i < len) {
					cout << "*";
					password[i] = character;
					i++;
				}
			}
		}
		if ((strcmp(user, "root") == 0) && (strcmp(password, "tor") == 0)) {
			getInto = true;
		}
		else {
			cout << "\a"; //Beep
			cout << "\n\t\tUsername and/or password wrong" << endl;
			attempts++;
			getchar();
		}
	} while ((attempts < 3) && (getInto == false));

	if (getInto == true) {
		cout << "\n\t\tWelcome to the System!";
	}
	else {
		cout << "\n\t\tYou can't log in, because You exceeded the number of attempts";
	}
	_getch();
	return 0;
}