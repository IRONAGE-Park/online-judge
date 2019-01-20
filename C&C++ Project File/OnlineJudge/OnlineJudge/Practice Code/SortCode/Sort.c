#include<stdio.h>
#include<stdlib.h>
#define INF 0xFFFFFFF

int compare(int *a, int *b) {    // 오름차순 비교 함수 구현
    if (*a < *b)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (*a > *b)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

void Swap(int *a, int *b){ // 두 수를 바꾸는 함수
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintArray(int *arr, int len){ // 배열 값들을 출력하는 함수
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void Selection_Sort(int *arr, int len){ // 선택정렬
    for(int i = 0; i < len - 1; i++){
        int minIDX = i; // 가장 작은 수의 인덱스를 저장하고 있는 변수
        for(int j = i + 1; j < len; j++){
            if(arr[minIDX] > arr[j]) // 지금까지 가장 작은 인덱스의 값보다 j번째 인덱스가 저장한 값이 작으면
                minIDX = j; // 가장 작은 인덱스를 j로 바꾸어 줌.
        }
        Swap(&arr[i], &arr[minIDX]); // i이후로 가장 작은 값의 인덱스와 i번째 인덱스 교환
        PrintArray(arr, 10);
    }
}

void Bubble_Sort(int *arr, int len){ // 버블정렬
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(arr[j] > arr[j + 1]) // j번째 인덱스 값보다 j + 1번째 인덱스 값이 작으면
                Swap(&arr[j], &arr[j + 1]); // 그 두 수를 바꾸어 줌.
        }
        PrintArray(arr, 10);
    }
}

void Insertion_Sort(int *arr, int len){ // 삽입정렬
    for(int i = 1; i < len; i++){
        int j = i - 1, data = arr[i]; // 추가할 i번째 데이터 미리 저장
        while(j >= 0 && arr[j] > data){
            arr[j + 1] = arr[j]; // 앞의 데이터를 뒤로 한 칸씩 당겨줌
            j--;
        }
        arr[j + 1] = data;
        PrintArray(arr, 10);
    }
}
/*
int main(){
    int arr[] = {10, 19, 8, 27, 6, 5, 64, 34, 2, 1};
    qsort(arr, 10, sizeof(int), compare);
    PrintArray(arr, 10);
    return 0;
}
 */
