/* po1.f -- translated by f2c (version of 23 April 1993  18:34:30).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int outpd_(n, m, qr, qi, iou)
integer *n, *m;
doublereal *qr, *qi;
integer *iou;
{
    /* Initialized data */

    static doublereal big = 1e35;
    static doublereal small = 1e-35;
    static doublereal pi2 = 6.283185308;

    /* Format strings */
    static char fmt_100[] = "(59x,\002нет корней\002)";
    static char fmt_110[] = "(2x,\002пор.\002,4x,\002действ.\002,10x,\002мни\
мая\002,11x,\002временная\002/1x,\002номер\002,4x,\002часть\002,12x,\002часть\
\002,12x,\002константа\002,/)";
    static char fmt_111[] = "(2x,\002пор.\002,2(6x,\002коэффиц. \002),6x,7x,\
7x,\002собств.\002,9x,4x/1x,\002номер\002,6x,\002затухание\002,5x,\002доброт\
н.\002,2(6x,\002частота \002),8x,\002фаза\002/)";
    static char fmt_120[] = "(2x,i2,4x,3(1pd15.5,2x))";
    static char fmt_121[] = "(2x,i2,6x,5(1pd13.4,1x))";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
    static integer i;
    static doublereal q, omega;
    extern /* Subroutine */ int amphd_();
    static doublereal phase, s1, s2;
    static integer ii;
    static doublereal qm, tau, xsi;

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___5 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___6 = { 0, 0, 0, fmt_111, 0 };
    static cilist io___10 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___18 = { 0, 0, 0, fmt_121, 0 };


/*     **************** */

/*     28.9.1987 */
    /* Parameter adjustments */
    --qi;
    --qr;

    /* Function Body */
    if (*n <= 0) {
	io___4.ciunit = *iou;
	s_wsfe(&io___4);
	e_wsfe();
    }
    if (*n <= 0) {
	return 0;
    }
    io___5.ciunit = *iou;
    s_wsfe(&io___5);
    e_wsfe();
    io___6.ciunit = *iou;
    s_wsfe(&io___6);
    e_wsfe();
/* печать действ. */
    i__1 = *n;
    for (ii = 1; ii <= i__1; ++ii) {
	i = ii;
	tau = big;
	if ((d__1 = qr[i], abs(d__1)) > small) {
	    tau = -1. / qr[i];
	}
	io___10.ciunit = *iou;
	s_wsfe(&io___10);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&qr[i], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&qi[i], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tau, (ftnlen)sizeof(doublereal));
	e_wsfe();

	if (qi[i] == 0.) {
	    goto L20;
	}
	amphd_(&qr[i], &qi[i], &qm, &phase, &s1, &s2);
	xsi = -qr[i] / qm;
	q = big;
	if (abs(xsi) > small) {
	    q = .5 / xsi;
	}
	omega = (d__1 = qi[i], abs(d__1)) / pi2;
	qm /= pi2;
	io___18.ciunit = *iou;
	s_wsfe(&io___18);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&xsi, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&q, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&qm, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&omega, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phase, (ftnlen)sizeof(doublereal));
	e_wsfe();
L20:
/* L10: */
	;
    }
    return 0;
} /* outpd_ */

/* Subroutine */ int polyd_(nroot, ndim, rootre, rootim, ncoef, coef)
integer *nroot, *ndim;
doublereal *rootre, *rootim;
integer *ncoef;
doublereal *coef;
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static doublereal help1, help2, help3;
    static integer i, j;
    static doublereal c1, c2;
    static integer incdeg;

/*     **************** */

