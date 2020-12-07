/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Real5_Array
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-13/Candra Wardaya - UGM - 
 *************************************************************************/

#include "Real5_Array.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Real5_Array_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Real5_Array, g_nStringIdReal5_Array)

const CStringDictionary::TStringId FORTE_Real5_Array::scm_anDataInputNames[] = {g_nStringIdA1, g_nStringIdA2, g_nStringIdA3, g_nStringIdA4, g_nStringIdA5};

const CStringDictionary::TStringId FORTE_Real5_Array::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_Real5_Array::scm_anDataOutputNames[] = {g_nStringIdAO};

const CStringDictionary::TStringId FORTE_Real5_Array::scm_anDataOutputTypeIds[] = {g_nStringIdARRAY, 5, g_nStringIdREAL};

const TForteInt16 FORTE_Real5_Array::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_Real5_Array::scm_anEIWith[] = {0, 1, 2, 3, 4, 255};
const CStringDictionary::TStringId FORTE_Real5_Array::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_Real5_Array::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Real5_Array::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_Real5_Array::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_Real5_Array::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_Real5_Array::alg_Initialize(void){

}

void FORTE_Real5_Array::alg_Address(void){
AO()[0] = A1();
AO()[1] = A2();
AO()[2] = A3();
AO()[3] = A4();
AO()[4] = A5();
}


void FORTE_Real5_Array::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Real5_Array::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_Real5_Array::enterStateAddressing(void){
  m_nECCState = scm_nStateAddressing;
  alg_Address();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Real5_Array::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateInitialization();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateAddressing();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialization:
        if((1))
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateAddressing:
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


