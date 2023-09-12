MonitoringStation_Central_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Central_EventScript_OnLoad
	.byte 0
	
MonitoringStation_Central_EventScript_OnLoad::
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Central_EventScript_GreyDoorAdminShadows
	goto_if_set FLAG_HORROR_ROCKET_MOVED, MonitoringStation_Central_EventScript_PlayWeatherMusic
	end
	
MonitoringStation_Central_EventScript_GreyDoorAdminShadows::
	setmetatile 2, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 3, 22, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 3, 23, METATILE_SilphCo_HideoutFloor, 0
	setweather WEATHER_NONE
	doweather
	return
	
MonitoringStation_Central_EventScript_PlayWeatherMusic::
	goto_if_set FLAG_HORROR_DONE, MonitoringStation_Central_EventScript_DontPlayWeatherMusic
	playbgm MUS_WEATHER_GROUDON, 1
	end
	
MonitoringStation_Central_EventScript_DontPlayWeatherMusic::
	end
	
MonitoringStation_Central_EventScript_GreyDoors::
	lock
	textcolor 2
	msgbox MonitoringStation_Central_Text_GreyDoor
	closemessage
	release
	end
	
