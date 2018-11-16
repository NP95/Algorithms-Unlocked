/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#ifndef exception_handler_h
#define exception_handler_h
#include "static.h"

class RuntimeException
{
private:
    string errorMsg;
public:
    RuntimeException(const string& err)
    {
        errorMsg = err;
    }
    string getMessage() const
    {
        return errorMsg;
    }
};

class FATAL_EXCEPTION : public RuntimeException {
public:
    std::stringstream ss;
    FATAL_EXCEPTION(const string& err) : RuntimeException(err)
    {
        ss << err;
        std::cerr << ss.str();
    }
};

#endif /* exception_handler_h */
