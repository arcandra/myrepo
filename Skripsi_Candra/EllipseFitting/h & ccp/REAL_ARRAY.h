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

#ifndef _REAL_ARRAY_H_
#define _REAL_ARRAY_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_int.h>
#include <forte_array.h>

class FORTE_REAL_ARRAY: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_REAL_ARRAY)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_INT &LI() {
    return *static_cast<CIEC_INT*>(getDI(0));
  };

  CIEC_REAL &Xi() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &LO() {
    return *static_cast<CIEC_INT*>(getDO(0));
  };

  CIEC_REAL *Xo() {
    return (CIEC_REAL*)(*static_cast<CIEC_ARRAY *>(getDO(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &Xo_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(1));
  };

  static const TEventID scm_nEventSETID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventSETOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_INT &L() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  CIEC_INT &a() {
    return *static_cast<CIEC_INT*>(getVarInternal(1));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 2, 2, 2, 0);
  void alg_ComputeARRAY2(void);
  void alg_SendingARRAYLENGTH(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateOperation = 1;
  static const TForteInt16 scm_nStatePreOperation = 2;

  void enterStateSTART(void);
  void enterStateOperation(void);
  void enterStatePreOperation(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_REAL_ARRAY(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_REAL_ARRAY(){};

};

#endif //close the ifdef sequence from the beginning of the file

