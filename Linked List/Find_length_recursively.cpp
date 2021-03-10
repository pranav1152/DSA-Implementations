/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/

int getCount(Node* head) {
	if (head == NULL)
		return 0;
	int pre = getCount(head->next);
	return pre + 1;
	//Code here

}