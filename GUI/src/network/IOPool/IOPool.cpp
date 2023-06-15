/*
** EPITECH PROJECT, 2023
** GUI
** File description:
** IOPool
*/

#include "IOPool.hpp"
#include "ErrorManagement.hpp"

namespace GUI::Network {
    IOPool::IOPool(size_t bufferSize):  _buffer(""), _bufferSize(bufferSize)
    {

    }

    void IOPool::addRequest(std::shared_ptr<IRequest> request)
    {
        _requests.push(request);
    }

    std::shared_ptr<IRequest> IOPool::popRequest(void)
    {
        std::shared_ptr<IRequest> firstRequest = nullptr;

        if (!_requests.empty()) {
            firstRequest = _requests.front();
            _requests.pop();
        }
        return (firstRequest);
    }

    std::shared_ptr<Response> IOPool::popResponse(void)
    {
        std::shared_ptr<Response> firstResponse = nullptr;

        if (!_responses.empty()) {
            firstResponse = _responses.front();
            _responses.pop();
        }
        return (firstResponse);
    }

    void IOPool::addResponse(std::shared_ptr<Response> response)
    {
        _buffer += response->get();
        while (_buffer.find("\n") != std::string::npos) {
            std::string responseString = _buffer.substr(0, _buffer.find("\n"));
            _buffer.erase(0, _buffer.find("\n") + 1);
            _responses.push(std::make_shared<Response>(responseString));
        }
        if (_buffer.size() > _bufferSize) {
            throw GUI::IOPoolBufferOverflowException("Buffer overflow");
        }
    }

    const std::queue<std::shared_ptr<IRequest>> &IOPool::getRequests(void) const
    {
        return (_requests);
    }

    const std::queue<std::shared_ptr<Response>> &IOPool::getResponses(void) const
    {
        return (_responses);
    }
}
