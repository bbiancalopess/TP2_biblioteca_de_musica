#ifndef MUSICNOTFOUNDEXCEPTION_H
#define MUSICNOTFOUNDEXCEPTION_H

#include <exception>
#include <string>

class MusicNotFoundException : public std::exception {
private:
    std::string message;

public:
    explicit MusicNotFoundException(const std::string& message)
        : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // MUSICNOTFOUNDEXCEPTION_H
