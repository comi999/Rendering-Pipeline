#include <iostream>
#include <GLFW/glfw3.h>
#include <assimp/Importer.hpp>
#include <assimp/config.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <entt/entt.hpp>
#include <glm/glm.hpp>
#include <imgui.h>

int main()
{
    ImGui::Begin("UI");
    ImGui::End();

    entt::registry r;
    glm::vec2 v;

    Assimp::Importer imp;
    stbi_load( "", 0, 0, 0, 3 );

	GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "GLFW CMake starter", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glClearColor( 0.4f, 0.3f, 0.4f, 0.0f );

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

}