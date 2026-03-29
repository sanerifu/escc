#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Token.hpp"
#include <string>

static std::string readFile(std::string const &path) {
    auto file = std::ifstream(path, std::ios::in);
    assert(file.is_open());
    std::stringstream ss = {};
    ss << file.rdbuf();
    return ss.str();
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: escc [file path]" << std::endl;
        return EXIT_SUCCESS;
    }

    token::Token tok = token::Token::integer(5.0);

    tok.match(
        [](token::Token::Number n) {
            std::cout << n.data << std::endl;
        },
        [](auto) {
        }
    );

    // std::string file = readFile(argv[1]);

    // std::cout << file << std::endl;

    return EXIT_SUCCESS;
}
