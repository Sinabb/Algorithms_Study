#include<iostream>

void print(int input[], int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << input[i] << "";
	}
	std::cout << std::endl;
}

void Swap(int value1, int value2)
{
	int temp = value1;

	value1 = value2;
	value2 = temp;

}

// ----------------------
// Sequential Sort

// time : 0(n^2
// space : 0(1) / 0(n)
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

int main()
{
	const int ARRAY_SIZE{ 5 };
	int array[ARRAY_SIZE]{ 8,7,2,3,1 };

	Sequential(array, ARRAY_SIZE);
	print(array, ARRAY_SIZE);
}

