#include <iostream>
#include <vector>
#include <cmath>

void blellochScan(std::vector<int>& vec) {

    while((vec.size() & (vec.size()-1)) != 0) {
        vec.push_back(0);
    }

    for(int i = 0; i < log2(vec.size()); i++) {
        int step = 1 << (i + 1);
        for(int j = 0; j < vec.size(); j += step) {
            vec[j + step - 1] += vec[j + (step/2) - 1];
        }
    }

    vec[vec.size() - 1] = 0;

    for(int i = log2(vec.size()) - 1; i >= 0; i--) {
        int step = 1 << (i + 1);
        for(int j = 0; j < vec.size(); j += step) {
            auto temp = vec[j + step - 1];
            vec[j + step - 1] += vec[j + (step / 2) - 1];
            vec[j + (step/2) - 1] = temp;
        }
    }
}

int main() {

    std::vector<int> myVector = {1, 2, 3, 4, 5, 6, 7, 8};

    for (auto& key : myVector) {
        std::cout << key << " ";
    }
    std::cout << "\n";

    blellochScan(myVector);

    for (auto& key : myVector) {
        std::cout << key << " ";
    }
    std::cout << "\n";

    return 0;
}