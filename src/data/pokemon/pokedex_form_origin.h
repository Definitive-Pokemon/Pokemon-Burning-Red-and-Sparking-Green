#define SEVIIAN_FORM 0

const u8 *gRegionalSymbols[] =
{
    [SEVIIAN_FORM] = gText_SeviiFormSymbol
};

// normally you'd use a macro here, careful
const u8 gFormMonOriginRegion[NUM_FORMS] =
{
    [SPECIES_FOSSILIZED_KABUTOPS - NUM_NON_FORM_MON_SPRITES] = SEVIIAN_FORM
};
