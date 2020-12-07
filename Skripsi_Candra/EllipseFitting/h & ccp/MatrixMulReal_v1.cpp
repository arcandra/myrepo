/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MatrixMulReal_v1
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-05/Candra Wardaya - UGM - 
 *************************************************************************/

#include "MatrixMulReal_v1.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "MatrixMulReal_v1_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_MatrixMulReal_v1, g_nStringIdMatrixMulReal_v1)

const CStringDictionary::TStringId FORTE_MatrixMulReal_v1::scm_anDataInputNames[] = {g_nStringIdai, g_nStringIdbi, g_nStringIdci, g_nStringIddi, g_nStringIdX1, g_nStringIdX2};

const CStringDictionary::TStringId FORTE_MatrixMulReal_v1::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_MatrixMulReal_v1::scm_anDataOutputNames[] = {g_nStringIdXo1, g_nStringIdXo2};

const CStringDictionary::TStringId FORTE_MatrixMulReal_v1::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const TForteInt16 FORTE_MatrixMulReal_v1::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_MatrixMulReal_v1::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 255};
const CStringDictionary::TStringId FORTE_MatrixMulReal_v1::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_MatrixMulReal_v1::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_MatrixMulReal_v1::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_MatrixMulReal_v1::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_MatrixMulReal_v1::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  6,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_MatrixMulReal_v1::alg_Initialise(void){

}

void FORTE_MatrixMulReal_v1::alg_Calculate(void){
Xo1() = ((ai()*X1()+bi()*X2()));
Xo2() = ((ci()*X1()+di()*X2()));
}


void FORTE_MatrixMulReal_v1::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_MatrixMulReal_v1::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialise();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_MatrixMulReal_v1::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_MatrixMulReal_v1::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateInitialization();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateCalculation();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialization:
        if((1))
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCalculation:
        if((1))
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 2.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