/*     15.5.1981 */
    /* Parameter adjustments */
    --coef;
    --rootim;
    --rootre;

    /* Function Body */
    *ncoef = 1;
    coef[1] = 1.;
    if (*nroot <= 0) {
	return 0;
    }
    i__1 = *nroot;
    for (i = 1; i <= i__1; ++i) {
	c1 = -rootre[i];
	help1 = rootim[i];
	if (help1 < 0.) {
	    goto L50;
	} else if (help1 == 0) {
	    goto L20;
	} else {
	    goto L10;
	}
/* KOMPLEXNE ZDRUZENE KORENY */
L10:
	coef[*ncoef + 1] = 0.;
	c2 = c1 * 2.;
	c1 = c1 * c1 + help1 * help1;
	incdeg = 2;
	goto L30;
/* REALNE KORENY */
L20:
	c2 = 1.;
	incdeg = 1;
L30:
	*ncoef += incdeg;
	coef[*ncoef] = 0.;
/* VYPOCET KOEFICIENTU (NEJVYSE 3 PRVKY COEF SE UCASTNI */
/* NASOBENI POLYNOMU KORENOVYM CINITELEM */
	i__2 = *ncoef;
	for (j = 1; j <= i__2; ++j) {
	    if (j > 3) {
		coef[j - 3] = help3;
	    }
	    help3 = help2;
	    help2 = help1;
	    help1 = c1 * coef[j];
	    if (j > 1) {
		help1 += c2 * coef[j - 1];
	    }
	    if (j > 2 && incdeg == 2) {
		help1 += coef[j - 2];
	    }
/* L40: */
	}
	if (*ncoef > 2) {
	    coef[*ncoef - 2] = help3;
	}
	coef[*ncoef - 1] = help2;
	coef[*ncoef] = 1.;
L50:
	;
    }
    return 0;
} /* polyd_ */

/* Subroutine */ int normd_(n, ndim, a, rnorm)
integer *n, *ndim;
doublereal *a, *rnorm;
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer i, j;
    static doublereal dum;

/*     **************** */
/* VYPOCET NORMEM SLOUPCU CTVERCOVE MATICE */
/*     17.4.1980 */
    /* Parameter adjustments */
    --rnorm;
    a_dim1 = *ndim;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	rnorm[j] = 0.;
	i__2 = *n;
	for (i = 1; i <= i__2; ++i) {
	    dum = (d__1 = a[i + j * a_dim1], abs(d__1));
	    if (rnorm[j] < dum) {
		rnorm[j] = dum;
	    }
/* L10: */
	}
    }
    return 0;
} /* normd_ */

/* Subroutine */ int defld1_(tole, e1, n, ndim, a, b, an, bn, nb, d)
doublereal *tole, *e1;
integer *n, *ndim;
doublereal *a, *b, *an, *bn;
integer *nb;
doublereal *d;
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer i, j, k;
    extern /* Subroutine */ int normd_();
    static integer k1, n1;
    static doublereal w1, w2;
    static integer na;
    static doublereal wa;
    static integer ir, jr, kr, iy, iz, jz, jy, ny, nb1;
    static doublereal big, aik, akj, bkj, tol;

/*     ***************** */
/* REDUKCE MATICE ZOBECNENE ULOHY CHARAKTERISTICKYCH CISEL */
/* NA MATICI STANDARDNI ULOHY V DVOJNASOBNE DELCE */
/*     30.9.1981 */
    /* Parameter adjustments */
    --bn;
    --an;
    b_dim1 = *ndim;
    b_offset = b_dim1 + 1;
    b -= b_offset;
    a_dim1 = *ndim;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    *d = 1.;
    *nb = *n;
    if (*n == 0) {
	goto L100;
    }
    n1 = *n + 1;
/* VYPOCET NOREM SLOUPCU MATIC A,B */
    normd_(n, ndim, &a[a_offset], &an[1]);
    normd_(n, ndim, &b[b_offset], &bn[1]);
/* PRIMA ELIMINACE */
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
/* VYPOCET NORMY MATICE A */
	iz = k;
	jz = k;
	big = 0.;
	i__2 = *n;
	for (j = k; j <= i__2; ++j) {
	    i__3 = *n;
	    for (i = k; i <= i__3; ++i) {
		if (abs(big) >= (d__1 = a[i + j * a_dim1], abs(d__1))) {
		    goto L22;
		}
		big = a[i + j * a_dim1];
		iz = i;
		jz = j;
L22:
		;
	    }
	}
	tol = an[jz] * *tole;
	if (abs(big) <= tol) {
	    goto L58;
	}
	if (k == *n) {
	    goto L50;
	}
