#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int len = citations.size();
        std::sort(citations.begin(), citations.end());
        int h = 0, p = 0;
        for(int i = 0; i < len; i++){
            if(citations[p] < h + 1)
                p = i;
            if(citations[i] > h && len - i >= citations[i])
                h = citations[i];
            else if(citations[i] > h && len - p > h){
                h++;
            }
        }
        return h;
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
