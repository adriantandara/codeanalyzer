#include "analyzer.h"
#include <iostream>

Analyzer::Analyzer(Parser& parser) : parser(parser) {}

void Analyzer::analyze() {
    parser.parse();
    declaredVariables = parser.declaredVariables;

    std::cout << "Performing code analysis..." << std::endl;
    checkUndeclaredVariables();
}

void Analyzer::checkUndeclaredVariables() {
    std::unordered_set<std::string> usedVariables;

    std::vector<std::string> tokens = parser.getTokens();
    for (const std::string& token : tokens) {
        if (token.find("identifier:") == 0) {
            usedVariables.insert(token.substr(11));
        }
    }

    for (const auto& var : usedVariables) {
        if (declaredVariables.find(var) == declaredVariables.end()) {
            std::cout << "Warning: Variable '" << var << "' used before declaration." << std::endl;
        }
    }
}
