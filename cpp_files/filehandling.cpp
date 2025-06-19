#include<iostream>
#include<vector>
#include<fstream>
#include<cassert>
#include<string>
#include<sstream>
#include<cmath>
#include"filehandling.h"
using namespace std;


vector<double>current, voltage, timevec;

void readfile(string file1, vector<double>& i, vector<double>& v, vector<double>& t)

{
    i.clear(); v.clear(); t.clear();
    string line;
    double time, current, volt;

    // Reading first file
    ifstream fin;
    fin.open(file1);
    assert(fin.is_open());

    while (getline(fin, line))
    {
        stringstream ss(line);
        string temp;
        getline(ss, temp, ',');
        time = stod(temp);
        getline(ss, temp, ',');
        volt = stod(temp);
        getline(ss, temp, ',');
        current = stod(temp);
        t.push_back(time);
        v.push_back(volt);
        i.push_back(current);
    }
    fin.close();
}

void outputdata(string of, double p, double pf, double cf,double vf, double e, double ec)
{
    ofstream fout;
    fout.open(of);
    assert(fout.is_open());
    fout << "power ,power_factor ,current_frequency ,volt_frequency ,energy ,energy_cost\n";
    fout << p << "," << pf << "," << cf << "," <<vf<<"," << e << "," << ec << endl;
    fout.close();
}


