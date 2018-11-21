CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

set (CMAKE_CXX_STANDARD 11)
ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(rshell
	tests/rshell.cpp
) 

ADD_EXECUTABLE(test
    tests/test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
