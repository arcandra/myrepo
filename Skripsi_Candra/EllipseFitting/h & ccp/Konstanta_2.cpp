/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Konstanta_2
 *** Description: Composite FB wrapping other FBs
 *** Version: 
 ***     1.0: 2020-08-15/Candra Wardaya - UGM - 
 *************************************************************************/

#include "Konstanta_2.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Konstanta_2_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Konstanta_2, g_nStringIdKonstanta_2)

const CStringDictionary::TStringId FORTE_Konstanta_2::scm_anDataInputNames[] = {g_nStringIdL, g_nStringIdop, g_nStringIdpv};

const CStringDictionary::TStringId FORTE_Konstanta_2::scm_anDataInputTypeIds[] = {g_nStringIdINT, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_Konstanta_2::scm_anDataOutputNames[] = {g_nStringIdconst_1, g_nStringIdconst_2, g_nStringIdconst_3, g_nStringIdconst_4, g_nStringIdconst_5};

const CStringDictionary::TStringId FORTE_Konstanta_2::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const TForteInt16 FORTE_Konstanta_2::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_Konstanta_2::scm_anEIWith[] = {1, 2, 255};
const CStringDictionary::TStringId FORTE_Konstanta_2::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_Konstanta_2::scm_anEOWith[] = {0, 1, 2, 3, 4, 255};
const TForteInt16 FORTE_Konstanta_2::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_Konstanta_2::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_Konstanta_2::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_Konstanta_2::setInitialValues(){
  L() = 512;
}


const SCFB_FBInstanceData FORTE_Konstanta_2::scm_astInternalFBs[] = {
  {g_nStringIdx2_sqrd_kumulatif_, g_nStringIdArrayCumulative},
  {g_nStringIdx1_sqrd_kumulatif, g_nStringIdArrayCumulative},
  {g_nStringIdReal5_Array, g_nStringIdReal5_Array},
  {g_nStringIdReal2_MatrixArray, g_nStringIdReal2_MatrixArray},
  {g_nStringIdx1x2_kumulatif, g_nStringIdArrayMulCumulative},
  {g_nStringIdMatrix_Inverse, g_nStringIdMatrix_Inverse},
  {g_nStringIdArrayMulCumulative_Real5, g_nStringIdArrayMulCumulative_Real5},
  {g_nStringIdx2_kumulatif, g_nStringIdArrayCumulative},
  {g_nStringIdx1_sqrd, g_nStringIdArraySquared},
  {g_nStringIdx2_sqrd, g_nStringIdArraySquared},
  {g_nStringIdx1_kumulatif, g_nStringIdArrayCumulative},
  {g_nStringIdx1, g_nStringIdREAL_ARRAY},
  {g_nStringIdx2, g_nStringIdREAL_ARRAY},
};

const SCFB_FBConnectionData FORTE_Konstanta_2::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd, g_nStringIdCNF), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd_kumulatif, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd_kumulatif, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal5_Array, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal5_Array, g_nStringIdINITO), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdArrayMulCumulative_Real5, g_nStringIdINIT), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal2_MatrixArray, g_nStringIdINITO), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrix_Inverse, g_nStringIdINIT), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_sqrd, g_nStringIdCNF), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_sqrd_kumulatif_, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd, g_nStringIdINITO), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd_kumulatif, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal2_MatrixArray, g_nStringIdCNF), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrix_Inverse, g_nStringIdREQ), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal5_Array, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdArrayMulCumulative_Real5, g_nStringIdREQ), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_sqrd, g_nStringIdINITO), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_sqrd_kumulatif_, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd_kumulatif, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal5_Array, g_nStringIdINIT), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal2_MatrixArray, g_nStringIdINIT), 3},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd, g_nStringIdREQ), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdArrayMulCumulative_Real5, g_nStringIdINITO), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdArrayMulCumulative_Real5, g_nStringIdCNF), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1, g_nStringIdSETO), 11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_kumulatif, g_nStringIdINIT), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1, g_nStringIdCNF), 11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_kumulatif, g_nStringIdREQ), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2, g_nStringIdSETO), 12, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_kumulatif, g_nStringIdINIT), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2, g_nStringIdCNF), 12, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_kumulatif, g_nStringIdREQ), 7},
};

