#ifndef POVRAY_COORDINATE_FILE_GENERATOR_TYPE_DEFINITION_H_
#define POVRAY_COORDINATE_FILE_GENERATOR_TYPE_DEFINITION_H_

#include <aliases.h>
#include <utilities.hpp>

namespace povutils {

    typedef struct StartingPose {
        std::string filename;
        size_t frames;
        GLMVec3 position;
        GLMVec3 lookAt;
        GLMVec3 translation;
        GLMVec3 rotation;

        StartingPose(std::string &filename, size_t frames, double x, double y, double z, 
            double lx, double ly, double lz, double tx, double ty, double tz, double roll, double pitch, double yaw)
            : filename(filename), frames(frames), position(GLMVec3(x, y, z)), lookAt(GLMVec3(lx, ly, lz)), translation(GLMVec3(tx, ty, tz)), rotation(GLMVec3(roll, pitch, yaw))
        { /*    */ }

    } StartingPose;
    typedef StartingPose* StartingPosePtr;
    typedef std::vector<StartingPosePtr> StartingPoseList;



} // namesapce cameval

#endif // POVRAY_COORDINATE_FILE_GENERATOR_TYPE_DEFINITION_H_
