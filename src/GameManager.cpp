#include "GameManager.h"
#include "LogManager.h"

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

void GameManager::run() {

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

}