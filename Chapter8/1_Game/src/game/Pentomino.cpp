/*
 * Copyright (C) 2013 Sergey Kosarevsky (sk@linderdaum.com)
 * Copyright (C) 2013 Viktor Latypov (vl@linderdaum.com)
 * Based on Linderdaum Engine http://www.linderdaum.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must display the names 'Sergey Kosarevsky' and
 *    'Viktor Latypov'in the credits of the application, if such credits exist.
 *    The authors of this work must be notified via email (sk@linderdaum.com) in
 *    this case of redistribution.
 *
 * 3. Neither the name of copyright holders nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "Pentomino.h"

/**
   1: Dot
   2: I2
   3: I3, L2
   4: Square, I4, L, L-mirrored, N, N-mirrored
   5: F, P, P-mirrored, S, T, U, V, W, X, Y, Z
**/

char Shapes [ NUM_SHAPES ][ ROTATIONS ][ SHAPES_X ][ SHAPES_Y ] =
{
	// W
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 3, 2, 0},
			{0, 5, 4, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 5, 0, 0, 0},
			{0, 4, 3, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 4, 5, 0},
			{0, 2, 3, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 3, 4, 0},
			{0, 0, 0, 5, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// L2
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 3, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 2, 0},
			{0, 0, 0, 3, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 3, 2, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// S
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{5, 4, 3, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 5, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 3, 2, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 3, 4, 5},
			{0, 1, 2, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 2, 3, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 5, 0, 0}
		}
	},

	// Y
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 5, 0, 0},
			{1, 2, 3, 4, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 3, 5, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 4, 3, 2, 1},
			{0, 0, 5, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 5, 3, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0}
		}
	},

	// F
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 5, 0, 0},
			{0, 4, 3, 2, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 3, 5, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 2, 3, 4, 0},
			{0, 0, 5, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 5, 3, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// U
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 0, 5, 0},
			{0, 2, 3, 4, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 4, 5, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 4, 3, 2, 0},
			{0, 5, 0, 1, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 5, 4, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 1, 2, 0, 0}
		}
	},

	// Dot
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// Square
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 1, 2, 0},
			{0, 0, 4, 3, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 4, 1, 0},
			{0, 0, 3, 2, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 3, 4, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 3, 0},
			{0, 0, 1, 4, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// P
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 3, 4, 0},
			{0, 0, 2, 5, 0},
			{0, 0, 1, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 3, 0},
			{0, 0, 5, 4, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 5, 2, 0},
			{0, 0, 4, 3, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 4, 5, 0},
			{0, 0, 3, 2, 1},
			{0, 0, 0, 0, 0}
		}
	},

	// P mirrored
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 4, 3, 0},
			{0, 0, 5, 2, 0},
			{0, 0, 0, 1, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 5, 4, 0},
			{0, 1, 2, 3, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 5, 0},
			{0, 0, 3, 4, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 3, 2, 1},
			{0, 0, 4, 5, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// X
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 4, 2, 5, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 3, 2, 1, 0},
			{0, 0, 5, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 5, 2, 4, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 5, 0, 0},
			{0, 1, 2, 3, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// V
	{
		{
			{0, 0, 0, 0, 0},
			{0, 3, 4, 5, 0},
			{0, 2, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 1, 2, 3, 0},
			{0, 0, 0, 4, 0},
			{0, 0, 0, 5, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 2, 0},
			{0, 5, 4, 3, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 5, 0, 0, 0},
			{0, 4, 0, 0, 0},
			{0, 3, 2, 1, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// T
	{
		{
			{0, 0, 0, 0, 0},
			{0, 1, 2, 3, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 5, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 5, 4, 2, 0},
			{0, 0, 0, 3, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 5, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 3, 2, 1, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 3, 0, 0, 0},
			{0, 2, 4, 5, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// I4
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 3, 4},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 4, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{4, 3, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 4, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},

	// I3
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 3, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 3, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},
	// I2
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},
	// Z
	{
		{
			{0, 0, 0, 0, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 4, 5, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 4, 3, 2, 0},
			{0, 5, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 5, 4, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 5, 0},
			{0, 2, 3, 4, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},
	// L
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 2, 3, 4, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 4, 3, 2, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},
	// L mirrored
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 2, 3, 4, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 4, 3, 2, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 0, 0}
		}
	},
	// N
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 3, 2, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 4, 3, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 2, 3, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 0, 0, 0}
		},

		{
			{0, 0, 0, 0, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 3, 4, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},
	// N mirrored
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 3, 0},
			{0, 0, 0, 4, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 2, 1, 0},
			{0, 4, 3, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 4, 0, 0, 0},
			{0, 3, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 3, 4, 0},
			{0, 1, 2, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	},
	// T
	{
		{
			{0, 0, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 2, 4, 0},
			{0, 0, 3, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 3, 2, 1, 0},
			{0, 0, 4, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 3, 0, 0},
			{0, 4, 2, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0},
			{0, 0, 4, 0, 0},
			{0, 1, 2, 3, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0}
		}
	}
};
