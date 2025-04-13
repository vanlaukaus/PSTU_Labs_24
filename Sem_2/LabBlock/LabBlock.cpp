#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void bsort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *std::max_element(arr.begin(), arr.end());
    int minVal = *std::min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    const int numBuckets = 10;
    std::vector<std::vector<int>> buckets(numBuckets);

    for (int num : arr) {
        int bucketIdx = (num - minVal) * numBuckets / range;
        buckets[bucketIdx].push_back(num);
    }

    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    size_t index = 0;
    for (const auto& bucket : buckets) {
        for (int num : bucket) {
            arr[index++] = num;
        }
    }
}

int main() {
    std::srand(std::time(0));

    const int size = 20;
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 100;
    }

    std::cout << "Original array:\n";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    bsort(arr);

    std::cout << "Sorted array:\n";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}