#ifndef SYSTEM
#define SYSTEM

#include <string>
#include <vector>
#include "User.hpp"
#include "Song.hpp"
#include "csv.hpp"
#include "auxiliares.hpp"

using std::string;
using std::vector;

/**
 * @class System
 * @brief The system funcionalities.
 * @details This class contains the system funcionalities, such as login and sign-up.
 */
class System {
    private:
        vector<User*> users;     /** List of all users in the system. */
        long count_users;       /** Number of users in the system. */
        vector<Song*> songs;
    public:
        /**
         * @brief Realizes the sign-up of an user.
         * @details Creates a account for a new user in the system.
         * @param name The name of the new user.
         * @param email The email used to login.
         * @param password The password used to login.
         * @param userType The user type in the system: 'L' for listener or 'A' for artist
         */
        string signUp(string name, string email, string password, string userType);
        
        /**
         * @brief Realizes the login of an user.
         * @details Let the user enter the system if the login informations are right.
         * @param email The email used as the user identifier.
         * @param password The key used to verify if the user is who it claims to be.
         */
        string login(string email, string password);

        /**
         * @brief Puts the system to work
         * @details Realizes all the initial configuration for the system to work.
         */
        void startTheSystem();

        /**
         * @brief Gets all the users of the system
         * @details Access the CSV file and get the users of the system.
         */
        void getAllUsers();
        
        void getAllSongs();

        void showListenerOptions();
        void showArtistOptions();
        void showMusicOptions();
        void showPlaylistOptions();
        void showAlbumOptions();
        void showFollowedArtistsOptions();
        void showArtistMusicOptions();
        void showArtistAlbumOptions();
        void findMusic(const string& filename, const string& songName);
};

#endif