#include <cstdint>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> res(rowIndex + 1, 1);
        for(int i = 1; i <= rowIndex; i++){
            for(int j = i - 1; j > 0; j--)
                res[j] += res[j - 1];
        } 
        return res;
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> v;
    Solution sol;
    int rowIndex;
    std::cin >> rowIndex;
    v = sol.getRow(rowIndex);
    for(int i = 0; i <= rowIndex; i++)
        std::cout << v[i] << " ";
    std::cout <<'\n';
    return 0;
}
