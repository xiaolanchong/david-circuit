/* trfft.f -- translated by f2c (version of 23 April 1993  18:34:30).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;

/* Subroutine */ int fand_(nx, np, nhar, f1, f2, iou, irec)
integer *nx, *np, *nhar;
doublereal *f1, *f2;
integer *iou, *irec;
{
    /* Format strings */
    static char fmt_100[] = "(///18x,\002 анализ фурье \002,i2,\002. выходна\
я величина\002)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    alist al__1;

    /* Builtin functions */
    integer f_rew(), s_rsue(), do_uio(), e_rsue(), s_wsfe(), do_fio(), e_wsfe(
	    );

    /* Local variables */
    static doublereal dist;
    static integer i, j, l;
    extern /* Subroutine */ int fourd_();
    static integer ii;
    extern /* Subroutine */ int plotfd_();
    static doublereal buf1[10], buf2[10];

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 0, 0, 0, 0 };
    static cilist io___7 = { 0, 0, 0, 0, 0 };
    static cilist io___9 = { 0, 0, 0, fmt_100, 0 };


/*     *************** */

/*     2.10.1981 */
    /* Parameter adjustments */
    --f2;
    --f1;

    /* Function Body */
    i__1 = *nx;
    for (ii = 1; ii <= i__1; ++ii) {
	i = ii;
	al__1.aerr = 0;
	al__1.aunit = *irec;
	f_rew(&al__1);
/* NACTENI VYSTUPNICH BODU */
	i__2 = *np;
	for (j = 1; j <= i__2; ++j) {
	    io___4.ciunit = *irec;
	    s_rsue(&io___4);
	    i__3 = *nx;
	    for (l = 1; l <= i__3; ++l) {
		do_uio(&c__1, (char *)&buf1[l - 1], (ftnlen)sizeof(doublereal)
			);
	    }
	    e_rsue();
	    io___7.ciunit = *irec;
	    s_rsue(&io___7);
	    i__3 = *nx;
	    for (l = 1; l <= i__3; ++l) {
		do_uio(&c__1, (char *)&buf2[l - 1], (ftnlen)sizeof(doublereal)
			);
	    }
	    e_rsue();
	    f1[j] = buf1[i - 1];
	    f2[j] = buf2[i - 1];
/* L20: */
	}
	io___9.ciunit = *iou;
	s_wsfe(&io___9);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	e_wsfe();
	fourd_(&f1[1], &f2[1], np, &dist);
/* GRAFICKE ZNAZORNENI */
	i__2 = *nhar + 1;
	plotfd_(&f1[1], &f2[1], &i__2, &dist, iou);
/* L30: */
    }
    return 0;
} /* fand_ */

/* Subroutine */ int fourd_(xreal, ximag, m, dist)
doublereal *xreal, *ximag;
integer *m;
doublereal *dist;
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double log(), sqrt();

    /* Local variables */
    extern /* Subroutine */ int fftd_();
    static integer i, k;
    extern /* Subroutine */ int ampfd_(), amphd_();
    static integer m2, mu;
    static doublereal ydb, ydg, yam, yph, sum;

/*     **************** */
/* VYPOCET SLOZEK FOURIEROVY TRANSFORMACE A ZKRESLENI */
/*     6.10.1981 */
    /* Parameter adjustments */
    --ximag;
    --xreal;

    /* Function Body */
    mu = (integer) (log((real) (*m)) / (float).6931472 + (float).5);
    fftd_(&xreal[1], &ximag[1], m, &mu);
/* VYPOCET MODULU SLOZEK */
    ampfd_(&xreal[1], &ximag[1], m);
/* VYPOCET AMPLITUDY A FAZE */
    m2 = *m / 2;
    xreal[1] = xreal[1] / (real) (*m) / 2.;
    i__1 = m2;
    for (k = 2; k <= i__1; ++k) {
	amphd_(&xreal[k], &ximag[k], &yam, &yph, &ydb, &ydg);
	xreal[k] = yam / (doublereal) (*m);
/* L10: */
	ximag[k] = ydg;
    }
/* VYPOCET ZKRESLENI */
    sum = 0.;
    i__1 = m2;
    for (i = 3; i <= i__1; ++i) {
/* L20: */
	sum += xreal[i] * xreal[i];
    }
    *dist = sqrt(sum / (sum + xreal[2] * xreal[2])) * 100.;
    return 0;
} /* fourd_ */

