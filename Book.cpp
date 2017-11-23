//
// Created by moc17 on 23/11/17.
//

#include "Book.h"

Book::Book() {
    std::cout << "I have arrived!!" << endl;
}

Book::~Book() {
    std::cout << "I am dead!!" << endl;
}
int main(){
    int array_index = 0;
    Book *books [11];
    ifstream file_in;
    file_in.open("../biblio.txt");
    if (file_in.is_open()){
        while(file_in.good()){
            Book *this_book = new Book;
            this_book->read_file(&file_in);
            books[array_index++] = this_book;
        }
    }

    return 0;
}
