/*
Link: https://leetcode.com/problems/maximum-frequency-stack/

Hashing Approach:
Maintaing the maxx frequency and pushing the value to the stack mapped to a particular frequency and return its top
and we have to keep track of the frequency of a given number so when we encounter it again we know in which stack the new value should be pushed
*/

class FreqStack {
public:
    unordered_map<int,int> hash;
    vector<stack<int>> stuff;
    FreqStack() {
        
    }
    
    void push(int val) {
        int len = hash[val];
        if(len>=stuff.size())
        {
            stuff.resize(len+1);
        }
        stuff[len].push(val);
        hash[val]++;
    }
    
    int pop() {
        int len = stuff.size()-1;
        while(len>0 && stuff[len].size()==0)
            len--;
        int ans = stuff[len].top();
        hash[ans]--;
        stuff[len].pop();
        return ans;
    }
};
