cmake_minimum_required(VERSION 3.12)
project(220TermProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(__MACOSX)

add_executable(220TermProject Library.cpp Song.cpp ReadSongs.cpp ReadSongs.h ReadFiles.h ReadPlaylists.cpp ReadPlaylists.h)