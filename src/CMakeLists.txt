include_directories(include)
file(GLOB src_files
        sources/Animations/*.cpp
        sources/Buttons/*.cpp
        sources/Detectors/*.cpp
        sources/Helpers/*.cpp
        sources/Modules/*.cpp
        sources/Scenario/*.cpp
        sources/Windows/*.cpp
        sources/*.cpp)
add_library(MyLib ${src_files})

add_executable(${EXECUTABLE_NAME} MainWrapper.cpp)
target_link_libraries(${EXECUTABLE_NAME} MyLib)
find_package(SFML 2.5 REQUIRED network audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

