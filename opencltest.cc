#include "CL/cl.h"
#include <iostream>


int main() {
    
    cl_uint platformsCount = 0;
    clGetPlatformIDs(0, nullptr, &platformsCount);
    std::cout << "Number of OpenCL platforms: " << platformsCount << std::endl;
    return 0;

}