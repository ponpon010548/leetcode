#include <iostream>
#include <vector>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int l = 0, r = citations.size() - 1, mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(citations[mid] >= citations.size() - mid){
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return citations.size() - l;
    }
};


int main(int argc, char *argv[])
{
    int res;
    Solution sol;
    std::vector<int> citations;
    while(std::cin.peek() != '\n'){
        std::cin >> res;
        citations.push_back(res);
    }
    res = sol.hIndex(citations);
    std::cout << res << std::endl;
    return 0;
}
