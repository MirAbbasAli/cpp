#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back
#define endl "\n"

#define si set <int>
#define vi vector <int>
#define pii pair <int, int>
#define vpi vector <pii>
#define mii map <int, int>
#define que_max priority_queue <int>
#define que_min priority_queue <int, vi, greater<int>>
#define sz(x) ((int) x.size())

#define print(a) for (auto x : a) cout << x << " "; cout << endl
#define print1(a) for (auto x: a) cout << x.F << " " << x.S << endl
#define print2(a,x,y) for (int i = x, i < y; i++) cout << a[i] << " "; cout << endl
#define bug(...) ___f (#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

void modifyArray(array<int, 5> arr){
	arr[0]=2;
}

void modifyArrayRef(array<int, 5> &arr){
	arr[0]=2;
}

void printArray(const array<int, 5> &arr){
	for(auto val : arr){
		cout << val << " ";
	}
	cout << endl;
}


void stlArray(){
	array<int, 5> arr = {1, 2, 3, 4, 5};

	// Access
	cout<<arr[0]<<endl;
	cout<<arr.at(1)<<endl;

	cout<<arr.size()<<endl;

	print(arr);

	// Fill operation
	array<int, 10> newArr;
	newArr.fill(1);

	print(newArr);

	// sorting operation
	array<int, 5> arrTwo = {2,5,3,4,1};
	print(arrTwo);
	sort(arrTwo.begin(), arrTwo.end());
	print(arrTwo);

	// pass by value(default)
	print(arr);
	modifyArray(arr);
	print(arr);

	// pass by reference
	print(arr);
	modifyArrayRef(arr);
	print(arr);

	// pass by const reference
	printArray(arr);
}

class Job {
public:
	int id;
	int priority;

	Job (int i, int p){
		id = i;
		priority = p;
	}
};

struct CompareJob {
	bool operator()(const Job &a, const Job &b){
		return a.priority > b.priority; // Higher priority first
	}
};

void stlPriorityQueue(){
	priority_queue<Job, vector<Job>, CompareJob> pq;
	pq.emplace(1, 10);
	pq.emplace(2, 20);
	pq.emplace(3, 5);

	while (!pq.empty()){
		Job top = pq.top();
		cout << "Job ID: " << top.id << ", Prirority: " << top.priority << endl;
		pq.pop();
	}

}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	// cin >> t;
	while (t--) stlPriorityQueue();

	return 0;
}