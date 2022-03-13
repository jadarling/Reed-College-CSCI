#include<iostream>


using namespace std;

const int* highest(int val, const int* start, const int* finish){
    auto beeper = start;
    auto mid = *finish;
    mid /= 2;
    while(mid!=val){
        if(val>mid) mid = mid + (*finish - mid / 2);
        if(val<mid) mid /= 2;





    }
    return 0;
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