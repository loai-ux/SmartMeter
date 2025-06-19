#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<cassert>
#include<string>
#include<sstream> 
using namespace std;
void Low_pass_filter(vector<double>& I, vector<double>& V, vector<double>& T);
string monitor_alarm(double max_current, double max_voltage, double limited_time, vector <double>& I, vector <double>& V, vector <double>& T);
vector<double> periodic_time_before_filter(vector <double>& S, vector <double>& T);
double periodic_time_after_filter(vector<double>& S, vector<double>& T);