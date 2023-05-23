#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "in_gps_estimation_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#else
#include "builtin_typeid_types.h"
#include "in_gps_estimation.h"
#include "in_gps_estimation_capi.h"
#include "in_gps_estimation_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"in_gps_estimation/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
1 , 0 , TARGET_STRING ( "in_gps_estimation/Gain3" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "in_gps_estimation/Gain8" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"in_gps_estimation/Divide" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
4 , 0 , TARGET_STRING ( "in_gps_estimation/S-Function" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"in_gps_estimation/S-Function16" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 6 , 0 , TARGET_STRING ( "in_gps_estimation/S-Function2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"in_gps_estimation/S-Function5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 8 , 0 , TARGET_STRING ( "in_gps_estimation/Add4" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"in_gps_estimation/Manual Switch" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 10 , 0 , TARGET_STRING ( "in_gps_estimation/Transfer Fcn" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"in_gps_estimation/Difference/Diff" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 12 , TARGET_STRING (
"in_gps_estimation/Difference" ) , TARGET_STRING ( "ICPrevInput" ) , 0 , 0 ,
0 } , { 13 , TARGET_STRING ( "in_gps_estimation/Constant2" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 14 , TARGET_STRING (
"in_gps_estimation/Constant3" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
15 , TARGET_STRING ( "in_gps_estimation/Gain" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 16 , TARGET_STRING ( "in_gps_estimation/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 17 , TARGET_STRING (
"in_gps_estimation/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 18 ,
TARGET_STRING ( "in_gps_estimation/Gain3" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 19 , TARGET_STRING ( "in_gps_estimation/Gain7" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 20 , TARGET_STRING ( "in_gps_estimation/Gain8" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 21 , TARGET_STRING (
"in_gps_estimation/S-Function" ) , TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , {
22 , TARGET_STRING ( "in_gps_estimation/S-Function" ) , TARGET_STRING ( "P2"
) , 0 , 0 , 0 } , { 23 , TARGET_STRING ( "in_gps_estimation/S-Function" ) ,
TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , { 24 , TARGET_STRING (
"in_gps_estimation/S-Function16" ) , TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , {
25 , TARGET_STRING ( "in_gps_estimation/S-Function16" ) , TARGET_STRING (
"P2" ) , 0 , 0 , 0 } , { 26 , TARGET_STRING (
"in_gps_estimation/S-Function16" ) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , {
27 , TARGET_STRING ( "in_gps_estimation/S-Function2" ) , TARGET_STRING ( "P1"
) , 0 , 0 , 0 } , { 28 , TARGET_STRING ( "in_gps_estimation/S-Function2" ) ,
TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , { 29 , TARGET_STRING (
"in_gps_estimation/S-Function2" ) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , {
30 , TARGET_STRING ( "in_gps_estimation/S-Function3" ) , TARGET_STRING ( "P1"
) , 0 , 0 , 0 } , { 31 , TARGET_STRING ( "in_gps_estimation/S-Function3" ) ,
TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , { 32 , TARGET_STRING (
"in_gps_estimation/S-Function3" ) , TARGET_STRING ( "P3" ) , 0 , 1 , 0 } , {
33 , TARGET_STRING ( "in_gps_estimation/S-Function3" ) , TARGET_STRING ( "P4"
) , 0 , 0 , 0 } , { 34 , TARGET_STRING ( "in_gps_estimation/S-Function5" ) ,
TARGET_STRING ( "P1" ) , 0 , 0 , 0 } , { 35 , TARGET_STRING (
"in_gps_estimation/S-Function5" ) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , {
36 , TARGET_STRING ( "in_gps_estimation/S-Function5" ) , TARGET_STRING ( "P4"
) , 0 , 0 , 0 } , { 37 , TARGET_STRING ( "in_gps_estimation/Sine Wave" ) ,
TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING (
"in_gps_estimation/Sine Wave" ) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , {
39 , TARGET_STRING ( "in_gps_estimation/Sine Wave" ) , TARGET_STRING (
"Frequency" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"in_gps_estimation/Sine Wave" ) , TARGET_STRING ( "Phase" ) , 0 , 0 , 0 } , {
41 , TARGET_STRING ( "in_gps_estimation/Step" ) , TARGET_STRING ( "Time" ) ,
0 , 0 , 0 } , { 42 , TARGET_STRING ( "in_gps_estimation/Step" ) ,
TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 43 , TARGET_STRING (
"in_gps_estimation/Step" ) , TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 44 ,
TARGET_STRING ( "in_gps_estimation/Manual Switch" ) , TARGET_STRING (
"CurrentSetting" ) , 1 , 0 , 0 } , { 45 , TARGET_STRING (
"in_gps_estimation/Transfer Fcn" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , {
46 , TARGET_STRING ( "in_gps_estimation/Transfer Fcn" ) , TARGET_STRING ( "C"
) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals
rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters
rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . fa5bpj2f2b , & rtB . orzekcshh1 ,
& rtB . mqkohde3av , & rtB . jvz2qkejcz , & rtB . ixicelz4a0 , & rtB .
apwxdnsmjg , & rtB . jdacxbno0x , & rtB . imhbzzo51g , & rtB . k3khppcoob , &
rtB . n4bmglhsm1 , & rtB . gho24r3wjp , & rtB . f0b2eyvx0s , & rtP .
Difference_ICPrevInput , & rtP . Constant2_Value , & rtP . Constant3_Value ,
& rtP . Gain_Gain , & rtP . Gain1_Gain , & rtP . Gain2_Gain , & rtP .
Gain3_Gain , & rtP . Gain7_Gain , & rtP . Gain8_Gain , & rtP . SFunction_P1 ,
& rtP . SFunction_P2 , & rtP . SFunction_P4 , & rtP . SFunction16_P1 , & rtP
. SFunction16_P2 , & rtP . SFunction16_P4 , & rtP . SFunction2_P1 , & rtP .
SFunction2_P2 , & rtP . SFunction2_P4 , & rtP . SFunction3_P1 , & rtP .
SFunction3_P2 , & rtP . SFunction3_P3 [ 0 ] , & rtP . SFunction3_P4 , & rtP .
SFunction5_P1 , & rtP . SFunction5_P2 , & rtP . SFunction5_P4 , & rtP .
SineWave_Amp , & rtP . SineWave_Bias , & rtP . SineWave_Freq , & rtP .
SineWave_Phase , & rtP . Step_Time , & rtP . Step_Y0 , & rtP . Step_YFinal ,
& rtP . ManualSwitch_CurrentSetting , & rtP . TransferFcn_A , & rtP .
TransferFcn_C , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 4 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 , 0.0005 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , (
boolean_T ) 0 } , } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ]
= { { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] ,
( int8_T ) 1 , ( uint8_T ) 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 12 , rtRootInputs , 0 , rtRootOutputs , 0 }
, { rtBlockParameters , 35 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 2226012495U , 2004764594U , 3757314384U ,
185473456U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * in_gps_estimation_GetCAPIStaticMap (
void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void in_gps_estimation_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion (
( * rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void in_gps_estimation_host_InitializeDataMapInfo (
in_gps_estimation_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
