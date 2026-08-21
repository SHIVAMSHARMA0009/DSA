/*  we are given the trie class -> implements the normal functions */

#include<bits/stdc++.h>
using namespace std;

class TrieNode{                                         // each TrieNode will have its character , map of its children & terminal value

    public:
    char ch;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;

    TrieNode(char ch) {
        this->ch = ch;
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* &root,string word) {

    if(word.length() == 0) {                   // base case (Final Step) : if string become zero -> then mark last TrieNode as terminal node
        root->isTerminal = true;
        return;
    }

    char ch = word[0];                                    // step  1 : take the first character of current string
    TrieNode* child;

    if(root->children.find(ch) != root->children.end()) {         // step 2 : if its mapping found -> move to its  children Trienode
        child = root->children[ch];
    }
    else{
        child = new TrieNode(ch);                    // if not then create new Trienode of character
        root->children[ch] = child;                  // map this TrieNode with the roots
    }

    insertWord(child,word.substr(1));            // step 3 : after insertion send the rest of string 

}


bool searchWord(TrieNode* root,string word) {

    if(word.length() == 0) return root->isTerminal;            // if string become empty -> then return its terminal value

    char ch = word[0];                                            // step  1 : take the first character of current string
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()) {        // step 2 : if its mapping found -> move to its  children Trienode
        child = root->children[ch];                                  
    }
    else{                                        // otherwise immediately return false
        return false;
    }

    return searchWord(child,word.substr(1));                // step 3 : send the rest of string 
}

bool searchPrefix(TrieNode* root,string prefix) {

    if(prefix.length() == 0) return true;                        // if string becomes empty means prefix has been traced -> return true value

    char ch = prefix[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()) {
        child = root->children[ch];
    }
    else{
        return false;
    }

    return searchPrefix(child,prefix.substr(1));
}

void removeWord(TrieNode* &root,string word) {

    if(word.length() == 0) {           // just mark the terminal value of word as false
        root->isTerminal = false;
        return;
    }     

    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()) {
        child = root->children[ch];
    }

    removeWord(child,word.substr(1));

}

class Trie {
public:

    TrieNode* root;

    Trie() {
        root = new TrieNode('-');
    }
    
    void insert(string word) {
        insertWord(root,word);
    }

    void remove(string word) {
        removeWord(root,word);
    }
    
    bool search(string word) {
        return searchWord(root,word);
    }
    
    bool startsWith(string prefix) {
        return searchPrefix(root,prefix);
    }

};

int main() {

    Trie tr;

    tr.insert("cartoon");
    tr.insert("cart");
    tr.insert("care");
    tr.insert("car");
    tr.insert("cricket");

    cout<<"Does Exist : "<<tr.search("cart")<<endl;
    cout<<"Does Exist : "<<tr.search("cricket")<<endl;
    cout<<"Does Exist : "<<tr.search("campus")<<endl;
    cout<<"Does Exist : "<<tr.search("care")<<endl;
    cout<<"Does Exist : "<<tr.search("camera")<<endl<<endl;

    cout<<"Is prefix : "<<tr.startsWith("car")<<endl;
    cout<<"Is prefix : "<<tr.startsWith("cart")<<endl;
    cout<<"Is prefix : "<<tr.startsWith("carm")<<endl<<endl;
    tr.remove("care");

    cout<<"Does Exist : "<<tr.search("care")<<endl;

    return 0;

}