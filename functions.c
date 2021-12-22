#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//сортировка пузырьком
void puz(int n, int a[]) {

  int i, j;

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
  }
}

//сортировка вставкой
void vst(int n, int a[]) {

  int i;
  int location;
  int newElement;

  for (i = 1; i < n; i++)
  {
    newElement = a[i];
    location = i - 1;
    while (location >= 0 && a[location] > newElement)
    {
      a[location + 1] = a[location];
      location = location - 1;
    }
    a[location + 1] = newElement;
  }
}

//быстрая сортировка
void quick(int* a, int left, int right) {

  int i, j;
  double x, y;

  i = left;
  j = right;
  x = a[(left + right) / 2];
  do
  {
    while ((a[i] < x) && (i < right))
      i++;
    while ((x < a[j]) && (j > left))
      j--;
    if (i <= j)
    {
      y = a[i];
      a[i] = a[j];
      a[j] = y;
      i++;
      j--;
    }
  } while (i <= j);
  if (left < j)
    quick(a, left, j);
  if (i < right)
    quick(a, i, right);
}