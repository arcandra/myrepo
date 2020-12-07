/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: t
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-17/Candra Wardaya - UGM - 
 *************************************************************************/

#include "t.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "t_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_t, g_nStringIdt)

const CStringDictionary::TStringId FORTE_t::scm_anDataInputNames[] = {g_nStringIdai, g_nStringIdbi, g_nStringIdci, g_nStringIddi, g_nStringIdconst_4, g_nStringIdconst_5};

const CStringDictionary::TStringId FORTE_t::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_t::scm_anDataOutputNames[] = {g_nStringIdx, g_nStringIdy};

const CStringDictionary::TStringId FORTE_t::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const TForteInt16 FORTE_t::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_t::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 255};
const CStringDictionary::TStringId FORTE_t::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_t::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_t::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_t::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_t::scm_anInternalsNames[] = {g_nStringIdxi, g_nStringIdyi};

const CStringDictionary::TStringId FORTE_t::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_t::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  6,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_t::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_t::alg_Initialize(void){

}

void FORTE_t::alg_Calculate(void){
xi() = ai()*const_4()+bi()*const_5();
yi() = ci()*const_4()+di()*const_5();

x() = -0.5*xi();
y() = -0.5*yi();
}


void FORTE_t::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_t::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_t::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_t::executeEvent(int pa_nEIID){
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


