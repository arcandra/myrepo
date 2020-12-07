/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Real_SqrtDenumerated
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-06/Candra Wardaya - UGM - 
 *************************************************************************/

#include "Real_SqrtDenumerated.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Real_SqrtDenumerated_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Real_SqrtDenumerated, g_nStringIdReal_SqrtDenumerated)

const CStringDictionary::TStringId FORTE_Real_SqrtDenumerated::scm_anDataInputNames[] = {g_nStringIdXi};

const CStringDictionary::TStringId FORTE_Real_SqrtDenumerated::scm_anDataInputTypeIds[] = {g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_Real_SqrtDenumerated::scm_anDataOutputNames[] = {g_nStringIdXo};

const CStringDictionary::TStringId FORTE_Real_SqrtDenumerated::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_Real_SqrtDenumerated::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_Real_SqrtDenumerated::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_Real_SqrtDenumerated::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_Real_SqrtDenumerated::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Real_SqrtDenumerated::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_Real_SqrtDenumerated::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_Real_SqrtDenumerated::scm_anInternalsNames[] = {g_nStringIdX};

const CStringDictionary::TStringId FORTE_Real_SqrtDenumerated::scm_anInternalsTypeIds[] = {g_nStringIdREAL};

const SFBInterfaceSpec FORTE_Real_SqrtDenumerated::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_Real_SqrtDenumerated::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_Real_SqrtDenumerated::alg_Initialise(void){

}

void FORTE_Real_SqrtDenumerated::alg_Calculate(void){
X() = 1/Xi();
Xo() = SQRT((X()));
}


void FORTE_Real_SqrtDenumerated::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Real_SqrtDenumerated::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialise();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_Real_SqrtDenumerated::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Real_SqrtDenumerated::executeEvent(int pa_nEIID){
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


