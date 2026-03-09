#include "KVStore.h"
KVStore::KVStore() : impl(std::make_unique<KVStoreImpl>()) {}
KVStore::~KVStore() = default;
void KVStore::put(const std::string& key, const std::string& value) {
  impl->put(key, value);
}
std::string KVStore::get(const std::string& key) const {
  return impl->get(key);
}
void KVStore::remove(const std::string& key) {
  impl->remove(key);
}