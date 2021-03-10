/* Author : Pranav Deshmukh
            PICT,Pune
   Stay Focused!
*/

int length(char s[]) {
	if (s[0] == '\0') {
		return 0;
	}
	int smallStringLength = length(s + 1);
	return 1 + smallStringLength;
}