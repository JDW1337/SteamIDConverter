#include <string>

#include "SteamIDConverter.h"
#include "SteamIDType.h"
#include "extension.h"

Extension g_Extension;
SMEXT_LINK(&g_Extension);

static cell_t Native_SteamIDConverter(IPluginContext *pContext, const cell_t *params)
{
    char *input;
    pContext->LocalToString(params[1], (char**)&input);

    SteamIDConverter convert(input, params[4]);
    
    if (!convert.ValidSteamID()) {
        return 0;
    }

    std::string result = convert.ConvertSteamID();

    pContext->StringToLocal(params[2], params[3], result.c_str());

    return 1;
}

const sp_nativeinfo_t g_Natives[] =
{
    {"SteamIDConverter", Native_SteamIDConverter},
    {nullptr, nullptr}
};

bool Extension::SDK_OnLoad(char *error, size_t maxlen, bool late)
{
    sharesys->AddNatives(myself, g_Natives);
    sharesys->RegisterLibrary(myself, "SteamIDConverter");

    return true;
}