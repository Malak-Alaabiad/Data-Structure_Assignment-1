#include "StatisticalCalculation.h"
#include <iostream>
#include <fstream>
using namespace std;
template <typename T>

StatisticalCalculation<T>::StatisticalCalculation(int size)
{
this->size = size;
data = new T[size];
}
template <typename T>

StatisticalCalculation<T>::~StatisticalCalculation(){
    delete[] data;
}
template <typename T>

void StatisticalCalculation<T>:: sort(){
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                // Swap elements
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
template <typename T>

T StatisticalCalculation<T>:: findMedian(){
sort();
if(size%2 ==0){
    return (data[size/2-1] + data[size/2])/2.0;
}
else{
    return data[size/2];
}
}
template <typename T>

T StatisticalCalculation<T>::findMax(){
    T max = data[0];
    for(int i=1; i<size; i++){
        if(data[i] > max)
            max = data[i];
    }
    return max;
}
template <typename T>

T StatisticalCalculation<T>::findMin(){
    T min = data[0];
    for(int i=1; i<size; i++){
        if(data[i] < min)
            min = data[i];
    }
    return min;
}
template <typename T>
double StatisticalCalculation<T>::findMean(){
    T sum = findSummation();
return static_cast<double>(sum) / size;
}
template <typename T>

T StatisticalCalculation<T>::findSummation(){
T sum = 0;
for(int i=0; i<size; i++){
    sum += data[i];
}
return sum;
}
template <typename T>

void StatisticalCalculation<T>::displayArray(){
    for (int i = 0; i < size; i++) {
        cout<< data[i]<< " ";
    }
    cout << endl;
}
template <typename T>

void StatisticalCalculation<T>::inputData()
{
    string filename = "test.txt";
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    inputFile >> size;

    if (data != nullptr) {
        delete[] data;
    }
    data = new T[size];

    for (int i = 0; i < size; i++) {
        if (inputFile.eof()) {
            cerr << "Error: Not enough elements in the file" << endl;
            break;
        }
        inputFile >> data[i];
        cout << "Read element " << i + 1 << ": " << data[i] << endl;
    }

    inputFile.close();
    cout << "Successfully read " << size << " elements from " << filename << endl;
}
template <typename T>
void StatisticalCalculation<T>::statisticsMenu(){
    int userChoice;
    bool menu = false;
    while(!menu){
        cout<<"Select a statistical calculation:"<<endl;
        cout<<"1. Find Median"<<endl;
        cout<<"2. Find Minimum"<<endl;
        cout<<"3. Find Maximum"<<endl;
        cout<<"4. Find Mean"<<endl;
        cout<<"5. Find Summation"<<endl;
        cout<<"6. Display Array"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice (1-7):"<<endl;
        cin>>userChoice;
    switch(userChoice){
        case 1:
            cout<<"Median: "<<findMedian()<<endl;
            break;
        case 2:
            cout<<"Minimum: "<<findMin()<<endl;
            break;
        case 3:
            cout<<"Maximum: "<<findMax()<<endl;
            break;
        case 4:
            cout<<"Mean: "<<findMean()<<endl;
            break;
        case 5:
            cout<<"Summation: "<<findSummation()<<endl;
            break;
        case 6:
            cout<<"Array elements: ";
            displayArray();
            break;
        case 7:
            cout<<"Exiting the program."<<endl;
            menu = true;
            break;
        default:
            cout<<"Invalid choice. Please try again."<<endl;
            continue; 
        }
        menu = true; 
    }
    }


