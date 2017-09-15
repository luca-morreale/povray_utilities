#include <iostream>
#include <fstream>
#include <sstream>

#include <aliases.h>
#include <utilities.hpp>

#include <glm/gtc/matrix_transform.hpp>

#include <omp.h>


#define OMP_THREADS 8
#define ARGS 10

using namespace povutils;

std::string readModel(std::string &source);
std::string getFilename(GLMVec3 &pos, GLMVec3 &lat);
GLMVec3 computeAngles(GLMMat3 &rot);
void copyFile(std::string &sourceFile, std::string &destFile);
void copyFile(BoostPath &source, BoostPath &dest);


int main(int argc, char *argv[]) {

    if (argc < ARGS + 1) {
        std::cout << argv[0] << " source.pov startx starty startz lx ly lz tx ty tz Nx Ny Nz" << std::endl;
        return 1;
    }

    omp_set_num_threads(OMP_THREADS);

    GLMVec3 start, translate, step;
    GLMVec3 zdir(0, 0, 10);

    std::string model = argv[1];
    start.x = strtod(argv[2], NULL);
    start.y = strtod(argv[3], NULL);
    start.z = strtod(argv[4], NULL);
    zdir.x = strtod(argv[2], NULL);
    zdir.y = strtod(argv[3], NULL);
    zdir.z = strtod(argv[4], NULL);
    translate.x = strtod(argv[5], NULL);
    translate.y = strtod(argv[6], NULL);
    translate.z = strtod(argv[7], NULL);
    int Nx = atoi(argv[8]);
    int Ny = atoi(argv[9]);
    int Nz = atoi(argv[10]);

    step.x = translate.x / (float)Nx;
    step.y = translate.y / (float)Ny;
    step.z = translate.z / (float)Nz;

    std::string content = readModel(model);


    #pragma omp parallel for collapse(3)
    for (int zi = 0; zi <= Nz; zi++) {
        for (int yi = 0; yi <= Ny; yi++) {
            for (int xi = 0; xi <= Nx; xi++) {

                GLMVec3 pos = start + step * GLMVec3(xi, yi, zi);
                GLMVec3 lat = zdir + step * GLMVec3(xi, yi, zi);

                std::string filename = getFilename(pos, lat) + ".pov";
                copyFile(model, filename);

                std::fstream cout(filename, std::fstream::out | std::fstream::in);
                cout << "#declare PdV=<" << pos.x <<","<< pos.y << "," << pos.z << ">;" << std::endl;
                cout << "#declare V=<" << lat.x <<","<< lat.y << "," << lat.z << ">;" << std::endl;
                cout << content;
                cout.close();
            }
        }
    }

    return 0;
}

std::string readModel(std::string &source)
{
    std::ifstream t(source);
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    return str;
}

std::string getFilename(GLMVec3 &pos, GLMVec3 &lat)
{
    GLMMat4 view = glm::lookAt(pos, lat, GLMVec3(0.0f, -1.0f, 0.0f));
    GLMMat3 rotation(view);
    rotation = glm::transpose(rotation);
    GLMVec3 angles = computeAngles(rotation);

    std::stringstream out;
    out << pos.x << "_" << pos.y << "_" << pos.z;
    out << "_" << angles.x << "_" << angles.y << "_" << angles.z;
    return out.str();
}

GLMVec3 computeAngles(GLMMat3 &rot)
{
    GLMVec3 angle;

    angle.x = std::atan2(rot[2][1], rot[2][2]);    // roll
    angle.y = std::atan2(-rot[2][0], std::sqrt(std::pow(rot[2][1], 2) + std::pow(rot[2][2], 2)));   // pitch
    angle.z = std::atan2(rot[1][0], rot[0][0]);    // yaw

    angle.x = deg(angle.x);
    angle.y = deg(angle.y);
    angle.z = deg(angle.z);

    return angle;
}


void copyFile(std::string &sourceFile, std::string &destFile)
{
    BoostPath source(sourceFile);
    BoostPath dest(destFile);
    copyFile(source, dest);
}

void copyFile(BoostPath &source, BoostPath &dest)
{
    boost::filesystem::copy_file(source, dest, boost::filesystem::copy_option::overwrite_if_exists);
}

