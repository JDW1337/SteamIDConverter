#include "SteamIDConverter.h"
#include "SteamIDType.h"

SteamIDConverter::SteamIDConverter(const char *steam, int type)
{
    convertType = type;
    steamID = steam;
    steamType = DetermineInputType();
}

bool SteamIDConverter::ValidSteamID()
{
    return DetermineInputType() != FIRST_PARAM_ERROR;
}

std::string SteamIDConverter::ConvertSteamID()
{
    if (steamType == convertType) {
        return steamID;
    }

    STEAMTO32();

    if (convertType == STEAM32) {
        return steamID;
    }
    else if (convertType == STEAM3) {
        STEAM32TO3();
    }
    else if (convertType == STEAM64) {
        STEAM32TO64();
    }

    return steamID;
}

int SteamIDConverter::DetermineInputType()
{
    if (std::regex_match(steamID, std::regex("^STEAM_([0-4]):([0-1]):([0-9]{1,10})$"))) {
        return STEAM32;
    }
    else if (std::regex_match(steamID, std::regex("^\\[U:1:([0-9]+\\])$"))) {
        return STEAM3;
    }
    else if (std::regex_match(steamID, std::regex("^(7656119)([0-9]{10})$"))) {
        return STEAM64;
    }

    return FIRST_PARAM_ERROR;
}

void SteamIDConverter::STEAMTO32()
{
    if (steamType == STEAM32) {
        SetOmega();
        return;
    }

    if (steamType == STEAM3) {
        std::string result = std::regex_replace(steamID, std::regex("\\[U:1:(\\d+)\\]"), "$1");

        uint64_t iResult = atoll(result.c_str());

        uint64_t alfa = iResult % 2;
        uint64_t beta = iResult / 2;

        steamID = "STEAM_0:" + std::to_string(alfa) + ":" + std::to_string(beta);
    }
    else if (steamType == STEAM64) {
        const uint64_t start = 7960265728;

        std::string result = std::regex_replace(steamID, std::regex("^(7656119)([0-9]{10})$"), "$2");

        uint64_t rvl = atoll(result.c_str());

        if (rvl >= start) {
            uint64_t alfa = (rvl - start) % 2;
            uint64_t beta = (rvl - start - alfa) / 2;

            steamID = "STEAM_0:" + std::to_string(alfa) + ":" + std::to_string(beta);
        }
    }

    SetOmega();
}

void SteamIDConverter::STEAM32TO3()
{
    steamID = "[U:1:" + std::to_string(omega * 2 + (isHigh ? 1 : 0)) + "]";
}

void SteamIDConverter::STEAM32TO64()
{
    steamID = std::to_string(omega * 2 + 76561197960265728 + (isHigh ? 1 : 0));
}

void SteamIDConverter::SetOmega()
{
    omega = atoll((std::regex_replace(steamID, std::regex("^STEAM_([0-4]):([0-1]):([0-9]{1,10})$"), "$3")).c_str());
    isHigh = std::regex_replace(steamID, std::regex("^STEAM_([0-4]):([0-1]):([0-9]{1,10})$"), "$2") == "1";
}