#include "Canvas.h"
#include "Agents.h"

#include <iostream>


Canvas::Canvas(const int _width, const int _height)
: width(_width), height(_height)
{

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, agents.getVertexData().size()*sizeof(float), agents.getVertexData().data(), GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
}

void Canvas::Clear() {
    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Canvas::Render(double dt){

    agents.Update(dt);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, agents.getVertexData().size()*sizeof(float), agents.getVertexData().data(), GL_DYNAMIC_DRAW);

    glEnable(GL_PROGRAM_POINT_SIZE);
    glDrawArrays(GL_POINTS, 0, agents.getVertexData().size());

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


}

GLuint Canvas::getTextureID()
{
    return texture;
}

Canvas::~Canvas()
{
    if(EBO != 0) {
        glDeleteBuffers(1, &EBO);
        EBO = 0;
    }
    if(VBO != 0) {
        glDeleteBuffers(1, &VBO);
        VBO = 0;
    }
    if(VAO != 0) {
        glDeleteVertexArrays(1, &VAO);
        VAO = 0;
    }
}