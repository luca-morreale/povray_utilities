#include <utilities.hpp>

namespace povutils {

    // trim from start
    std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }

    // trim from end
    std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(),
                std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
    }

    // trim from both ends
    std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
    }

    std::string readStringFromFile(std::string &filename)
    {
        std::ifstream cin(filename);
        std::string content((std::istreambuf_iterator<char>(cin)), std::istreambuf_iterator<char>());
        cin.close();
        return content;
    }

    float rad(float deg)
    {
        return deg * M_PI / 180.0f;
    }

    float deg(float rad)
    {
        return rad * 180.0f / M_PI;
    }

    GLMMat3 rotationMatrix(float yaw, float pitch, float roll)
    {
        return rotationYaw(yaw) * rotationPitch(pitch) * rotationRoll(roll);
    }

    GLMMat3 rotationMatrix(GLMVec3 &angles)
    {
        return rotationYaw(angles.z) * rotationPitch(angles.y) * rotationRoll(angles.x);
    }

    GLMMat3 rotationRoll(float roll)
    {
        return GLMMat3(1.0f, 0.0f, 0.0f,
                0.0f, std::cos(roll), -std::sin(roll),
                0.0f, std::sin(roll), std::cos(roll));
    }

    GLMMat3 rotationPitch(float pitch)
    {
        return GLMMat3(std::cos(pitch), 0.0f, std::sin(pitch),
                        0.0f, 1.0f, 0.0f,
                        -std::sin(pitch), 0.0f, std::cos(pitch));
    }

    GLMMat3 rotationYaw(float yaw)
    {
        return GLMMat3(std::cos(yaw), -std::sin(yaw), 0.0f,
                        std::sin(yaw), std::cos(yaw), 0.0f,
                        0.0f, 0.0f, 1.0f);
    }

} // namespace povutils
