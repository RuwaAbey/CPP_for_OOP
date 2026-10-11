#include <vector>
#include <string>
#include <iostream>

//3D vector

int x1,y1,z1; //global data
int x2,y2,z2; //global data

class Vec3D
{
    public:
        int x;
        int y;
        int z;

};

//Vec3D vec1; //global scope
int main()
{
    
    Vec3D vec1;
    vec1.x = 10;
    vec1.y = 12;
    vec1.z = 25;

    std::vector<Vec3D> coords; //gowable data structure

    coords.push_back(vec1);

    return 0;
}