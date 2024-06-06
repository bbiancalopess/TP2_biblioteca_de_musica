#ifndef USER
#define USER

#include <string>
using std::string;

class User {
    private:
        int id;
        string name;
        string email;
        string password;

    public:
        // construtor
        User(int id, string name, string email, string password);
        
        // getters e setter
        int getId();
        
        string getName();
        void setName(string name);

        string getEmail();
        void setEmail(string email);

        string getPassword();
        void setPassword(string password);

        // métodos
        void logout();
};

#endif
