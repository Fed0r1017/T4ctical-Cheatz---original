#pragma once
#include "IDirect3DDevice9.h"
typedef void(*CL_FullUpdate_t) (void);
CL_FullUpdate_t CL_FullUpdate = nullptr;

void KnifeApplyCallbk()
{
	static auto CL_FullUpdate = reinterpret_cast<CL_FullUpdate_t>(U::FindPattern("engine.dll", reinterpret_cast<PBYTE>("\xA1\x00\x00\x00\x00\xB9\x00\x00\x00\x00\x56\xFF\x50\x14\x8B\x34\x85"), "x????x????xxxxxxx"));
	CL_FullUpdate();
}
void RenderRageBot()
{
	ImGui::Checkbox(("Active"), &g_Options.Ragebot.MainSwitch);

	ImGui::Columns(3, NULL, true);
	{
		ImGui::Text("General"); ImGui::NextColumn(); ImGui::Text("Accuracy"); ImGui::NextColumn(); ImGui::Text("Anti-Aim"); ImGui::NextColumn(); ImGui::Separator();
		ImGui::Checkbox(("Enabled"), &g_Options.Ragebot.Enabled);
		ImGui::Checkbox(("Auto Fire"), &g_Options.Ragebot.AutoFire);
		ImGui::SliderFloat(("FOV"), &g_Options.Ragebot.FOV, 1.f, 180.f, "%.0f");
		ImGui::Checkbox(("Silent Aim"), &g_Options.Ragebot.Silent);
		ImGui::Checkbox(("AutoPistol"), &g_Options.Ragebot.AutoPistol);
		ImGui::Hotkey(("Key##999"), &g_Options.Ragebot.KeyPress);
		ImGui::Text(("Accuracy"));
		//ImGui::Separator();
		ImGui::Checkbox(("Friendly Fire"), &g_Options.Ragebot.FriendlyFire);
		ImGui::Combo(("Hitbox"), &g_Options.Ragebot.Hitbox, aimBones, ARRAYSIZE(aimBones));
		ImGui::Combo(("Hitscan"), &g_Options.Ragebot.Hitscan, hitscan, ARRAYSIZE(hitscan));

		//	ImGui::Separator();

	}
	ImGui::NextColumn();
	{

		//	ImGui::Text(("Accuracy"));
		//ImGui::Separator();

		ImGui::Checkbox(("NoRecoil"), &g_Options.Ragebot.AntiRecoil);
		ImGui::Checkbox(("Auto Stop"), &g_Options.Ragebot.AutoStop);
		ImGui::Checkbox(("Auto Crouch"), &g_Options.Ragebot.AutoCrouch);
		ImGui::Checkbox(("Auto Scope"), &g_Options.Ragebot.AutoScope);
		ImGui::SliderFloat(("Minimum Damage"), &g_Options.Ragebot.MinimumDamage, 1.f, 100.f, "%.2f");
		ImGui::Checkbox(("Hitchance"), &g_Options.Ragebot.Hitchance);
		ImGui::SliderFloat(("Hitchance Amount"), &g_Options.Ragebot.HitchanceAmount, 0.f, 100.f, "%.1f");
		ImGui::Checkbox(("Resolver"), &g_Options.Ragebot.Resolver);
		ImGui::Checkbox("Backtracking", &g_Options.Ragebot.FakeLagFix);
		ImGui::Hotkey(("BAIM key"), &g_Options.Ragebot.BAIMkey);


	}
	ImGui::NextColumn();
	{

		//	ImGui::Text("Anti-Aim");
		//	ImGui::Separator();
		ImGui::Checkbox(("Anti-Aim Enabled"), &g_Options.Ragebot.EnabledAntiAim);
		ImGui::Combo(("Pitch"), &g_Options.Ragebot.Pitch, antiaimpitch, ARRAYSIZE(antiaimpitch));
		ImGui::Combo(("Yaw"), &g_Options.Ragebot.YawTrue, antiaimyawtrue, ARRAYSIZE(antiaimyawtrue));
		ImGui::Combo(("Yaw-Fake"), &g_Options.Ragebot.YawFake, antiaimyawfake, ARRAYSIZE(antiaimyawfake));
		ImGui::Checkbox(("At Players"), &g_Options.Ragebot.AtTarget);
		ImGui::Checkbox(("Edge"), &g_Options.Ragebot.Edge);
		ImGui::Checkbox(("AntiAim on knife"), &g_Options.Ragebot.KnifeAA);
	}
}


