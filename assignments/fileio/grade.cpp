//Colton Williams Fileio HW grading tool


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Data structure to store student information
struct Student {
    string firstName;
    string lastName;
    vector<int> testScores;
    double average;
    char grade;
};

// Function to read student data from file
void readStudentData(string fileName, vector<Student>& students) {
    ifstream inputFile(fileName);

    if (!inputFile) {
        cout << "Error: Unable to open file " << fileName << endl;
        return;
    }

    string firstName, lastName;
    int test1, test2, test3, test4;

    while (inputFile >> firstName >> lastName >> test1 >> test2 >> test3 >> test4) {
        Student student;
        student.firstName = firstName;
        student.lastName = lastName;
        student.testScores.push_back(test1);
        student.testScores.push_back(test2);
        student.testScores.push_back(test3);
        student.testScores.push_back(test4);

        students.push_back(student);
    }

    inputFile.close();
}

// Function to calculate student's average score
double calculateAverage(const vector<int>& scores) {
    double total = 0.0;
    for (int score : scores) {
        total += score;
    }
    return total / scores.size();
}

// Function to calculate student's letter grade
char calculateLetterGrade(double averageScore) {
    if (averageScore >= 90.0) {
        return 'A';
    } else if (averageScore >= 80.0) {
        return 'B';
    } else if (averageScore >= 70.0) {
        return 'C';
    } else if (averageScore >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}

// Function to sort students by their average score in descending order
void sortByAverageScore(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.average > b.average;
    });
}

// Function to write student report to file

void writeStudentReport(string fileName, const vector<Student>& students) {
    ofstream outputFile(fileName);

    if (!outputFile) {
        cout << "Error: Unable to open file " << fileName << endl;
        return;
    }

    outputFile << "=============================================================================" << endl;
    outputFile << "fname\t\tlname\t\t\t\t\ttest1  test2  test3  test4\t  avg.\tgrade" << endl;
    outputFile << "=============================================================================" << endl;

    for (const auto& student : students) {
        outputFile << setw(15) << left << student.firstName << "\t" << setw(15) << left << student.lastName << "\t";
        for (int score : student.testScores) {
            outputFile << setw(6) << right << score << " ";
        }
        outputFile << "\t" << fixed << setprecision(2) << student.average << "\t\t" << student.grade << endl;
    }

    outputFile << "*****************************************************************************" << endl;

    // Class Average

    outputFile << "Class Average:\t\t\t\t\t\t";
    for (int i = 0; i < 4; i++) {
        double total = 0.0;
        for (const auto& student : students) {
            total += student.testScores[i];
        }
        double classAverage = total / students.size();
        outputFile << fixed << setprecision(2) << classAverage << "\t";
    }
    outputFile << endl;

    // Class Max

    outputFile << "Class Max:\t\t\t\t\t\t";
    for (int i = 0; i < 4; i++) {
        int maxScore = 0;
        for (const auto& student : students) {
            maxScore = max(maxScore, student.testScores[i]);
        }
        outputFile << "\t" << maxScore << "\t";
    }
    outputFile << endl;

    // Class Min

    outputFile << "Class Min:\t\t\t\t\t\t";
    for (int i = 0; i < 4; i++) {
        int minScore = 100;
        for (const auto& student : students) {
            minScore = min(minScore, student.testScores[i]);
        }
        outputFile << "\t" << minScore << "\t";
    }
    outputFile << endl;

    // Class Grade Distribution

    outputFile << "===============================================================================\n" << endl;
    outputFile << "Class Grade Distribution:\n\n";

    int totalA = 0, totalB = 0, totalC = 0, totalD = 0, totalF = 0;
    for (const auto& student : students) {
        switch (student.grade) {
            case 'A':
                totalA++;
                break;
            case 'B':
                totalB++;
                break;
            case 'C':
                totalC++;
                break;
            case 'D':
                totalD++;
                break;
            case 'F':
                totalF++;
                break;
        }
    }

    int totalStudents = students.size();
    int percentageA = round((double) totalA / totalStudents * 100);
    int percentageB = round((double) totalB / totalStudents * 100);
    int percentageC = round((double) totalC / totalStudents * 100);
    int percentageD = round((double) totalD / totalStudents * 100);
    int percentageF = round((double) totalF / totalStudents * 100);

    outputFile << "A: " << percentageA << "%" << endl;
    outputFile << "B: " << percentageB << "%" << endl;
    outputFile << "C: " << percentageC << "%" << endl;
    outputFile << "D: " << percentageD << "%" << endl;
    outputFile << "F: " << percentageF << "%" << endl;
       
       
       
       
    outputFile << "===========================================================================" << endl;


 outputFile.close();



}


int main() {
// Declare a vector to store student information
vector<Student> students;
string inputFile;
string outputFile;
cout << "Enter input file name: ";
    getline(cin, inputFile);
// Read student data from file
readStudentData(inputFile, students);

// Calculate each student's average score and letter grade
for (auto& student : students) {
    student.average = calculateAverage(student.testScores);
    student.grade = calculateLetterGrade(student.average);
}

// Sort students by their average score in descending order
sortByAverageScore(students);

cout << "Enter output file name: ";
    getline(cin, outputFile);
// Write student report to file
writeStudentReport(outputFile, students);

return 0;


}

