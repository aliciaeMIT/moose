/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

/***************************************************************/
/* New DGMatDiffusion DGKernel based upon the following paper: */
/*   Discontinuous Galerkin methods for convection-diffusion   */
/*       equations for varying and vanishing diffusivity       */
/*                 by: J. PROFT and B. RIVIERE                 */
/***************************************************************/

#ifndef ENHANCEDDGMATDIFFUSION_H
#define ENHANCEDDGMATDIFFUSION_H

#include "DGKernel.h"

//Forward Declarations
class EnhancedDGMatDiffusion;

template<>
InputParameters validParams<EnhancedDGMatDiffusion>();



class EnhancedDGMatDiffusion : public DGKernel
{
public:
  EnhancedDGMatDiffusion(const std::string & name, InputParameters parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type);
  virtual Real computeQpJacobian(Moose::DGJacobianType type);

  Real _epsilon;
  Real _sigma;
  Real _limiting_factor;
  Real _conv;
  RealVectorValue _velocity;
  Real _x;
  Real _y;
  Real _z;
  Real _adaptive;

  std::string _prop_name;                     // name of the material property
  MaterialProperty<Real> & _diff;             // diffusivity
  MaterialProperty<Real> & _diff_neighbor;    // diffusivity
};

#endif
