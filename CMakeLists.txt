cmake_minimum_required(VERSION 3.12)
project(220TermProject)

set(CMAKE_CXX_STANDARD 14)


add_executable(220TermProject Library.cpp Song.cpp Playlist.cpp Tests.cpp ArrayList.inl TestLib.cpp)