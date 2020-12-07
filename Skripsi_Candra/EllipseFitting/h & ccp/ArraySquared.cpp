/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: ArraySquared
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-07-23/Candra Wardaya - UGM - 
 *************************************************************************/

#include "ArraySquared.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "ArraySquared_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_ArraySquared, g_nStringIdArraySquared)

const CStringDictionary::TStringId FORTE_ArraySquared::scm_anDataInputNames[] = {g_nStringIdLI, g_nStringIdXi};

const CStringDictionary::TStringId FORTE_ArraySquared::scm_anDataInputTypeIds[] = {g_nStringIdINT, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_ArraySquared::scm_anDataOutputNames[] = {g_nStringIdLO, g_nStringIdXo};

const CStringDictionary::TStringId FORTE_ArraySquared::scm_anDataOutputTypeIds[] = {g_nStringIdINT, g_nStringIdARRAY, 512, g_nStringIdREAL};

const TForteInt16 FORTE_ArraySquared::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_ArraySquared::scm_anEIWith[] = {0, 255, 0, 1, 255};
const CStringDictionary::TStringId FORTE_ArraySquared::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_ArraySquared::scm_anEOWith[] = {0, 255, 0, 1, 255};
const TForteInt16 FORTE_ArraySquared::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_ArraySquared::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_ArraySquared::scm_anInternalsNames[] = {g_nStringIdL, g_nStringIdi};

const CStringDictionary::TStringId FORTE_ArraySquared::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdINT};

const SFBInterfaceSpec FORTE_ArraySquared::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_ArraySquared::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_ArraySquared::alg_Initialise(void){

}

void FORTE_ArraySquared::alg_Calculate(void){
L() = LI();

  {
    bool isi_Up = ((1) > 0);
    i() = 1;
    while(!(((isi_Up) && (i() > (L()-1))) ||
            ((!isi_Up) && (i() < (L()-1))))){

	Xo()[i()-1] = Xo()[i()];

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

Xo()[L()-1] = Xi()*Xi();

LO() = L();
}


void FORTE_ArraySquared::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_ArraySquared::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialise();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_ArraySquared::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_ArraySquared::executeEvent(int pa_nEIID){
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