/* Subroutine */ int plotfd_(har, phase, m, dist, iout)
doublereal *har, *phase;
integer *m;
doublereal *dist;
integer *iout;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_34 = { {'X', ' ', ' ', ' '}, 0 };

#define ix (*(integer *)&equiv_34)


    /* Format strings */
    static char fmt_100[] = "(/\002 шаг\002,3x,\002амплитуда   эфф.знач.   ф\
аза\002/23x,\002величина\002)";
    static char fmt_110[] = "(i5,1pd14.4,e12.4,0pf8.2,2x,100a1)";
    static char fmt_120[] = "(/8x,\002CINITEL ZKRESLENI  = \002,f9.2,\002 \
%\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
    static doublereal harr, xmax;
    static integer i, j, i1, ij;
    static doublereal sq, xp;

    /* Fortran I/O blocks */
    static cilist io___25 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___26 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___30 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___32 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___33 = { 0, 0, 0, fmt_120, 0 };


/*     ***************** */
/* GRAFICKE ZNAZORNENI SLOZEK FT */
/*     2.10.1981 */
    /* Parameter adjustments */
    --phase;
    --har;

    /* Function Body */
    sq = 1.414213562373;
    xp = 50.;
/* URCENI VZTAZNE HODNOTY */
    xmax = 0.;
    i__1 = *m;
    for (i = 2; i <= i__1; ++i) {
	if (xmax < har[i]) {
	    xmax = har[i];
	}
/* L10: */
    }
    i = 0;
    io___25.ciunit = *iout;
    s_wsfe(&io___25);
    e_wsfe();
    io___26.ciunit = *iout;
    s_wsfe(&io___26);
    do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&har[1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    i__1 = *m;
    for (i = 2; i <= i__1; ++i) {
	ij = (integer) (har[i] / xmax * xp);
	i1 = i - 1;
	harr = har[i] / sq;
	if (ij > 0) {
	    io___30.ciunit = *iout;
	    s_wsfe(&io___30);
	    do_fio(&c__1, (char *)&i1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&har[i], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&harr, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&phase[i], (ftnlen)sizeof(doublereal));
	    i__2 = ij;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	    }
	    e_wsfe();
	}
	if (ij <= 0) {
	    io___32.ciunit = *iout;
	    s_wsfe(&io___32);
	    do_fio(&c__1, (char *)&i1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&har[i], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&harr, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&phase[i], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
/* L50: */
    }
    io___33.ciunit = *iout;
    s_wsfe(&io___33);
    do_fio(&c__1, (char *)&(*dist), (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;
} /* plotfd_ */

#undef ix


/* Subroutine */ int fftd_(xreal, ximag, n, nu)
doublereal *xreal, *ximag;
integer *n, *nu;
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer pow_ii();
    double cos(), sin();

    /* Local variables */
    static doublereal c;
    static integer i, k, l;
    static doublereal p, s, timag, treal;
    extern integer ibitr_();
    static integer k1, n2, nu1;
    static doublereal arg;
    static integer k1n2;

/*     *************** */

/*     2.10.1981 */
    /* Parameter adjustments */
    --ximag;
    --xreal;

    /* Function Body */
    n2 = *n / 2;
    nu1 = *nu - 1;
    k = 0;
    i__1 = *nu;
    for (l = 1; l <= i__1; ++l) {
L102:
	i__2 = n2;
	for (i = 1; i <= i__2; ++i) {
	    i__3 = k / pow_ii(&c__2, &nu1);
	    p = (doublereal) ibitr_(&i__3, nu);
	    arg = p * 6.28318530718 / (doublereal) (*n);
	    c = cos(arg);
	    s = sin(arg);
	    k1 = k + 1;
	    k1n2 = k1 + n2;
	    treal = xreal[k1n2] * c + ximag[k1n2] * s;
	    timag = ximag[k1n2] * c - xreal[k1n2] * s;
	    xreal[k1n2] = xreal[k1] - treal;
	    ximag[k1n2] = ximag[k1] - timag;
	    xreal[k1] += treal;
	    ximag[k1] += timag;
/* L101: */
	    ++k;
	}
	k += n2;
	if (k < *n) {
	    goto L102;
	}
	k = 0;
	--nu1;
/* L100: */
	n2 /= 2;
    }
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	i__2 = k - 1;
	i = ibitr_(&i__2, nu) + 1;
	if (i <= k) {
	    goto L103;
	}
	treal = xreal[k];
	timag = ximag[k];
	xreal[k] = xreal[i];
	ximag[k] = ximag[i];
	xreal[i] = treal;
	ximag[i] = timag;
L103:
	;
    }
    return 0;
} /* fftd_ */

integer ibitr_(j, nu)
integer *j, *nu;
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer i, j1, j2;

/*     ************** */
    j1 = *j;
    ret_val = 0;
    i__1 = *nu;
    for (i = 1; i <= i__1; ++i) {
	j2 = j1 / 2;
	ret_val = (ret_val << 1) + (j1 - (j2 << 1));
/* L200: */
	j1 = j2;
    }
    return ret_val;
} /* ibitr_ */

