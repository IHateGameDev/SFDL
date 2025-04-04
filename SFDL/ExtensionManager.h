#ifndef SFDL_EXTENSION_MANAGER_H
#define SFDL_EXTENSION_MANAGER_H

#include "Extension.h"
#include "APIMacros/api.h"

API SFDLExtensionsData* sfdlExtensionsDataNew();
API void sfdlExtensionsDataLoad(SFDLExtensionsData* self, const char* path);
API void sfdlExtensionsDataFree(SFDLExtensionsData* self);

#endif // !SFDL_EXTENSION_MANAGER_H
