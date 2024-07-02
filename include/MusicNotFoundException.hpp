#ifndef MUSICNOTFOUNDEXCEPTION_H
#define MUSICNOTFOUNDEXCEPTION_H

#include <exception>
#include <string>

/**
 * @brief Exceção lançada quando uma música não é encontrada.
 */
class MusicNotFoundException : public std::exception {
private:
    std::string message;

public:
    /**
     * @brief Construtor da classe MusicNotFoundException.
     * @param message A mensagem de erro associada à exceção.
     */
    explicit MusicNotFoundException(const std::string& message)
        : message(message) {}

    /**
     * @brief Retorna a mensagem de erro associada à exceção.
     * @return A mensagem de erro.
     */
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // MUSICNOTFOUNDEXCEPTION_H
