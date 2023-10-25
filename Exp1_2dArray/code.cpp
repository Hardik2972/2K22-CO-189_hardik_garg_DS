#include <iostream>

using namespace std;

int main() {
    const int numStudents = 3;
    const int numSubjects = 5;
    int marks[numStudents][numSubjects];

    // Input marks for each student and subject
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter marks for Student " << i + 1 << ": ";
        for (int j = 0; j < numSubjects; j++) {
            cin >> marks[i][j];
        }
    }

    // Calculate the total marks for each student and average marks for each subject
    int totalMarks[numStudents] = {0};
    double averageMarks[numSubjects] = {0};

    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numSubjects; j++) {
            totalMarks[i] += marks[i][j];
            averageMarks[j] += marks[i][j];
        }
    }

    // Output total marks for each student
    cout << "Total marks for each student:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << ": " << totalMarks[i] << endl;
    }

    // Calculate and output the average marks for each subject
    cout << "Average marks for each subject:\n";
    for (int j = 0; j < numSubjects; j++) {
        averageMarks[j] /= numStudents;
        cout << "Subject " << j + 1 << ": " << averageMarks[j] << endl;
    }

    return 0;
}
