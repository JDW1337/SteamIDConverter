#ifndef _INCLUDE_SteamIDConverter_H
#define _INCLUDE_SteamIDConverter_H

#include <regex>
#include <string>
#include <cstdint>

class SteamIDConverter
{
public: 
    SteamIDConverter(const char *steam, int type);
    bool ValidSteamID();
    std::string ConvertSteamID();
private:
    int DetermineInputType();
    void STEAMTO32();
    void STEAM32TO3();
    void STEAM32TO64();
    void SetOmega();
private:
    int steamType;
    int convertType;
    std::string steamID;
    uint64_t omega;
    bool isHigh;
};

#endif