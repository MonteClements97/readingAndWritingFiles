//
// Created by moc17 on 23/11/17.
//
#include <vector>
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
    vector<Book*> vector_books;
    ifstream file_in;
    ofstream file_out;
    file_in.open("../biblio.txt");
    if (file_in.is_open()){
        while(file_in.good()){
            Book *this_book = new Book;
            this_book->read_file(&file_in);
            books[array_index++] = this_book;
        }
    }
    file_in.close();
    file_out.open("../biblio_with_semi.txt");
    for(Book * book : books){
        book->write_file_semi_colon(&file_out);
    }
    file_out.close();
    file_in.open("../biblio_with_semi.txt");
    if (file_in.is_open()){
        while(file_in.good()) {
            Book *this_book = new Book;
            this_book->read_file_semi_colon(&file_in);
            if (this_book->isbn == 0){
                continue;
            }
            vector_books.push_back(this_book);
        }
    }
    vector<Book*>::const_iterator it;
    for(it = vector_books.begin(); it != vector_books.end(); ++it){
        (*it) -> print();
    }

    return 0;
}