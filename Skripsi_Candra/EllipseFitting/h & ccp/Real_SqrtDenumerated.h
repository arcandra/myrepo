/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Real_SqrtDenumerated
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-06/Candra Wardaya - UGM - 
 *************************************************************************/

#ifndef _REAL_SQRTDENUMERATED_H_
#define _REAL_SQRTDENUMERATED_H_

#include <basicfb.h>
#include <forte_real.h>

class FORTE_Real_SqrtDenumerated: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Real_SqrtDenumerated)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &Xi() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &Xo() {
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
  CIEC_REAL &X() {
    return *static_cast<CIEC_REAL*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 1, 1, 1, 0);
  void alg_Initialise(void);
  void alg_Calculate(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInitialization = 1;
  static const TForteInt16 scm_nStateCalculation = 2;

  void enterStateSTART(void);
  void enterStateInitialization(void);
  void enterStateCalculation(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Real_SqrtDenumerated(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Real_SqrtDenumerated(){};

};

#endif //close the ifdef sequence from the beginning of the file

