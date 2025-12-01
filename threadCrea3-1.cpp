#include <iostream>
#include <Windows.h>
DWORD WINAPI printer(LPVOID ram)
{
	for (int i = 0; i < 100; i++)
	{
		cout << "Thread " << *((PINT)ram) << ", var = " << j << endl;
	}
	return 1;
}
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Incorrect number of arguments\n");
		return 0;
	}
	HANDLE* array = (HANDLE*)malloc(sizeof(HANDLE) * atoi(argv[1]));
	PINT array1 = (PINT)malloc(sizeof(int) * atoi(argv[1]));
	for (int i = 0; i < atoi(argv[1]); i++)
	{
		array1[i] = i;
		array[i] = CreateThread(NULL, 0, printer, &array1[i], 0, NULL);
		//create thread as many as argv[1] times
	}
	WaitForMultipleObjects(atoi(argv[1]), array, TRUE, INFINITE);
	delete[]array;
	return 0;
}