class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> ss;
        unordered_map<char,int> tt;
        for(const auto & ch: t) tt[ch]++;
        int tt_size = tt.size();
        int match = 0; // we need to satisfy the count condition for "match" unique characters
        int i = 0;
        int ansLen = 100001;
        // string ans = "";
        int ans_l = -1;
        int ans_r = -1;
        for(int j=0; j<s.size(); j++) {
            int rightCh = s[j];
            if(tt.find(rightCh) == tt.end()) continue;
            ss[rightCh] ++;
            if(ss[rightCh] == tt[rightCh]) match++;
            while (match == tt_size) {
                if(ansLen > (j-i+1)) {
                    ans_l = i;
                    ans_r = j;
                    // ans = s.substr(i, (j-i+1));
                    ansLen = j-i+1;
                }
                int leftCh = s[i];
                i++;
                if(tt.find(leftCh) == tt.end()) continue;
                if(ss[leftCh] == tt[leftCh]) match--;
                ss[leftCh] --;
            }
        }
        return ans_l==-1?"":s.substr(ans_l, (ans_r-ans_l+1));;
    }
};