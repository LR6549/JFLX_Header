#ifndef JFLX_LOGGING
#define JFLX_LOGGING

#include <iostream>
#include <string>

namespace JFLX {

    //* Log types
    enum class LOGTYPE {
        JFLX_NONE,
        JFLX_ERROR,
        JFLX_WARNING,
        JFLX_INFO,
        JFLX_SUCCESS
    };

    //* Returns a string for the corresponding log type
    inline std::string logTypeToColor(LOGTYPE type) {
        switch (type) {
            case LOGTYPE::JFLX_NONE:    return "\033[0m";
            case LOGTYPE::JFLX_ERROR:   return "\033[91;1;4m";
            case LOGTYPE::JFLX_WARNING: return "\033[33;1;4m";
            case LOGTYPE::JFLX_INFO:    return "\033[93;1;4m";
            case LOGTYPE::JFLX_SUCCESS: return "\033[92;1;4m";
        }
        return "\033[0m";
    }

    //* A wrapper for logging with color highlighting
    inline void log(std::string shortInfo, std::string detailedDescription = "", LOGTYPE logType = LOGTYPE::JFLX_NONE) {
        std::string logColor = logTypeToColor(logType);
        std::string msg = logColor + shortInfo + "\033[0m: " + detailedDescription;
        std::cout << msg << "\n";
    }

}

#endif
