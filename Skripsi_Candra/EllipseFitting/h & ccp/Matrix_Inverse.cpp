/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Matrix_Inverse
 *** Description: Template for a simple Basic Function Block Type
 *** Version: 
 ***     1.0: 2020-08-06/Hafiezd - null - 
 ***     1.1: 2020-08-12/Candra Wardaya -  - 
 *************************************************************************/

#include "Matrix_Inverse.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "Matrix_Inverse_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_Matrix_Inverse, g_nStringIdMatrix_Inverse)

const CStringDictionary::TStringId FORTE_Matrix_Inverse::scm_anDataInputNames[] = {g_nStringIdA1};

const CStringDictionary::TStringId FORTE_Matrix_Inverse::scm_anDataInputTypeIds[] = {g_nStringIdARRAY, 25, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_Matrix_Inverse::scm_anDataOutputNames[] = {g_nStringIdp2, g_nStringIdc2, g_nStringIdAO};

const CStringDictionary::TStringId FORTE_Matrix_Inverse::scm_anDataOutputTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdARRAY, 25, g_nStringIdREAL};

const TForteInt16 FORTE_Matrix_Inverse::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_Matrix_Inverse::scm_anEIWith[] = {0, 255, 0, 255};
const CStringDictionary::TStringId FORTE_Matrix_Inverse::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_Matrix_Inverse::scm_anEOWith[] = {2, 0, 1, 255, 2, 0, 1, 255};
const TForteInt16 FORTE_Matrix_Inverse::scm_anEOWithIndexes[] = {0, 4, -1};
const CStringDictionary::TStringId FORTE_Matrix_Inverse::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const CStringDictionary::TStringId FORTE_Matrix_Inverse::scm_anInternalsNames[] = {g_nStringIdi, g_nStringIdj, g_nStringIdc1, g_nStringIdB, g_nStringIdratio, g_nStringIdk, g_nStringIddivisor, g_nStringIdp, g_nStringIdc};

const CStringDictionary::TStringId FORTE_Matrix_Inverse::scm_anInternalsTypeIds[] = {g_nStringIdUINT, g_nStringIdUINT, g_nStringIdUINT, g_nStringIdARRAY, 100, g_nStringIdREAL, g_nStringIdREAL, g_nStringIdUINT, g_nStringIdREAL, g_nStringIdUINT, g_nStringIdUINT};

