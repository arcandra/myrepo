/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Real2_MatrixArray
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-10/Candra Wardaya - UGM - 
 *************************************************************************/

#include "Real2_MatrixArray.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Real2_MatrixArray_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Real2_MatrixArray, g_nStringIdReal2_MatrixArray)

const CStringDictionary::TStringId FORTE_Real2_MatrixArray::scm_anDataInputNames[] = {g_nStringIdai, g_nStringIdbi};

const CStringDictionary::TStringId FORTE_Real2_MatrixArray::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_Real2_MatrixArray::scm_anDataOutputNames[] = {g_nStringIdAO};

const CStringDictionary::TStringId FORTE_Real2_MatrixArray::scm_anDataOutputTypeIds[] = {g_nStringIdARRAY, 25, g_nStringIdREAL};

const TForteInt16 FORTE_Real2_MatrixArray::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_Real2_MatrixArray::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_Real2_MatrixArray::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_Real2_MatrixArray::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_Real2_MatrixArray::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_Real2_MatrixArray::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_Real2_MatrixArray::scm_anInternalsNames[] = {g_nStringIdi, g_nStringIdval};

const CStringDictionary::TStringId FORTE_Real2_MatrixArray::scm_anInternalsTypeIds[] = {g_nStringIdINT, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_Real2_MatrixArray::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_Real2_MatrixArray::scm_stInternalVars = {2, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_Real2_MatrixArray::alg_Calculate(void){
AO()[0] = AO()[0]+EXPT((ai()), (4));
AO()[1] = AO()[1]+((ai()*ai()))*((bi()*bi()));
AO()[2] = AO()[2]+((ai()*ai()))*((ai()*bi()));
AO()[3] = AO()[3]+((ai()*ai()))*ai();
AO()[4] = AO()[4]+((ai()*ai()))*bi();
AO()[5] = AO()[5]+((bi()*bi()))*((ai()*ai()));// [2][1]

AO()[6] = AO()[6]+((bi()*bi()))*((bi()*bi()));
AO()[7] = AO()[7]+((bi()*bi()))*((ai()*bi()));
AO()[8] = AO()[8]+((bi()*bi()))*((ai()));
AO()[9] = AO()[9]+((bi()*bi()))*((bi()));
AO()[10] = AO()[10]+((ai()*bi()))*((ai()*ai()));// [3][1]

AO()[11] = AO()[11]+((ai()*bi()))*((bi()*bi()));
AO()[12] = AO()[12]+((ai()*bi()))*((ai()*bi()));
AO()[13] = AO()[13]+((ai()*bi()))*((ai()));
AO()[14] = AO()[14]+((ai()*bi()))*((bi()));
AO()[15] = AO()[15]+((ai()))*((ai()*ai()));// [4][1]

AO()[16] = AO()[16]+((ai()))*((bi()*bi()));
AO()[17] = AO()[17]+((ai()))*((ai()*bi()));
AO()[18] = AO()[18]+((ai()))*((ai()));
AO()[19] = AO()[19]+((ai()))*((bi()));
AO()[20] = AO()[20]+((bi()))*((ai()*ai()));// [5][1]

AO()[21] = AO()[21]+((bi()))*((bi()*bi()));
AO()[22] = AO()[22]+((bi()))*((ai()*bi()));
AO()[23] = AO()[23]+((bi()))*((ai()));
AO()[24] = AO()[24]+((bi()))*((bi()));
}

void FORTE_Real2_MatrixArray::alg_Initialize(void){

}


void FORTE_Real2_MatrixArray::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Real2_MatrixArray::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Real2_MatrixArray::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_Real2_MatrixArray::executeEvent(int pa_nEIID){
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
      case scm_nStateCalculation:
        if((1))
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialization:
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


