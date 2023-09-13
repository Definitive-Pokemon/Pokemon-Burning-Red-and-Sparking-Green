.set LOCALID_BLUE_DOOR1, 1
.set LOCALID_BLUE_DOOR2, 2
.set LOCALID_ROCKET_M, 3

MonitoringStation_Storage_MapScripts::
map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Storage_EventScript_OnLoad
	.byte 0

MonitoringStation_Storage_EventScript_OnLoad::
	call_if_set FLAG_BLUE_DOOR_POKE, MonitoringStation_Storage_EventScript_BlueDoorPokeShadows
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Storage_EventScript_Restore_Power
	goto_if_set FLAG_HORROR_ROCKET_MOVED, MonitoringStation_Storage_EventScript_PlayWeatherMusic
	
MonitoringStation_Storage_EventScript_PlayWeatherMusic::
	goto_if_set FLAG_HORROR_DONE, MonitoringStation_Storage_EventScript_DontPlayWeatherMusic
	playbgm MUS_WEATHER_GROUDON, 1
	end
	
MonitoringStation_Storage_EventScript_DontPlayWeatherMusic::
	end
	
MonitoringStation_Storage_EventScript_BlueDoorPokeShadows::
	setmetatile 19, 7, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 20, 8, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 9, METATILE_SilphCo_HideoutFloor, 0
	return
	
MonitoringStation_Storage_EventScript_BlueDoor::
	lock
	checkitem ITEM_BLUE_KEY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MonitoringStation_Storage_EventScript_RemoveBlueDoor
	textcolor 2
	msgbox MonitoringStation_Storage_Text_BlueDoor
	closemessage
	release
	end
	
MonitoringStation_Storage_EventScript_RemoveBlueDoor::
	setflag FLAG_BLUE_DOOR_POKE
	playse SE_UNLOCK
	waitse
	removeobject LOCALID_BLUE_DOOR1
	removeobject LOCALID_BLUE_DOOR2
	setmetatile 19, 7, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 20, 8, METATILE_SilphCo_HideoutFloor , 0
	setmetatile 20, 9, METATILE_SilphCo_HideoutFloor , 0
	special DrawWholeMapView
	msgbox MonitoringStation_Storage_Text_BlueDoorGone
	closemessage
	release
	end
	
MonitoringStation_Storage_EventScript_Restore_Power::
	setweather WEATHER_NONE
	doweather
	return
	
MonitoringStation_Storage_EventScript_Rocket::
	lock
	faceplayer
	goto_if_set FLAG_HORROR_ROCKET_EXPLAINED, MonitoringStation_Storage_EventScript_RocketDone
	msgbox MonitoringStation_Storage_Text_Explain
	waitmessage
	applymovement LOCALID_ROCKET_M, MonitoringStation_Storage_Movement_Rocket
	waitmovement 0
	msgbox MonitoringStation_Storage_Text_RedKeyAdmin
	setflag FLAG_HORROR_ROCKET_EXPLAINED
	release
	end
	
MonitoringStation_Storage_EventScript_RocketDone::
	msgbox MonitoringStation_Storage_Text_Done
	release
	end
	
	
MonitoringStation_Storage_Movement_Rocket::
	walk_in_place_up
	delay_16
	walk_in_place_left
	delay_16
	step_end