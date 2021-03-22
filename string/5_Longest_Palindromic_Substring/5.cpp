#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        //Return the longest palindrome of s
        string longestPalindrome(string s){
            if(s=="")   //if s is NULL return
                return s;
            if(check(s)) //if s is a palidrome, then return s
                return s;
            int s_length = s.size();
            int odd, even, start, end, MAX = 0;
            /** odd: Start with a character
                even: Start with two character
                start: Index. The beginning of the longest palidrome in s
                end: Index. The end of the longest palidrome in s
                MAX: Record the longest palidrome length
            */ 
            for(int i = 0; i < s_length; i++){
                odd = getLength(s, i, i);
                even = getLength(s, i, i + 1);
                //if one of the which greater the MAX, then update
                if (odd > MAX || even > MAX){ 
                    if(odd > even){
                        MAX = odd;
                        start = i - odd / 2;
                        end = i + odd / 2;
                    }
                    else{
                        MAX = even;
                        start = i - even / 2 + 1;
                        end = i + even / 2 ;
                    }
                }
            }
            return s.substr(start, end - start + 1);
        }
    private:
        /** Find the longest palindrame whose center is i (or i and i+1)
            string s: input string to find longest palindrame
            left: Index. The index for left part of string
            right: Index. The index for right part of string
        */
        int getLength(const string s, const int left, const int right){
            int l = left, r = right;
             //chech whether it is out of bound and is valid palindrame
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                //if s[l] == s.at[r], we expand the range.
                --l;
                ++r;
            }
            return r - l - 1; //We expand the range of palindrame when
                              //while loop is terminal, so we correct
                              //the range before return
        }
        //check the string is a palindrame or not.
        bool check(const string s){
            size_t s_length = s.size();
            int i = 0;
            while(i < s_length / 2){
                if(s[i]!=s[s_length - 1 - i])
                    return false;
                ++i;
            }
            return true;
        }
};

int main(int argc, char *argv[])
{
    string s;
    Solution sol;
    getline(cin, s);
    cout << "Your input: " << s << endl;
    s = sol.longestPalindrome(s);
    cout << "Output: " << s << endl;
    return 0;
}
