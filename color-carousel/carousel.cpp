#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void processEscape(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}

double getRandom(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

int main(){

    //version control and GLFW setup

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //more setup and defining the size

    GLFWwindow *window = glfwCreateWindow(800, 600, "Hello, world!", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glViewport(0, 0, 800, 600); //something interesting about the viewport is that you can render less than the full window

    //showing

    while(!glfwWindowShouldClose(window)){
        processEscape(window);

        glClearColor(getRandom(), getRandom(), getRandom(), getRandom()); //generating color with 4 random numbers
        glClear(GL_COLOR_BUFFER_BIT);
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); //sleeping for safe reasons

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate(); //finishing the process
    return 0;
}
