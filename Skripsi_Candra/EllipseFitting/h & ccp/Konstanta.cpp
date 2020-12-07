/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Konstanta
 *** Description: Composite FB wrapping other FBs
 *** Version: 
 ***     1.0: 2020-08-06/Candra Wardaya - UGM - 
 *************************************************************************/

#include "Konstanta.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Konstanta_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Konstanta, g_nStringIdKonstanta)

const CStringDictionary::TStringId FORTE_Konstanta::scm_anDataInputNames[] = {g_nStringIdop, g_nStringIdpv};

const CStringDictionary::TStringId FORTE_Konstanta::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_Konstanta::scm_anDataOutputNames[] = {g_nStringIdconst_a, g_nStringIdconst_b};

const CStringDictionary::TStringId FORTE_Konstanta::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const TForteInt16 FORTE_Konstanta::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_Konstanta::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_Konstanta::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_Konstanta::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_Konstanta::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_Konstanta::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_Konstanta::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_Konstanta::scm_astInternalFBs[] = {
  {g_nStringIdd, g_nStringIdArrayCumulativeSquared},
  {g_nStringIdx1_squared, g_nStringIdArraySquared},
  {g_nStringIdMatrixMulReal_v1, g_nStringIdMatrixMulReal_v1},
  {g_nStringIda, g_nStringIdArrayCumulativeSquared},
  {g_nStringIdx2_cumulative, g_nStringIdArrayCumulative},
  {g_nStringIdReal_SqrtDenumerated_1, g_nStringIdReal_SqrtDenumerated},
  {g_nStringIdx1_cumulative, g_nStringIdArrayCumulative},
  {g_nStringIdReal_SqrtDenumerated_2, g_nStringIdReal_SqrtDenumerated},
  {g_nStringIdx2_squared, g_nStringIdArraySquared},
  {g_nStringIdb_dan_c, g_nStringIdArrayMulCumulative},
  {g_nStringIdMatrixInverse, g_nStringIdMatrixInverse2x2},
};

const SCFB_FBParameter FORTE_Konstanta::scm_astParamters[] = {
  {1, g_nStringIdLI, "512"},
  {8, g_nStringIdLI, "512"},
};

const SCFB_FBConnectionData FORTE_Konstanta::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixMulReal_v1, g_nStringIdINITO), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_SqrtDenumerated_2, g_nStringIdINIT), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_squared, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdb_dan_c, g_nStringIdREQ), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_squared, g_nStringIdINITO), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_cumulative, g_nStringIdINIT), 4},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_squared, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIda, g_nStringIdINIT), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_squared, g_nStringIdCNF), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdb_dan_c, g_nStringIdREQ), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixMulReal_v1, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_SqrtDenumerated_1, g_nStringIdREQ), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_squared, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_squared, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_SqrtDenumerated_2, g_nStringIdINITO), 7, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_SqrtDenumerated_2, g_nStringIdCNF), 7, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdb_dan_c, g_nStringIdINITO), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse, g_nStringIdINIT), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdb_dan_c, g_nStringIdCNF), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse, g_nStringIdREQ), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse, g_nStringIdINITO), 10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixMulReal_v1, g_nStringIdINIT), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse, g_nStringIdCNF), 10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixMulReal_v1, g_nStringIdREQ), 2},
};

const SCFB_FBFannedOutConnectionData FORTE_Konstanta::scm_astFannedOutEventConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_SqrtDenumerated_1, g_nStringIdINIT), 5},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_cumulative, g_nStringIdREQ), 6},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIda, g_nStringIdREQ), 3},
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdd, g_nStringIdINIT), 0},
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdb_dan_c, g_nStringIdINIT), 9},
  {3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_cumulative, g_nStringIdINIT), 6},
  {3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdb_dan_c, g_nStringIdINIT), 9},
  {4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_cumulative, g_nStringIdREQ), 4},
  {4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdd, g_nStringIdREQ), 0},
  {5, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_SqrtDenumerated_2, g_nStringIdREQ), 7},
  {6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_squared, g_nStringIdREQ), 8},
  {7, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_squared, g_nStringIdINIT), 8},
};

const SCFB_FBConnectionData FORTE_Konstanta::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_squared, g_nStringIdXo), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdd, g_nStringIdXi), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_squared, g_nStringIdXo), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdb_dan_c, g_nStringIdX1), 9},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_squared, g_nStringIdLO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIda, g_nStringIdLI), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_squared, g_nStringIdLO), 8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdd, g_nStringIdLI), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_cumulative, g_nStringIdXo), 6, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixMulReal_v1, g_nStringIdX1), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_cumulative, g_nStringIdXo), 4, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixMulReal_v1, g_nStringIdX2), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixMulReal_v1, g_nStringIdXo1), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_SqrtDenumerated_2, g_nStringIdXi), 7},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixMulReal_v1, g_nStringIdXo2), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_SqrtDenumerated_1, g_nStringIdXi), 5},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdop), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_squared, g_nStringIdXi), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdpv), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_squared, g_nStringIdXi), 8},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_SqrtDenumerated_2, g_nStringIdXo), 7, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_a), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_SqrtDenumerated_1, g_nStringIdXo), 5, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_b), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIda, g_nStringIdXo), 3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse, g_nStringIdai), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdb_dan_c, g_nStringIdXo), 9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse, g_nStringIdbi), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdd, g_nStringIdXo), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse, g_nStringIddi), 10},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse, g_nStringIdao), 10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixMulReal_v1, g_nStringIdai), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse, g_nStringIdbo), 10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixMulReal_v1, g_nStringIdbi), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse, g_nStringIdco), 10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixMulReal_v1, g_nStringIdci), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse, g_nStringIdd_o), 10, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixMulReal_v1, g_nStringIddi), 2},
};

const SCFB_FBFannedOutConnectionData FORTE_Konstanta::scm_astFannedOutDataConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_cumulative, g_nStringIdXi), 4},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdb_dan_c, g_nStringIdX2), 9},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIda, g_nStringIdXi), 3},
  {1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_cumulative, g_nStringIdXi), 6},
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdb_dan_c, g_nStringIdLI), 9},
  {3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx1_cumulative, g_nStringIdLI), 6},
  {3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdx2_cumulative, g_nStringIdLI), 4},
  {13, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse, g_nStringIdci), 10},
};

const SCFB_FBNData FORTE_Konstanta::scm_stFBNData = {
  11, scm_astInternalFBs,
  14, scm_astEventConnections,
  12, scm_astFannedOutEventConnections,
  19, scm_astDataConnections,
  8, scm_astFannedOutDataConnections,
  2, scm_astParamters
};


