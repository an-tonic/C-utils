#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

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

string printMovie(movie& m) {

	return m.title + '\t' + std::to_string(m.year) + "\t" + std::to_string(m.rating) + "\n";


}

void showMovies(movieDatabase& db) {

	if (db.count == 0) {
		cout << "Empty database" << endl;
	}
	else {
		for (int i = 0; i < db.count; i++) {
			cout << printMovie(db.movies[i]);
		}
	}
}


int menu() {
	cout << "+------------------------+" << endl;
	cout << "|Main Menu|" << endl;
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

void loadDataBase(movieDatabase& db) {
	ifstream file("movies.csv");

	string title;
	string syear;
	string srating;
	unsigned short year;
	unsigned short rating;

	db.count = 0;

	getline(file, title);
	

	while (file.good()) {
		getline(file, title, ',');
		getline(file, syear, ',');
		getline(file, srating, '\n');

		year = stoi(syear);
		rating = stoi(srating);


	}

}

unsigned int findMovie(movieDatabase& db, string key) {
	//search for a movie with a title equal to the key
	//if one is found, return the key
	//otherwise, return -1
	for (int i = 0; i < db.count; i++)
		if (db.movies[i].title == key) return i;

	return -1;
}

void deleteMovie(movieDatabase& db, string key) {
	int index = findMovie(db, key);
	if (index != -1) {
		db.movies[index] = db.movies[db.count-1];
		db.count--;
	}

}

int main() {
	movieDatabase db;

	menu();
		


};