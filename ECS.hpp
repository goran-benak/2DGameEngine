#ifndef ECS_HPP
#define ECS_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentID(){
    static ComponentID lastID = 0;
    return lastID++; //Da li stvarno vraca prvo 1. Mislim da ce vratiti prvo 0.
}

template <typename T> inline ComponentID getComponentID() noexcept {
    static ComponentID typeID = getComponentID();
    return typeID;

}

constexpr std::size_t maxComponenets = 32;

using ComponentBitSet = std::bitset<maxComponenets>;
using ComponentArray = std::array<Component*, maxComponenets>;


class ECS {
public:
    ECS();
    ECS(const ECS& orig);
    virtual ~ECS();
private:

};

#endif /* ECS_HPP */

