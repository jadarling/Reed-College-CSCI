#include"cities.hh"

extern Cities::permutation_t random_order(unsigned int);
int main(){
    unsigned int iterations = 10000;
    std::ifstream fin = std::ifstream("five.tsv");
    std::ofstream end = std::ofstream("shortest.tsv");
    //std::ofstream shortest = std::ofstream("shorest.tsv");
    Cities acity;
    fin >> acity;

    acity.currentperm_.resize(acity.range_);
    std::iota(acity.currentperm_.begin(),acity.currentperm_.end(),1);
    int i = 1;
    double shortest = acity.total_path_distance(acity.currentperm_) + 1;
    while (i != iterations){
        double tmp = acity.total_path_distance(acity.currentperm_);
        if (tmp < shortest){
            shortest = tmp; 
            std::cout << i << " " << shortest <<"\n";
            acity= acity.reorder(acity.currentperm_);}
        acity.currentperm_ = random_order(acity.range_);
        i++;};

    end << shortest;
    return 0;
};