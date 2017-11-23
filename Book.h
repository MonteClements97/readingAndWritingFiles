#include <string>
#include <iostream>
#include <fstream>

using namespace std;
#ifndef WORKSHEETFILESIO_BOOK_H
#define WORKSHEETFILESIO_BOOK_H


class Book {
public:
    string author;
    string title;
    int isbn;
    string ignore;

    void read_file(ifstream *file);
    Book();
    ~Book();



};

void Book::read_file( ifstream *file ){

        getline(*file, author);
        getline(*file, title);
        *file >> isbn;
        getline(*file, ignore);
        getline(*file, ignore);

}


#endif //WORKSHEETFILESIO_BOOK_H
