/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/
Node* insertNode(Node* head, int i, int data) {
	Node* newNode = new Node(data);
	int count = 0;
	Node* temp = head;

	if (i == 0) {
		newNode->next = head;
		head = newNode;
		return head;
	}
	while (temp != NULL && count < i - 1) {
		temp = temp->next;
		count++;
	}
	if (temp != NULL) {
		Node *a = temp->next;
		temp->next = newNode;
		newNode->next = a;
	}
	return head;
}