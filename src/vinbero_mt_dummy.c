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
#include <vinbero/vinbero_IModule.h>
#include <vinbero/vinbero_ITLocal.h>
#include <vinbero/vinbero_ITlService.h>

struct vinbero_mt_dummy_LocalModule {
    const char* message;
    int interval;
};

VINBERO_IMODULE_FUNCTIONS;
VINBERO_ITLOCAL_FUNCTIONS;
VINBERO_ITLSERVICE_FUNCTIONS;

int vinbero_IModule_init(struct vinbero_common_Module* module, struct vinbero_common_Config* config, void* args[]) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    module->name = "vinbero_mt_dummy";
    module->version = "0.0.1";
    module->needsChildren = false;
    module->localModule.pointer = malloc(1 * sizeof(struct vinbero_mt_dummy_LocalModule));
    struct vinbero_mt_dummy_LocalModule* localModule = module->localModule.pointer;
    vinbero_common_Config_getString(config, module, "vinbero_mt_dummy.message", &(localModule->message), "I HAVE NOTHING TO SAY");
    vinbero_common_Config_getInt(config, module, "vinbero_mt_dummy.interval", &(localModule->interval), 1);
    return 0;
}

int vinbero_IModule_rInit(struct vinbero_common_Module* module, struct vinbero_common_Config* config, void* args[]) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    return 0;
}

int vinbero_ITLocal_init(struct vinbero_common_Module* module, struct vinbero_common_Config* config, void* args[]) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    return 0;
}

int vinbero_ITLocal_rInit(struct vinbero_common_Module* module, struct vinbero_common_Config* config, void* args[]) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    return 0;
}

int vinbero_ITlService_call(struct vinbero_common_Module* module, void* args[]) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    struct vinbero_mt_dummy_LocalModule* localModule = module->localModule.pointer;
    while(true) {
        printf("%s\n", localModule->message);
        sleep(localModule->interval);
    }
    return 0;
}

int vinbero_ITLocal_destroy(struct vinbero_common_Module* module) {
    VINBERO_COMMON_LOG_TRACE("in %s()", __FUNCTION__);
    return 0;
}

int vinbero_ITLocal_rDestroy(struct vinbero_common_Module* module) {
VINBERO_COMMON_LOG_TRACE("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

int vinbero_IModule_destroy(struct vinbero_common_Module* module) {
VINBERO_COMMON_LOG_TRACE("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    return 0;
}

int vinbero_IModule_rDestroy(struct vinbero_common_Module* module) {
VINBERO_COMMON_LOG_TRACE("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
struct vinbero_mt_dummy_LocalModule* localModule = module->localModule.pointer;
    VINBERO_COMMON_LOG_TRACE("%s: %u: %s", __FILE__, __LINE__, __FUNCTION__);
    free(module->localModule.pointer);
    if(module->tlModuleKey != NULL)
        free(module->tlModuleKey);
//    dlclose(module->dl_handle);

    return 0;
}

