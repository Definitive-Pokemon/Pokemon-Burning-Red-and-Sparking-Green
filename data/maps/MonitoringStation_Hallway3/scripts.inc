.set LOCALID_BLUE_DOOR1, 1
.set LOCALID_BLUE_DOOR2, 2
.set LOCALID_YELLOW_DOOR1, 3
.set LOCALID_YELLOW_DOOR2, 4
.set LOCALID_YELLOW_DOOR3, 5

MonitoringStation_Hallway3_MapScripts::
map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Hallway3_EventScript_OnLoad
	.byte 0

MonitoringStation_Hallway3_EventScript_OnLoad::
	call_if_set FLAG_YELLOW_DOOR MonitoringStation_Hallway3_EventScript_YellowDoorShadows
	goto_if_set FLAG_HORROR_ROCKET_MOVED, MonitoringStation_Hallway3_EventScript_PlayWeatherMusic
	
MonitoringStation_Hallway3_EventScript_PlayWeatherMusic::
	goto_if_set FLAG_HORROR_DONE, MonitoringStation_Hallway3_EventScript_DontPlayWeatherMusic
	playbgm MUS_WEATHER_GROUDON, 0
	end
	
MonitoringStation_Hallway3_EventScript_DontPlayWeatherMusic::
	end
	
MonitoringStation_Hallway3_EventScript_YellowDoorShadows::
	setmetatile 11, 19, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 12, 20, METATILE_SilphCo_Floor, 0
	setmetatile 13, 20, METATILE_SilphCo_Floor, 0
	setmetatile 12, 21, METATILE_SilphCo_Floor, 0
	setmetatile 13, 21, METATILE_SilphCo_Floor, 0
	return
	
MonitoringStation_Hallway3_EventScript_BlueDoor::
	lock
	checkitem ITEM_BLUE_KEY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MonitoringStation_Hallway3_EventScript_RemoveBlueDoor
	textcolor 2
	msgbox MonitoringStation_Hallway3_Text_Door
	closemessage
	release
	end
	
MonitoringStation_Hallway3_EventScript_RemoveBlueDoor::
	setflag FLAG_BLUE_DOOR_QUARTER
	playse SE_UNLOCK
	waitse
	removeobject LOCALID_BLUE_DOOR1
	removeobject LOCALID_BLUE_DOOR2
	msgbox MonitoringStation_Hallway3_Text_BlueDoorGone
	closemessage
	release
	end
	
MonitoringStation_Hallway3_EventScript_YellowDoor::
	lock
	checkitem ITEM_YELLOW_KEY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MonitoringStation_Hallway3_EventScript_RemoveYellowDoor
	textcolor 2
	msgbox MonitoringStation_Hallway3_Text_Door
	closemessage
	release
	end
	
MonitoringStation_Hallway3_EventScript_RemoveYellowDoor::
	setflag FLAG_BLUE_DOOR_POKE
	playse SE_UNLOCK
	waitse
	removeobject LOCALID_YELLOW_DOOR1
	removeobject LOCALID_YELLOW_DOOR2
	removeobject LOCALID_YELLOW_DOOR3
	setmetatile 11, 19, METATILE_SilphCo_Floor_ShadeFull, 0
	setmetatile 12, 20, METATILE_SilphCo_Floor, 0
	setmetatile 13, 20, METATILE_SilphCo_Floor, 0
	setmetatile 12, 21, METATILE_SilphCo_Floor, 0
	setmetatile 13, 21, METATILE_SilphCo_Floor, 0
	special DrawWholeMapView
	msgbox MonitoringStation_Hallway3_Text_YellowDoorGone
	closemessage
	release
	end