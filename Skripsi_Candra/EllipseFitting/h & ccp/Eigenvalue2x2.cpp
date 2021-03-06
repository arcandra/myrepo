/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Eigenvalue2x2
 *** Description: Composite FB wrapping other FBs
 *** Version: 
 ***     1.0: 2020-08-19/Candra Wardaya - UGM - 
 *************************************************************************/

#include "Eigenvalue2x2.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Eigenvalue2x2_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Eigenvalue2x2, g_nStringIdEigenvalue2x2)

const CStringDictionary::TStringId FORTE_Eigenvalue2x2::scm_anDataInputNames[] = {g_nStringIdconst_1, g_nStringIdconst_2, g_nStringIdconst_3};

const CStringDictionary::TStringId FORTE_Eigenvalue2x2::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_Eigenvalue2x2::scm_anDataOutputNames[] = {g_nStringIdval_1, g_nStringIdval_2};

const CStringDictionary::TStringId FORTE_Eigenvalue2x2::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const TForteInt16 FORTE_Eigenvalue2x2::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_Eigenvalue2x2::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_Eigenvalue2x2::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_Eigenvalue2x2::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_Eigenvalue2x2::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_Eigenvalue2x2::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_Eigenvalue2x2::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SCFB_FBInstanceData FORTE_Eigenvalue2x2::scm_astInternalFBs[] = {
  {g_nStringIdReal_Half, g_nStringIdReal_Half},
  {g_nStringIdeigval_in, g_nStringIdeigval_in},
};

const SCFB_FBConnectionData FORTE_Eigenvalue2x2::scm_astEventConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdREQ), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_Half, g_nStringIdREQ), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINIT), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_Half, g_nStringIdINIT), 0},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_Half, g_nStringIdINITO), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdeigval_in, g_nStringIdINIT), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_Half, g_nStringIdCNF), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdeigval_in, g_nStringIdREQ), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdeigval_in, g_nStringIdINITO), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdINITO), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdeigval_in, g_nStringIdCNF), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdCNF), -1},
};

const SCFB_FBConnectionData FORTE_Eigenvalue2x2::scm_astDataConnections[] = {
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_3), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_Half, g_nStringIdXi), 0},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_1), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdeigval_in, g_nStringIdai), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdReal_Half, g_nStringIdXo), 0, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdeigval_in, g_nStringIdbi), 1},
  {GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdconst_2), -1, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdeigval_in, g_nStringIddi), 1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdeigval_in, g_nStringIdval_1), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdval_1), -1},
  {GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdeigval_in, g_nStringIdval_2), 1, GENERATE_CONNECTION_PORT_ID_1_ARG(g_nStringIdval_2), -1},
};

const SCFB_FBFannedOutConnectionData FORTE_Eigenvalue2x2::scm_astFannedOutDataConnections[] = {
  {2, GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdeigval_in, g_nStringIdci), 1},
};

const SCFB_FBNData FORTE_Eigenvalue2x2::scm_stFBNData = {
  2, scm_astInternalFBs,
  6, scm_astEventConnections,
  0, 0,
  6, scm_astDataConnections,
  1, scm_astFannedOutDataConnections,
  0, 0
};


