/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** IOPool
*/

#pragma once
#include <memory>
#include <queue>
#include "IRequest.hpp"
#include "Response.hpp"

namespace GUI::Network {
    class IOPool {
        public:
            IOPool(size_t bufferSize = 4096);
            ~IOPool() = default;

            void addRequest(std::shared_ptr<IRequest> request);
            std::shared_ptr<IRequest> popRequest(void);
            void addResponse(std::shared_ptr<Response> response);
            std::shared_ptr<Response> popResponse(void);

            const std::queue<std::shared_ptr<IRequest>> &getRequests(void) const;
            const std::queue<std::shared_ptr<Response>> &getResponses(void) const;

        private:
            std::queue<std::shared_ptr<IRequest>> _requests;
            std::queue<std::shared_ptr<Response>> _responses;
            std::string _buffer;
            size_t _bufferSize;
    };
}
