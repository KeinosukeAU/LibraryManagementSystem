#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool availability;
    string format;
    int fileSize;
    string location;

public:
    // Set book details
    void setBookDetails(string t, string a, string isbn, string fmt, int fSize, string loc) {
        title = t;
        author = a;
        ISBN = isbn;
        availability = true; // Default to available
        format = fmt;
        fileSize = fSize;
        location = loc;
    }

    // Display book details
    void displayBookDetails() {
        cout << "Title: " << title << "\nAuthor: " << author
             << "\nISBN: " << ISBN << "\nFormat: " << format
             << "\nAvailability: " << (availability ? "Available" : "Borrowed") << endl;
        if (format == "digital") {
            cout << "File Size: " << fileSize << " MB" << endl;
        } else if (format == "hardcopy") {
            cout << "Location: " << location << endl;
        }
        cout << "----------------------------" << endl;
    }

    // Borrow a book
    void borrowBook() {
        if (availability) {
            availability = false;
            cout << title << " has been borrowed." << endl;
        } else {
            cout << title << " is currently unavailable." << endl;
        }
    }

    // Return a book
    void returnBook() {
        availability = true;
        cout << title << " has been returned and is now available." << endl;
    }

    // Get ISBN (to access private ISBN)
    string getISBN() {
        return ISBN;
    }
};

int main() {
    const int numBooks = 5;
    Book library[numBooks];

    // Initialize books
    library[0].setBookDetails("Book A", "Author A", "12345", "hardcopy", 0, "Shelf 1");
    library[1].setBookDetails("Book B", "Author B", "67890", "digital", 10, "");
    library[2].setBookDetails("Book C", "Author C", "11111", "hardcopy", 0, "Shelf 2");
    library[3].setBookDetails("Book D", "Author D", "22222", "digital", 15, "");
    library[4].setBookDetails("Book E", "Author E", "33333", "hardcopy", 0, "Shelf 3");

    string userInput;
    while (true) {
        cout << "Enter the ISBN of the book to borrow (or '0' to exit): ";
        cin >> userInput;

        if (userInput == "0") {
            break;
        }

        bool found = false;
        for (int i = 0; i < numBooks; i++) {
            if (library[i].getISBN() == userInput) {  // Use getISBN() here
                found = true;
                library[i].borrowBook();
                break;
            }
        }

        if (!found) {
            cout << "Book with ISBN " << userInput << " not found in the library." << endl;
        }
    }

    return 0;
}

