#ifndef PLAYER_HH
#define PLAYER_HH
#include <string>

class Player
{
public:
    Player(std::string nimi);

    std::string get_name() const;
    int get_points()const ;
    void add_points(int points);
    bool has_won();

private:
    std::string name_;
    int points_;
    bool win_;

};

#endif // PLAYER_HH
