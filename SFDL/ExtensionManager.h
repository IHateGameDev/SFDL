#ifndef SFDL_EXTENSION_MANAGER_H
#define SFDL_EXTENSION_MANAGER_H

#include "Extension.h"
#include "APIMacros/api.h"

API SFDLExtensionsData sfdlExtensionLoad(const char* path);
API void sfdlExtensionFree(SFDLExtension* self);
API void sfdlEXtensionsDataFree(SFDLExtensionsData* self);

#endif // !SFDL_EXTENSION_MANAGER_H
