#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

void bubbleSort(int *array, int n)
{
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if(array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
void selectionSort(int *array, int n)
{
    for(int i = 0; i < n; i++) {
        int temp_index = i;
        for(int j = i + 1; j < n; j++) {
            if(array[j] < array[temp_index]) {
                temp_index = j;
            }
        }
        if(i != temp_index) {
            int temp = array[i];
            array[i] = array[temp_index];
            array[temp_index] = temp;
        }
    }
}
void insertionSort(int *array, int n)
{
    for(int i = 1; i < n; i++){
        int key = array[i];
        int j = i - 1;
        while(key < array[j] && j >= 0){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main()
{
	int array[SIZE];
	int j, k;
	srand(time(NULL));
	for(j = 0;j < SIZE;j ++)
		array[j] = rand();

	for(j = 0;j < SIZE;j ++)
		printf("%d ", array[j]);
	printf("\n");

	bubbleSort(array, SIZE);

	for(j = 0;j < SIZE;j ++)
		printf("%d ", array[j]);
	printf("\n");

	for(j = 0;j < SIZE;j ++)
		array[j] = rand();

	for(j = 0;j < SIZE;j ++)
		printf("%d ", array[j]);
	printf("\n");

	insertionSort(array, SIZE);

	for(j = 0;j < SIZE;j ++)
		printf("%d ", array[j]);
	printf("\n");

	for(j = 0;j < SIZE;j ++)
		array[j] = rand();

	for(j = 0;j < SIZE;j ++)
		printf("%d ", array[j]);
	printf("\n");

	selectionSort(array, SIZE);

	for(j = 0;j < SIZE;j ++)
		printf("%d ", array[j]);
	printf("\n");
}
