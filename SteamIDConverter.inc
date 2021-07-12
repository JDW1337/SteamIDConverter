#if defined SteamIDConverter_included
 #endinput
#endif
#define SteamIDConverter_included

enum ConversionType
{
    STEAM32 = 1, // STEAM_0:?:????
    STEAM3, // [U:1:????]
    STEAM64 // 7960265728??????
}

/**
 *	Converts SteamId from one type to another.
 *
 * @param steamId SteamID
 * @param output  Where the converted SteamID will be written to
 * @param maxlen  Output size
 * @param convert What type of SteamID do we convert to?
 *
 * @return true - success, false - failure
*/
native void SteamIDConverter(const char[] steamID, char[] output, int maxlen, ConversionType convert);

public Extension __ext_SteamIDConverter = 
{
	name = "SteamIDConverter",
	file = "SteamIDConverter.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_EXTENSIONS
public __ext_SteamIDConverter_SetNTVOptional()
{
	MarkNativeAsOptional("SteamIDConverter");
}
#endif