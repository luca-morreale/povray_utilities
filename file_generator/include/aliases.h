#ifndef POVRAY_COORDINATE_FILE_GENERATOR_ALIAS_H_
#define POVRAY_COORDINATE_FILE_GENERATOR_ALIAS_H_

#include <vector>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/writer.h>
#include <rapidjson/prettywriter.h>

#include <glm/glm.hpp>

#include <boost/filesystem.hpp>
#include <boost/system/error_code.hpp>


namespace povutils {

    typedef std::vector<std::string> StringList;
    typedef std::vector<int> IntList;
    typedef std::vector<float> FloatList;
    typedef std::vector<double> DoubleList;

    typedef glm::vec3 GLMVec3;
    typedef glm::mat3 GLMMat3;
    typedef glm::mat4 GLMMat4;
    
    typedef std::pair<GLMVec3, GLMVec3> AnglePose;
    typedef std::pair<GLMVec3, GLMMat3> Pose;

    typedef std::vector<GLMVec3> GLMVec3List;
    typedef std::vector<GLMMat3> GLMMat3List;
    typedef std::vector<AnglePose> AnglePoseList;
    typedef std::vector<Pose> PoseList;

    typedef boost::filesystem::path BoostPath;


    typedef rapidjson::SizeType JsonSizeT;
    const auto JsonArray = rapidjson::kArrayType;
    const auto JsonObject = rapidjson::kObjectType;
    const auto JsonNumber = rapidjson::kNumberType;

    typedef rapidjson::Document JsonDoc;
    typedef rapidjson::Value JsonValue;
    typedef rapidjson::IStreamWrapper JsonFINWrapper;
    typedef rapidjson::OStreamWrapper JsonFOUTWrapper;
    typedef rapidjson::Writer<JsonFOUTWrapper> JsonWriter;
    typedef rapidjson::PrettyWriter<JsonFOUTWrapper> JsonPrettyWriter;

    typedef boost::filesystem::path BoostPath;


} // namesapce povutils

#endif // POVRAY_COORDINATE_FILE_GENERATOR_ALIAS_H_
