
#ifndef JFLX_COLLISION
#define JFLX_COLLISION

#include <cmath>
#include <JFLX/vectors.hpp>

namespace JFLX {
    //* Standart AABB Collision Check
    namespace aabb {
        inline bool inBounds(float x1, float y1, float w1, float h1, float x2, float y2, float w2 = 1, float h2 = 1) {
            if (x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2) {
                return true;
            } return false;
        }
    }

    namespace fov {
        /*
        * Checks if an Object is infront/in FOV of another Object (This Object)
        * pVectDir -> Vector in which the this Object watch
        * pVectDirToObj -> Vector from this Object to the checked Object
        * The higher the tolerance the smaller the field of view, 0.45 would mean FOV of 45° above and below  the pVectDir!
        */
        inline bool isInFOV(JFLX::vects::Vector2<double> pVectDir, JFLX::vects::Vector2<double> pVectDirToObj, double tolerance = 0.0) {
            return (pVectDir.dot(pVectDirToObj) > tolerance);
        }
    }
}

#endif
