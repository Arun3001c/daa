#include<stdio.h>
void findMaxMin(int arr[], int low, int high, int *min, int *max) {
	int mid, min1, max1, min2, max2;
	if(low == high) {
		*min = *max = arr[low];
		return;
	}
	if(high == low + 1) {
		if(arr[low] < arr[high]) {
			*min = arr[low];
			*max = arr[high];
		} else {
			*min = arr[high];
			*max = arr[low];
		}
		return;
	}
	mid = (low + high) / 2;
	findMaxMin(arr, low, mid, &min1, &max1);
	findMaxMin(arr, mid + 1, high, &min2, &max2);
	*min = (min1 < min2) ? min1 : min2;
	*max = (max1 > max2) ? max1 : max2;
}
int main() {
	int i, n, min, max;
	printf("Enter the no.of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements: ",n);
	for (i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	findMaxMin(arr, 0, n - 1, &min, &max);
	printf("Minimum element: %d\n", min);
	printf("Maximum element: %d\n", max);
	return 0;
}
