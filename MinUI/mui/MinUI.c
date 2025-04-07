#include "MinUI.h"

#include <stdbool.h>
#include <stdlib.h>

#include <slog/slog.h>

static SLogger s_Logger = {0};
static GLFWwindow* s_Window = NULL;
static bool s_Init = false;

static void log_fatal(const char* msg) {
    slogLogConsole(&s_Logger, SLOG_SEVERITY_FATAL, msg);
    abort();
}

void mui_init(GLFWwindow* window) {
    slogLoggerReset(&s_Logger);
    slogLoggerSetName(&s_Logger, "MinUI");

    if(s_Init) {
        log_fatal("MinUI is already initialized!");
    }

    if(window == NULL) {
        log_fatal("The window must be valid!");
    }
    s_Init = true;
}

void mui_deinit() {
    if(!s_Init) {
        log_fatal("Can't deinit MinUI since it is not yet initialized!");
    }

    s_Window = NULL;
}
