/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/

BinaryTreeNode<int>* search(BinaryTreeNode<int>* root, int data) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == data) {
		return root;
	}
	if (root->data > data) {
		return search(root->left, data);
	}
	else {
		return search(root->right, data);
	}
}