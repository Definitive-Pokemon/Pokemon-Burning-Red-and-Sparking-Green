TrainerTower_Elevator_MapScripts:: @ 8164AF8
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_OnFrame
	.byte 0

TrainerTower_Elevator_EventScript_FloorSelect:: @ 8164B03
	lockall
	setvar VAR_0x8004, 6
	call_if_unset FLAG_TEMP_2, EventScript_GetElevatorFloor
	copyvar VAR_0x8005, VAR_ELEVATOR_FLOOR
	special DrawElevatorCurrentFloorWindow
	message Text_WantWhichFloor
	waitmessage
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, InitElevatorFloorSelectMenuPos
	switch VAR_RESULT
	case 0, TrainerTower_Elevator_EventScript_FloorSelectFromRoof
	case 1, TrainerTower_Elevator_EventScript_FloorSelectFromLobby
	end

TrainerTower_Elevator_EventScript_FloorSelectFromRoof:: @ 8164B46
	multichoicedefault 0, 0, MULTICHOICE_ROOFTOP_B1F, 0, FALSE
	goto TrainerTower_Elevator_EventScript_ChooseFloor
	end

TrainerTower_Elevator_EventScript_FloorSelectFromLobby:: @ 8164B52
	multichoicedefault 0, 0, MULTICHOICE_ROOFTOP_B1F, 1, FALSE
	goto TrainerTower_Elevator_EventScript_ChooseFloor
	end

TrainerTower_Elevator_EventScript_ChooseFloor:: @ 8164B5E
	switch VAR_RESULT
	case 0, TrainerTower_Elevator_EventScript_SelectRoof
	case 1, TrainerTower_Elevator_EventScript_SelectLobby
	case 2, TrainerTower_Elevator_EventScript_CloseFloorSelect
	case SCR_MENU_CANCEL, TrainerTower_Elevator_EventScript_CloseFloorSelect
	end

TrainerTower_Elevator_EventScript_SelectLobby:: @ 8164B90
	goto_if_unset FLAG_HORROR_DONE, TrainerTower_Elevator_EventScript_StartHorror
	setvar VAR_0x8006, 3
	setdynamicwarp MAP_TRAINER_TOWER_LOBBY, 255, 17, 8
	compare VAR_ELEVATOR_FLOOR, 3
	goto_if_eq TrainerTower_Elevator_EventScript_CloseFloorSelect
	call TrainerTower_Elevator_EventScript_MoveElevator
	setvar VAR_ELEVATOR_FLOOR, 3
	special CloseElevatorCurrentFloorWindow
	delay 25
	applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Elevator_Movement_ExitElevator
	waitmovement 0
	warp MAP_TRAINER_TOWER_LOBBY, 255, 17, 8
	waitstate
	releaseall
	end
	
TrainerTower_Elevator_EventScript_StartHorror::
	setvar VAR_0x8006, 1
	setdynamicwarp MAP_SAGE_CAVE, 255, 7, 2
	compare VAR_ELEVATOR_FLOOR, 1
	goto_if_eq TrainerTower_Elevator_EventScript_CloseFloorSelect
	call TrainerTower_Elevator_EventScript_MoveElevator
	setvar VAR_ELEVATOR_FLOOR, 1
	special CloseElevatorCurrentFloorWindow
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
	msgbox TrainerTower_Elevator_Text_SomethingHappened
	closemessage
	fadescreen FADE_TO_BLACK
	special AnimateElevator
	waitstate
	fadescreen FADE_FROM_BLACK
	delay 100
	applymovement OBJ_EVENT_ID_PLAYER, TrainerTower_Elevator_Movement_ExitElevator
	waitmovement 0
	warp MAP_SAGE_CAVE, 255, 7, 2
	waitstate
	releaseall
	end
	
TrainerTower_Elevator_Text_SomethingHappened::
	.string "The elevator is malfunctioning!$"

TrainerTower_Elevator_EventScript_SelectRoof:: @ 8164BCD
	goto TrainerTower_Elevator_EventScript_CloseFloorSelect
	end

TrainerTower_Elevator_EventScript_CloseFloorSelect:: @ 8164BD3
	special CloseElevatorCurrentFloorWindow
	releaseall
	end

TrainerTower_Elevator_EventScript_MoveElevator:: @ 8164BD8
	special CloseElevatorCurrentFloorWindow
	closemessage
	waitse
	special AnimateElevator
	waitstate
	setflag FLAG_TEMP_2
	return

TrainerTower_Elevator_Movement_ExitElevator:: @ 8164BE5
	walk_in_place_fastest_down
	delay_16
	walk_down
	walk_right
	walk_right
	walk_down
	step_end
	