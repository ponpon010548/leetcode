#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> res(rowIndex + 1);
        res[0] = res[rowIndex] = 1;
        for(int i = 1; i <= (rowIndex + 1) / 2; i++){
            int temp = (long)res[i - 1] * (rowIndex - i + 1) / i;
            res[i] = temp;
            res[rowIndex - i] = temp;
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
