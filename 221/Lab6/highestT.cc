#include<iostream>


using namespace std;

int highest(int val, const int* start, const int* finish){
    auto beeper = start[2];
    auto mid = *finish;
    auto JUST_finsih = --finish;
    auto starSTART = *start;
    auto STArT = start;
    //while(mid!=val){
    //    if(val>mid) mid = mid + (*finish - mid / 2);
    //    if(val<mid) mid /= 2;
    return 0;
}


int main()
{
    const int DATA_LEN = 9;
    const int data[DATA_LEN] = { 1, 1, 1, 4, 4, 5, 6, 7, 10 };
    auto goopedUp = data + DATA_LEN -1;
    highest(2, data, goopedUp);

    //for (auto search : { 0, 1, 2, 4, 7, 8, 9, 10, 11 }) {
    //    const auto where = highest(search, data, data + DATA_LEN);
    //    cout << "Index of elem: " << search << " is: ";
    //    if (where == nullptr) {
    //        cout << "not found!" << endl;
    //    } else {
    //        cout << (where-data) << endl;
     //   }

    //}
    return 0;

}