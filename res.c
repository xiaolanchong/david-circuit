/* res.f -- translated by f2c (version of 23 April 1993  18:34:30).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer icont, ind, inp, iou, irec, irec1;
    doublereal temp;
    integer name[30], list, maxsec, nsec, msec[10], nout[10], nfun, npar, 
	    iadr[30]	/* was [3][10] */;
    doublereal parx[100];
    integer maxel, nels, net[300]	/* was [5][60] */;
    doublereal val[60];
    integer nods, newn[20], ndim, neqs, intr[20];
    doublereal x[20], a0[400]	/* was [20][20] */, b0[20], xmax[20], xdot[20]
	    , xout[20];
    integer nw;
    doublereal wk, wr[20], wi[20], coefd[20];
    integer nz;
    doublereal zk, zr[20], zi[20], coefn[20];
    integer iplot[7], namey[7];
    real y[7];
    doublereal resr[20], resi[20];
    real tabx[51], graf[357]	/* was [51][7] */, grafs[357]	/* was [51][7]
	     */, grafc[102]	/* was [51][2] */, save[250];
    doublereal p[20];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__30 = 30;
static integer c__1 = 1;
static doublereal c_b35 = 10.;
static integer c__0 = 0;
static integer c__2 = 2;
static real c_b233 = (float)0.;

