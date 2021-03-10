/* Author : 	Pranav Deshmukh
            	PICT,Pune
   Purpose: 	Understanding GCD.
   Date:   		16/09/2020
   Stay Focused!
*/
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

