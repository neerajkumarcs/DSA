class Solution {
public:
    int calPoints(vector<string>& operations) {
    int n=operations.size();
    stack<int> s;
    for(int i=0; i<n; i++){
        if(operations[i]!="C" && operations[i]!="D" && operations[i]!="+"){
            s.push(stoi(operations[i]));
        }
        else if(operations[i]=="C") s.pop();
        else if(operations[i]=="D"){
            int a=s.top();
            s.push(a * 2);
        }
        else {
             int a=s.top();
            s.pop();
            int b=s.top();
            s.push(a);
            s.push(a+b);
        }
    }   
    int sum=0;
    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }
    return sum;
    }
};