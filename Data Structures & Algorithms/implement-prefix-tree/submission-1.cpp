class PrefixTree {
public:
    unordered_map<string, bool> mp;

    PrefixTree() {
        
    }
    
    void insert(string word) {
        string help {word[0]};
        int i=1;
        while(help.size() < word.size())
        {
            if(!mp.contains(help))mp[help] = false;
            help+= word[i];
            i++;
        }
        mp[word] = true;
    }
    
    bool search(string word) {
        if(mp.contains(word))
        {
            return mp[word];
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        if(mp.contains(prefix))return true;
        return false;
    }
};
