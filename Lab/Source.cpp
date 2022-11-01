#include <iostream>

#define MAX 100

using namespace std;

typedef struct movie {
	string title;
	unsigned short year;
	unsigned short rating;
};

typedef struct movieDatabase {
	movie movies[MAX];
	unsigned int count = 0;
};

int menu() {
	cout << "+------------------------+" << endl;
	cout << "| Main Menu |" << endl;
	cout << "+------------------------+" << endl;
	cout << endl << endl;
	cout << "1. Show List of Movies" << endl;
	cout << "2. Search for a Movie" << endl;
	cout << "3. Add a Movie" << endl;
	cout << "4. Delete a Movie" << endl;
	cout << "5. Update a Movie" << endl;
	cout << "6. Find movie with max rating" << endl;
	cout << "7. Find movies of year" << endl;
	cout << "8. Sort movies by rating" << endl;
	cout << "9. Load Movies from File" << endl;
	cout << "10. Exit" << endl << endl;
	cout << "Enter choice: ";
	static int choice = -1;
	cin >> choice;
	return choice;
}


	int main() {
		menu();

	};