#include <bits/stdc++.h>
#include "Utrip.hpp"
#include "IO.hpp"
using namespace std;

int main(int argc, char* argv[]){

    Utrip utrip(IO::read_hotels(argv[1]));
    string line, word;
    while(getline(cin, line)){
        stringstream sstream(line);
        sstream >> word;

        try
        {
            if(word == "POST"){
                utrip.post_command(sstream);
            }
            else if(word == "GET"){
                utrip.get_command(sstream);
            }
            else if(word == "DELETE"){
                utrip.delete_command(sstream);
            } 
            else{
                throw ImportException(BAD_REQUEST);
            }

        }catch(ImportException &err){
            cout << err.what() << endl;
        }
    }
}