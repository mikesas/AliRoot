/**************************************************************************
 * Copyright(c) 2007-2009, ALICE Experiment at CERN, All rights reserved. *
 *                                                                        *
 * Author: The ALICE Off-line Project.                                    *
 * Contributors are mentioned in the code where appropriate.              *
 *                                                                        *
 * Permission to use, copy, modify and distribute this software and its   *
 * documentation strictly for non-commercial purposes is hereby granted   *
 * without fee, provided that the above copyright notice appears in all   *
 * copies and that both the copyright notice and this permission notice   *
 * appear in the supporting documentation. The authors make no claims     *
 * about the suitability of this software for any purpose. It is          *
 * provided "as is" without express or implied warranty.                  *
 **************************************************************************/

#include "AliITSRecoParam.h"

/* $Id$ */

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Class with ITS reconstruction parameters                                  //
// Origin: andrea.dainese@lnl.infn.it                                        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////



ClassImp(AliITSRecoParam)


//_____________________________________________________________________________
AliITSRecoParam::AliITSRecoParam() : TObject(),
fNSigmaYLayerForRoadY(0),
fNSigmaRoadY(0),
fNSigmaZLayerForRoadZ(0),
fNSigmaRoadZ(0),
fNSigma2RoadZC(0),
fNSigma2RoadYC(0),
fNSigma2RoadZNonC(0),
fNSigma2RoadYNonC(0),
fMaxNormChi2NonCForHypothesis(0),
fMaxChi2(0),
fMaxRoad(0),
fMaxChi2In(0),
fChi2PerCluster(0),
fXV(0), 
fYV(0),
fZV(0),
fSigmaXV(0),
fSigmaYV(0),
fSigmaZV(0),
fVertexCut(0),
fMaxDZforPrimTrk(0),
fMaxDZToUseConstraint(0), 
fMaxDforV0dghtrForProlongation(0),
fMaxDForProlongation(0),
fMaxDZForProlongation(0),
fMinPtForProlongation(0),
fAddVirtualClustersInDeadZone(kTRUE),
fZWindowDeadZone(0),
fSigmaXDeadZoneHit2(0),
fSigmaZDeadZoneHit2(0),
fXPassDeadZoneHits(0),
fUseTGeoInTracker(kFALSE),
fAllowSharedClusters(kTRUE),
fUseNominalClusterErrors(kFALSE),
fFindV0s(kTRUE)
{
  //
  // constructor
  //
  SetLayersParameters();
  SetUseTGeoInTracker(kFALSE);
  SetAllowSharedClusters(kTRUE);
  SetFindV0s(kTRUE);
  SetAddVirtualClustersInDeadZone(kTRUE);
  SetUseAmplitudeInfo(kTRUE);
}
//_____________________________________________________________________________
AliITSRecoParam::~AliITSRecoParam() 
{
  //
  // destructor
  //  
}
//_____________________________________________________________________________
AliITSRecoParam *AliITSRecoParam::GetHighFluxParam() 
{
  //
  // make default reconstruction  parameters for hig  flux env.
  //
  AliITSRecoParam *param = new AliITSRecoParam();

  param->fMaxSnp = 0.95;

  param->fNSigmaYLayerForRoadY = 4.;
  param->fNSigmaRoadY = 7.5;
  param->fNSigmaZLayerForRoadZ = 4.;
  param->fNSigmaRoadZ = 7.5;

  param->fNSigma2RoadZC = 60.; //7.75^2
  param->fNSigma2RoadYC = 60.; //7.75^2
  param->fNSigma2RoadZNonC = 50.; //7.07^2
  param->fNSigma2RoadYNonC = 50.; //7.07^2

  param->fMaxChi2PerCluster[0] = 11.; //7
  param->fMaxChi2PerCluster[1] = 12.; //5
  param->fMaxChi2PerCluster[2] = 12.; //8
  param->fMaxChi2PerCluster[3] = 5.;  //8
  param->fMaxChi2PerCluster[4] = 12.; //6.5

  param->fMaxNormChi2NonC[0] = 7.;
  param->fMaxNormChi2NonC[1] = 8.;
  param->fMaxNormChi2NonC[2] = 8.;
  param->fMaxNormChi2NonC[3] = 11.;
  param->fMaxNormChi2NonC[4] = 14.;
  param->fMaxNormChi2NonC[5] = 25.;

  param->fMaxNormChi2C[0] = 11.;
  param->fMaxNormChi2C[1] = 13.;
  param->fMaxNormChi2C[2] = 15.;
  param->fMaxNormChi2C[3] = 18.;
  param->fMaxNormChi2C[4] = 30.;
  param->fMaxNormChi2C[5] = 35.;

  param->fMaxNormChi2NonCForHypothesis = 7.;
  
  param->fMaxChi2 = 35.;

  param->fMaxChi2s[0] = 25.; //40   
  param->fMaxChi2s[1] = 25.; //40   
  param->fMaxChi2s[2] = 25.; //40   
  param->fMaxChi2s[3] = 25.; //40   
  param->fMaxChi2s[4] = 40.; //40   
  param->fMaxChi2s[5] = 50.; //40

  param->fMaxRoad = 6.;

  // not used
  param->fMaxChi2In = 16.;
   
  param->fMaxChi2sR[0] = 10.;   
  param->fMaxChi2sR[1] = 10.;   
  param->fMaxChi2sR[2] = 10.;   
  param->fMaxChi2sR[3] = 10.;   
  param->fMaxChi2sR[4] = 30.;   
  param->fMaxChi2sR[5] = 40.;   

  param->fChi2PerCluster = 9.;
  // not used

  param->fXV = 0.;
  param->fYV = 0.;
  param->fZV = 0.;
  param->fSigmaXV = 0.0050;
  param->fSigmaYV = 0.0050;
  param->fSigmaZV = 0.0100;

  param->fVertexCut = 25.;

  param->fMaxDZforPrimTrk = 0.4;
  param->fMaxDZToUseConstraint = 3.;

  param->fMaxDforV0dghtrForProlongation = 30.;
  param->fMaxDForProlongation = 10.;
  param->fMaxDZForProlongation = 20.;
  param->fMinPtForProlongation = 0.120;

  param->fZWindowDeadZone = 2.0;
  param->fSigmaXDeadZoneHit2 = 0.004/12.;
  param->fSigmaZDeadZoneHit2 = 0.001/12.;
  param->fXPassDeadZoneHits = 0.018;

  
  return param;
}
//_____________________________________________________________________________
AliITSRecoParam *AliITSRecoParam::GetLowFluxParam() 
{
  //
  // make default reconstruction  parameters for low  flux env.
  //
  return GetHighFluxParam();
}
//_____________________________________________________________________________
AliITSRecoParam *AliITSRecoParam::GetCosmicTestParam() 
{
  //
  // make default reconstruction  parameters for cosmics
  //
  return GetHighFluxParam();
}
//_____________________________________________________________________________
void AliITSRecoParam::SetLayersParameters() 
{
  //
  // number of layers and layers spatial resolutions
  //

  // spatial resolutions of the detectors
  // y: 12 12 38 38 20 20 micron
  fSigmaY2[0]=1.44e-6;
  fSigmaY2[1]=1.44e-6;
  fSigmaY2[2]=1.444e-5;
  fSigmaY2[3]=1.444e-5;
  fSigmaY2[4]=4.0e-6;
  fSigmaY2[5]=4.0e-6;
  // z: 120 120 28 28 830 830 micron
  fSigmaZ2[0]=1.44e-4;
  fSigmaZ2[1]=1.44e-4;
  fSigmaZ2[2]=7.84e-6;
  fSigmaZ2[3]=7.84e-6;
  fSigmaZ2[4]=6.889e-3;
  fSigmaZ2[5]=6.889e-3;

  return;
}

