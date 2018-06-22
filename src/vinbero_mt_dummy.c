#include <dlfcn.h>
#include <err.h>
#include <fcntl.h>
#include <libgenc/genc_Tree.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <vinbero_common/vinbero_common_TlModule.h>
#include <vinbero_common/vinbero_common_Config.h>
#include <vinbero_common/vinbero_common_Log.h>
#include <vinbero_common/vinbero_common_Module.h>
#include <vinbero/vinbero_interface_MODULE.h>
#include <vinbero/vinbero_interface_TLOCAL.h>
#include <vinbero/vinbero_interface_TLSERVICE.h>

struct vinbero_mt_dummy_LocalModule {
    const char* message;
    int interval;
};

VINBERO_INTERFACE_MODULE_FUNCTIONS;
VINBERO_INTERFACE_TLOCAL_FUNCTIONS;
VINBERO_INTERFACE_TLSERVICE_FUNCTIONS;

int vinbero_interface_MODULE_init(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE2();
    module->name = "vinbero_mt_dummy";
    module->version = "0.0.1";
    module->childrenRequired = false;
    module->localModule.pointer = malloc(1 * sizeof(struct vinbero_mt_dummy_LocalModule));
    struct vinbero_mt_dummy_LocalModule* localModule = module->localModule.pointer;
    vinbero_common_Config_getString(module->config, module, "vinbero_mt_dummy.message", &(localModule->message), "I HAVE NOTHING TO SAY");
    vinbero_common_Config_getInt(module->config, module, "vinbero_mt_dummy.interval", &(localModule->interval), 1);
    return 0;
}

int vinbero_interface_MODULE_rInit(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE2();
    return 0;
}

int vinbero_interface_TLOCAL_init(struct vinbero_common_TlModule* tlModule) {
    VINBERO_COMMON_LOG_TRACE2();
    return 0;
}

int vinbero_interface_TLOCAL_rInit(struct vinbero_common_TlModule* tlModule) {
    VINBERO_COMMON_LOG_TRACE2();
    return 0;
}

int vinbero_interface_TLSERVICE_call(struct vinbero_common_TlModule* tlModule) {
    VINBERO_COMMON_LOG_TRACE2();
    struct vinbero_mt_dummy_LocalModule* localModule = tlModule->module->localModule.pointer;
    while(true) {
        VINBERO_COMMON_LOG_DEBUG("%s", localModule->message);
        sleep(localModule->interval);
    }
    return 0;
}

int vinbero_interface_TLOCAL_destroy(struct vinbero_common_TlModule* tlModule) {
    VINBERO_COMMON_LOG_TRACE2();
    return 0;
}

int vinbero_interface_TLOCAL_rDestroy(struct vinbero_common_TlModule* tlModule) {
    VINBERO_COMMON_LOG_TRACE2();
    return 0;
}

int vinbero_interface_MODULE_destroy(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE2();
    return 0;
}

int vinbero_interface_MODULE_rDestroy(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE2();
    struct vinbero_mt_dummy_LocalModule* localModule = module->localModule.pointer;
    free(module->localModule.pointer);
    return 0;
}