void RenderLegit()
{
	ImGui::Checkbox(("Active"), &g_Options.Legitbot.MainSwitch);
	ImGui::Columns(5, nullptr, true);
	{
		ImGui::Text("General"); ImGui::NextColumn(); ImGui::Text("Rifles"); ImGui::NextColumn(); ImGui::Text("Pistol"); ImGui::NextColumn(); ImGui::Text("Sniper"); ImGui::NextColumn(); ImGui::Text("Triggerbot"); ImGui::NextColumn(); ImGui::Separator();

		ImGui::Checkbox(("Enable Aimbot"), &g_Options.Legitbot.Aimbot.Enabled);
		//ImGui::Checkbox(("Auto Pistol"), &menu.Legitbot.Aimbot.AutoPistol);
		ImGui::Checkbox(("Backtrack"), &g_Options.Legitbot.backtrack);
		ImGui::Checkbox(("Backtrack Dot"), &g_Options.Legitbot.backtrackdot);
	}
	//ImGui::Separator();
	ImGui::NextColumn();

	{
        ImGui::Hotkey("Key##0", &g_Options.Legitbot.MainKey);
        //ImGui::Combo(("Key##0"), &menu.Legitbot.MainKey, keyNames, ARRAYSIZE(keyNames));
        ImGui::SliderFloat("Smooth##0", &g_Options.Legitbot.MainSmooth, 1.00f, 100.00f, "%.2f");
        ImGui::SliderFloat("FOV##0", &g_Options.Legitbot.Mainfov, 0.00f, 30.00f, "%.2f");
        ImGui::SliderFloat("Min RCS##0", &g_Options.Legitbot.main_recoil_min, 1.00f, 100.00f, "%.2f");
        ImGui::SliderFloat("Max RCS##0", &g_Options.Legitbot.main_recoil_max, 1.00f, 100.00f, "%.2f");
	}

	ImGui::NextColumn();

	{
        ImGui::Hotkey("Key##1", &g_Options.Legitbot.PistolKey);
        //ImGui::Combo(("Key##1"), &menu.Legitbot.PistolKey, keyNames, ARRAYSIZE(keyNames));
        ImGui::SliderFloat("Smooth##1", &g_Options.Legitbot.PistolSmooth, 1.00f, 100.00f, "%.2f");
        ImGui::SliderFloat("FOV##1", &g_Options.Legitbot.Pistolfov, 0.00f, 30.00f, "%.2f");
        ImGui::SliderFloat("Min RCS##1", &g_Options.Legitbot.pistol_recoil_min, 1.00f, 100.00f, "%.2f");
        ImGui::SliderFloat("Max RCS##1", &g_Options.Legitbot.pistol_recoil_max, 1.00f, 100.00f, "%.2f");
	}
	ImGui::NextColumn();

	{
        ImGui::Hotkey("Key##2", &g_Options.Legitbot.SniperKey);
        //ImGui::Combo(("Key##2"), &menu.Legitbot.SniperKey, keyNames, ARRAYSIZE(keyNames));
        ImGui::SliderFloat("Smooth##2", &g_Options.Legitbot.SniperSmooth, 1.00f, 100.00f, "%.2f");
        ImGui::SliderFloat("FOV##2", &g_Options.Legitbot.Sniperfov, 0.00f, 30.00f, "%.2f");
        ImGui::SliderFloat("Min RCS##2", &g_Options.Legitbot.sniper_recoil_min, 1.00f, 100.00f, "%.2f");
        ImGui::SliderFloat("Max RCS##2", &g_Options.Legitbot.sniper_recoil_max, 1.00f, 100.00f, "%.2f");
	}

	ImGui::NextColumn();

	{
		//ImGui::Separator();
		ImGui::Checkbox(("Enable Triggerbot"), &g_Options.Legitbot.Triggerbot.Enabled);
		ImGui::SliderFloat(("Delay"), &g_Options.Legitbot.Triggerbot.Delay, 1.f, 150.f, "%.0f");
        ImGui::Hotkey("Key##3", &g_Options.Legitbot.Triggerbot.Key);
        //ImGui::Combo(("Triggerbot key"), &menu.Legitbot.Triggerbot.Key, keyNames, ARRAYSIZE(keyNames));
		ImGui::SliderFloat(("Hitchance"), &g_Options.Legitbot.Triggerbot.hitchance, 1.f, 100.f, "%.0f");

		ImGui::Text(("Filter"));

		ImGui::BeginChild(("Filter"), ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f, 19 * 5));
		{
			ImGui::Selectable((" Head"), &g_Options.Legitbot.Triggerbot.Filter.Head);
			ImGui::Selectable((" Arms"), &g_Options.Legitbot.Triggerbot.Filter.Arms);
			ImGui::Selectable((" Chest"), &g_Options.Legitbot.Triggerbot.Filter.Chest);
			ImGui::Selectable((" Stomach"), &g_Options.Legitbot.Triggerbot.Filter.Stomach);
			ImGui::Selectable((" Legs"), &g_Options.Legitbot.Triggerbot.Filter.Legs);
		} ImGui::EndChild();
	}
}

