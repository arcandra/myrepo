/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Konstanta
 *** Description: Composite FB wrapping other FBs
 *** Version: 
 ***     1.0: 2020-08-06/Candra Wardaya - UGM - 
 *************************************************************************/

#ifndef _KONSTANTA_H_
#define _KONSTANTA_H_

#include <cfb.h>
#include <typelib.h>
#include <forte_real.h>

class FORTE_Konstanta: public CCompositeFB{
  DECLARE_FIRMWARE_FB(FORTE_Konstanta)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &op() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &pv() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &const_a() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  CIEC_REAL &const_b() {
    return *static_cast<CIEC_REAL*>(getDO(1));
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

   FORTE_FB_DATA_ARRAY(2, 2, 2, 0);

  static const SCFB_FBInstanceData scm_astInternalFBs[];

  static const SCFB_FBParameter scm_astParamters[];

  static const SCFB_FBConnectionData scm_astEventConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutEventConnections[];

  static const SCFB_FBConnectionData scm_astDataConnections[];

  static const SCFB_FBFannedOutConnectionData scm_astFannedOutDataConnections[];
  static const SCFB_FBNData scm_stFBNData;

public:
  COMPOSITE_FUNCTION_BLOCK_CTOR(FORTE_Konstanta){
  };

  virtual ~FORTE_Konstanta(){};

};

#endif //close the ifdef sequence from the beginning of the file

