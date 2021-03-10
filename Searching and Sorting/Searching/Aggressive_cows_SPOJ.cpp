/* Author :     Pranav Deshmukh
                PICT,Pune
   Purpose:     SPOJ Question - https://www.spoj.com/problems/AGGRCOW/
   Date   :     02/07/2020.
   Stay Focused!
*/
#include<bits/stdc++.h>
using namespace std;

bool check(long long arr[] , long long mid, int c, int n) {
    int count = 1;
    long long lastpos = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[lastpos] >= mid) {
            lastpos = i;
            count++;
        }
    }
    if (count >= c)
        return true;
    else
        return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        long long ans = -1;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        long long start = 0;
        long long end = arr[n - 1];
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            if (check(arr, mid, c, n)) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        cout << ans << endl;
    }
}