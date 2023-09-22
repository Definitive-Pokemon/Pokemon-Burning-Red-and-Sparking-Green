Special_MapScripts::
	.byte 0

Special_EventScript_Cage::
	lockall
	delay 800
	textcolor 2
	msgbox SpecialArea_Text_Asleep
	waitbuttonpress
	warp MAP_FAKE_PALLET1, 255, 2, 5
	releaseall
	end