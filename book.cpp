#include <iostream>
#include <vector>
#include <iomanip>

// Book class to store book details
class Book {
public:
    std::string title;
    std::string author;
    int quantity;
    double price;

    Book(std::string t, std::string a, int q, double p)
        : title(t), author(a), quantity(q), price(p) {}
};

// BookShop class to manage books and transactions
class BookShop {
private:
    std::vector<Book> books;

public:
    void addBook(std::string title, std::string author, int quantity, double price) {
        books.emplace_back(title, author, quantity, price);
    }

    void displayBooks() {
        std::cout << std::left << std::setw(25) << "Title"
                  << std::setw(25) << "Author"
                  << std::setw(10) << "Quantity"
                  << std::setw(10) << "Price" << std::endl;
        std::cout << "--------------------------------------------------------------------\n";

        for (const auto& book : books) {
            std::cout << std::setw(25) << book.title
                      << std::setw(25) << book.author
                      << std::setw(10) << book.quantity
                      << std::setw(10) << book.price << std::endl;
        }
    }

    void purchaseBook(std::string title, int quantity) {
        for (auto& book : books) {
            if (book.title == title) {
                if (book.quantity >= quantity) {
                    std::cout << "Purchased " << quantity << " copies of " << title << ". Total cost: $" << book.price * quantity << std::endl;
                    book.quantity -= quantity;
                } else {
                    std::cout << "Sorry, " << quantity << " copies of " << title << " are not available." << std::endl;
                }
                return;
            }
        }
        std::cout << "Book not found!" << std::endl;
    }
};

int main() {
    BookShop bookShop;

    // Adding sample books
    bookShop.addBook("Book1", "Author1", 5, 10.99);
    bookShop.addBook("Book2", "Author2", 8, 15.49);
    bookShop.addBook("Book3", "Author3", 3, 20.00);

    int choice;
    do {
        std::cout << "\n1. Display Books\n2. Purchase Book\n3. Exit\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                bookShop.displayBooks();
                break;
            case 2: {
                std::string title;
                int quantity;
                std::cout << "Enter title of the book: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                bookShop.purchaseBook(title, quantity);
                break;
            }
            case 3:
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}
