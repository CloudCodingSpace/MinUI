#include <stdio.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

const int WIDTH = 800;
const int HEIGHT = 600;
const char* TITLE = "MinUI test";

int main(int argc, const char** argv) {
    printf("Hello from MinUI Test!");

    if(!glfwInit()) {
        printf("Failed to init GLFW!");
        return -1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
    if(window == 0) {
        printf("Failed to create window!");
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwShowWindow(window);

    while(!glfwWindowShouldClose(window)) {
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}