#include<iostream>

using namespace std;

int Euclidean(int a, int b) {
    return a%b ? Euclidean(b, a%b) : b;
}
/*
int main(){
    cout << Euclidean(1366, 768);
    return 0;
}
*/
