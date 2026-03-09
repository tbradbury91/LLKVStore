#pragma once
#include "Memtable.h"
#include "WriteAheadLog.h"
#include <memory>

class KVStoreImpl {
public:
  KVStoreImpl();
  void put(const std::string& key, const std::string& value);
  std::string get(const std::string& key) const;
  void remove(const std::string& key);

private:
  Memtable memtable;
  std::unique_ptr<WriteAheadLog> wal; // optional WAL
};
