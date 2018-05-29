#include <dlfcn.h>
#include <err.h>
#include <fcntl.h>
#include <libgenc/genc_Tree.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <vinbero_common/vinbero_common_Config.h>
#include <vinbero_common/vinbero_common_Log.h>
#include <vinbero_common/vinbero_common_Module.h>
#include <vinbero/vinbero_IMODULE.h>
#include <vinbero/vinbero_ITLOCAL.h>
#include <vinbero/vinbero_ITLSERVICE.h>

struct vinbero_mt_dummy_LocalModule {
    const char* message;
    int interval;
};

VINBERO_IMODULE_FUNCTIONS;
VINBERO_ITLOCAL_FUNCTIONS;
VINBERO_ITLSERVICE_FUNCTIONS;

int vinbero_IMODULE_init(struct vinbero_common_Module* module, struct vinbero_common_Config* config, void* args[]) {
    VINBERO_COMMON_LOG_TRACE2();
    module->name = "vinbero_mt_dummy";
    module->version = "0.0.1";
    module->childrenRequired = false;
    module->localModule.pointer = malloc(1 * sizeof(struct vinbero_mt_dummy_LocalModule));
    struct vinbero_mt_dummy_LocalModule* localModule = module->localModule.pointer;
    vinbero_common_Config_getString(config, module, "vinbero_mt_dummy.message", &(localModule->message), "I HAVE NOTHING TO SAY");
    vinbero_common_Config_getInt(config, module, "vinbero_mt_dummy.interval", &(localModule->interval), 1);
    return 0;
}

int vinbero_IMODULE_rInit(struct vinbero_common_Module* module, struct vinbero_common_Config* config, void* args[]) {
    VINBERO_COMMON_LOG_TRACE2();
    return 0;
}

int vinbero_ITLOCAL_init(struct vinbero_common_Module* module, struct vinbero_common_Config* config, void* args[]) {
    VINBERO_COMMON_LOG_TRACE2();
    return 0;
}

int vinbero_ITLOCAL_rInit(struct vinbero_common_Module* module, struct vinbero_common_Config* config, void* args[]) {
    VINBERO_COMMON_LOG_TRACE2();
    return 0;
}

int vinbero_ITLSERVICE_call(struct vinbero_common_Module* module, void* args[]) {
    VINBERO_COMMON_LOG_TRACE2();
    struct vinbero_mt_dummy_LocalModule* localModule = module->localModule.pointer;
    while(true) {
        VINBERO_COMMON_LOG_DEBUG("%s", localModule->message);
        sleep(localModule->interval);
    }
    return 0;
}

int vinbero_ITLOCAL_destroy(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE2();
    return 0;
}

int vinbero_ITLOCAL_rDestroy(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE2();
    return 0;
}

int vinbero_IMODULE_destroy(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE2();
    return 0;
}

int vinbero_IMODULE_rDestroy(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE2();
    struct vinbero_mt_dummy_LocalModule* localModule = module->localModule.pointer;
    free(module->localModule.pointer);
    if(module->tlModuleKey != NULL)
        free(module->tlModuleKey);
//    dlclose(module->dl_handle);

    return 0;
}

