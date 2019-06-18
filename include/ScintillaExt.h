/// x-studio365 spec ScintillaExt.h header
#pragma once
#include "Platform.h"

#define SCLEX_SEARCHRESULT 150

#define SCN_VSCROLLCHANGE 2033
#define SCI_ALPHARECTANGLE 2810

struct SearchResultMarking {
    long _start;
    long _end;
};

struct SearchResultMarkings {
    long _length;
    SearchResultMarking *_markings;
};

namespace Scintilla {
    /** AlphaRectangle parameters
    *
    */
    struct AlphaRectangleParameters
    {
        int cornerSize;
        PRectangle rectangle;
        ColourDesired colorFill;
        int alphaFill;
        ColourDesired colorOutline;
        int alphaOutline;
    };
};
