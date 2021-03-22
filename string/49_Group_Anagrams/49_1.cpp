#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string, int> m;
        std::unordered_map<std::string, int>::iterator it;
        int groupNum = 0;
        if(strs.empty())
            return res;
        if(strs.size() == 1){
            res.push_back(strs);
            return res;
        }
        for(int i = 0; i < strs.size();i++){
            std::vector<int> check(26, 0);
            std::string s;
            for(int j = 0; j < strs[i].size();j++){
                check[strs[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; j++){
                if(check[j])
                    s+= (check[j] + '0');
                s+='#';
            }
            it = m.find(s);
            if(it != m.end()){
                res[it->second].insert(res[it->second].end(), strs[i]);
                }
            else{
                m[s] = groupNum++;
                std::vector<std::string> group;
                group.push_back(strs[i]);
                res.insert(res.end(), group);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    std::string s;
    std::vector<std::string> strs;
    std::vector<std::vector<std::string>> res;
    std::cout << "Your Input: \nstrs = ";
    while(std::cin.peek() != '\n'){
            std::cin >> s;
            std::cout << s << " ";
            strs.push_back(s);
    }
    std::cout << std::endl << "Output:\n";
    res = sol.groupAnagrams(strs);
    for(int i = 0; i < res.size(); i++){
        std::cout << "Group " << i + 1 << ": ";
        for(int j = 0; j < res[i].size(); j++)
            std::cout << res[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}
