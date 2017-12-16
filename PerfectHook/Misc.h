

#pragma once

#include "entities.h"
#include "SDK.h"
#include "singleton.hpp"

Vector GetAutostrafeView();

class misc
    : public singleton<misc>
{
public:
	void OnCreateMove(CInput::CUserCmd *cmd, C_BaseEntity *local);
private:
	void AutoStrafe(CInput::CUserCmd *cmd, C_BaseEntity *local);
};
template<class T, class U>
inline T clamp(T in, U low, U high)
{
    if (in <= low)
        return low;
    else if (in >= high)
        return high;
    else
        return in;
}

inline float bitsToFloat(unsigned long i)
{
    return *reinterpret_cast<float*>(&i);
}


inline float FloatNegate(float f)
{
    return bitsToFloat(FloatBits(f) ^ 0x80000000);
}

char* const tuxlist[] =
{
	"Wake up with an ache that fades",
	"Pop two pills with gatorade",
	"Round my neck hang gator fangs",
	"Might reveal more at a later date, but I don't know",
	"Yung snow kind of go with the flow",
	"Bring a hoe backstage tell her tell me everything you know about life",
	"And then I bounce",
	"Roxy hitting hard",
	"I'm feeling fucking sick",
	"I'll have to smoke a half an ounce just to balance it out",
	"Ruby backing out",
	"Ruby blacking out",
	"Falling fucking deeper I think Ruby's cashing out",
	"Grass is always greener when the grave is lacking crowds",
	"Look who's laughing now",
	"An audience cracking up you can let the curtains down now",
	"I wallow in sorrow ain't no tomorrow",
	"Missed a call from $lick, I woke up in a gown how ?"
};
char* const ezfragslist[] =
{
	"T4ctical-Cheatz > You",
	"T4ctical-Cheatz > Your Mom",
	"T4ctical-Cheatz > Your Dad",
	"T4ctical-Cheatz > Your Sister",
	"T4ctical-Cheatz > Your Brother",
	"T4ctical-Cheatz > Your Grandma",
	"T4ctical-Cheatz > Your Grandpa",
	"T4ctical-Cheatz > Your Cat",
	"T4ctical-Cheatz > Your Dog",
	"T4ctical-Cheatz > Your Bird",
	"T4ctical-Cheatz > Your Spider",
	"T4ctical-Cheatz > All"
};

inline void SetName(const char* new_name)
{
    static auto name = g_CVar->FindVar("name");

    name->SetValue(new_name);
    *reinterpret_cast<int*>(uintptr_t(&name->fnChangeCallback) + 0xC) = 0;
}
inline void setclantag(const char* tag)
{
    static auto ClanTagOffset = U::FindPattern("engine.dll", (PBYTE)"\x53\x56\x57\x8B\xDA\x8B\xF9\xFF\x15", "xxxxxxxxx");
    if (ClanTagOffset)
    {
        auto tag_ = std::string(tag);
        if (strlen(tag) > 0) {
            auto newline = tag_.find("\\n");
            auto tab = tag_.find("\\t");
            if (newline != std::string::npos) {
                tag_.replace(newline, newline + 2, "\n");
            }
            if (tab != std::string::npos) {
                tag_.replace(tab, tab + 2, "\t");
            }
        }
        static auto dankesttSetClanTag = reinterpret_cast<void(__fastcall*)(const char*, const char*)>(ClanTagOffset);
        dankesttSetClanTag(tag_.data(), tag_.data());
    }
}
inline void RankReveal(CInput::CUserCmd* cmd)
{

	static auto ServerRankRevealAll = (bool(__cdecl*)(int*))((PDWORD)U::FindPattern("client.dll", (PBYTE)"\x55\x8B\xEC\x8B\x0D\x00\x00\x00\x00\x68\x00\x00\x00\x00", "xxxxx????x????"));
	if (g_Options.Misc.ServerRankRevealAll)
	{
		static int fArray[3] = { 0,0,0 };
		ServerRankRevealAll(fArray);
	}
}
