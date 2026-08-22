/* Design a data structure that supports adding new words and finding if a string matches any previously added string. */


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

void insertNode(TrieNode* &root,string word) {    // trie creation

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

    insertNode(child,word.substr(1));

}

bool searchNode(TrieNode* root,string word) {     // searching in trie

    if(word.length() == 0) return root->isTerminal;

    char ch = word[0];     // step 1 : take first character
    TrieNode* child;

    if(ch != '.') {     // step 2 : if current character in not '.'
        if(root->children.find(ch) == root->children.end()) {   // if current character is not found 
            return false;
        }
        return searchNode(root->children[ch],word.substr(1));   // if foudn then search for next character of word
    }
    else{
        for(auto &p : root->children) {    // if  curren is dot
            if(searchNode(p.second,word.substr(1))) return true;    // try all the possible child attached to the dot
        }
        return false;   // otherwise return false
    }
}

class Trie{            // trie structure with methods
    public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('-');
    }

    void insertWord(string word) {
        insertNode(root,word);
    }

    bool searchWord(string word) {
        return searchNode(root,word);
    }
};


int main() {

    Trie tr;
    tr.insertWord("bad");
    tr.insertWord("dad");
    tr.insertWord("mad");

    cout<<"Is present : "<<tr.searchWord("pad")<<endl;
    cout<<"Is present : "<<tr.searchWord("bad")<<endl;
    cout<<"Is present : "<<tr.searchWord(".ad")<<endl;
    cout<<"Is present : "<<tr.searchWord("b..")<<endl;

    return 0;

}

