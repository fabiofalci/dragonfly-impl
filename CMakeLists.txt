cmake_minimum_required(VERSION 3.10)
project(dragonfly_impl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_library(engine
	src/Clock.cpp
	src/DisplayManager.cpp
	src/Event.cpp
	src/EventStep.cpp
	src/EventKeyboard.cpp
	src/EventMouse.cpp
	src/GameManager.cpp
	src/InputManager.cpp
	src/LogManager.cpp
	src/Manager.cpp
	src/Object.cpp
	src/ObjectList.cpp
	src/ObjectListIterator.cpp
	src/Vector.cpp
	src/WorldManager.cpp
)

target_include_directories(engine
	PUBLIC
		src
)

add_executable(engine_example
	example/game.cpp
	example/Saucer.cpp
	example/Star.cpp
)

target_link_libraries(engine_example
	PRIVATE
		engine sfml-audio sfml-graphics sfml-system sfml-window
)


add_executable(unit_tests
	test/main.cpp
	test/test_EventStep.cpp
	test/test_GameManager.cpp
	test/test_Hello.cpp
	test/test_InputManager.cpp
	test/test_Manager.cpp
	test/test_Object.cpp
	test/test_ObjectList.cpp
	test/test_ObjectListIterator.cpp
	test/test_Vector.cpp
	test/test_WorldManager.cpp
)

target_include_directories(unit_tests
	PUBLIC
		test/
)

Include(FetchContent)

FetchContent_Declare(
	Catch2
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG        v2.13.8
)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.5.1
)

FetchContent_MakeAvailable(Catch2 sfml)

target_link_libraries(engine PRIVATE sfml-audio sfml-graphics sfml-system sfml-window)
target_link_libraries(unit_tests PRIVATE Catch2 engine sfml-audio sfml-graphics sfml-system sfml-window)
