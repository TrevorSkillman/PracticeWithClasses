#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
	string title;
	string author;
	int year;
	bool available;
public:
	// default constructor
	Book(string title, string author, int year, bool available) : title(title), author(author), year(year), available(available){}
	
	// setters and getters
	void setTitle(string title) {
		this->title = title;
	}

	string getTitle() const {
		return title;
	}
	
	void setAuthor(string author) {
		this->author = author;
	}
	
	string getAuthor() const {
		return author;
	}

	void setYear(int year) {
		this->year = year;
	}
	
	int getYear() const {
		return year;
	}
	
	void setAvailable(bool available) {
		this->available = available;
	}
	
	bool getAvailable() {
		return available;
	}
	// method to display book information
	void displayBookInfo() {
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "Year: " << year << endl;
		cout << "Available: " << (available ? "Yes" : "No") << endl; // learning about using ? and : as the if else statements and decided to add it in to this line to check if book is available or not
		cout << endl;
	}
};

class Library {
private:
	vector<Book> books;
public:
	// Methods
	// adding a book
	void addBook(string title, string author, int year, bool available) {
		Book aBook(title, author, year, available);
		books.push_back(aBook);
	}

	/// DELETE FUNCTION
	void deleteBook(string title) {
		// looping through the vector of books, using "auto" to automatically understand the type of variable from its initializer. Its usefule when the type is long, complicated, or difficult to specify
		for (auto it = books.begin(); it != books.end(); ++it) {
			// getting the book by the title for the specific book being deleted
			if (it->getTitle() == title) {
				books.erase(it); // deleting it
				return;
			}
		}
		// printing message if the book was not found
		cout << "Book not found in the library." << endl;
	}

	void searchTitle(string title) {
		for (auto i = books.begin(); i != books.end(); ++i) {
			if (i->getTitle() == title) {
				i->displayBookInfo();
			}
		}
	}

	void searchAuthor(string author) {
		for (auto i = books.begin(); i != books.end(); i++) {
			if (i->getAuthor() == author) {
				i->displayBookInfo();
			}
		}
	}

	bool borrowBook(string title) {
		for (auto& book : books) {
			if (book.getTitle() == title) {
				if (book.getAvailable()) {
					book.setAvailable(false);
					return true; // successfully borrowed
				}
				else {
					return false; // book is already borrowed
				}
			}
		}
		return false; // book not found
	}
	// Creating a function to return the book or books
	bool returnBook(string title) {
		for (auto& book : books) {
			if (book.getTitle() == title) {
				if (!book.getAvailable()) {
					book.setAvailable(true);
					return true; // successfully returned
				}
				else {
					return false; // book was never taken out.
				}
			}
		}
		return false;
	}
	// function to display all of the books in the library
	void displayAllBooks() {
		// this is a range-based for loop that iterates over each "Book" object in the "books" vector. "auto&" is used to deduce the type of the elements in "books" vector and create a reference to each element.
		for (auto& book : books) {
			// for each "Book" object in the vector this calls the "displayBookInfo" method which should print out the details of the book. 
			book.displayBookInfo();
		}
	}

	// display available books function
	void displayAvailableBooks() {
		for (auto& book : books) {
			if (book.getAvailable()) {
				book.displayBookInfo();
			}
		}
	}

};

int main() {
	Library library; // creating library instance
	int choice;
	string title, author;
	int year;
	bool available;
	
	
	do {
		cout << "Welcome to the Library! Please choose from the following options!\n";
		cout << "1.) Add a book: \n";
		cout << "2.) Delete a book: \n";
		cout << "3.) Search by Title: \n";
		cout << "4.) Search by Author: \n";
		cout << "5.) Borrow a book: \n";
		cout << "6.) Return a book: \n";
		cout << "7.) Display all books: \n";
		cout << "8.) Display all available books: \n";
		cout << "9.) Exit... \n";
		cin >> choice;
		cin.ignore(); // clears out the newline character left in the buffer

		switch (choice) {
		case 1:
			cout << "Enter the book title: \n";
			getline(cin, title);
			cout << "Enter the author of the book: \n";
			getline(cin, author);
			cout << "Enter the year of the book: \n";
			cin >> year;
			cin.ignore();
			cout << "Is the book available (1 for yes, 0 for no): \n";
			cin >> available;
			cin.ignore();
			library.addBook(title, author, year, available);
			break;
		case 2:
			cout << "Enter the title of the book you wish to delete: \n";
			getline(cin, title);
			library.deleteBook(title);
			break;
		case 3:
			cout << "Enter the title of the book you wish to find: \n";
			getline(cin, title);
			library.searchTitle(title);
			break;
		case 4:
			cout << "Enter the name of the author you wish to find: \n";
			getline(cin, author);
			library.searchAuthor(author);
			break;
		case 5:
			cout << "Enter the book you wish to borrow: \n";
			getline(cin, title);
			if (library.borrowBook(title)) {
				cout << "You have successfully borrowed the book!" << endl;
			}
			else {
				cout << "Failed to borrow the book. It might already be borrowed.\n";
			}
			break;
		case 6:
			cout << "Enter the title of the book you are returning: \n";
			getline(cin, title);
			if (library.returnBook(title)) {
				cout << "You have successfully returned the book!" << endl;
			}
			else {
				cout << "Failed to return the book. It might already be in the system.\n";
			}
			break;
		case 7:
			library.displayAllBooks();
			break;
		case 8:
			library.displayAvailableBooks();
			break;
		case 9:
			cout << "Peace out!\n";
			break;
		default:
			cout << "Invalid choice! Please try again.\n";
			break;

		} 

	} while (choice != 7);

	return 0;
}