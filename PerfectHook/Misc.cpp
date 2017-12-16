
#include "Misc.h"
#include "Interfaces.h"
#include "Render.h"
#include <time.h>
#include "BaseClient.h"


std::string animatedclantag;
int iLastTime;
bool bDone=false;
void misc::OnCreateMove(CInput::CUserCmd *cmd, C_BaseEntity *local)
{

	if (g_Options.Misc.Bhop && local->IsAlive())
	{
		if (cmd->buttons & IN_JUMP && !(local->GetMoveType() & MOVETYPE_LADDER))
		{

			int iFlags = local->GetFlags();
			if (!(iFlags & FL_ONGROUND))
				cmd->buttons &= ~IN_JUMP;
		}
	}
	if (g_Options.Misc.namespam)
	{
		char name[151];
		char fucked_char = static_cast<char>(-1);
		for (auto i = 0; i <= 150; i++)
			name[i] = fucked_char;

		const char nick[16] = "name";
		memcpy(name, nick, 11);

		SetName(name);
	}
	static size_t lastTime = 0;
	static int counter = 0;
	if (GetTickCount() > lastTime)
	{

		counter = counter + 1;
		if (counter > 11)
			counter = 0;
		switch (g_Options.Misc.spammer)
		{
		case 1:
			SayInChat(ezfragslist[counter]);
			break;
		}

		lastTime = GetTickCount() + 850;


	}
}

//void misc::AutoStrafe(CInput::CUserCmd *cmd, C_BaseEntity *local)
//{
//
//    QAngle oldangles; g_Engine->GetViewAngles(oldangles);
//    static float move = 450;
//    float s_move = move * 0.5065f;
//    if (local->GetMoveType() & (MOVETYPE_NOCLIP | MOVETYPE_LADDER))
//        return;
//    if (cmd->buttons & (IN_FORWARD | IN_MOVERIGHT | IN_MOVELEFT | IN_BACK))
//        return;
//
//    if (cmd->buttons & IN_JUMP || !(local->GetFlags() & FL_ONGROUND))
//    {
//        cmd->forwardmove = move * 0.015f;
//        cmd->sidemove += (float)(((cmd->tick_count % 2) * 2) - 1) * s_move;
//
//        if (cmd->mousedx)
//            cmd->sidemove = (float)clamp(cmd->mousedx, -1, 1) * s_move;
//
//        static float strafe = cmd->viewangles.y;
//
//        float rt = cmd->viewangles.y, rotation;
//        rotation = strafe - rt;
//
//        if (rotation < FloatNegate(g_Globals->interval_per_tick))
//            cmd->sidemove = -s_move;
//
//        if (rotation > g_Globals->interval_per_tick)
//            cmd->sidemove = s_move;
//
//        strafe = rt;
//    }
//    movementfix(oldangles, cmd, cmd->forwardmove, cmd->sidemove);
//}