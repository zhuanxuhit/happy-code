add_executable(pcreate pthread_create.cpp Thread.cpp)
target_link_libraries(pcreate pthread)