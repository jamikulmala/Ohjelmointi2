#include "queue.hh"
#include <iostream>

// Implement the member functions of Queue here

Queue::Queue(unsigned int cycle):
    first_(nullptr),last_(nullptr),is_green_(false),cycle_(cycle)
{

}

Queue::~Queue(){
    Vehicle* car = first_;

    while(first_ != nullptr){
        car = first_;
        first_ = first_->next;
        delete car;
    }
}

void Queue::enqueue(string const& reg){
    if(is_green_){
        std::cout << "GREEN: The vehicle " << reg << " need not stop to wait" << std::endl;
        return;
    }
    else{
    if(first_ == nullptr){
        first_ = new Vehicle({reg,nullptr});
        last_ = first_;
    }
    else{
        Vehicle* car = new Vehicle({reg,nullptr});
    last_->next = car;
    last_ = car;
    }
    }
}

void Queue::switch_light(){
    if(is_green_ == false){
        if(first_ == nullptr){
            std::cout << "GREEN: No vehicles waiting in traffic lights" << std::endl;
            is_green_ = true;
        }
        else{
            std::cout << "GREEN: Vehicle(s) ";
            for(unsigned int cars = 0;cars < cycle_;++ cars){
                if(!dequeue()){
                    is_green_ = false;
                    break;
                }
            }
            std::cout << "can go on" << std::endl;
        }

    }
    else{
        if(first_ == nullptr){
            std::cout << "RED: No vehicles waiting in traffic lights" << std::endl;
            is_green_ = false;
        }
        else{
            std::cout << "RED: Vehicle(s) ";
            for(unsigned int cars = 0;cars < cycle_;++ cars){
                if(!dequeue()){
                    is_green_ = false;
                    break;
                }
            }
            std::cout << "can go on" << std::endl;
        }
        }
}

void Queue::reset_cycle(unsigned int cycle){
    cycle_ = cycle;
}

void Queue::print() const{
    if(is_green_){
        std::cout<<"GREEN: No vehicles waiting in traffic lights" << std::endl;
    }
    else{
        if(first_ != nullptr){
        Vehicle* car = first_;
        std::cout<<"RED: Vehicle(s) ";
        while(car != nullptr){
            std::cout << car->reg_num << " ";
            car = car->next;
        }
        std::cout<<"waiting in traffic lights" << std::endl;
    }
        else{
            std::cout << "RED: No vehicles waiting in traffic lights" << endl;
        }
    }

}

bool Queue::dequeue(){
    if(first_ == nullptr){
        return false;
    }
    else{
        Vehicle* car = first_;
        std::cout << first_->reg_num << " ";
        first_ = first_->next;
        delete car;

        return true;

    }
}
