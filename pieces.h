#ifndef PIECES_H
#define PIECES_H

#include <vector>
#include <QVector>
#include <QPoint>

const double degToRad = M_PI / 180.;

const double a = 1.; /// ~halfSize
const double b = 1.35; /// rectangle coef
const double c = 1.4; /// rhomb sizeX
const double d = 1.4; /// trapeze upper
const double e = 1.4; /// trapeze lower
const double alpha = 65 * degToRad; /// paral angle
const double f = a / tan(alpha); /// paral 1/4 base
const double g = a * 2 / (1. + cos(36. * degToRad)); /// penta radius
const double h = a / cos(30. * degToRad); /// hexa side = radius

const std::vector<QVector<QPointF>> figures =
{
    /// square
    {
        {-a, -a},
        {a, -a},
        {a, a},
        {-a, a}
    },
    /// rect
    {
        {-b, -a},
        {b, -a},
        {b, a},
        {-b, a}
    },
    /// triange
    {
        {-a, a},
        {-a, -a},
        {a, a}
    },
    /// rhomb
    {
        {-c, 0},
        {0, -a},
        {c, 0},
        {0, a}
    },
    /// trapeze
    {
        {-d, -a},
        {d, -a},
        {e, a},
        {-e, a}
    },
    /// paral
    {
        {-f, a},
        {-3 * f, -a},
        {a / f, -a},
        {3 * f, a}
    },
    /// penta
    {
        {-g * sin(36 * degToRad), a},
        {-g * cos(18 * degToRad), a - g * cos(18 * degToRad)},
        {0, -a},
        {g * cos(18 * degToRad), a - g * cos(18 * degToRad)},
        {g * sin(36 * degToRad), a}
    },
    /// hexa
    {
        {-h/2, a},
        {-h, 0},
        {-h/2, -a},
        {h/2, a},
        {h, 0},
        {h/2, a}
    }
};


/// figure type, variant, piece num, x/y
const std::vector<std::vector<std::vector<std::vector<double>>>> pieces =
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
        /// 2 var
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
        /// 3 var
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
        /// 4 var
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
        }
    },
    /// rect
    {
        /// 1 var
        {
            {
                {-a, b},
                {-a, -b},
                {0, -b}
            },
            {
                {-a, b},
                {0, -b},
                {0, b}
            },
            {
                {0, b},
                {0, -b},
                {a, -b}
            },
            {
                {0, b},
                {a, -b},
                {a, b}
            }
        },
        /// 2 var
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
        /// 3 var
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
        }
    },
    /// tri
    {
        /// 1 var
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
        },
        /// 2 var
        {
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
                {0, a},
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
    }
    /// trapeze
    /// paral
    /// penta
    /// hexa
};

#endif // PIECES_H
