#ifndef SFDL_EXTENSION_INFO_H
#define SFDL_EXTENSION_INFO_H

#include "Language.h"

typedef struct {
  SFDLLanguage* languages;
  uint8_t count;
} SFDLExtensionInfo;

#endif // !SFDL_EXTENSION_INFO_H
