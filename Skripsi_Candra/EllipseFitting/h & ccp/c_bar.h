/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: c_bar
 *** Description: Composite FB wrapping other FBs
 *** Version: 
 ***     1.0: 2020-08-19/Candra Wardaya - UGM - 
 *************************************************************************/

#ifndef _C_BAR_H_
#define _C_BAR_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_real.h>

class FORTE_c_bar: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_c_bar)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &const_1() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &const_2() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  CIEC_REAL &const_3() {
    return *static_cast<CIEC_REAL*>(getDI(2));
  };

  CIEC_REAL &const_4() {
    return *static_cast<CIEC_REAL*>(getDI(3));
  };

  CIEC_REAL &const_5() {
    return *static_cast<CIEC_REAL*>(getDI(4));
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

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 5, 1, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_c_bar){
  };

  virtual ~FORTE_c_bar(){};

};

#endif //close the ifdef sequence from the beginning of the file

