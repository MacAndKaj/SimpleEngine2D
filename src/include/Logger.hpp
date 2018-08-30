//
// Created by maciej on 20.08.18.
//

#ifndef ENGINE_LOGGER_HPP
#define ENGINE_LOGGER_HPP

#include <fstream>
#include <memory>
const unsigned int maxBufferSize = 1024;

enum class logging{
    logEnd,
    warning,
    debug
};

class Logger
{
public:
    Logger () = delete;
    explicit Logger (const std::string &_nameOfLoggerOwner);
    virtual ~Logger ();
    void setNameOfLoggerOwner (const std::string &nameOfLoggerOwner);
private:
    void addToBuffer(const std::string& arg) const{_buffer.append(arg);}
    void clearBuffer()const;
    mutable std::string _buffer;
    std::string _nameOfLoggerOwner;
    static std::unique_ptr<std::ofstream> _logFile;
    static void initLogFile();
    friend const Logger& operator << (const Logger &log, const char* strm);
    friend const Logger& operator << (const Logger &log, const logging& strm);
};



#endif //ENGINE_LOGGER_HPP
