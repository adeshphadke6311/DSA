#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Time Complexity   :   O(N * log(S)) where S = (arr[N-1] - arr[0])
//Space Complexity  :   O(1)

class Solution{
	public:
	
	bool isValid(vector<int> &arr, int N, int C, int minAllowedDist){ //O(N)
		int cows = 1, prevPosition = arr[0];
		
		for(int i=1; i<N; i++){
			if(arr[i] - prevPosition >= minAllowedDist){
				cows++;
				prevPosition = arr[i];
			}
			
			if(cows == C){
				return true;
			}
		}
		
		return false;
	}
	int minAllowedDistance(vector<int> &arr, int N, int C){
		sort(arr.begin(),arr.end());        //O(N log(N))
		int floor = 1, ceil = (arr[N-1]-arr[0]), ans = -1;
		
		while(floor <= ceil){  //O(N * log(arr[N-1] - arr[0]))
			int mid = floor + (ceil - floor)/2;
			
			if(isValid(arr, N, C, mid)){
				ans = mid;
				floor = mid+1;
				
			}else{
				ceil = mid-1;
			}
		}
		return ans;
	}
	
	
};

int main() {
	
	vector<int> arr = {1,2,8,4,9};
	int N = 5, C = 3;
	Solution sol;
	
	int result = sol.minAllowedDistance(arr, N, C);
	cout<<"Maximum Allowed Distance = "<<result<<endl;
	return 0;
}