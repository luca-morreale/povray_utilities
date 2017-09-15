#ifndef POVRAY_COORDINATE_FILE_GENERATOR_UTILITIES_H_
#define POVRAY_COORDINATE_FILE_GENERATOR_UTILITIES_H_

#include <algorithm> 
#include <functional>
#include <fstream>
#include <cctype>
#include <locale>
#include <cmath>

#include <boost/algorithm/string.hpp>

#include <aliases.h>

namespace povutils {

    std::string &ltrim(std::string &s);
    std::string &rtrim(std::string &s);
    std::string &trim(std::string &s);
    std::string readStringFromFile(std::string &filename);

    float rad(float deg);
    float deg(float rad);
    GLMMat3 rotationMatrix(float yaw, float pitch, float roll);
    GLMMat3 rotationMatrix(GLMVec3 &angles);
    GLMMat3 rotationRoll(float roll);
    GLMMat3 rotationPitch(float pitch);
    GLMMat3 rotationYaw(float yaw);

} // namespace povutils

#endif // POVRAY_COORDINATE_FILE_GENERATOR_UTILITIES_H_
