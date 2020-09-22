#include <math.h>
#include <stdio.h>

#include "intersection.h"

bool circle_line_intersect (circle2_t circle, line2_t line)
{
    float distanceSquareFromCircle = abs(dot_product((vector2_t){-line.dir.y, line.dir.x}, soustraction_vectors(line.pt, circle.center)));

    return (distanceSquareFromCircle <= (circle.radius * circle.radius));
}

bool circle_segment_intersect(circle2_t circle, segment2_t segment)
{
    vector2_t normalizedVect = normalized_vector(soustraction_vectors(segment.pt2, segment.pt1));

    //printf("test 1 !!\n");
    
    if(!circle_line_intersect(circle, (line2_t){segment.pt1, normalizedVect}))
        return false;
    
    //printf("test 2 !!\n");

    if (distance_vectors_square(segment.pt1, circle.center) <= (circle.radius * circle.radius) ||
        distance_vectors_square(segment.pt2, circle.center) <= (circle.radius * circle.radius))
        return true;

    //printf("test 3 !!\n");
    
    vector2_t projectCenter = create_vector(dot_product(normalizedVect, soustraction_vectors(segment.pt1, circle.center)), 
                                            dot_product((vector2_t){-normalizedVect.y, normalizedVect.x}, soustraction_vectors(segment.pt1, circle.center)));
    
    //printf("test 4 !!\n");
    
    float distPt = dot_product(projectCenter, soustraction_vectors(segment.pt2, segment.pt1));
    float test = square_magnitude_vector(soustraction_vectors(segment.pt2, segment.pt1));
    
    printf("distPt = %f, squareMag = %f\n", distPt, test);

    return (distPt >= 0 && distPt <= square_magnitude_vector(soustraction_vectors(segment.pt2, segment.pt1)));
}