#include<bits/stdc++.h>
using namespace std;


bool isOdd(int n){
	return n&1;
}

bool getBitSet(int num, int pos){
	return (num & (1 << pos)) != 0;
}

int clearIthBit(int num, int pos){
	return (num & ~(1 << pos));
}

void setIthBit(int &num, int pos){
	num = num | (1 << pos);
}

void clearLastIBits(int &n, int pos){
	n &= (-1 << pos);
}

void clearBitsInRange(int &n, int i, int j){
	int a = (-1 << (j+1));
	int b = (1 << i) - 1;
	int mask = a | b;
	n = n & mask;
}

void replaceBits(int &m, int n, int i, int j){
	clearBitsInRange(m, i, j);
	m = m | (n << i);
}

bool checkPowerTwo(const int &n){
	return n > 1 && (n & (n-1)) == 0;
}

bool checkPowerFour(const int &n){
	// 0x5 represent 0101 in binary
	// all the ones should be in even position
	return n > 1 && ((n & (n-1)) == 0 && (n & 0x5555555));
}

int countSetBits(int n){
	//log(n) because n has log(n) bits
/*
	// soln 1 
	int count = 0;
	while(n > 0){
		count += (n & 1);
		n = n >> 1;
	}
	return count;
*/
	// soln 2: Fast approach
	int count = 0;
	while (n > 0){
		n = n & (n-1);
		count ++;
	}
	return count;
}

int convertToBinary(int n){
	int result=0, power = 1;

	while(n > 0){
		result += (n & 1) * power;
		power *= 10;
		n = n >> 1;
	}
	return result;
}

int findUnique(vector<int> &arr){
	// Find unique element in an array where each element appears twice except 1 element
	int unique = 0;
	for (auto num : arr){
		unique ^= num;
	}
	return unique;
}

pair<int, int> findUniqueII(vector<int> &arr){
	int xorSum = 0, elemOne = 0, elemTwo = 0;
	int rightMostSetBit;

	for (auto num: arr) xorSum ^= num;

	rightMostSetBit = xorSum & -xorSum;
	
	for (auto num : arr){
		if(num & rightMostSetBit) elemOne ^= num;
		else elemTwo ^= num;
	}

	return {elemOne, elemTwo};
}

// Find Unique from 3N + 1 array

void updateSumArray(vector<int> &sumArr, int num){
	for(int i = 0; i<32; i++){
		int ithBit = num & (1<<i);
		if (ithBit) sumArr[i]++;
	}
}

void generateUniqueNumberBits(vector<int> &sumArr){
	for(int i=0; i<sumArr.size(); i++)
		sumArr[i] = sumArr[i]%3;
}

int binaryArrayToNumber(vector<int> &sumArr){
	int result = 0;
	for (int i=0; i<sumArr.size(); i++){
		result += (sumArr[i] * (1 << i));
	}
	return result;
}

int findUniqueIII(vector<int> &arr){
	// 32-bit number initialize with 0 (representing result)
	vector<int> sumArr(32, 0);

	// Create Sum Array by adding the bits/position in the given array
	for (auto num: arr) updateSumArray(sumArr, num);

	generateUniqueNumberBits(sumArr);
	
	return binaryArrayToNumber(sumArr);
}

void solve(){
	int n, i, j, pos;
	cin >> n;
/*
	// Check for odd
	if (isOdd(n))
		cout << "True\n";
	else 
		cout << "False\n";
*/
/*
	// Check the bitset position
	cin >> pos;
	cout << getBitSet(n, pos) << endl;
	*/

/*
	// Clear ith bit
	cin >> pos;
	cout << clearIthBit(n, pos) << endl;
*/
/*
	// Set ith bit
	cin >> pos;
	setIthBit(n, pos);
	cout << n << endl;
*/
	/*
	// Clear from ith bit
	cin >> pos;
	clearLastIBits(n, pos);
	cout << n << endl;

*/
/*
	//clear bits in range
	cin >> i;
	cin >> j;
	clearBitsInRange(n, i, j);
	cout << n << endl;
	*/
/*
	// Replace bits in range
	int m;
	cin >> m;
	cin >> i;
	cin >> j;
	replaceBits(n, m, i, j);
	cout << n << endl;
	*/
/*
	// Check power of Two
	cout << checkPowerTwo(n) << " ";
*/
	/*
	// Check power of Four
	cout << checkPowerFour(n) << " ";
*/
/*
	// Count set bits in a number
	cout << countSetBits(n) << " ";
	*/
/*
	// Convert to Binary
	cout << convertToBinary(n) << " ";
	*/
	/*
	// Unique - 1
	vector<int> arr;
	for(i = 0; i<n; i++){
		int elem;
		cin >> elem;
		arr.push_back(elem);
	}
	cout << findUnique(arr) << "\n";
*/
/*
	// Unique - 2
	vector<int> arr;
	for(i = 0; i<n; i++){
		int elem;
		cin >> elem;
		arr.push_back(elem);
	}
	pair<int, int> elems = findUniqueII(arr);
	cout << elems.first << " " << elems.second << "\n";
*/
	// Unique - 3
	vector<int> arr;
	for(i = 0; i<n; i++){
		int elem;
		cin >> elem;
		arr.push_back(elem);
	}
	cout << findUniqueIII(arr) << "\n";
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	// t=1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;

}