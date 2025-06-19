#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<cassert>
#include<string>
#include<sstream> 
using namespace std;
double energycalc(vector<double>& I, vector<double>& V, vector<double>& T);
double calculateTariff(double totenergy, vector<double>& T);
double calcTaxes(double totenergy, vector<double>& T);
double PowerCalc(vector <double>& I, vector <double>& V, vector <double>& T);
double PowerFactorCalc(vector <double>& I, vector <double>& V, vector <double>& T);
