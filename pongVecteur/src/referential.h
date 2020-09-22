#pragma once

#include "vector2.h"

typedef struct referential_t
{
    vector2_t origin;
    vector2_t unitI;
    vector2_t unitJ;

}referential_t;

referential_t create_referantial(float originX, float originY, float jX, float jY, float iX, float iY);

referential_t local_to_global(referential_t* referential)

//void destroy_referantial(referential_t* referantial);