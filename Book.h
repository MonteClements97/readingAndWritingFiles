#include <string>
#include <iostream>
#include <fstream>
#include <istream>

using namespace std;
#ifndef WORKSHEETFILESIO_BOOK_H
#define WORKSHEETFILESIO_BOOK_H


class Book {
public:
    string author;
    string title;
    int isbn;
    string ignore;

    void const print();
    void read_file(ifstream *file);
    void write_file_semi_colon(ofstream *file);
    void read_file_semi_colon(ifstream *file);
    Book();
    ~Book();



};

void Book::read_file( ifstream *file ){

    getline(*file, author);
    getline(*file, title);
    *file >> isbn;
    getline(*file, ignore);
    getline(*file, ignore);
    author.erase(author.size() - 1);
    title.erase(title.size() - 1);

}

void Book::write_file_semi_colon ( ofstream *file) {
    *file << author + ";" + title + ";" + to_string(isbn) + ";";
}


void Book::read_file_semi_colon (ifstream *file){
    char first_author[100];
    char first_title[100];
    char first_isbn[11];
    file->getline(first_author, 256, ';');
    file->getline(first_title, 256, ';');
    file->getline(first_isbn, 11, ';');
    author = first_author;
    title = first_title;
    isbn = atoi(first_isbn);

}

void const Book::print(){
    cout << author << ' ' << title << ' ' << isbn << ' ' << endl;
}




#endif //WORKSHEETFILESIO_BOOK_H