// SPDX-License-Identifier: Apache-2.0

#include <iostream>
#include <fstream>
#include <filesystem>

#include <toml++/toml.h>

namespace fs = std::filesystem;

static const char * usage = R"EOF(
    Usage:
        toml2json infile.toml [outfile.json]

    If outfile is not specificed then the output will be written to stdout
    )EOF";


int main(int argc, char ** argv) {
    if (argc < 2 || argc > 4) {
        std::cerr << "Error: incorrect number of arguments, got " << std::to_string(argc) << "expected 1 or two." << std::endl;
        std::cout << usage << std::endl;
        return 1;
    }

    const fs::path infile{argv[1]};

    if (!fs::exists(infile)) {
        std::cerr << "input file " << infile << " does not exist!" << std::endl;
        return 1;
    }

    auto data = toml::parse_file(infile.c_str());
    if (argc == 3) {
        std::ofstream out{argv[2]};
        out << toml::json_formatter(data) << std::endl;
    } else {
        std::cout << toml::json_formatter(data) << std::endl;
    }
}

