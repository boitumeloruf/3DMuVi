#ifndef PLUGIN_CONFIG_H
#define PLUGIN_CONFIG_H
#include "workflow/plugin/cpluginmanager.h"

//The name of your Plugin
#define PLUGIN_NAME AlgorithmSettingsTest
//The type of your plugin
#define PLUGIN_TYPE PT_FeatureMatcher
//The Author of this plugin
#define PLUGIN_AUTHOR "Stefan Wolf"
//The Version of this plugin (uint)
#define PLUGIN_VERSION 1
//The Date of this Plugin
#define PLUGIN_DATE "2016-03-07"



#define CLASS_GEN(x) _concat1(PLUGIN_NAME, x)
#define _concat1(x,y) _concat2(x, y)    //Double layer of indirection - otherwise PLUGIN_NAME will not be resolved
#define _concat2(x,y) _concat3(x, y)
#define _concat3(x,y) x ## y
#define STRINGIFY(x) STRINGIFY2(x)
#define STRINGIFY2(x) #x

#endif // PLUGIN_CONFIG_H
