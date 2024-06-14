cmake_minimum_required(VERSION 3.10)

# Define the project name
project(biblioteca_de_musicas)

# Include directories
include_directories(include)

# Collect all osruce files form different directories
file(GLOB ALBUM_SRC "src/album/*.cpp")
file(GLOB ARTIST_SRC "src/artist/*.cpp")
file(GLOB LISTENER_SRC "src/listener/*.cpp")
file(GLOB PLAYLIST_SRC "src/playlist/*.cpp")
file(GLOB SONG_SRC "src/song/*.cpp")
file(GLOB SYSTEM_SRC "src/system/*.cpp")
file(GLOB USER_SRC "src/user/*.cpp")

# Add the sources
set(SOURCES
    ${SYSTEM_SRC}
    src/main2.cpp
)

# Add the executable
add_executable(biblioteca_de_musicas ${SOURCES})