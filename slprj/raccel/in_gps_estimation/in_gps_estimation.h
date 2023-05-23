#ifndef RTW_HEADER_in_gps_estimation_h_
#define RTW_HEADER_in_gps_estimation_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef in_gps_estimation_COMMON_INCLUDES_
#define in_gps_estimation_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "in_gps_estimation_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME in_gps_estimation
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (12) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (1)   
#elif NCSTATES != 1
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T gho24r3wjp ; real_T imhbzzo51g ; real_T mqkohde3av ;
real_T k3khppcoob ; real_T ixicelz4a0 ; real_T orzekcshh1 ; real_T f0b2eyvx0s
; real_T apwxdnsmjg ; real_T jvz2qkejcz ; real_T n4bmglhsm1 ; real_T
fa5bpj2f2b ; real_T jdacxbno0x ; } B ; typedef struct { real_T hs5sslgrvi ;
struct { void * LoggedData ; } cywm4bsd5e ; struct { void * LoggedData ; }
aglikhlqco ; struct { void * LoggedData ; } odrrudiher ; struct { void *
LoggedData ; } gsjw3qyczu ; struct { void * LoggedData ; } fg3eckn3eu ;
struct { void * LoggedData ; } k32v50utzr ; struct { void * LoggedData ; }
bmvwp1nucp ; struct { void * LoggedData ; } kh0put4mx0 ; struct { void *
LoggedData ; } o4iq1brz0d ; int_T dqsf2qhlqe [ 3 ] ; int_T pi102jxxgd [ 3 ] ;
int_T gythey2jbv [ 3 ] ; int_T kj3fntqjhm [ 3 ] ; int_T gw33k54ujt [ 3 ] ; }
DW ; typedef struct { real_T bfyd2zvqf5 ; } X ; typedef struct { real_T
bfyd2zvqf5 ; } XDot ; typedef struct { boolean_T bfyd2zvqf5 ; } XDis ;
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ {
real_T Difference_ICPrevInput ; real_T TransferFcn_A ; real_T TransferFcn_C ;
real_T SFunction5_P1_Size [ 2 ] ; real_T SFunction5_P1 ; real_T
SFunction5_P2_Size [ 2 ] ; real_T SFunction5_P2 ; real_T SFunction5_P3_Size [
2 ] ; real_T SFunction5_P4_Size [ 2 ] ; real_T SFunction5_P4 ; real_T
Gain8_Gain ; real_T Gain7_Gain ; real_T Gain_Gain ; real_T SFunction_P1_Size
[ 2 ] ; real_T SFunction_P1 ; real_T SFunction_P2_Size [ 2 ] ; real_T
SFunction_P2 ; real_T SFunction_P3_Size [ 2 ] ; real_T SFunction_P4_Size [ 2
] ; real_T SFunction_P4 ; real_T Gain2_Gain ; real_T Gain3_Gain ; real_T
SFunction16_P1_Size [ 2 ] ; real_T SFunction16_P1 ; real_T
SFunction16_P2_Size [ 2 ] ; real_T SFunction16_P2 ; real_T
SFunction16_P3_Size [ 2 ] ; real_T SFunction16_P4_Size [ 2 ] ; real_T
SFunction16_P4 ; real_T Step_Time ; real_T Step_Y0 ; real_T Step_YFinal ;
real_T SineWave_Amp ; real_T SineWave_Bias ; real_T SineWave_Freq ; real_T
SineWave_Phase ; real_T Gain1_Gain ; real_T SFunction3_P1_Size [ 2 ] ; real_T
SFunction3_P1 ; real_T SFunction3_P2_Size [ 2 ] ; real_T SFunction3_P2 ;
real_T SFunction3_P3_Size [ 2 ] ; real_T SFunction3_P3 [ 4 ] ; real_T
SFunction3_P4_Size [ 2 ] ; real_T SFunction3_P4 ; real_T SFunction2_P1_Size [
2 ] ; real_T SFunction2_P1 ; real_T SFunction2_P2_Size [ 2 ] ; real_T
SFunction2_P2 ; real_T SFunction2_P3_Size [ 2 ] ; real_T SFunction2_P4_Size [
2 ] ; real_T SFunction2_P4 ; real_T Constant2_Value ; real_T Constant3_Value
; uint8_T ManualSwitch_CurrentSetting ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern mxArray * mr_in_gps_estimation_GetDWork ( ) ; extern
void mr_in_gps_estimation_SetDWork ( const mxArray * ssDW ) ; extern mxArray
* mr_in_gps_estimation_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * in_gps_estimation_GetCAPIStaticMap ( void )
; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
