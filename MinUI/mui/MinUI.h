#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <GLFW/glfw3.h>

void mui_init(GLFWwindow* window);
void mui_deinit();

#ifdef __cplusplus
}
#endif