/* ZAMENA RADKU */
	if (iz == k) {
	    goto L26;
	}
	*d = -(*d);
	i__3 = *n;
	for (j = 1; j <= i__3; ++j) {
	    wa = a[iz + j * a_dim1];
	    a[iz + j * a_dim1] = a[k + j * a_dim1];
	    a[k + j * a_dim1] = wa;
	    wa = b[iz + j * b_dim1];
	    b[iz + j * b_dim1] = b[k + j * b_dim1];
/* L24: */
	    b[k + j * b_dim1] = wa;
	}
/* ZAMENA SLOUPCU */
L26:
	if (jz == k) {
	    goto L30;
	}
	*d = -(*d);
	i__3 = *n;
	for (i = 1; i <= i__3; ++i) {
	    wa = a[i + jz * a_dim1];
	    a[i + jz * a_dim1] = a[i + k * a_dim1];
	    a[i + k * a_dim1] = wa;
	    wa = b[i + jz * b_dim1];
	    b[i + jz * b_dim1] = b[i + k * b_dim1];
/* L28: */
	    b[i + k * b_dim1] = wa;
	}
	wa = an[jz];
	an[jz] = an[k];
	an[k] = wa;
	wa = bn[jz];
	bn[jz] = bn[k];
	bn[k] = wa;
/* SLOUPCOVE OPERACE V MATICICH A, B */
L30:
	k1 = k + 1;
	i__3 = *n;
	for (j = k1; j <= i__3; ++j) {
	    akj = a[k + j * a_dim1] / big;
	    wa = abs(akj);
	    if (wa <= *e1) {
		goto L36;
	    }
	    an[j] += an[k] * wa;
	    bn[j] += bn[k] * wa;
	    i__2 = *n;
	    for (i = k1; i <= i__2; ++i) {
/* L32: */
		a[i + j * a_dim1] -= a[i + k * a_dim1] * akj;
	    }
	    i__2 = *n;
	    for (i = 1; i <= i__2; ++i) {
/* L34: */
		b[i + j * b_dim1] -= b[i + k * b_dim1] * akj;
	    }
L36:
	    ;
	}
/* RADKOVE OPERACE V MATICI B */
	i__3 = *n;
	for (i = k1; i <= i__3; ++i) {
	    aik = a[i + k * a_dim1] / big;
	    if (abs(aik) <= *e1) {
		goto L40;
	    }
	    i__2 = *n;
	    for (j = 1; j <= i__2; ++j) {
/* L38: */
		b[i + j * b_dim1] -= b[k + j * b_dim1] * aik;
	    }
L40:
	    a[i + k * a_dim1] = 0.;
/* L42: */
	    a[k + i * a_dim1] = 0.;
	}
L50:
	;
    }
/* MATICE A JE REGULARNI */
    na = *n;
    *nb = na;
/* VYPOCET DETERMINANTU */
L52:
    i__1 = *nb;
    for (i = 1; i <= i__1; ++i) {
/* L54: */
	*d *= a[i + i * a_dim1];
    }
    i__1 = *nb;
    for (j = 1; j <= i__1; ++j) {
	w1 = sqrt((d__1 = a[j + j * a_dim1], abs(d__1)));
	w2 = -w1;
	if (a[j + j * a_dim1] < 0.) {
	    w2 = -w2;
	}
	i__3 = *nb;
	for (i = 1; i <= i__3; ++i) {
	    b[j + i * b_dim1] /= w1;
	    b[i + j * b_dim1] /= w2;
/* L56: */
	}
    }
    return 0;
/* ZPETNA ELIMINACE */
L58:
    na = k - 1;
    *nb = na;
    k = 0;
