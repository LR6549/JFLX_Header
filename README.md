## JFLX_Header

**JFLX_Header** is a personal C++ utility library collection under the JFLX umbrella, designed for small projects, experiments, and hobbyist programming. It contains modular utilities such as vector math, JSON handling, logging, and collision detection.

### Background
The name **JFLX** originates from an old project idea called "JoFlex," which was originally intended for affordable luxury products. Over time, it became a personal brand that I now use for publishing experimental software, custom libraries, and other personal projects. The projects under JFLX are often diverse and unrelated, driven by curiosity, learning, or inspiration from suggestions by others.

**Note:** The code provided is functional but may not always be optimized or the latest standard. Bugs and improvements are welcome, but the library is not maintained for continuous updates.

### Features

#### 1. `vectors.hpp`
- Provides a templated `Vector2<T>` structure with arithmetic support.
- Functions for length calculation, normalization, dot product, and basic vector operations.
- Example:
```cpp
JFLX::vects::Vector2<double> v1(3, 4);
std::cout << v1.length(); // Outputs 5
```

#### 2. `collision.hpp`
- Axis-Aligned Bounding Box (AABB) collision detection.
- Field-of-View (FOV) checks using dot products for direction vectors.
- Example:
```cpp
bool hit = JFLX::aabb::inBounds(x1, y1, w1, h1, x2, y2); // true if collided
```
#### 3. `jsonFunctionality.hpp`
- Simple JSON loading and saving using nlohmann/json [https://github.com/nlohmann/json]
- Example:
```cpp
nlohmann::json j;
JFLX::loadJson("config.json", j);
```
#### 4. `logging.hpp`
- Lightweight logging with colored output for errors, warnings, info, and success.
- Example:
```cpp
JFLX::log("File not found", "config.json missing", JFLX::LOGTYPE::ERROR);
```
And many more.

## Summary:
JFLX_Header is a versatile, lightweight collection of C++ utilities for vectors, collision detection, JSON handling, and logging—perfect for hobby projects, prototypes, and learning purposes.
