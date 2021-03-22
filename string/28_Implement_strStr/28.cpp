#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t s_len = haystack.size(), n_len = needle.size();
        int res = -1, count = 0;
        if(needle == "")
            return 0;
        for(int i = s_len - 1; i >= 0; --i){
            if(haystack[i] == needle[n_len - 1 - count])
                count++;
            else{
                i+= count;  //reset position
                count = 0;
            }
            if(count == n_len){
                res = i;
                i += n_len - 1; //reset position
                count = 0;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    string haystack, needle;
    int res;
    Solution sol;
    getline(cin, haystack);
    getline(cin, needle);
    res = sol.strStr(haystack, needle);
    cout << "Your input:\n" << haystack << "\n" << needle << endl;
    cout << "Output: \n" << res << endl;
    return 0;
}
