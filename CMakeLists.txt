cmake_minimum_required(VERSION 3.10)
project(ClusteringProject)

set(CMAKE_CXX_STANDARD 11)

# путь к SFML
set(SFML_DIR "/opt/homebrew/opt/sfml")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(/usr/local/include)

link_directories(/opt/homebrew/opt/sfml)

set(SOURCES
        main.cpp
        csv.cpp
        dbscan.cpp
        graphs.cpp
        kmeans.cpp
        utils.cpp
        utils.h
)

add_executable(ClusteringProject ${SOURCES})

target_link_libraries(ClusteringProject sfml-graphics sfml-window sfml-system)
