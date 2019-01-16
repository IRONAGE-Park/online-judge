#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Food {
	int num;
	int time;
}Food;

bool compare(Food a, Food b) {
	return a.time < b.time;
}

int solution(vector<int> food_times, long long k) {
	int answer;
	k++;
	long long alltime = 0;
	vector<Food> sort_times(food_times.size());
	vector<int> not_exist_food;
	not_exist_food.reserve(food_times.size());
	for (int i = 0; i < food_times.size(); i++) {
		sort_times[i].time = food_times[i];
		sort_times[i].num = i + 1;
		alltime += food_times[i];
	}
	sort(sort_times.begin(), sort_times.end(), compare);
	if (alltime < k) return -1;

	int index = 0, all_delete = 0;
	while (true) {
		if (k > food_times.size() - not_exist_food.size()) {
			all_delete++;
			k -= food_times.size() - not_exist_food.size();
			while ((sort_times[index].time - all_delete) == 0) {
				not_exist_food.push_back(sort_times[index].num);
				index++;
			}
		}
		else {
			sort(not_exist_food.begin(), not_exist_food.end());
			answer = k;
			int i = 0;
			while (not_exist_food[i] <= answer && not_exist_food.size() > i) {
				i++;
				answer++;
			}
			return answer;
		}
	}
}


int main() {
	long long K;
	cin >> K;
	vector<int> input;
	int num;
	while (cin >> num) {
		if (num == 0) break;
		input.push_back(num);
	}
	int sol = solution(input, K);
	cout << sol << '\n';
	return 0;
}