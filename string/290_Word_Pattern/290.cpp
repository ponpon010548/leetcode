#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::unordered_map<std::string, char> m;
        std::unordered_map<std::string, char>::iterator mit;
        std::string::iterator it = pattern.begin();
        std::string split;
        bool check[26] = {false};
        int begin_pos = 0, end_pos = 0, count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ')
                count++;
        }
        if(count != pattern.size() - 1)
            return false;
        while(it != pattern.end() && end_pos != std::string::npos){
            end_pos = s.find(' ', begin_pos);
            if(end_pos != std::string::npos){
                split = s.substr(begin_pos, end_pos - begin_pos);
                begin_pos = ++end_pos;
                count++;
            }
            else{
                split = s.substr(begin_pos, s.size() - begin_pos + 1);   
            }    
            mit = m.find(split);
            if(mit != m.end()){
                if(mit -> second != *it)
                    return false;
            }
            else{
                if(check[*it - 'a'])
                    return false;
                m[split] = *it;
                check[*it - 'a'] = true;
            }
            it++;
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    bool res;
    std::string pattern, s;
    std::getline(std::cin, pattern);
    std::getline(std::cin, s);
    std::cout << "Your Input:\npattern = " << pattern << ", s = " << s << std::endl;
    res = sol.wordPattern(pattern, s);
    std::cout << "Output:\n" << res << std::endl;
    return 0;
}
