#include <iostream>
#include <vector>

using namespace std;

// https://dunjudge.me/analysis/problems/204/

bool visited[255]; // calculate once only
int distances[255]; // at most 255 planets
vector<int> wormholes[255]; // each planet's possible wormholes

int shortestDist(int start, int n) {
	if(start < n-1 and !visited[start]){
		int newDist;
		for(int i=0; i<wormholes[start].size(); i++){
			newDist = shortestDist(wormholes[start][i], n) + 1;
			if(distances[start] > newDist){
				distances[start] = newDist;
			}
		}
		newDist = shortestDist(start + 1, n) + 1;
		if(newDist < distances[start]) distances[start] = newDist;
		
		visited[start] = true;
	}
	return distances[start];
}

int main(){
	int n, w, x, y, i;
	cin >> n;
	for(i=0;i<n;i++) {
		distances[i] = (n-1) - i; // by default
		visited[i] = false;
	}
	cin >> w;
	for(i=0;i<w;i++){
		cin >> x >> y;
		wormholes[x].push_back(y); // one-directional
	}
	int result = shortestDist(0, n);
	cout << result << endl;
	return 0;
}
