/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: c_bar
 *** Description: Composite FB wrapping other FBs
 *** Version: 
 ***     1.0: 2020-08-19/Candra Wardaya - UGM - 
 *************************************************************************/

#include "c_bar.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "c_bar_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_c_bar, g_nStringIdc_bar)

const CStringDictionary::TStringId FORTE_c_bar::scm_anDataInputNames[] = {g_nStringIdconst_1, g_nStringIdconst_2, g_nStringIdconst_3, g_nStringIdconst_4, g_nStringIdconst_5};

const CStringDictionary::TStringId FORTE_c_bar::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_c_bar::scm_anDataOutputNames[] = {g_nStringIdc_bar};

const CStringDictionary::TStringId FORTE_c_bar::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_c_bar::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_c_bar::scm_anEIWith[] = {0, 1, 2, 3, 4, 255};
const CStringDictionary::TStringId FORTE_c_bar::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_c_bar::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_c_bar::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_c_bar::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_c_bar::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_c_bar::scm_astInternalFBs[] = {
  {g_nStringIdReal_Half, g_nStringIdReal_Half},
  {g_nStringIdMatrixInverse2x2, g_nStringIdMatrixInverse2x2},
  {g_nStringIdt, g_nStringIdt},
  {g_nStringIdc_bar_in, g_nStringIdc_bar_in},
};

const SCFB_FBConnectionData FORTE_c_bar::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_Half, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_Half, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_Half, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse2x2, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_Half, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse2x2, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse2x2, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdt, g_nStringIdREQ), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse2x2, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdt, g_nStringIdINIT), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdt, g_nStringIdCNF), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIdREQ), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdt, g_nStringIdINITO), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIdINIT), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIdINITO), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIdCNF), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
};

const SCFB_FBConnectionData FORTE_c_bar::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_Half, g_nStringIdXo), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse2x2, g_nStringIdci), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_3), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_Half, g_nStringIdXi), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse2x2, g_nStringIdai), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse2x2, g_nStringIddi), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse2x2, g_nStringIdao), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdt, g_nStringIdai), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse2x2, g_nStringIdbo), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdt, g_nStringIdbi), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse2x2, g_nStringIdco), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdt, g_nStringIdci), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse2x2, g_nStringIdd_o), 1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdt, g_nStringIddi), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_4), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdt, g_nStringIdconst_4), 2},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_5), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdt, g_nStringIdconst_5), 2},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdt, g_nStringIdx), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIdx), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdt, g_nStringIdy), 2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIdy), 3},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIdc_bar), 3, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdc_bar), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_c_bar::scm_astFannedOutDataConnections[] = {
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMatrixInverse2x2, g_nStringIdbi), 1},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIdbi), 3},
  {0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIdci), 3},
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIdai), 3},
  {3, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIddi), 3},
  {8, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIdconst_4), 3},
  {9, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdc_bar_in, g_nStringIdconst_5), 3},
};

const SCFB_FBNData FORTE_c_bar::scm_stFBNData = {
  4, scm_astInternalFBs,
  10, scm_astEventConnections,
  0, 0,
  13, scm_astDataConnections,
  7, scm_astFannedOutDataConnections,
  0, 0
};


