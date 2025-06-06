cmake_minimum_required(VERSION 3.23.0)
project(wcad VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets OpenGL OpenGLWidgets)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(GLM_DIR
    "C:/Users/13098/Documents/libraries/libs/glm"
)

file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp" "src/*.ui")


add_executable(${PROJECT_NAME}
    ${ALL_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::OpenGL
    Qt6::OpenGLWidgets
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${GLM_DIR}/include"
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND "${WINDEPLOYQT_EXECUTABLE}"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
        )

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
            "${CMAKE_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"
)
