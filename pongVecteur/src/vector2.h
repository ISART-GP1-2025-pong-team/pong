#ifndef __VECTOR2__
#define __VECTOR2__

#include <stdbool.h>

typedef struct vector2_t
{
    float x;
    float y;
}vector2_t;

// create a vector
vector2_t create_vector(float x, float y);

// return a null vector2
vector2_t null_vector();

// return the square magnitude of a vector
float square_magnitude_vector(vector2_t vect);

//return the magnitude of a vector2
float magnitude_vector(vector2_t vect);

// return the normalized vector of a vector2
vector2_t normalized_vector(vector2_t vect);

// return the soustraction of two vectors
vector2_t soustraction_vectors(vector2_t vect1, vector2_t vect2);

// return distance between 2 points
float distance_vectors(vector2_t vect1, vector2_t vect2);

float distance_vectors_square(vector2_t vect1, vector2_t vect2);

// return 1 if vect1 =~ vect2 else return 0
bool epsilon_compare_vectors(vector2_t vect1, vector2_t vect2);

// return the addition of two vectors
vector2_t addition_vectors(vector2_t vect1, vector2_t vect2);

//return the multiplication of a vector and a scalar number
vector2_t scale(vector2_t vect, float scalar);

// return negate vector (vecteur oppose)
vector2_t negate_vector(vector2_t vect);

// return dot product of two vectors
float dot_product(vector2_t vect1, vector2_t vect2);

// return the angle between two vectors (shortest way)
float angle_vector(vector2_t vect1, vector2_t vect2);

#endif
