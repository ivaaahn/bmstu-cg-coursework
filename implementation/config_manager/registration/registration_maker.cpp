//
// Created by ivaaahn on 26.05.2021.
//

#include <memory>
#include <exceptions/load_exceptions.hpp>
#include <load/loaders/file_loader/file_loader.hpp>


#include "registration_maker.hpp"


void RegistrationMaker::makeRegistration(Solution &solution) {
    if (!solution.registerLoaderCreator(0, std::make_shared<ConLoaderCreator<FileLoader>>()))
        throw ConfigError(__FILE__, __LINE__, "failed to register source loader");

//    if (!solution.registerLoaderCreator(1, std::make_shared<ConLoaderCreator<FileCameraLoader>>()))
//        throw ConfigError(__FILE__, __LINE__, "failed to register source loader");
}
