
enum gender{Male, Female};



struct STUDENT {
	char name[30];
	int age;
	int grade;
	int semester;
	gender gen;
	
};



struct JOURNAL {
	STUDENT** student;
	size_t n = 0;
	size_t cap = 0;
};

int Menu();
void Print(JOURNAL& K);
void EnterStudent(JOURNAL& K);
void DelStudent(JOURNAL& K);
void Write(JOURNAL& K);
void Read(JOURNAL& K);

int compareAge(const STUDENT& a, const STUDENT& b);;
int compareName(const STUDENT& a, const STUDENT& b);
int compareGrade(const STUDENT& a, const STUDENT& b);
int compareSemester(const STUDENT& a, const STUDENT& b);
int compareGender(const STUDENT& a, const STUDENT& b);



void SortChoise(JOURNAL& K);
void Sort(JOURNAL& K, int(*compare)(const STUDENT& a, const STUDENT& b));
