/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: ArrayMulCumulative
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-07-22/Candra Wardaya - UGM - 
 *************************************************************************/

#include "ArrayMulCumulative.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "ArrayMulCumulative_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_ArrayMulCumulative, g_nStringIdArrayMulCumulative)

const CStringDictionary::TStringId FORTE_ArrayMulCumulative::scm_anDataInputNames[] = {g_nStringIdLI, g_nStringIdX1, g_nStringIdX2};

const CStringDictionary::TStringId FORTE_ArrayMulCumulative::scm_anDataInputTypeIds[] = {g_nStringIdINT, g_nStringIdARRAY, 512, g_nStringIdREAL, g_nStringIdARRAY, 512, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_ArrayMulCumulative::scm_anDataOutputNames[] = {g_nStringIdXo};

const CStringDictionary::TStringId FORTE_ArrayMulCumulative::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_ArrayMulCumulative::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_ArrayMulCumulative::scm_anEIWith[] = {0, 255, 0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_ArrayMulCumulative::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_ArrayMulCumulative::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_ArrayMulCumulative::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_ArrayMulCumulative::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_ArrayMulCumulative::scm_anInternalsNames[] = {g_nStringIdi, g_nStringIdval};

const CStringDictionary::TStringId FORTE_ArrayMulCumulative::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_ArrayMulCumulative::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_ArrayMulCumulative::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_ArrayMulCumulative::alg_Initialise(void){

}

void FORTE_ArrayMulCumulative::alg_Calculate(void){
val() = 0;
  {
    bool isi_Up = ((1) > 0);
    i() = 0;
    while(!(((isi_Up) && (i() > (LI()-1))) ||
            ((!isi_Up) && (i() < (LI()-1))))){

	val() = val()+X1()[i()]*X2()[i()];

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


void FORTE_ArrayMulCumulative::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_ArrayMulCumulative::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialise();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_ArrayMulCumulative::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_ArrayMulCumulative::executeEvent(int pa_nEIID){
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


