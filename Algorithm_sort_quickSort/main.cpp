#include <iostream>

#define N 8

using namespace std;

int i = -1;  //pivot���� ���� ���Ҵ� data[i] ���� �۰ų� ���� ������ ����

int partition(int* data, int begin, int end) { //data�� data[end]�� pivot ��� �¿�� ������, data[end] ��ġ ��ȯ
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
		quickSort(data, begin, pivot - 1); //���� ����
		quickSort(data, pivot+1, end); //������ ����
	}
}

int main() {
	int data[N] = {1, 7, 4, 9, 2, 8, 6, 5};

	quickSort(data, 0, 7);

	for (int i = 0; i < N; i++) {
		cout << data[i] << " ";
	}
}