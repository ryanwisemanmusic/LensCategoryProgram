#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream iFile;
ofstream oFile;
//Lens Details contained in struct
struct lensType
{
    string lens;
    string lensname = "", mount_type = "", brandName = "", 
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
    lensType lens = getLensData();
    printLensData(lens);
    return 0;
}

lensType getLensData()
{
    lensType l;
    cout << "Enter lens name: ";
    cin >> l.lensname;
    cout << "Enter mount type: ";
    cin >> l.mount_type;
    cout << "Enter brand name: ";
    cin >> l.brandName;
    cout << "Enter sensor type: ";
    cin >> l.sensor_type;
    cout << "Enter mm length";
    cin >> l.mm_lenth;
    cout << "Enter f/t-stop";
    cin >> l.aperaturestop;

    while (true)
    {
        cout << "Enter a cost";
        cin >> l.cost;
        /*If incorrect price or string is used,
        return an error with the price*/
        if (cin.fail() || l.cost < 0 || !l.cost)
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid price!";
        }
        
    }
    
}

void getLensName(const string input, lensType &lens)
{
    cout << input;
    cin >> lens.lensname;
}
void getMountType(const string input, lensType &lens)
{
    cout << input;
    cin >> lens.mount_type;
}
void getBrandName(const string input, lensType &lens)
{
    cout << input;
    cin >> lens.brandName;
}
void getSensorType(const string input, lensType &lens)
{
    cout << input;
    cin >> lens.sensor_type;
}
void get_mm_Length(const string input, lensType &lens)
{
    cout << input;
    cin >> lens.mm_lenth;
}
void getAperatureStop(const string input, lensType &lens)
{
    cout << input;
    cin >> lens.aperaturestop;
}

//Need to rework this with arrays since I want multiple output files. 
void printLensData(const lensType lens)
{
    getLensName, getMountType, getBrandName,
    getSensorType, get_mm_Length, getAperatureStop;
    oFile << "output.txt";
}
