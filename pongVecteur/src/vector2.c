#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "vector2.h"

// create a vector
vector2_t create_vector(float x, float y)
{
    vector2_t vect;

    vect.x = x;
    vect.y = y;

    return vect;
}

// return a null vector2
vector2_t null_vector()
{
    return create_vector(0, 0);
}

// return the square magnitude of a vector
float square_magnitude_vector(vector2_t vect)
{
    return vect.x * vect.x + vect.y * vect.y;
}

//return the magnitude of a vector2
float magnitude_vector(vector2_t vect)
{
    return sqrt(square_magnitude_vector(vect));
}

// return the normalized vector of a vector2
vector2_t normalized_vector(vector2_t vect)
{
    float mag = magnitude_vector(vect);
    
    if (mag == 0)
        return null_vector();

    return create_vector(vect.x / mag, vect.y / mag); 
}

// return the soustraction of two vectors
vector2_t soustraction_vectors(vector2_t vect1, vector2_t vect2)
{
    vector2_t vect;
    vect.x = vect2.x - vect1.x;
    vect.y = vect2.y - vect1.y;

    return vect;
}

// return distance between 2 points
float distance_vectors(vector2_t vect1, vector2_t vect2)
{
    vector2_t vect = soustraction_vectors(vect1, vect2);

    return magnitude_vector(vect);
}

float distance_vectors_square(vector2_t vect1, vector2_t vect2)
{
    vector2_t vect = soustraction_vectors(vect1, vect2);

    return square_magnitude_vector(vect);
}

// return 1 if vect1 =~ vect2 else return 0
bool epsilon_compare_vectors(vector2_t vect1, vector2_t vect2)
{
    float epsilon = 0.001;

    if (distance_vectors(vect1, vect2) > epsilon)
        return false;

    return true;
}

// return the addition of two vectors
vector2_t addition_vectors(vector2_t vect1, vector2_t vect2)
{
    vector2_t vect;
    vect.x = vect1.x + vect2.x;
    vect.y = vect1.y + vect2.y;

    return vect;
}

//return the multiplication of a vector and a scalar number
vector2_t scale(vector2_t vect, float scalar)
{
    vect.x *= scalar;
    vect.y *= scalar;

    return vect;
}

// return negate vector (vecteur oppose)
vector2_t negate_vector(vector2_t vect)
{
    vect.x *= -1.f;
    vect.y *= -1.f;

    return vect;
}

// return dot product of two vectors
float dot_product(vector2_t vect1, vector2_t vect2)
{
    return vect1.x * vect2.x + vect1.y * vect2.y;
}

// return the angle between two vectors in radians (shortest way)
float angle_vector(vector2_t vect1, vector2_t vect2)
{
    float magVect = magnitude_vector(vect1) * magnitude_vector(vect2);

    if (magVect == 0)
        return 0;

    return acos(dot_product(vect1, vect2) / magVect); 
}