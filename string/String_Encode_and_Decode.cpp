
/* 
 * Design an algorithm to encode a list of strings to a single string. 
 * The encoded string is then decoded back to the original list of strings.
 * Please implement encode and decode
 * 
 * Input: ["neet","code","love","you"]
 *
 * Output:["neet","code","love","you"]
 */

// Approach

// encode the input string with length and #
// # is to seperate string

// ex. "need","code","love","you" wiil be encoded as 
// 4#need4#code4#love3#you
// string length will more than on digit(ex. 10/11/12)
// make sure each charater will be decoded.
// pay attention to how to use to_string and stoi

class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        for(string s : strs){
            //cout << s;
            int num = s.size();
            ret += (to_string(num) + "#"+ s);
        }
        cout << ret;
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        string s_c = "";
        string s_n = "";
        for(int i = 0; i < s.size(); i++){
            s_n += s[i];
            if(s[i] == '#'){
                int cnt = stoi(s_n);
                s_n = "";
                cout << "cnt "<<cnt ;
                s_c = "";
                while(cnt--){
                    i++;
                    s_c += s[i];
                }
                ret.push_back(s_c);
            }
        }
        return ret;
    }
};
