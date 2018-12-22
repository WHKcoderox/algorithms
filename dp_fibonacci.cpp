#include <iostream>
#include <string.h>

using namespace std;

// the memo table stores calculated answers. fit to requirements.
long long int memo[5000];

int nthFibo(int n){ // recursive
	cout << memo[n] << endl;
	if (memo[n] == -1) {
		// only compute if not already known.
		memo[n] = nthFibo(n-1) + nthFibo(n-2);
	}
	return memo[n]; // return answer regardless.
}

int main(){
	// a basic DP problem of finding the nth fibonacci number
	memset(memo, -1, sizeof(memo));
	
	// set base case values
	memo[0] = 1; memo[1] = 1;
	int n; long long int result;
	cin >> n; result = nthFibo(n);
	cout << result << endl;
	return 0;
}
