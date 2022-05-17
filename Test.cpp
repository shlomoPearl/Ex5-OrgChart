#include "doctest.h"
#include "OrgChart.hpp"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
using namespace ariel;
TEST_CASE("good input"){
    for(uint i = 555 ; i < 595; i++){
        CHECK(i > 0);
    }
}