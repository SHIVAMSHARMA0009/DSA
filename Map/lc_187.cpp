/* we are given the DNA in form string sequnce -> return the substring of exactly 10 size but should be repeated more than once in the DNA */



#include<bits/stdc++.h>
using namespace std;

/* appraoch 1 : sliding window + map */
vector<string> findDnaSeq(string s) {

    unordered_map<string,int>seqCount;
    vector<string>ans;

    if(s.size() < 10) return {};

    for(int i=0;i<=s.size()-10;i++) {
        auto  currSubStr = s.substr(i,10);
        seqCount[currSubStr]++;
    }

    for(auto it : seqCount) {
        if(it.second > 1) {
            ans.push_back(it.first);
        }
    }

    return ans;

}

/* Approach 2 : hash rolling + bit-manipulation */

int code(char c){
    switch(c) {
        case 'A' : return 0;   //00
        case 'C' : return 1;   //01
        case 'G' : return 2;   //10
        case 'T' : return 3;   //11
        default  : return 3;
    }
}

vector<string> findDnaSeq1(string s) {
    unordered_map<int,int>seqCount;
    vector<string>ans;

    if(s.size() < 10) return {};

    const int MASK = 0xFFFFF;  // F -> 1111 (hexadecimal bit representation )  ->  000000000...0001111...1111 -> total 20 ones bcz of 10 size string and one character take 2 bits

    int x = 0;   // enoded number for current window

    for(int i=0;i<10;i++) {
        x = (x << 2) | code(s[i]);
    }

    seqCount[x]++;

    for(int i=10;i<s.size();i++) {
        x = ((x << 2) & MASK) | code(s[i]);      // doing left shift to remove 2-bit from left & adding 2-bits of current character in right side
        if(seqCount.find(x) != seqCount.end()){
            if(seqCount[x] == 1) {
                ans.push_back(s.substr(i-10+1,10));
            }
        }
        seqCount[x]++;
    }

    return ans;

}

int main() {

    string s;
    cout<<"Enter String  : ";
    cin >> s;

    vector<string>seq = findDnaSeq1(s);
    cout<<"The Sequence : ";
    for(auto st : seq){
        cout<<st<<" ";
    }

    return 0;

}