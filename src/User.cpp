#include "User.hpp"

// contrutor
User::User(int id, string name, string email, string password, string userType) 
    : id(id), name(name), email(email), password(password), userType(userType){}

string User::login(string email, string password) {
    // this->getAllUsers(); // Remove this line, as it is not needed in the User class

    for (User* u : this->users) { // passa pelos usuários do sistema
        if (email == u->email) { // verifica se o email é igual ao da linha, se não for, passa para a linha seguinte e faz o mesmo
            if (password == u->password) { // se o email for igual, verifica se a senha é igual
                cout << "Login feito com sucesso!"; // se a senha for a certa, o usuário está logado
                return to_string(u->id);
            } else {
                return "Senha incorreta"; // se a senha for diferente, a senha digitada está errada
            }
        }
    }

    return "Email não registrado"; // caso o email não esteja no arquivo, o usuário não está cadastrado
}

string User::signUp(string name, string email, string password, string userType) {
    try {   
        string caminho = "users.csv";
        vector<vector<string>> data = readCSV(caminho);
        string id = to_string(getId(caminho));
        vector<string> newData = {id, name, email, password, userType};

        data.push_back(newData);

        writeCSV("../csv/users.csv", data);
        cout << "Cadastrado com sucesso!" << endl;
        string a = id;
        return a;
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        return "Erro ao cadastrar!";
    }
}

void User::signUpInfo(System* sistema) {
    string name = getInput("Digite seu nome: ");
    string email = getInput("Digite seu email: ");
    string password = getInput("Digite sua senha: ");
    string userType = getInput("Digite o tipo de usuário (ouvinte ou artista): ");
    while(userType != "ouvinte" && userType != "artista"){
        userType = getInput("Digite o tipo de usuário (ouvinte ou artista): ");
    }
    sistema->signUp(name, email, password, userType);
    return;
}

// métodos
void User::logout(){

}

