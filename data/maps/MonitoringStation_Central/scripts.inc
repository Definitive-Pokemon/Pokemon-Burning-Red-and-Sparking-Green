.set LOCALID_KABUTOPS_SHADOW, 1
.set LOCALID_ROCKET_M, 2
.set LOCALID_MACHOKE, 3
.set LOCALID_PUSHABLE_BOULDER, 7

MonitoringStation_Central_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Central_EventScript_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MonitoringStation_Central_EventScript_OnFrame
	.byte 0
	
MonitoringStation_Central_EventScript_OnLoad::
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Central_EventScript_GreyDoorAdminShadows
	setflag FLAG_HORROR_HIDE_BOULDER
	end
	
MonitoringStation_Central_EventScript_OnFrame::
	map_script_2 VAR_MONITORING_STATION_CENTRAL_STATE, 0, MonitoringStation_Central_EventScript_Kabutops
	
MonitoringStation_Central_EventScript_GreyDoorAdminShadows::
	setmetatile 2, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 3, 22, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 3, 23, METATILE_SilphCo_HideoutFloor, 0
	setweather WEATHER_NONE
	doweather
	return
	
MonitoringStation_Central_EventScript_GreyDoors::
	lock
	textcolor 2
	msgbox MonitoringStation_Central_Text_GreyDoor
	closemessage
	release
	end
	
MonitoringStation_Central_EventScript_Kabutops::
	lockall
	fadeoutbgm 0
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MonitoringStation_Central_Movement_PanToActionFromTop
	waitmovement 0
	applymovement LOCALID_ROCKET_M, MonitoringStation_Central_Movement_RocketTalk
	waitmovement 0
	textcolor 0
	msgbox MonitoringStation_Central_Text_RocketAttack
	waitmessage
	playmoncry SPECIES_MACHOKE, 2
	textcolor 2
	msgbox MonitoringStation_Central_Text_MachokeNoise
	closemessage
	playse SE_M_VITAL_THROW
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeAttack
	waitmovement 0
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Central_Movement_KabutopsTurn
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeAttack2
	waitmovement 0
	playse SE_M_VITAL_THROW
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeAttackBack
	waitmovement 0
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Central_Movement_KabutopsTurnBack
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeAttackBack2
	waitmovement 0
	playmoncry SPECIES_KABUTOPS, 4
	clearflag FLAG_HORROR_HIDE_BOULDER
	addobject LOCALID_PUSHABLE_BOULDER
	applymovement LOCALID_PUSHABLE_BOULDER, MonitoringStation_Central_Movement_KabutopsAttack
	waitmovement 0
	playse SE_FALL
	applymovement LOCALID_PUSHABLE_BOULDER, MonitoringStation_Central_Movement_KabutopsAttack2
	waitmovement 0
	playmoncry SPECIES_MACHOKE, 5
	playse SE_BANG
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeSlammedAway
	applymovement LOCALID_PUSHABLE_BOULDER, MonitoringStation_Central_Movement_KabutopsAttack3
	waitmovement 0
	delay 100
	textcolor 0
	msgbox MonitoringStation_Central_Text_RocketWhat
	closemessage
	playmoncry SPECIES_KABUTOPS, 11
	waitmoncry
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Central_Movement_KabutopsWalkThrough
	waitmovement 0
	delay 60
	applymovement LOCALID_ROCKET_M, MonitoringStation_Central_Movement_RocketTalk2
	waitmovement 0
	msgbox MonitoringStation_Central_Text_RocketNo
	closemessage
	playmoncry SPECIES_KABUTOPS, 4
	waitmoncry
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Central_Movement_KabutopsWalkThrough2
	waitmovement 0
	applymovement LOCALID_ROCKET_M, MonitoringStation_Central_Movement_RocketTalk3
	waitmovement 0
	delay 200
	msgbox MonitoringStation_Central_Text_RocketOh
	closemessage
	delay 100
	message MonitoringStation_Central_Text_RocketAh
	applymovement LOCALID_ROCKET_M, MonitoringStation_Central_Movement_RocketRun
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_MACHOKE
	removeobject LOCALID_KABUTOPS_SHADOW
	removeobject LOCALID_ROCKET_M
	releaseall
	end

MonitoringStation_Central_Movement_PanToActionFromTop::
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_right
	step_end
	
MonitoringStation_Central_Movement_RocketTalk::
	walk_in_place_right
	step_end

MonitoringStation_Central_Movement_MachokeAttack::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
	
MonitoringStation_Central_Movement_MachokeAttack2::
	walk_fast_right
	walk_in_place_right
	delay_16
	walk_in_place_left
	step_end
	
MonitoringStation_Central_Movement_KabutopsTurn::
	walk_in_place_right
	step_end
	
MonitoringStation_Central_Movement_MachokeAttackBack::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
	
MonitoringStation_Central_Movement_MachokeAttackBack2::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_left
	delay_16
	walk_in_place_right
	step_end
	
MonitoringStation_Central_Movement_KabutopsTurnBack::
	walk_in_place_left
	step_end
	
MonitoringStation_Central_Movement_KabutopsAttack::
	walk_fast_left
	walk_fast_down
	step_end

MonitoringStation_Central_Movement_KabutopsAttack2::	
	walk_fast_left
	walk_fast_left
	step_end
	
MonitoringStation_Central_Movement_KabutopsAttack3::
	walk_left
	walk_left
	step_end
	
MonitoringStation_Central_Movement_MachokeSlammedAway::
	walk_in_place_up
	lock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
	
MonitoringStation_Central_Movement_KabutopsWalkThrough::
	walk_slow_left
	delay_64
	walk_slow_left
	delay_64
	walk_slow_left
	delay_64
	walk_slow_left
	delay_64
	walk_slow_left
	delay_64
	step_end
	
MonitoringStation_Central_Movement_RocketTalk2::
	walk_in_place_right
	step_end
	
MonitoringStation_Central_Movement_KabutopsWalkThrough2::
	walk_left
	delay_32
	walk_left
	delay_32
	walk_left
	delay_32
	walk_left
	delay_32
	walk_left
	delay_32
	walk_left
	delay_32
	step_end
	
MonitoringStation_Central_Movement_RocketTalk3::
	walk_in_place_left
	step_end
	
MonitoringStation_Central_Movement_RocketRun::
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end