/* plot.f -- translated by f2c (version of 23 April 1993  18:34:30).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static real c_b16 = (float)10.;
static integer c__1 = 1;
static integer c__30 = 30;
static integer c__2 = 2;
static integer c__0 = 0;
static integer c__65 = 65;

/* Subroutine */ int plot_(ihst, log_, impl, xmn, xmx, iscl, nx, m, ndim, a, 
	iwdth, nplot, iout)
integer *ihst, *log_, *impl;
real *xmn, *xmx;
integer *iscl, *nx, *m, *ndim;
real *a;
integer *iwdth, *nplot, *iout;
{
    /* Initialized data */

    static struct {
	char e_1[44];
	integer e_2;
	} equiv_40 = { {'1', ' ', ' ', ' ', '2', ' ', ' ', ' ', '3', ' ', ' ',
		 ' ', '4', ' ', ' ', ' ', '5', ' ', ' ', ' ', '6', ' ', ' ', 
		' ', '7', ' ', ' ', ' ', '8', ' ', ' ', ' ', '9', ' ', ' ', 
		' ', '0', ' ', ' ', ' ', 'X', ' ', ' ', ' '}, 0 };

#define ih ((integer *)&equiv_40)


    /* Format strings */
    static char fmt_101[] = "(//\002 osx Y =>\002)";
    static char fmt_102[] = "(i3,3x,5(1pe10.2,10x),1pe10.2)";
    static char fmt_103[] = "(12x,101a1)";
    static char fmt_104[] = "(\002 ось X\002,6x,101i1)";
    static char fmt_106[] = "(1pe10.2,2x,101a1)";
    static char fmt_107[] = "(\002 *** grafik *** ERROR\002,i2,\002 ***\002)";

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3, i__4, i__5;
    real r__1, r__2, r__3, r__4, r__5;

    /* Builtin functions */
    double log(), r_lg10(), pow_ri(), r_int();
    integer s_wsfe(), e_wsfe(), do_fio();
    double exp();

    /* Local variables */
    static integer line[101];
    static real xmin, ymin[10], xmax, ymax[10];
    static integer i, j, k, l, nchar;
    extern /* Subroutine */ int space_();
    static integer isign[101], konst;
    static real w1, w2, rchar1;
    static integer konst1, ii, jj, ll, mm;
    static real dx, qq;
    static integer jz;
    static real zz;
    static integer nplmax;
    extern /* Subroutine */ int rastrh_();
    static integer irastr;
    static real rkonst;
    extern /* Subroutine */ int rastrv_();
    static real pom[6], ttt;

    /* Fortran I/O blocks */
    static cilist io___26 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___29 = { 0, 0, 0, fmt_102, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_103, 0 };
    static cilist io___32 = { 0, 0, 0, fmt_104, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_106, 0 };
    static cilist io___35 = { 0, 0, 0, fmt_104, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_106, 0 };
    static cilist io___38 = { 0, 0, 0, fmt_106, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_107, 0 };


/*     *************** */

/*     10.03.1983 ( dorabotal - cyrulxnik ) */
    /* Parameter adjustments */
    a_dim1 = *ndim;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
/*     MIRA ZAOKROUHLENI JZ */
/*     JZ = 0, 1, 2, ...  (0 = NEZAOKROUHLUJE SE) */
    jz = 4;
/*     POCET SLOUPCU GRAFU NCHAR */
/*     NCHAR = 20 * KONST + 1 */
/*     1 .LE. KONST .LE. 5 => 21 .LE. NCHAR .LE. 101 */
    konst = 5;
    nchar = 101;
    if (*iwdth != 0) {
	konst = 3;
    }
    if (*iwdth != 0) {
	nchar = 61;
    }
/*     INDIKACE POZADAVKU NA TISK RASTRU IRASTR */
/*     NEMA-LI SE TISKNOUT RASTR GRAFU, IRASTR = 0 */
    irastr = 1;
    rkonst = (real) konst;
    rchar1 = (real) (nchar - 1);
    konst1 = konst + 1;
/* maksim.~islo grafikow,zadawaemoe w " TR3 " : */
/*  M = NSEC ( pri pe~ati srazu wseh wyh.weli~in ) */
/*  M = IHOLD+1 ( pri pe~ati posle zapisi nesk.graf.w pamqtx ) */
    nplmax = *m;
/* postr.grafikow s u~etom zadan.kol-wa w odnoj sis-me koordin. */
    i__1 = nplmax;
    i__2 = *nplot;
    for (jj = 1; i__2 < 0 ? jj >= i__1 : jj <= i__1; jj += i__2) {
	xmin = *xmn;
	xmax = *xmx;
	*m = jj + *nplot - 1;
	if (*m > nplmax) {
	    *m = nplmax;
	}
	if (*impl != 0) {
	    mm = *m;
	}
	if (*impl == 0) {
	    mm = *m - 1;
	}
/*     REALIZACE POPISU DATA PRO POLE VODICICH ZNACEK */
	i__3 = nchar;
	for (i = 1; i <= i__3; ++i) {
	    j = i - 1;
	    isign[i - 1] = j - j / 10 * 10;
/* L50: */
	}
/*     PRVNI CAST KONTROLY PARAMETRU */
	i = 1;
	if (*nx > *ndim) {
	    goto L99;
	}
	i = 2;
	if (*nx <= 1) {
	    goto L99;
	}
	i = 3;
	if (mm < 1) {
	    goto L99;
	}
	i = 4;
	if (mm > 10) {
	    goto L99;
	}
	i = 5;
	if (*ihst != 0 && mm != 1) {
	    goto L99;
	}
	if (*impl != 0) {
	    goto L1;
	}
/*     SETRIDENI PODLE NEZAVISLE PROMENNE */
	i__3 = *nx;
	for (i = 1; i <= i__3; ++i) {
	    i__4 = *nx;
	    for (j = i; j <= i__4; ++j) {
		if (a[i + *m * a_dim1] <= a[j + *m * a_dim1]) {
		    goto L3;
		}
		i__5 = *m;
		for (k = jj; k <= i__5; ++k) {
		    ttt = a[i + k * a_dim1];
		    a[i + k * a_dim1] = a[j + k * a_dim1];
		    a[j + k * a_dim1] = ttt;
/* L4: */
		}
L3:
		;
	    }
/* L2: */
	}
	xmax = a[*nx + *m * a_dim1];
	xmin = a[*m * a_dim1 + 1];
/*     DRUHA CAST KONTROLY PARAMETRU */
L1:
	i = 6;
	if (xmin <= (float)0. && *log_ != 0) {
	    goto L99;
	}
	i = 7;
	if (xmin >= xmax) {
	    goto L99;
	}
/*     URCENI KROKU NEZAVISLE PROMENNE */
	dx = (xmax - xmin) / (real) (*nx - 1);
	if (*log_ != 0) {
	    dx = (log(xmax) - log(xmin)) / (real) (*nx - 1);
	}
/*     NALEZENI MAXIMA A MINIMA ZAVISLE PROMENNYCH */
	i__3 = mm;
	for (i = jj; i <= i__3; ++i) {
	    ymax[i - 1] = a[i * a_dim1 + 1];
	    ymin[i - 1] = ymax[i - 1];
/* L5: */
	}
	i__3 = mm;
	for (i = jj; i <= i__3; ++i) {
	    i__4 = *nx;
	    for (j = 2; j <= i__4; ++j) {
		if (a[j + i * a_dim1] > ymax[i - 1]) {
		    ymax[i - 1] = a[j + i * a_dim1];
		}
		if (a[j + i * a_dim1] < ymin[i - 1]) {
		    ymin[i - 1] = a[j + i * a_dim1];
		}
/* L6: */
	    }
	}
	if (*iscl == 0) {
	    goto L9;
	}
/*     REALIZACE SPOLECNEHO MERITKA ZAVISLE PROMENNYCH */
	i__4 = mm;
	for (i = jj; i <= i__4; ++i) {
	    if (ymax[i - 1] > ymax[jj - 1]) {
		ymax[jj - 1] = ymax[i - 1];
	    }
	    if (ymin[i - 1] < ymin[jj - 1]) {
		ymin[jj - 1] = ymin[i - 1];
	    }
/* L7: */
	}
	i__4 = mm;
	for (i = jj; i <= i__4; ++i) {
	    ymax[i - 1] = ymax[jj - 1];
	    ymin[i - 1] = ymin[jj - 1];
/* L8: */
	}
/*     ZAOKRUHLENI KRAJNICH HODNOT ZAVISLE PROMENNYCH */
L9:
	i__4 = mm;
	for (i = jj; i <= i__4; ++i) {
	    if (ymax[i - 1] == ymin[i - 1]) {
		goto L11;
	    }
	    if (jz <= 0) {
		goto L10;
	    }
	    r__1 = ymax[i - 1] - ymin[i - 1];
	    i__3 = (integer) r_lg10(&r__1) - 1;
	    ttt = pow_ri(&c_b16, &i__3);
	    if (ymax[i - 1] - ymin[i - 1] < (float)1.) {
		ttt /= (float)10.;
	    }
	    w1 = (float).9999999999;
	    w2 = w1;
	    if (ymax[i - 1] < (float)0.) {
		w1 = (float)0.;
	    }
	    if (ymin[i - 1] > (float)0.) {
		w2 = (float)0.;
	    }
	    i__3 = (jz - 1) / 2;
	    zz = pow_ri(&c_b16, &i__3);
	    if ((ymax[i - 1] - ymin[i - 1]) / ttt < (float)50.) {
		goto L12;
	    }
	    if (jz / 2 << 1 == jz) {
		zz *= (float)5.;
	    }
L13:
	    qq = ttt * zz;
	    r__1 = ymax[i - 1] / qq + w1;
	    ymax[i - 1] = r_int(&r__1) * qq;
	    r__1 = ymin[i - 1] / qq - w2;
	    ymin[i - 1] = r_int(&r__1) * qq;
	    goto L10;
L12:
	    if (jz / 2 << 1 != jz) {
		zz /= (float)2.;
	    }
	    goto L13;
L11:
/* Computing MAX */
	    r__4 = ymax[i - 1] + (float)1.;
	    r__5 = ymax[i - 1] + (r__1 = ymax[i - 1], dabs(r__1)) * (float)
		    .001;
	    r__2 = r_int(&r__4), r__3 = r_int(&r__5);
	    ymax[i - 1] = dmax(r__2,r__3);
/* Computing MIN */
	    r__4 = ymin[i - 1] - (float)1.;
	    r__5 = ymin[i - 1] - (r__1 = ymin[i - 1], dabs(r__1)) * (float)
		    .001;
	    r__2 = r_int(&r__4), r__3 = r_int(&r__5);
	    ymin[i - 1] = dmin(r__2,r__3);
L10:
	    ;
	}
	io___26.ciunit = *iout;
	s_wsfe(&io___26);
	e_wsfe();
/*     VYPOCET A TISK MERITKA ZAVISLE PROMENNYCH */
	i__4 = mm;
	for (ii = jj; ii <= i__4; ++ii) {
	    i = ii;
	    ttt = (ymax[i - 1] - ymin[i - 1]) / rkonst;
	    i__3 = konst1;
	    for (j = 1; j <= i__3; ++j) {
		pom[j - 1] = (real) (j - 1) * ttt + ymin[i - 1];
/* L15: */
	    }
	    io___29.ciunit = *iout;
	    s_wsfe(&io___29);
	    do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	    i__3 = konst1;
	    for (j = 1; j <= i__3; ++j) {
		do_fio(&c__1, (char *)&pom[j - 1], (ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* L14: */
	}
	space_(line, &nchar);
	rastrv_(line, &nchar);
	io___31.ciunit = *iout;
	s_wsfe(&io___31);
	i__4 = nchar;
	for (i = 1; i <= i__4; ++i) {
	    do_fio(&c__1, (char *)&line[i - 1], (ftnlen)sizeof(integer));
	}
	e_wsfe();
	io___32.ciunit = *iout;
	s_wsfe(&io___32);
	i__4 = nchar;
	for (i = 1; i <= i__4; ++i) {
	    do_fio(&c__1, (char *)&isign[i - 1], (ftnlen)sizeof(integer));
	}
	e_wsfe();
	if (*impl == 0) {
	    goto L16;
	}
/*     VYPOCET A TISK KRIVEK PRI IMPLICITNIM ZADANI */
/*     NEZAVISLE PROMENNE */
	i__4 = *nx;
	for (i = 1; i <= i__4; ++i) {
	    space_(line, &nchar);
	    if (i / 15 * 15 == i && irastr != 0) {
		rastrh_(line, &nchar);
	    }
	    if (irastr != 0) {
		rastrv_(line, &nchar);
	    }
	    if (*log_ == 0) {
		ttt = xmin + (real) (i - 1) * dx;
	    }
	    if (*log_ != 0) {
		ttt = xmin * exp((real) (i - 1) * dx);
	    }
	    i__3 = mm;
	    for (j = jj; j <= i__3; ++j) {
		k = (integer) (rchar1 * (a[i + j * a_dim1] - ymin[j - 1]) / (
			ymax[j - 1] - ymin[j - 1]) + (float)1.5);
		line[k - 1] = ih[j - 1];
		if (*ihst == 0) {
		    goto L18;
		}
		i__5 = k;
		for (l = 1; l <= i__5; ++l) {
		    line[l - 1] = ih[10];
/* L25: */
		}
L18:
		;
	    }
	    io___34.ciunit = *iout;
	    s_wsfe(&io___34);
	    do_fio(&c__1, (char *)&ttt, (ftnlen)sizeof(real));
	    i__3 = nchar;
	    for (j = 1; j <= i__3; ++j) {
		do_fio(&c__1, (char *)&line[j - 1], (ftnlen)sizeof(integer));
	    }
	    e_wsfe();
/* L17: */
	}
/* L23: */
	io___35.ciunit = *iout;
	s_wsfe(&io___35);
	i__4 = nchar;
	for (i = 1; i <= i__4; ++i) {
	    do_fio(&c__1, (char *)&isign[i - 1], (ftnlen)sizeof(integer));
	}
	e_wsfe();
/*     WRITE (IOUT,105) */
/* L100: */
    }
    return 0;
/*     VYPOCET A TISK KRIVEK PRI EXPLICITNIM ZADANI */
/*     NEZAVISLE PROMENNE */
L16:
    i = 1;
    j = 1;
L22:
    space_(line, &nchar);
    if (i / 15 * 15 == i && irastr != 0) {
	rastrh_(line, &nchar);
    }
    if (irastr != 0) {
	rastrv_(line, &nchar);
    }
    if (*log_ == 0) {
	ttt = xmin + (real) (i - 1) * dx;
    }
    if (*log_ != 0) {
	ttt = xmin * exp((real) (i - 1) * dx);
    }
    zz = ((real) i - (float).5) * dx;
    if (*log_ == 0) {
	zz = xmin + zz;
    }
    if (*log_ != 0) {
	zz = xmin * exp(zz);
    }
L21:
    if (a[j + *m * a_dim1] >= zz) {
	goto L19;
    }
    i__2 = mm;
    for (l = jj; l <= i__2; ++l) {
	k = (integer) (rchar1 * (a[j + l * a_dim1] - ymin[l - 1]) / (ymax[l - 
		1] - ymin[l - 1]) + (float)1.5);
	line[k - 1] = ih[l - 1];
	if (*ihst == 0) {
	    goto L20;
	}
	i__1 = k;
	for (ll = 1; ll <= i__1; ++ll) {
	    line[ll - 1] = ih[10];
/* L26: */
	}
L20:
	;
    }
    if (j == *nx) {
	goto L24;
    }
    ++j;
    goto L21;
L19:
    io___37.ciunit = *iout;
    s_wsfe(&io___37);
    do_fio(&c__1, (char *)&ttt, (ftnlen)sizeof(real));
    i__2 = nchar;
    for (k = 1; k <= i__2; ++k) {
	do_fio(&c__1, (char *)&line[k - 1], (ftnlen)sizeof(integer));
    }
    e_wsfe();
    ++i;
    goto L22;
L24:
    io___38.ciunit = *iout;
    s_wsfe(&io___38);
    do_fio(&c__1, (char *)&ttt, (ftnlen)sizeof(real));
    i__2 = nchar;
    for (k = 1; k <= i__2; ++k) {
	do_fio(&c__1, (char *)&line[k - 1], (ftnlen)sizeof(integer));
    }
    e_wsfe();
/*      GO TO 23 powered by me */
/*     TISK HLASENI O CHYBE */
L99:
    io___39.ciunit = *iout;
    s_wsfe(&io___39);
    do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;
/* 105 FORMAT ('+',6X,'I') */
} /* plot_ */

#undef ih


/* Subroutine */ int space_(line, nchar)
integer *line, *nchar;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_43 = { {' ', ' ', ' ', ' '}, 0 };

#define ihb (*(integer *)&equiv_43)


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i;

/*     **************** */
/*     31.6.1977 */
    /* Parameter adjustments */
    --line;

    /* Function Body */
    i__1 = *nchar;
    for (i = 1; i <= i__1; ++i) {
	line[i] = ihb;
/* L1: */
    }
    return 0;
} /* space_ */

#undef ihb


/* Subroutine */ int rastrv_(line, nchar)
integer *line, *nchar;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_46 = { {'!', ' ', ' ', ' '}, 0 };

#define ihi (*(integer *)&equiv_46)


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i;

/*     ***************** */
    /* Parameter adjustments */
    --line;

    /* Function Body */
    i__1 = *nchar;
    for (i = 1; i <= i__1; i += 20) {
	line[i] = ihi;
/* L1: */
    }
    return 0;
} /* rastrv_ */

#undef ihi


/* Subroutine */ int rastrh_(line, nchar)
integer *line, *nchar;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_49 = { {'-', ' ', ' ', ' '}, 0 };

#define ihm (*(integer *)&equiv_49)


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i;

/*     ***************** */
    /* Parameter adjustments */
    --line;

    /* Function Body */
    i__1 = *nchar;
    for (i = 1; i <= i__1; ++i) {
	line[i] = ihm;
/* L1: */
    }
    return 0;
} /* rastrh_ */

