#include "mui.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include <slog/slog.h>

#include <glad/glad.h>

struct MUIContext {
    GLFWwindow* window;
    bool init;
    uint32_t shaderID;
};

static SLogger s_Logger = {0};
static MUIContext* ctx = NULL;

static void log_fatal(const char* msg) {
    slogLogConsole(&s_Logger, SLOG_SEVERITY_FATAL, msg);
    abort();
}

static void init_ctx() {
    const char* vSrc = "#version 330 core\n"
                        "void main() {\n"
                        "}\n"
                        "\0";
    const char* fSrc = "#version 330 core\n"
                        "void main() {\n"
                        "}\n"
                        "\0";

    int success;
    char log[1024];

    uint32_t vert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert, 1, &vSrc, NULL);
    glCompileShader(vert);
    glGetShaderiv(vert, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vert, 1024, NULL, log);
        log_fatal(log);
    }

    uint32_t frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag, 1, &fSrc, NULL);
    glCompileShader(frag);
    glGetShaderiv(frag, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(frag, 1024, NULL, log);
        log_fatal(log);
    }

    ctx->shaderID = glCreateProgram();
    glAttachShader(ctx->shaderID, vert);
    glAttachShader(ctx->shaderID, frag);
    glLinkProgram(ctx->shaderID);
    glValidateProgram(ctx->shaderID);
    glGetProgramiv(ctx->shaderID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(ctx->shaderID, 1024, NULL, log);
        log_fatal(log);
    }

    glDeleteShader(vert);
    glDeleteShader(frag);
}

static void deinit_ctx() {
    glDeleteProgram(ctx->shaderID);
}

void mui_setctx(MUIContext* ctx_) {
    if(ctx_ == NULL)
        log_fatal("The context must be a valid pointer!");

    ctx = ctx_;
}

size_t mui_sizeofcontext() {
    return sizeof(MUIContext);
}

void mui_init(GLFWwindow* window) {
    slogLoggerReset(&s_Logger);
    slogLoggerSetName(&s_Logger, "MinUI");

    if(window == NULL) {
        log_fatal("The window must be valid!");
    }
    
    if(ctx == NULL) {
        log_fatal("The context must be a valid pointer to a MUIContext object! The current context must be set through the mui_setctx function!");
    }
    
    if(ctx->init) {
        log_fatal("MinUI is already initialized!");
    }

    ctx->init = true;
    ctx->window = window;

    init_ctx();
}

void mui_deinit() {
    if(ctx == NULL) {
        log_fatal("The context must be a valid pointer to a MUIContext object!");
    }

    if(!ctx->init) {
        log_fatal("Can't deinit MinUI since it is not yet initialized!");
    }

    deinit_ctx();
}
