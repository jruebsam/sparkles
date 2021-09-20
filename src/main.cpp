#include "glad/glad.h"

#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>     

#include "Window.h"
#include "Shader.h"
#include "Canvas.h"
#include "Agents.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


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
    float my_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

    shader->UseShader();
    shader->setUniform("pointColor", my_color);

    while(!mainWindow.getShouldClose()){
        double now = glfwGetTime();
        deltaTime = now - lastTime;
        lastTime = now;
        glfwPollEvents();

        shader->UseShader();
        shader->setUniform("pointColor", my_color);
        canvas->Clear();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        canvas->Render(deltaTime);

        // render your GUI
        ImGui::Begin("Demo window");
            ImGui::ColorEdit3("Color", my_color);
        ImGui::End();

        // Render dear imgui into screen
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        mainWindow.swapBuffers();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    return 0;
}

