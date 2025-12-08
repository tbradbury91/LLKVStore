# LLKVStore
A High-Performance Low-Latency In-Memory Key-Value Store

## Overview
LLKVStore is a modern C++ in-memory key-value store designed to handle high-throughput, low-latency operations safely in multi-threaded environments. It demonstrates the core skills required in high-frequency trading (HFT) systems, including concurrency, memory optimisation, and reliable data handling.

While LLKVStore doesn’t execute trades itself, it represents the kind of ultra-fast data infrastructure used in trading systems to store live market data, orders, and positions, enabling trading engines to make microsecond-level decisions.

## Key Features
- Thread-safe in-memory storage (put, get, remove)
- Concurrent multi-threaded operations using std::thread and std::shared_mutex
- Optional Write-Ahead Log (WAL) for durability
- High-performance design optimised for low-latency access
- Built-in multi-threaded benchmarking to measure insert and retrieve performance

## Architecture
- KVStore — Public interface for client use
- KVStoreImpl — Core implementation coordinating Memtable and WAL
- Memtable — Thread-safe in-memory hash map
- WriteAheadLog — Optional disk-based log for durability
- utils — Timer and helper utilities for benchmarking

## Benchmark Example
---- Concurrent Insert Benchmark ----
Insert time: 0.154 seconds
---- Concurrent Retrieve Benchmark ----
Retrieve time: 0.021 seconds

100,000 entries across 8 threads; insert and retrieve times demonstrate low-latency performance suitable for HFT applications.

## Getting Started
Build
cd ~/Documents/LLKVStore/src
g++ -std=c++20 -O2 -pthread *.cpp -o LLKVStore
Run Benchmark
./LLKVStore
Tech Stack
C++20
std::thread, std::mutex, std::shared_mutex for concurrency
std::unordered_map for in-memory storage
Optional Write-Ahead Log (fstream)
Benchmarking via std::chrono

## Real-World Relevance
LLKVStore is similar to components used in high-frequency trading and crypto exchange systems. It provides a fast, reliable, concurrent store for live market data, orders, and positions, allowing trading engines to make decisions at microsecond speeds. This project demonstrates key HFT skills: low-latency design, concurrency, memory optimisation, and end-to-end system architecture.
