/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: ArrayMulCumulative_Real5
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-15/Candra Wardaya - UGM - 
 *************************************************************************/

#include "ArrayMulCumulative_Real5.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "ArrayMulCumulative_Real5_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_ArrayMulCumulative_Real5, g_nStringIdArrayMulCumulative_Real5)

const CStringDictionary::TStringId FORTE_ArrayMulCumulative_Real5::scm_anDataInputNames[] = {g_nStringIdX, g_nStringIdY};

const CStringDictionary::TStringId FORTE_ArrayMulCumulative_Real5::scm_anDataInputTypeIds[] = {g_nStringIdARRAY, 25, g_nStringIdREAL, g_nStringIdARRAY, 5, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_ArrayMulCumulative_Real5::scm_anDataOutputNames[] = {g_nStringIdo1, g_nStringIdo2, g_nStringIdo3, g_nStringIdo4, g_nStringIdo5};

const CStringDictionary::TStringId FORTE_ArrayMulCumulative_Real5::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const TForteInt16 FORTE_ArrayMulCumulative_Real5::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_ArrayMulCumulative_Real5::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_ArrayMulCumulative_Real5::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_ArrayMulCumulative_Real5::scm_anEOWith[] = {0, 1, 2, 3, 4, 255};
const TForteInt16 FORTE_ArrayMulCumulative_Real5::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_ArrayMulCumulative_Real5::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_ArrayMulCumulative_Real5::scm_anInternalsNames[] = {g_nStringIdi, g_nStringIdval1};

const CStringDictionary::TStringId FORTE_ArrayMulCumulative_Real5::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_ArrayMulCumulative_Real5::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_ArrayMulCumulative_Real5::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_ArrayMulCumulative_Real5::alg_Initialize(void){

}

void FORTE_ArrayMulCumulative_Real5::alg_Calculate(void){
o1() = X()[0]*Y()[0]+X()[1]*Y()[1]+X()[2]*Y()[2]+X()[3]*Y()[3]+X()[4]*Y()[4];
o2() = X()[5]*Y()[0]+X()[6]*Y()[1]+X()[7]*Y()[2]+X()[8]*Y()[3]+X()[9]*Y()[4];
o3() = X()[10]*Y()[0]+X()[11]*Y()[1]+X()[12]*Y()[2]+X()[13]*Y()[3]+X()[14]*Y()[4];
o4() = X()[15]*Y()[0]+X()[16]*Y()[1]+X()[17]*Y()[2]+X()[18]*Y()[3]+X()[19]*Y()[4];
o5() = X()[20]*Y()[0]+X()[21]*Y()[1]+X()[22]*Y()[2]+X()[23]*Y()[3]+X()[24]*Y()[4];
}


void FORTE_ArrayMulCumulative_Real5::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_ArrayMulCumulative_Real5::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_ArrayMulCumulative_Real5::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_ArrayMulCumulative_Real5::executeEvent(int pa_nEIID){
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


