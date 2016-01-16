#ifndef GET_DISSIMS_H
#define GET_DISSIMS_H

#include <vector>

#define __CL_ENABLE_EXCEPTIONS
#include <CL/cl.hpp>

#include "insar_data.h"
#include "cl_wrappers.h"

namespace nlsar {
    namespace training {
        std::vector<float> get_dissims(cl::Context context,
                                       nlsar::cl_wrappers nlsar_cl_wrappers,
                                       const insar_data& sub_insar_data,
                                       const int patch_size,
                                       const int window_width);
    }
}

#endif
