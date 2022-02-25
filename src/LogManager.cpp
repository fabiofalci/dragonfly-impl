#include <stdio.h>
#include <stdarg.h>
#include <vector>
#include <cstring>
#include <iostream>
#include "LogManager.h"

namespace df {

LogManager::LogManager() {
    setType("LogManager");
}

LogManager::~LogManager() { }


LogManager& LogManager::getInstance() {
    static LogManager *p_log_manager = new LogManager;
    return *p_log_manager;
}

int LogManager::startUp() {
    m_p_f = fopen(LOGFILE_NAME.c_str(), "wt");
    if (m_p_f != nullptr)  {
        Manager::startUp();
        return 0;
    }
    
    return -1;
}

void LogManager::shutDown() {
    fclose(m_p_f);
    Manager::shutDown();
}

void LogManager::setFlush(bool do_flush) {
    m_do_flush = do_flush;
}

int LogManager::writeLog(const char *fmt, ...) const {
    va_list args_size;
    va_start(args_size, fmt);

    char *nfmt = new char[std::strlen(fmt) + 2];
    std::strcpy(nfmt, fmt);
    std::strcat(nfmt, "\n");

    int size = std::vsnprintf(nullptr, 0, nfmt, args_size);
    va_end(args_size);
    
    std::vector<char> buf(size + 1);

    va_list args;
    va_start(args, fmt);
    std::vsnprintf(&buf[0], buf.size(), nfmt, args);
    std::string message(buf.begin(), buf.end());
    fputs(message.c_str(), m_p_f);
    va_end(args);

    if (m_do_flush)
        fflush(m_p_f);

    return size;
}


}