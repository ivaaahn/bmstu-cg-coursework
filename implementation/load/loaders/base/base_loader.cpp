//
// Created by ivaaahn on 07.09.2021.
//

#include <memory>
#include <fstream>

#include "base_loader.hpp"
#include "exceptions/load_exceptions.hpp"


void BaseLoader::open(const std::string& filename) {
    this->srcFile = std::make_shared<std::ifstream>(filename);

    if (!*(this->srcFile))
        throw FileOpenError(__FILE__, __LINE__, "could not open model-file");
}

void BaseLoader::close() {
    this->srcFile->close();
}