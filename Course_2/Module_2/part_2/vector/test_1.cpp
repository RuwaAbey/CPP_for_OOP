#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include "Vec3D.h"
//
//Vec3D vec1; //global scope
int main()
{
    
    Vec3D vec1;
    vec1.x = 10;
    vec1.y = 12;
    vec1.z = 25;

   // std::vector<Vec3D> coords; //gowable data structure

   // coords.push_back(vec1);

    int len = vec1.getLength();
    std::cout << "Length: " << len << std::endl;

    return 0;
}