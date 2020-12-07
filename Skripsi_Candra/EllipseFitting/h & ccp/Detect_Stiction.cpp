/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Detect_Stiction
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-21/Candra Wardaya - UGM - 
 *************************************************************************/

#include "Detect_Stiction.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Detect_Stiction_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Detect_Stiction, g_nStringIdDetect_Stiction)

const CStringDictionary::TStringId FORTE_Detect_Stiction::scm_anDataInputNames[] = {g_nStringIdc_bar, g_nStringIdval_1, g_nStringIdval_2, g_nStringIdvec_2};

const CStringDictionary::TStringId FORTE_Detect_Stiction::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_Detect_Stiction::scm_anDataOutputNames[] = {g_nStringIdStatus, g_nStringIdSt, g_nStringIdsud, g_nStringIdx2, g_nStringIdy2};

const CStringDictionary::TStringId FORTE_Detect_Stiction::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const TForteInt16 FORTE_Detect_Stiction::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_Detect_Stiction::scm_anEIWith[] = {0, 1, 2, 3, 255};
const CStringDictionary::TStringId FORTE_Detect_Stiction::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_Detect_Stiction::scm_anEOWith[] = {0, 1, 2, 4, 3, 255};
const TForteInt16 FORTE_Detect_Stiction::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_Detect_Stiction::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_Detect_Stiction::scm_anInternalsNames[] = {g_nStringIdx, g_nStringIdy, g_nStringIdpangkat_x, g_nStringIdpangkat_y, g_nStringIdx1, g_nStringIdy1, g_nStringIdx2_y2};

const CStringDictionary::TStringId FORTE_Detect_Stiction::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_Detect_Stiction::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_Detect_Stiction::scm_stInternalVars = {7, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_Detect_Stiction::alg_Initial(void){

}

void FORTE_Detect_Stiction::alg_Calculate(void){
//  m & n // x & y


x1() = ((-c_bar()))/val_1();
y1() = ((-c_bar()))/val_2();

x() = SQRT((x1()));
y() = SQRT((y1()));

sud() = acos((vec_2()));

pangkat_x() = ((sin((sud()))))*((sin((sud()))));
pangkat_y() = ((cos((sud()))))*((cos((sud()))));

x2() = ((EXPT((y()), (2))))*pangkat_x();
y2() = ((EXPT((x()), (2))))*pangkat_y();

if((val_1() > 0) && (val_2() > 0) && (c_bar() < 0) && (x() != y())){
	Status() = true;
	x2_y2() = x2()+y2();
	St() = 2*x()*y()/SQRT((x2_y2()));
}
else{
	Status() = false;
	St() = 0;
};

}


void FORTE_Detect_Stiction::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Detect_Stiction::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initial();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_Detect_Stiction::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Detect_Stiction::executeEvent(int pa_nEIID){
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


