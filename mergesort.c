#include <stdio.h>

void merge(int arr[], int i, int m, int j)
{
  int temp[100], z = 0;
  int left = i;
  int right = m + 1;
  while (left <= m && right <= j)
  {
    if (arr[left] < arr[right])
    {
      temp[z++] = arr[left];
      left++;
    }
    else
    {
      temp[z++] = arr[right];
      right++;
    }
  }
  while (left <= m)
  {
    temp[z++] = arr[left];
    left++;
  }
  while (right <= j)
  {
    temp[z++] = arr[right];
    right++;
  }

  left = i;
  while (i <= j)
  {
    arr[i] = temp[i - left];
    i++;
  }
}

void mergeSort(int i, int arr[], int j)
{
  if (i >= j)
    return;

  int m = (i + j) / 2;
  mergeSort(i, arr, m);
  mergeSort(m + 1, arr, j);
  merge(arr, i, m, j);
}

int main()
{
  int N, arr[1000];
  printf("Enter the size of the array:");
  scanf("%d", &N);

  printf("Enter elements:\n");
  for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);

  mergeSort(0, arr, N - 1);

  printf("Sorted Array:\n");
  for (int i = 0; i < N; i++)
    printf("%d ", arr[i]);
  return 0;
}