/* Subroutine */ int resp_()
{
    /* Initialized data */

    static struct {
	char e_1[80];
	real e_2;
	} equiv_58 = { {'L', 'I', 'S', 'T', 'P', 'U', 'L', 'S', 'S', 'T', 'E',
		 'P', 'T', 'I', 'M', 'E', 'R', 'U', 'N', ' ', 'P', 'L', 'O', 
		'T', 'E', 'N', 'D', ' ', 'F', 'R', 'E', 'Q', 'L', 'I', 'N', 
		' ', 'L', 'O', 'G', ' ', 'T', 'A', 'B', ' ', 'B', 'A', 'N', 
		'D', 'R', 'E', ' ', ' ', 'I', 'M', ' ', ' ', 'A', 'M', 'P', 
		'L', 'D', 'B', ' ', ' ', 'F', 'A', 'Z', 'E', 'D', 'E', 'G', 
		' ', 'C', 'O', 'M', 'P', 'R', 'E', 'S', 'E'}, (float)0. };

#define con ((real *)&equiv_58)


    /* Format strings */
    static char fmt_205[] = "(//1x,30a2//)";
    static char fmt_160[] = "(1x,\002ошибка: знаменатель перед. функции = \
0\002)";
    static char fmt_150[] = "(//1x,\002константа =\002,1pe15.5/)";
    static char fmt_100[] = "(///23x,\002ЧАСТОТНАЯ ХАРАКТЕРИСТИКА  \002//1x\
,\002точка\002,2x,\002частота(гц)\002,1x,\002реальная часть\002,2x,\002мнима\
я часть,\0022x,\002амплитуда\002,4x,3x,\002фаза (гр)/\002)";
    static char fmt_105[] = "(1x,i3,1x,1p5e14.5)";
    static char fmt_110[] = "(///9x,\002ПЕРЕХОДНАЯ ХАРАКТЕРИСТИКА\002/)";
    static char fmt_120[] = "(///9x,\002импульсная характеристика\002/)";
    static char fmt_170[] = "(//11x,\002ПЕРЕДАТОЧНАЯ ХАРАКТЕРИСТИКА\002//)";
    static char fmt_175[] = "(4x,2(1pd17.5,2x,\002P **\002,i2))";
    static char fmt_180[] = "(///25x,\002КОЭФФИЦИЕНТЫ\002//15x,\002знаменате\
ль\002,15x,\002числитель\002/1x)";
    static char fmt_190[] = "(//11x,\002константа = \002,1pe13.5///1x,\002от\
вет содержит в момент\002,1pe13.5,4x,/4x,\002производную импульса дирака \
:\002/5x,\002пор. производн.\002,5x,\002коэффициент\002/)";
    static char fmt_195[] = "(9x,i4,12x,1pd13.5)";
    static char fmt_200[] = "(//1x,\002в последующих вычислениях            \
                  импульс игнорируется\002//)";
    static char fmt_115[] = "(9x,\002полусимволическое выражение\002//)";
    static char fmt_130[] = "(1x,\002точка\002,3x,\002время\002,11x,\002вели\
чина\002/)";
    static char fmt_140[] = "(1x,i3,1p2e16.5)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();
    double r_lg10(), pow_dd(), pow_ri();

    /* Local variables */
    static integer kdim;
    extern /* Subroutine */ int amph_(), dmat_();
#define help ((real *)&_BLNK__1 + 1758)
    static real fmin, fmax;
    static integer ncon;
    static real tmin, tmax;
    static integer iplt;
    extern integer ierr_();
    extern /* Subroutine */ int rvar_();
    static real freq;
    extern /* Subroutine */ int nuld_();
    static integer nwtt, i, j;
    static real t, omega;
    extern /* Subroutine */ int racrd_(), tabin_(), parfd_(), lapld_(), 
	    fautd_();
    extern doublereal rlapd_();
    static integer ifreq;
    extern /* Subroutine */ int divpd_();
    static integer isaut;
    static doublereal const_;
    extern /* Subroutine */ int polyd_(), tautd_();
    static integer ipuls;
    extern /* Subroutine */ int rlist_(), contr1_();
    static integer ii;
    extern /* Subroutine */ int plotr3_();
    static integer in, np;
    static real deltaf, pp, yi, yr, deltat;
    extern /* Subroutine */ int orderd_();
    static real taumax;
    static integer ipoint, kpoint, npoint, im1, log_, key, nwp1, nzp1;

    /* Fortran I/O blocks */
    static cilist io___18 = { 0, 0, 0, fmt_205, 0 };
    static cilist io___19 = { 0, 0, 0, fmt_160, 0 };
    static cilist io___21 = { 0, 0, 0, fmt_150, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___30 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___38 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___40 = { 0, 0, 0, fmt_170, 0 };
    static cilist io___43 = { 0, 0, 0, fmt_175, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_180, 0 };
    static cilist io___45 = { 0, 0, 0, fmt_175, 0 };
    static cilist io___46 = { 0, 0, 0, fmt_190, 0 };
    static cilist io___48 = { 0, 0, 0, fmt_195, 0 };
    static cilist io___49 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___50 = { 0, 0, 0, fmt_115, 0 };
    static cilist io___51 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___52 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___53 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___55 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___56 = { 0, 0, 0, fmt_150, 0 };
    static cilist io___57 = { 0, 0, 0, fmt_205, 0 };


/*     *************** */


/*     2.10.1981 */




    ncon = 20;
    for (i = 1; i <= 250; ++i) {
/* L2: */
	_BLNK__1.save[i - 1] = help[i - 1];
    }
L1:
    _BLNK__1.list = 0;
    isaut = 1;
    tmin = (float)0.;
    tmax = (float)0.;
    npoint = 31;
    ipuls = 1;
    ifreq = 1;
    fmin = (float)0.;
    fmax = (float)0.;
    log_ = 1;
    iplt = 0;
    kdim = 51;
    for (i = 1; i <= 7; ++i) {
	_BLNK__1.iplot[i - 1] = 0;
/* L5: */
    }

    for (ii = 1; ii <= 30; ++ii) {
	contr1_(&ncon, con, &key, &_BLNK__1.inp, &_BLNK__1.iou);
	if (key != 0) {
	    goto L7;
	}
	key = ierr_(&_BLNK__1.icont, &ncon);
	goto L95;

L7:
	switch ((int)key) {
	    case 1:  goto L10;
	    case 2:  goto L15;
	    case 3:  goto L17;
	    case 4:  goto L20;
	    case 5:  goto L50;
	    case 6:  goto L85;
	    case 7:  goto L99;
	    case 8:  goto L25;
	    case 9:  goto L30;
	    case 10:  goto L32;
	    case 11:  goto L34;
	    case 12:  goto L36;
	    case 13:  goto L38;
	    case 14:  goto L38;
	    case 15:  goto L38;
	    case 16:  goto L38;
	    case 17:  goto L38;
	    case 18:  goto L38;
	    case 19:  goto L38;
	    case 20:  goto L1;
	}

L10:
	rlist_(&_BLNK__1.inp, &_BLNK__1.iou, &_BLNK__1.list);
	goto L95;

L15:
	ipuls = 1;
	goto L18;

L17:
	ipuls = 0;
L18:
	if (tmax == (float)0.) {
	    isaut = 1;
	}
/* L19: */
	ifreq = 0;
	goto L95;

L20:
	isaut = 0;
	rvar_(&tmin, &tmax, &npoint, &kdim, &_BLNK__1.ind, &_BLNK__1.inp, &
		_BLNK__1.iou);
	goto L90;

L25:
	if (fmax == (float)0.) {
	    isaut = 1;
	}
	ifreq = 1;
	goto L95;

L30:
	log_ = 0;
	goto L95;

L32:
	log_ = 1;
	goto L95;

L34:
	log_ = 2;
	tabin_(&kdim, _BLNK__1.tabx, &npoint, &_BLNK__1.inp, &_BLNK__1.iou, &
		_BLNK__1.ind);
	goto L90;
L36:

	isaut = 0;
	rvar_(&fmin, &fmax, &npoint, &kdim, &_BLNK__1.ind, &_BLNK__1.inp, &
		_BLNK__1.iou);
	goto L90;

L38:
	iplt = 1;
	_BLNK__1.iplot[key - 13] = 1;
	goto L95;

L50:
	io___18.ciunit = _BLNK__1.iou;
	s_wsfe(&io___18);
	do_fio(&c__30, (char *)&_BLNK__1.name[0], (ftnlen)sizeof(integer));
	e_wsfe();
	if (_BLNK__1.icont < 0) {
	    goto L95;
	}

	if (_BLNK__1.wk != 0.) {
	    goto L53;
	}
	io___19.ciunit = _BLNK__1.iou;
	s_wsfe(&io___19);
	e_wsfe();
	_BLNK__1.ind = 1;
	goto L95;
L53:
	const_ = _BLNK__1.zk / _BLNK__1.wk;
	if (_BLNK__1.nz != 0 || _BLNK__1.nw != 0) {
	    goto L51;
	}
	io___21.ciunit = _BLNK__1.iou;
	s_wsfe(&io___21);
	do_fio(&c__1, (char *)&const_, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L95;
L51:

	if (_BLNK__1.nw > 0) {
	    orderd_(&_BLNK__1.nw, _BLNK__1.wr, _BLNK__1.wi);
	}
	if (_BLNK__1.nz > 0) {
	    orderd_(&_BLNK__1.nz, _BLNK__1.zr, _BLNK__1.zi);
	}
	if (ifreq == 0) {
	    goto L70;
	}

	if (isaut != 1) {
	    goto L52;
	}
	fautd_(&_BLNK__1.nw, _BLNK__1.wr, _BLNK__1.wi, &_BLNK__1.nz, 
		_BLNK__1.zr, _BLNK__1.zi, &fmin, &fmax);
	fmin /= (float)2.;
	fmax *= (float)2.;
L52:
	if (fmin == fmax) {
	    fmax = (float)1.;
	}
	if (fmin == (float)0. && log_ == 1) {
	    fmin = fmax * (float)1e-6;
	}

	if (log_ == 0) {
	    deltaf = (fmax - fmin) / (real) (npoint - 1);
	}
	if (log_ == 1) {
	    d__1 = (doublereal) ((r_lg10(&fmax) - r_lg10(&fmin)) / (real) (
		    npoint - 1));
	    deltaf = pow_dd(&c_b35, &d__1);
	}

	io___23.ciunit = _BLNK__1.iou;
	s_wsfe(&io___23);
	e_wsfe();
	i__1 = npoint;
	for (kpoint = 1; kpoint <= i__1; ++kpoint) {
	    ipoint = kpoint;

	    if (log_ == 0) {
		freq = fmin + deltaf * (real) (ipoint - 1);
	    }
	    if (log_ == 1) {
		i__2 = ipoint - 1;
		freq = fmin * pow_ri(&deltaf, &i__2);
	    }
	    if (log_ == 2) {
		freq = _BLNK__1.tabx[ipoint - 1];
	    }
	    omega = freq * (float)6.2831853;

	    racrd_(&_BLNK__1.ndim, &_BLNK__1.nw, _BLNK__1.wr, _BLNK__1.wi, &
		    _BLNK__1.nz, _BLNK__1.zr, _BLNK__1.zi, &omega, &yr, &yi);

	    yr = const_ * yr;
	    yi *= const_;

	    amph_(&yr, &yi, &_BLNK__1.y[2], &_BLNK__1.y[4], &_BLNK__1.y[3], &
		    _BLNK__1.y[5]);
	    _BLNK__1.y[0] = yr;
	    _BLNK__1.y[1] = yi;
	    _BLNK__1.y[6] = omega;

	    io___30.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___30);
	    do_fio(&c__1, (char *)&ipoint, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&freq, (ftnlen)sizeof(real));
	    for (i = 1; i <= 3; ++i) {
		do_fio(&c__1, (char *)&_BLNK__1.y[i - 1], (ftnlen)sizeof(real)
			);
	    }
	    do_fio(&c__1, (char *)&_BLNK__1.y[5], (ftnlen)sizeof(real));
	    e_wsfe();

	    for (i = 1; i <= 6; ++i) {
		_BLNK__1.grafs[ipoint + i * 51 - 52] = _BLNK__1.y[i - 1];
/* L55: */
	    }
	    _BLNK__1.grafs[ipoint + 305] = freq;
/* L60: */
	}
	goto L90;

L70:
	np = 0;
	polyd_(&_BLNK__1.nz, &_BLNK__1.ndim, _BLNK__1.zr, _BLNK__1.zi, &nzp1, 
		_BLNK__1.coefn);
	nwtt = _BLNK__1.nw;
	nwp1 = _BLNK__1.nw + 1;
	if (ipuls == 1) {
	    goto L1071;
	}
	nwtt = nwp1;
	_BLNK__1.wr[nwtt - 1] = (float)0.;
	_BLNK__1.wi[nwtt - 1] = (float)0.;
	orderd_(&nwtt, _BLNK__1.wr, _BLNK__1.wi);
L1071:
	polyd_(&nwtt, &_BLNK__1.ndim, _BLNK__1.wr, _BLNK__1.wi, &nwp1, 
		_BLNK__1.coefd);
	if (nwtt > _BLNK__1.nz) {
	    goto L71;
	}

	i__1 = _BLNK__1.nz + 1;
	divpd_(_BLNK__1.coefn, &i__1, _BLNK__1.coefd, &nwp1, _BLNK__1.p, &np);
	_BLNK__1.nz = nwtt - 1;
L71:
	const_ = _BLNK__1.zk / _BLNK__1.wk;

	if (isaut != 1) {
	    goto L74;
	}
	tautd_(&nwtt, _BLNK__1.wr, &taumax);
	tmax = taumax * (float)2.;
L74:

	if (log_ != 2) {
	    deltat = (tmax - tmin) / (real) (npoint - 1);
	}
	nuld_(&c__1, &_BLNK__1.ndim, &c__1, _BLNK__1.resr);
	nuld_(&c__1, &_BLNK__1.ndim, &c__1, _BLNK__1.resi);
	nwp1 = nwtt + 1;
	nzp1 = _BLNK__1.nz + 1;
	i__1 = nzp1;
	for (i = 1; i <= i__1; ++i) {
	    j = nwp1 - i;
	    _BLNK__1.resr[j - 1] = _BLNK__1.coefn[i - 1];
/* L76: */
	}

	parfd_(&nwtt, _BLNK__1.wr, _BLNK__1.wi, _BLNK__1.resr, _BLNK__1.resi);
	if (_BLNK__1.list < 1) {
	    goto L78;
	}
	dmat_(&c__1, &nwtt, &c__1, _BLNK__1.resr, "RESR    ", &_BLNK__1.iou, 
		8L);
	dmat_(&c__1, &nwtt, &c__1, _BLNK__1.resi, "RESI    ", &_BLNK__1.iou, 
		8L);
L78:


	i__1 = nwtt;
	for (i = 1; i <= i__1; ++i) {
	    _BLNK__1.resr[i - 1] *= const_;
	    _BLNK__1.resi[i - 1] *= const_;
/* L79: */
	}
	if (ipuls == 0) {
	    io___38.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___38);
	    e_wsfe();
	}
	if (ipuls == 1) {
	    io___39.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___39);
	    e_wsfe();
	}
/* если степ. числ. > степ.знам. */
/* N(P)/M(P)=p(P)+R(P)/Q(P) */
	if (np == 0) {
	    goto L1279;
	}
/* печать p(P) */
	io___40.ciunit = _BLNK__1.iou;
	s_wsfe(&io___40);
	e_wsfe();
	i__1 = np;
	for (i = 1; i <= i__1; ++i) {
	    im1 = i - 1;
	    in = im1 + np;
/* печать R(P)  и  Q(P) */
/* L1100: */
	    io___43.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___43);
	    do_fio(&c__1, (char *)&_BLNK__1.p[in - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&im1, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	io___44.ciunit = _BLNK__1.iou;
	s_wsfe(&io___44);
	e_wsfe();
	i__1 = nwp1;
	for (i = 1; i <= i__1; ++i) {
	    im1 = i - 1;
/* L1110: */
	    io___45.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___45);
	    do_fio(&c__1, (char *)&_BLNK__1.coefd[i - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&im1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&_BLNK__1.coefn[i - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&im1, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	io___46.ciunit = _BLNK__1.iou;
	s_wsfe(&io___46);
	do_fio(&c__1, (char *)&const_, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tmin, (ftnlen)sizeof(real));
	e_wsfe();
/* печать сообщ. */
	i__1 = np;
	for (i = 1; i <= i__1; ++i) {
	    pp = _BLNK__1.p[i - 1] * const_;
	    im1 = i - 1;
/* L1120: */
	    io___48.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___48);
	    do_fio(&c__1, (char *)&im1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&pp, (ftnlen)sizeof(real));
	    e_wsfe();
	}
	io___49.ciunit = _BLNK__1.iou;
	s_wsfe(&io___49);
	e_wsfe();
/* печать оригинала в полусимв. */
L1279:
	io___50.ciunit = _BLNK__1.iou;
	s_wsfe(&io___50);
	e_wsfe();
	lapld_(&nwtt, _BLNK__1.wr, _BLNK__1.wi, _BLNK__1.resr, _BLNK__1.resi, 
		&_BLNK__1.iou);

	if (ipuls == 0) {
	    io___51.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___51);
	    e_wsfe();
	}
	if (ipuls == 1) {
	    io___52.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___52);
	    e_wsfe();
	}
	io___53.ciunit = _BLNK__1.iou;
	s_wsfe(&io___53);
	e_wsfe();

	i__1 = npoint;
	for (kpoint = 1; kpoint <= i__1; ++kpoint) {
	    ipoint = kpoint;
	    if (log_ != 2) {
		t = tmin + deltat * (real) (ipoint - 1);
	    }
	    if (log_ == 2) {
		t = _BLNK__1.tabx[ipoint - 1];
	    }
	    _BLNK__1.y[0] = rlapd_(&t, &nwtt, _BLNK__1.wr, _BLNK__1.wi, 
		    _BLNK__1.resr, _BLNK__1.resi);
	    io___55.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___55);
	    do_fio(&c__1, (char *)&ipoint, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&t, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&_BLNK__1.y[0], (ftnlen)sizeof(real));
	    e_wsfe();

	    _BLNK__1.graf[ipoint - 1] = _BLNK__1.y[0];
	    _BLNK__1.graf[ipoint + 50] = t;
/* L80: */
	}
	for (i = 1; i <= 250; ++i) {
/* L82: */
	    help[i - 1] = _BLNK__1.save[i - 1];
	}
	goto L90;

L85:
	if (_BLNK__1.icont < 0) {
	    goto L95;
	}
	if (_BLNK__1.nz != 0 || _BLNK__1.nw != 0) {
	    goto L87;
	}
	io___56.ciunit = _BLNK__1.iou;
	s_wsfe(&io___56);
	do_fio(&c__1, (char *)&const_, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L95;
L87:
	io___57.ciunit = _BLNK__1.iou;
	s_wsfe(&io___57);
	do_fio(&c__30, (char *)&_BLNK__1.name[0], (ftnlen)sizeof(integer));
	e_wsfe();
	if (iplt == 0) {
	    _BLNK__1.iplot[3] = 1;
	}
	plotr3_(&ifreq, &ipuls, &npoint, &log_, &tmin, &tmax, &fmin, &fmax, 
		_BLNK__1.iplot, &con[12], &kdim, _BLNK__1.graf, 
		_BLNK__1.grafs, _BLNK__1.grafc, &_BLNK__1.iou);
	iplt = 0;
	for (i = 1; i <= 7; ++i) {
	    _BLNK__1.iplot[i - 1] = 0;
/* L88: */
	}
L90:
	_BLNK__1.ind = ierr_(&_BLNK__1.icont, &_BLNK__1.ind);
L95:
	;
    }
    _BLNK__1.ind = 10;
L99:
    return 0;
} /* resp_ */

#undef help
#undef con


/* Subroutine */ int tabin_(ndim, tab, npoint, inp, iou, ind)
integer *ndim;
real *tab;
integer *npoint, *inp, *iou, *ind;
{
    /* Format strings */
    static char fmt_100[] = "(i5)";
    static char fmt_110[] = "(//8x,\002число точек\002,i5//10x,\002заданное \
значение\002//)";
    static char fmt_120[] = "(5f9.5)";
    static char fmt_130[] = "(20(1x,1p5e20.5/))";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();

    /* Local variables */
    static integer i;

    /* Fortran I/O blocks */
    static cilist io___59 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___60 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___61 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___63 = { 0, 0, 0, fmt_130, 0 };


/*     **************** */

/*     8.3.1987 */

    /* Parameter adjustments */
    --tab;

    /* Function Body */
    io___59.ciunit = *inp;
    s_rsfe(&io___59);
    do_fio(&c__1, (char *)&(*npoint), (ftnlen)sizeof(integer));
    e_rsfe();
    io___60.ciunit = *iou;
    s_wsfe(&io___60);
    do_fio(&c__1, (char *)&(*npoint), (ftnlen)sizeof(integer));
    e_wsfe();
    if (*npoint > *ndim) {
	*ind = 7;
    }
    if (*ind != 0) {
	return 0;
    }
    io___61.ciunit = *inp;
    s_rsfe(&io___61);
    i__1 = *npoint;
    for (i = 1; i <= i__1; ++i) {
	do_fio(&c__1, (char *)&tab[i], (ftnlen)sizeof(real));
    }
    e_rsfe();
    io___63.ciunit = *iou;
    s_wsfe(&io___63);
    i__1 = *npoint;
    for (i = 1; i <= i__1; ++i) {
	do_fio(&c__1, (char *)&tab[i], (ftnlen)sizeof(real));
    }
    e_wsfe();
    return 0;
} /* tabin_ */

/* Subroutine */ int rvar_(xmin, xmax, npoint, maxpnt, ind, inp, iprnt)
real *xmin, *xmax;
integer *npoint, *maxpnt, *ind, *inp, *iprnt;
{
    /* Format strings */
    static char fmt_100[] = "(2f9.5,i5)";
    static char fmt_200[] = "(//\002независимая переменная :\002//\002 миним\
ум =\002,1pe13.5,5x,\002максимум =\002,1pe13.5,5x,\002число точек =\002,i3)";
    static char fmt_300[] = "(//\002внимание:число точек исправлено на\002,i\
3)";
    static char fmt_400[] = "(//\002ошибка:максимум больше минимума\002)";

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();

    /* Fortran I/O blocks */
    static cilist io___64 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___65 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___66 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___67 = { 0, 0, 0, fmt_400, 0 };


/*     *************** */

/*     9.10.1978 */
    *ind = 0;
    io___64.ciunit = *inp;
    s_rsfe(&io___64);
    do_fio(&c__1, (char *)&(*xmin), (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&(*xmax), (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&(*npoint), (ftnlen)sizeof(integer));
    e_rsfe();
    io___65.ciunit = *iprnt;
    s_wsfe(&io___65);
    do_fio(&c__1, (char *)&(*xmin), (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&(*xmax), (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&(*npoint), (ftnlen)sizeof(integer));
    e_wsfe();
    if (*npoint > *maxpnt || *npoint <= 1) {
	io___66.ciunit = *iprnt;
	s_wsfe(&io___66);
	do_fio(&c__1, (char *)&(*maxpnt), (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (*npoint > *maxpnt || *npoint <= 1) {
	*npoint = *maxpnt;
    }
    if (*xmax <= *xmin) {
	*ind = 1;
    }
    if (*xmax <= *xmin) {
	io___67.ciunit = *iprnt;
	s_wsfe(&io___67);
	e_wsfe();
    }
    return 0;
} /* rvar_ */

/* Subroutine */ int amph_(yr, yi, yam, yph, ydb, ydg)
real *yr, *yi, *yam, *yph, *ydb, *ydg;
{
    /* Builtin functions */
    double sqrt(), r_lg10(), atan();

    /* Local variables */
    static real pi, pi2, eps;

/*     *************** */

/*     1.2.1981 */
    pi = (float)3.1415926535;
    eps = (float)1e-20;
    pi2 = pi / (float)2.;

    *yam = sqrt(*yr * *yr + *yi * *yi);
    *ydb = (float)-300.;
    if (*yam != (float)0.) {
	*ydb = r_lg10(yam) * (float)20.;
    }

    if (dabs(*yr) < eps || dabs(*yi) < eps) {
	goto L1;
    }

    *yph = atan(*yi / *yr);
    if (*yr < (float)0.) {
	goto L2;
    }
    goto L5;
L2:
    if (*yi > (float)0.) {
	*yph += pi;
    }
    if (*yi < (float)0.) {
	*yph -= pi;
    }
    goto L5;

L1:
    if (dabs(*yi) < eps && dabs(*yr) < eps) {
	goto L3;
    }
    if (dabs(*yi) < eps) {
	goto L4;
    }
    if (*yi > (float)0.) {
	*yph = pi2;
    }
    if (*yi < (float)0.) {
	*yph = -(doublereal)pi2;
    }
    goto L5;
L3:
    *yph = (float)0.;
    goto L5;
L4:
    if (*yr > (float)0.) {
	*yph = (float)0.;
    }
    if (*yr < (float)0.) {
	*yph = pi;
    }
L5:
    *ydg = *yph * (float)57.295779513;
    return 0;
} /* amph_ */

/* Subroutine */ int orderd_(n, vr, vi)
integer *n;
doublereal *vr, *vi;
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Local variables */
    static doublereal help;
    static integer i;
    static logical inter;
    static doublereal difabs;
    static integer im1;

/*     ***************** */
/* упорядочение элементов комплексного вектора по абс. */
/*     15.5.1981 */
    /* Parameter adjustments */
    --vi;
    --vr;

    /* Function Body */
    if (*n == 1) {
	return 0;
    }
L1:
    inter = FALSE_;
    i__1 = *n;
    for (i = 2; i <= i__1; ++i) {
	im1 = i - 1;
	difabs = vr[i] * vr[i] + vi[i] * vi[i] - (vr[im1] * vr[im1] + vi[im1] 
		* vi[im1]);
	if (difabs < 0.) {
	    goto L4;
	} else if (difabs == 0) {
	    goto L2;
	} else {
	    goto L10;
	}
L2:
	if ((d__1 = vi[i], abs(d__1)) != (d__2 = vi[im1], abs(d__2))) {
	    goto L10;
	}
	if (vi[i] <= vi[im1]) {
	    goto L10;
	}
/* замена I-того элем.  (I - 1)- */
L4:
	help = vr[i];
	vr[i] = vr[im1];
	vr[im1] = help;
	help = vi[i];
	vi[i] = vi[im1];
	vi[im1] = help;
	inter = TRUE_;
L10:
	;
    }
    if (inter) {
	goto L1;
    }
    return 0;
} /* orderd_ */

/* Subroutine */ int fautd_(nw, wr, wi, nz, zr, zi, fmin, fmax)
integer *nw;
doublereal *wr, *wi;
integer *nz;
doublereal *zr, *zi;
real *fmin, *fmax;
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static real absp, absz;
    static integer i;
    static real absmn, absmx;

/*     **************** */


/*     1.10.1981 */
/* poisk pol`sow s naimenx{im nenulewym absol`tnym zna~eniem */
    /* Parameter adjustments */
    --zi;
    --zr;
    --wi;
    --wr;

    /* Function Body */
    i__1 = *nw;
    for (i = 1; i <= i__1; ++i) {
	absp = wr[i] * wr[i] + wi[i] * wi[i];
	if (absp != (float)0.) {
	    goto L15;
	}
/* L10: */
    }
L15:

    absz = absp;
    if (*nz <= 0) {
	goto L25;
    }
    i__1 = *nz;
    for (i = 1; i <= i__1; ++i) {
	absz = zr[i] * zr[i] + zi[i] * zi[i];
	if (absz != (float)0.) {
	    goto L25;
	}
/* L20: */
    }
    absz = absp;
L25:

    absmn = dmin(absp,absz);
    *fmin = sqrt(absmn) / (float)6.28318;

/* L30: */
    absp = wr[*nw] * wr[*nw] + wi[*nw] * wi[*nw];
    if (*nz > 0) {
	absz = zr[*nz] * zr[*nz] + zi[*nz] * zi[*nz];
    }
    absmx = dmax(absp,absz);
    *fmax = sqrt(absmx) / (float)6.28318;
    return 0;
} /* fautd_ */

/* Subroutine */ int racrd_(ndim, nw, wr, wi, nz, zr, zi, omegas, xrs, xis)
integer *ndim, *nw;
doublereal *wr, *wi;
integer *nz;
doublereal *zr, *zi;
real *omegas, *xrs, *xis;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static doublereal help, help1, help2;
    static integer i, n;
    static doublereal omega, xi, xr;

/*     **************** */


/*     1.10.1981 */
    /* Parameter adjustments */
    --zi;
    --zr;
    --wi;
    --wr;

    /* Function Body */
    n = max(*nw,*nz);
    omega = (doublereal) (*omegas);
    xr = 1.;
    xi = 0.;
    if (n < 1) {
	goto L3;
    }
    i__1 = n;
    for (i = 1; i <= i__1; ++i) {
	if (i > *nz) {
	    goto L1;
	}
	help = xi * (zi[i] - omega) - xr * zr[i];
	xi = xr * (omega - zi[i]) - xi * zr[i];
	xr = help;
L1:
	if (i > *nw) {
	    goto L2;
	}
	help1 = wi[i] - omega;
	help2 = wr[i] * wr[i] + help1 * help1;
	help = -(xr * wr[i] + xi * help1) / help2;
	xi = (xr * help1 - xi * wr[i]) / help2;
	xr = help;
L2:
	;
    }
L3:
    *xrs = xr;
    *xis = xi;
    return 0;
} /* racrd_ */

/* Subroutine */ int divpd_(x, nx, y, ny, p, np)
doublereal *x;
integer *nx;
doublereal *y;
integer *ny;
doublereal *p;
integer *np;
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i, j, k, ik, ny1, nyk;

/*     **************** */
/* деление полиномов ( X на Y ) */
/*     1.10.1981 */
    /* Parameter adjustments */
    --p;
    --y;
    --x;

    /* Function Body */
    *np = 0;
    if (*nx < *ny) {
	goto L30;
    }
    *np = *nx - *ny + 1;
    if (*ny != 1) {
	goto L40;
    }
    i__1 = *nx;
    for (i = 1; i <= i__1; ++i) {
	j = *nx - i + 1;
/* L50: */
	p[j] = x[i] / y[1];
    }
    goto L30;
L40:
    ny1 = *ny - 1;
    i = *nx;
    i__1 = *np;
    for (j = 1; j <= i__1; ++j) {
	p[j] = x[i] / y[*ny];
	i__2 = ny1;
	for (k = 1; k <= i__2; ++k) {
	    ik = i - k;
	    nyk = *ny - k;
/* L10: */
	    x[ik] -= p[j] * y[nyk];
	}
	x[i] = (float)0.;
/* L20: */
	--i;
    }
L30:
    return 0;
} /* divpd_ */

/* Subroutine */ int tautd_(nw, wr, taumax)
integer *nw;
doublereal *wr;
real *taumax;
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Local variables */
    static real absr;
    static integer i;
    static real absrmn;

/*     **************** */


/*     1.10.1981 */

    /* Parameter adjustments */
    --wr;

    /* Function Body */
    absrmn = (float)1e10;
    i__1 = *nw;
    for (i = 1; i <= i__1; ++i) {
	absr = (r__1 = wr[i], dabs(r__1));
	if (absr == (float)0.) {
	    goto L10;
	}
	absrmn = dmin(absrmn,absr);
L10:
	;
    }
    *taumax = (float)1. / absrmn;
    return 0;
} /* tautd_ */

/* Subroutine */ int parfd_(n, pre, pim, are, aim)
integer *n;
doublereal *pre, *pim, *are, *aim;
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static doublereal zero, a, b, c;
    static integer i, j;
    static doublereal p, x, y, z, small;
    static integer i1, j1, ik, ip;
    static doublereal qq;

/*     **************** */


/*     1.10.1981 */
    /* Parameter adjustments */
    --aim;
    --are;
    --pim;
    --pre;

    /* Function Body */
    zero = 1e-5;
    small = 1e-10;
    i__1 = *n;
    for (i = 1; i <= i__1; ++i) {
	i1 = *n + 1 - i;
	if (i1 == 1) {
	    goto L3;
	}

	i__2 = i1;
	for (j = 2; j <= i__2; ++j) {
	    are[j] = are[j] + pre[i] * are[j - 1] - pim[i] * aim[j - 1];
/* L2: */
	    aim[j] = aim[j] + pre[i] * aim[j - 1] + pim[i] * are[j - 1];
	}
L3:
	i__2 = i;
	for (j = 1; j <= i__2; ++j) {
	    j1 = *n - j + 1;
/* test NASOBNOSTI pol`sow */
	    if (j == 1) {
		goto L7;
	    }
	    qq = sqrt(pre[j] * pre[j] + pim[j] * pim[j]);
	    x = (pre[j] - pre[j - 1]) / max(small,qq);
	    y = (pim[j] - pim[j - 1]) / max(small,qq);
	    z = sqrt(x * x + y * y);
	    if (z <= zero) {
		goto L6;
	    }

	    p = are[i1] - are[j1 + 1];
	    aim[i1] -= aim[j1 + 1];
	    are[i1] = p;
L7:
	    qq = sqrt(pre[j] * pre[j] + pim[j] * pim[j]);
	    x = (pre[j] - pre[i]) / max(small,qq);
	    y = (pim[j] - pim[i]) / max(small,qq);
	    z = x * x + y * y;
	    if (sqrt(z) <= zero) {
		goto L4;
	    }
	    a = pre[j] - pre[i];
	    b = pim[j] - pim[i];
	    c = a * a + b * b;
	    p = (are[j1] * a + aim[j1] * b) / c;
	    aim[j1] = (aim[j1] * a - are[j1] * b) / c;
	    are[j1] = p;
	    goto L5;
L6:
	    p = ((are[j1] - are[j1 + 1]) * a + (aim[j1] - aim[j1 + 1]) * b) / 
		    c;
	    aim[j1] = ((aim[j1] - aim[j1 + 1]) * a - (are[j1] - are[j1 + 1]) *
		     b) / c;
	    are[j1] = p;
L5:
	    ;
	}
L4:
	;
    }
    i = 1;
    ip = 1;
    ik = *n;
L8:
    if (ik <= ip) {
	goto L11;
    }
L9:
    i1 = (ik - ip) / 2 + ip;
    i__1 = i1;
    for (j = ip; j <= i__1; ++j) {
	j1 = ik - j + ip;
	x = are[j];
	y = aim[j];
	are[j] = are[j1];
	aim[j] = aim[j1];
	are[j1] = x;
	aim[j1] = y;
/* L10: */
    }
    ik = 1;
L11:
    ip = i;
    if (i >= *n) {
	return 0;
    }
L12:
    ++i;
    qq = sqrt(pre[i] * pre[i] + pim[i] * pim[i]);
    x = (pre[i] - pre[ip]) / max(small,qq);
    y = (pim[i] - pim[ip]) / max(small,qq);
    z = x * x + y * y;
    if (sqrt(z) > zero) {
	goto L8;
    }
    ik = i;
    if (i - *n >= 0) {
	goto L9;
    } else {
	goto L12;
    }
} /* parfd_ */

/* Subroutine */ int lapld_(n, wr, wi, resr, resi, iout)
integer *n;
doublereal *wr, *wi, *resr, *resi;
integer *iout;
{
    /* Format strings */
    static char fmt_102[] = "(/\002 + T**\002,i1,\002 * EXP(\002,1pd13.6,\
\002 * T) / \002,i1,\002!\002/7x,\002* (\002,1pd13.6,\002 * COS(\002,1pd13.6,\
\002 * T)\002/7x,\002+  \002,1pd13.6,\002 * SIN(\002,1pd13.6,\002 * T))\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sqrt();
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static doublereal zero;
    static integer i, k;
    static doublereal x, y, small, qq, wii, wli, wri, wlr;

    /* Fortran I/O blocks */
    static cilist io___125 = { 0, 0, 0, fmt_102, 0 };


/*     **************** */
/* полусимволический вывод оригиналов рациональной функции, */

/*     1.10.1981 */
    /* Parameter adjustments */
    --resi;
    --resr;
    --wi;
    --wr;

    /* Function Body */
    zero = 1e-5;
    small = 1e-10;
    i__1 = *n;
    for (i = 1; i <= i__1; ++i) {
	wri = wr[i];
	wii = wi[i];
	if (i == 1) {
	    goto L1;
	}
	qq = sqrt(wri * wri + wii * wii);
	x = (wri - wlr) / max(qq,small);
	y = (wii - wli) / max(qq,small);
	if (sqrt(x * x + y * y) > zero) {
	    goto L1;
	}
	++k;
	goto L4;
L1:
	k = 0;
	wlr = wri;
	wli = wii;
L4:
	io___125.ciunit = *iout;
	s_wsfe(&io___125);
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&wri, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&resr[i], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&wii, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&resi[i], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&wii, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    return 0;
} /* lapld_ */

doublereal rlapd_(t, n, wr, wi, resr, resi)
real *t;
integer *n;
doublereal *wr, *wi, *resr, *resi;
{
    /* System generated locals */
    integer i__1;
    real ret_val;

    /* Builtin functions */
    double sqrt(), exp(), cos(), sin();

    /* Local variables */
    static doublereal zero, c, e;
    static integer i, k;
    static doublereal s, x, y, small, td, qq, wii, wli, wri, sum, wlr;

/*     ************** */
/* вычисление значения оригинала рациональной функции, */

/*     1.10.1981 */
    /* Parameter adjustments */
    --resi;
    --resr;
    --wi;
    --wr;

    /* Function Body */
    zero = 1e-5;
    small = 1e-10;
    td = (doublereal) (*t);
    sum = (float)0.;
    i__1 = *n;
    for (i = 1; i <= i__1; ++i) {
	wri = wr[i];
	wii = wi[i];
	if (i == 1) {
	    goto L1;
	}
	qq = sqrt(wri * wri + wii * wii);
	x = (wri - wlr) / max(qq,small);
	y = (wii - wli) / max(qq,small);
	if (sqrt(x * x + y * y) > zero) {
	    goto L1;
	}
	e *= td;
	if (k != 0) {
	    e /= (doublereal) k;
	}
	++k;
	goto L3;
L1:
	k = 0;
	e = exp(td * wri);
	c = cos(td * wii);
	s = sin(td * wii);
	wlr = wri;
	wli = wii;
L3:
	sum += e * (resr[i] * c - resi[i] * s);
/* L4: */
    }
    ret_val = sum;
    return ret_val;
} /* rlapd_ */

/* Subroutine */ int plotr3_(ifreq, ipuls, npoint, log_, tmin, tmax, fmin, 
	fmax, iplot, con, kdim, graf, grafs, grafc, iou)
integer *ifreq, *ipuls, *npoint, *log_;
real *tmin, *tmax, *fmin, *fmax;
integer *iplot;
real *con;
integer *kdim;
real *graf, *grafs, *grafc;
integer *iou;
{
    /* Format strings */
    static char fmt_100[] = "(///20x,\002импульсная характеристика\002/)";
    static char fmt_110[] = "(///19x,\002ПЕРЕХОДНАЯ ХАРАКТЕРИСТИКА\002/)";
    static char fmt_120[] = "(16x,\002ось X: время\002,10x,\002ось Y: значен\
ия\002/)";
    static char fmt_130[] = "(///26x,\002ЧАСТОТНАЯ ХАРАКТЕРИСТИКА\002/)";
    static char fmt_140[] = "(16x,\002ось X: част\002,10x,\002ось Y: \002,\
i1,\002 ... \002,a4/(44x,i1,\002 ... \002,a4))";
    static char fmt_150[] = "(///20x,\002КОМПЛЕКСНАЯ ХАРАКТЕРИСТИКА\002/16x\
,\002ось X: RE\002,12x,\002ось Y: IM\002/)";

    /* System generated locals */
    integer graf_dim1, graf_offset, grafc_dim1, grafc_offset, grafs_dim1, 
	    grafs_offset, i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
    static integer impl, logp;
    extern /* Subroutine */ int plot_();
    static integer i, j, m, ihelp[6];
    static real yname[6];
    static integer i2, ipoint, mp1;
    static real xmn, xmx;

    /* Fortran I/O blocks */
    static cilist io___142 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___143 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___144 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___149 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___158 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___159 = { 0, 0, 0, fmt_150, 0 };


/*     ***************** */

/*     29.7.1981 */
    /* Parameter adjustments */
    grafc_dim1 = *kdim;
    grafc_offset = grafc_dim1 + 1;
    grafc -= grafc_offset;
    grafs_dim1 = *kdim;
    grafs_offset = grafs_dim1 + 1;
    grafs -= grafs_offset;
    graf_dim1 = *kdim;
    graf_offset = graf_dim1 + 1;
    graf -= graf_offset;
    --con;
    --iplot;

    /* Function Body */
    if (*ifreq == 1) {
	goto L50;
    }

    if (*ipuls == 1) {
	io___142.ciunit = *iou;
	s_wsfe(&io___142);
	e_wsfe();
    }
    if (*ipuls == 0) {
	io___143.ciunit = *iou;
	s_wsfe(&io___143);
	e_wsfe();
    }
    io___144.ciunit = *iou;
    s_wsfe(&io___144);
    e_wsfe();
    impl = 1;
    m = 1;
    xmn = *tmin;
    xmx = *tmax;
    if (*log_ != 2) {
	goto L32;
    }
    impl = 0;
    m = 2;
    xmn = (float)0.;
    xmx = (float)0.;
L32:
    plot_(&c__0, &c__0, &impl, &xmn, &xmx, &c__1, npoint, &m, kdim, &graf[
	    graf_offset], &c__1, &c__2, iou);
    goto L99;
L50:

    io___149.ciunit = *iou;
    s_wsfe(&io___149);
    e_wsfe();

    for (i = 1; i <= 6; ++i) {
	ihelp[i - 1] = 7;
/* L52: */
    }
    m = 0;
    for (i = 1; i <= 6; ++i) {
	if (iplot[i] != 1) {
	    goto L55;
	}
	++m;
	yname[m - 1] = con[i];
	ihelp[m - 1] = i;
L55:
	;
    }
    mp1 = m + 1;

    i__1 = *npoint;
    for (ipoint = 1; ipoint <= i__1; ++ipoint) {
	graf[ipoint + mp1 * graf_dim1] = grafs[ipoint + grafs_dim1 * 7];
	i__2 = m;
	for (j = 1; j <= i__2; ++j) {
	    i = ihelp[j - 1];
	    graf[ipoint + j * graf_dim1] = grafs[ipoint + i * grafs_dim1];
/* L70: */
	}
	if (iplot[7] != 1) {
	    goto L72;
	}
	grafc[ipoint + grafc_dim1] = grafs[ipoint + grafs_dim1];
	grafc[ipoint + (grafc_dim1 << 1)] = grafs[ipoint + (grafs_dim1 << 1)];
L72:
	;
    }
    if (m == 0) {
	goto L80;
    }
    impl = 1;
    xmn = *fmin;
    xmx = *fmax;
    logp = *log_;
    if (*log_ != 2) {
	goto L75;
    }
    m = mp1;
    logp = 0;
    impl = 0;
L75:
    i__1 = m;
    for (i2 = 1; i2 <= i__1; ++i2) {
	i = i2;
	io___158.ciunit = *iou;
	s_wsfe(&io___158);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&yname[i - 1], (ftnlen)sizeof(real));
	e_wsfe();
/* L76: */
    }
    plot_(&c__0, &logp, &impl, &xmn, &xmx, &c__1, npoint, &m, kdim, &graf[
	    graf_offset], &c__1, &c__2, iou);
L80:
    if (iplot[7] != 1) {
	goto L99;
    }
    io___159.ciunit = *iou;
    s_wsfe(&io___159);
    e_wsfe();
    plot_(&c__0, &c__0, &c__0, &c_b233, &c_b233, &c__1, npoint, &c__2, kdim, &
	    grafc[grafc_offset], &c__1, &c__2, iou);
L99:
    return 0;
} /* plotr3_ */

