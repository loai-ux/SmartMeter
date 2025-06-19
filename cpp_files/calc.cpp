#include<fstream>
#include<cassert>
#include<string>
#include<sstream>
#include<cmath>
#include<iostream>
#include<vector>
#include"calc.h"
using namespace std;
double energycalc(vector<double>& I, vector<double>& V, vector<double>& T)
{
    double totenergy = 0.0;
    for (size_t i = 1; i < T.size(); i++)
    {
        // Calculate time interval in hours
        double deltaT = (T[i] - T[i - 1]) / (3600.0);  // Time interval in hours (seconds to hours)

        // Calculate power for this interval: P = V * I
        double power = V[i] * I[i];

        // Calculate energy for this interval: E = P * deltaTime
        double energy = power * deltaT * 0.001;

        // Accumulate total energy
        totenergy += energy;
    }

    return totenergy; // Return total energy consumed
}

double calcTaxes(double totenergy,vector<double>& T)
{
    double tax = 0.0;
    double totaltime = T[T.size() - 1] - T[0];
    totenergy = (totenergy/totaltime)*30*60*60*24;
    if (totenergy <= 50) {
        tax = 1;
    }
    else if (totenergy > 50 && totenergy <= 100) {
        tax = 2;
    }
    else if (totenergy > 100 && totenergy <= 200) {
        tax = 6;
    }
    else if (totenergy > 200 && totenergy <= 350) {
        tax = 11;
    }
    else if (totenergy > 350 && totenergy <= 650) {
        tax = 15;
    }
    else if (totenergy > 650 && totenergy <= 1000) {
        tax = 25;
    }
    else if (totenergy > 1000) {
        tax = 40;
    }
    else
        tax = 9;

    return tax;

}

double calculateTariff(double totenergy, vector<double>& T)
{
    double totaltime = T[T.size() - 1] - T[0];
    double s = totaltime / (30 * 60 * 60 * 24);
    double Menergy = (totenergy / totaltime) * 30 * 60 * 60 * 24;
    double tax = calcTaxes(totenergy,T);
    double cost = 0.0;
    if (Menergy <= 50) {
        cost = totenergy * 0.58; // 0–50 kWh tier
    }
    else if (Menergy <= 100) {
        cost = (50 * 0.58 * s) + ((Menergy - 50) * s * 0.68); // 51–100 kWh tier
    }
    else if (Menergy <= 200) {
        cost = totenergy * 0.83; // 101–200 kWh tier
    }
    else if (Menergy <= 350) {
        cost = (200 * 0.83 * s) + ((Menergy - 200) * s * 1.25);
    }
    else if (Menergy <= 650) {
        cost = (200 * 0.83 * s) + (150 * 1.25 * s) + ((Menergy - 350) * s * 1.4);
    }
    else if (Menergy <= 1000) {
        cost = totenergy * 1.5; //651-1000 tier
    }
    else {
        cost = totenergy * 1.65; // Above 1000 kWh
    }

    cost = cost + tax;
    return cost;
}
double PowerCalc(vector <double>& I, vector <double>& V, vector <double>& T) {
    double num = T.size();
    double totaltime = T.at(num - 1) - T.at(0);
    vector<double> power;
    double sump = 0;

    for (int i = 0; i < num; i++) {
        power.push_back(I.at(i) * V.at(i));

    }

    for (int i = 0; i < T.size() - 1; i++) {
        sump += power.at(i) * (T.at(i + 1) - T.at(i));

    }
    double avg_power = sump / totaltime;
    return avg_power;
}



double PowerFactorCalc(vector <double>& I, vector <double>& V, vector <double>& T) {

    //first we need to calculate the the rms value to be able to calculate the appernt power 
    double sumv = 0;
    double sumi = 0;
    for (int i = 0; i < I.size(); i++) {
        sumv = sumv + V.at(i) * V.at(i);
        sumi = sumi + I.at(i) * I.at(i);
    }
    double Vrms = sqrt(sumv / V.size());
    double Irms = sqrt(sumi / I.size());

    double app_power = Vrms * Irms;

    //to calcullate the real power 
    double realpower = PowerCalc(I, V, T);

    //finally , power factor = real power/apperant power
    double powerfactor = realpower / app_power;
    return powerfactor;
}

