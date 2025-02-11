// TODO: document trainer pic indices with macro
const u8 gFacilityClassToPicIndex[] =
{
    [FACILITY_CLASS_AQUA_LEADER] = TRAINER_PIC_AQUA_LEADER_ARCHIE,
    [FACILITY_CLASS_TEAM_AQUA] = TRAINER_PIC_AQUA_GRUNT_M,
    [FACILITY_CLASS_TEAM_AQUA_2] = TRAINER_PIC_AQUA_GRUNT_F,
    [FACILITY_CLASS_AROMA_LADY] = TRAINER_PIC_AROMA_LADY,
    [FACILITY_CLASS_RUIN_MANIAC] = TRAINER_PIC_RUIN_MANIAC,
    [FACILITY_CLASS_INTERVIEWER] = TRAINER_PIC_INTERVIEWER,
    [FACILITY_CLASS_TUBER] = TRAINER_PIC_TUBER_F,
    [FACILITY_CLASS_TUBER_2] = TRAINER_PIC_TUBER_M,
    [FACILITY_CLASS_COOLTRAINER] = TRAINER_PIC_COOLTRAINER_M,
    [FACILITY_CLASS_COOLTRAINER_2] = TRAINER_PIC_COOLTRAINER_F,
    [FACILITY_CLASS_HEX_MANIAC] = TRAINER_PIC_HEX_MANIAC,
    [FACILITY_CLASS_LADY] = TRAINER_PIC_LADY,
    [FACILITY_CLASS_BEAUTY] = TRAINER_PIC_BEAUTY,
    [FACILITY_CLASS_RICH_BOY] = TRAINER_PIC_RICH_BOY,
    [FACILITY_CLASS_POKEMANIAC] = TRAINER_PIC_POKEMANIAC,
    [FACILITY_CLASS_SWIMMER_MALE] = TRAINER_PIC_SWIMMER_M,
    [FACILITY_CLASS_BLACK_BELT] = TRAINER_PIC_BLACK_BELT,
    [FACILITY_CLASS_GUITARIST] = TRAINER_PIC_ROCKER,
    [FACILITY_CLASS_KINDLER] = TRAINER_PIC_KINDLER,
    [FACILITY_CLASS_CAMPER] = TRAINER_PIC_CAMPER,
    [FACILITY_CLASS_BUG_MANIAC] = TRAINER_PIC_BUG_MANIAC,
    [FACILITY_CLASS_PSYCHIC] = TRAINER_PIC_PSYCHIC_M,
    [FACILITY_CLASS_PSYCHIC_2] = TRAINER_PIC_PSYCHIC_F,
    [FACILITY_CLASS_GENTLEMAN] = TRAINER_PIC_GENTLEMAN,
    [FACILITY_CLASS_ELITE_FOUR] = TRAINER_PIC_ELITE_FOUR_SIDNEY,
    [FACILITY_CLASS_ELITE_FOUR_2] = TRAINER_PIC_ELITE_FOUR_PHOEBE,
    [FACILITY_CLASS_LEADER] = TRAINER_PIC_LEADER_ROXANNE,
    [FACILITY_CLASS_LEADER_2] = TRAINER_PIC_LEADER_BRAWLY,
    [FACILITY_CLASS_LEADER_3] = TRAINER_PIC_LEADER_TATE_AND_LIZA,
    [FACILITY_CLASS_SCHOOL_KID] = TRAINER_PIC_SCHOOL_KID_M,
    [FACILITY_CLASS_SCHOOL_KID_2] = TRAINER_PIC_SCHOOL_KID_F,
    [FACILITY_CLASS_SR_AND_JR] = TRAINER_PIC_SR_AND_JR,
    [FACILITY_CLASS_POKEFAN] = TRAINER_PIC_POKEFAN_M,
    [FACILITY_CLASS_POKEFAN_2] = TRAINER_PIC_POKEFAN_F,
    [FACILITY_CLASS_EXPERT] = TRAINER_PIC_EXPERT_M,
    [FACILITY_CLASS_EXPERT_2] = TRAINER_PIC_EXPERT_F,
    [FACILITY_CLASS_YOUNGSTER] = TRAINER_PIC_YOUNGSTER,
    [FACILITY_CLASS_CHAMPION] = TRAINER_PIC_CHAMPION_STEVEN,
    [FACILITY_CLASS_FISHERMAN] = TRAINER_PIC_FISHERMAN,
    [FACILITY_CLASS_TRIATHLETE] = TRAINER_PIC_CYCLING_TRIATHLETE_M,
    [FACILITY_CLASS_TRIATHLETE_2] = TRAINER_PIC_CYCLING_TRIATHLETE_F,
    [FACILITY_CLASS_TRIATHLETE_3] = TRAINER_PIC_RUNNING_TRIATHLETE_M,
    [FACILITY_CLASS_TRIATHLETE_4] = TRAINER_PIC_RUNNING_TRIATHLETE_F,
    [FACILITY_CLASS_TRIATHLETE_5] = TRAINER_PIC_SWIMMING_TRIATHLETE_M,
    [FACILITY_CLASS_TRIATHLETE_6] = TRAINER_PIC_SWIMMING_TRIATHLETE_F,
    [FACILITY_CLASS_DRAGON_TAMER] = TRAINER_PIC_DRAGON_TAMER,
    [FACILITY_CLASS_BIRD_KEEPER] = TRAINER_PIC_BIRD_KEEPER,
    [FACILITY_CLASS_NINJA_BOY] = TRAINER_PIC_NINJA_BOY,
    [FACILITY_CLASS_BATTLE_GIRL] = TRAINER_PIC_BATTLE_GIRL,
    [FACILITY_CLASS_PARASOL_LADY] = TRAINER_PIC_PARASOL_LADY,
    [FACILITY_CLASS_SWIMMER_FEMALE] = TRAINER_PIC_SWIMMER_F,
    [FACILITY_CLASS_PICNICKER] = TRAINER_PIC_PICNICKER,
    [FACILITY_CLASS_TWINS] = TRAINER_PIC_TWINS,
    [FACILITY_CLASS_SAILOR] = TRAINER_PIC_SAILOR,
    [FACILITY_CLASS_BOARDER] = TRAINER_PIC_RS_YOUNGSTER,
    [FACILITY_CLASS_BOARDER_2] = TRAINER_PIC_RS_YOUNGSTER,
    [FACILITY_CLASS_COLLECTOR] = TRAINER_PIC_COLLECTOR,
    [FACILITY_CLASS_PKMN_TRAINER] = TRAINER_PIC_WALLY,
    [FACILITY_CLASS_PKMN_TRAINER_2] = TRAINER_PIC_RS_BRENDAN_1,
    [FACILITY_CLASS_PKMN_TRAINER_3] = TRAINER_PIC_RS_BRENDAN_1,
    [FACILITY_CLASS_PKMN_TRAINER_4] = TRAINER_PIC_RS_BRENDAN_1,
    [FACILITY_CLASS_PKMN_TRAINER_5] = TRAINER_PIC_RS_MAY_1,
    [FACILITY_CLASS_PKMN_TRAINER_6] = TRAINER_PIC_RS_MAY_1,
    [FACILITY_CLASS_PKMN_TRAINER_7] = TRAINER_PIC_RS_MAY_1,
    [FACILITY_CLASS_PKMN_BREEDER] = TRAINER_PIC_POKEMON_BREEDER_M,
    [FACILITY_CLASS_PKMN_BREEDER_2] = TRAINER_PIC_POKEMON_BREEDER_F,
    [FACILITY_CLASS_PKMN_RANGER] = TRAINER_PIC_POKEMON_RANGER_M,
    [FACILITY_CLASS_PKMN_RANGER_2] = TRAINER_PIC_POKEMON_RANGER_F,
    [FACILITY_CLASS_MAGMA_LEADER] = TRAINER_PIC_MAGMA_LEADER_MAXIE,
    [FACILITY_CLASS_TEAM_MAGMA] = TRAINER_PIC_MAGMA_GRUNT_M,
    [FACILITY_CLASS_TEAM_MAGMA_2] = TRAINER_PIC_MAGMA_GRUNT_F,
    [FACILITY_CLASS_LASS] = TRAINER_PIC_LASS,
    [FACILITY_CLASS_BUG_CATCHER] = TRAINER_PIC_BUG_CATCHER,
    [FACILITY_CLASS_HIKER] = TRAINER_PIC_HIKER,
    [FACILITY_CLASS_YOUNG_COUPLE] = TRAINER_PIC_YOUNG_COUPLE,
    [FACILITY_CLASS_OLD_COUPLE] = TRAINER_PIC_OLD_COUPLE,
    [FACILITY_CLASS_SIS_AND_BRO] = TRAINER_PIC_SIS_AND_BRO,
    [FACILITY_CLASS_AQUA_ADMIN] = TRAINER_PIC_AQUA_ADMIN_M,
    [FACILITY_CLASS_AQUA_ADMIN_2] = TRAINER_PIC_AQUA_ADMIN_F,
    [FACILITY_CLASS_MAGMA_ADMIN] = TRAINER_PIC_MAGMA_ADMIN_M,
    [FACILITY_CLASS_MAGMA_ADMIN_2] = TRAINER_PIC_MAGMA_ADMIN_F,
    [FACILITY_CLASS_LEADER_4] = TRAINER_PIC_LEADER_WATTSON,
    [FACILITY_CLASS_LEADER_5] = TRAINER_PIC_LEADER_FLANNERY,
    [FACILITY_CLASS_LEADER_6] = TRAINER_PIC_LEADER_NORMAN,
    [FACILITY_CLASS_LEADER_7] = TRAINER_PIC_LEADER_WINONA,
    [FACILITY_CLASS_LEADER_8] = TRAINER_PIC_LEADER_WALLACE,
    [FACILITY_CLASS_ELITE_FOUR_3] = TRAINER_PIC_ELITE_FOUR_GLACIA,
    [FACILITY_CLASS_ELITE_FOUR_4] = TRAINER_PIC_ELITE_FOUR_DRAKE,
    [FACILITY_CLASS_YOUNGSTER_2] = 82,
    [FACILITY_CLASS_BUG_CATCHER_2] = 83,
    [FACILITY_CLASS_LASS_2] = 84,
    [FACILITY_CLASS_SAILOR_2] = 85,
    [FACILITY_CLASS_CAMPER_2] = 86,
    [FACILITY_CLASS_PICNICKER_2] = 87,
    [FACILITY_CLASS_POKEMANIAC_2] = 88,
    [FACILITY_CLASS_SUPER_NERD] = 89,
    [FACILITY_CLASS_HIKER_2] = 90,
    [FACILITY_CLASS_BIKER] = 91,
    [FACILITY_CLASS_BURGLAR] = 92,
    [FACILITY_CLASS_ENGINEER] = 93,
    [FACILITY_CLASS_FISHERMAN_2] = 94,
    [FACILITY_CLASS_SWIMMER_MALE_2] = 95,
    [FACILITY_CLASS_CUE_BALL] = 96,
    [FACILITY_CLASS_GAMER] = 97,
    [FACILITY_CLASS_BEAUTY_2] = 98,
    [FACILITY_CLASS_SWIMMER_FEMALE_2] = 99,
    [FACILITY_CLASS_PSYCHIC_3] = 100,
    [FACILITY_CLASS_ROCKER] = 101,
    [FACILITY_CLASS_JUGGLER] = 102,
    [FACILITY_CLASS_TAMER] = 103,
    [FACILITY_CLASS_BIRD_KEEPER_2] = 104,
    [FACILITY_CLASS_BLACK_BELT_2] = 105,
    [FACILITY_CLASS_RIVAL] = 106,
    [FACILITY_CLASS_SCIENTIST] = 107,
    [FACILITY_CLASS_BOSS] = 108,
    [FACILITY_CLASS_TEAM_ROCKET] = 109,
    [FACILITY_CLASS_COOLTRAINER_3] = 110,
    [FACILITY_CLASS_COOLTRAINER_4] = 111,
    [FACILITY_CLASS_ELITE_FOUR_5] = 112,
    [FACILITY_CLASS_ELITE_FOUR_6] = 113,
    [FACILITY_CLASS_LEADER_9] = 116,
    [FACILITY_CLASS_LEADER_10] = 117,
    [FACILITY_CLASS_GENTLEMAN_2] = 123,
    [FACILITY_CLASS_RIVAL_2] = 124,
    [FACILITY_CLASS_CHAMPION_2] = 125,
    [FACILITY_CLASS_CHANNELER] = 126,
    [FACILITY_CLASS_TWINS_2] = 127,
    [FACILITY_CLASS_COOL_COUPLE] = 128,
    [FACILITY_CLASS_YOUNG_COUPLE_2] = 129,
    [FACILITY_CLASS_CRUSH_KIN] = 130,
    [FACILITY_CLASS_SIS_AND_BRO_2] = 131,
    [FACILITY_CLASS_PKMN_PROF] = 132,
    [FACILITY_CLASS_BRENDAN] = TRAINER_PIC_RS_BRENDAN_2,
    [FACILITY_CLASS_MAY] = TRAINER_PIC_RS_MAY_2,
    [FACILITY_CLASS_RED] = TRAINER_PIC_RED,
    [FACILITY_CLASS_LEAF] = TRAINER_PIC_LEAF,
    [FACILITY_CLASS_TEAM_ROCKET_2] = 137,
    [FACILITY_CLASS_PSYCHIC_4] = 138,
    [FACILITY_CLASS_CRUSH_GIRL] = 139,
    [FACILITY_CLASS_TUBER_3] = 140,
    [FACILITY_CLASS_PKMN_BREEDER_3] = 141,
    [FACILITY_CLASS_PKMN_RANGER_3] = 142,
    [FACILITY_CLASS_PKMN_RANGER_4] = 143,
    [FACILITY_CLASS_AROMA_LADY_2] = 144,
    [FACILITY_CLASS_RUIN_MANIAC_2] = 145,
    [FACILITY_CLASS_LADY_2] = 146,
    [FACILITY_CLASS_PAINTER] = 147,
    [FACILITY_CLASS_ELITE_FOUR_7] = 112,
    [FACILITY_CLASS_ELITE_FOUR_8] = 113,
    [FACILITY_CLASS_CHAMPION_3] = 125,
    [FACILITY_CLASS_EM_BRENDAN] = TRAINER_PIC_EM_BRENDAN,
    [FACILITY_CLASS_EM_MAY] = TRAINER_PIC_EM_MAY,
	[FACILITY_CLASS_MYSTERY_GIRL] = TRAINER_PIC_ANABEL,
};

