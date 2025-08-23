// CS151 Fall 2025
// HW1 Project 2: Use a vector to sort planets
// Jack Marriott
#include "Planet.h"

Planet::Planet(const string name, int diameter, long long distance)
{
    this->name = name;
    this->diameter = diameter;
    this->distance = distance;
}

// getters
string Planet::getName() const
{
    return this->name;
}

long long Planet::getDistance() const
{
    return this->distance;
}

int Planet::getDiameter() const
{
    return this->diameter;
}

// setters
void Planet::setName(const string& name)
{
    this->name = name;
}

void Planet::setDistance(int distance)
{
    this->distance = distance;
}

void Planet::setDiameter(long int diameter)
{
    this->diameter = diameter;
}
