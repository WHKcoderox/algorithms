#include <iostream>

using namespace std;

// https://dunjudge.me/analysis/problems/68/

int lengths[5100]; // 5100 is maximum size
int sequence[5100];
bool visited[5100];

int lis(int end) { // recursively find lis
	if(!visited[end]){
		int e, newLis;
		for(e=0; e<end; e++){
			newLis = lis(e);
			if(sequence[e] < sequence[end]){
				newLis++;
				if(newLis > lengths[end]) lengths[end] = newLis;
			}
		}
		visited[end] = true;
	}
	return lengths[end];
}

int main(){
	int N, i, si, maxResult = 0;
	cin >> N;
	// set defaults
	for(i=0; i<N; i++){
		cin >> si;
		sequence[i] = si;
		lengths[i] = 1;
		visited[i] = false;
		if(lis(i) > maxResult) maxResult = lis(i);
	}
	cout << maxResult << endl;
	return 0;
} 
