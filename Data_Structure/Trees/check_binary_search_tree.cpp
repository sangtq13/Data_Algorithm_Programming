/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    bool checkBSTUntil(Node*root, int min, int max) {
        if (!root) return true;
        if ((root->data < min) || (root->data > max)) return false;
        return checkBSTUntil(root->left, min, root->data-1) && checkBSTUntil(root->right, root->data+1, max);
    }    

	bool checkBST(Node* root) {
		int min = -1;
        int max = 1e4+1;
        
        return checkBSTUntil(root, min, max);
	}
