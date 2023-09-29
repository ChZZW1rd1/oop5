#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person {
	int _recordBookNumber; // номер зачетки
	int _admissionYear; // год поступления

	void SetRBNumber(int number) {
		this->_recordBookNumber = number;
	}
	void SetYear(int year) {
		if (year < 1950 || year > 2022) {
			throw exception("Incorrect year");
		}
		this->_admissionYear = year;
	}
public:
	int GetRBNumber() {
		return this->_recordBookNumber;
	}
	int GetAdmissionYear() {
		return this->_admissionYear;
	}

	Student(int rbnumber = 10000, int admyear = 2020, string name = "Bob", string patr = "Bob", string lname = "Bobos") : Person(name, patr, lname) {
		SetRBNumber(rbnumber);
		SetYear(admyear);
	}
};

class Teacher : public Person {
	string _post;

	void SetPost(string post) {
		this->_post = post;
	}

public:
	string GetPost() {
		return this->_post;
	}

	Teacher(string post, string name = "Bob", string patr = "Bob", string lname = "Bobos") : Person(name, patr, lname) {
		SetPost(post);
	}
};