#undef ihm


/* Subroutine */ int plott3_(ivarx, ititle, namin, indep, ihold, name, np, m, 
	xmin, xmax, iwdth, mplot, nplot, iou, irec)
integer *ivarx, *ititle, *namin, *indep, *ihold, *name, *np, *m;
doublereal *xmin, *xmax;
integer *iwdth, *mplot, *nplot, *iou, *irec;
{
    /* Initialized data */

    static struct {
	char e_1[24];
	integer e_2;
	} equiv_81 = { {'\256', '\341', ' ', ' ', '\354', ' ', ' ', ' ', 'Y', 
		':', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
		' ', ' ', ' '}, 0 };

#define iaxy ((integer *)&equiv_81)


    /* Format strings */
    static char fmt_130[] = "(//15x,30a2)";
    static char fmt_100[] = "(//30x,\002ось X: \002,6x,2a2,i2//)";
    static char fmt_110[] = "(30x,3a2,2x,i2,\002 ... \002,a2,i2)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    alist al__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe(), f_rew(), s_rsue(), do_uio(), e_rsue(
	    );

    /* Local variables */
    static real graf[650]	/* was [65][10] */;
    static doublereal xdel;
    static integer impl;
    extern /* Subroutine */ int plot_();
    static integer i, j, k, l, n, k1, k2;
    static real x1, x2;
    static integer ib, nc, ii, jj, kk, kk1;
    static doublereal buf[10];
    static integer kkk, mup;

    /* Fortran I/O blocks */
    static cilist io___51 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___54 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___56 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___57 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___64 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___67 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___68 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___73 = { 0, 0, 0, 0, 0 };
    static cilist io___76 = { 0, 0, 0, 0, 0 };


