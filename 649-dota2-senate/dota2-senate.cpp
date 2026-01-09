class Solution {
public:
    string predictPartyVictory(string senate) {
      int n=senate.size();
    //   int count1=0,count2=0;
    //   for(int i=0; i<n; i++){
    //     if(senate[i]=='R') count1++;
    //     else count2++;
    //   }  
    //   if(count1==count2){
    //     if(senate[0]=='R') return "Radiant";
    //     else return "Dire";
    //   }
    //   if(count1>count2) return "Radiant";
    //   else return "Dire";
        queue<int> q;
        queue<int> r;
        queue<int> d;
        for(int i=0 ;i<n; i++){
            q.push(i);
            if(senate[i]=='R') r.push(i);
            else d.push(i);
        }
        while(q.size()>0){
            if(senate[q.front()]=='X') q.pop();
            else if(senate[q.front()]=='R'){
               if(d.size()==0) return "Radiant"; // check victory
               else { // take right of next D
               senate[d.front()]='X';
               d.pop();
               q.push(q.front());
               q.pop();
               r.push(r.front());
               r.pop();
               }
            }
            else {
               if(senate[q.front()]=='D'){
                if(r.size()==0) return "Dire"; // check victory
               else { // take right of next R
               senate[r.front()]='X';
               r.pop();
               q.push(q.front());
               q.pop();
               d.push(d.front());
               d.pop();
               }
            }
            }       
        }
        if(senate[q.front()=='R']) return "Radiant";
        else return "Dire";
    }
};