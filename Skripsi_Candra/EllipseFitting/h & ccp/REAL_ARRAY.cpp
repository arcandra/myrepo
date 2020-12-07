/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: REAL_ARRAY
 *** Description: Tamplate for a simple Basic Function Block Type
 *** Version: 
 ***     0.0: 2019-03-10/4DIAC-IDE - 4DIAC-Consortium - 
 ***     1.0: 2016-05-26/AZ - fortiss GmbH - 
 *************************************************************************/

#include "REAL_ARRAY.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "REAL_ARRAY_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_REAL_ARRAY, g_nStringIdREAL_ARRAY)

const CStringDictionary::TStringId FORTE_REAL_ARRAY::scm_anDataInputNames[] = {g_nStringIdLI, g_nStringIdXi};

const CStringDictionary::TStringId FORTE_REAL_ARRAY::scm_anDataInputTypeIds[] = {g_nStringIdINT, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_REAL_ARRAY::scm_anDataOutputNames[] = {g_nStringIdLO, g_nStringIdXo};

const CStringDictionary::TStringId FORTE_REAL_ARRAY::scm_anDataOutputTypeIds[] = {g_nStringIdINT, g_nStringIdARRAY, 512, g_nStringIdREAL};

const TForteInt16 FORTE_REAL_ARRAY::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_REAL_ARRAY::scm_anEIWith[] = {0, 255, 0, 1, 255};
const CStringDictionary::TStringId FORTE_REAL_ARRAY::scm_anEventInputNames[] = {g_nStringIdSET, g_nStringIdREQ};

const TDataIOID FORTE_REAL_ARRAY::scm_anEOWith[] = {0, 255, 0, 1, 255};
const TForteInt16 FORTE_REAL_ARRAY::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_REAL_ARRAY::scm_anEventOutputNames[] = {g_nStringIdSETO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_REAL_ARRAY::scm_anInternalsNames[] = {g_nStringIdL, g_nStringIda};

const CStringDictionary::TStringId FORTE_REAL_ARRAY::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdINT};

const SFBInterfaceSpec FORTE_REAL_ARRAY::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_REAL_ARRAY::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_REAL_ARRAY::alg_ComputeARRAY2(void){
L() = LI();
  {
    bool isa_Up = ((1) > 0);
    a() = 1;
    while(!(((isa_Up) && (a() > (L()-1))) ||
            ((!isa_Up) && (a() < (L()-1))))){

	Xo()[a()-1] = Xo()[a()];// menggeser slot array

      if(((isa_Up) && ((1) > 0)) || 
         ((!isa_Up) && ((1) < 0))){
        a() = a() + (1);
      }
      else{
        a() = a() - (1);
      }
    }
  }
;
Xo()[L()-1] = Xi();//  memasukan nilai
LO() = L();// cuma menunjukkan
}

void FORTE_REAL_ARRAY::alg_SendingARRAYLENGTH(void){
LO() = LI();
}


void FORTE_REAL_ARRAY::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_REAL_ARRAY::enterStateOperation(void){
  m_nECCState = scm_nStateOperation;
  alg_ComputeARRAY2();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_REAL_ARRAY::enterStatePreOperation(void){
  m_nECCState = scm_nStatePreOperation;
  alg_SendingARRAYLENGTH();
  sendOutputEvent( scm_nEventSETOID);
}

void FORTE_REAL_ARRAY::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQID == pa_nEIID)
          enterStateOperation();
        else
        if(scm_nEventSETID == pa_nEIID)
          enterStatePreOperation();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateOperation:
        if((1))
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatePreOperation:
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


