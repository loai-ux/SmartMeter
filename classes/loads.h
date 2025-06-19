#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include <string>
#include <sstream>

using namespace std;

class loads
{
private:
    std::string name; 
    double max_current;
    double max_voltage;
    bool stat;
    
public:
    loads(std::string n, double i, double v, bool s);
    loads();
   
    struct load_properties
    {
        double voltage;
        double current;
        double power;
        double frequancy;
        load_properties()
        {

            voltage = 0;
            current = 0;
            power = 0;
            frequancy = 0;
        }
        load_properties(double v, double i, double p, double f)
        {
            voltage = v;
            current = i;
            power = p;
            frequancy = f;
        }
    };
    load_properties myloadproperties;
    
    
    
    void setname(std::string n);
    const std::string getname(); 

    void setcurrent(double i);
    const double getcurrent();
   
    double RMS( vector<double>& s,  vector<double>& t);
    double Peak(vector<double>& s, vector<double>& t);
  
    void setvoltage(const double v);
    const double getvoltage(); 

    
    void setstat(bool s);
    const bool getstat();

 

};