/*     ***************** */
/*    31.10.89 */
    /* Parameter adjustments */
    name -= 3;
    --namin;
    --ititle;

    /* Function Body */
    io___51.ciunit = *iou;
    s_wsfe(&io___51);
    do_fio(&c__30, (char *)&ititle[1], (ftnlen)sizeof(integer));
    e_wsfe();
    mup = 1;
    *ihold = min(*ihold,9);
    if (*ihold != 0) {
	mup = *ihold + 1;
    }
    nc = *m;
    if (*ihold != 0) {
	nc = *ihold + 1;
    }
    if (*ivarx == 0) {
	goto L5;
    }

    io___54.ciunit = *iou;
    s_wsfe(&io___54);
    do_fio(&c__1, (char *)&name[(*ivarx << 1) + 1], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ib, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&name[(*ivarx << 1) + 2], (ftnlen)sizeof(integer));
    e_wsfe();
    goto L8;
L5:
    if (*indep <= 0) {
	goto L7;
    }
/* INDEPENDENT VARIABLE IS ELEMENT PARAMETER */
    io___56.ciunit = *iou;
    s_wsfe(&io___56);
    do_fio(&c__2, (char *)&namin[1], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*indep), (ftnlen)sizeof(integer));
    e_wsfe();
    goto L8;
