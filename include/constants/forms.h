#ifndef GUARD_CONSTANTS_FORMS_H
#define GUARD_CONSTANTS_FORMS_H

#include "species.h"

#define FORM_FLAG_SHIFT 14
// zero form is simply the 'normal' Gen 3 pokemon!
#define FORM_FLAG_VALUE(form) ((u16)(form) << FORM_FLAG_SHIFT)
#define FIRST_FORM FORM_FLAG_VALUE(1)
#define SECOND_FORM FORM_FLAG_VALUE(2)
#define THIRD_FORM FORM_FLAG_VALUE(3)
#define FORM_SPECIES_MASK (FIRST_FORM - 1)
#define FORM_PART(formSpecies) ((u16)(formSpecies) >>> FORM_FLAG_SHIFT)
#define SPECIES_PART(species) ((species) & ((u16) FORM_SPECIES_MASK))
#define FORM_SPECIES_NUMBER(form, species) ((species) | (form))

// this is the exact order pokemon forms appear in ROM pokemon data tables
// These definitions should only be used inside data files
#define FORM_FOSSILIZED_KABUTOPS 0
#define NUM_TOTAL_VARIANTS 1

// Order of this list is unimportant, these definitions can be used in
// wild pokemon encounters, trainer party data etc..
#define SPECIES_FOSSILIZED_KABUTOPS FORM_SPECIES_NUMBER(FIRST_FORM, SPECIES_KABUTOPS)

// DEOXYS FRLGPlus revamped

#define FORME_DEOXYS_NORMAL 0
#define FORME_DEOXYS_ATTACK 1
#define FORME_DEOXYS_DEFENSE 2
#define FORME_DEOXYS_SPEED 3

#define FORM_NUM_BITS 2

#define SPECIES_DEOXYS_NORMAL_FORME SPECIES_DEOXYS
#define SPECIES_DEOXYS_ATTACK_FORME ((FORME_DEOXYS_ATTACK << (FORM_FLAG_SHIFT - FORM_NUM_BITS)) | SPECIES_DEOXYS)
#define SPECIES_DEOXYS_DEFENSE_FORME ((FORME_DEOXYS_DEFENSE << (FORM_FLAG_SHIFT - FORM_NUM_BITS)) | SPECIES_DEOXYS)
#define SPECIES_DEOXYS_SPEED_FORME ((FORME_DEOXYS_SPEED << (FORM_FLAG_SHIFT - FORM_NUM_BITS)) | SPECIES_DEOXYS)

#define DEOXYS_START_FORME_NUM SPECIES_DEOXYS_ATTACK_FORME
#define DEOXYS_LAST_FORME_NUM SPECIES_DEOXYS_SPEED_FORME

#define SPECIES_PART_INCLUDING_DEOXYS(formSpecies) ((formSpecies) & ((u16) (1 << (FORM_FLAG_SHIFT - FORM_NUM_BITS)) - 1))
#define FORM_PART_INCLUDING_DEOXYS(formSpecies) ((formSpecies) >> (FORM_FLAG_SHIFT - FORM_NUM_BITS))

#endif // GUARD_CONSTANTS_FORMS_H
