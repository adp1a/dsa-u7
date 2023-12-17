#pragma once

template <class T, bool (*cf)(T*, T*)>
class Sort
{
public:	
	static void swap(T *&a, T *&b);
	static void SelectionSort(T *p[], int N);
//	static void BubleSort(T *p[], int N);
//	static void InsertionSort(T *p[], int N);
//	static void QuickSort(T *p[], int l, int h);
};

template <class T, bool (*cf)(T*, T*)> void Sort<T, cf>::swap(T *&a, T *&b)
{
	T* c = a;
	a = b;
	b = c;
}

template <class T, bool (*cf)(T*, T*)> void Sort<T, cf>::SelectionSort(T *p[], int N)
{
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			if (cf(p[i], p[j]))
				swap(p[i], p[j]);
}

/*
template <class T, bool (*cf)(T*, T*)> void Sort<T, cf>::BubleSort(T *p[], int N)
{
	bool isVymena = false;
	int j = 0;
	do
	{
		isVymena = false;
		for (int i = 0; i < N - 1 - j; i++)
			if (cf(p[i],p[i+1]))
			{
				swap(p[i], p[i+1]);
				isVymena = true;
			}
		j++;
	} while (isVymena == true);
}

template <class T, bool (*cf)(T*, T*)> void Sort<T, cf>::InsertionSort(T *p[], int N)
{
	for (int i = 1; i < N; i++)
	{
		T x = p[i];
		int j;
		for (j = i - 1; j >= 0 && (cf(x, p[j]) == false); j--)
			p[j + 1] = p[j];
		p[j + 1] = x;
	}
}

template <class T, bool (*cf)(T*, T*)> void Sort<T, cf>::QuickSort(T *p[], int l, int h)
{
	if (l < h)
	{
		T pivot = p[(l + h) / 2];
		int i = h, j = l;
		while (i > j)
		{
			while (cf(p[i], pivot)) 
				i--;
			while (cf(pivot, p[j]))
				j++;
			swap(p[i], p[j]);

			if (i > l)
				i--;
			if (j < h)
				j++;
		}

		QuickSort(p, l, i);
		QuickSort(p, j, h);
	}
}
*/



