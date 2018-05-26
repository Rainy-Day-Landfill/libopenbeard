//
// Created by bagira on 5/26/18.
//

#include "OpenBeardFunc.h"

int BeardDomamaru::calc_followers( int depth, int length, int coverage, int * followers )
{
    try {
        * followers = int( pow( depth, length ) ) * int(  coverage );
        return FUNC_SUCCESS;
    }
    catch ( const std::exception& e ) {
        std::cerr << e.what() << std::endl;
        return FUNC_FAILURE;
    }
};

