class Trie {
public:
    Trie() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode * node = root;
        for(const auto w: word) 
        {
            if(node->next[w-'a'] == NULL) node->next[w-'a'] = new TreeNode();
            node = node->next[w-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TreeNode * node = root;
        for(const auto w: word)
        {
            if(node->next[w-'a'] == NULL) return false;
            node = node->next[w-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TreeNode * node = root;
        for(const auto p: prefix)
        {
            if(node->next[p-'a'] == NULL) return false;
            node = node->next[p-'a'];
        }
        return true;
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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */