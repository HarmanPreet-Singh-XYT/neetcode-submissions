class TreeNode{
    public:
    int key;
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int key,int val):key(key),val(val),left(nullptr),right(nullptr){};
};
class TreeMap {
    TreeNode* root;
    void inorderTrans(TreeNode* node, vector<int>& arr){
        if(!node){
            return;
        }
        inorderTrans(node->left,arr);
        arr.push_back(node->key);
        inorderTrans(node->right,arr);
    }
    TreeNode* insertHelper(TreeNode* node,int key,int val){
        if(!node){
            return new TreeNode(key,val);
        }
        if(node->key > key){
            node->left = insertHelper(node->left,key,val);
        }else if(node->key < key){
            node->right = insertHelper(node->right,key,val);
        }else{
            node->key = key;
            node->val = val;
        }
        return node;
    }
    TreeNode* getHelper(TreeNode* node, int key) {
        if (!node) return nullptr;
        if (key < node->key) return getHelper(node->left, key);
        if (key > node->key) return getHelper(node->right, key);
        return node;
    }

    TreeNode* returnMinimum(TreeNode* node){
        TreeNode* curr = node;
        while(curr && curr->left){
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* removeHelper(TreeNode* node,int key){
        if(!node){
            return node;
        }
        if(node->key > key){
            node->left = removeHelper(node->left,key);
        }else if(node->key < key){
            node->right = removeHelper(node->right,key);
        }else{
            if(!node->left){
                return node->right;
            }else if(!node->right){
                return node->left;
            }else{
                TreeNode* minNode = returnMinimum(node->right);
                node->val = minNode->val;
                node->key = minNode->key;
                node->right = removeHelper(node->right,minNode->key);
            }
        }
        return node;
    }
public:
    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        root = insertHelper(root,key,val);
    }

    int get(int key) {
        TreeNode* curr = root;
        TreeNode* node = getHelper(curr,key);
        if(!node){
            return -1;
        }
        return node->val;
    }

    int getMin() {
        if (!root) return -1;
        TreeNode* curr = root;
        while(curr && curr->left){
            curr = curr->left;
        }
        return curr->val;
    }

    int getMax() {
        if (!root) return -1;
        TreeNode* curr = root;
        while(curr && curr->right){
            curr = curr->right;
        }
        return curr->val;
    }

    void remove(int key) {
        root = removeHelper(root,key);
    }

    std::vector<int> getInorderKeys() {
        vector<int> arr;
        inorderTrans(root,arr);
        return arr;
    }
};
