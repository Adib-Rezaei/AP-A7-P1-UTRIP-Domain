#include <bits/stdc++.h>
#include "Utrip.hpp"
using namespace std;

bool User::check_signup(std::string _email, std::string _username){
    if(_email == email || _username == username)
        return false;
    return true;
}

bool User::check_login(std::string _email, std::string _password){
    if(email == _email && password == _password)
        return true;
    return false;
}

void User::update_wallet(int amount){
    wallet.push_back(wallet.back()+amount);
}

void User::set_reservation(Reserve* reserve){
    reserves.push_back(reserve);
    reserve->print_rooms();
}

void User::print_reservations(){
    bool is_empty = true;
    for(int i=reserves.size()-1; i>= 0; i--){
        if(reserves[i] == NULL)
            continue;
        cout << "id: " << i+1 << ' ';
        reserves[i]->print_all();
        is_empty = true;
    }
    if(is_empty)
        cout << "Empty" << endl;
}

void User::delete_reserve(int reserve_id){
    if(reserve_id > reserves.size())
        throw ImportException(NOT_FOUND);
    if(reserves[reserve_id-1] == NULL)
        throw ImportException(NOT_FOUND);
    update_wallet(reserves[reserve_id-1]->get_cost()/2);
    reserves[reserve_id-1] = NULL;
    
}