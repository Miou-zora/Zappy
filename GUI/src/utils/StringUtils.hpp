/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** StringUtils
*/

#pragma once
#include <string>
#include <vector>

namespace GUI::Utils {
    /**
     * @brief StringUtils class that handle string
     */
    class StringUtils {
        public:
            StringUtils();
            ~StringUtils();

        /**
         * @brief Try to split a command to get the key only
         * @param command Command to split
         * @return std::string Key of the command  
        **/
        static std::string try_split_command(std::string command)
        {
            std::string command_key = "";

            for (std::size_t i = 0; i < command.size(); i++) {
                if (command[i] == ' ') {
                    return command_key;
                }
                command_key += command[i];
            }
            return command_key;
        }

        /**
         * @brief Split a string with a token
         * @param str String to split
         * @param token Token to split with
         * @return std::vector<std::string> Vector of string
        **/
        static std::vector<std::string> split(std::string str, std::string token)
        {
            std::vector<std::string> result;
            while (str.size()) {
                std::size_t index = str.find(token);
                if (index != std::string::npos) {
                    result.push_back(str.substr(0, index));
                    str = str.substr(index + token.size());
                    if (str.size() == 0) {
                        result.push_back(str);
                    }
                } else {
                    result.push_back(str);
                    str = "";
                }
            }
            return result;
        }
    };
}
