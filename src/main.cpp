#include "glad/glad.h"

#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>     

#include "Window.h"
#include "Shader.h"
#include "Canvas.h"
#include "Agents.h"

int main()
{
    double deltaTime = 0.0;
    double lastTime = 0.0;
    srand(42);

    static const char* vShader = "bin/shaders/shader.vert";
    static const char* fShader = "bin/shaders/shader.frag";

    Window mainWindow = Window(1600, 800);
    mainWindow.Initialise();


    Shader* shader = new Shader();
    shader->CreateFromFiles(vShader, fShader);

    int nx = 1024, ny = 512;
    Canvas* canvas = new Canvas(nx, ny);


    GLuint texId = canvas->getTextureID();

    while(!mainWindow.getShouldClose()){
        double now = glfwGetTime();
        deltaTime = now - lastTime;
        lastTime = now;
        glfwPollEvents();

        shader->UseShader();
        canvas->Render(deltaTime);

        mainWindow.swapBuffers();
    }

    return 0;
}

