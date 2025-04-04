#include "../SFDL/ExtensionManager.h"

#include "APIMacros/lib.h"
#include "APIMacros/stdlib/memorylib.h"


#include "stdio.h"


#ifndef API_NI_MEMORYLIB_H
# include API_MEMORYLIB_H
#endif

API SFDLExtensionsData* sfdlExtensionsDataNew() {
  SFDLExtensionsData* data = API_MALLOC(sizeof(SFDLExtensionsData));
  data->exts = nullptr;
  data->library = nullptr;
  data->count = 0;

  return data;
}

API void sfdlExtensionsDataLoad(SFDLExtensionsData* self, const char* path) {
  self->exts = nullptr;
  self->count = 0;

  self->library = (void*)API_LOAD_LIBRARY(path);
  
  if(!self->library)
    puts("ivalid extension");

  ((setupExtFn)API_GET_LIB_FUNC(self->library, "setup"))(self);
}

API void sfdlExtensionsDataFree(SFDLExtensionsData* self) {
  for(API_U8 i = 0; i < self->count; i++)
    API_FREE(self->exts[i].langName);

  API_UNLOAD_LIBRARY(self->library);
  API_FREE(self);
}
