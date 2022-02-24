#include <stdio.h>
#include <stdarg.h>
#include <vector>
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
    m_p_f = fopen(LOGFILE_NAME.c_str(), "wt");
    if (m_p_f != nullptr) 
        return 0;
    
    return -1;
}

void LogManager::shutDown() {
    fclose(m_p_f);
}

void LogManager::setFlush(bool do_flush) {

}

int LogManager::writeLog(const char *fmt, ...) const {
    va_list args_size;
    va_start(args_size, fmt);
    int size = std::vsnprintf(nullptr, 0, fmt, args_size);
    va_end(args_size);
    
    std::vector<char> buf(size + 1);

    va_list args;
    va_start(args, fmt);
    std::vsnprintf(&buf[0], buf.size(), fmt, args);
    std::string message(buf.begin(), buf.end());
    fputs(message.c_str(), m_p_f);
    va_end(args);

    return size;
}


}