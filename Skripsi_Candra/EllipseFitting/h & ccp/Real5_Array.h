/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Real5_Array
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-13/Candra Wardaya - UGM - 
 *************************************************************************/

#ifndef _REAL5_ARRAY_H_
#define _REAL5_ARRAY_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_array.h>

class FORTE_Real5_Array: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Real5_Array)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &A1() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &A2() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &A3() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &A4() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_REAL &A5() {
    return *static_cast<CIEC_REAL*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL *AO() {
    return (CIEC_REAL*)(*static_cast<CIEC_ARRAY *>(getDO(0)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &AO_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(0));
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

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(2, 5, 1, 0, 0);
  void alg_Initialize(void);
  void alg_Address(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInitialization = 1;
  static const TForteInt16 scm_nStateAddressing = 2;

  void enterStateSTART(void);
  void enterStateInitialization(void);
  void enterStateAddressing(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Real5_Array(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Real5_Array(){};

};

#endif //close the ifdef sequence from the beginning of the file

