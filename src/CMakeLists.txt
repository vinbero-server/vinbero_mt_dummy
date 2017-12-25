add_library(tucube_mt_dummy MODULE tucube_mt_dummy.c)
set_target_properties(tucube_mt_dummy PROPERTIES PREFIX "")
install(TARGETS tucube_mt_dummy
        LIBRARY DESTINATION lib/tucube)
