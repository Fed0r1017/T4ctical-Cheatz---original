

#pragma once

#include "SDK.h"
#include "singleton.hpp"
class visuals
    :public singleton<visuals>
{
public:
    visuals();
	void OnPaintTraverse(C_BaseEntity* local);
	void DrawSkeleton(C_BaseEntity * entity);
	void DrawPlayer(C_BaseEntity* entity, player_info_t pinfo, C_BaseEntity* local);
private:
	struct playerlist_t
	{
		char *name;
		char *steamid;
		int   money;
		int   health;
		int   mmwins;
		char *mmrank;
	}players[64];
	// Other shit
	C_BaseEntity *BombCarrier;

	struct ESPBox
	{
		int x, y, w, h, gay;
	};
    void DLight(C_BaseEntity* local, C_BaseEntity* entity);

	// Get player info
	Color GetPlayerColor(C_BaseEntity* pEntity, C_BaseEntity* local);
	bool GetBox(C_BaseEntity* pEntity, ESPBox &result);
	void BoxAndText(C_BaseEntity* pEntity, std::string text);

	// Draw shit about player
	void DrawBox(ESPBox size, Color color);
	void PlayerBox(float x, float y, float w, float h, Color clr);
	void DrawHealth(Vector bot, Vector top, float health);
	void DrawHealth(C_BaseEntity* pEntity, ESPBox size);

	void Snaplines(visuals::ESPBox size, Color color, C_BaseEntity * entity);
	void DrawDrop(C_BaseEntity* pEntity);
	void DrawBombPlanted(C_BaseEntity* entity, C_BaseEntity* local);
	void DrawBomb(C_BaseEntity* pEntity, ClientClass* cClass);
	void DrawThrowable(C_BaseEntity* throwable);
    void NightMode();
    void SpecList(C_BaseEntity *local);

};

inline float CSGO_Armor(float flDamage, int ArmorValue)
{
    float flArmorRatio = 0.5f;
    float flArmorBonus = 0.5f;
    if (ArmorValue > 0) {
        float flNew = flDamage * flArmorRatio;
        float flArmor = (flDamage - flNew) * flArmorBonus;

        if (flArmor > static_cast<float>(ArmorValue)) {
            flArmor = static_cast<float>(ArmorValue) * (1.f / flArmorBonus);
            flNew = flDamage - flArmor;
        }

        flDamage = flNew;
    }
    return flDamage;
}

template <typename T, std::size_t N> T* end_(T(&arr)[N]) { return arr + N; }

template <typename T, std::size_t N> T* begin_(T(&arr)[N]) { return arr; }

char* const itemNames[] =
{
    "Knife", //0 - default
    "Desert Eagle",
    "Dual Berettas",
    "Five-Seven",
    "Glock-18",
    "none",
    "none",
    "AK-47",
    "AUG",
    "AWP",

    "FAMAS", //10
    "G3SG1",
    "none",
    "Galil AR",
    "M249",
    "none",
    "M4A4",
    "MAC-10",
    "none",
    "P90",

    "none", //20
    "none",
    "none",
    "none",
    "UMP-45",
    "XM1014",
    "PP-Bizon",
    "MAG-7",
    "Negev",
    "Sawed-Off",

    "Tec-9", //30
    "Zeus x27",
    "P2000",
    "MP7",
    "MP9",
    "Nova",
    "P250",
    "none",
    "SCAR-20",
    "SG 553",

    "SSG 08", //40
    "Knife",
    "Knife",
    "Flashbang",
    "HE Grenade",
    "Smoke Grenade",
    "Molotov",
    "Decoy Grenade",
    "Incendiary Grenade",
    "C4",

    "none", //50
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "none",
    "Knife",

    "M4A1-S", //60
    "USP-S",
    "none",
    "CZ75-Auto",
    "R8 Revolver"
};




inline const char* ItemDefinitionIndexToString(int index)
{
    if (index < 0 || index > 64)
        index = 0;

    return itemNames[index];
}
inline float flGetDistance(Vector from, Vector to)
{
    Vector angle;
    angle.x = to.x - from.x;	angle.y = to.y - from.y;	angle.z = to.z - from.z;

    return sqrt(angle.x*angle.x + angle.y*angle.y + angle.z*angle.z);
}
