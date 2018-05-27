//
// Created by bagira on 5/26/18.
//

#include "OpenBeardFunc.h"

int BeardDomamaru::calc_followers( long depth, long length, long coverage, long * followers )
{
    try {
        * followers = long( pow( depth, length ) ) * coverage;
        return FUNC_SUCCESS;
    }
    catch ( const std::exception& e ) {
        std::cerr << e.what() << std::endl;
        return FUNC_FAILURE;
    }
};

