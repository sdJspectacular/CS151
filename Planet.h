// CS151 Fall 2025
// HW1 Project 2: Use a vector to sort planets
// Jack Marriott
#ifndef _PLANET_H_
#define _PLANET_H_

#include <string>

using namespace std;

class Planet
{
private:
    string name;
    int diameter;
    long long distance;

public:
    // default constructor 
    Planet(): name(""), distance(0), diameter(0) {}
    
    // constructor 
    Planet(const string name, int diameter, long long distance);

    // getters
    string getName() const;
    int getDiameter() const;
    long long getDistance() const;

    // setters
    void setName(const string& name);
    void setDistance(int distance);
    void setDiameter(long int diameter);
};

#endif // _PLANET_H_
