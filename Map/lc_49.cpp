/* we are given the vector of strings , we have return the vector string which become same after sorting */

#include<bits/stdc++.h>
using namespace std;



vector<vector<string>> anagrams(vector<string>&strs) {

    unordered_map<string,vector<string>>mp;
    for(auto str : strs) {
        string temp = str;
        sort(temp.begin(),temp.end());              // sort the current string
        mp[temp].push_back(str);                    // group the sorted keys
    }

    vector<vector<string>>ans;
    for(auto it : mp) {
        ans.push_back(it.second);
    }

    return ans;
}

int main() {
    int n;
    cout<<"Enter The Size of Vector : ";
    cin>>n;
    cin.ignore();                               // igonre the next buffer otherwise

    vector<string>strs(n);
    cout<<"Enter The Strings : ";
    for(int i=0;i<n;i++) {
        string str;
        getline(cin,str);                       // here one empty string will be added automatically
        strs.push_back(str);
    }

    vector<vector<string>> ans = anagrams(strs);
    cout<<endl;
    
    for(auto s1 : ans) {
        for(auto s2 : s1) {
            cout<<s2<<" ";
        }
        cout<<endl;
    }

    return 0;

}