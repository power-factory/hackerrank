#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::vector<int> vec;
    int i;
    std::cin >> i;
    for (int k = 0; k < i; ++k)
    {
        int tmp{};
        std::cin >> tmp;
        vec.push_back(tmp);
    }
    std::sort(vec.begin(), vec.end());
    for (int k = 0; k < vec.size(); ++k)
    {
        std::cout << vec[k] << " ";
    }
    return 0;
}
