#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

class Lexer {
public:
    Lexer(const std::string& sourceCode);
    std::vector<std::string> tokenize();

private:
    std::string sourceCode;
    size_t currentIndex;
};

#endif // LEXER_H
