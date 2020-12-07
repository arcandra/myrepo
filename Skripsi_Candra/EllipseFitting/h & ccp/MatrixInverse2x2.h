/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: MatrixInverse2x2
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-07-23/Candra Wardaya - UGM - 
 *************************************************************************/

#ifndef _MATRIXINVERSE2X2_H_
#define _MATRIXINVERSE2X2_H_

#include <basicfb.h>
#include <forte_real.h>

class FORTE_MatrixInverse2x2: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_MatrixInverse2x2)

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

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &ao() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  CIEC_REAL &bo() {
    return *static_cast<CIEC_REAL*>(getDO(1));
  };

  CIEC_REAL &co() {
    return *static_cast<CIEC_REAL*>(getDO(2));
  };

  CIEC_REAL &d_o() {
    return *static_cast<CIEC_REAL*>(getDO(3));
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
  CIEC_REAL &det() {
    return *static_cast<CIEC_REAL*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 4, 4, 1, 0);
  void alg_Calculate(void);
  void alg_Initialise(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInitialization = 1;
  static const TForteInt16 scm_nStateCalculation = 2;

  void enterStateSTART(void);
  void enterStateInitialization(void);
  void enterStateCalculation(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_MatrixInverse2x2(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_MatrixInverse2x2(){};

};

#endif //close the ifdef sequence from the beginning of the file

