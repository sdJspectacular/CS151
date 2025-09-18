// CS151 Fall 2025
// HW1 Project 2: Use a vector to sort planets
// Jack Marriott
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "Planet.h"

using namespace std;

int main()
{
    vector<string> names = {"Ceres", "Earth", "Eris", "Haumea",
        "Jupiter", "Makemake", "Mars", "Mercury",
        "Neptune", "Pluto", "Saturn", "Uranus", "Venus"};

    vector<int> diams = {952, 12756, 2321, 1220,
        142796, 1475, 6787, 4878, 48600, 2302,
        120660, 51118, 12104};
    
    
    vector<long long> orbits = {413700000LL, 149600000LL, 10125000000LL, 6452000000LL,
        778300000LL, 6850000000LL, 227900000LL, 57900000LL, 4497000000LL, 589100000LL,
        1427000000LL, 2831000000LL, 108200000LL};

    // List of ordered planets
    vector<Planet> planets;
    vector<Planet>::iterator it;

    // Add first planet
    planets.push_back(Planet(names[0], diams[0], orbits[0]));
    
    // Add remaining planets in ascending orbit
    for (int i = 1; i < names.size(); ++i)
    {
        it = planets.begin();
        bool added = false;
        while (it < planets.end())
        {
            if (orbits[i] <= it->getDistance())
            {
                planets.insert(it, Planet(names[i], diams[i], orbits[i]));
                added = true;
                break;
            }
            ++it;
        }
        if (!added)
            planets.insert(it, Planet(names[i], diams[i], orbits[i]));
    }

    cout << left << setw(8) << "Planet" << " ";
    cout << right << setw(10) << "Diameter" << " ";
    cout << right << setw(10) << "Orbit";
    cout << "\n";
    cout << left << setw(8) << "Name" << " ";
    cout << right << setw(10) << "[km/1e3]" << " ";
    cout << right << setw(10) << "[km/1e6]";
    cout << "\n";
    cout << left << setw(8) << "--------" << " ";
    cout << right << setw(10) << "-------" << " ";
    cout << right << setw(10) << "--------";
    cout << "\n";

    it = planets.begin();
    double totDiam = 0.0, totOrbit = 0.0;
    double diam, orbit;

    while (it < planets.end())
    {
        diam = it->getDiameter()/1e3;totDiam += diam;
        orbit = it->getDistance()/1e6;totOrbit += orbit;
        cout << fixed;
        cout << left << setw(8) << it->getName() << " ";
        cout << right << setw(10) << setprecision(3) << diam << " ";
        cout << right << setw(10) << setprecision(1) << orbit << "\n";
        ++it;
    }
    cout << left << setw(8) << "--------" << " ";
    cout << right << setw(10) << "-------" << " ";
    cout << right << setw(10) << "--------";
    cout << "\n";

    cout << left << setw(8) << "Totals" << " ";
    cout << right << setw(10) << totDiam << " ";
    cout << right << setw(10) << totOrbit;
    cout << "\n";

    cout << "\n\n";

    return 0;
}
