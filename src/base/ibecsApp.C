#include "ibecsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<ibecsApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ibecsApp::ibecsApp(InputParameters parameters) : MooseApp(parameters)
{
  ibecsApp::registerAll(_factory, _action_factory, _syntax);
}

ibecsApp::~ibecsApp() {}

void
ibecsApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"ibecsApp"});
  Registry::registerActionsTo(af, {"ibecsApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
ibecsApp::registerApps()
{
  registerApp(ibecsApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ibecsApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ibecsApp::registerAll(f, af, s);
}
extern "C" void
ibecsApp__registerApps()
{
  ibecsApp::registerApps();
}
