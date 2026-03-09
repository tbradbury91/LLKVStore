#include "WriteAheadLog.h"

WriteAheadLog::WriteAheadLog(const std::string& filename) {
  logFile.open(filename, std::ios::app | std::ios::binary);
}

WriteAheadLog::~WriteAheadLog() {
  logFile.close();
}

void WriteAheadLog::logPut(const std::string& key, const std::string& value) {
  std::lock_guard lock(mtx);
  logFile << "PUT " << key << " " << value << "\n";
}

void WriteAheadLog::logRemove(const std::string& key) {
  std::lock_guard lock(mtx);
  logFile << "REMOVE " << key << "\n";
}
