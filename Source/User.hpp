#ifndef USER_HPP
#define USER_HPP

#include "Reserve.hpp"

class User {
public:
    User(std::string _email, std::string _username, std::string _pass){
        email = _email; username = _username; password = _pass; wallet.push_back(0);
    }
    bool check_signup(std::string _email, std::string _username);
    bool check_login(std::string _email, std::string _password);
    void update_wallet(int amount);
    void set_reservation(Reserve* reserve);
    std::vector<int> get_wallet(){ return wallet; }
    void print_reservations();
    void delete_reserve(int reserve_id);
    std::string get_name(){ return username; }
    
private:
    std::string email;
    std::string username;
    std::string password;
    std::vector<int> wallet;
    std::vector<Reserve*> reserves;
};

#endif