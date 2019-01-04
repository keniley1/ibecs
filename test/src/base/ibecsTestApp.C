//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ibecsTestApp.h"
#include "ibecsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<ibecsTestApp>()
{
  InputParameters params = validParams<ibecsApp>();
  return params;
}

ibecsTestApp::ibecsTestApp(InputParameters parameters) : MooseApp(parameters)
{
  ibecsTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

ibecsTestApp::~ibecsTestApp() {}

void
ibecsTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  ibecsApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"ibecsTestApp"});
    Registry::registerActionsTo(af, {"ibecsTestApp"});
  }
}

void
ibecsTestApp::registerApps()
{
  registerApp(ibecsApp);
  registerApp(ibecsTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ibecsTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ibecsTestApp::registerAll(f, af, s);
}
extern "C" void
ibecsTestApp__registerApps()
{
  ibecsTestApp::registerApps();
}
