Special_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Special_EventScript_OnFrame
	.byte 0

Special_EventScript_OnFrame::
	delay 999
	textcolor 2
	msgbox SpecialArea_Text_Asleep
	waitbuttonpress
	warp MAP_FAKE_PALLET1, 255, 2, 5
	end
	.byte 0