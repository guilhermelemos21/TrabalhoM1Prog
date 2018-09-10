#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>


using namespace std;

int bubblesort(int vet[], int tamanho) {
	int troca = 0;
	int aux;

	for (int i = 0; i < tamanho; i++)
		for (int j = i + 1; j < tamanho; j++)
			if (vet[i] > vet[j])
			{
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
				troca = troca + 1;
			}
	return troca;
}
int quicksort(int values[], int began, int end)
{
	int i, j, pivo, aux, troca = 0;
	i = began;
	j = end - 1;
	pivo = values[(began + end) / 2];
	while (i <= j)
	{
		while (values[i] < pivo && i < end)
		{
			i++;
		}
		while (values[j] > pivo && j > began)
		{
			j--;
		}
		if (i <= j)
		{
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
			troca++;
		}
	}
	if (j > began)
		quicksort(values, began, j + 1);
	if (i < end)
		quicksort(values, i, end);
	return troca;
}
int InsertionSort(int vetor[], int TAM) {
	int x, y, aux, troca = 0;
	cout << endl;
	for (x = 1; x < TAM; x++)
	{
		aux = vetor[x];
		y = x - 1;
		while (y >= 0 && aux < vetor[y])
		{
			vetor[y + 1] = vetor[y];
			y--;
			troca++;
		}
		vetor[y + 1] = aux;

	}return troca;
}
int SelectionSort(int vet[], int TAMANHO) {
	int aux, troca = 0;
	for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO; j++)
			if (vet[i] < vet[j])
			{

				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
				troca = troca + 1;
			}
	}
	return troca;
}
int gnomeSort(int vet[], int TAMANHO)
{
	int index = 0, troca = 0;
	while (index < TAMANHO) {
		if (index == 0)
			index++;
		if (vet[index] >= vet[index - 1])
			index++;
		else {
			swap(vet[index], vet[index - 1]);
			index--;
			troca = troca + 1;
		}
	}
	return troca;
}
void shell_sort(int vet[], int TAMANHO) {

	int gap = 1;
	int i, j, aux, troca = 0;

	while (gap < TAMANHO) {
		gap = gap * 3 + 1;
	}

	while (gap > 1) {
		gap /= 3;

		for (i = gap; i < TAMANHO; i++) {
			aux = vet[i];
			j = i;

			while (j >= gap && aux < vet[j - gap]) {
				vet[j] = vet[j - gap];
				j -= gap;
				troca++;
			}

			vet[j] = aux;
		}
	}cout << troca << "\t";
}
void SorteioDoVetor(int vet1[], int tamanho1, int vet2[], int tamanho2, int vet3[], int tamanho3, int vet4[], int tamanho4, int vet5[], int tamanho5) {
	for (int i = 0; i < tamanho1; i++)
		vet1[i] = rand() % 10;
	for (int i = 0; i < tamanho2; i++)
		vet2[i] = rand() % 101;
	for (int i = 0; i < tamanho3; i++)
		vet3[i] = rand() % 1001;
	for (int i = 0; i < tamanho4; i++)
		vet4[i] = rand() % 10001;
	for (int i = 0; i < tamanho5; i++)
		vet5[i] = rand() % 100001;

}

