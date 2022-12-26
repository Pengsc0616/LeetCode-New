class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> dict;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        wordSet.insert(beginWord);
        for(const auto & word: wordSet) {
            int size_w = word.size();
            // string temp = word;
            for(int i=0; i<size_w; i++) {
                string temp = word;
                for(auto ch='a'; ch<='z'; ch++) {
                    temp[i] = ch;
                    if(temp == word) continue;
                    if(wordSet.count(temp)) {
                        dict[word].push_back(temp);
                        // cout << word << ": push in [" << temp << "]\n";
                    }
                }
            }
        }
        for(const auto & word: dict[beginWord]) cout << word << " ";
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int ans = 0;
        while(!q.empty()) {
            int size_q = q.size();
            ans ++;
            cout << ans;
            while(size_q--) {
                string head = q.front();
                q.pop();
                if(head == endWord) return ans;
                for(const auto & word: dict[head]) {
                    if(visited.count(word)) continue;
                    visited.insert(word);
                    q.push(word);
                }
            }
        }
        return 0;
    }
};




// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_map<string, vector<string>> dict;
//         unordered_set<string> Set(wordList.begin(), wordList.end());
//         Set.insert(beginWord);
//         for(const auto & word: wordList) {
//             int size_w = word.size();
//             for(int i=0; i<size_w; i++) {
//                 string word1 = word.substr(0, i);
//                 string word2 = word.substr(i+1, size_w-i-1);
//                 for(int c=0; c<26; c++) {
//                     char cc = c+'a';
//                     string temp = word1 + cc + word2;
//                     if(Set.count(temp)) dict[word].push_back(temp);
//                 }
//             }
//         }
//         EndWord = endWord;
//         queue<string> q;
//         q.push(beginWord);
//         while(!q.empty()) {
//             int size_q = q.size();
//             while(size_q) {
//                 string word = q.top();
//                 q.pop();
//             }
//         }
//     }
//     unordered_map<string, int> memory;
//     string EndWord;
//     int dfs(string & beginWord, unordered_map<string, vector<string>> & dict, int ans){
//         if(memory.find(beginWord) != memory.end()) return memory[beginWord];
//         ans ++;
//         if(beginWord == EndWord) {

//         }
//         int ret = 10000;
//         for(auto & nextWord: dict[beginWord]) {
//             ret = min(ret, dfs(nextWord, dict, ans));
//         }
//         memory[beginWord] = ret;
//         return ret;
//     }
// private:
//     int ansLen = 10000;
// };









