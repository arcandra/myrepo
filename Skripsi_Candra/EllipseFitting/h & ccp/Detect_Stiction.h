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

#ifndef _DETECT_STICTION_H_
#define _DETECT_STICTION_H_

#include <basicfb.h>
#include <forte_bool.h>
#include <forte_real.h>

class FORTE_Detect_Stiction: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Detect_Stiction)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &c_bar() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &val_1() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &val_2() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &vec_2() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &Status() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_REAL &St() {
    return *static_cast<CIEC_REAL*>(getDO(1));
  };

  CIEC_REAL &sud() {
    return *static_cast<CIEC_REAL*>(getDO(2));
  };

  CIEC_REAL &x2() {
    return *static_cast<CIEC_REAL*>(getDO(3));
  };

  CIEC_REAL &y2() {
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
  CIEC_REAL &x() {
    return *static_cast<CIEC_REAL*>(getVarInternal(0));
  };

  CIEC_REAL &y() {
    return *static_cast<CIEC_REAL*>(getVarInternal(1));
  };

  CIEC_REAL &pangkat_x() {
    return *static_cast<CIEC_REAL*>(getVarInternal(2));
  };

  CIEC_REAL &pangkat_y() {
    return *static_cast<CIEC_REAL*>(getVarInternal(3));
  };

  CIEC_REAL &x1() {
    return *static_cast<CIEC_REAL*>(getVarInternal(4));
  };

  CIEC_REAL &y1() {
    return *static_cast<CIEC_REAL*>(getVarInternal(5));
  };

  CIEC_REAL &x2_y2() {
    return *static_cast<CIEC_REAL*>(getVarInternal(6));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 4, 5, 7, 0);
  void alg_Initial(void);
  void alg_Calculate(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInitialization = 1;
  static const TForteInt16 scm_nStateCalculation = 2;

  void enterStateSTART(void);
  void enterStateInitialization(void);
  void enterStateCalculation(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Detect_Stiction(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Detect_Stiction(){};

};

#endif //close the ifdef sequence from the beginning of the file