const SFBInterfaceSpec FORTE_Matrix_Inverse::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  3,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_Matrix_Inverse::scm_stInternalVars = {9, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_Matrix_Inverse::setInitialValues(){
  p() = 5;
  c() = 5;
}

void FORTE_Matrix_Inverse::alg_Define_New_Size(void){
c2() = c();
p2() = p();
c1() = c()*2;
}

void FORTE_Matrix_Inverse::alg_Gauss_jordan_elimination(void){
  {
    bool isi_Up = ((1) > 0);
    i() = 1;
    while(!(((isi_Up) && (i() > (c()))) ||
            ((!isi_Up) && (i() < (c()))))){
																								/* Start Matrix augmentation */

	  {
    bool isj_Up = ((1) > 0);
    j() = 1;
    while(!(((isj_Up) && (j() > (c1()))) ||
            ((!isj_Up) && (j() < (c1()))))){

	
		if((i() == 1) && (j() <= c())){
			B()[c1()*i()+j()-((c1()+1))] = A1()[c1()*i()+j()-((c1()+1))];// input nilai
		
		}
else
  if((i() > 1) && (j() <= c())){
			B()[c1()*i()+j()-((c1()+1))] = A1()[c1()*i()+j()-((c1()+1))-((i()-1))*((c1()-c()))];
		
		}
else{
		//  matrix identitas
			if((i() == j()-c())){
				B()[c1()*i()+j()-((c1()+1))] = 1;
			}
else{
				B()[c1()*i()+j()-((c1()+1))] = 0;
			};
			
		};
		
	
      if(((isj_Up) && ((1) > 0)) || 
         ((!isj_Up) && ((1) < 0))){
        j() = j() + (1);
      }
      else{
        j() = j() - (1);
      }
    }
  }
;
	

      if(((isi_Up) && ((1) > 0)) || 
         ((!isi_Up) && ((1) < 0))){
        i() = i() + (1);
      }
      else{
        i() = i() - (1);
      }
    }
  }
;																													/* End Matrix augmentation */

  {
    bool isi_Up = ((1) > 0);
    i() = 1;
    while(!(((isi_Up) && (i() > (c()))) ||
            ((!isi_Up) && (i() < (c()))))){
																								/* Start Gauss Jordan Elimination */
	  {
    bool isj_Up = ((1) > 0);
    j() = 1;
    while(!(((isj_Up) && (j() > (c()))) ||
            ((!isj_Up) && (j() < (c()))))){

		if((i() != j())){
			ratio() = B()[((j()-1))*c1()+((i()-1))]/B()[i()*c1()-c1()+i()-1];
			
			  {
    bool isk_Up = ((1) > 0);
    k() = 1;
    while(!(((isk_Up) && (k() > (c1()))) ||
            ((!isk_Up) && (k() < (c1()))))){

				B()[c1()*j()+k()-((c1()+1))] = B()[c1()*j()+k()-((c1()+1))]-ratio()*B()[c1()*i()+k()-((c1()+1))];
			
      if(((isk_Up) && ((1) > 0)) || 
         ((!isk_Up) && ((1) < 0))){
        k() = k() + (1);
      }
      else{
        k() = k() - (1);
      }
    }
  }
;
			
		};
	
      if(((isj_Up) && ((1) > 0)) || 
         ((!isj_Up) && ((1) < 0))){
        j() = j() + (1);
      }
      else{
        j() = j() - (1);
      }
    }
  }
;

      if(((isi_Up) && ((1) > 0)) || 
         ((!isi_Up) && ((1) < 0))){
        i() = i() + (1);
      }
      else{
        i() = i() - (1);
      }
    }
  }
;																													/* End Gauss Jordan Elimination */

  {
    bool isi_Up = ((1) > 0);
    i() = 1;
    while(!(((isi_Up) && (i() > (c()))) ||
            ((!isi_Up) && (i() < (c()))))){
																								/* Start Row Operation */
	divisor() = B()[i()*c1()-c1()+((i()-1))];
	
	  {
    bool isj_Up = ((1) > 0);
    j() = 1;
    while(!(((isj_Up) && (j() > (c1()))) ||
            ((!isj_Up) && (j() < (c1()))))){

		B()[c1()*i()+j()-((c1()+1))] = B()[c1()*i()+j()-((c1()+1))]/divisor();
	
      if(((isj_Up) && ((1) > 0)) || 
         ((!isj_Up) && ((1) < 0))){
        j() = j() + (1);
      }
      else{
        j() = j() - (1);
      }
    }
  }
;


      if(((isi_Up) && ((1) > 0)) || 
         ((!isi_Up) && ((1) < 0))){
        i() = i() + (1);
      }
      else{
        i() = i() - (1);
      }
    }
  }
;																													/* End Row Operation */

  {
    bool isi_Up = ((1) > 0);
    i() = 1;
    while(!(((isi_Up) && (i() > (p2()))) ||
            ((!isi_Up) && (i() < (p2()))))){
																							/* Output Matrix Inverse Mapping*/

	  {
    bool isj_Up = ((1) > 0);
    j() = 1;
    while(!(((isj_Up) && (j() > (c2()))) ||
            ((!isj_Up) && (j() < (c2()))))){

		AO()[c2()*i()+j()-((c2()+1))] = B()[c2()*i()+j()-((c2()+1))+c2()*i()];
	
      if(((isj_Up) && ((1) > 0)) || 
         ((!isj_Up) && ((1) < 0))){
        j() = j() + (1);
      }
      else{
        j() = j() - (1);
      }
    }
  }
;
	

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
}


void FORTE_Matrix_Inverse::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_Matrix_Inverse::enterStateCHECK(void){
  m_nECCState = scm_nStateCHECK;
  alg_Define_New_Size();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_Matrix_Inverse::enterStateCALCULATE(void){
  m_nECCState = scm_nStateCALCULATE;
  alg_Gauss_jordan_elimination();
  sendOutputEvent( scm_nEventCNFID);
}

void FORTE_Matrix_Inverse::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateCHECK();
        else
        if(scm_nEventREQID == pa_nEIID)
          enterStateCALCULATE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCHECK:
        if((1))
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateCALCULATE:
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


