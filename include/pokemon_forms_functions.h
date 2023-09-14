#include "global.h"
#include "pokemon.h"

bool8 SpeciesIsForm(u16 species);

u8 GetFormFromSpecies(u16 species);

u16 RemoveFormFromSpecies(u16 species);

struct BaseStats * GetBaseStats(u16 species);

u16 GetFormAndSpeciesFromMon(struct Pokemon * mon);

bool8 PokemonHasVariantForm(u16 species);
