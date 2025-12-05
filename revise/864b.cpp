#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    vector<int> capPos(2);
    capPos[0]=-1;
    capPos[1]=n;
    cin>>s;
    for(int j = 0; j < s.size(); j++) {
            if(isupper(s[j])) {
                if(j==0)
                    {capPos[0]=0; 
                    continue;}//if starting letter is capital
                capPos.insert(capPos.end()-1,j);
               //store positions of uppercase letters
            }
    }int currMax=0, disCount=0;//no of distinct char in between two capital letters

    for(int j=0;j<capPos.size();j++){ //1 capPos to another capPos how many distinct letter present
        unordered_map<char,int> distinct{};
        for(int i=capPos[j]+1;i<capPos[j+1] && i<n;i++){
                if(distinct.find(s[i])==distinct.end()){disCount++;
                distinct.insert({s[i],i});
                }        
            }currMax=max(currMax,disCount);//currMax stores the max no. of distinct char
            disCount=0;
    }
    cout<<currMax<<endl;
}
