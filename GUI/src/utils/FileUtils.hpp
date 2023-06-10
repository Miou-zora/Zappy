/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** FileUtils
*/

#pragma once

#include "ErrorManagement.hpp"
#include <string>
#include <fstream>
#include <sstream>

namespace GUI::Utils {
    /**
     * @brief StringUtils class that handle string
     */
    class FileUtils {
        public:
            /**
             * @brief Construct a new StringUtils object
             */
            static std::string loadFile(const std::string &path)
            {
                std::string fileContent;
                std::ifstream fileLoader(path, std::ios::in);

                if (fileLoader.is_open()) {
                    std::stringstream sstr;
                    sstr << fileLoader.rdbuf();
                    fileContent = sstr.str();
                    fileLoader.close();
                } else {
                    throw FileException("Impossible to open " + path);
                }
                return fileContent;
            };
    };
}
