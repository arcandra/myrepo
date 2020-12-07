/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MatrixInverse
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-07-23/Candra Wardaya - UGM - 
 *************************************************************************/

#include "MatrixInverse.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "MatrixInverse_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_MatrixInverse, g_nStringIdMatrixInverse)

const CStringDictionary::TStringId FORTE_MatrixInverse::scm_anDataInputNames[] = {g_nStringIdai, g_nStringIdbi, g_nStringIdci, g_nStringIddi};

const CStringDictionary::TStringId FORTE_MatrixInverse::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_MatrixInverse::scm_anDataOutputNames[] = {g_nStringIdao, g_nStringIdbo, g_nStringIdco, g_nStringIdd_o};

const CStringDictionary::TStringId FORTE_MatrixInverse::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const TForteInt16 FORTE_MatrixInverse::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_MatrixInverse::scm_anEIWith[] = {0, 1, 2, 3, 255};
const CStringDictionary::TStringId FORTE_MatrixInverse::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_MatrixInverse::scm_anEOWith[] = {0, 1, 2, 3, 255};
const TForteInt16 FORTE_MatrixInverse::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_MatrixInverse::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_MatrixInverse::scm_anInternalsNames[] = {g_nStringIddet};

const CStringDictionary::TStringId FORTE_MatrixInverse::scm_anInternalsTypeIds[] = {g_nStringIdREAL};

const SFBInterfaceSpec FORTE_MatrixInverse::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  4,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_MatrixInverse::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_MatrixInverse::alg_Calculate(void){
det() = 1/((ai()*di()-ci()*bi()));// determinant

ao() = di()*det();
bo() = -bi()*det();
co() = -ci()*det();
d_o() = ai()*det();
}

void FORTE_MatrixInverse::alg_Initialise(void){

}


void FORTE_MatrixInverse::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_MatrixInverse::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialise();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_MatrixInverse::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_MatrixInverse::executeEvent(int pa_nEIID){
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


