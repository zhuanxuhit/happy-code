add_executable(type_alias type_alias.cpp)
add_executable(noexcept noexcept.cpp)
add_executable(overide overide.cpp)
add_executable(final final.cpp)
add_executable(ic implicit_cast.cpp)
add_executable(dc down_cast.cpp)
add_executable(sp shared_ptr.cpp)
add_executable(up unique_ptr.cpp)
add_executable(sfinae sfinae.cpp)
set_target_properties(sfinae PROPERTIES
        CXX_STANDARD 17)