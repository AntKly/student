#include <string>
#include "other.h"
#include <iostream>
#include <cstdio>

const char* genderOf[] = { "Male", "Female"};


int Menu() {
	int x = 0;
	std::cout << "Menu: \n 1 - Print \n 2 - Add student \n 3 - Del student \n 4 - Write to file \n 5 - Read from file \n 6 - Sort \n 7 - Exit\n";
	std::cin >> x;
	return x;

}

void Print(JOURNAL& K) {
	if (K.n == 0) {
		std::cout << "no students" << std::endl;
	}
	for (int i = 0; i < K.n; i++) {
		printf("Student N%3d\nName of student: %-30s\n Age of student: %d\n Grade for the semester: %6d\n Semester: %4d\n Gender: %9s\n\n",i + 1, K.student[i]->name, K.student[i]->age, K.student[i]->grade, K.student[i]->semester, genderOf[K.student[i]->gen]);
	}
}

void EnterStudent(JOURNAL& K) {
	if (K.cap == K.n) {
		K.cap++;
		STUDENT** copy = new STUDENT*[K.cap];
		for (int i = 0; i < K.n; i++) {
			copy[i] = K.student[i];
		}
		delete[] K.student;
		K.student = copy;
		K.student[K.n] = new STUDENT;
	}
	K.n++;
	
	char name[30];
	printf("Enter name ");
	scanf_s("%s", &name, 20);
	strcpy_s(K.student[K.n - 1]->name, name);

	int age = 10;

	while (age < 17 || age > 100) {
		printf("Enter age ");
		scanf_s("%d", &age, 20);
	}
	K.student[K.n - 1]->age = age;


	int semester = 0;
	while (semester <= 0) {
		printf("Enter semester ");
		scanf_s("%d", &semester, 20);
	}
	K.student[K.n - 1]->semester = semester;

	int grade = 0;
	while (grade <= 0) {
		printf("Enter grade for the semester ");
		scanf_s("%d", &grade);
	}
	K.student[K.n - 1]->grade = grade;

	
	
	printf("Choose gender :\n 0 - Male\n 1 - Female\n");
	scanf_s("%d", &K.student[K.n - 1]->gen);
	
}

void DelStudent(JOURNAL& K) {
	int N = 0;
	while (N <= 0 || N > K.n) {
		std::cout << "Enter N% student" << std::endl;
		std::cin >> N;
	}
		delete K.student[N - 1];
		if (N != K.n) {
			for (int i = N - 1; i < K.n - 1; i++) {
				K.student[i] = K.student[i + 1];
			}
			K.student[K.n - 1] = nullptr;
		}K.n--;
}

void Write(JOURNAL& K) {
	FILE* f = fopen("myStud.txt", "w");
	if (f) {
		fprintf(f, "%d\n", K.n);
		for (int i = 0; i < K.n; i++) {
			fprintf(f, "%s %d %d %d %d\n", K.student[i]->name, K.student[i]->age,K.student[i]->semester, K.student[i]->grade, K.student[i]->gen);
		}
		fclose(f);
	}
	else std::cout << "Error";
}

void Read(JOURNAL& K) {
	FILE* f = fopen("myStud.txt", "r");
	if (f) {
		int size = 0;
		fscanf(f, "%d\n", &size);
		for (int i = 0; i < size; i++) {
			if (K.cap == K.n) {
				K.cap++;
				STUDENT** copy = new STUDENT*[K.cap];
				for (int i = 0; i < K.cap - 1; i++) {
					copy[i] = K.student[i];
				}
				delete[] K.student;
				K.student = copy;
				K.student[K.cap - 1] = new STUDENT;
			}
			K.n++;
			fscanf(f, "%s %d %d %d %d", K.student[K.n - 1]->name, &K.student[K.n - 1]->age, &K.student[K.n -1]->semester, &K.student[K.n - 1]->grade, &K.student[K.n - 1]->gen);
		}
		fclose(f);
	}
}


int(*comparator[])(const STUDENT&, const STUDENT&) = {
	compareName,
	compareAge,
	compareGrade,
	compareSemester,
	compareGender
};


int compareName(const STUDENT& a, const STUDENT& b) {
	return std::strcmp(a.name, b.name);
}
int compareAge(const STUDENT& a, const STUDENT& b) {
	return a.age - b.age;

}
int compareGrade(const STUDENT& a, const STUDENT& b) {
	return a.grade - b.grade;
}
int compareSemester(const STUDENT& a, const STUDENT& b) {
	return a.semester - b.semester;
}
int compareGender(const STUDENT& a, const STUDENT& b) {
	return a.gen - b.gen;
}

void SortChoise(JOURNAL& K) {
	printf("Choose category : \n 0 - Name\n 1 - Age\n 2 - Grade for the semester\n 3 - Semester\n 4 - Gender\n");
	int n;
	scanf("%d", &n );
	Sort(K, comparator[n]);
}

void Sort(JOURNAL& K, int (*compare)(const STUDENT& a, const STUDENT& b)) {
	STUDENT** studentAr = K.student;
	for (int j = 1; j < K.n; j++) {
		for (int i = 0; i < K.n - 1; i++) {
			if (compare(*studentAr[i], *studentAr[i + 1]) > 0) {
				STUDENT* copy = K.student[i];
				K.student[i] = K.student[i + 1];
				K.student[i + 1] = copy;
			}
		}
	}
}
