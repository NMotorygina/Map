#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef map<string, vector <int>> StudentsAll;
typedef pair<string, vector <int>> Student;

int main()
{
	string name, line, temp;
	int grade, pos;
	vector <int> grades;
	StudentsAll studentsAll;
	
	ifstream file;
	file.open("Test.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			grades.clear();
			getline(file, line, ';');

			if (!line.empty()) {

			pos = line.find("-");
			name = line.substr(0, pos);
			line = line.substr(pos + 1);

			while (line.find(",") != string::npos)
			 {
				pos = line.find(",");
				temp = line.substr(0, pos);
				grade = stoi(temp);
				line = line.substr(pos + 1);
				grades.push_back(grade);
			}
				
			grade = stoi(line);
			grades.push_back(grade);

			}

		auto element = Student(name, grades);
			studentsAll.insert(element);

		}
	}
	else cout << "Error!";
	
	for (auto item : studentsAll) {	
		cout << item.first;

		for (auto grade : item.second) {
			cout << grade << ", ";
		}
		cout << endl;
		
		
	}


}