const u8 gFacilityClassToTrainerClass[] =
{
    [FACILITY_CLASS_AQUA_LEADER] = TRAINER_PIC_AQUA_LEADER_ARCHIE,
    [FACILITY_CLASS_TEAM_AQUA] = CLASS_TEAM_AQUA,
    [FACILITY_CLASS_TEAM_AQUA_2] = CLASS_TEAM_AQUA,
    [FACILITY_CLASS_AROMA_LADY] = CLASS_AROMA_LADY,
    [FACILITY_CLASS_RUIN_MANIAC] = CLASS_RUIN_MANIAC,
    [FACILITY_CLASS_INTERVIEWER] = CLASS_INTERVIEWER,
    [FACILITY_CLASS_TUBER] = CLASS_TUBER,
    [FACILITY_CLASS_TUBER_2] = CLASS_TUBER_2,
    [FACILITY_CLASS_COOLTRAINER] = CLASS_COOLTRAINER,
    [FACILITY_CLASS_COOLTRAINER_2] = CLASS_COOLTRAINER,
    [FACILITY_CLASS_HEX_MANIAC] = CLASS_HEX_MANIAC,
    [FACILITY_CLASS_LADY] = CLASS_LADY,
    [FACILITY_CLASS_BEAUTY] = CLASS_BEAUTY,
    [FACILITY_CLASS_RICH_BOY] = CLASS_RICH_BOY,
    [FACILITY_CLASS_POKEMANIAC] = CLASS_POKEMANIAC,
    [FACILITY_CLASS_SWIMMER_MALE] = CLASS_SWIMMER_MALE,
    [FACILITY_CLASS_BLACK_BELT] = CLASS_BLACK_BELT,
    [FACILITY_CLASS_GUITARIST] = CLASS_ENGINEER,
    [FACILITY_CLASS_KINDLER] = CLASS_KINDLER,
    [FACILITY_CLASS_CAMPER] = CLASS_CAMPER,
    [FACILITY_CLASS_BUG_MANIAC] = CLASS_BUG_MANIAC,
    [FACILITY_CLASS_PSYCHIC] = CLASS_PSYCHIC,
    [FACILITY_CLASS_PSYCHIC_2] = CLASS_PSYCHIC,
    [FACILITY_CLASS_GENTLEMAN] = CLASS_GENTLEMAN,
    [FACILITY_CLASS_ELITE_FOUR] = CLASS_ELITE_FOUR,
    [FACILITY_CLASS_ELITE_FOUR_2] = CLASS_ELITE_FOUR,
    [FACILITY_CLASS_LEADER] = CLASS_LEADER,
    [FACILITY_CLASS_LEADER_2] = CLASS_LEADER,
    [FACILITY_CLASS_LEADER_3] = CLASS_LEADER,
    [FACILITY_CLASS_SCHOOL_KID] = CLASS_SCHOOL_KID,
    [FACILITY_CLASS_SCHOOL_KID_2] = CLASS_SCHOOL_KID,
    [FACILITY_CLASS_SR_AND_JR] = CLASS_SR_AND_JR,
    [FACILITY_CLASS_POKEFAN] = CLASS_POKEFAN,
    [FACILITY_CLASS_POKEFAN_2] = CLASS_POKEFAN,
    [FACILITY_CLASS_EXPERT] = CLASS_EXPERT,
    [FACILITY_CLASS_EXPERT_2] = CLASS_EXPERT,
    [FACILITY_CLASS_YOUNGSTER] = CLASS_YOUNGSTER,
    [FACILITY_CLASS_CHAMPION] = CLASS_CHAMPION,
    [FACILITY_CLASS_FISHERMAN] = CLASS_FISHERMAN,
    [FACILITY_CLASS_TRIATHLETE] = CLASS_TRIATHLETE,
    [FACILITY_CLASS_TRIATHLETE_2] = CLASS_TRIATHLETE,
    [FACILITY_CLASS_TRIATHLETE_3] = CLASS_TRIATHLETE,
    [FACILITY_CLASS_TRIATHLETE_4] = CLASS_TRIATHLETE,
    [FACILITY_CLASS_TRIATHLETE_5] = CLASS_TRIATHLETE,
    [FACILITY_CLASS_TRIATHLETE_6] = CLASS_TRIATHLETE,
    [FACILITY_CLASS_DRAGON_TAMER] = CLASS_DRAGON_TAMER,
    [FACILITY_CLASS_BIRD_KEEPER] = CLASS_BIRD_KEEPER,
    [FACILITY_CLASS_NINJA_BOY] = CLASS_NINJA_BOY,
    [FACILITY_CLASS_BATTLE_GIRL] = CLASS_BATTLE_GIRL,
    [FACILITY_CLASS_PARASOL_LADY] = CLASS_PARASOL_LADY,
    [FACILITY_CLASS_SWIMMER_FEMALE] = CLASS_SWIMMER_FEMALE,
    [FACILITY_CLASS_PICNICKER] = CLASS_PICNICKER,
    [FACILITY_CLASS_TWINS] = CLASS_TWINS,
    [FACILITY_CLASS_SAILOR] = CLASS_SAILOR,
    [FACILITY_CLASS_BOARDER] = CLASS_BOARDER,
    [FACILITY_CLASS_BOARDER_2] = CLASS_BOARDER,
    [FACILITY_CLASS_COLLECTOR] = CLASS_COLLECTOR,
    [FACILITY_CLASS_PKMN_TRAINER] = CLASS_PKMN_TRAINER_3,
    [FACILITY_CLASS_PKMN_TRAINER_2] = CLASS_PKMN_TRAINER_3,
    [FACILITY_CLASS_PKMN_TRAINER_3] = CLASS_PKMN_TRAINER_3,
    [FACILITY_CLASS_PKMN_TRAINER_4] = CLASS_PKMN_TRAINER_3,
    [FACILITY_CLASS_PKMN_TRAINER_5] = CLASS_PKMN_TRAINER_3,
    [FACILITY_CLASS_PKMN_TRAINER_6] = CLASS_PKMN_TRAINER_3,
    [FACILITY_CLASS_PKMN_TRAINER_7] = CLASS_PKMN_TRAINER_3,
    [FACILITY_CLASS_PKMN_BREEDER] = CLASS_PKMN_BREEDER,
    [FACILITY_CLASS_PKMN_BREEDER_2] = CLASS_PKMN_BREEDER,
    [FACILITY_CLASS_PKMN_RANGER] = CLASS_PKMN_RANGER,
    [FACILITY_CLASS_PKMN_RANGER_2] = CLASS_PKMN_RANGER,
    [FACILITY_CLASS_MAGMA_LEADER] = CLASS_MAGMA_LEADER,
    [FACILITY_CLASS_TEAM_MAGMA] = CLASS_TEAM_MAGMA,
    [FACILITY_CLASS_TEAM_MAGMA_2] = CLASS_TEAM_MAGMA,
    [FACILITY_CLASS_LASS] = CLASS_LASS,
    [FACILITY_CLASS_BUG_CATCHER] = CLASS_BUG_CATCHER,
    [FACILITY_CLASS_HIKER] = CLASS_HIKER,
    [FACILITY_CLASS_YOUNG_COUPLE] = CLASS_YOUNG_COUPLE,
    [FACILITY_CLASS_OLD_COUPLE] = CLASS_OLD_COUPLE,
    [FACILITY_CLASS_SIS_AND_BRO] = CLASS_SIS_AND_BRO,
    [FACILITY_CLASS_AQUA_ADMIN] = CLASS_AQUA_ADMIN,
    [FACILITY_CLASS_AQUA_ADMIN_2] = CLASS_AQUA_ADMIN,
    [FACILITY_CLASS_MAGMA_ADMIN] = CLASS_MAGMA_ADMIN,
    [FACILITY_CLASS_MAGMA_ADMIN_2] = CLASS_MAGMA_ADMIN,
    [FACILITY_CLASS_LEADER_4] = CLASS_LEADER,
    [FACILITY_CLASS_LEADER_5] = CLASS_LEADER,
    [FACILITY_CLASS_LEADER_6] = CLASS_LEADER,
    [FACILITY_CLASS_LEADER_7] = CLASS_LEADER,
    [FACILITY_CLASS_LEADER_8] = CLASS_LEADER,
    [FACILITY_CLASS_ELITE_FOUR_3] = CLASS_ELITE_FOUR,
    [FACILITY_CLASS_ELITE_FOUR_4] = CLASS_ELITE_FOUR,
    [FACILITY_CLASS_YOUNGSTER_2] = CLASS_YOUNGSTER_2,
    [FACILITY_CLASS_BUG_CATCHER_2] = CLASS_BUG_CATCHER_2,
    [FACILITY_CLASS_LASS_2] = CLASS_LASS_2,
    [FACILITY_CLASS_SAILOR_2] = CLASS_SAILOR_2,
    [FACILITY_CLASS_CAMPER_2] = CLASS_CAMPER_2,
    [FACILITY_CLASS_PICNICKER_2] = CLASS_PICNICKER_2,
    [FACILITY_CLASS_POKEMANIAC_2] = CLASS_POKEMANIAC_2,
    [FACILITY_CLASS_SUPER_NERD] = CLASS_SUPER_NERD,
    [FACILITY_CLASS_HIKER_2] = CLASS_HIKER_2,
    [FACILITY_CLASS_BIKER] = CLASS_BIKER,
    [FACILITY_CLASS_BURGLAR] = CLASS_BURGLAR,
    [FACILITY_CLASS_ENGINEER] = CLASS_ENGINEER,
    [FACILITY_CLASS_FISHERMAN_2] = CLASS_FISHERMAN_2,
    [FACILITY_CLASS_SWIMMER_MALE_2] = CLASS_SWIMMER_MALE_2,
    [FACILITY_CLASS_CUE_BALL] = CLASS_CUE_BALL,
    [FACILITY_CLASS_GAMER] = CLASS_GAMER,
    [FACILITY_CLASS_BEAUTY_2] = CLASS_BEAUTY_2,
    [FACILITY_CLASS_SWIMMER_FEMALE_2] = CLASS_SWIMMER_FEMALE_2,
    [FACILITY_CLASS_PSYCHIC_3] = CLASS_PSYCHIC_2,
    [FACILITY_CLASS_ROCKER] = CLASS_ROCKER,
    [FACILITY_CLASS_JUGGLER] = CLASS_JUGGLER,
    [FACILITY_CLASS_TAMER] = CLASS_TAMER,
    [FACILITY_CLASS_BIRD_KEEPER_2] = CLASS_BIRD_KEEPER_2,
    [FACILITY_CLASS_BLACK_BELT_2] = CLASS_BLACK_BELT_2,
    [FACILITY_CLASS_RIVAL] = CLASS_RIVAL,
    [FACILITY_CLASS_SCIENTIST] = CLASS_SCIENTIST,
    [FACILITY_CLASS_BOSS] = CLASS_BOSS,
    [FACILITY_CLASS_TEAM_ROCKET] = CLASS_TEAM_ROCKET,
    [FACILITY_CLASS_COOLTRAINER_3] = CLASS_COOLTRAINER_2,
    [FACILITY_CLASS_COOLTRAINER_4] = CLASS_COOLTRAINER_2,
    [FACILITY_CLASS_ELITE_FOUR_5] = CLASS_ELITE_FOUR_2,
    [FACILITY_CLASS_ELITE_FOUR_6] = CLASS_ELITE_FOUR_2,
    [FACILITY_CLASS_LEADER_9] = CLASS_LEADER_2,
    [FACILITY_CLASS_LEADER_10] = CLASS_LEADER_2,
    [FACILITY_CLASS_GENTLEMAN_2] = CLASS_GENTLEMAN_2,
    [FACILITY_CLASS_RIVAL_2] = CLASS_RIVAL_2,
    [FACILITY_CLASS_CHAMPION_2] = CLASS_CHAMPION_2,
    [FACILITY_CLASS_CHANNELER] = CLASS_CHANNELER,
    [FACILITY_CLASS_TWINS_2] = CLASS_TWINS_2,
    [FACILITY_CLASS_COOL_COUPLE] = CLASS_COOL_COUPLE,
    [FACILITY_CLASS_YOUNG_COUPLE_2] = CLASS_YOUNG_COUPLE_2,
    [FACILITY_CLASS_CRUSH_KIN] = CLASS_CRUSH_KIN,
    [FACILITY_CLASS_SIS_AND_BRO_2] = CLASS_SIS_AND_BRO_2,
    [FACILITY_CLASS_PKMN_PROF] = CLASS_PKMN_PROF,
    [FACILITY_CLASS_BRENDAN] = CLASS_PLAYER,
    [FACILITY_CLASS_MAY] = CLASS_PLAYER,
    [FACILITY_CLASS_RED] = CLASS_PLAYER,
    [FACILITY_CLASS_LEAF] = CLASS_PLAYER,
    [FACILITY_CLASS_TEAM_ROCKET_2] = CLASS_TEAM_ROCKET,
    [FACILITY_CLASS_PSYCHIC_4] = CLASS_PSYCHIC_2,
    [FACILITY_CLASS_CRUSH_GIRL] = CLASS_CRUSH_GIRL,
    [FACILITY_CLASS_TUBER_3] = CLASS_TUBER_3,
    [FACILITY_CLASS_PKMN_BREEDER_3] = CLASS_PKMN_BREEDER_2,
    [FACILITY_CLASS_PKMN_RANGER_3] = CLASS_PKMN_RANGER_2,
    [FACILITY_CLASS_PKMN_RANGER_4] = CLASS_PKMN_RANGER_2,
    [FACILITY_CLASS_AROMA_LADY_2] = CLASS_AROMA_LADY_2,
    [FACILITY_CLASS_RUIN_MANIAC_2] = CLASS_RUIN_MANIAC_2,
    [FACILITY_CLASS_LADY_2] = CLASS_LADY_2,
    [FACILITY_CLASS_PAINTER] = CLASS_PAINTER,
    [FACILITY_CLASS_ELITE_FOUR_7] = CLASS_ELITE_FOUR_2,
    [FACILITY_CLASS_ELITE_FOUR_8] = CLASS_ELITE_FOUR_2,
    [FACILITY_CLASS_CHAMPION_3] = CLASS_CHAMPION_2,
    [FACILITY_CLASS_EM_BRENDAN] = CLASS_PKMN_TRAINER_3,
    [FACILITY_CLASS_EM_MAY] = CLASS_PKMN_TRAINER_3,
	[FACILITY_CLASS_MYSTERY_GIRL] = TRAINER_PIC_ANABEL,
};
