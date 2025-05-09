#include <iostream>
#include <string>

template <typename T>
class StatisticalCalculation {
private:
    T* data;
    int size;
    std::string fileName;
public:
    StatisticalCalculation(int size);
    ~StatisticalCalculation();
    void sort();
    T findMedian();
    T findMax();
    T findMin();
    double findMean();
    T findSummation();
    void displayArray();
    void inputData();
    void statisticsMenu();
    void setFileName(const std::string& fileName);
};
