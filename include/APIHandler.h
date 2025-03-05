#ifndef API_HANDLER_H
#define API_HANDLER_H

#include <string>

class APIHandler {
public:
    static std::string fetchAPIData(const std::string& url);
};

#endif