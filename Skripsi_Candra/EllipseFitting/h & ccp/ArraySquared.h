/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: ArraySquared
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-07-23/Candra Wardaya - UGM - 
 *************************************************************************/

#ifndef _ARRAYSQUARED_H_
#define _ARRAYSQUARED_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_int.h>
#include <forte_array.h>

class FORTE_ArraySquared: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_ArraySquared)

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
  CIEC_INT &L() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  CIEC_INT &i() {
    return *static_cast<CIEC_INT*>(getVarInternal(1));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 2, 2, 2, 0);
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
  FORTE_ArraySquared(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_ArraySquared(){};

};

#endif //close the ifdef sequence from the beginning of the file

