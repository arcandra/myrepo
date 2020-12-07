/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: eigval_in
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-19/Candra Wardaya - UGM - 
 *************************************************************************/

#include "eigval_in.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "eigval_in_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_eigval_in, g_nStringIdeigval_in)

const CStringDictionary::TStringId FORTE_eigval_in::scm_anDataInputNames[] = {g_nStringIdai, g_nStringIdbi, g_nStringIdci, g_nStringIddi};

const CStringDictionary::TStringId FORTE_eigval_in::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_eigval_in::scm_anDataOutputNames[] = {g_nStringIdval_1, g_nStringIdval_2};

const CStringDictionary::TStringId FORTE_eigval_in::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const TForteInt16 FORTE_eigval_in::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_eigval_in::scm_anEIWith[] = {0, 1, 2, 3, 255};
const CStringDictionary::TStringId FORTE_eigval_in::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_eigval_in::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_eigval_in::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_eigval_in::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_eigval_in::scm_anInternalsNames[] = {g_nStringIdA, g_nStringIdB, g_nStringIdC, g_nStringIdDi};

const CStringDictionary::TStringId FORTE_eigval_in::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_eigval_in::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_eigval_in::scm_stInternalVars = {4, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_eigval_in::alg_Initialize(void){

}

void FORTE_eigval_in::alg_Calculate(void){
A() = 1;
B() = -ai()-di();
C() = ai()*di()-bi()*ci();

Di() = EXPT((B()), (2))-4*A()*C();

val_2() = ((((-B()))+SQRT((Di()))))/((2*A()));
val_1() = ((((-B()))-SQRT((Di()))))/((2*A()));
}


void FORTE_eigval_in::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_eigval_in::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_eigval_in::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_eigval_in::executeEvent(int pa_nEIID){
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


