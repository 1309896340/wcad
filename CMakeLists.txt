cmake_minimum_required(VERSION 3.10.0)
project(windcad VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH
    "C:/Users/13098/Documents/libraries/libs/QT"
)

file(GLOB MYSRC
    "src/*.cpp"
)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(windcad
    "demo/main.cpp"
    "src/${MYSRC}"
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "include"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Widgets
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND "${WINDEPLOYQT_EXECUTABLE}"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
            COMMENT "Deploying Qt libraries for ${PROJECT_NAME}..."
        )