#pragma once
#include <iostream>
#include "Person.h"

using namespace std;

class PersonTools {
public:
	string GetDescription(Person* person) {
		string description;
		description += person->GetLastName() + " ";
		description += person->GetName() + " ";
		description += person->GetPatronymic() + " ";
		return description;
	}
};