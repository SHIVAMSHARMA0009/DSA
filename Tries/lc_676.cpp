/* we have design the design the magic dictionary from the string vector & search any word -> condition : only one character mismatch is allowed */

#include<bits/stdc++.h>
using namespace std;

class TrieNode{                // node data of trie
    public:
    char ch;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;

    TrieNode(char ch) {
        this->ch = ch;
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* &root,string word) {    // dictionary creation

    if(word.size() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()) {
        child = root->children[ch];
    }
    else{
        child = new TrieNode(ch);
        root->children[ch] = child;
    }

    insertWord(child,word.substr(1));

}

bool searchWord(TrieNode* root,string &word,int i,bool mismatch) {
    
    if(i == word.size()) return mismatch && root->isTerminal;

    auto ch = word[i];

    if(root->children.find(ch) != root->children.end()) {
        if(searchWord(root->children[ch],word,i+1,mismatch)) return true;         // move to child node if current character is matched
    }

    if(mismatch == false) {                 // try exactly one mismatch
        for(auto itr : root->children) {
            if(ch == itr.first) continue;
            if(searchWord(itr.second,word,i+1,true)) return true;
        }
    }

    return false;
}

class MagicDictionary {
public:

    TrieNode* root;

    MagicDictionary() {
        root = new TrieNode('-');
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &word : dictionary) {
            insertWord(root,word);
        }
    }
    
    bool search(string Word) {
       return searchWord(root,Word,0,false);
    }
};


int main() {

    MagicDictionary md;

    int n;
    cout<<"Enter Size : ";
    cin >> n;

    vector<string>dict(n);
    cout<<"Enter String : ";
    for(int i=0;i<n;i++) {
        cin>>dict[i];
    }

    md.buildDict(dict);
    
    cout<<"Is Present : "<<md.search("hello")<<endl;
    cout<<"Is Present : "<<md.search("hhllo")<<endl;
    cout<<"Is Present : "<<md.search("hell")<<endl;
    cout<<"Is Present : "<<md.search("leetcoded")<<endl;

    return 0;

}