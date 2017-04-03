#include <iostream>
#include "other.h"
#include <cstdio>



int main()
{
	JOURNAL K = {};

	while (true) {
		int choise = Menu();
		switch (choise) {
		case 1: Print(K); break;
		case 2: EnterStudent(K); break;
		case 3: DelStudent(K); break;
		case 4: Write(K); break;
		case 5: Read(K); break;
		case 6: SortChoise(K); break;
		case 7: for (int i = 0; i < K.n; i++) {
			delete[] K.student[i];
		}
				delete[] K.student;
				return 0;
		default: std::cout << "Error" << std::endl; break;
		}
	}

	return 0;
}