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

#ifndef _ARRAYMULCUMULATIVE_REAL5_H_
#define _ARRAYMULCUMULATIVE_REAL5_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_int.h>
#include <forte_array.h>

class FORTE_ArrayMulCumulative_Real5: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_ArrayMulCumulative_Real5)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL *X() {
    return (CIEC_REAL*)(*static_cast<CIEC_ARRAY *>(getDI(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &X_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(0));
  };

  CIEC_REAL *Y() {
    return (CIEC_REAL*)(*static_cast<CIEC_ARRAY *>(getDI(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &Y_Array() {
    return *static_cast<CIEC_ARRAY*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &o1() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  CIEC_REAL &o2() {
    return *static_cast<CIEC_REAL*>(getDO(1));
  };

  CIEC_REAL &o3() {
    return *static_cast<CIEC_REAL*>(getDO(2));
  };

  CIEC_REAL &o4() {
    return *static_cast<CIEC_REAL*>(getDO(3));
  };

  CIEC_REAL &o5() {
    return *static_cast<CIEC_REAL*>(getDO(4));
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
  CIEC_INT &i() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  CIEC_REAL &val1() {
    return *static_cast<CIEC_REAL*>(getVarInternal(1));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 2, 5, 2, 0);
  void alg_Initialize(void);
  void alg_Calculate(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInitialization = 1;
  static const TForteInt16 scm_nStateCalculation = 2;

  void enterStateSTART(void);
  void enterStateInitialization(void);
  void enterStateCalculation(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_ArrayMulCumulative_Real5(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_ArrayMulCumulative_Real5(){};

};

#endif //close the ifdef sequence from the beginning of the file

