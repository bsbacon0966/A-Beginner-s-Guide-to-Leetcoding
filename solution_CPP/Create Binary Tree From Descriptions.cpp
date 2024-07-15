//when reading descriptions , we should create a new TreeNode at the same time
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> is_not_root;
        unordered_map<int,TreeNode*> node_list;
        for(auto node:descriptions){
            int parent = node[0];
            int child = node[1];
            bool isLeft = node[2];
            is_not_root.insert(child);
            if(node_list.find(node[0])==node_list.end()){
                node_list[parent] = new TreeNode(parent); 
            }
            if(node_list.find(child)==node_list.end()){ // we should create child's node to record that "the node is in the map"
                node_list[child] = new TreeNode(child); 
            }
            //key--------------------------------------------------
            if(isLeft){// let the node inside the map to link the child node which is also in the map
                node_list[parent]->left = node_list[child]; 
            }
            else{
                node_list[parent]->right = node_list[child];
            }
            //key--------------------------------------------------
        }
        for(auto i:descriptions){
            if(is_not_root.find(i[0])==is_not_root.end()){
                return node_list[i[0]];
            } 
        }
        return NULL;
    }
};