/* INDEPENDENT VARIABLE IS TIME OR TEMP */
L7:
    io___57.ciunit = *iou;
    s_wsfe(&io___57);
    do_fio(&c__2, (char *)&namin[1], (ftnlen)sizeof(integer));
    e_wsfe();
L8:
/* DEPENDENT VARIABLE */
    i__1 = nc;
    for (k1 = 1; k1 <= i__1; ++k1) {
	k2 = k1;
	k = k1;
	if (*ihold != 0) {
	    k = 1;
	}
	kk = 4;
	if (k1 == 1) {
	    kk = 1;
	}
	kkk = kk + 2;
	if (*ivarx == k) {
	    goto L9;
	}
	kk1 = kk;
	io___64.ciunit = *iou;
	s_wsfe(&io___64);
	i__2 = kkk;
	for (jj = kk; jj <= i__2; ++jj) {
	    do_fio(&c__1, (char *)&iaxy[jj - 1], (ftnlen)sizeof(integer));
	}
	do_fio(&c__1, (char *)&k2, (ftnlen)sizeof(integer));
	for (l = 1; l <= 2; ++l) {
	    do_fio(&c__1, (char *)&name[l + (k << 1)], (ftnlen)sizeof(integer)
		    );
	}
	e_wsfe();
	goto L20;
L9:
	if (*indep <= 0) {
	    goto L10;
	}
	io___67.ciunit = *iou;
	s_wsfe(&io___67);
	i__2 = kkk;
	for (jj = kk; jj <= i__2; ++jj) {
	    do_fio(&c__1, (char *)&iaxy[jj - 1], (ftnlen)sizeof(integer));
	}
	do_fio(&c__1, (char *)&k2, (ftnlen)sizeof(integer));
	do_fio(&c__2, (char *)&namin[1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*indep), (ftnlen)sizeof(integer));
	e_wsfe();
	goto L20;
L10:
	io___68.ciunit = *iou;
	s_wsfe(&io___68);
	i__2 = kkk;
	for (jj = kk; jj <= i__2; ++jj) {
	    do_fio(&c__1, (char *)&iaxy[jj - 1], (ftnlen)sizeof(integer));
	}
	do_fio(&c__1, (char *)&k2, (ftnlen)sizeof(integer));
	do_fio(&c__2, (char *)&namin[1], (ftnlen)sizeof(integer));
	e_wsfe();
L20:
	;
    }
