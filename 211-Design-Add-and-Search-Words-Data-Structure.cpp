class WordDictionary {
public:
    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode * node = root;
        for(const auto w: word) 
        {
            if(node->next[w-'a'] == NULL) node->next[w-'a'] = new TreeNode();
            node = node->next[w-'a'];
        }
        node->isEnd = true;
        if(word.size() > longest_word) longest_word = word.size();
    }
    
    bool search(string word) {
        if(records.count(word)) return true;
        if(longest_word < word.size()) return false;
        queue<TreeNode*> q;
        q.push(root);
        int index = 0;
        // while((!q.empty()) && (index<word.size()))
        while((!q.empty()) && (index<=word.size()))
        {
            int size = q.size();
            while(size--) 
            {
                TreeNode * node = q.front();
                q.pop();
                if(index == word.size()) {
                    if(node->isEnd) {
                        records.insert(word);
                        return true;
                    }
                    /* Can't just return false because there's other node in this level that hasn't been checked */
                    // else return false;
                    continue;
                }
                if(word[index] == '.') {
                    for(int i=0; i<26; i++) {
                        if(node->next[i] != NULL) {
                            // if((index == word.size()-1)&&(node->next[i]->isEnd)) return true;
                            q.push(node->next[i]);
                        }
                    }
                }
                else if(node->next[word[index]-'a'] != NULL) {
                    // if((index == word.size()-1)&&(node->next[word[index]-'a']->isEnd)) return true;
                    q.push(node->next[word[index]-'a']);
                }
            }
            index ++;
        }
        return false;
    }
private:
    class TreeNode {
    public:
        TreeNode() {
            for(int i=0; i<26; i++) next[i] = NULL;
            isEnd = false;
        }
        TreeNode * next[26];
        bool isEnd;
    };
    TreeNode * root;
    set<string> records; // Record matched word to avoid TLE
    int longest_word = 0; // https://leetcode.com/problems/design-add-and-search-words-data-structure/solutions/2622355/do-you-have-tle-add-this-one-thing-to-your-code/ 
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */