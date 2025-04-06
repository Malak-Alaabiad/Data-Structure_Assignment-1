#include <iostream>
#include <chrono>
#include <limits>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class SortingSystem
{
private:
    T *data;
    int size;

public:
    SortingSystem(int n);
    ~SortingSystem();
    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void shellSort();
    void mergeSort(int left, int right);
    void quickSort(int left, int right);
    void countSort();
    void radixSort();
    void bucketSort();

    void merge(int left, int mid, int right);
    int partition(int left, int right);

    void displayData();
    void measureSortingTime(void (SortingSystem::*sortfunc)());

    void showMenu();
};
template <typename T>
SortingSystem<T>::SortingSystem(int n)
{
    size = n;
    data = new T[size];
}
template <typename T>
SortingSystem<T>::~SortingSystem()
{
    delete[] data;
}
template <typename T>
void SortingSystem<T>::displayData()
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
template <typename T>
void SortingSystem<T>::insertionSort()
{
    for (int i = 1; i < size; i++)
    {
        T key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
        displayData();
    }
}
template <typename T>
void SortingSystem<T>::selectionSort()
{
    for (int i = 0; i < size - 1; i++)
    {
        int mnIDX = i;
        for (int j = i + 1; j < size; j++)
            if (data[j] < data[mnIDX])
                mnIDX = j;
        if (mnIDX != i)
        {
            T temp = data[i];
            data[i] = data[mnIDX];
            data[mnIDX] = temp;
        }
        displayData();
    }
}
template <typename T>
void SortingSystem<T>::bubbleSort()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
        displayData();
    }
}
template <typename T>
void SortingSystem<T>::shellSort()
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            T temp = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
            {
                data[j] = data[j - gap];
            }
            data[j] = temp;
        }
        displayData();
    }
}
template <typename T>
void SortingSystem<T>::merge(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T *L = new T[n1];
    T *R = new T[n2];

    for (int i = 0; i < n1; i++)
        L[i] = data[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = data[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            data[k] = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        data[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        data[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;

    displayData();
}
template <typename T>
void SortingSystem<T>::mergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}
template <typename T>
int SortingSystem<T>::partition(int left, int right)
{
    T pivot = data[right];
    int i = left - 1;

    cout << "Pivot: " << pivot << " -> ";

    for (int j = left; j < right; j++)
    {
        if (data[j] <= pivot)
        {
            i++;
            T temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    T temp = data[i + 1];
    data[i + 1] = data[right];
    data[right] = temp;

    cout << "[";
    for (int k = left; k <= i; k++)
    {
        cout << data[k];
        if (k < i)
            cout << ", ";
    }
    cout << "] " << pivot << " [";
    for (int k = i + 2; k <= right; k++)
    {
        cout << data[k];
        if (k < right)
            cout << ", ";
    }
    cout << "]" << endl;

    return i + 1;
}
template <typename T>
void SortingSystem<T>::quickSort(int left, int right)
{
    if (left < right)
    {
        int pi = partition(left, right);
        quickSort(left, pi - 1);
        quickSort(pi + 1, right);
    }
}
template <typename T>
void SortingSystem<T>::countSort()
{
    if (typeid(T) != typeid(int))
    {
        cout << "Count Sort is only available for integer data type." << endl;
        return;
    }

    int max = data[0];
    for (int i = 1; i < size; i++)
        if (data[i] > max)
            max = data[i];

    int *count = new int[max + 1]();

    for (int i = 0; i < size; i++)
        count[static_cast<int>(data[i])]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    T *output = new T[size];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[static_cast<int>(data[i])] - 1] = data[i];
        count[static_cast<int>(data[i])]--;
    }

    for (int i = 0; i < size; i++)
        data[i] = output[i];

    delete[] count;
    delete[] output;

    displayData();
}
template <typename T>
void SortingSystem<T>::radixSort()
{
    if (typeid(T) != typeid(int))
    {
        cout << "Radix Sort is only available for integer data type." << endl;
        return;
    }

    int max = data[0];
    for (int i = 1; i < size; i++)
        if (data[i] > max)
            max = data[i];

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        int *count = new int[10]();

        for (int i = 0; i < size; i++)
            count[(static_cast<int>(data[i]) / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        T *output = new T[size];

        for (int i = size - 1; i >= 0; i--)
        {
            output[count[(static_cast<int>(data[i]) / exp) % 10] - 1] = data[i];
            count[(static_cast<int>(data[i]) / exp) % 10]--;
        }

        for (int i = 0; i < size; i++)
        {
            data[i] = output[i];
        }

        delete[] count;
        delete[] output;

        displayData();
    }
}

template <typename T>
void SortingSystem<T>::bucketSort()
{
    if (typeid(T) != typeid(int) && typeid(T) != typeid(float) && typeid(T) != typeid(double))
    {
        cout << "Bucket Sort is optimized for numeric data types." << endl;
        return;
    }

    T mn = data[0];
    T mx = data[0];
    for (int i = 1; i < size; i++)
    {
        if (data[i] < mn)
            mn = data[i];
        if (data[i] > mx)
            mx = data[i];
    }

    vector<T> *buckets = new vector<T>[size];

    for (int i = 0; i < size; i++)
    {
        int idx = (int)((data[i] - mn) * (size - 1) / (mx - mn));
        if (idx >= size)
            idx = size - 1;
        buckets[idx].push_back(data[i]);
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < buckets[i].size(); j++)
        {
            T key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    int index = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < buckets[i].size(); j++)
            data[index++] = buckets[i][j];

    delete[] buckets;

    displayData();
}

template <typename T>
void SortingSystem<T>::measureSortingTime(void (SortingSystem::*sortfunc)())
{

    auto start = chrono::high_resolution_clock::now();
    (this->*sortfunc)();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Sorting Time: " << diff.count() << " seconds" << endl;
}
template <typename T>
void SortingSystem<T>::showMenu()
{
    for (int i = 0; i < size; i++)
    {
        cin >> data[i];
    }

    cout << "Initial Data: ";
    displayData();
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Sorting using Insertion Sort..." << endl;
        measureSortingTime(&SortingSystem<T>::insertionSort);
        break;
    case 2:
        cout << "Sorting using Selection Sort..." << endl;
        measureSortingTime(&SortingSystem<T>::selectionSort);
        break;
    case 3:
        cout << "Sorting using Bubble Sort..." << endl;
        measureSortingTime(&SortingSystem<T>::bubbleSort);
        break;
    case 4:
        cout << "Sorting using Shell Sort..." << endl;
        measureSortingTime(&SortingSystem<T>::shellSort);
        break;
    case 5:
        cout << "Sorting using Merge Sort..." << endl;
        mergeSort(0, size - 1);
        break;
    case 6:
        cout << "Sorting using Quick Sort..." << endl;
        quickSort(0, size - 1);
        break;
    case 7:
        if (typeid(T) == typeid(int))
        {
            cout << "Sorting using Count Sort..." << endl;
            measureSortingTime(&SortingSystem<T>::countSort);
        }
        else
        {
            cout << "Count Sort is only available for integer data type." << endl;
        }
        break;
    case 8:
        if (typeid(T) == typeid(int))
        {
            cout << "Sorting using Radix Sort..." << endl;
            measureSortingTime(&SortingSystem<T>::radixSort);
        }
        else
        {
            cout << "Radix Sort is only available for integer data type." << endl;
        }
        break;
    case 9:
        cout << "Sorting using Bucket Sort..." << endl;
        measureSortingTime(&SortingSystem<T>::bucketSort);
        break;
    default:
        cout << "Invalid choice!" << endl;
        return;
    }

    cout << "Data: ";
    displayData();
}

template <>
void SortingSystem<string>::showMenu()
{
    cout << "Enter " << size << " strings:" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < size; i++)
    {
        cout << "Enter data " << (i + 1) << ": ";
        getline(cin, data[i]);
    }

    cout << "Initial Data: ";
    displayData();

    cout << "Select a sorting algorithm:" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Bubble Sort" << endl;
    cout << "4. Shell Sort" << endl;
    cout << "5. Merge Sort" << endl;
    cout << "6. Quick Sort" << endl;
    cout << "7. Count Sort (Only for integers)" << endl;
    cout << "8. Radix Sort (Only for integers)" << endl;
    cout << "9. Bucket Sort (Not available for strings)" << endl;
    cout << "Enter your choice (1-9): ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Sorting using Insertion Sort..." << endl;
        measureSortingTime(&SortingSystem<string>::insertionSort);
        break;
    case 2:
        cout << "Sorting using Selection Sort..." << endl;
        measureSortingTime(&SortingSystem<string>::selectionSort);
        break;
    case 3:
        cout << "Sorting using Bubble Sort..." << endl;
        measureSortingTime(&SortingSystem<string>::bubbleSort);
        break;
    case 4:
        cout << "Sorting using Shell Sort..." << endl;
        measureSortingTime(&SortingSystem<string>::shellSort);
        break;
    case 5:
        cout << "Sorting using Merge Sort..." << endl;
        mergeSort(0, size - 1);
        break;
    case 6:
        cout << "Sorting using Quick Sort..." << endl;
        quickSort(0, size - 1);
        break;
    case 7:
    case 8:
        cout << "Count Sort and Radix Sort are only available for integer data type." << endl;
        break;
    case 9:
        cout << "Bucket Sort is not available for string data type." << endl;
        cout << "Please use another sorting algorithm like Merge Sort or Quick Sort." << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        return;
    }

    cout << "Data: ";
    displayData();
}

int main()
{
    cout << "Input format:\n"
         << "1 - first line takes the name of the file\n"
         << "2 - then enter the data type (i for int, f for float, d for double, s for string)\n"
         << "3 - then enter the number of items to sort\n"
         << "4 - then enter the items to sort\n"
         << "5 - then enter the sorting algorithm (1-9)\n"
         << "6 - enter y or n to sort another dataset start from step 1\n"
         << "Output in the file output.txt\n";
    cout << "Select a sorting algorithm: in step 5" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Bubble Sort" << endl;
    cout << "4. Shell Sort" << endl;
    cout << "5. Merge Sort" << endl;
    cout << "6. Quick Sort" << endl;
    cout << "7. Count Sort (Only for integers)" << endl;
    cout << "8. Radix Sort (Only for integers)" << endl;
    cout << "9. Bucket Sort" << endl;

    string s;
    cout << "enter the name of the file : ";
    cin >> s;
    freopen(s.c_str(), "r", stdin);
    freopen("output.txt", "w", stdout);
    while (1)
    {
        char dataType;
        cin >> dataType;
        int size;
        cin >> size;
        if (dataType == 'i')
        {
            SortingSystem<int> s(size);
            s.showMenu();
        }
        else if (dataType == 'f')
        {
            SortingSystem<float> s(size);
            s.showMenu();
        }
        else if (dataType == 'd')
        {
            SortingSystem<double> s(size);
            s.showMenu();
        }
        else if (dataType == 's')
        {
            SortingSystem<string> s(size);
            s.showMenu();
        }
        else
        {
            cout << "Invalid data type!" << endl;
            return 1;
        }
        char again;
        cin >> again;
        if (again != 'y' && again != 'Y')
        {
            cout << "Thank you for using the sorting system! Goodbye!" << endl;
            break;
        }
    }
    return 0;
}