L60:
    ++k;
L61:
    kr = n1 - k;
    ny = *n - *nb;
/* VYPOCET NORMY PODMATICE B */
    big = 0.;
    i__3 = ny;
    for (j = k; j <= i__3; ++j) {
	jr = n1 - j;
	i__1 = ny;
	for (i = k; i <= i__1; ++i) {
	    ir = n1 - i;
	    if (abs(big) > (d__1 = b[ir + jr * b_dim1], abs(d__1))) {
		goto L62;
	    }
	    big = b[ir + jr * b_dim1];
	    iz = ir;
	    jz = jr;
L62:
	    ;
	}
    }
    if (*nb <= 0) {
	goto L63;
    } else {
	goto L65;
    }
L63:
    tol = bn[jz] * *tole;
    goto L69;
L65:
    bkj = 0.;
    iy = 1;
    i__1 = *nb;
    for (i = 1; i <= i__1; ++i) {
	wa = b[i + jz * b_dim1] / a[i + i * a_dim1];
	if (abs(bkj) >= abs(wa)) {
	    goto L67;
	}
	bkj = wa;
	iy = i;
L67:
	;
    }
    tol = abs(bkj) * an[iy] * *tole;
L69:
    if (abs(big) > tol) {
	goto L66;
    }
/* VYPOCET NORMY REDUKCNICH VEKTORU */
    if (ny == *n) {
	goto L92;
    }
    big = bkj;
    iz = iy;
    jy = jz;
    tol = bn[jy] * *tole;
    if ((d__1 = big * a[iz + iz * a_dim1], abs(d__1)) <= tol) {
	goto L92;
    }
    kr = *nb;
    jz = iz;
    a[iz + iz * a_dim1] = a[*nb + *nb * a_dim1];
    an[iz] = an[*nb];
/* ZAMENA RADKU */
L66:
    if (iz == kr) {
	goto L70;
    }
    *d = -(*d);
    i__1 = *n;
    for (j = k; j <= i__1; ++j) {
	jr = n1 - j;
	wa = b[iz + jr * b_dim1];
	b[iz + jr * b_dim1] = b[kr + jr * b_dim1];
/* L68: */
	b[kr + jr * b_dim1] = wa;
    }
/* ZAMENA SLOUPCU */
L70:
    if (jz == kr) {
	goto L74;
    }
    *d = -(*d);
    i__1 = *n;
    for (i = k; i <= i__1; ++i) {
	ir = n1 - i;
	wa = b[ir + jz * b_dim1];
	b[ir + jz * b_dim1] = b[ir + kr * b_dim1];
/* L72: */
	b[ir + kr * b_dim1] = wa;
    }
    wa = bn[jz];
    bn[jz] = bn[kr];
    bn[kr] = wa;
L74:
    if (kr != *nb) {
	goto L80;
    }
/* REDUKCNI POSTUP */
    nb1 = *nb;
    --(*nb);
    if (*nb == 0) {
	goto L61;
    }
    kr = n1 - k;
    i__1 = *nb;
    for (j = 1; j <= i__1; ++j) {
	bkj = b[j + jy * b_dim1] / a[j + j * a_dim1] / big;
	wa = abs(bkj);
	if (wa <= *e1) {
	    goto L78;
	}
	bn[nb1] += bn[j] * wa;
	i__3 = kr;
	for (i = 1; i <= i__3; ++i) {
/* L76: */
	    b[i + nb1 * b_dim1] += b[i + j * b_dim1] * bkj;
	}
L78:
	;
    }
    goto L61;
L80:
    kr = n1 - k;
    *d *= big;
    if (k == *n) {
	goto L90;
    }
