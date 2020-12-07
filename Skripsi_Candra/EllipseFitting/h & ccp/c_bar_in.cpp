/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: c_bar_in
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-20/Administrator -  - 
 *************************************************************************/

#include "c_bar_in.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "c_bar_in_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_c_bar_in, g_nStringIdc_bar_in)

const CStringDictionary::TStringId FORTE_c_bar_in::scm_anDataInputNames[] = {g_nStringIdai, g_nStringIdbi, g_nStringIdci, g_nStringIddi, g_nStringIdx, g_nStringIdy, g_nStringIdconst_4, g_nStringIdconst_5};

const CStringDictionary::TStringId FORTE_c_bar_in::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_c_bar_in::scm_anDataOutputNames[] = {g_nStringIdc_bar};

const CStringDictionary::TStringId FORTE_c_bar_in::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_c_bar_in::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_c_bar_in::scm_anEIWith[] = {0, 1, 2, 4, 3, 5, 7, 6, 255};
const CStringDictionary::TStringId FORTE_c_bar_in::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_c_bar_in::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_c_bar_in::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_c_bar_in::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_c_bar_in::scm_anInternalsNames[] = {g_nStringIdx2, g_nStringIdy2, g_nStringIdA, g_nStringIdB, g_nStringIdC};

const CStringDictionary::TStringId FORTE_c_bar_in::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_c_bar_in::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  8,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_c_bar_in::scm_stInternalVars = {5, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_c_bar_in::alg_Initialize(void){

}

void FORTE_c_bar_in::alg_Calculate(void){
// A

x2() = x()*ai()+y()*ci();
y2() = x()*bi()+y()*di();

A() = x2()*x()+y2()*y();

// B

B() = const_4()*x()+const_5()*y();

// C = -1


// 

c_bar() = A()+B()-1;
}


void FORTE_c_bar_in::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_c_bar_in::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_c_bar_in::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_c_bar_in::executeEvent(int pa_nEIID){
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


