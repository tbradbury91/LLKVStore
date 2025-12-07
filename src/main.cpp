#include <iostream>
#include <thread>
#include <vector>
#include "KVStore.h"
#include "utils.h"

void insertRange(KVStore& store, int start, int end) {
    for (int i = start; i < end; ++i) {
        store.put("key" + std::to_string(i), "value" + std::to_string(i));
    }
}

void retrieveRange(KVStore& store, int start, int end) {
    for (int i = start; i < end; ++i) {
        store.get("key" + std::to_string(i));
    }
}

int main() {
    KVStore store;
    const int numEntries = 100000;
    const int numThreads = 8;
    int range = numEntries / numThreads;

    std::cout << "---- Concurrent Insert Benchmark ----" << std::endl;
    Timer t;
    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i)
        threads.emplace_back(insertRange, std::ref(store), i*range, (i+1)*range);
    for (auto& th : threads) th.join();
    std::cout << "Insert time: " << t.elapsed() << " seconds" << std::endl;

    std::cout << "---- Concurrent Retrieve Benchmark ----" << std::endl;
    t.reset();
    threads.clear();
    for (int i = 0; i < numThreads; ++i)
        threads.emplace_back(retrieveRange, std::ref(store), i*range, (i+1)*range);
    for (auto& th : threads) th.join();
    std::cout << "Retrieve time: " << t.elapsed() << " seconds" << std::endl;

    return 0;
}
