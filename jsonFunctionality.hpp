
#ifndef JFLX_JSONFUNCTIONALITY
#define JFLX_JSONFUNCTIONALITY

#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <JFLX/logging.hpp>

namespace JFLX {
    namespace fs = std::filesystem;

    std::string path = fs::current_path().string() + "/";

    //* Load JSON from file and return as parsed json object
    bool loadJson(std::string pathToJson, nlohmann::json& j) {
        std::ifstream loadedFile(pathToJson);
        if (!loadedFile.is_open()) {
            log("Failed to open ", pathToJson, LOGTYPE::JFLX_ERROR);
            return false;
        }
        
        loadedFile >> j;
        return true;
    }

    bool saveJson(std::string pathToJson, nlohmann::json& j) {
        std::ofstream file(pathToJson);

        if (!file.is_open()) {
            log("JSON COULD NOT BE SAVED: ", ("Json Fie could not be opened located at: " + pathToJson), LOGTYPE::JFLX_ERROR);
            return false;
        }

        file << j.dump(4);
        return true;
    }
}

#endif
