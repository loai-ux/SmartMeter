#include<fstream>
#include<cassert>
#include<string>
#include<sstream>
#include<cmath>
#include<iostream>
#include<vector>
#include"alarm.h"
using namespace std;

vector<double> periodic_time_before_filter(vector <double>& S, vector <double>& T)
{
    vector <double>peak_time;
    vector <double> periodic_time;
    for (int i = 1; i < (T.size() - 1); i++)
    {
        if (S[i] > S[i - 1] && S[i] > S[i + 1])
            peak_time.push_back(T[i]);
    }
    for (int j = 0; j < (peak_time.size() - 1); j++)
    {
        periodic_time.push_back(peak_time[j + 1] - peak_time[j]);

    }
    return periodic_time;
}

string monitor_alarm(double max_current, double max_voltage, double limited_time, vector <double>& I, vector <double>& V, vector <double>& T)
{
    std::ostringstream oss;
    vector <double> periodic_time_i = periodic_time_before_filter(I, T);
    vector <double> periodic_time_v = periodic_time_before_filter(V, T);
    double sumv = 0, sumi = 0;
   
   
    double max_frequency = 50.5;
    double mini_frequency = 49.5;
    

    
    for (int i = 0; i < I.size(); ++i)
    {

        if (I[i] > max_current)
        {
            for (int j = i + 1; j < I.size(); j++)
            {
                if (I[j] > max_current)
                {
                    sumi += T[j] - T[j - 1];
                    if (sumi > limited_time)
                        oss << "warning: the current exceeded the maximum allowed current for more than the allowed time  " << endl;
                    break;
                }

            }

            break;
        }
    }
    for (int i = 0; i < V.size(); ++i)
        if (V[i] > max_voltage)
        {
            for (int j = i + 1; j < V.size(); j++)
            {
                if (V[j] > max_voltage)
                {
                    sumv += T[j] - T[j - 1];
                    if (sumv > limited_time)
                        oss << "warning: the voltage exceeded the maximum allowed voltage  for more than the allowed time  " << endl;
                    break;
                }

            }

            break;
           
        }

    for (int i = 0; i < periodic_time_v.size(); i++)
    {
        if (((1 / periodic_time_v[i]) > max_frequency) || ((1 / periodic_time_v[i]) < mini_frequency))

            oss << " warning: the frequency of voltage bypassed the limited frequency" << endl;
        break;
    }

    for (int i = 0; i < periodic_time_i.size(); i++)
    {

        if (((1 / periodic_time_i[i]) > max_frequency) || ((1 / periodic_time_i[i]) < mini_frequency))
            oss << "warning: the frequency of current bypassed the limited frequency " << endl;
        break;
    }
    return oss.str();
}

double periodic_time_after_filter(vector<double>& S, vector<double>& T)
{
    vector<double> peaktime_s;
    for (int i = 1; i < S.size() - 1; i++)
    {
        if ((S[i] > S[i - 1]) && (S[i] > S[i + 1])) {
            peaktime_s.push_back(T[i]);
        }
    }
    double periodic_time = peaktime_s[4] - peaktime_s[3];
    return periodic_time;
}


void Low_pass_filter(vector<double>& I, vector<double>& V, vector<double>& T)
{
    vector<double> Filtered_Volt;
    vector<double> Filtered_I;

    const double cutoff_angular_frequency = 2 * 3.14 * 50.0;
    double Tsampling = T[2] - T[1];

    Filtered_Volt.resize(V.size());
    Filtered_I.resize(V.size());
    Filtered_Volt[0] = V[0];
    Filtered_I[0] = I[0];

    for (int i = 0; i < V.size() - 1; i++)
    {
        Filtered_Volt[i + 1] = (Filtered_Volt[i] + (cutoff_angular_frequency * Tsampling * V[i + 1])) / (1 + (cutoff_angular_frequency * Tsampling));
        Filtered_I[i + 1] = (Filtered_I[i] + (cutoff_angular_frequency * Tsampling * I[i + 1])) / (1 + (cutoff_angular_frequency * Tsampling));
    }
    V = Filtered_Volt;
    I = Filtered_I;

}
