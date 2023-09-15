PokeCenter_MapScripts::
	.byte 0

Pokecenter_EventScript_NoHope::
	lock
	textcolor 2
	msgbox Pokecenter_Text_NoHope
	waitmessage
	setvar VAR_NOHOPE, 1
	release
	end
	
Pokecenter_EventScript_Pointless::
	lock
	textcolor 2
	msgbox Pokecenter_Text_Pointless
	waitmessage
	setvar VAR_POINTLESS, 1
	release
	end
	
Pokecenter_EventScript_BeyondReach::
	lock
	textcolor 2
	msgbox Pokecenter_Text_BeyondReach
	waitmessage
	setvar VAR_BEYONDREACH, 1
	release
	end
	
Pokecenter_EventScript_DontGiveUp::
	lock
	textcolor 2
	msgbox Pokecenter_Text_DontGiveUp
	waitmessage
	setvar VAR_DONTGIVEUP, 1
	release
	end
	
Pokecenter_EventScript_KeepTrying::
	lock
	textcolor 2
	msgbox Pokecenter_Text_KeepTrying
	waitmessage
	setvar VAR_KEEPTRYING, 1
	release
	end
	
Pokecenter_EventScript_Determination::
	lock
	textcolor 2
	msgbox Pokecenter_Text_Determination
	waitmessage
	setvar VAR_DETERMINATION, 1
	release
	end
	
Pokecenter_EventScript_AlmostThere::
	lock
	textcolor 2
	msgbox Pokecenter_Text_AlmostThere
	waitmessage
	setvar VAR_ALMOSTTHERE, 1
	release
	end
	
Pokecenter_EventScript_TheEnd::
	lock
	textcolor 2
	msgbox Pokecenter_Text_TheEnd
	waitmessage
	setflag FLAG_HORROR_ABSOLUTE
	clearflag FLAG_HIDE_HORROR_NPC
	warp MAP_MONITORING_STATION_SHORTCUT, 255, 3, 3
	release
	end