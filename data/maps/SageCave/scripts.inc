SageCave_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SageCave_EventScript_OnLoad
	.byte 0
	
SageCave_EventScript_OnLoad::
	clearflag FLAG_DONT_TRANSITION_MUSIC
	end
	
SageCave_EventScript_Sign::
	lock
	message SageCave_Text_OutOfOrder
	
SageCave_Text_OutOfOrder::
	.string "The elevator seems to be out of order.$"