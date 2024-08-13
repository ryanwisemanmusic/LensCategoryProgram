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
void printLensData(lensType lens);

int main()
{
    
}

lensType getLensData()
{

}
void printLensData(const lensType lens)
{
    cout << "\nLens Data: ";
}