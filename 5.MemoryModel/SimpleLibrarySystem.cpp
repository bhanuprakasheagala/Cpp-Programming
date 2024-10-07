#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Book {
    public:
        Book(const std::string& title, const std::string& author) : 
        title(title), author(author) {}
        
        void display() const {
            std::cout << "Title: " << title << ", Author: " << author << '\n';
        }
    
    private:
        std::string title;
        std::string author;
    
};

// Library class
class Library{
    public:
        void addBook(const std::shared_ptr<Book>& book) {
            books.push_back(book);
        }
        
        void listBooks() const {
            for(const auto& book : books) {
                book->display();
            }
        }
        
    private:
        std::vector<std::shared_ptr<Book>> books;
};

// LibraryManager class
class LibraryManager {
    public:
        LibraryManager(std::shared_ptr<Library> library) : library(library){}
        
        void addBook(const std::string& title, const std::string& author) {
            auto book = std::make_shared<Book>(title, author);
            library->addBook(book);
        }
        
        void displayBooks() const {
            library->listBooks();
        }
        
    private:
        std::shared_ptr<Library> library;
};

int main() {
    
    auto library = std::make_shared<Library>();
    LibraryManager lm(library);
    
    lm.addBook("1984", "George Orwell");
    lm.addBook("The Mysterious stranger", "Mark Twain");
    
    std::cout << "Books in the library: \n";
    lm.displayBooks();
        
    return 0;
}
