#include "player.hh"
#include <iostream>
#include <string>

Player::Player(std::string nimi):
    name_(nimi),points_(0),win_(false)
{

}

std::string Player::get_name() const{
    return name_;

}

int Player::get_points() const{
    return points_;

}

void Player::add_points(int pisteet){
    if (points_ + pisteet <= 50){
        points_ += pisteet;
    }
    else{
        points_ = 25;
    }
}

bool Player::has_won(){
    if (points_ == 50){
        win_ = true;
        return true;
    }
    else{
        return false;
    }
}
