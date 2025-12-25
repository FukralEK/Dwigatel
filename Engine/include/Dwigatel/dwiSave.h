#pragma once
#include <string>
#include <vector>

namespace dwiSave
{  
    inline uint32_t hash32(const std::string& s)
    {
        uint32_t hash = 0x811C9DC5;
        for (char c : s) {
            hash ^= static_cast<uint8_t>(c);
            hash *= 0x01000193;
        }
        return hash;
    }
    enum valueType : unsigned char
    {
         INT,
         FLOAT,
         DOUBLE,
         BOOL,

    };
    struct Value
    {
        valueType type;
    };
    struct Section
    {
        std::vector<Section> sections;
        std::vector<Value> values;
    };
} 