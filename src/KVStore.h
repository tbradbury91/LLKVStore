#pragma once
#include "KVStoreImpl.h"
#include <memory>
#include <string>

class KVStore {
public:
  KVStore();
  ~KVStore();
  void put(const std::string& key, const std::string& value);
  std::string get(const std::string& key) const;
  void remove(const std::string& key);

private:
  std::unique_ptr<KVStoreImpl> impl;
};
