#include "global.h"

#define FORM_SPECIES_MASK FIRST_FORM - 1
#define SPECIES_PART(formSpecies) formSpecies & FORM_SPECIES_MASK
#define FORM_PART(formSpecies) formSpecies >> FORM_FLAG_SHIFT

/*  */
const struct PokemonForm gPokemonForms [] = 
{
    [0] = 
    {
        .baseSpecies = SPECIES_PART(SPECIES_FOSSILIZED_KABUTOPS);
        .formNumber = FORM_PART(SPECIES_FOSSILIZED_KABUTOPS);
        .stats = gFossilizedKabutopsBaseStats;
        .levelUpMoves = sFossilizedKabutopsLevelUpLearnset;
        .TMHMMoves = sFossilizedKabutopsTMHMLearnset;
        .eggMoves = gFossilizedKabutopsEggMoves;
        .tutorMoveFlags = sFossilizedKabutopsTutorLearnsets;
    },
};
