/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: c_bar_in
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-20/Administrator -  - 
 *************************************************************************/

#ifndef _C_BAR_IN_H_
#define _C_BAR_IN_H_

#include <basicfb.h>
#include <forte_real.h>

class FORTE_c_bar_in: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_c_bar_in)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &ai() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &bi() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &ci() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &di() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_REAL &x() {
    return *static_cast<CIEC_REAL*>(getDI(4));
  };

  CIEC_REAL &y() {
    return *static_cast<CIEC_REAL*>(getDI(5));
  };

  CIEC_REAL &const_4() {
    return *static_cast<CIEC_REAL*>(getDI(6));
  };

  CIEC_REAL &const_5() {
    return *static_cast<CIEC_REAL*>(getDI(7));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &c_bar() {
    return *static_cast<CIEC_REAL*>(getDO(0));
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
  CIEC_REAL &x2() {
    return *static_cast<CIEC_REAL*>(getVarInternal(0));
  };

  CIEC_REAL &y2() {
    return *static_cast<CIEC_REAL*>(getVarInternal(1));
  };

  CIEC_REAL &A() {
    return *static_cast<CIEC_REAL*>(getVarInternal(2));
  };

  CIEC_REAL &B() {
    return *static_cast<CIEC_REAL*>(getVarInternal(3));
  };

  CIEC_REAL &C() {
    return *static_cast<CIEC_REAL*>(getVarInternal(4));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 8, 1, 5, 0);
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
  FORTE_c_bar_in(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_c_bar_in(){};

};

#endif //close the ifdef sequence from the beginning of the file

