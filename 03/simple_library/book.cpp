# include "book.hh"
# include <iostream>
# include "date.hh"

Book::Book(std::string const kirjailija, std::string const teos):
    kirjailija_(kirjailija),teos_(teos),in_loan_(false),loaned_(0,0,0),returned_(0,0,0)
{

}


void Book::print() const{
    std::cout << kirjailija_ << " : " << teos_ << std::endl;
    if (in_loan_ == false){
        std::cout << "- available" << std::endl;
    }
    else{
        std::cout <<"- loaned: "; loaned_.print();
        std::cout <<"- to be returned: "; returned_.print();
    }
}


void Book::loan(Date& day){
    if (in_loan_ == false){
        in_loan_ = true;
        loaned_ = day;
        returned_ = day;
        returned_.advance(28);
        // returned_ = loaned_.advance(28);

    }
    else{
        std::cout << "Already loaned: cannot be loaned" <<std::endl;
    }

}

void Book::renew(){
    if (in_loan_ == true){
        returned_.advance(28);
    }
    else{
        std::cout << "Not loaned: cannot be renewed" <<std::endl;
    }
}

void Book::give_back(){
    in_loan_= false;
}
