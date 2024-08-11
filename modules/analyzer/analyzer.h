#ifndef ANALYZER_H
#define ANALYZER_H

#include "../parser/parser.h"
#include <unordered_set>

class Analyzer {
public:
    Analyzer(Parser& parser);
    void analyze();

private:
    Parser& parser;
    std::unordered_set<std::string> declaredVariables;

    void checkUndeclaredVariables();
    void checkVariableUsage(const std::string& token);
};

#endif // ANALYZER_H