void RenderVisuals()
{
	ImGui::Checkbox(("Active"), &g_Options.Visuals.Enabled);

	ImGui::Columns(3, NULL, true);
	{
		ImGui::Text("Player"); ImGui::NextColumn(); ImGui::Text("Filter"); ImGui::NextColumn(); ImGui::Text("Misc"); ImGui::NextColumn(); ImGui::Separator();
		ImGui::Checkbox(("Box"), &g_Options.Visuals.Box);
		ImGui::Checkbox(("Name"), &g_Options.Visuals.Name);
		ImGui::Checkbox(("HP"), &g_Options.Visuals.HP);
		ImGui::Checkbox(("Weapon"), &g_Options.Visuals.Weapon);
		ImGui::Checkbox(("Money"), &g_Options.Visuals.money);
		ImGui::Checkbox(("Chams"), &g_Options.Visuals.Chams);
		ImGui::Checkbox(("DLight"), &g_Options.Visuals.DLight);
		ImGui::Checkbox(("Snaplinese"), &g_Options.Visuals.Snaplines);
		ImGui::Checkbox(("GrenadeESP"), &g_Options.Visuals.GrenadeESP);
		ImGui::Checkbox(("C4"), &g_Options.Visuals.C4);
        ImGui::Checkbox("Glow", &g_Options.Visuals.Glow);
	}
	ImGui::NextColumn();
	{
		ImGui::BeginChild(("Filter"), ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f, 19 * 2));
		{
			ImGui::Selectable((" Players"), &g_Options.Visuals.Filter.Players);
			ImGui::Selectable((" Enemy Only"), &g_Options.Visuals.Filter.EnemyOnly);
		} ImGui::EndChild();
		ImGui::Text("World");
		ImGui::Checkbox(("C4 - World"), &g_Options.Visuals.C4World);
		ImGui::Checkbox(("Weapons - World"), &g_Options.Visuals.WeaponsWorld);



	}
	ImGui::NextColumn();
	{


		ImGui::Checkbox(("No Visual Recoil"), &g_Options.Visuals.NoVisualRecoil);
		ImGui::SliderFloat(("FOV"), &g_Options.Visuals.FOVChanger, 0.f, 60.f, "%.0f");
		ImGui::SliderFloat(("viewmodel FOV"), &g_Options.Visuals.viewmodelChanger, 0.f, 120.f, "%.0f");
		ImGui::Checkbox(("Watermark"), &g_Options.Visuals.Time);
		ImGui::Checkbox(("noScope Border"), &g_Options.Visuals.noscopeborder);
		ImGui::Checkbox(("Grenade Prediction"), &g_Options.Visuals.GrenadePrediction);
		ImGui::Checkbox(("Hitmarker"), &g_Options.Misc.Hitmarker);
		ImGui::Combo(("Hitmarker Color"), &g_Options.Misc.HitMarkerColor, HitMarkerClrType, ARRAYSIZE(HitMarkerClrType));
	}
}
bool memesaredank;

void RenderMisc()
{
	ImGui::Columns(2, NULL, true);
	{
		ImGui::Text("	"); ImGui::NextColumn(); ImGui::Text("	");ImGui::Separator();
		ImGui::Checkbox(("Bunny Hop"), &g_Options.Misc.Bhop);
		ImGui::Checkbox(("NightMode"), &g_Options.Misc.nightMode);
		ImGui::Checkbox(("SpecList"), &g_Options.Misc.SpecList);
		ImGui::Combo(("Spammer"), &g_Options.Misc.spammer, spammers, ARRAYSIZE(spammers));
		ImGui::Checkbox(("Rank Revealer"), &g_Options.Misc.ServerRankRevealAll);
	}
	ImGui::NextColumn();
	{
		ImGui::PushItemWidth(100);
		ImGui::Hotkey("ragequit key", &g_Options.Misc.ragequit);

		ImGui::Text("Config");
		ImGui::Combo(("File"), &g_Options.Menu.ConfigFile, configFiles, ARRAYSIZE(configFiles));
		if (ImGui::Button("Save Config")) Config->Save();
		ImGui::SameLine();
		if (ImGui::Button("Load Config")) Config->Load();
		ImGui::SameLine();
		if (ImGui::Button("Unload (May crash CS:GO)"))
		{
			g_Engine->ClientCmd_Unrestricted("cl_mouseenable 1");
			unload = true;
		}
	}
}

