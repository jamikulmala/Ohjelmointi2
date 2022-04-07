#ifndef BOOK_HH
#define BOOK_HH

#include <string>
#include "date.hh"

class Book
{
public:
    Book(std::string const kirjailija, std::string const teos);

    void print() const;
    void loan(Date&);
    void renew();
    void give_back();

private:
    std::string kirjailija_;
    std::string teos_;
    bool in_loan_;
    Date loaned_;
    Date returned_;


};

#endif // BOOK_HH
