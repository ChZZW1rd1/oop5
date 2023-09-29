#pragma once
#include <iostream>
using namespace std;

class Person {
	string _name; // имя
	string _patronymic; //отчество
	string _lastName; // фамилия

	void SetName(string name) {
		this->_name = name;
	}
	void SetPatronymic(string pat) {
		this->_patronymic = pat;
	}
	void SetLastName(string lname) {
		this->_lastName = lname;
	}

public:
	string GetName() {
		return this->_name;
	}
	string GetPatronymic() {
		return this->_patronymic;
	}
	string GetLastName() {
		return this->_lastName;
	}

	Person(string name = "Bob", string patr = "Bob", string lname = "Bobos") {
		SetName(name);
		SetPatronymic(patr);
		SetLastName(lname);
	}

};