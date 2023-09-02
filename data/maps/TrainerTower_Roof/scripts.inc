TrainerTower_Roof_MapScripts:: @ 8164828
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, TrainerTower_Roof_OnLoad
	.byte 0

@ Below script is unused, the identical version in the 1F script is used instead

TrainerTower_Roof_EventScript_Owner:: @ 8164833
	call TrainerTower_EventScript_SpeakToOwner
	end

TrainerTower_Roof_OnLoad::
	goto_if_unset FLAG_HORROR_DONE, TrainerTower_Roof_SetHorrorElevator
	clearflag FLAG_HORROR_ELEVATOR_BOTTOM
	@ use default elevator instead
	setdynamicwarp MAP_TRAINER_TOWER_ELEVATOR, 255, 2, 4
	end

TrainerTower_Roof_SetHorrorElevator::
	setdynamicwarp MAP_TRAINER_TOWER_HORROR, 255, 2, 4
	end
