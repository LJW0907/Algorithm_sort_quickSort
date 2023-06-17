#include <iostream>

#define N 8

using namespace std;

int i = -1;  //pivot보다 작은 원소는 data[i] 보다 작거나 같은 공간에 저장

int partition(int* data, int begin, int end) { //data를 data[end]를 pivot 삼아 좌우로 나누고, data[end] 위치 반환
	int j = begin;
	int i = j - 1;
	int pivot = data[end];
	int tmp;

	for (; j <= end; j++) {
		if (j == end) {
			tmp = data[i+1];
			data[i + 1] = data[end];
			data[end] = tmp;

			return i + 1;
		}
		if(data[j] < pivot) {
			i++;

			tmp = data[j];
			data[j] = data[i];
			data[i] = tmp;
		}
	}
}

void quickSort(int* data, int begin, int end) {
	int pivot;

	if (begin < end) {
		pivot = partition(data, begin, end);
		quickSort(data, begin, pivot - 1); //왼쪽 정렬
		quickSort(data, pivot+1, end); //오른쪽 정렬
	}
}

int main() {
	int data[N] = {1, 7, 4, 9, 2, 8, 6, 5};

	quickSort(data, 0, 7);

	for (int i = 0; i < N; i++) {
		cout << data[i] << " ";
	}
}