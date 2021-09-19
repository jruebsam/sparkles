#pragma once

#include "glad/glad.h"
#include "Agents.h"

class Canvas
{
private:
    GLuint VBO = 0, VAO = 0, EBO = 0, texture;
    int width, height;
    int agents_size{};
    Agents agents{500000};

public:
    Canvas(const int width, const int height);
    ~Canvas();
    void Render(double dt);
    GLuint getTextureID();
};

