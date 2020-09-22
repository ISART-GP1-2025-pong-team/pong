#include <stdio.h>
#include <stdlib.h>

#include "referential.h"

referential_t create_referantial(float originX, float originY, float iX, float jY)
{
    referential_t referantial;

    referantial.origin = create_vector(originX, originY);
    referantial.unitI = create_vector(iX, originY);
    referantial.unitJ = create_vector(originX, jY);
    
    return referantial;
}
/*
referential_t local_to_global(referential_t* referential)
{
    referential_t globRef;
    
    return globRef;
}*/