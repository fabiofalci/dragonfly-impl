#include "GameManager.h"
#include "LogManager.h"
#include "Clock.h"

#include <chrono>
#include <thread>


namespace df {

GameManager::GameManager() {
    setType("GameManager");
}

GameManager::GameManager(GameManager const&) {}

void GameManager::operator=(GameManager const&) {}

GameManager& GameManager::getInstance() {
    static GameManager *p_game_manager = new GameManager;
    return *p_game_manager;
}

int GameManager::startUp() {
    LM.startUp();
    return Manager::startUp();
}

void GameManager::shutDown() {
    game_over = true;
    LM.shutDown();
    return Manager::shutDown();
}

void GameManager::setGameOver(bool new_game_over) {
    game_over = new_game_over;
}

bool GameManager::getGameOver() const {
    return game_over;
}

int GameManager::getFrameTime() const {
    return 0;
}

void GameManager::run() {
    df::Clock *clock = new df::Clock;

    long int loop_time = -1;
    while (!game_over) {
        clock->delta();

        // to stuff
        LM.writeLog("Loop %ld", loop_time);

        loop_time = clock->split();
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_TIME_DEFAULT - loop_time));
    }

}

}