MonitoringStation_Lair_MapScripts::
	.byte 0

MonitoringStation_Lair_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, MonitoringStation_Lair_EventScript_TryRemoveKabutops
	end

MonitoringStation_Lair_EventScript_TryRemoveKabutops::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

MonitoringStation_Lair_OnTransition::
	call_if_set FLAG_FOUGHT_KABUTOPS, MonitoringStation_Lair_EventScript_HideKabutops
	call_if_unset FLAG_FOUGHT_KABUTOPS, MonitoringStation_Lair_EventScript_TryShowKabutops
	end

MonitoringStation_Lair_EventScript_TryShowKabutops::
	goto_if_set FLAG_KABUTOPS_FLED, EventScript_Return
	clearflag FLAG_HIDE_KABUTOPS
	return

MonitoringStation_Lair_EventScript_HideKabutops::
	setflag FLAG_HIDE_KABUTOPS
	return

MonitoringStation_Lair_EventScript_Kabutops::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_KABUTOPS, 15, ITEM_NONE
	waitse
	playmoncry SPECIES_KABUTOPS, 2
	msgbox MonitoringStation_Lair_Text_Kabutops
	waitmessage
	waitmoncry
	delay 10
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MonitoringStation_Lair_EventScript_DefeatedKabutops
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MonitoringStation_Lair_EventScript_RanFromKabutops
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MonitoringStation_Lair_EventScript_RanFromKabutops
	setflag FLAG_FOUGHT_KABUTOPS
	release
	end

MonitoringStation_Lair_EventScript_DefeatedKabutops::
	setflag FLAG_KABUTOPS_FLED
	setvar VAR_0x8004, SPECIES_KABUTOPS
	goto EventScript_MonFlewAway
	end

MonitoringStation_Lair_EventScript_RanFromKabutops::
	setvar VAR_0x8004, SPECIES_KABUTOPS
	goto EventScript_MonFlewAway
	end