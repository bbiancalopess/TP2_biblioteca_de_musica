#ifndef SYSTEM
#define SYSTEM

#include <string>
#include <vector>
#include "../user/User.hpp"

using std::string;
using std::vector;

class System {
    private:
        vector<User> users;
        long count_users;
    public:
        // métodos
        void createUser(string name, string email, string password);
        void login(string email, string password);

        // construtor
        System(vector<User> users, long count_users);

        // getters and setters
        vector<User> getUsers();
        long getCountUsers();
        void increaseCountUsers();
};

#endif