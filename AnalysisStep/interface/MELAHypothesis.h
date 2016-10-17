/** \class MELABranch
*
*
*  \author N. Amapane - Torino
*  \author U. Sarica - JHU
*/
#ifndef MELAHYPOTHESIS_H
#define MELAHYPOTHESIS_H

#include <ZZMatrixElement/MELA/interface/Mela.h>


class MELAHypothesis{

public:

  enum METype{
    UseME,
    UsePAux,
    UsePConstant
  };

protected:

  Mela* mela;
  METype calc_type;

  SpinZeroCouplings* coupl_H;
  SpinOneCouplings* coupl_Zp;
  SpinTwoCouplings* coupl_X;

  TVar::Process proc;
  TVar::Production prod;
  TVar::MatrixElement me;

  float hmass;
  float hwidth;
  float h2mass;
  float h2width;

  float pME;
  float pAux;
  float cMEAvg;

  void reset();
  void setVal();

public:

  float value;

  MELAHypothesis(
    Mela* mela_,
    METype calc_type_,

    SpinZeroCouplings* coupl_H_,
    SpinOneCouplings* coupl_Zp_,
    SpinTwoCouplings* coupl_X_,

    TVar::Process proc_,
    TVar::Production prod_,
    TVar::MatrixElement me_,

    float hmass_=-1.,
    float hwidth_=0.,
    float h2mass_=-1.,
    float h2width_=0.
    );
  virtual ~MELAHypothesis(){}

  void computeP(MELACandidate* cand, bool isGen);
  void computePM4l(MELACandidate* cand, TVar::SuperMelaSyst syst);

};


#endif
