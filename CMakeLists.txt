cmake_minimum_required(VERSION 3.29)

project(nuclearreaction)

add_executable(${PROJECT_NAME} main.cpp Game.cpp Scene.cpp Fuel.cpp Neutron.cpp) 

target_link_libraries(${PROJECT_NAME} libsfml-graphics.so libsfml-window.so libsfml-audio.so libsfml-network.so libsfml-system.so GL.so)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
