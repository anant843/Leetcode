class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int i=0,j=0, mini=INT_MAX,index=0;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int count=t.length();
        while(j<s.length()){
    if(mp[s[j]]>0){
count--;
   }
   mp[s[j]]--;
   while(count==0){
    if(j-i+1<mini){
        mini=j-i+1;
        index=i;
    }
    mp[s[i]]++;
    if(mp[s[i]]>0){
        count++;
    }
    i++;
   }
   j++;
        }
        if(mini==INT_MAX) return"";
        return s.substr(index,mini);
    }
};