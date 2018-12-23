#include <iostream>

using namespace std;

// Kadane's DP optimisation - find the min. sub arrays based on calculated sums.
signed long int sums[1000000];
signed int sequence[1000000];
signed int recordMin = 1001; // higher than the largest possible min-sum of 1000.

int minSum(int endPt){
	if(endPt > 0){
		// either combine previously occuring sum, or don't.
		signed int newSum = minSum(endPt-1) + sequence[endPt];
		if(newSum < sequence[endPt]){
			// found local minimum.
			sums[endPt] = newSum;
		}
		else sums[endPt] = sequence[endPt];
	}
	// update global minimum.
	if(sums[endPt] < recordMin) recordMin = sums[endPt];
	
	return sums[endPt];
}

int main() {
	int N, i;
	cin >> N;
	for(i=0; i<N; i++) cin >> sequence[i];
	
	sums[0] = sequence[0];
	minSum(N-1);
	cout << recordMin << endl;
	return 0;
}
