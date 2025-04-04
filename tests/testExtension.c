#include "../SFDL/Extension.h"

#include "APIMacros/stdlib/memorylib.h"
#include "stdio.h"
#include "string.h"

#ifndef API_NI_MEMORYLIB_H
# include API_MEMORYLIB_H
#endif

void someFunc(const char** token, API_U8 count) {
  puts("someFunc");
}

void someFunc2(const char** token, API_U8 count) {
  puts("someFunc2");
}

void setup(SFDLExtensionsData* data) {
  data->count = 2;
  data->exts = API_MALLOC(sizeof(SFDLExtension) * data->count);
 
  for(API_U8 i = 0; i < data->count; i++) {
    data->exts[i].langName = API_MALLOC(sizeof(char) * 5);
    strncpy(data->exts[i].langName, "TEST", 5);
    data->exts[i].flags = SFDLNoLimits;
  }

  data->exts[0].procToken = someFunc;
  data->exts[1].procToken = someFunc2;
}
