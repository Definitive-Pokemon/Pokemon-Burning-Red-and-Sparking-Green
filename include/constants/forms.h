
#ifndef GUARD_CONSTANTS_FORMS_H
#define GUARD_CONSTANTS_FORMS_H

#define FORM_FLAG_SHIFT 14
#define FIRST_FORM (0x1 << FORM_FLAG_SHIFT)
#define SECOND_FORM (0x2 << FORM_FLAG_SHIFT)
#define THIRD_FORM (0x3 << FORM_FLAG_SHIFT)
#define SPECIES_FOSSILIZED_KABUTOPS (FIRST_FORM + 141)
// add new forms here, make sure every form of a single species does not share a form number!

#define NUM_TOTAL_VARIANTS 1

#endif // GUARD_CONSTANTS_FORMS_H
