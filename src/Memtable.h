#pragma once
#include <unordered_map>
#include <shared_mutex>
#include <string>

class Memtable {
public:
    void put(const std::string& key, const std::string& value);
    std::string get(const std::string& key) const;
    void remove(const std::string& key);

private:
    mutable std::shared_mutex mtx;
    std::unordered_map<std::string, std::string> store;
};
