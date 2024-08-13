#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

//Lens Details contained in struct
struct lensType
{
    string lens;
    string mount_type = "", brandName = "", 
    sensor_type = "", mm_lenth = "", 
    aperaturestop = ""; 
    double cost;
    char USDcost = '\0';
};

//Preprocessor functions
lensType getLensData();
void getLensName(string, lensType &);
void getMountType(string, lensType &);
void getBrandName (string, lensType &);
void getSensorType(string, lensType &);
void get_mm_Length(string, lensType &);
void getAperatureStop(string, lensType &);
void printLensData(lensType lens);

int main()
{
    
}

lensType getLensData()
{

}

void getLensName()
{

}
void printLensData(const lensType lens)
{
    cout << "\nLens Data: ";
}