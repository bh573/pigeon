//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "PigeonTestApp.h"
#include "PigeonApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
PigeonTestApp::validParams()
{
  InputParameters params = PigeonApp::validParams();
  return params;
}

PigeonTestApp::PigeonTestApp(InputParameters parameters) : MooseApp(parameters)
{
  PigeonTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

PigeonTestApp::~PigeonTestApp() {}

void
PigeonTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  PigeonApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"PigeonTestApp"});
    Registry::registerActionsTo(af, {"PigeonTestApp"});
  }
}

void
PigeonTestApp::registerApps()
{
  registerApp(PigeonApp);
  registerApp(PigeonTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
PigeonTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  PigeonTestApp::registerAll(f, af, s);
}
extern "C" void
PigeonTestApp__registerApps()
{
  PigeonTestApp::registerApps();
}
