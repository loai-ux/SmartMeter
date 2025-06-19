#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<cassert>
#include<string>
#include<sstream> 
using namespace std;
extern vector<double>current, voltage, timevec;

void readfile(string file1, vector<double>& I, vector<double>& V, vector<double>& T);
void outputdata(string of,double p, double pf, double cf,double vf, double e, double ec);

