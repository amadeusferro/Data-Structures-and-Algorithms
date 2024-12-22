#include <iostream>
#include <vector>
#include <cmath>

void hillisSteeleScan(std::vector<int>& vec) {

    for (int i = 0; i < std::log2(vec.size()); i++) {
        int offset = 1 << i;

        for (int j = vec.size() - 1; j >= offset; j--) {
            vec[j] += vec[j - offset];
        }
    }
}

int main() {

    std::vector<int> myVector = {1, 2, 3, 4, 5, 6, 7, 8};

    for (auto& key : myVector) {
        std::cout << key << " ";
    }
    std::cout << "\n";

    hillisSteeleScan(myVector);

    for (auto& key : myVector) {
        std::cout << key << " ";
    }
    std::cout << "\n";

    return 0;
}