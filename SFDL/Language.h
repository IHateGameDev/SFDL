#ifndef SFDL_LANGUAGE_H
#define SFDL_LANGUAGE_H

#include <APIMacros/api.h>
#include <stdint.h>

typedef enum : uint8_t {
  SFDLLanguageFlagNone          = 0x00,
  SFDLLanguageFlagAll           = 0xFF,
  SFDLLanguageFlagPipeIn        = 1 << 0,
  SFDLLanguageFlagPipeOut       = 1 << 1,
  SFDLLanguageFlagMacro         = 1 << 2,
  SFDLLanguageFlagInclude       = 1 << 3,
  SFDLLanguageFlagSafeInclude   = 1 << 4,
  SFDLLanguageFlagGetStdFns     = 1 << 5,
  SFDLLanguageFlagChangeMod     = 1 << 6,
  SFDLLanguageFlagChangeName    = 1 << 7
} SFDLLanguageFlag;

typedef void(*SFDLProcessToken)(const char**, uint8_t);
typedef const char*(*SFDLEndLanguage)();

typedef struct {
  char* langName;
  SFDLLanguageFlag flags;

  SFDLProcessToken processToken;
  SFDLEndLanguage end;
} SFDLLanguage;

API SFDLLanguage* SFDLLanguageNew(uint8_t count);
API void SFDLLanguageInit(SFDLLanguage* self);
API void SFDLLanguageFree(SFDLLanguage* self);

#endif // !SFDL_LANGUAGE_H
