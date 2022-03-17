cmake_minimum_required(VERSION 3.10)
project(dragonfly_impl LANGUAGES CXX)

include_directories(include)

add_library(engine
	src/Clock.cpp
	src/Event.cpp
	src/EventStep.cpp
	src/GameManager.cpp
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

add_executable(engine_test
	src/game.cpp
)

target_link_libraries(engine_test
	PRIVATE
		engine
)


add_executable(unit_tests
	test/main.cpp
	test/test_EventStep.cpp
	test/test_GameManager.cpp
	test/test_Hello.cpp
	test/test_Manager.cpp
	test/test_Object.cpp
	test/test_ObjectList.cpp
	test/test_ObjectListIterator.cpp
	test/test_Vector.cpp
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

FetchContent_MakeAvailable(Catch2)

target_link_libraries(unit_tests PRIVATE Catch2 engine)
