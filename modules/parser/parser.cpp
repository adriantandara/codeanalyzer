#include "parser.h"
#include <iostream>

Parser::Parser(const std::vector<std::string>& tokens) : tokens(tokens), currentIndex(0) {}

void Parser::parse() {
    while (currentIndex < tokens.size()) {
        std::string token = tokens[currentIndex++];
        if (token.find("keyword:") == 0) {
            std::string keyword = token.substr(8);
            if (keyword == "int" || keyword == "float" || keyword == "double") {
                std::cout << "Declaration: " << keyword << std::endl;
                if (currentIndex < tokens.size() && tokens[currentIndex].find("identifier:") == 0) {
                    std::string varName = tokens[currentIndex++].substr(11);
                    std::cout << "Variable: " << varName << std::endl;
                    declaredVariables.insert(varName);
                }
            } else if (keyword == "return") {
                std::cout << "Return statement found" << std::endl;
            }
        } else if (token.find("identifier:") == 0) {
            std::cout << "Used Variable: " << token.substr(11) << std::endl;
        } else if (token == ";") {
            std::cout << "End of statement" << std::endl;
        } else {
            std::cout << "Unhandled token: " << token << std::endl;
        }
    }
}

std::vector<std::string> Parser::getTokens() const {
    return tokens;
}
