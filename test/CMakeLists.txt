file(GLOB SRCS *.cpp)

add_executable(testAVLTree ${SRCS} ../AVLTree/AVLTree.h ../AVLTree/AVLTree.cpp)

target_link_libraries(testAVLTree
        gtest
        gmock
        )

include_directories("..")

install(TARGETS testAVLTree DESTINATION bin)