/* SLOUPCOVE PERACE V MATICI B */
    k1 = k + 1;
    i__1 = *n;
    for (j = k1; j <= i__1; ++j) {
	jr = n1 - j;
	bkj = b[kr + jr * b_dim1] / big;
	wa = abs(bkj);
	if (wa <= *e1) {
	    goto L88;
	}
	bn[jr] += bn[kr] * wa;
	i__3 = *n;
	for (i = k1; i <= i__3; ++i) {
	    ir = n1 - i;
/* L86: */
	    b[ir + jr * b_dim1] -= b[ir + kr * b_dim1] * bkj;
	}
L88:
	;
    }
    if (k != ny) {
	goto L60;
    }
L90:
    if (*nb != 0) {
	goto L52;
    }
    goto L100;
/* CHYBA */
L92:
    *d = 0.;
L100:
    return 0;
} /* defld1_ */

/* Subroutine */ int baland_(n, ndim, a, low, igh, scale)
integer *n, *ndim;
doublereal *a;
integer *low, *igh;
doublereal *scale;
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer iexc;
    static doublereal c, f, g;
    static integer i, j, k, l, m;
    static doublereal r, s, radix, b2;
    static integer jj;
    static logical noconv;

/*     ***************** */
/* VYVAZENI REALNE MATICE A IZOLOVANI JEJICH */
/* CHARAKTERISTICKYCH CISEL,POKUD JE MOZNE */
/*     28.1.1980 */
/* RADIX JE POCITACOVE ZAVISLY PARAMETR ROVNY */
/* ZAKLADU CISELNE REPREZENTACE S POHYBLIVOU CARKOU */
    /* Parameter adjustments */
    --scale;
    a_dim1 = *ndim;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    radix = 16.;
    b2 = radix * radix;
    k = 1;
    l = *n;
    goto L100;
/* ZAMENA RADEK A SLOUPCU */
L20:
    scale[m] = (doublereal) j;
    if (j == m) {
	goto L50;
    }
    i__1 = l;
    for (i = 1; i <= i__1; ++i) {
	f = a[i + j * a_dim1];
	a[i + j * a_dim1] = a[i + m * a_dim1];
	a[i + m * a_dim1] = f;
/* L30: */
    }
    i__1 = *n;
    for (i = k; i <= i__1; ++i) {
	f = a[j + i * a_dim1];
	a[j + i * a_dim1] = a[m + i * a_dim1];
	a[m + i * a_dim1] = f;
/* L40: */
    }
L50:
    switch ((int)iexc) {
	case 1:  goto L80;
	case 2:  goto L130;
    }
/* IZOLOVANI CHARAKTERISTICKEHO CISLA A JEHO POSUV DOLU */
L80:
    if (l == 1) {
	goto L280;
    }
    --l;
L100:
    i__1 = l;
    for (jj = 1; jj <= i__1; ++jj) {
	j = l + 1 - jj;
	i__2 = l;
	for (i = 1; i <= i__2; ++i) {
	    if (i == j) {
		goto L110;
	    }
	    if (a[j + i * a_dim1] != 0.) {
		goto L120;
	    }
L110:
	    ;
	}
	m = l;
	iexc = 1;
	goto L20;
L120:
	;
    }
    goto L140;
/* IZOLOVANI CHARAKTERISTICKEHO CISLA A JEHO POSUV DOLEVA */
L130:
    ++k;
L140:
    i__1 = l;
    for (j = k; j <= i__1; ++j) {
	i__2 = l;
	for (i = k; i <= i__2; ++i) {
	    if (i == j) {
		goto L150;
	    }
	    if (a[i + j * a_dim1] != 0.) {
		goto L170;
	    }
L150:
	    ;
	}
	m = k;
	iexc = 2;
	goto L20;
L170:
	;
    }
/* VYVAZENI PODMATICE V RADCICH K AZ L */
    i__1 = l;
    for (i = k; i <= i__1; ++i) {
/* L180: */
	scale[i] = 1.;
    }
