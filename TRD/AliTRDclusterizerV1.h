#ifndef TRDclusterizerV1_h
#define TRDclusterizerV1_h
/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

/* $Id$ */

#include "AliTRD.h"
#include "AliTRDdigitsManager.h"
#include "AliTRDclusterizer.h"

///////////////////////////////////////////////////////
//  Finds and handles cluster (slow simulation)      //
///////////////////////////////////////////////////////

class AliTRDclusterizerV1 : public AliTRDclusterizer {

 public:

  AliTRDclusterizerV1();
  AliTRDclusterizerV1(const Text_t* name, const Text_t* title);
  ~AliTRDclusterizerV1();

  virtual void    Init();
  virtual Bool_t  MakeCluster();
  virtual Bool_t  ReadDigits();

  virtual void    SetClusMaxThresh(Float_t thresh)          { fClusMaxThresh = thresh; };
  virtual void    SetClusSigThresh(Float_t thresh)          { fClusSigThresh = thresh; };
  virtual void    SetClusMethod(Int_t meth)                 { fClusMethod    = meth;   };

  virtual Float_t GetClusMaxThresh()                        { return fClusMaxThresh; };
  virtual Float_t GetClusSigThresh()                        { return fClusSigThresh; };
  virtual Int_t   GetClusMethod()                           { return fClusMethod;    };

 protected:

  AliTRDdigitsManager *fDigitsManager; //! TRD digits manager

  Float_t              fClusMaxThresh; // Threshold value for cluster maximum
  Float_t              fClusSigThresh; // Threshold value for cluster signal
  Int_t                fClusMethod;    // Clustering method

 private:

  virtual Float_t  Unfold(Float_t eps, Float_t *padSignal);
  virtual Float_t  PadResponse(Float_t x);

  ClassDef(AliTRDclusterizerV1,1)      // TRD-Cluster manager, slow simulator

};

#endif
