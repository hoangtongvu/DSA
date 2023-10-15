#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Student
{
public:
	int id;
	string name;
	string _class;
	Student(int id, string name, string _class);
	~Student();

private:

};

Student::Student(int id, string name, string _class)
{
	this->id = id;
	this->name = name;
	this->_class = _class;
}

Student::~Student()
{
}



class StudentManager
{
private:
	int capacity;
	int size;

public:
	Student** students;
	StudentManager();
	~StudentManager();
	void Insert(int id, string name, string _class);
	void Delete(int id);
	string Info(int id);
	Student* GetStudentWith(int id);
	int HashFunction(int i);

private:

};

StudentManager::StudentManager()
{
	this->capacity = 50;
	this->size = 0;
	this->students = new Student * [capacity];

	for (int i = 0; i < this->capacity; i++)
	{
		this->students[i] = NULL;
	}
}

StudentManager::~StudentManager()
{
}

void StudentManager::Insert(int id, string name, string _class)
{
	Student* newStudent = new Student(id, name, _class);
	int hashIndex = this->HashFunction(id);

	//check if at hashIndex element exsist
	while (this->students[hashIndex] != NULL)
	{
		hashIndex++;
		if (hashIndex >= this->capacity) hashIndex = 0;
	}

	this->students[hashIndex] = newStudent;
	this->size++;

}

void StudentManager::Delete(int id)
{
	Student* s = this->GetStudentWith(id);
	if (s == NULL) return;
	delete s;
}

string StudentManager::Info(int id)
{
	Student* s = this->GetStudentWith(id);
	return s == NULL ? "NA,NA" : s->name + ", " + s->_class;
}

Student* StudentManager::GetStudentWith(int id)
{
	int hashIndex = this->HashFunction(id);
	int tempIndex = hashIndex;
	while (true)
	{
		Student* s = this->students[hashIndex];
		if (s != NULL)
		{
			if (s->id == id) return s;
		}


		hashIndex++;
		if (hashIndex >= this->capacity) hashIndex = 0;
		if (hashIndex == tempIndex) return NULL;

	}
}


int StudentManager::HashFunction(int i)
{

	return (i + 3) % this->capacity;
}

int main()
{
	StudentManager* sm = new StudentManager();

	sm->Insert(12, "Hoang", "12A5");
	sm->Insert(1, "Yen", "7Q3");
	sm->Insert(13, "Ha", "11B6");
	sm->Delete(141);
	cout<< sm->Info(12);


	delete sm;

    return 0;
}



