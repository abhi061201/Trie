struct Trienode{
    Trienode* links[26];
    bool isleaf;
    Trienode(){
        for(int i=0; i<26;i++)links[i]= NULL;
        isleaf=0;
    }
    
};
class Trie{
    Trienode* root ;
    public: 
    Trie(){
        root = new Trienode();
        
    }
    void insert(string word){
        Trienode * temp= root;
        for(auto it: word){
            if(!temp->links[it-'a']){
                temp->links[it-'a']= new Trienode();
            }
            temp= temp->links[it-'a'];
        }
        temp->isleaf= true;
    }
    bool check(string &word){
        Trienode* temp= root;
        for(auto it : word){
           if(!temp->links[it-'a'])return false;
            temp= temp->links[it-'a'];
            if(!temp->isleaf)return false;
        }
        return temp->isleaf;
    }
};

string completeString(int n, vector<string> &a){
    Trie t;
    for(auto it: a)t.insert(it);
    string longest="";
    for(auto word: a){
        if(t.check(word)){
            if(word.length() > longest.length()) {
                longest = word; 
            }
            else if(word.length() == longest.length() && word < longest) {
                longest = word; 
            }
        }
    }
    return longest==""?"None":longest;
}
