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

#ifndef _MATRIX_INVERSE_H_
#define _MATRIX_INVERSE_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_uint.h>
#include <forte_array.h>

class FORTE_Matrix_Inverse: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Matrix_Inverse)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL *A1() {
    return (CIEC_REAL*)(*static_cast<CIEC_ARRAY *>(getDI(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &A1_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_UINT &p2() {
    return *static_cast<CIEC_UINT*>(getDO(0));
  };

  CIEC_UINT &c2() {
    return *static_cast<CIEC_UINT*>(getDO(1));
  };

  CIEC_REAL *AO() {
    return (CIEC_REAL*)(*static_cast<CIEC_ARRAY *>(getDO(2)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &AO_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(2));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_UINT &i() {
    return *static_cast<CIEC_UINT*>(getVarInternal(0));
  };

  CIEC_UINT &j() {
    return *static_cast<CIEC_UINT*>(getVarInternal(1));
  };

  CIEC_UINT &c1() {
    return *static_cast<CIEC_UINT*>(getVarInternal(2));
  };

  CIEC_REAL *B() {
    return (CIEC_REAL*)(*static_cast<CIEC_ARRAY *>(getVarInternal(3)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &B_Array() {
    return *static_cast<CIEC_ARRAY*>(getVarInternal(3));
  };

  CIEC_REAL &ratio() {
    return *static_cast<CIEC_REAL*>(getVarInternal(4));
  };

  CIEC_UINT &k() {
    return *static_cast<CIEC_UINT*>(getVarInternal(5));
  };

  CIEC_REAL &divisor() {
    return *static_cast<CIEC_REAL*>(getVarInternal(6));
  };

  CIEC_UINT &p() {
    return *static_cast<CIEC_UINT*>(getVarInternal(7));
  };

  CIEC_UINT &c() {
    return *static_cast<CIEC_UINT*>(getVarInternal(8));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 1, 3, 9, 0);

virtual void setInitialValues();
  void alg_Define_New_Size(void);
  void alg_Gauss_jordan_elimination(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateCHECK = 1;
  static const TForteInt16 scm_nStateCALCULATE = 2;

  void enterStateSTART(void);
  void enterStateCHECK(void);
  void enterStateCALCULATE(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Matrix_Inverse(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Matrix_Inverse(){};

};

#endif //close the ifdef sequence from the beginning of the file

