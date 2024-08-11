#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <unordered_set>

class Parser {
public:
    Parser(const std::vector<std::string>& tokens);
    void parse();
    std::unordered_set<std::string> declaredVariables;
    std::vector<std::string> getTokens() const;

private:
    std::vector<std::string> tokens;
    size_t currentIndex;
};

#endif // PARSER_H
