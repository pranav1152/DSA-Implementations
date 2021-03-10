/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/

Node* insertRec(Node* head, int i, int data) {
	if (head == NULL)
		return;
	if (i == 0) {
		Node* newNode = new Node*(data);
		newNode -> next = head;
		head = newNode;
		return head;
	}
	head->next = insertRec(head->next, i - 1, data);
	return head;
}