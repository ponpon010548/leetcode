#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res;
        if(strs.empty())
            return res;
        if(strs.size() == 1){
            res.push_back(strs);
            return res;
        }
        std::vector<std::string> emptyGroup;
        for(int i = 0; i < strs.size(); i++){        
            if(strs[i] == ""){
                emptyGroup.insert(emptyGroup.end(),"");
            }
        }
        if(!emptyGroup.empty())
            res.insert(res.end(), emptyGroup);
        for(int i = 0; i < strs.size(); i++){
            std::vector<std::string> group;
            if(strs[i] != ""){
                for(int j = i + 1; j < strs.size(); j++){
                    if(strs[j].size()== strs[i].size()){
                        int count[26] = {0};
                        for(int k = 0; k < strs[i].size(); k++){
                            count[strs[i][k] - 'a']++;
                            count[strs[j][k] - 'a']--;
                        }
                        int valid = 0;
                        for(; valid < 26; valid++){
                            if(count[valid] != 0)
                                break;
                        }
                        if(valid == 26){
                            group.insert(group.end(), strs[j]);
                            strs[j] = "";
                        }
                    }
                }
                group.insert(group.end(),strs[i]);
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
