#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include "Header.h"



int scan(FILE* filename)
{
  int result = 0;
  rewind(filename);
  while (!ferror(filename) && !feof(filename)) {
    if (fgetc(filename) == '\n') ++result;
  }
  return result;
}

int main()
{
  srand(time(0));
  setlocale(LC_ALL, "Rus");
  FILE* f1 = 0;
  int i = 0;
  int j = 0;
  int N = 0;
  int c = 0;
  int s = 0;
  unsigned int* mas1;
  double time = 0.0;
  fopen_s(&f1, "..\\rand_In.txt", "r");
  N = scan(f1);

  mas1 = (unsigned int*)malloc(N * sizeof(unsigned int));
  if (mas1 == 0)
  {
    printf("ОШИБКА!!! Массив не может быть пустым.\n");
    return 0;
  }
  rewind(f1);
  for (i = 0; i < N; i++)
  {
    fscanf_s(f1, "%d", &mas1[i]);
  }
  do
  {
    printf("Выберите действие:\n1. Печать\n2. Сортировка\n3. Сброс\n4. Выход\n");
    printf("Введите № команды: ");
    scanf_s("%d", &c);

    if (c == 1)
    {
      for (i = 0; i < N; i++)
      {
        printf("mas[%d] = %d\n", i, mas1[i]);
      }
    }

    else if (c == 2)
    {
      printf("Выберите метод сортировки:\n1. Пузырьком\n2. Вставкой\n3. Быстрая\n");
      printf("Введите № сортировки: ");
      scanf_s("%d", &s);
      if (s == 1) //сортировка пузырьком
      {
        clock_t start = clock();
        puz(N, mas1);
        clock_t end = clock();
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Время, занятое сортировкой: %lf\n", time);
      }

      else if (s == 2) //сортировка вставкой
      {
        clock_t start = clock();
        vst(N, mas1);
        clock_t end = clock();
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Время, занятое сортировкой: %lf\n", time);
      }

      else if (s == 3) //быстрая сортировка
      {
        clock_t start = clock();
        quick(mas1, 0, N - 1);
        clock_t end = clock();
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Время, занятое сортировкой: %lf\n", time);
      }
    }

    else if (c == 3)
    {
      rewind(f1);
      for (i = 0; i < N; i++)
      {
        fscanf_s(f1, "%d", &mas1[i]);
      }
      printf("Массив сброшен к исходному.\n");
    }

    else if (c == 4)
    {
      printf("Завершение работы.\n");
    }
    else
    {
      printf("Ошибка!\n");
    }
  } while (c != 4);
  fclose(f1);
  free(mas1);
  return 0;

}