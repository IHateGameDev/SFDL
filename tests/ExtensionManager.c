#include "../SFDL/ExtensionManager.h"

int main(void) {
  SFDLExtensionsData* data = sfdlExtensionsDataNew();
  sfdlExtensionsDataLoad(data, "./testext");

  for(API_U8 i = 0; i < data->count; i++)
    data->exts[i].procToken(nullptr, 0);

  sfdlExtensionsDataFree(data);
}
