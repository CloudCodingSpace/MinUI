#pragma once

#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

typedef struct MUIContext MUIContext;

void mui_init(GLFWwindow* window);
void mui_deinit();

void mui_setctx(MUIContext* ctx);
size_t mui_sizeofcontext();

#ifdef __cplusplus
}
#endif
