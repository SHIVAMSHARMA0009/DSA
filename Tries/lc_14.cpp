/*  given vector of strings -> give the longest common prefix */

#include<bits/stdc++.h>
using namespace std;

class TrieNode{                                         // each TrieNode will have its character , map of its children & terminal value

    public:
    char ch;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;
    int childCount;

    TrieNode(char ch) {
        this->ch = ch;
        this->isTerminal = false;
        this->childCount = 0;
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
        root->childCount++;                      // calculate its child count
    }

    insertWord(child,word.substr(1));            // step 3 : after insertion send the rest of string 

}

string findLCP(TrieNode* root,string word) {

    string ans = "";

    if(root->isTerminal) return ans;      // IMP : Most Common Mistake

    for(int i=0;i<word.length();i++) {
        
        char ch = word[i];
        if(root->childCount == 1) {     // if there is only one child one current node -> then add the character to ans
            ans.push_back(ch);
            root = root->children[ch];   // move the root to its child
        }
        else{
            break;      // if child count is greater than 2
        }

        if(root->isTerminal) break;     // suppose reached the terminal node

    }

    return ans;

}

int main() {

    int n;
    cout<<"Enter Size of Array : ";
    cin>>n;

    vector<string>strs(n);
    cout<<"Enter Strings : ";
    for(int i=0;i<n;i++) {
        cin >> strs[i];
    }

    TrieNode* root = new TrieNode('-');
    for(int i=0;i<n;i++) {
        insertWord(root,strs[i]);
    }

    string ans = findLCP(root,strs[0]);
    cout<<"The LCP : "<<ans<<endl;

    return 0;
}