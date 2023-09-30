.set LOCALID_BLUE_DOOR1, 1
.set LOCALID_BLUE_DOOR2, 2
.set LOCALID_YELLOW_DOOR1, 3
.set LOCALID_YELLOW_DOOR2, 4
.set LOCALID_YELLOW_DOOR3, 5

MonitoringStation_Hallway3_MapScripts::
map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Hallway3_EventScript_OnLoad
map_script MAP_SCRIPT_ON_FRAME_TABLE, MonitoringStation_Hallway3_EventScript_OnFrame
	.byte 0
	
MonitoringStation_Hallway3_EventScript_OnFrame::
	map_script_2 VAR_MONITORING_STATION_HALLWAY, 0, MonitoringStation_Hallway3_EventScript_AdminTalk
	end

MonitoringStation_Hallway3_EventScript_OnLoad::
	call_if_set FLAG_YELLOW_DOOR MonitoringStation_Hallway3_EventScript_YellowDoorShadows
	end
	
MonitoringStation_Hallway3_EventScript_AdminTalk::
	lockall
	delay 20
	msgbox MonitoringStation_Hallway3_Text_AdminTalk
	closemessage
	setvar VAR_MONITORING_STATION_HALLWAY, 1
	warp MAP_MONITORING_STATION, 255, 3, 11
	releaseall
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
	playse SE_RS_DOOR
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
	setflag FLAG_YELLOW_DOOR
	playse SE_RS_DOOR
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