class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n=students.size();
        for(int i=0; i<n; i++){
            q.push(students[i]);
        }
        int i=0; // to traverse sanwitches stack
        int count=0;
        while(q.size()>0 && count!=q.size()){
            if(q.front()==sandwiches[i]){
                q.pop();
                i++;
                count=0;
            }
            else{
                int x=q.front();
                q.pop();
                q.push(x);
                count++;

            }
        }
        if(count>0){
            return count;
        }
        else {
            return 0;
        }
    }
};