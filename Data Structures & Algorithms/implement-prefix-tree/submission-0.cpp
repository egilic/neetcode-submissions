class PrefixTree 
{
public:
    bool isWord;
    unordered_map<char, PrefixTree*> mp;

    PrefixTree() 
    {
        isWord = false;
    }
    
    void insert(string word) 
    {
        unordered_map<char, PrefixTree*>* cMap = &mp; 
        for (int i = 0; i < word.size(); ++i)
        {
            if (cMap->find(word[i]) == cMap->end())
            {
                // No entry for this letter; create an entry before continuing
                (*cMap)[word[i]] = new PrefixTree();
            }

            // Use the last char as a sentinel to signal that the word is done
            if (i == word.size() - 1) { (*cMap)[word[i]]->isWord = true; }

            // Update cMap to be the next char's map
            cMap = &(*cMap)[word[i]]->mp;
        }

    }
    
    bool search(string word) 
    {
        unordered_map<char, PrefixTree*>* cMap = &mp;
        for (int i = 0; i < word.size(); ++i)
        {
            // No entry for this letter
            if (cMap->find(word[i]) == cMap->end()) { return false; }

            if (i == word.size() - 1) { return (*cMap)[word[i]]->isWord == true; }

            // Update cMap
            cMap = &(*cMap)[word[i]]->mp;
        }
        return false;
    }
    
    bool startsWith(string prefix) 
    {
        unordered_map<char, PrefixTree*>* cMap = &mp;
        for (int i = 0; i < prefix.size(); ++i)
        {
            // No entry for this letter
            if (cMap->find(prefix[i]) == cMap->end()) { return false; }

            // Update cMap
            cMap = &(*cMap)[prefix[i]]->mp;
        }
        return true;
    }
};
