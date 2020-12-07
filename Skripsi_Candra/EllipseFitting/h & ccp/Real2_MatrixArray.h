/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Real2_MatrixArray
 *** Description: Basic FB with empty ECC
 *** Version: 
 ***     1.0: 2020-08-10/Candra Wardaya - UGM - 
 *************************************************************************/

#ifndef _REAL2_MATRIXARRAY_H_
#define _REAL2_MATRIXARRAY_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_int.h>
#include <forte_array.h>

class FORTE_Real2_MatrixArray: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Real2_MatrixArray)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &ai() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &bi() {
    return *static_cast<CIEC_REAL*>(getDI(1));
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

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_INT &i() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  CIEC_REAL &val() {
    return *static_cast<CIEC_REAL*>(getVarInternal(1));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 2, 1, 2, 0);
  void alg_Calculate(void);
  void alg_Initialize(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateCalculation = 1;
  static const TForteInt16 scm_nStateInitialization = 2;

  void enterStateSTART(void);
  void enterStateCalculation(void);
  void enterStateInitialization(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Real2_MatrixArray(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Real2_MatrixArray(){};

};

#endif //close the ifdef sequence from the beginning of the file

