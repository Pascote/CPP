#include <iostream>
#include <string>
#include <limits>
#include <vector>

class Book {
    private:
        std::string title_of_the_book;
        std::string name_of_the_author;
        std::string year_of_publication;
        std::string number_of_pages;

    public:
        void setTitleOfTheBook(std::string _title);
        std::string getTitleOfTheBook() const;
        void inputTitleOfTheBook();

        void setNameOfTheAuthor(std::string _author);
        std::string getNameOfTheAuthor() const;
        void inputNameOfTheAuthor();

        void setYearOfPublication(std::string _year);
        std::string getYearOfPublication() const;
        void inputYearOfPublication();

        void setNumberOfPages(std::string _pages);
        std::string getNumberOfPages() const;
        void inputNumberOfPages();

};

//Title Of The Book Zone
void Book::setTitleOfTheBook(std::string _title){
    title_of_the_book = _title;
}

std::string Book::getTitleOfTheBook() const {
    return title_of_the_book;
}

void Book::inputTitleOfTheBook(){
    std::cout << "Enter the title of the book -> ";
    std::string _title;
    std::getline(std::cin, _title);
    setTitleOfTheBook(_title);
}

//Author Of The Book Zone
void Book::setNameOfTheAuthor(std::string _author){
    name_of_the_author = _author;
}

std::string Book::getNameOfTheAuthor() const {
    return name_of_the_author;
}

void Book::inputNameOfTheAuthor(){
    std::cout << "Enter the name of the author -> ";
    std::string _author;
    std::getline(std::cin, _author);
    setNameOfTheAuthor(_author);
}

//Year of Publicaton Zone
void Book::setYearOfPublication(std::string _year){
    year_of_publication = _year;
}

std::string Book::getYearOfPublication() const {
    return year_of_publication;
}

void Book::inputYearOfPublication(){
    std::cout << "Enter the year of publication -> ";
    std::string _year;
    std::getline(std::cin, _year);
    setYearOfPublication(_year);
}

//Number Of Pages Zone
void Book::setNumberOfPages(std::string _pages){
    number_of_pages = _pages;
}

std::string Book::getNumberOfPages() const {
    return number_of_pages;
}

void Book::inputNumberOfPages(){
    std::cout << "Enter the number of pages of this book -> ";
    std::string _pages;
    std::getline(std::cin, _pages);
    setNumberOfPages(_pages);
}

Book createBook(){
    Book myBook;

    myBook.inputTitleOfTheBook();
    myBook.inputNameOfTheAuthor();
    myBook.inputYearOfPublication();
    myBook.inputNumberOfPages();

    return myBook;
}

int findBookByTitle(const std::vector<Book>& libraryCollection, const std::string& title){
    for(int i = 0; i < libraryCollection.size(); ++i) {
        if(libraryCollection[i].getTitleOfTheBook() == title) {
            return i;
        }
    }
    return -1;
}

int main(){
    std::vector<Book> libraryCollection;

    std::cout << "Welcome to Pegasus, our Library System. What do you want to do?\n";

    std::string libraryOptions[3] = {
    "[1] INSERT A NEW BOOK",
    "[2] CHECK A SPECIFIC BOOK",
    "[3] SHOW ALL THE BOOKS"};

    int size_of_library_options = sizeof(libraryOptions) / sizeof(libraryOptions[0]);

    while(true){
        int decision_from_user;
        int option_to_start;

        for(int i = 0; i < size_of_library_options; ++i){
            std::cout << libraryOptions[i] << std::endl;
        }

        std::cout << "Choose you option -> ";
        std::cin >> option_to_start;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(option_to_start){
            case 1:
                libraryCollection.push_back(createBook());
                std::cout << "A new book was inserted." << std::endl;
                break;
            case 2:{
                std::string title;
                std::cout << "Enter the title of the book you want to see the details -> ";
                std::getline(std::cin, title);

                int index = findBookByTitle(libraryCollection, title);

                if(index != -1) {
                    Book chosenBook = libraryCollection[index];
                    std::cout << "Title: " << chosenBook.getTitleOfTheBook() << std::endl;
                    std::cout << "Author: " << chosenBook.getNameOfTheAuthor() << std::endl;
                    std::cout << "Year of Publication: " << chosenBook.getYearOfPublication() << std::endl;
                    std::cout << "Number of Pages: " << chosenBook.getNumberOfPages() << std::endl;
                } else{
                    std::cout << "Book not found!" << std::endl;
                }
                break;
            }
            case 3:
                if(libraryCollection.size() > 0){
                    std::cout << "|--------- PEGASUS LIBRARY ---------|\n" << std::endl;
                    for(const auto& book : libraryCollection){
                        std::cout << "Title: " << book.getTitleOfTheBook() << std::endl;
                        std::cout << "Author: " << book.getNameOfTheAuthor() << std::endl;
                        std::cout << "Year of Publication: " << book.getYearOfPublication() << std::endl;
                        std::cout << "Number of Pages: " << book.getNumberOfPages() << std::endl;
                        std::cout << "|-----------------------------------|\n" << std::endl;
                }
                } else{
                    std::cout << "You do not have any books yet!" << std::endl;
                };
                break;
            default:
                std::cout << "I did not understand this option!" << std::endl;
        }

        std::cout << "Do you want to make something else? [1] to Yes, [0] to Not -> ";
        std::cin >> decision_from_user;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(decision_from_user == 0){
            std::cout << "You wanted to stop!" << std::endl;
            break;
        } else if(decision_from_user == 1){
            std::cout << "You wanted to continue!" << std::endl;
        } else{
            std::cout << "I did not understand your option. Try again!" << std::endl;
        }
    }

    return 0;
}
