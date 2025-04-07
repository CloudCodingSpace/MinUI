#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <mui/MinUI.h>

const int WIDTH = 800;
const int HEIGHT = 600;
const char* TITLE = "MinUI test";

int main(int argc, const char** argv) {
    printf("Hello from MinUI Test!\n");

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
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize opengl!");
        return -1;
    }

    mui_init(window);

    glfwShowWindow(window);
    while(!glfwWindowShouldClose(window)) {
        {
            int width, height;
            glfwGetWindowSize(window, &width, &height);
            glViewport(0, 0, width, height);
        }

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    mui_deinit();
    glfwTerminate();
    return 0;
}