//


//
// Created by maciej on 20.08.18.

#include <Logger.hpp>
#include <ctime>

#if defined(DEBUG)
#include <iostream>
#endif

using namespace std;

unique_ptr<ofstream> Logger::_logFile = unique_ptr<ofstream>(nullptr);

Logger::Logger(const string &_nameOfLoggerOwner) : _nameOfLoggerOwner(_nameOfLoggerOwner)
{
    if (not Logger::_logFile) initLogFile();
}

void Logger::initLogFile()
{
    auto now = time(nullptr);
    auto timeNow = localtime(&now);
    string fileName = "logs/";
    fileName += to_string(timeNow->tm_year);
    fileName += to_string(timeNow->tm_mon);
    fileName += to_string(timeNow->tm_mday);
    fileName += to_string(timeNow->tm_hour);
    fileName += to_string(timeNow->tm_min);
    fileName += ".log";
    Logger::_logFile = make_unique<ofstream>(fileName);
}

Logger::~Logger()
{
    if (_logFile)
    {
        clearBuffer();
        if (_logFile->is_open()) _logFile->close();
    }
}

void Logger::clearBuffer()const
{
    if (_buffer.empty()) return;
    *_logFile << '[' << _nameOfLoggerOwner << "] " << _buffer << '\n';
#if defined(DEBUG)
    std::cout << '[' << _nameOfLoggerOwner << "] " << _buffer << std::endl;
#endif
    _buffer.clear();
}


void Logger::setNameOfLoggerOwner(const string &nameOfLoggerOwner)
{
    _nameOfLoggerOwner = nameOfLoggerOwner;
}

const Logger &operator<<(const Logger &log, const char *strm)
{
    std::string tmp{strm};
    tmp += ' ';
    if (not tmp.empty())
    {
        log.addToBuffer(strm);
    }
    return log;
}

const Logger &operator<<(const Logger &log, const logging &strm)
{
    if (strm == logging::logEnd)
    {
        log.clearBuffer();
    }

    return log;
}