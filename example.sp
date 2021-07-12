#include <sourcemod>
#include <SteamIDConverter>

public void OnPluginStart()
{
    char buffer[128];

    SteamIDConverter("STEAM_0:0:461672184", buffer, sizeof(buffer), STEAM3);
    PrintToServer(buffer);

    SteamIDConverter("STEAM_0:0:461672184", buffer, sizeof(buffer), STEAM64);
    PrintToServer(buffer);

    SteamIDConverter("[U:1:923344368]", buffer, sizeof(buffer), STEAM32);
    PrintToServer(buffer);

    SteamIDConverter("[U:1:923344368]", buffer, sizeof(buffer), STEAM64);
    PrintToServer(buffer);

    SteamIDConverter("76561198883610096", buffer, sizeof(buffer), STEAM32);
    PrintToServer(buffer);

    SteamIDConverter("76561198883610096", buffer, sizeof(buffer), STEAM3);
    PrintToServer(buffer);

    SteamIDConverter("STEAM_0:1:91378715", buffer, sizeof(buffer), STEAM3);
    PrintToServer(buffer);

    SteamIDConverter("STEAM_0:1:91378715", buffer, sizeof(buffer), STEAM64);
    PrintToServer(buffer);

    SteamIDConverter("[U:1:182757431]", buffer, sizeof(buffer), STEAM32);
    PrintToServer(buffer);

    SteamIDConverter("[U:1:182757431]", buffer, sizeof(buffer), STEAM64);
    PrintToServer(buffer);

    SteamIDConverter("76561198143023159", buffer, sizeof(buffer), STEAM32);
    PrintToServer(buffer);

    SteamIDConverter("76561198143023159", buffer, sizeof(buffer), STEAM3);
    PrintToServer(buffer);
}