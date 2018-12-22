#include <iostream>

using namespace std;

// https://dunjudge.me/analysis/problems/500/
int main(){
	int n; long long int wi, runningTotal = 0, record = 0;
	// simply update the running total... this problem is a giveaway...
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> wi;
		if (wi < 0) {
			// bad potato, stop harvesting and update record.
			if(runningTotal > record) record = runningTotal;
			runningTotal = 0;
		}
		else {
			runningTotal += wi;
		}
	}
	if(runningTotal > record) record = runningTotal;
	cout << record << endl;
	return 0;
}
