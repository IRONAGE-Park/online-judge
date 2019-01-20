#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

int PrimeFactor(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return i;
	}
	return false;
}

int PrimeSum(int n) {
	int sum = 0;
	while (true) {
		int div = PrimeFactor(n);
		sum += div;
		if (div == 0) {
			if(sum) sum += n;
			break;
		}
		n /= div;
	}
	return sum;
}

int main() {
	ifstream inp("primefactor.inp");
	ofstream out("primefactor.out");

	int testcase;
	inp >> testcase;
	while (testcase--) {
		int n;
		inp >> n;
		int sol = PrimeSum(n);
		if (sol) out << sol;
		else out << "Prime Number";
		out << '\n';
	}
	inp.close();
	out.close();
	return 0;
}