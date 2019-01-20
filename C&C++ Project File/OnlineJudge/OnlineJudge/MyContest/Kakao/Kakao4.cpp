#include<iostream>
#include<vector>

using namespace std;

typedef struct Node{
    int singer; // 가수 번호
    int subNode; // 서브노드의 갯수
    vector<int> child; // 자식들 정보
}Node;

vector< Node > tree; // 트리
vector<int> singerNum; // 가수들의 노래 갯수
vector<long long int> songPoint; // 해당 곡을 부른 가수의 총 점수
vector<int> Time; // 그 가수의 노래가 평균점수를 넘게 된 시간
int N, K, J;
int T, P, S;

void SubtreeCounting(int root){
    tree[root].subNode = 1; // 우선 자기 자신 1개
    for(int i = 0; i < tree[root].child.size(); i++){
        SubtreeCounting(tree[root].child[i]);
        tree[root].subNode += tree[tree[root].child[i]].subNode;
    }
}

void Update(int root, int point){
    songPoint[tree[root].singer] += point;
    if(songPoint[tree[root].singer] / singerNum[tree[root].singer] >= J && Time[tree[root].singer] == -1)
        Time[tree[root].singer] = T;
    for(int i = 0; i < tree[root].child.size(); i++){
        Update(tree[root].child[i], point);
    }
}

int main(){
    cin >> N >> K >> J;
    tree.resize(N + 1); songPoint.resize(N + 1);
    singerNum.resize(N + 1); Time.resize(N + 1, -1);
    for(int i = 2; i < N + 1; i++){
        int parent;
        cin >> parent;
        tree[parent].child.push_back(i);
    } // 자식 연결
    for(int i = 1; i <= N; i++){
        int num;
        cin >> num;
        singerNum[num]++;
        tree[i].singer = num;
    } // 가수 번호 할당
    // 트리 완성
    SubtreeCounting(1); // 1번 부터 재귀로 자식 수 체크
    while(K--){
        cin >> T >> P >> S;
        Update(P, S / tree[P].subNode);
    }
    for(int i = 1; i <= N; i++){
        cout << Time[tree[i].singer] << '\n';
    }
    return 0;
}
