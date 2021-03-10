/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/

// Ascending order

bool is_sorted(int a[], int size) {
	if (size == 0 || size == 1) {
		return true;
	}
	if (a[0] > a[1])
		return false;
	bool isSmallerOutput = is_sorted(a + 1, size - 1);
	return isSmallerOutput;
}