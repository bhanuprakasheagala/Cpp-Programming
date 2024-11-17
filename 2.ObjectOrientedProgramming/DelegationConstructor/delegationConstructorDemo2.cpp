#include <iostream>
#include <string>

class Book {
    std::string title;
    std::string author;
    double price;

public:
    Book(const std::string& t, const std::string& a, double p)
        : title(t), author(a), price(p) {
        std::cout << "Book(const std::string&, const std::string&, double)" << std::endl;
    }

    Book(const std::string& t, const std::string& a)
        : Book(t, a, 0.0) {  // Delegating to the main constructor
        std::cout << "Book(const std::string&, const std::string&)" << std::endl;
    }

    Book(const std::string& t)
        : Book(t, "Unknown", 0.0) {  // Delegating to the main constructor
        std::cout << "Book(const std::string&)" << std::endl;
    }

    Book()
        : Book("Untitled", "Unknown", 0.0) {  // Delegating to the main constructor
        std::cout << "Book()" << std::endl;
    }

    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", Price: $" << price << std::endl;
    }
};

int main() {
    Book b1;
    b1.display();

    Book b2("1984");
    b2.display();

    Book b3("To Kill a Mockingbird", "Harper Lee");
    b3.display();

    Book b4("The Great Gatsby", "F. Scott Fitzgerald", 10.99);
    b4.display();

    return 0;
}
