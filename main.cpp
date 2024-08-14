#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>

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
    string USDcost = "";
};

//Preprocessor functions
lensType getLensData();
void addLensCost(string, lensType &lens);
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

    iFile.open("Lens Data V1.txt");
    if (!iFile.is_open())
    {
        cerr << "Error: File cannot be opened!\n";
        exit(1);
    }

    cout << "Enter lens name: ";
    iFile >> l.lensname;
    cout << "Enter mount type: ";
    iFile >> l.mount_type;
    cout << "Enter brand name: ";
    iFile >> l.brandName;
    cout << "Enter sensor type: ";
    iFile >> l.sensor_type;
    cout << "Enter mm length";
    iFile >> l.mm_lenth;
    cout << "Enter f/t-stop";
    iFile >> l.aperaturestop;

    while (true)
    {
        cout << "Enter a cost";
        iFile >> l.cost;
        /*If incorrect price or string is used,
        return an error with the price*/
        if (iFile.fail() || l.cost < 0)
        {
            iFile.clear();
            iFile.ignore(256, '\n');
            cout << "Invalid price!\n";
        }
        else
        {
            break;
        }
    }

    addLensCost(l);
    iFile.close();
    return l;
}

void getLensName(const string input, lensType &lens)
{
    cout << input;
    iFile >> lens.lensname;
}
void getMountType(const string input, lensType &lens)
{
    cout << input;
    iFile >> lens.mount_type;
}
void getBrandName(const string input, lensType &lens)
{
    cout << input;
    iFile >> lens.brandName;
}
void getSensorType(const string input, lensType &lens)
{
    cout << input;
    iFile >> lens.sensor_type;
}
void get_mm_Length(const string input, lensType &lens)
{
    cout << input;
    iFile >> lens.mm_lenth;
}
void getAperatureStop(const string input, lensType &lens)
{
    cout << input;
    iFile >> lens.aperaturestop;
}

void addLensCost (lensType &lens)
{
    if (lens.cost >= 0 && lens.cost <= 250)
    {
        lens.USDcost = "Cheap";
    }

    else if (lens.cost >= 250.1 && lens.cost <= 1000)
    {
        lens.USDcost = "Moderately Priced";
    }

    else if (lens.cost >= 1000.1 && lens.cost <= 9000)
    {
        lens.USDcost = "Expensive";
    }
}
//Need to rework this with arrays since I want multiple output files. 
void printLensData(const lensType lens)
{
    oFile.open("output.txt");
    if (!oFile.is_open())
    {
        cerr << "Error: Cannot open this file\n";
        return;
    }
    oFile << lens.lensname << lens.mount_type 
    << lens.brandName << lens.sensor_type 
    << lens.mm_lenth << lens.aperaturestop
    << lens.USDcost;
}
