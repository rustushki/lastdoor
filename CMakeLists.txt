cmake_minimum_required (VERSION 2.6)

project (Key)

add_executable (Key key.cpp Item.cpp Room.cpp)

install(TARGETS Key DESTINATION bin)