/* ITERATIVNI CYKL PRO REDUKCI NORMY */
L190:
    noconv = FALSE_;
    i__1 = l;
    for (i = k; i <= i__1; ++i) {
	c = 0.;
	r = 0.;
	i__2 = l;
	for (j = k; j <= i__2; ++j) {
	    if (j == i) {
		goto L200;
	    }
	    c += (d__1 = a[j + i * a_dim1], abs(d__1));
	    r += (d__1 = a[i + j * a_dim1], abs(d__1));
L200:
	    ;
	}
	g = r / radix;
	f = 1.;
	s = c + r;
L210:
	if (c >= g) {
	    goto L220;
	}
	f *= radix;
	c *= b2;
	goto L210;
L220:
	g = r * radix;
L230:
	if (c < g) {
	    goto L240;
	}
	f /= radix;
	c /= b2;
	goto L230;
/* VYVAZENI */
L240:
	if ((c + r) / f >= s * .95) {
	    goto L270;
	}
	g = 1. / f;
	scale[i] *= f;
	noconv = TRUE_;
	i__2 = *n;
	for (j = k; j <= i__2; ++j) {
/* L250: */
	    a[i + j * a_dim1] *= g;
	}
	i__2 = l;
	for (j = 1; j <= i__2; ++j) {
/* L260: */
	    a[j + i * a_dim1] *= f;
	}
L270:
	;
    }
    if (noconv) {
	goto L190;
    }
L280:
    *low = k;
    *igh = l;
    return 0;
} /* baland_ */

/* Subroutine */ int hessd_(n, ndim, a, low, igh, int_)
integer *n, *ndim;
doublereal *a;
integer *low, *igh, *int_;
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;
    doublereal d__1;

    /* Local variables */
    static integer i, j, m;
    static doublereal x, y;
    static integer la, mm1, kp1, mp1;

/*     **************** */
/* REDUKCE REALNE MATICE NA HORNI HESSENBERGOVU FORMU */
/*     28.1.1980 */
    /* Parameter adjustments */
    --int_;
    a_dim1 = *ndim;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    la = *igh - 1;
    kp1 = *low + 1;
    if (la < kp1) {
	return 0;
    }
    i__1 = la;
    for (m = kp1; m <= i__1; ++m) {
	mm1 = m - 1;
	x = 0.;
	i = m;
	i__2 = *igh;
	for (j = m; j <= i__2; ++j) {
	    if ((d__1 = a[j + mm1 * a_dim1], abs(d__1)) <= abs(x)) {
		goto L100;
	    }
	    x = a[j + mm1 * a_dim1];
	    i = j;
L100:
	    ;
	}
	int_[m] = i;
	if (i == m) {
	    goto L130;
	}
/* ZAMENA RADEK A SLOUPCU */
	i__2 = *n;
	for (j = mm1; j <= i__2; ++j) {
	    y = a[i + j * a_dim1];
	    a[i + j * a_dim1] = a[m + j * a_dim1];
	    a[m + j * a_dim1] = y;
/* L110: */
	}
	i__2 = *igh;
	for (j = 1; j <= i__2; ++j) {
	    y = a[j + i * a_dim1];
	    a[j + i * a_dim1] = a[j + m * a_dim1];
	    a[j + m * a_dim1] = y;
/* L120: */
	}
/* KONECNA ZAMENA */
L130:
	if (x == 0.) {
	    goto L180;
	}
	mp1 = m + 1;
	i__2 = *igh;
	for (i = mp1; i <= i__2; ++i) {
	    y = a[i + mm1 * a_dim1];
	    if (y == 0.) {
		goto L160;
	    }
	    y /= x;
	    a[i + mm1 * a_dim1] = y;
	    i__3 = *n;
	    for (j = m; j <= i__3; ++j) {
/* L140: */
		a[i + j * a_dim1] -= y * a[m + j * a_dim1];
	    }
	    i__3 = *igh;
	    for (j = 1; j <= i__3; ++j) {
/* L150: */
		a[j + m * a_dim1] += y * a[j + i * a_dim1];
	    }
L160:
	    ;
	}
L180:
	;
    }
    return 0;
} /* hessd_ */

