#include <cstdio>
#include <ctime>
#include <string>
#include <vector>
#include <bits/locale_classes.h>

void print(const std::string& name, const std::string& firstName, const std::vector<int>& dateOfBirth, const float& salary) {
//durch const da oben können die variablen nicht geändert werden, read only
    printf("Name:\t\t%s\n",name.c_str());
    printf("First Name:\t%s\n",firstName.c_str());
    printf("Date of Birth:\t%02d.%02d.%4d\n",dateOfBirth[2],dateOfBirth[1],dateOfBirth[0]);
    printf("Salary:\t\t%.2f\n",salary);
}

int age(const std::vector<int>& dateOfBirth) {
    time_t now = time(nullptr);
    tm* t = localtime(&now);
    int year = t->tm_year + 1900;
    int month = t->tm_mon + 1;
    int day = t->tm_mday;
    int age = (year - dateOfBirth[0]);
    if (month<dateOfBirth[1]) {
        age = age - 1;
    }
    if (month==dateOfBirth[1]) {
        if (day<dateOfBirth[2]) {
        age = age -1;
        }
    }
    return age;
}

void riseSalary(float& salary,const float& rise) {//erhöhung in prozen
    salary = salary + salary * (rise/100);
}


int main() {
    std::string name = "Duster";
    std::string firstName = "Jeff";
    std::vector<int> dateOfBirth = {2002,12,24};//year month day
    float salary = 2500;
    print(name,firstName,dateOfBirth,salary);
    printf("Alter:\t\t%d\n",age(dateOfBirth));
    riseSalary(salary,0);//erhöhung in prozent
    print(name,firstName,dateOfBirth,salary);
    return 0;
}
