#ifndef PRAKTIKUM_PEMPLOY_H
#define PRAKTIKUM_PEMPLOY_H
#include <string>
#include <vector>

//methods
void print(const std::string& name, const std::string& firstName, const std::vector<int>& dateOfBirth, const float& salary);
int age(const std::vector<int>& dateOfBirth);
void riseSalary(float& salary,const float& rise);
#endif //PRAKTIKUM_PEMPLOY_H
