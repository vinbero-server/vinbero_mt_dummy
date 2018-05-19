add_library(vinbero_mt_dummy MODULE vinbero_mt_dummy.c)
set_target_properties(vinbero_mt_dummy PROPERTIES PREFIX "")
target_link_libraries(vinbero_mt_dummy vinbero_common)
install(TARGETS vinbero_mt_dummy
        LIBRARY DESTINATION lib/vinbero)
