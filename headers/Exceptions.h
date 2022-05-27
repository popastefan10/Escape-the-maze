//
// Created by popas on 27.05.2022.
//

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <exception>
#include <string>

class CustomException : public std::exception {

private:
    std::string exceptionMessage;

public:
    explicit CustomException(std::string  = "Something went wrong.");
    [[nodiscard]] const char * what() const noexcept override;

};

class FailedTextureLoad : public CustomException {

public:
    FailedTextureLoad();
    explicit FailedTextureLoad(const std::string&);
};

#endif //OOP_EXCEPTIONS_H
