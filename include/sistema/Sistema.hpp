#ifndef SISTEMA
#define SISTEMA

#include <string>
#include <vector>
#include "../usuario/Usuario.hpp"

using std::string;
using std::vector;

class Sistema {
    private:
        vector<Usuario> usuarios;
        long quantidade_usuarios;
    public:
        // métodos
        void criaUsuario(string nome, string email, string senha);
        void login(string email, string senha);

        // construtor
        Sistema(vector<Usuario> usuarios, long quantidade_usuarios);

        // getters and setters
        vector<Usuario> getUsuarios();
        long getQuantidadeUsuarios();
        void setQuantidadeUsuarios(long qunantidade_usuarios);
};

#endif