#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib>
#include <vector>

const int CORES = std::thread::hardware_concurrency();
std::mutex globalLock;

void quickSort(std::vector<int>* arr, int startIdx, int endIdx, int maxthreads = 1) {
    static int threadsNumber = 1;
    //std::lock_guard<std::mutex> lock(globalLock);

    if (startIdx != endIdx) {
        int pointerIdx = startIdx - 1;
        for (int i = startIdx; i <= endIdx; i++) {
            if ((*arr)[i] <= (*arr)[endIdx]) {
                pointerIdx += 1;

                int temp = (*arr)[i];
                (*arr)[i] = (*arr)[pointerIdx];
                (*arr)[pointerIdx] = temp;
            }
        }

        std::thread left;
        std::thread right;

        if ((pointerIdx - 1) >= startIdx) {
            if (threadsNumber < maxthreads) {
                left = std::thread(quickSort, arr, startIdx, pointerIdx - 1, maxthreads);
                threadsNumber++;
            }
            else {
                quickSort(arr, startIdx, pointerIdx - 1, maxthreads);
            }
        }

        if ((pointerIdx + 1) <= endIdx) {
            if (threadsNumber < maxthreads) {
                right = std::thread(quickSort, arr, pointerIdx + 1, endIdx, maxthreads);
                threadsNumber++;
            }
            else {
                quickSort(arr, pointerIdx + 1, endIdx, maxthreads);
            }
        }

        if (left.joinable()) {
            left.join();
        }
        if (right.joinable()) {
            right.join();
        }
    }
}

int main()
{
    for (int vectorLen : {10'000, 100'000, 1'000'000, 10'000'000, 100'000'000}) {
        for (int maxThreadsNumber : {1, 2, CORES, CORES * 2}) {

            std::vector<int>* vec = new std::vector<int>{};
            for (int i = 0; i < vectorLen; i++) {
                vec->push_back(std::rand());
            }
            auto t_start = std::chrono::high_resolution_clock::now();

            quickSort(vec, 0, vectorLen - 1, maxThreadsNumber);

            auto t_end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start);

            std::cout << "The vector of " << vectorLen << " elements was sorted in " << duration.count() << " using " << maxThreadsNumber << " threads." << std::endl;

            delete vec;
        }
    }

    return 0;
}
