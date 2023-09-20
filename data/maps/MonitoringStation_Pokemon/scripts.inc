MonitoringStation_Pokemon_MapScripts::
	.byte 0

MonitoringStation_Pokemon_EventScript_SetDoorRemove::
	setmetatile 5, 1, METATILE_SilphCo_Wall_Upper, 1
	setmetatile 6, 1, METATILE_SilphCo_Wall_Upper, 1
	setmetatile 7, 1, METATILE_SilphCo_Wall_Upper, 1
	setmetatile 5, 2, METATILE_SilphCo_Wall_Lower, 1
	setmetatile 6, 2, METATILE_SilphCo_Wall_Lower, 1
	setmetatile 7, 2, METATILE_SilphCo_Wall_Lower, 1
	special DrawWholeMapView
	setvar VAR_REMOVE_DOOR, 1
	setflag FLAG_DOOR_REMOVE
	end

MonitoringStation_Pokemon_EventScript_Warp::
	lockall
	warp MAP_SPECIAL, 255, 6, 7
	releaseall
	end

MonitoringStation_Pokemon_EventScript_Aggron::
	lock
	playmoncry SPECIES_AGGRON, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Shiftry::
	lock
	playmoncry SPECIES_SHIFTRY, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Rhydon::
	lock
	playmoncry SPECIES_RHYDON, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Typhlosion::
	lock
	playmoncry SPECIES_TYPHLOSION, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Walrein::
	lock
	playmoncry SPECIES_WALREIN, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Gardevoir::
	lock
	playmoncry SPECIES_GARDEVOIR, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Altaria::
	lock
	playmoncry SPECIES_ALTARIA, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Tauros::
	lock
	playmoncry SPECIES_TAUROS, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Ampharos::
	lock
	playmoncry SPECIES_AMPHAROS, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Cacturne::
	lock
	playmoncry SPECIES_CACTURNE, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Houndoom::
	lock
	playmoncry SPECIES_HOUNDOOM, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Venusaur::
	lock
	playmoncry SPECIES_VENUSAUR, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end
	
MonitoringStation_Pokemon_EventScript_Text::
	msgbox MonitoringStation_Pokemon_Text_Text, MSGBOX_SIGN
	end