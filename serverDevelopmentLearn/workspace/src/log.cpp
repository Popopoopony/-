#include "log.h"

namespace max {

Logger::Logger(const std::string& name) : m_name(name) {}
void Logger::addAppender(LogAppender::ptr appender) {
  m_appenders.push_back(appender);
}
void Logger::delAppender(LogAppender::ptr appender) {
  for (auto it = m_appenders.begin(); it != m_appenders.end(); it++) {
    if (*it == appender) {
      m_appenders.erase(it);
      break;
    }
  }
}
void Logger::log(LogLevel::Level level, LogEvent::ptr event) {
  if (level >= m_level) {
    for (auto& n : m_appenders) {
      n->log(level, event);
    }
  }
}
void Logger::debug(LogEvent::ptr event) { debug(LogLevel::DEBUG, event); }
void Logger::info(LogEvent::ptr event) { debug(LogLevel::INFO, event); }
void Logger::warn(LogEvent::ptr event) { debug(LogLevel::WARN, event); }
void Logger::error(LogEvent::ptr event) { debug(LogLevel::ERROR, event); }
void Logger::fatal(LogEvent::ptr event) { debug(LogLevel::FATAL, event); }

void log(LogLevel::Level level, LogEvent::ptr event) 
void log(LogLevel::Level level, LogEvent::ptr event) 

void FileLogAppender::FileLogAppender(const std::string& filename) {

}
void FileLogAppender::log(LogLevel::Level level, LogEvent::ptr event) {

}

void StdoutLogAppender::log(LogLevel::Level level, LogEvent::ptr event) {
    if (level >= m_level) {

    }
    
}
}  // namespace max