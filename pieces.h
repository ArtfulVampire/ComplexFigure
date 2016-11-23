#ifndef PIECES_H
#define PIECES_H

#include <vector>
#include <QVector>
#include <QPoint>

namespace fig
{
const double degToRad = M_PI / 180.;
const double size = 240. / 2;
const double pieceSize = 220. / 2;

const double a = 1.; /// ~halfSize
const double b = 1.35; /// rectangle coef
const double c = 1.4; /// rhomb sizeX
const double d = 0.8; /// trapeze upper
const double e = 1.4; /// trapeze lower
const double i = -a + d / (d+e) * 2 * a; /// trapeze diags cross
const double alpha = 65 * degToRad; /// paral angle
const double f = a / tan(alpha); /// paral 1/4 base
const double g1 = a * 2 / (1. + cos(36. * degToRad)); /// penta radius
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
        {-a, a},
        {-a, -a},
        {a, a}
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

/// figure type, variant, piece num, piece point, x/y
const std::vector<std::vector<std::vector<QVector<QPointF>>>> pieces =
{
    /// square
    {

        {
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
        {
            {
                {0, 0},
                {-a, a},
                {-a, 0}
            },
            {
                {0, 0},
                {-a, 0},
                {-a, -a},
                {0, -a}
            },
            {
                {0, 0},
                {0, -a},
                {a, -a}
            },
            {
                {a, -a},
                {a, a},
                {-a, a}
            }
		},
		{
			{
				{0, 0},
				{0, a},
				{-a, a}
			},
			{
				{0, 0},
				{-a, a},
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
		}
    },
    /// rect
	{
        {
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
        {
            {
                {0, 0},
                {-a, b},
                {-a, 0}
            },
            {
                {0, 0},
                {-a, 0},
                {-a, -b},
                {0, -b}
            },
            {
                {0, 0},
                {0, -b},
                {a, -b}
            },
            {
                {a, -b},
                {a, b},
                {-a, b}
            }
		},
		{
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
		}
    },
    /// tri
    {
		{
			{
				{0, 0},
				{-a/2, a/2},
				{a/2, a/2}
			},
			{
				{-a/2, a/2},
				{a/2, a/2},
				{a, a},
				{-a, a}
			},
			{
				{-a, -a},
				{-a, 0},
				{0, 0}
			},
			{
				{0, 0},
				{-a, a},
				{-a, 0}
			}
		}
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
        {
            {
                {-c, 0},
                {-c/2, -a/2},
                {0, 0},
                {-c/2, a/2}
            },
            {
                {0, 0},
                {-c/2, -a/2},
                {0, -a},
                {c/2, -a/2}
            },
            {
                {0, 0},
                {c/2, -a/2},
                {c, 0},
                {c/2, a/2}
            },
            {
                {0, 0},
                {c/2, a/2},
                {0, a},
                {-c/2, a/2}
            }
        },
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
                {-d, -a},
                {0, -a},
                {0, a},
                {-d, a}
            },
            {
                {0, a},
                {0, -a},
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
		}
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
		}
    },
	/// penta
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
		}

    }
};
} /// end namespace fig

#endif // PIECES_H
