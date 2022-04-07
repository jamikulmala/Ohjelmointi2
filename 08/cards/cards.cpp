#include "cards.hh"

Cards::Cards():
    top_(nullptr)
{

}

void Cards::add(int id){
    Card_data* card = new Card_data;
    card->data = id;
    card->next = top_;
    top_ = card;
}

void Cards::print_from_top_to_bottom(std::ostream& s){
    Card_data* current = top_;
        int card = 0;

        while(current != nullptr){
            s << card + 1 << ": " << current->data << std::endl;
            ++card;
            current = current->next;
        }
}

bool Cards::remove(int& id){
    if(top_ == nullptr){
            return false;
        }

        id = top_->data;
        Card_data* temp = top_;
        top_ = top_->next;
        delete temp;


        return true;

}

bool Cards::bottom_to_top(){
    if(top_ == nullptr){
            return false;
        }
        if(top_->next == nullptr){
            return true;
        }

        Card_data* second_last = top_;

        while(second_last->next->next != nullptr){
               second_last = second_last->next;
           }
           Card_data* last = second_last->next;
           last->next = top_;
           top_ = last;
           second_last->next = nullptr;

           return true;
}

bool Cards::top_to_bottom(){
    if(top_ == nullptr){
            return false;
        }


        Card_data* last = top_;
        while(last->next != nullptr){
            last = last->next;
        }

        last->next = top_;
        top_ = top_->next;
        last->next->next = nullptr;

        return true;
}


Cards::~Cards(){
    Card_data* card = top_;

    while(top_ != nullptr){
        card = top_;
        top_ = top_->next;
        delete card;

    }
}

void Cards::print_from_bottom_to_top(std::ostream &s)
{
    recursive_print(top_, s);
}

int Cards::recursive_print(Card_data* current, std::ostream &s){
    if(current == nullptr){
        return 1;
    }

    int number = recursive_print(current->next, s);
    s << number << ": " << current->data << std::endl;
    return number +1;

}

Card_data* Cards::get_topmost(){
    return top_;
}
