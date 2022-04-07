#include <iostream>
#include <memory>
#include "cards.hh"


Cards::Cards(): top_( nullptr ) {
}


void Cards::add(int id) {
    std::shared_ptr<Card_data> new_card 
            = std::make_shared<Card_data>(Card_data{id, top_});
    top_ = new_card;
}

void Cards::print(std::ostream& s) {
   std::shared_ptr<Card_data> to_be_printed = top_;
   int nr = 1;

   while( to_be_printed != 0 ) {
      s << nr << ": " << to_be_printed->data << std::endl;
      to_be_printed = to_be_printed->next;
      ++nr;
   }
}

bool Cards::remove(int &id){

  if(top_ == nullptr){
     return false;
     }
  std::shared_ptr<Card_data> card = top_;
  id = card->data;
  top_ = top_->next;
  return true;

}

void Cards::reverse()
{
    std::shared_ptr<Card_data> temp = nullptr;
    std::shared_ptr<Card_data> prev = nullptr;
    std::shared_ptr<Card_data> card = top_;
    while(card != nullptr){
        temp = card->next;
        card->next = prev;
        prev = card;
        card = temp;
    }
    top_ = prev;
}

