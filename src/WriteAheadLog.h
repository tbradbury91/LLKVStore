#pragma once
#include <string>
#include <fstream>
#include <mutex>

class WriteAheadLog {
public:
  WriteAheadLog(const std::string& filename);
  ~WriteAheadLog();
  void logPut(const std::string& key, const std::string& value);
  void logRemove(const std::string& key);

private:
  std::ofstream logFile;
  std::mutex mtx;
};
