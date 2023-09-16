#include "global.h"
#include "level_up_learnsets.h"
#include "tmhm_learnsets.h"
#include "tutor_learnsets.h"

#define FORM_SPECIES_MASK (FIRST_FORM - 1)
#define SPECIES_PART(formSpecies) (formSpecies & FORM_SPECIES_MASK)
#define FORM_PART(formSpecies) (formSpecies >> FORM_FLAG_SHIFT)

/*  */
const struct PokemonForm gPokemonForms[] = 
{
    [0] = 
    {
        .baseSpecies = (u16) 0x408D,
        .formNumber = (u8) FORM_PART(SPECIES_FOSSILIZED_KABUTOPS),
        .stats = (struct BaseStats *) &gFossilizedKabutopsBaseStats,
        .levelUpMoves = (const u16 (*)[])&sFossilizedKabutopsLevelUpLearnset,
        .TMHMMoves = (const u8 (*)[])&sFossilizedKabutopsTMHMLearnset,
        .eggMoves = (const u16 (*)[])&gFossilizedKabutopsEggMoves,
        .tutorMoveFlags = &sFossilizedKabutopsTutorLearnsets,
    },
};
