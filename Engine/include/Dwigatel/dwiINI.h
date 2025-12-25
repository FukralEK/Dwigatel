#pragma once
#include <vector>
#include <string>
#include <sstream> 
#include <algorithm>
#include <iostream>
#include <fstream>
#include <unordered_map>

namespace dwiINI
{
	typedef std::unordered_map<std::string, std::unordered_map<std::string, std::string>> Data;

    inline void trim(std::string& s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
            }));
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
            }).base(), s.end());
    }

	inline std::string serialize(Data data)
	{
        std::string text;
        for (auto& section : data)
        {
            text.append("[");
            text.append(section.first);
            text.append("]\n");
            for (auto& key : section.second)
            {
                text.append(key.first);
                text.append(" = ");
                text.append(key.second);
                text.append("\n");
            }
        }
        return text;
	}

	inline Data parse(const std::string& text)
	{
        Data data;
        std::string currentSection;
        std::istringstream stream(text);
        std::string line;

        while (std::getline(stream, line)) {
            trim(line);

            if (line.empty() || line[0] == ';' || line[0] == '#') continue;
            if (line.front() == '[' && line.back() == ']') {
                currentSection = line.substr(1, line.size() - 2);
                continue;
            }
            auto eqPos = line.find('=');
            if (eqPos == std::string::npos) continue;

            std::string key = line.substr(0, eqPos);
            std::string value = line.substr(eqPos + 1);
            trim(key);
            trim(value);

            data[currentSection][key] = value;
        }

        return data;
	}

    inline std::string getString(const Data& data, const std::string& section,
        const std::string& key, const std::string& defaultValue = "")
    {
        auto secIt = data.find(section);
        if (secIt == data.end()) return defaultValue;

        auto keyIt = secIt->second.find(key);
        return (keyIt == secIt->second.end()) ? defaultValue : keyIt->second;
    }

    inline int getInt(const Data& data, const std::string& section,
        const std::string& key, int defaultValue = 0)
    {
        std::string val = getString(data, section, key);
        if (val.empty()) return defaultValue;
        return std::stoi(val);
    }

    inline float getFloat(const Data& data, const std::string& section,
        const std::string& key, double defaultValue = 0.0)
    {
        std::string val = getString(data, section, key);
        if (val.empty()) return defaultValue;
        return std::stof(val);
    }

    inline double getDouble(const Data& data, const std::string& section,
        const std::string& key, double defaultValue = 0.0)
    {
        std::string val = getString(data, section, key);
        if (val.empty()) return defaultValue;
        return std::stod(val);
    }

    inline bool getBool(const Data& data, const std::string& section,
        const std::string& key, bool defaultValue = false)
    {
        std::string val = getString(data, section, key);
        if (val.empty()) return defaultValue;

        std::transform(val.begin(), val.end(), val.begin(), ::tolower);

        return (val == "true" || val == "1" || val == "yes" || val == "on");
    }

    inline std::string fromBool(bool value = false)
    {
        return value ? "true" : "false";
    }
    inline std::string fromInt(int value = 0)
    {
        return std::to_string(value);
    }
    inline std::string fromFloat(float value = 0)
    {
        return std::to_string(value);
    }
    inline std::string fromDouble(double value = 0)
    {
        return std::to_string(value);
    }
    
    inline bool save(const std::string& text, const std::string& path)
    {
        std::ofstream file(path);

        if (!file.is_open())
        {
            return false;
        }
        file << text;

        file.close();
        return true;
    }
    inline std::string load(const std::string& path)
    {
        std::string text;
        std::string line;

        std::ifstream file(path);

        if (!file.is_open())
        {
            return "";
        }

        while (std::getline(file, line)) {
            text.append(line);
            text.append("\n");
        }

        file.close();
        return text;
    }
}
