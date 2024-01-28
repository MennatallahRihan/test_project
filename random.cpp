#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <bits/stdc++.h>
int main()
{

    std::random_device rd;
    std::mt19937 engine{rd()};
    std::uniform_int_distribution<int> distrib{1, 250};

    std::vector<int> numbers(100000);
    auto gen = [&distrib, &engine]()
    {
        return distrib(engine);
    };
    std::generate(numbers.begin(), numbers.end(), gen);

    auto start = std::chrono::high_resolution_clock::now();
    auto it = std::find(numbers.begin(), numbers.end(), 64);
    if (it != numbers.end())
    {
        std::cout << "Number found at index " << it - numbers.begin() << std::endl;
    }
    else
    {
        std::cout << "Number not found" << std::endl;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << duration.count() << " microseconds" << std::endl;

    std::unordered_set<int> nums;
    
    for (int i = 0; i < 100000; i++)
    {
        nums.insert(gen());
    }
    start = std::chrono::high_resolution_clock::now();
    if ( nums.find(64)== nums.end())
    {
        std::cout<< "number not found" << std::endl;

    }
    else {
        std::cout<< "number found" << std::endl;
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << duration.count() << " microseconds: Hashset" << std::endl;
    return 0;
}
