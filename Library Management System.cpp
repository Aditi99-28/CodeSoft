#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class to store book details
class Book {
public:
    int id;
    string title;
    string author;
    int year;

    // Constructor
    Book(int bookId, string bookTitle, string bookAuthor, int bookYear) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        year = bookYear;
    }

    // Display book details
    void displayBook() {
        cout << "Book ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "--------------------------" << endl;
    }
};

// Library class to manage books
class Library {
private:
    vector<Book> books; // Stores list of books

public:
    // Add a new book
    void addBook() {
        int id, year;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore(); // Ignore newline character

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Year of Publication: ";
        cin >> year;

        books.push_back(Book(id, title, author, year));
        cout << "Book added successfully!\n";
    }

    // Display all books
    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }

        cout << "Books in Library:\n";
        for (size_t i = 0; i < books.size(); i++) {
            books[i].displayBook();
        }
    }

    // Search for a book by ID
    void searchBook() {
        int searchId;
        cout << "Enter Book ID to search: ";
        cin >> searchId;

        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].id == searchId) {
                cout << "Book Found!\n";
                books[i].displayBook();
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Delete a book by ID
    void deleteBook() {
        int deleteId;
        cout << "Enter Book ID to delete: ";
        cin >> deleteId;

        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].id == deleteId) {
                books.erase(books.begin() + i);
                cout << "Book deleted successfully!\n";
                return;
            }
        }
        cout << "Book not found!\n";
    }
};

// Main function with menu
int main() {
    Library library;
    int choice;

    while (true) {
        // Menu
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                library.deleteBook();
                break;
            case 5:
                cout << "Exiting the program...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

