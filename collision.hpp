
#ifndef JFLX_COLLISION
#define JFLX_COLLISION

namespace JFLX {
    //* Standart AABB Collision Check
    namespace aabb {
        inline bool inBounds(float x1, float y1, float w1, float h1, float x2, float y2, float w2 = 1, float h2 = 1) {
            if (x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2) {
                return true;
            } return false;
        }
    }

}

#endif
