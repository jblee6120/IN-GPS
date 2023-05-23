#include "rt_logging_mmi.h"
#include "in_gps_estimation_capi.h"
#include <math.h>
#include "in_gps_estimation.h"
#include "in_gps_estimation_private.h"
#include "in_gps_estimation_dt.h"
#include "sfcn_loader_c_api.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "10.4 (R2021b) 14-May-2021" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { rtX . bfyd2zvqf5 = 0.0 ; {
SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; { static const char *
blockSIDForSFcnLoader = "in_gps_estimation:103" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = rts -> modelMethods . sFcn .
mdlInitializeConditions . level2 ; sfcnLoader_separateComplexHandler ( rts ,
sfcnMethodPtr ) ; } if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; { static const char *
blockSIDForSFcnLoader = "in_gps_estimation:10" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = rts -> modelMethods . sFcn .
mdlInitializeConditions . level2 ; sfcnLoader_separateComplexHandler ( rts ,
sfcnMethodPtr ) ; } if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
rtDW . hs5sslgrvi = rtP . Difference_ICPrevInput ; { SimStruct * rts =
ssGetSFunction ( rtS , 2 ) ; { static const char * blockSIDForSFcnLoader =
"in_gps_estimation:16" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * ) = rts ->
modelMethods . sFcn . mdlInitializeConditions . level2 ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 3 ) ; { static const char * blockSIDForSFcnLoader =
"in_gps_estimation:1" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * ) = rts ->
modelMethods . sFcn . mdlInitializeConditions . level2 ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 4 ) ; { static const char * blockSIDForSFcnLoader =
"in_gps_estimation:47" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * ) = rts ->
modelMethods . sFcn . mdlInitializeConditions . level2 ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } } void MdlStart ( void ) {
{ bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { int_T dimensions [ 1 ] = { 1 } ; rtDW . odrrudiher . LoggedData =
rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal
( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "i" , SS_DOUBLE , 0 , 0 , 0
, 1 , 1 , dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0005 ,
1 ) ; if ( rtDW . odrrudiher . LoggedData == ( NULL ) ) return ; } { int_T
dimensions [ 1 ] = { 1 } ; rtDW . k32v50utzr . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "w" , SS_DOUBLE , 0 , 0 , 0 , 1 , 1 ,
dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0005 , 1 ) ; if
( rtDW . k32v50utzr . LoggedData == ( NULL ) ) return ; } { int_T dimensions
[ 1 ] = { 1 } ; rtDW . kh0put4mx0 . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "input_voltage" , SS_DOUBLE , 0 , 0 , 0 , 1 ,
1 , dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0005 , 1 ) ;
if ( rtDW . kh0put4mx0 . LoggedData == ( NULL ) ) return ; } { int_T
dimensions [ 1 ] = { 1 } ; rtDW . o4iq1brz0d . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "true_time" , SS_DOUBLE , 0 , 0 , 0 , 1 , 1 ,
dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0005 , 1 ) ; if
( rtDW . o4iq1brz0d . LoggedData == ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; { static const char * blockSIDForSFcnLoader =
"in_gps_estimation:103" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * ) =
ssGetmdlStart ( rts ) ; sfcnLoader_separateComplexHandler ( rts ,
sfcnMethodPtr ) ; } if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; { static const char *
blockSIDForSFcnLoader = "in_gps_estimation:10" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = ssGetmdlStart ( rts ) ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 2 ) ; { static const char * blockSIDForSFcnLoader =
"in_gps_estimation:16" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * ) =
ssGetmdlStart ( rts ) ; sfcnLoader_separateComplexHandler ( rts ,
sfcnMethodPtr ) ; } if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } {
SimStruct * rts = ssGetSFunction ( rtS , 3 ) ; { static const char *
blockSIDForSFcnLoader = "in_gps_estimation:1" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = ssGetmdlStart ( rts ) ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 4 ) ; { static const char * blockSIDForSFcnLoader =
"in_gps_estimation:47" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * ) =
ssGetmdlStart ( rts ) ; sfcnLoader_separateComplexHandler ( rts ,
sfcnMethodPtr ) ; } if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { rtB . gho24r3wjp = 0.0
; rtB . gho24r3wjp += rtP . TransferFcn_C * rtX . bfyd2zvqf5 ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { } { SimStruct * rts = ssGetSFunction ( rtS
, 0 ) ; { static const char * blockSIDForSFcnLoader = "in_gps_estimation:103"
; sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * , int ) = rts -> modelMethods . sFcn .
mdlOutputs . level2 ; sfcnLoader_separateComplexHandler_withTID ( rts ,
sfcnMethodPtr , ( 0 <= 1 ) && gbl_raccel_tid01eq ? 0 : 0 ) ; } } rtB .
mqkohde3av = rtP . Gain8_Gain * rtB . imhbzzo51g ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { } rtB . k3khppcoob = ( rtB . mqkohde3av - rtP . Constant3_Value )
* rtP . Gain7_Gain * rtP . Gain_Gain + rtP . Constant2_Value ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 1 ) ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) ( LogVar * ) ( rtDW . odrrudiher
. LoggedData ) , & rtB . k3khppcoob , 0 ) ; } } } } { SimStruct * rts =
ssGetSFunction ( rtS , 1 ) ; { static const char * blockSIDForSFcnLoader =
"in_gps_estimation:10" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * , int ) =
rts -> modelMethods . sFcn . mdlOutputs . level2 ;
sfcnLoader_separateComplexHandler_withTID ( rts , sfcnMethodPtr , ( 0 <= 1 )
&& gbl_raccel_tid01eq ? 0 : 0 ) ; } } rtB . orzekcshh1 = rtP . Gain2_Gain *
rtB . ixicelz4a0 * rtP . Gain3_Gain ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . f0b2eyvx0s = rtB . orzekcshh1 - rtDW . hs5sslgrvi ; } { SimStruct * rts
= ssGetSFunction ( rtS , 2 ) ; { static const char * blockSIDForSFcnLoader =
"in_gps_estimation:16" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * , int ) =
rts -> modelMethods . sFcn . mdlOutputs . level2 ;
sfcnLoader_separateComplexHandler_withTID ( rts , sfcnMethodPtr , ( 0 <= 1 )
&& gbl_raccel_tid01eq ? 0 : 0 ) ; } } rtB . jvz2qkejcz = rtB . f0b2eyvx0s /
rtB . apwxdnsmjg ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssGetLogOutput
( rtS ) ) { { double locTime = ssGetTaskTime ( rtS , 1 ) ; if (
rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) (
LogVar * ) ( rtDW . k32v50utzr . LoggedData ) , & rtB . jvz2qkejcz , 0 ) ; }
} } } if ( rtP . ManualSwitch_CurrentSetting == 1 ) { if ( ssGetTaskTime (
rtS , 0 ) < rtP . Step_Time ) { rtB . n4bmglhsm1 = rtP . Step_Y0 ; } else {
rtB . n4bmglhsm1 = rtP . Step_YFinal ; } } else { rtB . n4bmglhsm1 =
muDoubleScalarSin ( rtP . SineWave_Freq * ssGetTaskTime ( rtS , 0 ) + rtP .
SineWave_Phase ) * rtP . SineWave_Amp + rtP . SineWave_Bias ; } rtB .
fa5bpj2f2b = rtP . Gain1_Gain * rtB . n4bmglhsm1 ; { SimStruct * rts =
ssGetSFunction ( rtS , 3 ) ; { static const char * blockSIDForSFcnLoader =
"in_gps_estimation:1" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * , int ) =
rts -> modelMethods . sFcn . mdlOutputs . level2 ;
sfcnLoader_separateComplexHandler_withTID ( rts , sfcnMethodPtr , ( 0 <= 1 )
&& gbl_raccel_tid01eq ? 0 : 0 ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
if ( ssGetLogOutput ( rtS ) ) { { double locTime = ssGetTaskTime ( rtS , 1 )
; if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS
) -> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) (
LogVar * ) ( rtDW . kh0put4mx0 . LoggedData ) , & rtB . n4bmglhsm1 , 0 ) ; }
} } } { SimStruct * rts = ssGetSFunction ( rtS , 4 ) ; { static const char *
blockSIDForSFcnLoader = "in_gps_estimation:47" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * , int ) = rts -> modelMethods . sFcn .
mdlOutputs . level2 ; sfcnLoader_separateComplexHandler_withTID ( rts ,
sfcnMethodPtr , ( 0 <= 1 ) && gbl_raccel_tid01eq ? 0 : 0 ) ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssGetLogOutput ( rtS ) ) { { double
locTime = ssGetTaskTime ( rtS , 1 ) ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) ( LogVar * ) ( rtDW . o4iq1brz0d
. LoggedData ) , & rtB . jdacxbno0x , 0 ) ; } } } } UNUSED_PARAMETER ( tid )
; } void MdlOutputsTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW .
hs5sslgrvi = rtB . orzekcshh1 ; } UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> bfyd2zvqf5 = 0.0 ; _rtXdot -> bfyd2zvqf5 += rtP .
TransferFcn_A * rtX . bfyd2zvqf5 ; _rtXdot -> bfyd2zvqf5 += rtB . k3khppcoob
; } void MdlProjection ( void ) { } void MdlTerminate ( void ) { { SimStruct
* rts = ssGetSFunction ( rtS , 0 ) ; { static const char *
blockSIDForSFcnLoader = "in_gps_estimation:103" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = rts -> modelMethods . sFcn . mdlTerminate ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } } { SimStruct *
rts = ssGetSFunction ( rtS , 1 ) ; { static const char *
blockSIDForSFcnLoader = "in_gps_estimation:10" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = rts -> modelMethods . sFcn . mdlTerminate ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } } { SimStruct *
rts = ssGetSFunction ( rtS , 2 ) ; { static const char *
blockSIDForSFcnLoader = "in_gps_estimation:16" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = rts -> modelMethods . sFcn . mdlTerminate ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } } { SimStruct *
rts = ssGetSFunction ( rtS , 3 ) ; { static const char *
blockSIDForSFcnLoader = "in_gps_estimation:1" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = rts -> modelMethods . sFcn . mdlTerminate ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } } { SimStruct *
rts = ssGetSFunction ( rtS , 4 ) ; { static const char *
blockSIDForSFcnLoader = "in_gps_estimation:47" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = rts -> modelMethods . sFcn . mdlTerminate ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } } } static void
mr_in_gps_estimation_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) ; static void
mr_in_gps_estimation_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_in_gps_estimation_restoreDataFromMxArray ( void * destData
, const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_in_gps_estimation_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_in_gps_estimation_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) ; static void
mr_in_gps_estimation_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_in_gps_estimation_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_in_gps_estimation_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_in_gps_estimation_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_in_gps_estimation_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_in_gps_estimation_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void
mr_in_gps_estimation_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_in_gps_estimation_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_in_gps_estimation_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( double ) fieldVal ) ) ; } static uint_T
mr_in_gps_estimation_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_in_gps_estimation_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_in_gps_estimation_GetDWork ( ) {
static const char * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX"
, } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_in_gps_estimation_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & (
rtB ) , sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 6 ] = {
"rtDW.hs5sslgrvi" , "rtDW.dqsf2qhlqe" , "rtDW.pi102jxxgd" , "rtDW.gythey2jbv"
, "rtDW.kj3fntqjhm" , "rtDW.gw33k54ujt" , } ; mxArray * rtdwData =
mxCreateStructMatrix ( 1 , 1 , 6 , rtdwDataFieldNames ) ;
mr_in_gps_estimation_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * )
& ( rtDW . hs5sslgrvi ) , sizeof ( rtDW . hs5sslgrvi ) ) ;
mr_in_gps_estimation_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * )
& ( rtDW . dqsf2qhlqe ) , sizeof ( rtDW . dqsf2qhlqe ) ) ;
mr_in_gps_estimation_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * )
& ( rtDW . pi102jxxgd ) , sizeof ( rtDW . pi102jxxgd ) ) ;
mr_in_gps_estimation_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * )
& ( rtDW . gythey2jbv ) , sizeof ( rtDW . gythey2jbv ) ) ;
mr_in_gps_estimation_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * )
& ( rtDW . kj3fntqjhm ) , sizeof ( rtDW . kj3fntqjhm ) ) ;
mr_in_gps_estimation_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * )
& ( rtDW . gw33k54ujt ) , sizeof ( rtDW . gw33k54ujt ) ) ; mxSetFieldByNumber
( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_in_gps_estimation_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_in_gps_estimation_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0
, 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber (
ssDW , 0 , 1 ) ; mr_in_gps_estimation_restoreDataFromMxArray ( ( void * ) & (
rtDW . hs5sslgrvi ) , rtdwData , 0 , 0 , sizeof ( rtDW . hs5sslgrvi ) ) ;
mr_in_gps_estimation_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dqsf2qhlqe ) , rtdwData , 0 , 1 , sizeof ( rtDW . dqsf2qhlqe ) ) ;
mr_in_gps_estimation_restoreDataFromMxArray ( ( void * ) & ( rtDW .
pi102jxxgd ) , rtdwData , 0 , 2 , sizeof ( rtDW . pi102jxxgd ) ) ;
mr_in_gps_estimation_restoreDataFromMxArray ( ( void * ) & ( rtDW .
gythey2jbv ) , rtdwData , 0 , 3 , sizeof ( rtDW . gythey2jbv ) ) ;
mr_in_gps_estimation_restoreDataFromMxArray ( ( void * ) & ( rtDW .
kj3fntqjhm ) , rtdwData , 0 , 4 , sizeof ( rtDW . kj3fntqjhm ) ) ;
mr_in_gps_estimation_restoreDataFromMxArray ( ( void * ) & ( rtDW .
gw33k54ujt ) , rtdwData , 0 , 5 , sizeof ( rtDW . gw33k54ujt ) ) ; } }
mxArray * mr_in_gps_estimation_GetSimStateDisallowedBlocks ( ) { mxArray *
data = mxCreateCellMatrix ( 5 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static
const char * blockType [ 5 ] = { "Scope" , "Scope" , "Scope" , "Scope" ,
"Scope" , } ; static const char * blockPath [ 5 ] = {
"in_gps_estimation/Scope5" , "in_gps_estimation/Scope6" ,
"in_gps_estimation/Scope1" , "in_gps_estimation/Scope7" ,
"in_gps_estimation/Scope" , } ; static const int reason [ 5 ] = { 0 , 0 , 0 ,
0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 5 ; ++ ( subs [ 0 ] ) ) {
subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 1 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 31 ) ;
ssSetNumBlockIO ( rtS , 12 ) ; ssSetNumBlockParams ( rtS , 78 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0005 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2226012495U ) ; ssSetChecksumVal ( rtS , 1 ,
2004764594U ) ; ssSetChecksumVal ( rtS , 2 , 3757314384U ) ; ssSetChecksumVal
( rtS , 3 , 185473456U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 20 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
in_gps_estimation_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "in_gps_estimation" ) ;
ssSetPath ( rtS , "in_gps_estimation" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 30.0 ) ; ssSetStepSize ( rtS , 0.0005 ) ;
ssSetFixedStepSize ( rtS , 0.0005 ) ; { static RTWLogInfo rt_DataLoggingInfo
; rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
} ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "DSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"in_gps_estimation/Transfer Fcn" , "in_gps_estimation/Difference/UD" } ;
static const char_T * rt_LoggedStateNames [ ] = { "" , "DSTATE" } ; static
boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 0 }
; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 2 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . bfyd2zvqf5 ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtDW . hs5sslgrvi ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 1 ] ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode4" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
0 ) ; ssSetContStateDisabled ( rtS , contStatesDisabled ) ; }
ssSetChecksumVal ( rtS , 0 , 2226012495U ) ; ssSetChecksumVal ( rtS , 1 ,
2004764594U ) ; ssSetChecksumVal ( rtS , 2 , 3757314384U ) ; ssSetChecksumVal
( rtS , 3 , 185473456U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_in_gps_estimation_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_in_gps_estimation_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_in_gps_estimation_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } ssSetNumSFunctions ( rtS , 5 ) ; { static SimStruct
childSFunctions [ 5 ] ; static SimStruct * childSFunctionPtrs [ 5 ] ; ( void
) memset ( ( void * ) & childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions
) ) ; ssSetSFunctions ( rtS , & childSFunctionPtrs [ 0 ] ) ; { int_T i ; for
( i = 0 ; i < 5 ; i ++ ) { ssSetSFunction ( rtS , i , & childSFunctions [ i ]
) ; } } { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; static time_T
sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [
1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ;
( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; static ssJacobianPerturbationBounds
jacPerturbationBounds ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ;
ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
static struct _ssPortOutputs outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs (
rts , & outputPortInfo [ 0 ] ) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static
struct _ssOutPortUnit outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits (
rts , & outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . imhbzzo51g
) ) ; } } ssSetModelName ( rts , "DueDaqSfun" ) ; ssSetPath ( rts ,
"in_gps_estimation/S-Function5" ) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) {
ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; }
else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , (
NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion ( rts ,
SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 4 ] ;
ssSetSFcnParamsCount ( rts , 4 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . SFunction5_P1_Size ) ;
ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . SFunction5_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . SFunction5_P3_Size ) ;
ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP . SFunction5_P4_Size ) ; }
ssSetIWork ( rts , ( int_T * ) & rtDW . dqsf2qhlqe [ 0 ] ) ; { static struct
_ssDWorkRecord dWorkRecord [ 1 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 1 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 1 ) ;
ssSetDWorkWidth ( rts , 0 , 3 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
dqsf2qhlqe [ 0 ] ) ; } { raccelLoadSFcnMexFile ( "DueDaqSfun" ,
"in_gps_estimation:103" , rts , 0 ) ; if ( ssGetErrorStatus ( rtS ) ) {
return rtS ; } } sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts ,
0 , 0.0 ) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCs ( rts , 0 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 )
; _ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; } { SimStruct * rts =
ssGetSFunction ( rtS , 1 ) ; static time_T sfcnPeriod [ 1 ] ; static time_T
sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void *
) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void * )
sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , &
sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; { static struct _ssBlkInfo2
_blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr (
rts , blkInfo2 ) ; } { static struct _ssPortInfo2 _portInfo2 ; struct
_ssPortInfo2 * portInfo2 = & _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts ,
portInfo2 ) ; } ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static
struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2
) ; } { static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 (
rts , & methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ; static
ssJacobianPerturbationBounds jacPerturbationBounds ; ssSetStatesInfo2 ( rts ,
& statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
static struct _ssPortOutputs outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs (
rts , & outputPortInfo [ 0 ] ) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static
struct _ssOutPortUnit outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits (
rts , & outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . ixicelz4a0
) ) ; } } ssSetModelName ( rts , "DueDaqSfun" ) ; ssSetPath ( rts ,
"in_gps_estimation/S-Function" ) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) {
ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; }
else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , (
NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion ( rts ,
SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 4 ] ;
ssSetSFcnParamsCount ( rts , 4 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . SFunction_P1_Size ) ;
ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . SFunction_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . SFunction_P3_Size ) ;
ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP . SFunction_P4_Size ) ; }
ssSetIWork ( rts , ( int_T * ) & rtDW . pi102jxxgd [ 0 ] ) ; { static struct
_ssDWorkRecord dWorkRecord [ 1 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 1 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 1 ) ;
ssSetDWorkWidth ( rts , 0 , 3 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
pi102jxxgd [ 0 ] ) ; } { raccelLoadSFcnMexFile ( "DueDaqSfun" ,
"in_gps_estimation:10" , rts , 1 ) ; if ( ssGetErrorStatus ( rtS ) ) { return
rtS ; } } sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0
) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCs ( rts , 0 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 )
; _ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; } { SimStruct * rts =
ssGetSFunction ( rtS , 2 ) ; static time_T sfcnPeriod [ 1 ] ; static time_T
sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void *
) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void * )
sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , &
sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; { static struct _ssBlkInfo2
_blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr (
rts , blkInfo2 ) ; } { static struct _ssPortInfo2 _portInfo2 ; struct
_ssPortInfo2 * portInfo2 = & _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts ,
portInfo2 ) ; } ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static
struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2
) ; } { static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 (
rts , & methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ; static
ssJacobianPerturbationBounds jacPerturbationBounds ; ssSetStatesInfo2 ( rts ,
& statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
static struct _ssPortOutputs outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs (
rts , & outputPortInfo [ 0 ] ) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static
struct _ssOutPortUnit outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits (
rts , & outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . apwxdnsmjg
) ) ; } } ssSetModelName ( rts , "DueDaqSfun" ) ; ssSetPath ( rts ,
"in_gps_estimation/S-Function16" ) ; if ( ssGetRTModel ( rtS ) == ( NULL ) )
{ ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; }
else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , (
NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion ( rts ,
SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 4 ] ;
ssSetSFcnParamsCount ( rts , 4 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . SFunction16_P1_Size )
; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . SFunction16_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . SFunction16_P3_Size ) ;
ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP . SFunction16_P4_Size ) ; }
ssSetIWork ( rts , ( int_T * ) & rtDW . gythey2jbv [ 0 ] ) ; { static struct
_ssDWorkRecord dWorkRecord [ 1 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 1 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 1 ) ;
ssSetDWorkWidth ( rts , 0 , 3 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
gythey2jbv [ 0 ] ) ; } { raccelLoadSFcnMexFile ( "DueDaqSfun" ,
"in_gps_estimation:16" , rts , 2 ) ; if ( ssGetErrorStatus ( rtS ) ) { return
rtS ; } } sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0
) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCs ( rts , 0 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 )
; _ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; } { SimStruct * rts =
ssGetSFunction ( rtS , 3 ) ; static time_T sfcnPeriod [ 1 ] ; static time_T
sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void *
) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void * )
sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , &
sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; { static struct _ssBlkInfo2
_blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr (
rts , blkInfo2 ) ; } { static struct _ssPortInfo2 _portInfo2 ; struct
_ssPortInfo2 * portInfo2 = & _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts ,
portInfo2 ) ; } ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static
struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2
) ; } { static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 (
rts , & methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ; static
ssJacobianPerturbationBounds jacPerturbationBounds ; ssSetStatesInfo2 ( rts ,
& statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
static struct _ssPortInputs inputPortInfo [ 1 ] ; _ssSetNumInputPorts ( rts ,
1 ) ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 1 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; { static real_T
const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . fa5bpj2f2b ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 1 ) ; } } ssSetModelName ( rts , "DueDaqSfun" ) ; ssSetPath ( rts ,
"in_gps_estimation/S-Function3" ) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) {
ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; }
else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , (
NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion ( rts ,
SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 4 ] ;
ssSetSFcnParamsCount ( rts , 4 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . SFunction3_P1_Size ) ;
ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . SFunction3_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . SFunction3_P3_Size ) ;
ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP . SFunction3_P4_Size ) ; }
ssSetIWork ( rts , ( int_T * ) & rtDW . kj3fntqjhm [ 0 ] ) ; { static struct
_ssDWorkRecord dWorkRecord [ 1 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 1 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 1 ) ;
ssSetDWorkWidth ( rts , 0 , 3 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
kj3fntqjhm [ 0 ] ) ; } { raccelLoadSFcnMexFile ( "DueDaqSfun" ,
"in_gps_estimation:1" , rts , 3 ) ; if ( ssGetErrorStatus ( rtS ) ) { return
rtS ; } } sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0
) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCs ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } { SimStruct * rts =
ssGetSFunction ( rtS , 4 ) ; static time_T sfcnPeriod [ 1 ] ; static time_T
sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void *
) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void * )
sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , &
sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; { static struct _ssBlkInfo2
_blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr (
rts , blkInfo2 ) ; } { static struct _ssPortInfo2 _portInfo2 ; struct
_ssPortInfo2 * portInfo2 = & _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts ,
portInfo2 ) ; } ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static
struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2
) ; } { static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 (
rts , & methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ; static
ssJacobianPerturbationBounds jacPerturbationBounds ; ssSetStatesInfo2 ( rts ,
& statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
static struct _ssPortOutputs outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs (
rts , & outputPortInfo [ 0 ] ) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static
struct _ssOutPortUnit outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits (
rts , & outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB . jdacxbno0x
) ) ; } } ssSetModelName ( rts , "DueDaqSfun" ) ; ssSetPath ( rts ,
"in_gps_estimation/S-Function2" ) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) {
ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; }
else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , (
NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion ( rts ,
SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 4 ] ;
ssSetSFcnParamsCount ( rts , 4 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . SFunction2_P1_Size ) ;
ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . SFunction2_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . SFunction2_P3_Size ) ;
ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP . SFunction2_P4_Size ) ; }
ssSetIWork ( rts , ( int_T * ) & rtDW . gw33k54ujt [ 0 ] ) ; { static struct
_ssDWorkRecord dWorkRecord [ 1 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 1 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 1 ) ;
ssSetDWorkWidth ( rts , 0 , 3 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
gw33k54ujt [ 0 ] ) ; } { raccelLoadSFcnMexFile ( "DueDaqSfun" ,
"in_gps_estimation:47" , rts , 4 ) ; if ( ssGetErrorStatus ( rtS ) ) { return
rtS ; } } sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0
) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCs ( rts , 0 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 )
; _ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; } } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
