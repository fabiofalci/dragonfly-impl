#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include <stdio.h>
#include "Manager.h"

#define LM df::LogManager::getInstance()

namespace df {

const std::string LOGFILE_NAME = "dragonfly.log";

class LogManager : public Manager {

    private:
        LogManager();
        LogManager(LogManager const&);

        void operator=(LogManager const&);
        bool m_do_flush;
        FILE *m_p_f;


    public:
        ~LogManager();
        static LogManager& getInstance();
        int startUp();
        void shutDown();
        void setFlush(bool do_flush=true);
        int writeLog(const char *fmt, ...) const;
        
};

}

#endif // __LOG_MANAGER_H__