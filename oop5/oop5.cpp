#include <iostream>
#include "StudentTeacher.h"
#include "PersonTools.h"
#include "Refactor.h"
#include "Discount.h"
using namespace std;

void DemoPerson() {
    Student* stud = new Student(10001, 2021);
    string descr;
    PersonTools* tools = new PersonTools();
    cout << tools->GetDescription(stud);
    delete stud; delete tools;
}

void DemoUser() {
    User** users = new User * []
    {
        new User(100000, "morkovka1995", "1995morkovka"),
            new User(100001, "ilon_mask", "X æ A-12"),
            new User(100002, "megazver", "password"),
            new User(100003, "yogurt", "ksTPQzSu"),
    };
    User** paidUsers = new User * []
    {
        new PaidUser(200000, "TheKnyazz", "JHPzPGFG"),
            new PaidUser(200001, "system_exe", "UgfkDGmU"),
            new PaidUser(200002, "RazorQ", "TBgRnbCP"),
            new PaidUser(200003, "schdub", "CetyQVID"),
    };
    string login = "megazver";
    string password = "password";
    User* loginedUser = Login(users, 4, login, password);
    cout << "Signed in as: " << loginedUser->GetLogin() << endl;
    login = "system_exe";
    password = "UgfkDGmU";
    User* loginedPaidUser = Login(paidUsers, 4, login, password);
    cout << "Signed in as: " << loginedPaidUser->GetLogin() << endl;
    for (int i = 0; i < 4; i++)
    {
        delete users[i];
    }
    delete[] users;
    for (int i = 0; i < 4; i++)
    {
        delete paidUsers[i];
    }
    delete[] paidUsers;
}

void DemoDiscount() {
    Product pr1 = Product();
    Product pr2 = Product(TV, "TV LG49N000", 40000);
    Product pr3 = Product(Phone, "Huawei", 25000);
    Product pr4 = Product(Laptop, "Apple", 90000);
    PercentDiscount percDisc = PercentDiscount(Phone, 50);
    CerteficateDiscount certDisc = CerteficateDiscount(TV, 5000);
    Product* arr = new Product [4];
    arr[0] = pr1; arr[1] = pr2; arr[2] = pr3; arr[3] = pr4;
    ShowCheckWithDiscount(&percDisc, arr, 4);
    cout << endl << endl << " Amount of discount in certeficate: " << certDisc.GetAmount() << endl << endl;
    ShowCheckWithDiscount(&certDisc, arr, 4);
    cout << endl << endl << " Amount of discount in certeficate: " << certDisc.GetAmount();
}

int main()
{
    //DemoPerson();
    //DemoUser();
    DemoDiscount();
}
