#include"cities.hh"

Cities Cities::reorder(const permutation_t& ordering) const{
    Cities city;
    city.cities_ = this->cities_;
    city.currentperm_ = this->currentperm_;
    city.range_ = this->range_;
    std::vector<const unsigned int>::iterator e;
    int i = 0;
    for (e = ordering.cbegin(); e != ordering.cend(); ++e) {
        city.cities_[i] = cities_[ordering[*e]];
        ++i;
    };
    return city;
};



Cities::permutation_t 
random_order(unsigned int range){
    Cities::permutation_t randy(range);
    std::iota(randy.begin(), randy.end(), 1);
    std::random_device generator;
    std::mt19937 rando(generator());
    std::shuffle(randy.begin(),randy.end(),rando);
    return randy;
}



//Helper to detirmine distance between two points
double 
distance_between(const Cities::coord_t one, const Cities::coord_t two) {
    return(hypot((one.second - one.first),(two.second - two.first)));
};


double Cities::total_path_distance(const permutation_t& ordering) const{
    double total;
    Cities::coord_t first;
    Cities::coord_t next;
    std::vector<const unsigned int>::iterator e;
    for (e = ordering.cbegin(); e != ordering.cend()-1; ++e) {
        //if (last index in ordering){};
        first = cities_[*e];
        next = cities_ [ordering[*e+1]];
        total = total + distance_between(first, next);
    }
    first = cities_[*ordering.cbegin()];
    next = cities_[*ordering.cend()];
    total = +distance_between(first, next);
    return total;
};


std::istream &operator>> (std::istream& inS, Cities& city){
    Cities::coord_t coord;
    while (inS.good()){
        inS >> coord.first >>coord.second;
        city.range_++;
        city.cities_.push_back(coord);
    }
    return inS;
}


std::ostream &operator<< (std::ostream& outS, Cities& city){
    for (Cities::coord_t coords : city.cities_) {
        outS << coords.first << "\t"<< coords.second << "\n";
    }
    return outS;
}

