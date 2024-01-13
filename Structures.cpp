#include <iostream>
#include <algorithm>

const int SUBJECT_NUM = 4;
const int CLASS_SIZE = 5;

struct Student {
    const char* name;
    int marks[SUBJECT_NUM];
};

double averageMark(const Student& student);

//int compareByAverageMark(const void* a, const void* b);
bool compareByAverageMark(const Student& s1, const Student& s2);

void sortByAverageMark(Student(&students)[CLASS_SIZE]);

Student* getBestStudentPtr(Student(&students)[CLASS_SIZE]);

int studentsNumberAbovePercentile(Student(&students)[CLASS_SIZE], float percentile);

int main()
{
    // -------------------- TASK 1 --------------------
    std::cout << "-------------------- TASK 1 --------------------" << std::endl << std::endl;

    Student Mark = { "Mark", {1,2,3,4} };
    std::cout << "Average Mark's mark is " << averageMark(Mark) << std::endl << std::endl;

    // -------------------- TASK 2 --------------------
    std::cout << "-------------------- TASK 2 --------------------" << std::endl << std::endl;

    Student course[CLASS_SIZE] = { {"Peter", {3,4,5,3}}, {"Mary", {5,2,6,50}}, {"Osvald", {3,1,1,2}}, {"Bob", {3,5,1,45}}, {"Jenna", {3,4,6,15}} };

    for (Student s : course) {
        std::cout << "Student: " << s.name << " with marks { ";
        for (int mark : s.marks) {
            std::cout << mark << " ";
        }
        std::cout << "}" << std::endl;
    }

    std::cout << std::endl << std::endl;

    // -------------------- TASK 3 --------------------
    std::cout << "-------------------- TASK 3 --------------------" << std::endl << std::endl;
    
    sortByAverageMark(course);
    
    std::cout << "Sorted students: " << std::endl;
    for (Student s : course) {
        std::cout << "Student: " << s.name << " with marks { ";
        for (int mark : s.marks) {
            std::cout << mark << " ";
        }
        std::cout << "}" << std::endl;
    }

    std::cout << std::endl;

    // -------------------- TASK 4 --------------------
    std::cout << "-------------------- TASK 4 --------------------" << std::endl << std::endl;

    Student* bestStudentPtr = getBestStudentPtr(course);

    std::cout << "Best student " << bestStudentPtr->name << " is located in memory " << bestStudentPtr << std::endl << std::endl;

    // -------------------- TASK 5 --------------------
    std::cout << "-------------------- TASK 5 --------------------" << std::endl << std::endl;

    float percentile = 0.75;
    int numStudentsAbove75 = studentsNumberAbovePercentile(course, percentile);

    std::cout << numStudentsAbove75 << " students in class have an average mark higher then " << static_cast<int>(percentile * 100) 
        << "% of the best average mark." << std::endl;
}

double averageMark(const Student& student) {
    double sum = 0;
    for (int i : student.marks) {
        sum += i;
    }

    return sum / static_cast<double>((sizeof(student.marks) / sizeof(int)));
}

/*int compareByAverageMark(const void* a, const void* b)
{
    if (averageMark(*(Student*)a) < averageMark(*(Student*)b)) return -1;
    if (averageMark(*(Student*)a) == averageMark(*(Student*)b)) return 0;
    if (averageMark(*(Student*)a) > averageMark(*(Student*)b)) return 1;
}*/

bool compareByAverageMark(const Student& s1, const Student& s2) {
    return averageMark(s1) > averageMark(s2);
}

void sortByAverageMark(Student (&students)[CLASS_SIZE]) {
    //std::qsort(students, CLASS_SIZE, sizeof(Student), compareByAverageMark);
    //std::sort(students, students + CLASS_SIZE, [](const Student &s1, const Student &s2) {return averageMark(s1) > averageMark(s2);});
    std::sort(students, students + CLASS_SIZE, compareByAverageMark);
}

Student* getBestStudentPtr(Student(&students)[CLASS_SIZE]) {
    Student *bestStudentPtr = students;

    for (int i = 1; i <= CLASS_SIZE; i++) {
        if (compareByAverageMark(students[i], *bestStudentPtr)) {
            bestStudentPtr = students + i;
        }
    }

    return bestStudentPtr;
}

int studentsNumberAbovePercentile(Student(&students)[CLASS_SIZE], float percentile = 0.75) {
    int bestAverageMark75 =  averageMark(*(getBestStudentPtr(students))) * percentile;
    
    int count = 0;
    for (const Student &student : students) {
        if (averageMark(student) >= bestAverageMark75) {
            count += 1;
        }
    }

    return count;
}
