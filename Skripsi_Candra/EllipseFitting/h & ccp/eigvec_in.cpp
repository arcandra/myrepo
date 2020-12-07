/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: eigvec_in
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-21/Administrator - null - 
 *************************************************************************/

#include "eigvec_in.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "eigvec_in_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_eigvec_in, g_nStringIdeigvec_in)

const CStringDictionary::TStringId FORTE_eigvec_in::scm_anDataInputNames[] = {g_nStringIdval_1, g_nStringIdval_2, g_nStringIdai, g_nStringIdbi, g_nStringIdci, g_nStringIddi};

const CStringDictionary::TStringId FORTE_eigvec_in::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_eigvec_in::scm_anDataOutputNames[] = {g_nStringIdvec_1, g_nStringIdvec_2, g_nStringIdvec_3, g_nStringIdvec_4};

const CStringDictionary::TStringId FORTE_eigvec_in::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const TForteInt16 FORTE_eigvec_in::scm_anEIWithIndexes[] = {-1, 0};
const TDataIOID FORTE_eigvec_in::scm_anEIWith[] = {0, 1, 2, 3, 4, 5, 255};
const CStringDictionary::TStringId FORTE_eigvec_in::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_eigvec_in::scm_anEOWith[] = {0, 1, 2, 3, 255};
const TForteInt16 FORTE_eigvec_in::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_eigvec_in::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_eigvec_in::scm_anInternalsNames[] = {g_nStringIdx1, g_nStringIdx2, g_nStringIdy1, g_nStringIdy2, g_nStringIddivisor, g_nStringIdx, g_nStringIdy, g_nStringIdx1_2, g_nStringIdx2_2, g_nStringIdm1, g_nStringIdm2, g_nStringIdm3, g_nStringIdm4};

const CStringDictionary::TStringId FORTE_eigvec_in::scm_anInternalsTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdREAL};

const SFBInterfaceSpec FORTE_eigvec_in::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  6,  scm_anDataInputNames, scm_anDataInputTypeIds,
  4,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_eigvec_in::scm_stInternalVars = {13, scm_anInternalsNames, scm_anInternalsTypeIds};

void FORTE_eigvec_in::alg_Initialise(void){

}

void FORTE_eigvec_in::alg_Calculate(void){
x1() = ai()-val_1();
x2() = bi();
y1() = ci();
y2() = di()-val_2();

x1_2() = EXPT((x1()), (2));
x2_2() = EXPT((x2()), (2));

x() = x1_2()+x2_2();

divisor() = SQRT((x()));

// /


if((((bi() > 0))) && (((di() < 0))) && (((ai() > 0))) && (((ABS((di())) > ai())))){// 1

	m1() = -1;
	m2() = 1;
	m3() = -1;
	m4() = 1;
}
else
  if((((bi() > 0))) && (((di() < 0))) && (((ai() < 0))) && (((ABS((di())) > ABS((ai())))))){// 2

	m1() = -1;
	m2() = 1;
	m3() = -1;
	m4() = 1;
}
else
  if((((bi() > 0))) && (((di() > 0))) && (((ai() > 0))) && (((di() > ai())))){// 3

	m1() = -1;
	m2() = -1;
	m3() = -1;
	m4() = -1;
}
else
  if((((bi() > 0))) && (((di() < 0))) && (((ai() < 0))) && (((abs((di())) == abs((ai())))))){// 4

	m1() = 1;
	m2() = -1;
	m3() = 1;
	m4() = -1;
}
else
  if((((bi() > 0))) && (((ai() < 0))) && (((di() > 0))) && (((ABS((ai())) > di())))){// 5

	m1() = -1;
	m2() = 1;
	m3() = -1;
	m4() = 1;
}
else
  if((((bi() < 0))) && (((ai() < 0))) && (((di() < 0))) && (((ABS((di())) > ABS((ai())))))){// 6

	m1() = -1;
	m2() = 1;
	m3() = -1;
	m4() = 1;
}
else
  if((((bi() < 0))) && (((ai() < 0))) && (((di() < 0))) && (((ABS((di())) < ABS((ai())))))){// 7

	m1() = 1;
	m2() = -1;
	m3() = 1;
	m4() = -1;
}
else
  if((((bi() < 0))) && (((ai() < 0))) && (((di() > 0))) && (((ABS((di())) < ABS((ai())))))){// 8

	m1() = 1;
	m2() = -1;
	m3() = 1;
	m4() = -1;
}
else
  if((((bi() < 0))) && (((ai() < 0))) && (((di() < 0))) && (((ABS((di())) == ABS((ai())))))){// 9

	m1() = -1;
	m2() = 1;
	m3() = -1;
	m4() = 1;
}
else{
	m1() = 1;
	m2() = 1;
	m3() = 1;
	m4() = 1;
};
	
// /


vec_1() = m1()*x2()/divisor();
vec_2() = m2()*-x1()/divisor();
vec_3() = m3()*y2()/divisor();
vec_4() = m4()*-y1()/divisor();
}


void FORTE_eigvec_in::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_eigvec_in::enterStateInitialization(void){
  m_nECCState = scm_nStateInitialization;
  alg_Initialise();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_eigvec_in::enterStateCalculation(void){
  m_nECCState = scm_nStateCalculation;
  alg_Calculate();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_eigvec_in::executeEvent(int pa_nEIID){
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


