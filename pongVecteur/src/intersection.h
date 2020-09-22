#ifndef __INTERSECTION__
#define __INTERSECTION__

#include "vector2.h"
#include "line2D.h"
#include "circle2D.h"
#include "segment2D.h"

#include <stdbool.h>

bool circle_line_intersect (circle2_t circle, line2_t line);
bool circle_segment_intersect(circle2_t circle, segment2_t line);

#endif