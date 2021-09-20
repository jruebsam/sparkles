#include "Agents.h"

#include <iostream>
#include <random>
#include <cmath>

    
Agents::Agents(int size) : size{size} {
    std::random_device rd;
    std::normal_distribution<float> dis{0, 0.25};

    agents = std::vector<Agent>(size);

    for(auto &agent: agents) {
        agent.x = dis(rd);
        agent.y = dis(rd);
        agent.z = 0.0;
        agent.vx = dis(rd);
        agent.vy = dis(rd);
    }
}


void Agents::Update(double dt) {
    float px, py;
    float g = 0.5;
    for(auto &agent: agents) {
        px = agent.x + (float) dt*agent.vx;
        py = agent.y + (float) dt*agent.vy;

        float r2 = agent.x*agent.x + agent.y*agent.y + 0.000001;

        agent.vx -= (float) dt*px*g/r2;
        agent.vy -= (float) dt*py*g/r2;

        agent.x = px;
        agent.y = py;
    }
}