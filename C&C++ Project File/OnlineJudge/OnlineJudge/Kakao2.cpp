#include<iostream>
#include<cmath>
#define MAX 500

using namespace std;

double standard_deviation(int arr[], int left, int right){
    double sum = 0;
    int n = right - left;
    for(int i = left; i < right; i++){
        sum += arr[i];
    } // 수의 합
    double avg = sum / n, variance = 0;
    for(int i = left; i < right; i++){
        variance += (pow(arr[i] - avg, 2) / n);
    }
    return sqrt(variance);
}

int main(){
    int N, K;
    int arr[MAX];
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> arr[i];
    /* Input Data */
    double min = pow(MAX, 4);
    while(K <= N){
        for(int i = 0; i < N - K + 1; i++){
            double sd = standard_deviation(arr, i, i + K);
            if(sd < min) min = sd;
        }
        K++;
    }
    cout << fixed;
    cout.precision(11);
    cout << min << '\n';
    return 0;
}


