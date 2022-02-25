#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "Manager.h"

namespace df {

class GameManager : public Manager {
    
    private:
        GameManager();
        GameManager(GameManager const&);
        void operator=(GameManager const&);
        bool game_over;
        int frame_time;
    
    public:
        static GameManager& getInstance();
        int startUp();
        void shutDown();
        void run();
        void setGameOver(bool new_game_over=true);
        bool getGameOver() const;
        int getFrameTime() const;

};

}

#endif // __GAME_MANAGER_H__