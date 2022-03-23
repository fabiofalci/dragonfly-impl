#include <chrono>
#include <thread>

#include "GameManager.h"
#include "LogManager.h"
#include "Clock.h"
#include "ObjectList.h"
#include "WorldManager.h"
#include "EventStep.h"

namespace df {

GameManager::GameManager() {
    setType("GameManager");
    game_over = false;
}

GameManager::GameManager(GameManager const&) {}

void GameManager::operator=(GameManager const&) {}

GameManager& GameManager::getInstance() {
    static GameManager *p_game_manager = new GameManager;
    return *p_game_manager;
}

int GameManager::startUp() {
    game_over = false;
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

        ObjectList all_objects = WM.getAllObjects();
        ObjectListIterator li(&all_objects);

        EventStep event_step;
        for (li.first(); !li.isDone(); li.next())
            li.currentObject()->eventHandler(&event_step);

        LM.writeLog("Loop %ld", loop_time);

        WM.update();

        loop_time = clock->split();
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_TIME_DEFAULT - loop_time));
    }

}

}