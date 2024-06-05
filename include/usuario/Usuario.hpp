#ifndef USUARIO
#define USUARIO

#include <string>
using std::string;

class Usuario {
    private:
        int id;
        string nome;
        string email;
        string senha;

    public:
        // construtor
        Usuario(int id, string nome, string email, string senha);
        
        // getters e setter
        int getId();
        void setId(int id);
        
        string getNome();
        void setNome(string nome);

        string getEmail();
        void setEmail(string email);

        string getSenha();
        void setSenha(string senha);

        // métodos
        void logout();
};

#endif
