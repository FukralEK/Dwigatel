#pragma once
#include <unordered_map>
#include <vector>
#include <functional>
#include <typeindex>
#include <string>


namespace dwiEvent
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

	class Event
	{
	public:
        virtual~Event();

		virtual const uint32_t getEventType() const = 0;

        bool handled{ false };
	};

    
}