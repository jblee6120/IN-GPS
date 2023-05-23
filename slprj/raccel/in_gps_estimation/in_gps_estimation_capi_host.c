#include "in_gps_estimation_capi_host.h"
static in_gps_estimation_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        in_gps_estimation_host_InitializeDataMapInfo(&(root), "in_gps_estimation");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
