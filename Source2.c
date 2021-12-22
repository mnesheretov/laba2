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
    printf("������!!! ������ �� ����� ���� ������.\n");
    return 0;
  }
  rewind(f1);
  for (i = 0; i < N; i++)
  {
    fscanf_s(f1, "%d", &mas1[i]);
  }
  do
  {
    printf("�������� ��������:\n1. ������\n2. ����������\n3. �����\n4. �����\n");
    printf("������� � �������: ");
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
      printf("�������� ����� ����������:\n1. ���������\n2. ��������\n3. �������\n");
      printf("������� � ����������: ");
      scanf_s("%d", &s);
      if (s == 1) //���������� ���������
      {
        clock_t start = clock();
        puz(N, mas1);
        clock_t end = clock();
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("�����, ������� �����������: %lf\n", time);
      }

      else if (s == 2) //���������� ��������
      {
        clock_t start = clock();
        vst(N, mas1);
        clock_t end = clock();
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("�����, ������� �����������: %lf\n", time);
      }

      else if (s == 3) //������� ����������
      {
        clock_t start = clock();
        quick(mas1, 0, N - 1);
        clock_t end = clock();
        time = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("�����, ������� �����������: %lf\n", time);
      }
    }

    else if (c == 3)
    {
      rewind(f1);
      for (i = 0; i < N; i++)
      {
        fscanf_s(f1, "%d", &mas1[i]);
      }
      printf("������ ������� � ���������.\n");
    }

    else if (c == 4)
    {
      printf("���������� ������.\n");
    }
    else
    {
      printf("������!\n");
    }
  } while (c != 4);
  fclose(f1);
  free(mas1);
  return 0;

}