void EscreverVetor(int vet[], int tamanho) {
	for (int i = 0; i < tamanho; i++)
		cout << vet[i] << "\t";
	cout << endl;
}
void Menu() {

	const int  TAMANHO1 = 10, TAMANHO2 = 100, TAMANHO3 = 1000, TAMANHO4 = 10000, TAMANHO5 = 100000;
	int troca[5]{ 0,0,0,0,0 };
	int troca2 = 0, inici[5] = { 0,0,0,0,0 };
	int vet1[TAMANHO1], vet2[TAMANHO2], vet3[TAMANHO3], vet4[TAMANHO4], vet5[TAMANHO5], op = 0;
	SorteioDoVetor(vet1, TAMANHO1, vet2, TAMANHO2, vet3, TAMANHO3, vet4, TAMANHO4, vet5, TAMANHO5);
	cin >> op;
	if (op == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			clock_t inicio = clock();
			if (i == 0) troca[i] = bubblesort(vet1, TAMANHO1);
			if (i == 1) troca[i] = bubblesort(vet2, TAMANHO2);
			if (i == 2)troca[i] = bubblesort(vet3, TAMANHO3);
			if (i == 3)troca[i] = bubblesort(vet4, TAMANHO4);
			if (i == 4)troca[i] = bubblesort(vet5, TAMANHO5);
			clock_t fim = clock();
			cout << (double)(fim - inicio) / CLOCKS_PER_SEC << endl;
		}
	}
	else if (op == 2)
	{
		for (int i = 0; i < 5; i++)
		{
			clock_t inicio = clock();
			if (i == 0) troca[i] = quicksort(vet1, inici[i], TAMANHO1);

			if (i == 1) troca[i] = quicksort(vet2, inici[i], TAMANHO2);

			if (i == 2)troca[i] = quicksort(vet3, inici[i], TAMANHO3);

			if (i == 3)troca[i] = quicksort(vet4, inici[i], TAMANHO4);

			if (i == 4)troca[i] = quicksort(vet5, inici[i], TAMANHO5);
			clock_t fim = clock();
			cout << (double)(fim - inicio) / CLOCKS_PER_SEC << endl;
		}
	}
	else if (op == 3)
	{
		for (int i = 0; i < 5; i++)
		{
			clock_t inicio = clock();
			if (i == 0) troca[i] = InsertionSort(vet1, TAMANHO1);

			if (i == 1) troca[i] = InsertionSort(vet2, TAMANHO2);

			if (i == 2)troca[i] = InsertionSort(vet3, TAMANHO3);

			if (i == 3)troca[i] = InsertionSort(vet4, TAMANHO4);

			if (i == 4)troca[i] = InsertionSort(vet5, TAMANHO5);
			clock_t fim = clock();
			cout << (double)(fim - inicio) / CLOCKS_PER_SEC << endl;
		}
	}
	else if (op == 4)
	{
		for (int i = 0; i < 5; i++)
		{
			clock_t inicio = clock();
			if (i == 0) troca[i] = SelectionSort(vet1, TAMANHO1);

			if (i == 1) troca[i] = SelectionSort(vet2, TAMANHO2);

			if (i == 2)troca[i] = SelectionSort(vet3, TAMANHO3);

			if (i == 3)troca[i] = SelectionSort(vet4, TAMANHO4);

			if (i == 4)troca[i] = SelectionSort(vet5, TAMANHO5);
			clock_t fim = clock();
			cout << (double)(fim - inicio) / CLOCKS_PER_SEC << endl;
		}
	}
	else if (op == 5)
	{
		for (int i = 0; i < 5; i++)
		{
			clock_t inicio = clock();
			if (i == 0) troca[i] = gnomeSort(vet1, TAMANHO1);

			if (i == 1) troca[i] = gnomeSort(vet2, TAMANHO2);

			if (i == 2)troca[i] = gnomeSort(vet3, TAMANHO3);

			if (i == 3)troca[i] = gnomeSort(vet4, TAMANHO4);

			if (i == 4)troca[i] = gnomeSort(vet5, TAMANHO5);
			clock_t fim = clock();
			cout << (double)(fim - inicio) / CLOCKS_PER_SEC << endl;
		}
	}
	else if (op == 6)
	{
		clock_t inicio = clock();
		shell_sort(vet1, TAMANHO1);
		shell_sort(vet2, TAMANHO2);
		shell_sort(vet3, TAMANHO3);
		shell_sort(vet4, TAMANHO4);
		shell_sort(vet5, TAMANHO5);
		clock_t fim = clock();
		cout << (double)(fim - inicio) / CLOCKS_PER_SEC << endl;
	}

	if (op != 6) {
		for (int i = 0; i < 5; i++)
			cout << troca[i] << "\t";
		cout << endl;
	}
}
int main()
{
	srand(time(NULL));
	Menu();

	return 0;
}