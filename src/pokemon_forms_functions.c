#include "global.h"
#include "pokemon.h"
#include "data/pokemon/forms.h"

bool8 SpeciesIsForm(u16 species)
{
    bool8 result = FALSE;
    if (species | (0x03 << FORM_FLAG_SHIFT))
    {
        result = TRUE;
    }
    return result;
}

u8 GetFormFromSpecies(u16 species)
{
    return species >> FORM_FLAG_SHIFT;
}

u16 RemoveFormFromSpecies(u16 species)
{
    // removes the special form bits
    species = (species & FORM_SPECIES_MASK);
    return species;
}
// retrieves the basestats for us, regardless of whether it is a form or not
// work on it returning a pointer instead?
struct BaseStats *GetBaseStats(u16 species)
{
    if(SpeciesIsForm(species)) 
    {
        u8 form = FORM_PART(species);
        u16 i;
        species = SPECIES_PART(species);
        struct BaseStats result = gBaseStats[SPECIES_NONE];
        for(i = 0; i < NUM_TOTAL_VARIANTS; i++)
        {
            if(gPokemonForms[i].baseSpecies == species &&
                gPokemonForms[i].formNumber == form)
            {
                return gPokemonForms[i].stats;
            }
        }
    }
    else
    {
        return (struct BaseStats *) &gBaseStats[species];
    }
}

u16 GetFormAndSpeciesFromMon(struct Pokemon * mon)
{
    u16 result = GetMonData(mon, MON_DATA_SPECIES);
    u8 form = GetMonData(mon, MON_DATA_FORME);
    result = result | (((u16)form) << FORM_FLAG_SHIFT);
    return result;
}

bool8 PokemonHasVariantForm(u16 species)
{
    bool8 result = FALSE;
    s8 i;
    for (i = 0; i < NUM_TOTAL_VARIANTS; i++)
    {
        if (gPokemonForms[i].baseSpecies == species)
        {
            result = TRUE;
            break;
        }
    }
    return result;
}
