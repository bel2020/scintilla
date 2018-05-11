// Scintilla source code edit control
/** @file CharacterSet.cxx
 ** Simple case functions for ASCII.
 ** Lexer infrastructure.
 **/
// Copyright 1998-2010 by Neil Hodgson <neilh@scintilla.org>
// The License.txt file describes the conditions under which this software may be distributed.
#include <string.h>
#include <cstdlib>
#include <cassert>

#include "CharacterSet.h"

using namespace Scintilla;

namespace Scintilla {

int CompareCaseInsensitive(const char *a, const char *b) {
#if 1 // x-studio365 spec:
    return _stricmp(a, b);
#else
	while (*a && *b) {
		if (*a != *b) {
			const char upperA = MakeUpperCase(*a);
			const char upperB = MakeUpperCase(*b);
			if (upperA != upperB)
				return upperA - upperB;
		}
		a++;
		b++;
	}
	// Either *a or *b is nul
	return *a - *b;
#endif
}

int CompareNCaseInsensitive(const char *a, const char *b, size_t len) {
#if 1 // x-studio365 spec: the system standard api is work fine, post a pull request
    return _strnicmp(a, b, len);
#else
	while (*a && *b && len) {
		if (*a != *b) {
			const char upperA = MakeUpperCase(*a);
			const char upperB = MakeUpperCase(*b);
			if (upperA != upperB)
				return upperA - upperB;
		}
		a++;
		b++;
		len--;
	}
	if (len == 0)
		return 0;
	else
		// Either *a or *b is nul
		return *a - *b;
#endif
}

}
