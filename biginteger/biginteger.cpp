#include<bits/stdc++.h>
using namespace std;

class BigInteger {
private:
    vector<int> digits;

public:
    BigInteger(string num) {
        for (int i = num.length() - 1; i >= 0; i--) {
            digits.push_back(num[i] - '0');
        }
    }

    void print() {
        for (int i = digits.size() - 1; i >= 0; i--) {
            cout << digits[i];
        }
        cout << endl;
    }

    BigInteger operator+(const BigInteger &other) {
        vector<int> result;
        int carry = 0;
        int sizeOne = digits.size();
        int sizeTwo = other.digits.size();
        int maxSize = max(sizeOne, sizeTwo);

        for (int i = 0; i < maxSize || carry; i++) {
            int sum = carry;
            if (i < sizeOne) sum += digits[i];
            if (i < sizeTwo) sum += other.digits[i];
            result.push_back(sum % 10);
            carry = sum / 10;
        }

        return BigInteger(result);
    }

    BigInteger operator*(const BigInteger &other){
    	vector<int> result(digits.size() + other.digits.size(), 0);

    	for(int i = 0; i < digits.size(); i++){
    		int carry = 0;
    		for(int j = 0; j < other.digits.size() || carry; j++){
    			int prod = result[i + j] + digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + carry;
    			result[i + j] = prod % 10;
    			carry = prod / 10;
    		}
    	}

    	while(result.size() > 0 && result.back() == 0) result.pop_back();
    	return BigInteger(result);
    }
private:
	BigInteger(const vector<int> &vec): digits(vec) {}
};

void factorial(int num){
    vector<int> fac;

    fac.push_back(1);

    for(int i = 2; i <= num; i++){
        int carry = 0;
        for(int j = 0; j < fac.size() || carry; j++){
            int sum = carry + i * (j < fac.size() ? fac[j] : 0);
            if (j < fac.size()) fac[j] = sum % 10;
            else fac.push_back(sum % 10);
            carry = sum / 10;

        }
    }

    for (int i= fac.size()-1; i>=0; i--){
        cout << fac[i];
    }
    cout << endl;
}

void solve() {
/*
    string num1, num2;
    cin >> num1;
    BigInteger b1(num1);

    cin >> num2;
    BigInteger b2(num2);

    // BigInteger result = b1 + b2;

    // result.print(); // ✅ Printing result correctly

    // Checking product
    BigInteger result = b1 * b2;
    result.print();
    */
    // Factorial
    int num;
    cin >> num;
    factorial(num);
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