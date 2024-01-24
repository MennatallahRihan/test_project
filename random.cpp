#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>
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
    
    return 0;
}
