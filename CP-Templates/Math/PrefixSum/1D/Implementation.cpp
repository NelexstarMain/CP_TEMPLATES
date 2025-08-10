#include <iostream>
#include <vector>

std::vector<int> prefix_sum(const std::vector<int>& arr) {
    std::vector<int> ps(arr.size());
    if (arr.empty()) return ps;

    ps[0] = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        ps[i] = ps[i - 1] + arr[i];
    }
    return ps;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    auto ps = prefix_sum(arr);

    for (int val : ps) std::cout << val << " ";
    std::cout << "\n";
}
