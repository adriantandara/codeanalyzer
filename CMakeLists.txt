cmake_minimum_required(VERSION 3.28)
project(CodeAnalyzer)

set(CMAKE_CXX_STANDARD 17)

add_executable(CodeAnalyzer main.cpp
        modules/lexer/lexer.cpp
        modules/lexer/lexer.h
        modules/parser/parser.cpp
        modules/parser/parser.h
        modules/analyzer/analyzer.cpp
        modules/analyzer/analyzer.h)
