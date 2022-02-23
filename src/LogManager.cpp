#include <stdio.h>
#include "LogManager.h"

namespace df {

LogManager::LogManager() {
    setType("LogManager");
}

LogManager::~LogManager() { }


LogManager& LogManager::getInstance() {
    LogManager *p_log_manager = new LogManager;
    return *p_log_manager;
}

int LogManager::startUp() {
    m_p_f = fopen("cfile.txt", "wt");
    if (m_p_f != nullptr) {
        return 0;
    }
    return -1;

}
void LogManager::shutDown() {
    fclose(m_p_f);
}

void LogManager::setFlush(bool do_flush) {

}

int LogManager::writeLog(const char *fmt, ...) const {
    fputs("fopen example", m_p_f);
    return 0;
}


}