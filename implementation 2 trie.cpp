#include <iostream>
using namespace std;
struct Trienode
{
    Trienode *links[26];
    int ew, cp;
    Trienode()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = NULL;
        }
        ew = 0;
        cp = 0;
    }
};
class Trie
{
    Trienode *root;

public:
    Trie()
    {
        root = new Trienode();
    }
    void insert(string word)
    {
        Trienode *temp = root;
        for (auto it : word)
        {
            if (temp->links[it - 'a'] == NULL)
            {
                temp->links[it - 'a'] = new Trienode();
            }
            temp = temp->links[it - 'a'];
            temp->cp++;
        }
        temp->ew++;
    }
    bool search(string word)
    {
        Trienode *temp = root;
        for (auto it : word)
        {
            if (!temp->links[it - 'a'])
                return NULL;
            temp = temp->links[it - 'a'];
        }
        return temp->ew;
    }
    int count_no_words(string word)
    {
        Trienode *temp = root;
        for (auto it : word)
        {
            if (!temp->links[it - 'a'])
                return 0;
            temp = temp->links[it - 'a'];
        }
        return temp->ew;
    }
    int count_no_of_words_starts_with(string word)
    {
        Trienode *temp = root;
        for (auto it : word)
        {
            if (!temp->links[it - 'a'])
                return 0;
            temp = temp->links[it - 'a'];
        }
        return temp->cp;
    }
    void delete_word(string word)
    {
        Trienode *temp = root;
        for (auto it : word)
        {
            if (!temp->links[it - 'a'])
            {
                cout << "this word does not exist in this trie\n";
                return;
            }
            temp = temp->links[it - 'a'];
            temp->cp--;
        }
        if (temp->ew == 0)
        {
            cout << "this word not exist\n";
        }
    }
};
int main()
{

    Trie t;
    t.insert("apple");
    t.insert("apple");
    t.insert("apps");
    t.insert("apps");
    cout << t.count_no_words("ran")<<endl;
    t.count_no_of_words_starts_with("aps");

    return 0;
}
