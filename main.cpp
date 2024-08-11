#include <iostream>
#include "modules/lexer/lexer.h"
#include "modules/parser/parser.h"
#include "modules/analyzer/analyzer.h"

int main() {
    std::string sourceCode = R"(
        int main() {
            int x;
            float y = 3.14;
            return z;  // Variabila 'z' nu este declarată
        }
    )";

    Lexer lexer(sourceCode);
    std::vector<std::string> tokens = lexer.tokenize();

    Parser parser(tokens);

    Analyzer analyzer(parser);
    analyzer.analyze();

    return 0;
}
