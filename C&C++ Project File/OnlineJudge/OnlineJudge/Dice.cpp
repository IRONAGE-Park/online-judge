#include<iostream>
using namespace std;

typedef struct DICE {
	int A;
	int B;
	int C;
	int D;
	int E;
	int F;
}DICE;

DICE dice[10000];
int num;

void Scan() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> dice[i].A >> dice[i].B >> dice[i].C >> dice[i].D >> dice[i].E >> dice[i].F;
	}
}

int Dice(int n) {
	int up = n, bigest, sum = 0;
	// A-F, B-D, C-E
	for (int i = 0; i < num; i++) {
		if (dice[i].A == up) {
			up = dice[i].F;
			bigest = dice[i].B;
			if (bigest < dice[i].C) bigest = dice[i].C;
			if (bigest < dice[i].D) bigest = dice[i].D;
			if (bigest < dice[i].E) bigest = dice[i].E;
			sum += bigest;
		}
		else if (dice[i].B == up) {
			up = dice[i].D;
			bigest = dice[i].A;
			if (bigest < dice[i].C) bigest = dice[i].C;
			if (bigest < dice[i].E) bigest = dice[i].E;
			if (bigest < dice[i].F) bigest = dice[i].F;
			sum += bigest;
		}
		else if (dice[i].C == up) {
			up = dice[i].E;
			bigest = dice[i].A;
			if (bigest < dice[i].B) bigest = dice[i].B;
			if (bigest < dice[i].D) bigest = dice[i].D;
			if (bigest < dice[i].F) bigest = dice[i].F;
			sum += bigest;
		}
		else if (dice[i].D == up) {
			up = dice[i].B;
			bigest = dice[i].A;
			if (bigest < dice[i].C) bigest = dice[i].C;
			if (bigest < dice[i].E) bigest = dice[i].E;
			if (bigest < dice[i].F) bigest = dice[i].F;
			sum += bigest;
		}
		else if (dice[i].E == up) {
			up = dice[i].C;
			bigest = dice[i].A;
			if (bigest < dice[i].B) bigest = dice[i].B;
			if (bigest < dice[i].D) bigest = dice[i].D;
			if (bigest < dice[i].F) bigest = dice[i].F;
			sum += bigest;
		}
		else {
			up = dice[i].A;
			bigest = dice[i].B;
			if (bigest < dice[i].C) bigest = dice[i].C;
			if (bigest < dice[i].D) bigest = dice[i].D;
			if (bigest < dice[i].E) bigest = dice[i].E;
			sum += bigest;
		}
	}
	return sum;
}

int main() {
	int finalsum;
	Scan();
	finalsum = Dice(1);
	for (int i = 2; i <= 6; i++) {
		if (finalsum < Dice(i)) finalsum = Dice(i);
	}
	cout << finalsum;
	return 0;
}