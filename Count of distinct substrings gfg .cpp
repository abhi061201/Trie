//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends

#include<bits/stdc++.h>
struct Trienode{
    Trienode* links[26];
    bool isleaf;
    Trienode(){
        for(int i=0 ; i<26 ;i++)links[i]=NULL;
        isleaf= false;
    }
    
};
class Trie{
    Trienode* root;
    int count;
    public:
    Trie(){
        root= new Trienode();
        count=0;
    }
    void insert(string word){
        Trienode* temp= root;
        for(auto it : word){
            if(!temp->links[it-'a']){
                count++;
                temp->links[it-'a']=new Trienode();
            }
            temp= temp->links[it-'a'];
        }
        temp->isleaf=true;
    }
    int getcount(){
        return count;
    }
    void insertword(string word){
        int n= word.size();
        for(int i=0 ; i<word.size(); i++){
            string temp= word.substr(i, n-i);
            insert(temp);
        }
    }
};
/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    Trie t;
    t.insertword(s);
    return t.getcount()+1;
}
