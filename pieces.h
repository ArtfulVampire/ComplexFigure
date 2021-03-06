#ifndef PIECES_H
#define PIECES_H

#include <vector>
#include <QVector>
#include <QPoint>

namespace fig
{
const double degToRad = M_PI / 180.;
const double size = 220. / 2;
const double pieceSize = 220. / 2;

const double a = 1.; /// ~halfSize
const double b = 1.4; /// rectangle width coef
const double c = 1.55; /// rhomb diagonals ratio
const double t = a * sqrt(2); /// triangle base

const double d = 0.8; /// trapeze upper
const double e = 1.4; /// trapeze lower
const double i = -a + d / (d + e) * 2 * a; /// trapeze diags cross

const double alpha = 65 * degToRad; /// paral angle
const double f = a / tan(alpha); /// paral 1/4 base

const double g1 = a * 2 / (1. + cos(36. * degToRad)); /// penta "radius"
const double g2 = g1 * cos(54. * degToRad); /// penta half side
const double g3 = g1 * cos(18 * degToRad); /// penta left x
const double g4 = a - 2 * g2 * cos(18 * degToRad); /// penta left y

const double h = a / cos(30. * degToRad) / 2.; /// hexa half side = half radius

const std::vector<QVector<QPointF>> figures =
{
    /// square - 0
    {
        {-a, -a},
        {a, -a},
        {a, a},
        {-a, a}
    },
    /// rect - 1
    {
        {-b, -a},
        {b, -a},
        {b, a},
        {-b, a}
    },
    /// triange -2
    {
		{0, -a},
		{-2*a, a},
		{2*a, a}
    },
    /// rhomb - 3
    {
        {-c, 0},
        {0, -a},
        {c, 0},
        {0, a}
    },
    /// trapeze - 4
    {
        {-d, -a},
        {d, -a},
        {e, a},
        {-e, a}
    },
    /// paral - 5
    {
        {-f, a},
        {-3 * f, -a},
        {f, -a},
        {3 * f, a}
    },
    /// penta - 6
    {
        {-g2, a},
        {-g3, g4},
        {0, -a},
        {g3, g4},
        {g2, a}
    },
    /// hexa - 7
    {
        {-h, a},
        {-2 * h, 0},
        {-h, -a},
        {h, -a},
        {2 * h, 0},
        {h, a}
	},
	/// empty figure - 8
	{
		{0, 0},
		{0, 0.001},
		{0.001, 0}
	}
};




/// figure type, variant, piece num, piece point, x/y
const std::vector<std::vector<std::vector<QVector<QPointF>>>> pieces =
{
    /// square
    {

		{
			/// very simple
			{
				{-a, a},
				{-a, -a},
				{0, a}
			},
			{
				{0, a},
				{-a, -a},
				{0, -a}
			},
			{
				{0, 0},
				{0, -a},
				{a, -a},
				{a, 0}
			},
			{
				{0, 0},
				{a, 0},
				{a, a},
				{0, a}
			}
		},
//		{
//			/// very simple
//			{
//				{0, 0},
//				{-a, a},
//				{-a, 0}
//			},
//			{
//				{0, 0},
//				{-a, 0},
//				{-a, -a},
//				{0, -a}
//			},
//			{
//				{0, 0},
//				{0, -a},
//				{a, -a}
//			},
//			{
//				{a, -a},
//				{a, a},
//				{-a, a}
//			}
//		},

//		{
//			/// very simple
//			{
//				{0, 0},
//				{0, a},
//				{-a, a}
//			},
//			{
//				{0, 0},
//				{-a, a},
//				{-a, -a},
//				{0, -a}
//			},
//			{
//				{0, 0},
//				{0, -a},
//				{a, -a},
//				{a, 0}
//			},
//			{
//				{0, 0},
//				{a, 0},
//				{a, a},
//				{0, a}
//			}
//		},

		{
			/// very hard
			{
				{-a, -a},
				{-a, a},
				{0, -a}
			},
			{
				{0, 0},
				{0, -a},
				{-a, a}
			},
			{
				{0, 0},
				{-a, a},
				{a, a}
			},
			{
				{0, 0},
				{a, a},
				{a, -a},
				{0, -a}
			}
		},
		{
			/// quite hard
			{
				{-a, -a},
				{a, -a},
				{0, 0}
			},
			{
				{0, 0},
				{-a, -a},
				{-a, a}
			},
			{
				{a, -a},
				{-a, a},
				{0, a}
			},
			{
				{0, a},
				{a, a},
				{a, -a}
			}
		},
		{
			{
				{-a, -a},
				{-a, a},
				{0, a}
			},
			{
				{-a, -a},
				{a, -a},
				{a/2, 0},
				{-a/2, 0}
			},
			{
				{a/2, 0},
				{-a/2, 0},
				{0, a}
			},
			{
				{0, a},
				{a, a},
				{a, -a}
			}
		},
		{
			/// very hard
			{
				{-a, -a},
				{0, -a},
				{-a, a}
			},
			{
				{-a, a},
				{0, -a},
				{a, -a}
			},
			{
				{a, -a},
				{-a, a},
				{0, a}
			},
			{
				{0, a},
				{a, a},
				{a, -a}
			}
		},
		{
			{
				{-a, a / 2.},
				{-a, -a},
				{0, -a}
			},
			{
				{-a, a / 2.},
				{a, a / 2.},
				{0, -a}
			},
			{
				{-a, a / 2.},
				{a, a / 2.},
				{a, a},
				{-a, a}
			},
			{
				{a, a / 2.},
				{a, -a},
				{0, -a}
			}
		},
		{
			/// same in rectangle
			{
				{-a, -a},
				{a, -a},
				{0, 0}
			},
			{
				{a, -a},
				{a, a},
				{0, a},
				{0, 0}
			},
			{
				{0, a},
				{0, 0},
				{-a, 0},
				{-a, a}
			},
			{
				{-a, -a},
				{0, 0},
				{-a, 0}
			}
		},
		{
			{
				{-a, -a},
				{a, -a},
				{0, 0}
			},
			{
				{0, 0},
				{-a, a},
				{-a, -a}
			},
			{
				{-a, a},
				{a, -a},
				{a, 0},
				{0, a}
			},
			{
				{0, a},
				{a, 0},
				{a, a}
			}
		}

    },
    /// rect
	{
        {
			/// quite simple
            {
                {0, 0},
                {-a, b},
                {-a, -b}
            },
            {
                {0, 0},
                {-a, -b},
                {a, -b}
            },
            {
                {0, 0},
                {a,-b},
                {a, b}
            },
            {
                {0, 0},
                {a, b},
                {-a, b}
            }
		},
//		{
//			/// quite simple
//			{
//				{0, 0},
//				{-a, b},
//				{-a, 0}
//			},
//			{
//				{0, 0},
//				{-a, 0},
//				{-a, -b},
//				{0, -b}
//			},
//			{
//				{0, 0},
//				{0, -b},
//				{a, -b}
//			},
//			{
//				{a, -b},
//				{a, b},
//				{-a, b}
//			}
//		},
		{
			/// same in square
			{
				{0, 0},
				{-a, -b},
				{a, -b}
			},
			{
				{0, 0},
				{a, -b},
				{a, 0}
			},
			{
				{0, 0},
				{a, 0},
				{a, b},
				{0, b}
			},
			{
				{0, 0},
				{0, b},
				{-a, b},
				{-a, -b}
			}
		},
		{
			/// quite hard
			{
				{0, 0},
				{-a, -b},
				{a, -b}
			},
			{
				{0, 0},
				{a, -b},
				{a, b},
				{0, b}
			},
			{
				{0, 0},
				{0, b},
				{-a, 0},
				{-a, -b}
			},
			{
				{0, b},
				{-a, b},
				{-a, 0}
			}
		},
		{
			/// quite simple
			{
				{-b, -a},
				{0, -a},
				{-b, a}
			},
			{
				{0, -a},
				{-b, a},
				{0, a}
			},
			{
				{0, 0},
				{0, -a},
				{b, -a},
				{b, 0}
			},
			{
				{0, 0},
				{b, 0},
				{b, a},
				{0, a}
			}
		},
		{
			/// quite simple
			{
				{-b, -a},
				{0, -a},
				{0, a},
				{-b, 0}
			},
			{
				{-b, a},
				{-b, 0},
				{0, a}
			},
			{
				{0, -a},
				{b, -a},
				{b, 0},
				{0, a}
			},
			{
				{0, a},
				{b, 0},
				{b, a}
			}
		},
		{
			/// rotated
			/// quite simple
			{
				{-b, -a},
				{b, -a},
				{0, 0}
			},
			{
				{b, -a},
				{0, 0},
				{b, 0}
			},
			{
				{0, 0},
				{b, 0},
				{b, a},
				{0, a}
			},
			{
				{-b, -a},
				{0, 0},
				{0, a},
				{-b, a}
			}
		}
    },
    /// tri
    {
		{
			{
				{0, 0},
				{-t/2, t/2},
				{t/2, t/2}
			},
			{
				{-t/2, t/2},
				{t/2, t/2},
				{t, t},
				{-t, t}
			},
			{
				{-t, -t},
				{-t, 0},
				{0, 0}
			},
			{
				{0, 0},
				{-t, t},
				{-t, 0}
			}
		},
		{
			/// square conflict
			{
				{-t, t},
				{0, 0},
				{t/2, t/2},
				{0, t}
			},
			{
				{t/2, t/2},
				{t, t},
				{0, t}
			},
			{
				{-t, t},
				{0, 0},
				{-t/2, -t/2},
				{-t, 0}
			},
			{
				{-t, 0},
				{-t/2, -t/2},
				{-t, -t}
			}
		},
		{
			/// quite hard
			{
				{-t, t},
				{t/3, t},
				{t/3, t/3.},
				{-t, t/3.}
			},
			{
				{t/3, t},
				{t/3, t/3},
				{t, t}
			},
			{
				{t/3, t/3},
				{-t, t/3},
				{-t/3, -t/3}
			},
			{
				{-t, t/3},
				{-t/3, -t/3},
				{-t, -t}
			}
		},
//		{
//			/// quite simple, rectangle conflict
//			{
//				{0, -a},
//				{-2 * a, a},
//				{-a, a},
//				{a / 2., -a / 2}
//			},
//			{
//				{a / 2., -a / 2.},
//				{-a, a},
//				{0, a},
//				{a, 0}
//			},
//			{
//				{a, 0},
//				{0, a},
//				{a, a},
//				{3 * a / 2., a / 2.}
//			},
//			{
//				{3 * a / 2., a / 2.},
//				{a, a},
//				{2 * a, a}
//			}
//		},
		{

			{
				{0, -a},
				{-2 * a, a},
				{-a, a},
				{a / 2., -a / 2}
			},
			{
				{a / 2., -a / 2.},
				{-a, a},
				{0, a},
				{a, 0}
			},
			{
				{a, 0},
				{0, a},
				{a, a}
			},
			{
				{a, 0},
				{a, a},
				{2 * a, a}
			}
		},
		{
			/// could be hard
			{
				{0, -a},
				{2 * a, a},
				{a, a},
				{-a / 2., -a / 2}
			},
			{
				{-a / 2., -a / 2.},
				{a, a},
				{-a, a},
				{-a, 0}
			},
			{
				{-a, 0},
				{-a, a},
				{-3 * a / 2, a / 2.}
			},
			{
				{-3 * a / 2., a / 2.},
				{-a, a},
				{-2 * a, a}
			}
		},
		{
			/// simple
			{
				{0, -a},
				{-a, 0},
				{a, 0}
			},
			{
				{-2 * a, a},
				{-a, a},
				{-a, 0}
			},
			{
				{-a, 0},
				{a, 0},
				{a, a},
				{-a, a}
			},
			{
				{a, 0},
				{a, a},
				{2 * a, a}
			}
		},
//		{
//			/// long pieces
//			{
//				{0, -a},
//				{-a / 2., -a / 2.},
//				{a / 2., -a / 2.}
//			},
//			{
//				{-a / 2., -a / 2.},
//				{a / 2., -a / 2.},
//				{a, 0},
//				{-a, 0}
//			},
//			{
//				{-a, 0},
//				{a, 0},
//				{3 * a / 2., a / 2.},
//				{-3 * a / 2., a / 2.}
//			},
//			{
//				{-3 * a / 2., a / 2.},
//				{3 * a / 2., a / 2.},
//				{2 * a, a},
//				{-2 * a, a}
//			}
//		},
		{
			/// long pieces
			{
				{0, -a},
				{-a, 0},
				{a, 0}
			},
			{
				{-a, 0},
				{a, 0},
				{3 * a / 2., a / 2.},
				{-3 * a / 2., a / 2.}
			},
			{
				{-3 * a / 2., a / 2.},
				{0, a / 2.},
				{0, a},
				{-2 * a, a}
			},
			{
				{0, a / 2.},
				{3 * a / 2., a / 2.},
				{2 * a, a},
				{0, a}
			}
		}
//		,
//		{
//			/// just not good
//			{
//				{0, -a},
//				{-a / 2., -a / 2.},
//				{a / 2., -a / 2.}
//			},
//			{
//				{-2 * a, a},
//				{-a, a},
//				{-a, 0}
//			},
//			{
//				{2 * a, a},
//				{a, a},
//				{a, 0}
//			},
//			{
//				{-a, a},
//				{-a, 0},
//				{-a / 2., -a / 2.},
//				{a / 2., -a / 2.},
//				{a, 0},
//				{a, a}
//			}
//		}
    },
    /// rhomb
    {
        /// 1 var
        {
            {
                {0, 0},
                {-c, 0},
                {0, -a}
            },
            {
                {0, 0},
                {0, -a},
                {c, 0}
            },
            {
                {0, 0},
                {c, 0},
                {0, a}
            },
            {
                {0, 0},
                {0, a},
                {-c, 0}
            }
        },
//		{
//			{
//				{-c, 0},
//				{-c/2, -a/2},
//				{0, 0},
//				{-c/2, a/2}
//			},
//			{
//				{0, 0},
//				{-c/2, -a/2},
//				{0, -a},
//				{c/2, -a/2}
//			},
//			{
//				{0, 0},
//				{c/2, -a/2},
//				{c, 0},
//				{c/2, a/2}
//			},
//			{
//				{0, 0},
//				{c/2, a/2},
//				{0, a},
//				{-c/2, a/2}
//			}
//		},
        {
            {
                {-c, 0},
                {-c/2, -a/2},
                {-c/2, a/2}
            },
            {
                {-c/2, a/2},
                {-c/2, -a/2},
                {0, -a},
                {0, a}
            },
            {
                {0, a},
                {0, -a},
                {c/2, -a/2},
                {c/2, a/2}
            },
            {
                {c/2, a/2},
                {c/2, -a/2},
                {c, 0}
            }
        },
        {
            {
                {0, 0},
                {0, a},
                {-c, 0}
            },
            {
                {0, 0},
                {-c, 0},
                {0, -a}
            },
            {
                {0, a},
                {0, -a},
                {c/2, -a/2},
                {c/2, a/2}
            },
            {
                {c/2, a/2},
                {c/2, -a/2},
                {c, 0}
            }
		}
		,
		{
			/// too hard
			{
				{-c, 0},
				{0, -a},
				{c/2, -a/2}
			},
			{
				{c/2, -a/2},
				{c, 0},
				{-c, 0}
			},
			{
				{c, 0},
				{-c, 0},
				{-c/2, a/2}
			},
			{
				{-c/2, a/2},
				{0, a},
				{c, 0}
			}
		}
		,
		{
			{
				{-c, 0},
				{0, -a},
				{0, 0}
			},
			{
				{0, 0},
				{c, 0},
				{0, -a}
			},
			{
				{-c, 0},
				{-c/2, a/2},
				{c/2, a/2},
				{c, 0}
			},
			{
				{-c/2, a/2},
				{c/2, a/2},
				{0, a}
			}
		}
    },
    /// trapeze
    {
        {
            {
                {-e, a},
                {-d, -a},
                {-d, a}
            },
            {
                {-d, a},
                {-d, -a},
                {d, -a}
            },
            {
                {-d, a},
                {d, -a},
                {d, a}
            },
            {
                {e, a},
                {d, a},
                {d, -a}
            }
        },
        {
            {
                {-e, a},
                {-d, -a},
                {0, -a}
            },
            {
                {-e, a},
                {0, -a},
                {0, a}
            },
            {
                {0, a},
                {0, -a},
                {d, -a}
            },
            {
                {0, a},
                {d, -a},
                {e, a}
            }
		},
		{
			{
				{0, i},
				{-d, -a},
				{d, -a}
			},
			{
				{0, i},
				{d, -a},
				{e, a}
			},
			{
				{0, i},
				{e, a},
				{-e, a}
			},
			{
				{0, i},
				{-e, a},
				{-d, -a}
			}
		},
//		{
//			/// quite hard
//			{
//				{-e, a},
//				{-d, -a},
//				{-d, a}
//			},
//			{
//				{-d, a},
//				{-d, -a},
//				{d, a}
//			},
//			{
//				{d, a},
//				{-d, -a},
//				{e, a}
//			},
//			{
//				{e, a},
//				{-d, -a},
//				{d, -a}
//			}
//		},
		{
			{
				{-e, a},
				{-d, -a},
				{0, -a}
			},
			{
				{-e, a},
				{0, -a},
				{0, a}
			},
			{
				{0, a},
				{0, -a},
				{e, a}
			},
			{
				{e, a},
				{0, -a},
				{d, -a}
			}
		},
		{
			{
				{-e, a},
				{-d, -a},
				{0, a}
			},
			{
				{e, a},
				{0, a},
				{d, -a}
			},
			{
				{0, a},
				{-d/2, 0},
				{d/2, 0}
			},
			{
				{-d/2, 0},
				{d/2, 0},
				{d, -a},
				{-d, -a}
			}
		},
		{
			{
				{-d, -a},
				{0, -a},
				{0, 0},
				{-d/2-e/2, 0}
			},
			{
				{d, -a},
				{0, -a},
				{0, 0},
				{d/2+e/2, 0}
			},
			{
				{-e, a},
				{0, a},
				{0, 0},
				{-d/2-e/2, 0}
			},
			{
				{e, a},
				{0, a},
				{0, 0},
				{d/2+e/2, 0}
			}
		},
		{
			{
				{-d, -a},
				{-d, a},
				{-e, a}
			},
			{
				{-d, -a},
				{-d, 0},
				{(d + e) / 2., 0},
				{d, -a}
			},
			{
				{-d, 0},
				{0, 0},
				{0, a},
				{-d, a}
			},
			{
				{0, 0},
				{(d + e) / 2., 0},
				{e, a},
				{0, a},
			}
		},
		{
			{
				{d, -a},
				{d, a},
				{e, a}
			},
			{
				{d, 0},
				{0, 0},
				{0, -a},
				{d, -a}
			},
			{
				{0, -a},
				{0, 0},
				{-(d + e) / 2., 0},
				{-d, -a}
			},
			{
				{d, 0},
				{-(d + e) / 2., 0},
				{-e, a},
				{d, a},
			}
		},
		{
			{
				{-d, -a},
				{-d, a},
				{-e, a}
			},
			{
				{-d, -a},
				{0, -a},
				{0, a},
				{-d, a}
			},
			{
				{0, -a},
				{d, -a},
				{(d + e) / 2., 0},
				{0, 0}
			},
			{
				{(d + e) / 2., 0},
				{e, a},
				{0, a},
				{0, 0}
			}
		},
		{
			/// very hard
			{
				{-d, -a},
				{0, -a},
				{0, 0},
				{-e, a}
			},
			{
				{0, -a},
				{d, -a},
				{(d + e) / 2., 0},
				{0, 0}
			},
			{
				{0, 0},
				{(d + e) / 2., 0},
				{e, a}
			},
			{
				{0, 0},
				{e, a},
				{-e, a}
			}
		}
//		,
//		{
//			/// very hard
//			{
//				{-d, -a},
//				{d, -a},
//				{0, 0}
//			},
//			{
//				{d, -a},
//				{e, a},
//				{0, a},
//				{0, 0}
//			},
//			{
//				{-d, -a},
//				{0, 0},
//				{-(d + e) / 2., 0}
//			},
//			{
//				{-(d + e) / 2., 0},
//				{0, 0},
//				{0, a},
//				{-e, a}
//			}
//		}

    },
    /// paral
    {
        {
            {
                {-f, a},
                {-3 * f, -a},
                {0, 0}
            },
            {
                {-3 * f, -a},
                {f, -a},
                {0, 0}
            },
            {
                {f, -a},
                {3 * f, a},
                {0, 0}
            },
            {
                {3 * f, a},
                {-f, a},
                {0, 0}
            }
		},
        {
            {
                {-f, a},
                {-2 * f, 0},
                {0, 0}
            },
            {
                {-2 * f, 0},
                {-3 * f, -a},
                {f, -a},
                {0, 0}
            },
			{
				{f, -a},
				{3 * f, a},
				{0, 0}
			},
			{
				{3 * f, a},
				{-f, a},
				{0, 0}
			}
        },

        {
            {
                {-2 * f, 0},
                {- 3 * f, -a},
                {f, -a}
            },
            {
                {-2 * f, 0},
                {f, -a},
                {2 * f, 0}
            },
            {
                {-2 * f, 0},
                {2 * f, 0},
                {3 * f, a}
            },
            {
                {-2 * f, 0},
                {3 * f, a},
                {-f, a}
            }
		},
		{
			{
				{0, 0},
				{- 2 * f, 0},
				{-3 * f, -a},
				{-f, -a}
			},
			{
				{0, 0},
				{-f, -a},
				{f, -a},
				{2 * f, 0}
			},
			{
				{0, 0},
				{2 * f, 0},
				{3 * f, a},
				{f, a}
			},
			{
				{0, 0},
				{f, a},
				{-f, a},
				{-2 * f, 0}
			}
		},
		{
			{
				{-3 * f, -a},
				{f, -a},
				{-2 * f, 0}
			},
			{
				{f, -a},
				{-2 * f, 0},
				{2 * f, 0}
			},
			{
				{0, 0},
				{2 * f, 0},
				{3 * f, a},
				{f, a}
			},
			{
				{-2 * f, 0},
				{0, 0},
				{f, a},
				{-f, a}
			}
		},
		{
			{
				{-3 * f, -a},
				{f, -a},
				{3 * f / 2., -a / 2.},
				{-5 * f / 2., -a / 2.}
			},
			{
				{-5 * f / 2., -a / 2.},
				{3 * f / 2., -a / 2.},
				{2 * f, 0},
				{-2 * f, 0}
			},
			{
				{0, 0},
				{2 * f, 0},
				{3 * f, a},
				{f, a}
			},
			{
				{-2 * f, 0},
				{0, 0},
				{f, a},
				{-f, a}
			}
		}
    },
	/// penta - all hard
    {
        {
            {
				{0, -a},
				{0, a},
				{-g2, a}
            },
            {
				{-g2, a},
                {-g3, g4},
				{0, -a}
            },
			{
				{0, -a},
				{0, a},
				{g2, a}
			},
			{
				{g2, a},
				{g3, g4},
				{0, -a}
			}
		},
		{
			{
				{0, -a},
				{0, a},
				{-g3, g4}
			},
			{
				{0,a},
				{-g3, g4},
				{-g2, a}
			},
			{
				{0, a},
				{0, -a},
				{g3, g4}
			},
			{
				{0, a},
				{g3, g4},
				{g2, a}
			}
		},
		{
			{
				{0, -a},
				{0, a},
				{-g2, a}
			},
			{
				{-g2, a},
				{-g3, g4},
				{0, -a}
			},
			{
				{0, -a},
				{0, a},
				{g3, g4}
			},
			{
				{0, a},
				{g2, a},
				{g3, g4}
			}
		},
		{
			/// quite simple
			{
				{0, g4},
				{0, a},
				{-g2, a},
				{-g3, g4}
			},
			{
				{0, g4},
				{0, a},
				{g2, a},
				{g3, g4}
			},
			{
				{0, -a},
				{0, g4},
				{-g3, g4}
			},
			{
				{0, -a},
				{0, g4},
				{g3, g4}
			}
		},
		{
			/// quite simple
			{
				{0, -a},
				{-g2, a},
				{-g3, g4}
			},
			{
				{0, -a},
				{g2, a},
				{g3, g4}
			},
			{
				{0, -a},
				{-g2/2, 0},
				{g2/2, 0}
			},
			{
				{-g2/2, 0},
				{g2/2, 0},
				{g2, a},
				{-g2, a}
			}
		},
		{
			{
				{0, -a},
				{0, a},
				{-g3/2, -a/2+g4/2}
			},
			{
				{-g3/2, -a/2+g4/2},
				{0, a},
				{-g2, a},
				{-g3, g4}
			},
			{
				{0, -a},
				{0, a},
				{g3/2, -a/2+g4/2}
			},
			{
				{g3/2, -a/2+g4/2},
				{0, a},
				{g2, a},
				{g3, g4}
			}
		},
		{
			{
				{0, -a},
				{0, a},
				{-g3/2, -a/2+g4/2}
			},
			{
				{-g3/2, -a/2+g4/2},
				{0, a},
				{-g2, a},
				{-g3, g4}
			},
			{
				{0, -a},
				{0, a},
				{g3, g4}
			},
			{
				{0, a},
				{g2, a},
				{g3, g4}
			}
		},
		{
			/// quite simple
			{
				{0, -a},
				{g3, g4},
				{-g3, g4}
			},
			{
				{0, g4},
				{g3, g4},
				{(g3 + g2) / 2., (g4 + a) / 2.},
				{0, (g4 + a) / 2.}
			},
			{
				{0, g4},
				{-g3, g4},
				{-(g3 + g2) / 2., (g4 + a) / 2.},
				{0, (g4 + a) / 2.}
			},
			{
				{-(g3 + g2) / 2., (g4 + a) / 2.},
				{(g3 + g2) / 2., (g4 + a) / 2.},
				{g2, a},
				{-g2, a}
			}
		},
		{
			{
				{0, -a},
				{g3, g4},
				{-g3, g4}
			},
			{
				{0, g4},
				{g3, g4},
				{g2, a},
				{0, a}
			},
			{
				{0, g4},
				{-g3, g4},
				{-(g3 + g2) / 2., (g4 + a) / 2.},
				{0, (g4 + a) / 2.}
			},
			{
				{-(g3 + g2) / 2., (g4 + a) / 2.},
				{0, (g4 + a) / 2.},
				{0, a},
				{-g2, a}
			}
		}
    },
    /// hexa
    {
        {
            {
                {-h, a},
                {-2 * h, 0},
                {-h, -a}
            },
            {
                {-h, a},
                {-h, -a},
                {h, a}
            },
            {
                {-h, -a},
                {h, -a},
                {h, a}
            },
            {
                {h, a},
                {h, -a},
                {2 * h, 0}
            }
        },
        {
            {
                {-2 * h, 0},
                {-h, -a},
                {h, -a}
            },
            {
                {-2 * h, 0},
                {h, -a},
                {2 * h, 0}
            },
            {
                {-2 * h, 0},
                {2 * h, 0},
                {h, a}
            },
            {
                {-2 * h, 0},
                {h, a},
                {-h, a}
            }
        },
        {
			/// simple, rhomb conflict
            {
                {-2 * h, 0},
                {-h, -a},
                {h, -a}
            },
            {
                {-2 * h, 0},
                {h, -a},
                {h, a}
            },
            {
                {h, -a},
                {2 * h, 0},
                {h, a}
            },
            {
                {h, a},
                {-h, a},
                {-2 * h, 0}
            }
		},
		{
			{
				{0, -a},
				{0, 0},
				{-2 * h, 0},
				{-h, -a}
			},
			{
				{0, -a},
				{0, 0},
				{2 * h, 0},
				{h, -a}
			},
			{
				{0, a},
				{0, 0},
				{-2 * h, 0},
				{-h, a}
			},
			{
				{0, a},
				{0, 0},
				{2 * h, 0},
				{h, a}
			}
		},
		{
			{
				{-h, -a},
				{h, -a},
				{+3*h/2, -a/2},
				{-3*h/2, -a/2}
			},
			{
				{+3*h/2, -a/2},
				{-3*h/2, -a/2},
				{0, a}
			},
			{
				{-3*h/2, -a/2},
				{0, a},
				{-h, a},
				{-2*h, 0}
			},
			{
				{3*h/2, -a/2},
				{0, a},
				{h, a},
				{2*h, 0}
			}
		},
		{
			{
				{-h, -a},
				{0, -a},
				{0, 0},
				{-2 * h, 0}
			},
			{
				{0, 0},
				{0, a},
				{-h, a},
				{-2 * h, 0}
			},
			{
				{0, -a},
				{h, -a},
				{h, a},
				{0, a}
			},
			{
				{h, -a},
				{2 * h, 0},
				{h, a}
			}
		},
		{
			{
				{-h, -a},
				{0, -a},
				{0, 0},
				{-2 * h, 0}
			},
			{
				{0, -a},
				{h, -a},
				{2 * h, 0},
				{0, 0}
			},
			{
				{-2 * h, 0},
				{2 * h, 0},
				{3 * h / 2., a / 2.},
				{-3 * h / 2., a / 2.}
			},
			{
				{-3 * h / 2., a / 2.},
				{3 * h / 2., a / 2.},
				{h, a},
				{-h, a}
			}
		},
		{
			/// long pieces
			{
				{-2 * h, 0},
				{2 * h, 0},
				{3 * h / 2., -a / 2.},
				{-3 * h / 2., -a / 2.}
			},
			{
				{-3 * h / 2., -a / 2.},
				{3 * h / 2., -a / 2.},
				{h, -a},
				{-h, -a}
			},
			{
				{-2 * h, 0},
				{2 * h, 0},
				{3 * h / 2., a / 2.},
				{-3 * h / 2., a / 2.}
			},
			{
				{-3 * h / 2., a / 2.},
				{3 * h / 2., a / 2.},
				{h, a},
				{-h, a}
			}
		},
		{
			{
				{-3 * h / 2., -a / 2.},
				{3 * h / 2., -a / 2.},
				{h, -a},
				{-h, -a}
			},
			{
				{-3 * h / 2., -a / 2.},
				{0, -a / 2.},
				{0, a / 2.},
				{-3 * h / 2., a / 2.},
				{-2 * h, 0}
			},
			{
				{3 * h / 2., -a / 2.},
				{0, -a / 2.},
				{0, a / 2.},
				{3 * h / 2., a / 2.},
				{2 * h, 0}
			},
			{
				{-3 * h / 2., a / 2.},
				{3 * h / 2., a / 2.},
				{h, a},
				{-h, a}
			}
		}
	},
	/// empty
	{
		{
			{
				{0, 0},
				{0, 0.05},
				{0.001, 0}
			},
			{
				{0, 0},
				{0, 0.05},
				{0.001, 0}
			},
			{
				{0, 0},
				{0, 0.05},
				{0.001, 0}
			}
		}
	}
};


const std::vector<std::vector<std::vector<QVector<QPointF>>>> pieces3 =
{
	/// square
	{
		/// 1 var
		{
			{
				{-a, a},
				{-a, -a},
				{a, -a}
			},
			{
				{0, 0},
				{a, -a},
				{a, a}
			},
			{
				{0, 0},
				{a, a},
				{-a, a}
			}
		},
		{
			{
				{-a, a},
				{-a, 0},
				{0, 0},
				{0, a}
			},
			{
				{0, 0},
				{-a, 0},
				{-a, -a},
				{0, -a}
			},
			{
				{0, -a},
				{a, -a},
				{a, a},
				{0, a}
			}
		},
	},
	/// rect
	{
		{
			{
				{0, 0},
				{-a, -b},
				{a, -b},
				{a, 0}
			},
			{
				{0, 0},
				{-a, b},
				{a, b},
				{a, 0}
			},
			{
				{0, 0},
				{-a, -b},
				{-a, b}
			}
		}
	},
	/// triang
	{
		{
			{
				{0, 0},
				{0, a},
				{-a, a},
				{-a, 0}
			},
			{
				{0, 0},
				{-a, 0},
				{-a, -a}
			},
			{
				{0, 0},
				{a, a},
				{0, a}
			}
		},        {
			{
				{0, 0},
				{0, a},
				{-a, 0},
				{-a, -a}
			},
			{
				{0, a},
				{-a, a},
				{-a, 0}
			},
			{
				{0, 0},
				{a, a},
				{0, a}
			}
		},
	},
	/// rhomb
	{

	},
	/// trapeze
	{
		{
			{
				{-e, a},
				{-d, -a},
				{-d, a}
			},
			{
				{-d, a},
				{-d, -a},
				{d, -a}
			},
			{
				{-d, a},
				{d, -a},
				{e, a}
			}
		}
	},
	/// paral
	{
		{
			{
				{-f, a},
				{-3 * f, -a},
				{-f, -a}
			},
			{
				{-f, -a},
				{3 * f, a},
				{-f, a}
			},
			{
				{-f, -a},
				{f, -a},
				{3 * f, a}
			}
		}
	},
	/// penta
	{
		{
			{
				{-g2, a},
				{-g3, g4},
				{0, -a}
			},
			{
				{0, -a},
				{-g2, a},
				{g2, a}
			},
			{
				{g2, a},
				{g3, g4},
				{0, -a}
			}
		}
	},
	/// hexa
	{

	}
};

} /// end namespace fig

#endif // PIECES_H
