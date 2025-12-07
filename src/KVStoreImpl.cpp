#include "KVStoreImpl.h"

KVStoreImpl::KVStoreImpl() {
    wal = std::make_unique<WriteAheadLog>("LLKVStore.log");
}

void KVStoreImpl::put(const std::string& key, const std::string& value) {
    memtable.put(key, value);
    wal->logPut(key, value);
}

std::string KVStoreImpl::get(const std::string& key) const {
    return memtable.get(key);
}

void KVStoreImpl::remove(const std::string& key) {
    memtable.remove(key);
    wal->logRemove(key);
}
