#pragma once

#include <vector>

class Agents {
private:
#pragma pack(push, 1)

    struct Agent {
        float x;
        float y;
        float z;
        float vx;
        float vy;
    };

#pragma pack(pop)
private:
    int size{};
    std::vector<Agent> agents{};


public:
    Agents() = default;
    Agents(int size);

    Agents(const Agents&) = delete;
    Agents& operator=(const Agents&) = delete;

    void Update(double dt);

    std::vector<Agent> getVertexData() {return agents;}
    int getSize() {return size;}
};