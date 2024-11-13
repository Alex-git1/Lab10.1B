#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

struct Student {
    string surname;
    int course;
    int speciality;
    int physicsGrade;
    int mathGrade;
    union {
        int programmingGrade;
        int numericMethodsGrade;
        int pedagogyGrade;
    } extraGrade;
};

string specialityStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

void Create(Student* students, const int N);
void Print(const Student* students, const int N);
void CountMathGrades(const Student* students, const int N, int& count5, int& count4, int& count3);
void FindTopStudents(const Student* students, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* students = new Student[N];
    Create(students, N);
    Print(students, N);

    int count5 = 0, count4 = 0, count3 = 0;
    CountMathGrades(students, N, count5, count4, count3);
    cout << "\nКількість оцінок з математики:\n";
    cout << "Оцінка 5: " << count5 << "\nОцінка 4: " << count4 << "\nОцінка 3: " << count3 << endl;

    cout << "\nСтуденти, які отримали оцінку 5 з фізики і математики:\n";
    FindTopStudents(students, N);

    delete[] students;
    return 0;
}

void Create(Student* students, const int N) {
    for (int i = 0; i < N; i++) {
        cout << "Студент №" << i + 1 << ":" << endl;
        cin.ignore();

        cout << " Прізвище: ";
        getline(cin, students[i].surname);
        cout << " Курс: ";
        cin >> students[i].course;

        cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> students[i].speciality;

        cout << " Оцінка з фізики: ";
        cin >> students[i].physicsGrade;
        cout << " Оцінка з математики: ";
        cin >> students[i].mathGrade;

        if (students[i].speciality == 0) {
            cout << " Оцінка з програмування: ";
            cin >> students[i].extraGrade.programmingGrade;
        }
        else if (students[i].speciality == 1) {
            cout << " Оцінка з чисельних методів: ";
            cin >> students[i].extraGrade.numericMethodsGrade;
        }
        else {
            cout << " Оцінка з педагогіки: ";
            cin >> students[i].extraGrade.pedagogyGrade;
        }
        cout << endl;
    }
}

void Print(const Student* students, const int N) {
    cout << "===========================================================================================================================" << endl;
    cout << "| № | Прізвище       | Курс | Спеціальність          | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "| " << setw(1) << right << i + 1 << " ";
        cout << "| " << setw(15) << left << students[i].surname;
        cout << "| " << setw(4) << right << students[i].course << " ";
        cout << "| " << setw(23) << left << specialityStr[students[i].speciality];
        cout << "| " << setw(6) << right << students[i].physicsGrade << " ";
        cout << "| " << setw(10) << right << students[i].mathGrade << " ";

        if (students[i].speciality == 0) {
            cout << "| " << setw(13) << right << students[i].extraGrade.programmingGrade << " |" << setw(17) << " " << "|" << setw(10) << "|" << endl;
        }
        else if (students[i].speciality == 1) {
            cout << "| " << setw(14) << " " << "| " << setw(15) << right << students[i].extraGrade.numericMethodsGrade << " |" << setw(10) << "|" << endl;
        }
        else {
            cout << "| " << setw(14) << " " << "| " << setw(16) << " " << "|" << setw(8) << right << students[i].extraGrade.pedagogyGrade << " |" << endl;
        }
    }
    cout << "===========================================================================================================================" << endl;
}

void CountMathGrades(const Student* students, const int N, int& count5, int& count4, int& count3) {
    count5 = count4 = count3 = 0;
    for (int i = 0; i < N; i++) {
        if (students[i].mathGrade == 5) count5++;
        else if (students[i].mathGrade == 4) count4++;
        else if (students[i].mathGrade == 3) count3++;
    }
}

void FindTopStudents(const Student* students, const int N) {
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (students[i].physicsGrade == 5 && students[i].mathGrade == 5) {
            cout << " " << students[i].surname << endl;
            found = true;
        }
    }
    if (!found) {
        cout << " Немає студентів з оцінкою 5 з фізики і математики." << endl;
    }
}