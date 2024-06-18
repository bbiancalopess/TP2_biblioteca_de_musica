#ifndef USER
#define USER

#include <string>
using std::string;

/**
 * @class User
 * @brief Represents an user of the system.
 * @details This class contains informations about an user, including its id, name, email and password.
 */
class User {
    private:
        int id;                 /** Unique identifier for the user. */
        string name;            /** Name of the user. */
        string email;           /** Email used to login in the system. */
        string password;        /** Password used to login in the system. */
        string userType;        /** Type of the user. */

    public:
        /**
         * @brief Constructor for the User class.
         * @param id Unique identifier for the album.
         * @param name Name of the user.
         * @param email Email used to login in the system.
         * @param password Password used to login in the system.
         * @details Initializes an User object with the provided id, name, email and password.
         */
        User(int id, string name, string email, string password, string userType);



        string login(string email, string password) ;
        string signUp(string name, string email, string password, string userType);
        atring signUpInfo(System* sistema);


        /**
         * @brief Realizes the logout of the user.
         * @details Realizes the logout of the current user going back to the initial page.
         */
        void logout();

        friend class System;
};

#endif
