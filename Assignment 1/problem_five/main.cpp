#include "iostream"
#include "StatisticalCalculation.h"
using namespace std;
int main(){
    StatisticalCalculation<double> statisticalCalculation(1);
    statisticalCalculation.inputData();
    statisticalCalculation.statisticsMenu();
    return 0;
}
