class Solution {
public: TreeNode* first=NULL;
    void mapping(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parent ){
        if(root==NULL) return ;
        if(root->left) parent[root->left]=root; // key child with parent 
        if(root->right) parent[root->right]=root;// key child with parent 
        mapping(root->left, parent);
        mapping(root->right, parent);
    }
    void find(TreeNode* root, int start){
        if(root==NULL) return ;
        if(root->val==start) first=root;
        find(root->left, start);
        find (root->right, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root==nullptr) return 0;
        // step 1-> find start node in tree
         find(root, start);
        // step->2 mark child parent mapping using hashmap
        unordered_map<TreeNode*, TreeNode*> parent;
        mapping(root, parent);
        // step-> create an unorederd set to check isvisited
        unordered_set<TreeNode*> s;
        s.insert(first);
        queue<pair<TreeNode*, int>> q;
        q.push({first,0});
        int maxlvl=0;
    // step ->3 do bfs
    while(q.size()>0){
        pair<TreeNode*, int> p=q.front();
        q.pop();
        int level=p.second;
        maxlvl=max(maxlvl, level);
        TreeNode* temp=p.first;
        // check if left exist
        if(temp->left){
            if(s.find(temp->left)==s.end()){
                q.push({temp->left,level+1});
                s.insert(temp->left);
            }
        }
        // check if right exist
        if(temp->right){
            if(s.find(temp->right)==s.end()){
                q.push({temp->right,level+1});
                s.insert(temp->right);
            }
        }
    // check if parent exist from child parent map 
        if(parent.find(temp)!=parent.end()){
            if(s.find(parent[temp])==s.end()){
                q.push({parent[temp],level+1});
                s.insert(parent[temp]);
            }
        }
    }
    return maxlvl;
    }
};