const SCFB_FBFannedOutConnectionData FORTE_Konstanta_2::scm_astFannedOutEventConnections[] = {
  {10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd, g_nStringIdINIT), 8},
  {10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_sqrd, g_nStringIdINIT), 9},
  {10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1, g_nStringIdSET), 11},
  {10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2, g_nStringIdSET), 12},
  {11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_sqrd, g_nStringIdREQ), 9},
  {11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal2_MatrixArray, g_nStringIdREQ), 3},
  {11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1, g_nStringIdREQ), 11},
  {11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2, g_nStringIdREQ), 12},
  {14, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1x2_kumulatif, g_nStringIdINIT), 4},
  {15, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1x2_kumulatif, g_nStringIdREQ), 4},
};

const SCFB_FBConnectionData FORTE_Konstanta_2::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_kumulatif, g_nStringIdXo), 10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal5_Array, g_nStringIdA4), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_sqrd_kumulatif_, g_nStringIdXo), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal5_Array, g_nStringIdA2), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal5_Array, g_nStringIdAO), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdArrayMulCumulative_Real5, g_nStringIdY), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrix_Inverse, g_nStringIdAO), 5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdArrayMulCumulative_Real5, g_nStringIdX), 6},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_sqrd, g_nStringIdXo), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_sqrd_kumulatif_, g_nStringIdXi), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal2_MatrixArray, g_nStringIdAO), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrix_Inverse, g_nStringIdA1), 5},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1x2_kumulatif, g_nStringIdXo), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal5_Array, g_nStringIdA3), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_kumulatif, g_nStringIdXo), 7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal5_Array, g_nStringIdA5), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd, g_nStringIdXo), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd_kumulatif, g_nStringIdXi), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd_kumulatif, g_nStringIdXo), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal5_Array, g_nStringIdA1), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdop), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd, g_nStringIdXi), 8},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdpv), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_sqrd, g_nStringIdXi), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdArrayMulCumulative_Real5, g_nStringIdo1), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_1), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdArrayMulCumulative_Real5, g_nStringIdo2), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_2), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdArrayMulCumulative_Real5, g_nStringIdo3), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_3), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdArrayMulCumulative_Real5, g_nStringIdo4), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_4), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdArrayMulCumulative_Real5, g_nStringIdo5), 6, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_5), -1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdL), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd, g_nStringIdLI), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd, g_nStringIdLO), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_sqrd_kumulatif, g_nStringIdLI), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1, g_nStringIdXo), 11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_kumulatif, g_nStringIdXi), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2, g_nStringIdXo), 12, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_kumulatif, g_nStringIdXi), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1, g_nStringIdLO), 11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_kumulatif, g_nStringIdLI), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2, g_nStringIdLO), 12, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_kumulatif, g_nStringIdLI), 7},
};

const SCFB_FBFannedOutConnectionData FORTE_Konstanta_2::scm_astFannedOutDataConnections[] = {
  {10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal2_MatrixArray, g_nStringIdai), 3},
  {10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1, g_nStringIdXi), 11},
  {11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal2_MatrixArray, g_nStringIdbi), 3},
  {11, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2, g_nStringIdXi), 12},
  {17, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_sqrd, g_nStringIdLI), 9},
  {17, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1, g_nStringIdLI), 11},
  {17, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2, g_nStringIdLI), 12},
  {19, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1x2_kumulatif, g_nStringIdX1), 4},
  {20, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1x2_kumulatif, g_nStringIdX2), 4},
  {22, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1x2_kumulatif, g_nStringIdLI), 4},
  {22, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_sqrd_kumulatif_, g_nStringIdLI), 0},
};

const SCFB_FBNData FORTE_Konstanta_2::scm_stFBNData = {
  13, scm_astInternalFBs,
  18, scm_astEventConnections,
  10, scm_astFannedOutEventConnections,
  23, scm_astDataConnections,
  11, scm_astFannedOutDataConnections,
  0, 0
};


