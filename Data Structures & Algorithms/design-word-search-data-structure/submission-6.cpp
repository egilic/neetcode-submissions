class WordDictionary {
public:
    struct PrefixTrie {
        unordered_map<char, PrefixTrie*> mp_;
        bool is_word_ = false;
    };

    PrefixTrie* root;

    WordDictionary() {
        root = new PrefixTrie();
    }
    
    void addWord(string word) {
        PrefixTrie* trie = root;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (!trie->mp_.contains(c)) {
                trie->mp_[c] = new PrefixTrie();
            }
            trie = trie->mp_[c];
            
            if (i == word.length() - 1) {
                trie->is_word_ = true;
            }
        }
    }
    
    bool search(string word) {
        PrefixTrie* trie = root;
        return dfs(trie, word, 0);
    }

    bool dfs(PrefixTrie* trie, string word, int j) {
        for (int i = j; i < word.length(); i += 1) {
            char c = word[i];

            if (c == '.') {
                for (const auto [key, value] : trie->mp_) {
                    if (dfs(value, word, i + 1)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (trie->mp_.contains(c)) {
                    trie = trie->mp_[c];
                } else {
                    return false;
                }
            }
        }
        return trie->is_word_;
    }
};