/* Subroutine */ int amphd_(yr, yi, yam, yph, ydb, ydg)
doublereal *yr, *yi, *yam, *yph, *ydb, *ydg;
{
    /* Builtin functions */
    double sqrt(), d_lg10(), atan();

    /* Local variables */
    static real pioto5;
    static doublereal pi, pi2, eps;

/*     **************** */
/* вычисл модуля и амплитуды комплекс. */
/*     28.9.1981 */
    pi = 3.1415926535;
    eps = 1e-20;
    pi2 = pi / (float)2.;
/* VYPOCET AMPLITUDY */
    *yam = sqrt(*yr * *yr + *yi * *yi);
    *ydb = -300.;
    if (*yam != 0.) {
	*ydb = d_lg10(yam) * 20.;
    }
/* VYPOCET FAZE */
    if (abs(*yr) < eps || abs(*yi) < eps) {
	goto L1;
    }
/* VELKE PRVKY */
    *yph = atan(*yi / *yr);
    if (*yr < 0.) {
	goto L2;
    }
    goto L5;
L2:
    if (*yi > 0.) {
	*yph += pi;
    }
    if (*yi < 0.) {
	*yph -= pioto5;
    }
/* MALE PRVKY */
L1:
    if (abs(*yi) < eps && abs(*yr) < eps) {
	goto L3;
    }
    if (abs(*yi) < eps) {
	goto L4;
    }
    if (*yi > 0.) {
	*yph = pi2;
    }
    if (*yi < 0.) {
	*yph = -pi2;
    }
    goto L5;
L3:
    *yph = 0.;
    goto L5;
L4:
    if (*yr > 0.) {
	*yph = 0.;
    }
    if (*yr < 0.) {
	*yph = pi;
    }
L5:
    *ydg = *yph * 57.295779513;
    return 0;
} /* amphd_ */

/* Subroutine */ int ampfd_(xreal, ximag, n)
doublereal *xreal, *ximag;
integer *n;
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double cos(), sin();

    /* Local variables */
    static doublereal pink;
    static integer k, l;
    static doublereal xikml, xilmk, xikpl, xrkml, xrlmk, xrkpl;
    static integer n2;
    static doublereal ck;
    static integer n21;
    static doublereal sk, pin, xik, xil, xrk, xrl;

/*     **************** */
/* VYPOCET 2N BODOVE TRANSFORMACE */
/*     6.10.1981 */
    /* Parameter adjustments */
    --ximag;
    --xreal;

    /* Function Body */
    n2 = *n / 2;
    pin = 3.14159265359 / (doublereal) (*n);
    xreal[1] += ximag[1];
    ximag[1] = 0.;
    i__1 = n2;
    for (k = 2; k <= i__1; ++k) {
	l = *n - k + 2;
	xrk = xreal[k] / 2.;
	xrl = xreal[l] / 2.;
	xik = ximag[k] / 2.;
	xil = ximag[l] / 2.;
	xrkpl = xrk + xrl;
	xrkml = xrk - xrl;
	xrlmk = xrl - xrk;
	xikpl = xik + xil;
	xikml = xik - xil;
	xilmk = xil - xik;
	pink = pin * ((real) k - 1.);
	ck = cos(pink);
	sk = sin(pink);
	xreal[k] = xrkpl + ck * xikpl - sk * xrkml;
	xreal[l] = xrkpl - ck * xikpl - sk * xrlmk;
	ximag[k] = xikml - sk * xikpl - ck * xrkml;
	ximag[l] = xilmk - sk * xikpl + ck * xrlmk;
/* L300: */
    }
    n21 = n2 + 1;
    ximag[n21] = -ximag[n21];
    return 0;
} /* ampfd_ */

