TC- O(word.size())
sc-O(26*words)

struct Node{
        Node* links[26];
        bool flag= false;
        bool containKey(char ch){
            return links[ch-'a']!=NULL;
        }
    void put(char ch, Node* node){
        links[ch-'a']= node;
    }
    Node * get(char ch){
        return links[ch-'a'];
    }
    void setend(){
        flag=true;
    }
     bool isEND(){
         return flag;
     }   
        
    };
class Trie {
    private : Node * root;
public:
    
    
    Trie() {
        
        root= new Node();
    }
    
    void insert(string word) {
        // we start with root
        Node * node= root;
       for(int i=0 ; i<word.length(); i++){
           if(!node->containKey(word[i])){
               // insert a word into trie
               node->put(word[i], new Node());
           }
           // moves to the reference trie
           
           node=node->get(word[i]);
           
       }
        node->setend();
        
    }
    
    bool search(string word) {
        
        Node* node= root;
        for(int i=0 ; i<word.length(); i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEND();
        
        
        
    }
    
    bool startsWith(string word) {
        Node* node= root;
        for(int i=0 ; i<word.length(); i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
