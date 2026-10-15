#ifndef POKERANGER2_FIELD_FIELDPARTNERINDEX_HPP
#define POKERANGER2_FIELD_FIELDPARTNERINDEX_HPP

#include <nitro.h>

extern u16 DAT_0208d58c;

extern "C" {
BOOL HasPartnerIndex(int kind);
int PartnerKindToIndex(int kind);
int PartnerIndexToKind(int index);
}

#endif // POKERANGER2_FIELD_FIELDPARTNERINDEX_HPP
