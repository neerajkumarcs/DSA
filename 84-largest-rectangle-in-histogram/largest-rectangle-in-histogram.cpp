class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // approach
        // step 1-> find next smallest index and previous smallest index
        //step2 -> find maximun area for each index area =heihgt* width
        // widht=nsi[val]-psi[val]-1
         
        // step finding next smallest element index 
        int n=heights.size();   
        vector<int> nsi(n);
        stack<int> ni;
        nsi[n-1]=n;
        ni.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(ni.size()>0 && heights[ni.top()]>=heights[i]) ni.pop();
            if(ni.size()==0) nsi[i]=n;
            else {
                nsi[i]=ni.top();
            }
            ni.push(i);
        }
        // finding next smallest element index  
        vector<int> psi(n);
        stack<int> pi;
        psi[0]=-1;
        pi.push(0);
        for(int i=1; i<n; i++){
            while(pi.size()>0 && heights[pi.top()]>=heights[i]) pi.pop();
            if(pi.size()==0) psi[i]=-1;
            else {
                psi[i]=pi.top();
            }
            pi.push(i);
        } 
        // now find the area 
        int maxarea=0;
        for(int i=0; i<n; i++){
            int height=heights[i];
            int width=nsi[i]-psi[i]-1;
            int area=height*width;
            maxarea=max(maxarea, area);
        } 
        return maxarea;

    }
};