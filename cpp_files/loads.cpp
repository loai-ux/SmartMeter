#include "loads.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<cassert>
#include<string>
#include<sstream> 

loads::loads() 
{
    name = "!";
    max_current = 0;
    max_voltage = 0;
    stat = 0;
}

loads:: loads (std::string n, double i, double v, bool s)
{
    
    name = n;
    max_current = i;
    max_voltage = v;
    stat = s;

}
double loads::RMS(vector<double>& s,vector<double>& t)
{
    double sums = 0, Srms;

    for (int j = 0; j < s.size() - 1; ++j)
    {
        sums += s[j] * s[j] * (t[j + 1] - t[j]);
    }

    double totaltime = (t[t.size() - 1] - t[0]);
    Srms = sqrt(sums / totaltime);

    return Srms;
}
double loads::Peak(vector<double>& s, vector<double>& t)
{
    

    double max = s[0];
    for (int j = 0; j < s.size(); ++j)
    {
        if (s[j] > max)
        {
            max = s[j];

        }
    }

    return max;
}

void loads:: setstat(bool s) { stat = s; }
const bool loads::getstat() { return stat; }





void loads::setname (std::string n) 
{ 
    name = n; 
}

const string loads::getname()
{ 
    return name;
}
void loads:: setcurrent(double i) { max_current = i; }
const double loads::getcurrent() { return max_current; }
void loads:: setvoltage(double v) { max_voltage = v; }
const double loads:: getvoltage() { return max_voltage; }



