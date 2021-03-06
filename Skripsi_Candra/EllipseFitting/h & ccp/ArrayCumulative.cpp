/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: ArrayCumulative
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-07-16/Candra Wardaya - UGM - 
 *************************************************************************/

#include "ArrayCumulative.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "ArrayCumulative_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_ArrayCumulative, g_nStringIdArrayCumulative)

const CStringDictionary::TStringId FORTE_ArrayCumulative::scm_anDataInputNames[] = {g_nStringIdLI, g_nStringIdXi};

const CStringDictionary::TStringId FORTE_ArrayCumulative::scm_anDataInputTypeIds[] = {g_nStringIdINT, g_nStringIdARRAY, 512, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_ArrayCumulative::scm_anDataOutputNames[] = {g_nStringIdXo};

const CStringDictionary::TStringId FORTE_ArrayCumulative::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_ArrayCumulative::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_ArrayCumulative::scm_anEIWith[] = {0, 255, 0, 1, 255};
const CStringDictionary::TStringId FORTE_ArrayCumulative::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_ArrayCumulative::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_ArrayCumulative::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_ArrayCumulative::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_ArrayCumulative::scm_anInternalsNames[] = {g_nStringIdi, g_nStringIdval};

const CStringDictionary::TStringId FORTE_ArrayCumulative::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_ArrayCumulative::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_ArrayCumulative::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_ArrayCumulative::alg_CalculationReal(void){
val() = 0;
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (LI()-1))) ||
            ((!isi_Up) && (i() < (LI()-1))))){

	val() = val()+Xi()[i()];

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

void FORTE_ArrayCumulative::alg_Initialize(void){

}


void FORTE_ArrayCumulative::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_ArrayCumulative::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_ArrayCumulative::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_CalculationReal();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_ArrayCumulative::executeEvent(int pa_nEIID){
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


