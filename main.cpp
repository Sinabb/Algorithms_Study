#include<iostream>

void print(int input[], int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << input[i] << "";
	}
	std::cout << std::endl;
}

void Swap(int& value1, int& value2)
{
	int temp = value1;

	value1 = value2;
	value2 = temp;

}

// ----------------------
// Sequential Sort
// time : O(n^2)
// space :  O(n)
void Sequential(int input[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (input[i] > input[j])
			{
				Swap(input[i], input[j]);
			}
		}
	}
}

//Selection Sort
//time: O(n^2)
//space: O(n)
void SelectionSort(int input[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int minIndex = i;
		for (int j = 0; j < size; j++)
		{
			if (input[minIndex] > input[j])
			{
				minIndex = j;
			}
		}
	}
}

//bubble Sort
//time: O(n^2)
//space: O(n)
void bubbleSort(int input[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (input[j]>input[j+1])
			{
				Swap(input[j], input[j + 1]);
			}
		}
	}
}

//insertion sort
//time: O(n^2)
//space: O(n)
void insertionsort(int input[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int j = i;
		int target = input[i];
		while (--j >= 0 && target < input[j])
		{
			input[j + 1] = input[j];
			input[j] = target;
		}
	}
}

//merge sort
//time: O(n log n)
//space: O(n)
void merge(int input[], int start,int half, int end, int temp[])
{
	int i{ start };
	int j{ half + 1 };
	int tempIndex{};

	while (i <= half && j <= end)
	{
		if (input[i] < input[j])
		{
			temp[tempIndex++] = input[i++];
		}
		else
		{
			temp[tempIndex++] = input[j++];
		}
	}

	while (i <= half)
	{
		temp[tempIndex++] = input[i++];
	}

	while (j <= end)
	{
		temp[tempIndex++] = input[j++];
	}

	for (int i = start; i <= end; i++)
	{
		input[i] = temp[tempIndex++];
	}
}

void mergesort(int input[], int start, int end, int temp[])
{
	//base case
	if (start >= end)
	{
		return;
	}

	int half = (start + end) / 2;
	mergesort(input, start, half, temp);
	mergesort(input, half+1, end, temp);

	merge(input, start, half, end, temp);
}

//Quicksort
//time: O(c n long n)
//space: O(n)
void Quicksort(int input[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = input[(left + right) / 2];
	do
	{
		while (input[i] < pivot) {
			i++;
		}
		while (input[j]>pivot)
		{
			j--;
		}
		if (i <=j)
		{
			Swap(input[i], input[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left<i)
	{
		Quicksort(input, left, j);
	}
	if (i<right)
	{
		Quicksort(input, i, right);
	}
	
}

int main()
{
	const int ARRAY_SIZE{ 5 };
	int array[ARRAY_SIZE]{ 8,7,2,3,1 };

	//Sequential(array, ARRAY_SIZE);
	//SelectionSort(array, ARRAY_SIZE);
	//bubbleSort(array, ARRAY_SIZE);
	//int temArray[ARRAY_SIZE]{};
	//mergesort(array, 0, ARRAY_SIZE - 1, temArray);
	Quicksort(array, 0, ARRAY_SIZE - 1);
	print(array, ARRAY_SIZE);
}

