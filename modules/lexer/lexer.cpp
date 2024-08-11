#include "lexer.h"
#include <cctype>
#include <sstream>
#include <unordered_set>

Lexer::Lexer(const std::string& sourceCode) : sourceCode(sourceCode), currentIndex(0) {}

std::vector<std::string> Lexer::tokenize() {
    std::vector<std::string> tokens;
    std::unordered_set<std::string> keywords = {"int", "float", "double", "return", "if", "else", "for", "while"};

    while (currentIndex < sourceCode.length()) {
        if (std::isspace(sourceCode[currentIndex])) {
            ++currentIndex;
            continue;
        }

        if (std::isalpha(sourceCode[currentIndex]) || sourceCode[currentIndex] == '_') {
            std::string token;
            while (currentIndex < sourceCode.length() &&
                   (std::isalnum(sourceCode[currentIndex]) || sourceCode[currentIndex] == '_')) {
                token += sourceCode[currentIndex++];
            }
            if (keywords.find(token) != keywords.end()) {
                tokens.push_back("keyword:" + token);
            } else {
                tokens.push_back("identifier:" + token);
            }
            continue;
        }

        if (std::isdigit(sourceCode[currentIndex])) {
            std::string token;
            while (currentIndex < sourceCode.length() && std::isdigit(sourceCode[currentIndex])) {
                token += sourceCode[currentIndex++];
            }
            tokens.push_back("number:" + token);
            continue;
        }

        switch (sourceCode[currentIndex]) {
            case '+': case '-': case '*': case '/': case '=': case ';':
                tokens.push_back(std::string(1, sourceCode[currentIndex]));
                ++currentIndex;
                break;
            case '(':
            case ')':
            case '{':
            case '}':
                tokens.push_back(std::string(1, sourceCode[currentIndex]));
                ++currentIndex;
                break;
            default:
                ++currentIndex;
                break;
        }
    }
    return tokens;
}
