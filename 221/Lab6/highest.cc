#include<iostream>


using namespace std;

const int* highest(int val, const int* start, const int* finish){
    int mid = (finish - start) /2;
    if (mid==val)
        const int* foundIt = &mid;
        return foundIt;
    if(start[mid] < val){
        mid++;
        const int* highest(int val, int mid, const int* finish);
        }
    if (start[mid] > val){
        mid--;
        const int* highest(int val, const int* start, int mid);
        }
}


int main()
{
    const int DATA_LEN = 9;
    const int data[DATA_LEN] = { 1, 1, 1, 4, 4, 5, 6, 7, 10 };

    for (auto search : { 0, 1, 2, 4, 7, 8, 9, 10, 11 }) {
        const auto where = highest(search, data, data + DATA_LEN);
        cout << "Index of elem: " << search << " is: ";
        if (where == nullptr) {
            cout << "not found!" << endl;
        } else {
            cout << (where-data) << endl;
        }

    }
    return 0;

}