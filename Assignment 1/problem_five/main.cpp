#include "iostream"
#include "StatisticalCalculation.h"
using namespace std;
int main(){
    string fileName;
    cout<<"Enter file name (test_int.txt , test_float.txt , test_double.txt) :";
    cin >> fileName;
    if(fileName == "test_int.txt"){
        StatisticalCalculation<int> statisticalCalculation(1);
        statisticalCalculation.setFileName("test_int.txt");
        statisticalCalculation.inputData();
        statisticalCalculation.statisticsMenu();
    }
    else if(fileName == "test_double.txt"){
        StatisticalCalculation<double> statisticalCalculation(1);
        statisticalCalculation.setFileName("test_double.txt");
        statisticalCalculation.inputData();
        statisticalCalculation.statisticsMenu();
    }
    else if(fileName == "test_float.txt"){
        StatisticalCalculation<float> statisticalCalculation(1);
        statisticalCalculation.setFileName("test_float.txt");
        statisticalCalculation.inputData();
        statisticalCalculation.statisticsMenu();
    }
    return 0;
}