/* READ OUTPUT POINTS */
    xdel = *xmax - *xmin;
    n = *np;
    if (*np < 0) {
	n = -(*np) / 2;
    }
    al__1.aerr = 0;
    al__1.aunit = *irec;
    f_rew(&al__1);
    i__1 = mup;
    for (ii = 1; ii <= i__1; ++ii) {
	i__2 = n;
	for (i = 1; i <= i__2; ++i) {
	    io___73.ciunit = *irec;
	    s_rsue(&io___73);
	    i__3 = *m;
	    for (j = 1; j <= i__3; ++j) {
		do_uio(&c__1, (char *)&buf[j - 1], (ftnlen)sizeof(doublereal))
			;
	    }
	    e_rsue();
	    if (*np > 0) {
		goto L25;
	    }
	    io___76.ciunit = *irec;
	    s_rsue(&io___76);
	    e_rsue();
L25:
	    if (*ihold != 0) {
		goto L35;
	    }
	    i__3 = *m;
	    for (k = 1; k <= i__3; ++k) {
		if (*ivarx == k) {
		    goto L27;
		}
		graf[i + k * 65 - 66] = buf[k - 1];
		goto L30;
L27:
		graf[i + k * 65 - 66] = *xmin + (real) (i - 1) * xdel;
L30:
		;
	    }
	    if (*ivarx != 0) {
		graf[i + (*m + 1) * 65 - 66] = buf[*ivarx - 1];
	    }
	    goto L40;
L35:
	    graf[i + ii * 65 - 66] = buf[0];
L40:
	    ;
	}
/* L50: */
    }
    if (*ivarx != 0) {
	nc = *m + 1;
    }
    x1 = *xmin;
    x2 = *xmax;
    impl = 1;
    if (*ivarx != 0) {
	impl = 0;
    }
/* PLOT OUT GRAPHS */
    plot_(&c__0, &c__0, &impl, &x1, &x2, mplot, &n, &nc, &c__65, graf, iwdth, 
	    nplot, iou);
    return 0;
} /* plott3_ */

#undef iaxy


