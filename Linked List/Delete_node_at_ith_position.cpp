/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/

Node* deletenode(Node* root, int i) {
	Node* temp = root;
	if (i == 0) {
		root = root->next;
		return root;
	}
	for (int j = 0; j < i - 1 && temp != NULL; i++) {
		temp = temp->next;
	}
	if (temp != NULL) {
		Node* a = temp->next;
		temp ->next = temp->next->next;
		delete a;
		return root;
	}
}