/* Subroutine */ int qrvald_(n, ndim, h, low, igh, wr, wi, ind)
integer *n, *ndim;
doublereal *h;
integer *low, *igh;
doublereal *wr, *wi;
integer *ind;
{
    /* System generated locals */
    integer h_dim1, h_offset, i__1, i__2, i__3;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(), d_sign();

    /* Local variables */
    static doublereal zero;
    static integer i, j, k, l, m;
    static doublereal p, q, r, s, t, w, x, y;
    static integer na, en, ll, mm;
    static doublereal zz;
    static logical notlas;
    static integer mp2, its, enm2;

/*     ***************** */
/* VYPOCET CHARAKTERISTICKYCH CISEL REALNE HORNI */
/* HESSENBERGOVY MATICE */
/*     28.1.1980 */
    /* Parameter adjustments */
    --wi;
    --wr;
    h_dim1 = *ndim;
    h_offset = h_dim1 + 1;
    h -= h_offset;

    /* Function Body */
    zero = 9.0949470177292824e-13;
    *ind = 0;
/* ULOZENI CISEL IZOLOVANYCH PODPROGRAMEM BALAN */
    i__1 = *n;
    for (i = 1; i <= i__1; ++i) {
	if (i >= *low && i <= *igh) {
	    goto L50;
	}
	wr[i] = h[i + i * h_dim1];
	wi[i] = 0.;
L50:
	;
    }
    en = *igh;
    t = 0.;
/* HLEDANI DALSICH CHARAKTERISTICKYCH CISEL */
L60:
    if (en < *low) {
	return 0;
    }
    its = 0;
    na = en - 1;
    enm2 = na - 1;
/* HLEDANI MALYCH IZOLOVANYCH PRVKU POD DIAGONALOU */
L70:
    i__1 = en;
    for (ll = *low; ll <= i__1; ++ll) {
	l = en + *low - ll;
	if (l == *low) {
	    goto L100;
	}
	if ((d__1 = h[l + (l - 1) * h_dim1], abs(d__1)) <= zero * ((d__2 = h[
		l - 1 + (l - 1) * h_dim1], abs(d__2)) + (d__3 = h[l + l * 
		h_dim1], abs(d__3)))) {
	    goto L100;
	}
/* L80: */
    }
/* POSUV */
L100:
    x = h[en + en * h_dim1];
    if (l == en) {
	goto L270;
    }
    y = h[na + na * h_dim1];
    w = h[en + na * h_dim1] * h[na + en * h_dim1];
    if (l == na) {
	goto L280;
    }
    if (its == 30) {
	goto L1000;
    }
    if (its != 10 && its != 20) {
	goto L130;
    }
/* MIMORADNY POSUV */
    t += x;
    i__1 = en;
    for (i = *low; i <= i__1; ++i) {
/* L120: */
	h[i + i * h_dim1] -= x;
    }
    s = (d__1 = h[en + na * h_dim1], abs(d__1)) + (d__2 = h[na + enm2 * 
	    h_dim1], abs(d__2));
    x = s * .75;
    y = x;
    w = s * -.4375 * s;
L130:
    ++its;
/* HLEDANI DVOJIC MALYCH PRVKU POD DIAGONALOU */
    i__1 = enm2;
    for (mm = l; mm <= i__1; ++mm) {
	m = enm2 + l - mm;
	zz = h[m + m * h_dim1];
	r = x - zz;
	s = y - zz;
	p = (r * s - w) / h[m + 1 + m * h_dim1] + h[m + (m + 1) * h_dim1];
	q = h[m + 1 + (m + 1) * h_dim1] - zz - r - s;
	r = h[m + 2 + (m + 1) * h_dim1];
	s = abs(p) + abs(q) + abs(r);
	p /= s;
	q /= s;
	r /= s;
	if (m == l) {
	    goto L150;
	}
	if ((d__1 = h[m + (m - 1) * h_dim1], abs(d__1)) * (abs(q) + abs(r)) <=
		 zero * abs(p) * ((d__2 = h[m - 1 + (m - 1) * h_dim1], abs(
		d__2)) + abs(zz) + (d__3 = h[m + 1 + (m + 1) * h_dim1], abs(
		d__3)))) {
	    goto L150;
	}
/* L140: */
    }
L150:
    mp2 = m + 2;
    i__1 = en;
    for (i = mp2; i <= i__1; ++i) {
	h[i + (i - 2) * h_dim1] = 0.;
	if (i == mp2) {
	    goto L160;
	}
	h[i + (i - 3) * h_dim1] = 0.;
L160:
	;
    }
/* DVOJITY KROK QR */
    i__1 = na;
    for (k = m; k <= i__1; ++k) {
	notlas = k != na;
	if (k == m) {
	    goto L170;
	}
	p = h[k + (k - 1) * h_dim1];
	q = h[k + 1 + (k - 1) * h_dim1];
	r = 0.;
	if (notlas) {
	    r = h[k + 2 + (k - 1) * h_dim1];
	}
	x = abs(p) + abs(q) + abs(r);
	if (x == 0.) {
	    goto L260;
	}
	p /= x;
	q /= x;
	r /= x;
L170:
	d__1 = sqrt(p * p + q * q + r * r);
	s = d_sign(&d__1, &p);
	if (k == m) {
	    goto L180;
	}
	h[k + (k - 1) * h_dim1] = -s * x;
	goto L190;
L180:
	if (l != m) {
	    h[k + (k - 1) * h_dim1] = -h[k + (k - 1) * h_dim1];
	}
L190:
	p += s;
	x = p / s;
	y = q / s;
	zz = r / s;
	q /= p;
	r /= p;
/* RADKOVA MODIFIKACE */
	i__2 = en;
	for (j = k; j <= i__2; ++j) {
	    p = h[k + j * h_dim1] + q * h[k + 1 + j * h_dim1];
	    if (! notlas) {
		goto L200;
	    }
	    p += r * h[k + 2 + j * h_dim1];
	    h[k + 2 + j * h_dim1] -= p * zz;
L200:
	    h[k + 1 + j * h_dim1] -= p * y;
	    h[k + j * h_dim1] -= p * x;
/* L210: */
	}

/* Computing MIN */
	i__2 = en, i__3 = k + 3;
	j = min(i__2,i__3);
/* SLOUPCOVA MODIFIKACE */
	i__2 = j;
	for (i = l; i <= i__2; ++i) {
	    p = x * h[i + k * h_dim1] + y * h[i + (k + 1) * h_dim1];
	    if (! notlas) {
		goto L220;
	    }
	    p += zz * h[i + (k + 2) * h_dim1];
	    h[i + (k + 2) * h_dim1] -= p * r;
L220:
	    h[i + (k + 1) * h_dim1] -= p * q;
	    h[i + k * h_dim1] -= p;
/* L230: */
	}
L260:
	;
    }
    goto L70;
/* NALEZEN JEDEN KOREN */
L270:
    wr[en] = x + t;
    wi[en] = 0.;
    en = na;
    goto L60;
/* NALEZENY DVA KORENY */
L280:
    p = (y - x) / 2.;
    q = p * p + w;
    zz = sqrt((abs(q)));
    x += t;
    if (q < 0.) {
	goto L320;
    }
/* REALNA DVOJICE */
    zz = p + d_sign(&zz, &p);
    wr[na] = x + zz;
    wr[en] = wr[na];
    if (zz != 0.) {
	wr[en] = x - w / zz;
    }
    wi[na] = 0.;
    wi[en] = 0.;
    goto L330;
/* KOMPLEXNI DVOJICE */
L320:
    wr[na] = x + p;
    wr[en] = x + p;
    wi[na] = zz;
    wi[en] = -zz;
L330:
    en = enm2;
    goto L60;
/* CHYBA - PROGRAM NEKONVERGOVAL VE 30 ITERACICH */
L1000:
    *ind = en;
    return 0;
} /* qrvald_ */