void RenderSkinChanger()
{
    {
        ImGui::Checkbox(("Enabled"), &g_Options.Skinchanger.Enabled);
        ImGui::SameLine();
        ImGui::PushItemWidth(150);
        if (ImGui::Button(("Force Update (May crash CS:GO)")))
        {
            KnifeApplyCallbk();
        }


        //ImGui::Separator();

        ImGui::Text("General");
        ImGui::Combo(("Knife Model"), &g_Options.Skinchanger.Knife, knives, ARRAYSIZE(knives));
        ImGui::Combo(("Knife Skin"), &g_Options.Skinchanger.KnifeSkin, knifeskins, ARRAYSIZE(knifeskins));
        ImGui::Combo(("Gloves"), &g_Options.Skinchanger.gloves, gloves, ARRAYSIZE(gloves));


        ImGui::Columns(1);
        ImGui::Separator();
        ImGui::Text("Rifles");
        ImGui::Columns(2, NULL, false);
        ImGui::Combo(("AK-47"), &g_Options.Skinchanger.AK47Skin, ak47, ARRAYSIZE(ak47));
        ImGui::Combo(("M4A1-S"), &g_Options.Skinchanger.M4A1SSkin, m4a1s, ARRAYSIZE(m4a1s));
        ImGui::Combo(("M4A4"), &g_Options.Skinchanger.M4A4Skin, m4a4, ARRAYSIZE(m4a4));
        ImGui::NextColumn();
        ImGui::Combo(("AUG"), &g_Options.Skinchanger.AUGSkin, aug, ARRAYSIZE(aug));
        ImGui::Combo(("FAMAS"), &g_Options.Skinchanger.FAMASSkin, famas, ARRAYSIZE(famas));

        ImGui::Columns(1);
        ImGui::Separator();
        ImGui::Text("Snipers");
        ImGui::Columns(2, NULL, false);
        ImGui::Combo(("AWP"), &g_Options.Skinchanger.AWPSkin, awp, ARRAYSIZE(awp));
        ImGui::Combo(("SSG08"), &g_Options.Skinchanger.SSG08Skin, ssg08, ARRAYSIZE(ssg08));
        ImGui::NextColumn();
        ImGui::Combo(("SCAR20"), &g_Options.Skinchanger.SCAR20Skin, scar20, ARRAYSIZE(scar20));

        ImGui::Columns(1);
        ImGui::Separator();
        ImGui::Text("SMG's");
        ImGui::Columns(2, NULL, false);
        ImGui::Combo(("P90"), &g_Options.Skinchanger.P90Skin, p90, ARRAYSIZE(p90));
        ImGui::NextColumn();
        ImGui::Combo(("UMP45"), &g_Options.Skinchanger.UMP45Skin, ump45, ARRAYSIZE(ump45));

        ImGui::Columns(1);
        ImGui::Separator();
        ImGui::Text("Pistols");
        ImGui::Columns(2, NULL, false);
        ImGui::Combo(("Glock-18"), &g_Options.Skinchanger.GlockSkin, glock, ARRAYSIZE(glock));
        ImGui::Combo(("USP-S"), &g_Options.Skinchanger.USPSkin, usp, ARRAYSIZE(usp));
        ImGui::Combo(("Deagle"), &g_Options.Skinchanger.DeagleSkin, deagle, ARRAYSIZE(deagle));

        ImGui::NextColumn();
        ImGui::Combo(("TEC-9"), &g_Options.Skinchanger.tec9Skin, tec9, ARRAYSIZE(tec9));
        ImGui::Combo(("P2000"), &g_Options.Skinchanger.P2000Skin, p2000, ARRAYSIZE(p2000));
        ImGui::Combo(("P250"), &g_Options.Skinchanger.P250Skin, p250, ARRAYSIZE(p250));

    }
}
