/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: ArrayCumulativeSquared
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-07-18/CandraWardaya - UGM - 
 *************************************************************************/

#include "ArrayCumulativeSquared.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "ArrayCumulativeSquared_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_ArrayCumulativeSquared, g_nStringIdArrayCumulativeSquared)

const CStringDictionary::TStringId FORTE_ArrayCumulativeSquared::scm_anDataInputNames[] = {g_nStringIdLI, g_nStringIdXi};

const CStringDictionary::TStringId FORTE_ArrayCumulativeSquared::scm_anDataInputTypeIds[] = {g_nStringIdINT, g_nStringIdARRAY, 512, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_ArrayCumulativeSquared::scm_anDataOutputNames[] = {g_nStringIdXo};

const CStringDictionary::TStringId FORTE_ArrayCumulativeSquared::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_ArrayCumulativeSquared::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_ArrayCumulativeSquared::scm_anEIWith[] = {0, 255, 1, 0, 255};
const CStringDictionary::TStringId FORTE_ArrayCumulativeSquared::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_ArrayCumulativeSquared::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_ArrayCumulativeSquared::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_ArrayCumulativeSquared::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_ArrayCumulativeSquared::scm_anInternalsNames[] = {g_nStringIdi, g_nStringIdX, g_nStringIdval};

const CStringDictionary::TStringId FORTE_ArrayCumulativeSquared::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_ArrayCumulativeSquared::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_ArrayCumulativeSquared::scm_stInternalVars = {3, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_ArrayCumulativeSquared::alg_CalculateReal(void){
val() = 0;
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (LI()-1))) ||
            ((!isi_Up) && (i() < (LI()-1))))){

	val() = val()+EXPT((Xi()[i()]), (2));

      if(((isi_Up) && ((1) > 0)) || 
         ((!isi_Up) && ((1) < 0))){
        i() = i() + (1);
      }
      else{
        i() = i() - (1);
      }
    }
  }
;
Xo() = val();
}

void FORTE_ArrayCumulativeSquared::alg_Initialization(void){

}


void FORTE_ArrayCumulativeSquared::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_ArrayCumulativeSquared::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_CalculateReal();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_ArrayCumulativeSquared::enterStateInitial(void){
  m_nECCState = scm_nStateInitial;
  alg_Initialization();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_ArrayCumulativeSquared::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateInitial();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateCalculation();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCalculation:
        if((1))
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitial:
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


