/* give the suggestions for give string or prefix */

#include<bits/stdc++.h>
using namespace std;

class TrieNode{

    public:
    char ch;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;

    TrieNode(char ch) {
        this->ch = ch;
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word) {

    if(word.length() == 0) {
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

void storesuggestions(TrieNode* root,string input,vector<string>&temp) {

    if(root->isTerminal) {
        temp.push_back(input);    // push the current complete string into the vector
    }

    for(auto i : root->children) {

        char ch = i.first;
        TrieNode* child = i.second;

        if(child != NULL) {

            input.push_back(ch);     // current child character ko add kro input

            storesuggestions(child,input,temp);    // aur next child node ko store kro

            input.pop_back();    // backtrack after we reach one complete string means terminal node so that we can visit other child also
        }

    }
}

vector<string> getSuggestion(TrieNode* root,string input) {

    // approach : tarvel till prefix -> include all the string down to prefix  -> merge to get ans 

    for(int i=0;i<input.size();i++) {
        char ch = input[i];
        root = root->children[ch];      // step 1 : move to end of prefix
    }

    vector<string>temp;
    storesuggestions(root,input,temp);   // step 2 : current input me sare niche wale child node add kro
    return temp;
}

int main() {

    int n;
    cout<<"Enter Size : ";
    cin>>n;

    vector<string>strs(n);
    cout<<"Enter String : ";
    for(int i=0;i<n;i++) {
        cin >> strs[i];
    }

    TrieNode* root = new TrieNode('-');
    for(int i=0;i<n;i++) {
        insertWord(root,strs[i]);
    }

    string input;
    cout<<"Enter Input String : ";
    cin >> input;
    cout<<endl;

    vector<string>ans = getSuggestion(root,input);
    cout<<"The Suggestions : "<<endl;
    for(auto str : ans) {
        cout<<str<<endl;
    }

    return 0;

}