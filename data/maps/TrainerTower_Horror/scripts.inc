TrainerTower_Horror_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TrainerTower_Horror_OnLoad
	.byte 0

TrainerTower_Horror_OnLoad::
	goto_if_set FLAG_HORROR_ELEVATOR_BOTTOM, TrainerTower_Horror_BottomAlreadyReached
	@ Case (flag!): to make sure if the player saves in the elevator they exit at SageCave
	@ also, under the same case, activate the weather
	end

TrainerTower_Horror_EventScript_ElevatorControls::
	lock
	goto_if_unset FLAG_HORROR_ELEVATOR_BOTTOM, TrainerTower_Horror_EventScript_PromptFloor
	goto TrainerTower_Horror_ControlsBroke
	end

TrainerTower_Horror_ControlsBroke::
	msgbox TrainerTower_Horror_Text_ElevatorDefunct
	closemessage
	end

TrainerTower_Horror_EventScript_PromptFloor:: 
	@ msgbox
	@ also show current floor?
	multichoice 0, 0, MULTICHOICE_TRAINER_TOWER_HORROR_ELEVATOR, FALSE
	switch VAR_RESULT
	case 0, TrainerTower_Horror_EventScript_CloseFloorSelect
	case 1, TrainerTower_Horror_EventScript_SelectLobby
	case 2, TrainerTower_Horror_EventScript_CloseFloorSelect
	case SCR_MENU_CANCEL, TrainerTower_Horror_EventScript_CloseFloorSelect
	end

TrainerTower_Horror_EventScript_SelectLobby::
	@ todo handle close floor window?
	goto TrainerTower_Horror_EventScript_HorrorSequence
	
TrainerTower_Horror_EventScript_HorrorSequence::
	setvar VAR_0x8005, 8
	setvar VAR_0x8006, 1
	waitse
	special AnimateElevator
	waitstate
	setflag FLAG_TEMP_2
	delay 25
	fadeoutbgm 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 10
	setvar VAR_0x8007, 3
	special ShakeScreen
	delay 60
	playse SE_M_THUNDER_WAVE
	waitse
	playse SE_M_THUNDER_WAVE
	waitse
	setweather WEATHER_SHADE
	doweather
	msgbox TrainerTower_Horror_Text_SomethingHappened
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_ELEVATOR
	waitse
	playse SE_DING_DONG
	waitse
	waitstate
	fadescreen FADE_FROM_BLACK
	delay 100
	@ warp MAP_SAGE_CAVE, 255, 7, 2
	setdynamicwarp MAP_SAGE_CAVE, 255, 7, 2
	setflag FLAG_HORROR_ELEVATOR_BOTTOM
	releaseall
	end
	
TrainerTower_Horror_Text_SomethingHappened::
	.string "The elevator is malfunctioning!$"

TrainerTower_Horror_Text_ElevatorDefunct::
	.string "It doesn't seem to be working...$"

TrainerTower_Horror_EventScript_CloseFloorSelect:: @ 8164BD3
	releaseall
	end

TrainerTower_Horror_BottomAlreadyReached::
	setweather WEATHER_SHADE
	doweather
	fadeoutbgm 0
	setdynamicwarp MAP_SAGE_CAVE, 255, 7, 2
	end
