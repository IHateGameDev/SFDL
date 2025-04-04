#ifndef SFDL_EXTENSION_H
#define SFDL_EXTENSION_H

#include "APIMacros/stdint/conf.h"
#include "APIMacros/useful.h"

#ifndef API_NI_STDINT_H
# include API_STDINT_H
#endif

typedef enum {
  SFDLNoLimits        = 0,
  SFDLNoPipeIn        = 1 << 0,
  SFDLNoPipeOut       = 1 << 1,
  SFDLNoMacro         = 1 << 2,
  SFDLNoInclude       = 1 << 3,
  SFDLNoSafeInclude   = 1 << 4,
  SFDLNoGetStdFns     = 1 << 5,
  SFDLNoChangeMod     = 1 << 6,
  SFDLNoChangeName    = 1 << 7
} SFDLNoFlags;

typedef void(*procTokenExtFn)(const char**, API_U8);
typedef bool(*cleanExtFn)(void);

typedef struct SFDLExtension {
  char* langName;
  SFDLNoFlags flags;

  procTokenExtFn procToken;
  cleanExtFn clean;
} SFDLExtension;

typedef struct {
  SFDLExtension* exts;
  API_U8 count;
  mlocal void* library;
} SFDLExtensionsData;

typedef void(*setupExtFn)(SFDLExtensionsData*);

#endif // !SFDL_EXTENSION_H
