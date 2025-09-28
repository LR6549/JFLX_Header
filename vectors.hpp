#ifndef VECTS
#define VECTS

#include <iostream>
#include <cmath>
#include <concepts>

namespace JFLX {
    namespace vects {
        template <typename T>
        struct Vector2 {
            static_assert(std::is_arithmetic<T>::value, "Vector2 only supports arithmetic types.");
            T x;
            T y;
        
            /*
            *  Creates a new Vector2, if pX and pY are not  given, 0 will be assumed
            */
            Vector2(T pX = 0, T pY = 0) : x(pX), y(pY)  {
        
            }
        
            ~Vector2() {
        
            }

            void setX(T pX) {
                x = pX;
            }

            void setY(T pY) {
                y = pY;
            }
            
            double length() const {
                return std::sqrt(x * x + y * y);
            }
            
            Vector2<double> normalized() const {
                double len = length();
                if (len == 0.0) return {0, 0};
                return {static_cast<double>(x) / len, static_cast<double>(y) / len};
            }

            void normalize() {
                double len = length();
                if (len != 0.0) {
                    x /= len;
                    y /= len;
                } else {
                    x = 0;
                    y = 0;
                }
            }

            double dot(const Vector2& pVector) const {
                const Vector2 pVect1 = normalized();
                const Vector2 pVect2 = pVector.normalized();
                return (pVect1.x * pVect2.x) + (pVect1.y * pVect2.y)
            }
        
            Vector2 operator+(const Vector2& other) const {
                return { x + other.x, y + other.y };
            }
            
            Vector2 operator-(const Vector2& other) const {
                return { x - other.x, y - other.y };
            }
            
            Vector2 operator*(const Vector2& other) const {
                return { x * other.x, y * other.y };
            }

            Vector2 operator/(const Vector2& other) const {
                return { x / other.x, y / other.y };
            }

            void print() const {
                std::cout << "{" << x << ", " << y << "}\n";
            }
        };
    }
}


#endif
