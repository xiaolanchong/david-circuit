/* po.f -- translated by f2c (version of 23 April 1993  18:34:30).
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
    doublereal parf[100];
    integer maxel, nels, net[300]	/* was [5][60] */;
    doublereal val[60];
    integer nods, newn[20], ndim, neqs, intr[20];
    doublereal x[20], a0[400]	/* was [20][20] */, b0[20], xmax[20], xdot[20]
	    , xout[20];
    integer nw;
    doublereal wk, wr[20], wi[20], coefd[20];
    integer nz;
    doublereal zk, zr[20], zi[20], coefn[20], a1[400]	/* was [20][20] */, 
	    b1[20];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__1 = 1;
static integer c__30 = 30;
static integer c__0 = 0;
static doublereal c_b170 = 1.;

/* Subroutine */ int pzn_()
{
    /* Initialized data */

    static struct {
	char e_1[44];
	real e_2;
	} equiv_48 = { {'L', 'I', 'S', 'T', 'T', 'R', 'A', 'N', 'E', 'N', 'D',
		 ' ', 'M', 'O', 'D', 'I', 'C', 'O', 'N', 'T', 'R', 'U', 'N', 
		' ', 'C', 'O', 'E', 'F', 'N', 'O', 'P', 'O', 'R', 'E', 'S', 
		'E', 'N', 'O', 'R', 'M', 'I', 'N', 'I', 'T'}, (float)0. };

#define con ((real *)&equiv_48)


    /* Format strings */
    static char fmt_100[] = "(2f9.5)";
    static char fmt_105[] = "(1x,\002изменение констант TOLE=\002,1pd15.5,\
3x,\002E1=\002,1pd15.5)";
    static char fmt_107[] = "(/11x,\002нормировочные значения : R0 =\002,1pd\
13.5,\002,\002,\002 OMEGA0 =\002,1pd13.5)";
    static char fmt_170[] = "(//1x,30a2//)";
    static char fmt_165[] = "(///1x,15(\002*\002),3x,\002Z\002,i3,2x,\002выч\
ислено только\002,i3,2x,\002собственных чисел\002,14(\002*\002)///)";
    static char fmt_106[] = "(////33x,\002ПЕРЕДАТОЧНАЯ ФУНКЦИЯ\002)";
    static char fmt_110[] = "(/39x,\002ПОЛЮСА\002/)";
    static char fmt_130[] = "(/39x,\002НУЛИ\002/)";
    static char fmt_135[] = "(/29x,\002НУЛИ НАЧАЛЬНЫХ УСЛОВИЙ\002/)";
    static char fmt_140[] = "(//28x,\002константа\002,1pd17.5)";
    static char fmt_150[] = "(///36x,\002КОЭФФИЦИЕНТЫ\002//22x,\002знаменате\
ль\002,23x,\002числитель\002/)";
    static char fmt_160[] = "(5x,2(10x,1pd13.5,2x,\002P **\002,i2))";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();
    double pow_di();

    /* Local variables */
    static integer idep[60], inic, icol, ncon;
    static doublereal valn[60], tole;
    extern /* Subroutine */ int nuld_();
    static integer inpt, norm, iopt;
    extern integer ierr_();
    static integer irow1, irow2, i, j;
    static logical lcoef;
    extern /* Subroutine */ int rincd_();
    static doublereal const_, e1;
    extern /* Subroutine */ int polyd_(), outpd_();
    static integer l0, l1;
    extern /* Subroutine */ int rlist_();
    static doublereal r0, omega0;
    extern /* Subroutine */ int trfin2_(), contr1_();
    static integer ii, ll;
    extern /* Subroutine */ int modifd_(), critfd_(), orderd_(), normfd_();
    static logical lpoles;
    static integer np1, key;
    extern /* Subroutine */ int nul_(), trf2_();
    static integer npp1, nzp1;

    /* Fortran I/O blocks */
    static cilist io___16 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___18 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___21 = { 0, 0, 0, fmt_107, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_170, 0 };
    static cilist io___27 = { 0, 0, 0, fmt_165, 0 };
    static cilist io___28 = { 0, 0, 0, fmt_106, 0 };
    static cilist io___29 = { 0, 0, 0, fmt_107, 0 };
    static cilist io___30 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___32 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_165, 0 };
    static cilist io___35 = { 0, 0, 0, fmt_107, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_135, 0 };
    static cilist io___38 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_135, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_150, 0 };
    static cilist io___47 = { 0, 0, 0, fmt_160, 0 };




/*     6.10.1987 */






    ncon = 11;
    l0 = 3;
    l1 = 5;

L1:
    inic = 0;
    norm = 0;
    _BLNK__1.list = 0;
    inpt = 1;
    iopt = 1;
    tole = 3e-15;
    e1 = 1e-20;
    lcoef = TRUE_;
    lpoles = TRUE_;
    nuld_(&c__1, &_BLNK__1.ndim, &c__1, _BLNK__1.coefn);
    nuld_(&c__1, &_BLNK__1.ndim, &c__1, _BLNK__1.zr);
    nuld_(&c__1, &_BLNK__1.ndim, &c__1, _BLNK__1.zi);
    nul_(&c__1, &_BLNK__1.maxel, &c__1, idep);
    _BLNK__1.zk = 1.;
    _BLNK__1.nz = 0;

    for (ii = 1; ii <= 30; ++ii) {
	contr1_(&ncon, con, &key, &_BLNK__1.inp, &_BLNK__1.iou);
	if (key != 0) {
	    goto L3;
	}
	key = ierr_(&_BLNK__1.icont, &ncon);
	goto L95;
L3:

	switch ((int)key) {
	    case 1:  goto L10;
	    case 2:  goto L15;
	    case 3:  goto L99;
	    case 4:  goto L25;
	    case 5:  goto L30;
	    case 6:  goto L50;
	    case 7:  goto L35;
	    case 8:  goto L40;
	    case 9:  goto L1;
	    case 10:  goto L42;
	    case 11:  goto L44;
	}

L10:
	rlist_(&_BLNK__1.inp, &_BLNK__1.iou, &_BLNK__1.list);
	goto L95;
/* ввод заданий на расчет PF */
L15:
	trfin2_(&_BLNK__1.icont, &_BLNK__1.nels, _BLNK__1.newn, &
		_BLNK__1.nsec, &inpt, &iopt, &_BLNK__1.ind, &_BLNK__1.inp, &
		_BLNK__1.iou);
	goto L90;

L25:
	modifd_(&_BLNK__1.nels, _BLNK__1.net, _BLNK__1.val, &_BLNK__1.ind, &
		_BLNK__1.inp, &_BLNK__1.iou);
	goto L90;

L30:
	io___16.ciunit = _BLNK__1.inp;
	s_rsfe(&io___16);
	do_fio(&c__1, (char *)&tole, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&e1, (ftnlen)sizeof(doublereal));
	e_rsfe();
	io___17.ciunit = _BLNK__1.iou;
	s_wsfe(&io___17);
	do_fio(&c__1, (char *)&tole, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&e1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L95;
/* COEF - */
L35:
	lcoef = FALSE_;
	goto L95;
/* NOPO - */
L40:
	lpoles = FALSE_;
	goto L95;
/* NORM - */
L42:
	norm = 1;
	io___18.ciunit = _BLNK__1.inp;
	s_rsfe(&io___18);
	do_fio(&c__1, (char *)&r0, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&omega0, (ftnlen)sizeof(doublereal));
	e_rsfe();
	io___21.ciunit = _BLNK__1.iou;
	s_wsfe(&io___21);
	do_fio(&c__1, (char *)&r0, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&omega0, (ftnlen)sizeof(doublereal));
	e_wsfe();
	normfd_(&_BLNK__1.nels, _BLNK__1.net, _BLNK__1.val, valn, &r0, &
		omega0);
	goto L95;
/* INIT - */
L44:
	nuld_(&c__1, &_BLNK__1.neqs, &c__1, _BLNK__1.x);
	rincd_(&_BLNK__1.nels, _BLNK__1.net, &_BLNK__1.neqs, _BLNK__1.x, 
		_BLNK__1.val, &_BLNK__1.ind, &_BLNK__1.inp, &_BLNK__1.iou);
	inic = 1;
	goto L90;
/* RUN - */
L50:
/* идентификация ввода/вывода d */
	io___23.ciunit = _BLNK__1.iou;
	s_wsfe(&io___23);
	do_fio(&c__30, (char *)&_BLNK__1.name[0], (ftnlen)sizeof(integer));
	e_wsfe();
	trf2_(&_BLNK__1.icont, &inpt, &iopt, &_BLNK__1.nels, _BLNK__1.newn, 
		_BLNK__1.net, &_BLNK__1.ndim, &_BLNK__1.nsec, _BLNK__1.msec, &
		irow1, &irow2, &icol, &_BLNK__1.ind, &_BLNK__1.iou);
	_BLNK__1.ind = ierr_(&_BLNK__1.icont, &_BLNK__1.ind);
	if (_BLNK__1.icont < 0) {
	    goto L95;
	}

/* L48: */
	if (! lpoles) {
	    goto L58;
	}
	nuld_(&c__1, &_BLNK__1.ndim, &c__1, _BLNK__1.coefd);
	nuld_(&c__1, &_BLNK__1.ndim, &c__1, _BLNK__1.wr);
	nuld_(&c__1, &_BLNK__1.ndim, &c__1, _BLNK__1.wi);
	_BLNK__1.wk = 1.;
	_BLNK__1.nw = 0;
	if (norm == 0) {
	    critfd_(&_BLNK__1.icont, &tole, &e1, &c__0, &c__0, &c__0, &
		    _BLNK__1.nels, _BLNK__1.net, _BLNK__1.val, idep, &
		    _BLNK__1.temp, &_BLNK__1.nfun, &_BLNK__1.npar, 
		    _BLNK__1.iadr, _BLNK__1.parf, &_BLNK__1.neqs, &
		    _BLNK__1.ndim, _BLNK__1.x, _BLNK__1.a0, _BLNK__1.a1, 
		    _BLNK__1.b0, _BLNK__1.b1, &_BLNK__1.nw, _BLNK__1.wr, 
		    _BLNK__1.wi, &_BLNK__1.wk, _BLNK__1.intr, &_BLNK__1.ind, &
		    _BLNK__1.list, &l0, &l1, &_BLNK__1.iou);
	}
	if (norm == 1) {
	    critfd_(&_BLNK__1.icont, &tole, &e1, &c__0, &c__0, &c__0, &
		    _BLNK__1.nels, _BLNK__1.net, valn, idep, &_BLNK__1.temp, &
		    _BLNK__1.nfun, &_BLNK__1.npar, _BLNK__1.iadr, 
		    _BLNK__1.parf, &_BLNK__1.neqs, &_BLNK__1.ndim, _BLNK__1.x,
		     _BLNK__1.a0, _BLNK__1.a1, _BLNK__1.b0, _BLNK__1.b1, &
		    _BLNK__1.nw, _BLNK__1.wr, _BLNK__1.wi, &_BLNK__1.wk, 
		    _BLNK__1.intr, &_BLNK__1.ind, &_BLNK__1.list, &l0, &l1, &
		    _BLNK__1.iou);
	}
	if (_BLNK__1.ind == 0) {
	    goto L51;
	}
	if (_BLNK__1.ind != 100) {
	    io___27.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___27);
	    do_fio(&c__1, (char *)&_BLNK__1.nw, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&_BLNK__1.ind, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	_BLNK__1.ind = ierr_(&_BLNK__1.icont, &_BLNK__1.ind);
L51:
	io___28.ciunit = _BLNK__1.iou;
	s_wsfe(&io___28);
	e_wsfe();
	if (norm == 0 || _BLNK__1.nw == 0) {
	    goto L56;
	}
	if (_BLNK__1.list < 1) {
	    goto L52;
	}
	io___29.ciunit = _BLNK__1.iou;
	s_wsfe(&io___29);
	do_fio(&c__1, (char *)&r0, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&omega0, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___30.ciunit = _BLNK__1.iou;
	s_wsfe(&io___30);
	e_wsfe();
	outpd_(&_BLNK__1.nw, &_BLNK__1.ndim, _BLNK__1.wr, _BLNK__1.wi, &
		_BLNK__1.iou);
L52:
	i__1 = _BLNK__1.nw;
	for (i = 1; i <= i__1; ++i) {
	    _BLNK__1.wr[i - 1] *= omega0;
	    _BLNK__1.wi[i - 1] *= omega0;
/* L54: */
	}
L56:
	io___32.ciunit = _BLNK__1.iou;
	s_wsfe(&io___32);
	e_wsfe();
	outpd_(&_BLNK__1.nw, &_BLNK__1.ndim, _BLNK__1.wr, _BLNK__1.wi, &
		_BLNK__1.iou);
L58:

	if (inic == 0) {
	    goto L59;
	}
	irow1 = 0;
	i__1 = _BLNK__1.neqs;
	for (ll = 1; ll <= i__1; ++ll) {
	    _BLNK__1.b0[ll - 1] = _BLNK__1.x[ll - 1];
/* L1000: */
	    _BLNK__1.b1[ll - 1] = (float)0.;
	}
L59:
	if (norm == 0) {
	    critfd_(&_BLNK__1.icont, &tole, &e1, &irow1, &irow2, &icol, &
		    _BLNK__1.nels, _BLNK__1.net, _BLNK__1.val, idep, &
		    _BLNK__1.temp, &_BLNK__1.nfun, &_BLNK__1.npar, 
		    _BLNK__1.iadr, _BLNK__1.parf, &_BLNK__1.neqs, &
		    _BLNK__1.ndim, _BLNK__1.x, _BLNK__1.a0, _BLNK__1.a1, 
		    _BLNK__1.b0, _BLNK__1.b1, &_BLNK__1.nz, _BLNK__1.zr, 
		    _BLNK__1.zi, &_BLNK__1.zk, _BLNK__1.intr, &_BLNK__1.ind, &
		    _BLNK__1.list, &l0, &l1, &_BLNK__1.iou);
	}
	if (norm == 1) {
	    critfd_(&_BLNK__1.icont, &tole, &e1, &irow1, &irow2, &icol, &
		    _BLNK__1.nels, _BLNK__1.net, valn, idep, &_BLNK__1.temp, &
		    _BLNK__1.nfun, &_BLNK__1.npar, _BLNK__1.iadr, 
		    _BLNK__1.parf, &_BLNK__1.neqs, &_BLNK__1.ndim, _BLNK__1.x,
		     _BLNK__1.a0, _BLNK__1.a1, _BLNK__1.b0, _BLNK__1.b1, &
		    _BLNK__1.nz, _BLNK__1.zr, _BLNK__1.zi, &_BLNK__1.zk, 
		    _BLNK__1.intr, &_BLNK__1.ind, &_BLNK__1.list, &l0, &l1, &
		    _BLNK__1.iou);
	}
	if (_BLNK__1.ind == 0) {
	    goto L61;
	}
	if (_BLNK__1.ind != 100) {
	    io___34.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___34);
	    do_fio(&c__1, (char *)&_BLNK__1.nw, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&_BLNK__1.ind, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	_BLNK__1.ind = ierr_(&_BLNK__1.icont, &_BLNK__1.ind);
L61:
	if (norm == 0) {
	    goto L66;
	}
	if (_BLNK__1.nz == 0) {
	    goto L65;
	}
	if (_BLNK__1.list < 1) {
	    goto L62;
	}
	io___35.ciunit = _BLNK__1.iou;
	s_wsfe(&io___35);
	do_fio(&c__1, (char *)&r0, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&omega0, (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (inic == 0) {
	    io___36.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___36);
	    e_wsfe();
	}
	if (inic != 0) {
	    io___37.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___37);
	    e_wsfe();
	}
	outpd_(&_BLNK__1.nz, &_BLNK__1.ndim, _BLNK__1.zr, _BLNK__1.zi, &
		_BLNK__1.iou);
L62:
	i__1 = _BLNK__1.nz;
	for (i = 1; i <= i__1; ++i) {
	    _BLNK__1.zr[i - 1] *= omega0;
	    _BLNK__1.zi[i - 1] *= omega0;
/* L64: */
	}
L65:
	d__1 = 1. / omega0;
	i__1 = _BLNK__1.nz - _BLNK__1.nw;
	_BLNK__1.zk = _BLNK__1.zk / _BLNK__1.wk * pow_di(&d__1, &i__1);
	_BLNK__1.wk = (float)1.;
	if (_BLNK__1.msec[iopt - 1] < 0 && _BLNK__1.net[inpt * 5 - 5] == 4) {
	    _BLNK__1.zk /= r0;
	}
	if (_BLNK__1.msec[iopt - 1] > 0 && _BLNK__1.net[inpt * 5 - 5] == 3) {
	    _BLNK__1.zk *= r0;
	}
L66:
	if (inic == 0) {
	    io___38.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___38);
	    e_wsfe();
	}
	if (inic != 0) {
	    io___39.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___39);
	    e_wsfe();
	}
	outpd_(&_BLNK__1.nz, &_BLNK__1.ndim, _BLNK__1.zr, _BLNK__1.zi, &
		_BLNK__1.iou);
/* L68: */
	if (_BLNK__1.icont < 0) {
	    goto L95;
	}
	const_ = _BLNK__1.zk / _BLNK__1.wk;
	io___41.ciunit = _BLNK__1.iou;
	s_wsfe(&io___41);
	do_fio(&c__1, (char *)&const_, (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (lcoef) {
	    goto L95;
	}
	nuld_(&c__1, &_BLNK__1.ndim, &c__1, _BLNK__1.coefn);
	nuld_(&c__1, &_BLNK__1.ndim, &c__1, _BLNK__1.coefd);

	npp1 = _BLNK__1.nw + 1;
	if (_BLNK__1.nw > 0) {
	    orderd_(&_BLNK__1.nw, _BLNK__1.wr, _BLNK__1.wi);
	}
	polyd_(&_BLNK__1.nw, &_BLNK__1.ndim, _BLNK__1.wr, _BLNK__1.wi, &npp1, 
		_BLNK__1.coefd);
	nzp1 = _BLNK__1.nz + 1;
	if (_BLNK__1.nz > 0) {
	    orderd_(&_BLNK__1.nz, _BLNK__1.zr, _BLNK__1.zi);
	}
	polyd_(&_BLNK__1.nz, &_BLNK__1.ndim, _BLNK__1.zr, _BLNK__1.zi, &nzp1, 
		_BLNK__1.coefn);
	io___44.ciunit = _BLNK__1.iou;
	s_wsfe(&io___44);
	e_wsfe();
	np1 = max(npp1,nzp1);
	i__1 = np1;
	for (i = 1; i <= i__1; ++i) {
	    j = i - 1;
	    io___47.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___47);
	    do_fio(&c__1, (char *)&_BLNK__1.coefd[i - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&_BLNK__1.coefn[i - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	    e_wsfe();
/* L80: */
	}
	goto L95;
L90:
	_BLNK__1.ind = ierr_(&_BLNK__1.icont, &_BLNK__1.ind);
L95:
	;
    }
    _BLNK__1.ind = 10;
L99:
    return 0;
} /* pzn_ */

#undef con


/* Subroutine */ int trf2_(icont, inp, nou, nels, newn, net, ndim, ny, isec, 
	irow1, irow2, icol, ind, iou)
integer *icont, *inp, *nou, *nels, *newn, *net, *ndim, *ny, *isec, *irow1, *
	irow2, *icol, *ind, *iou;
{
    /* Format strings */
    static char fmt_100[] = "(1x,\002ошибка : выход не задан\002)";
    static char fmt_110[] = "(1x,\002ошибка : вход не источник\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer ivar, i, j, ii, nod1, nod2;

    /* Fortran I/O blocks */
    static cilist io___55 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___56 = { 0, 0, 0, fmt_110, 0 };


/*     *************** */

/*     13.7.1981 */
/* PRIRAZENI VYSTUPNIHO NAPETI */
    /* Parameter adjustments */
    --isec;
    net -= 6;
    --newn;

    /* Function Body */
    *ind = 0;
    ivar = isec[*nou];
    ii = net[*inp * 5 + 1];
    if (*icont == 2) {
	goto L70;
    }
    if (ii < 3 || ii > 5) {
	goto L85;
    }
    if (ivar <= 0) {
	goto L50;
    }
    nod1 = net[ivar * 5 + 2];
    nod2 = net[ivar * 5 + 3];
    i__1 = *nels;
    for (i = 1; i <= i__1; ++i) {
	if (net[i * 5 + 2] != nod2) {
	    goto L10;
	}
	net[i * 5 + 2] = *ndim;
	goto L20;
L10:
	if (net[i * 5 + 2] == *ndim) {
	    net[i * 5 + 2] = nod2;
	}
L20:
	if (net[i * 5 + 3] != nod2) {
	    goto L30;
	}
	net[i * 5 + 3] = *ndim;
	goto L40;
L30:
	if (net[i * 5 + 3] == *ndim) {
	    net[i * 5 + 3] = nod2;
	}
L40:
	;
    }
    *icol = nod1;
    goto L60;
/* PRIRAZENI VYSTUPNIHO PROUDU */
L50:
    ivar = -ivar;
    *icol = net[ivar * 5 + 5];
L60:
/* PRIRAZENI VSTUPNIHO ZDROJE */
    *irow1 = net[*inp * 5 + 5];
    *irow2 = 0;
    if (*irow1 != 0) {
	goto L65;
    }
    *irow1 = net[*inp * 5 + 3];
    *irow2 = net[*inp * 5 + 2];
L65:
    if (ii != 5) {
	goto L90;
    }
/* ER */
    j = net[*inp * 5 + 4];
    *irow1 = net[j * 5 + 3];
    *irow2 = net[j * 5 + 2];
    goto L90;
/* BLOKOVE DIAGRAMY */
L70:
    if (ii != 106 && ii != 107) {
	goto L85;
    }
    if (newn[*inp] != 0) {
	goto L80;
    }
    io___55.ciunit = *iou;
    s_wsfe(&io___55);
    do_fio(&c__1, (char *)&(*inp), (ftnlen)sizeof(integer));
    e_wsfe();
    goto L87;
L80:
    *irow1 = newn[*inp];
    *irow2 = 0;
    *icol = newn[ivar];
    goto L90;
L85:
    io___56.ciunit = *iou;
    s_wsfe(&io___56);
    e_wsfe();
L87:
    *ind = 1;
L90:
    return 0;
} /* trf2_ */

/* Subroutine */ int trfin2_(icont, nels, newn, nsec, inp, nou, ind, input, 
	iou)
integer *icont, *nels, *newn, *nsec, *inp, *nou, *ind, *input, *iou;
{
    /* Format strings */
    static char fmt_100[] = "(2i5)";
    static char fmt_110[] = "(/\002 вход элемент номер\002,i3,\002 ,  \002\
,\002выходная величина\002,i3)";
    static char fmt_120[] = "(\002 ошибка : вход не задан\002)";
    static char fmt_140[] = "(1x,\002ошибка : выходная величина не задана\
\002)";

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();

    /* Local variables */
    static integer inp1;

    /* Fortran I/O blocks */
    static cilist io___57 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___59 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___60 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___61 = { 0, 0, 0, fmt_140, 0 };


/*     ***************** */

/*     15.7.1981 */
    /* Parameter adjustments */
    --newn;

    /* Function Body */
    io___57.ciunit = *input;
    s_rsfe(&io___57);
    do_fio(&c__1, (char *)&inp1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*nou), (ftnlen)sizeof(integer));
    e_rsfe();
    io___59.ciunit = *iou;
    s_wsfe(&io___59);
    do_fio(&c__1, (char *)&inp1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*nou), (ftnlen)sizeof(integer));
    e_wsfe();
/* L3: */
    if (inp1 > 0 && inp1 <= *nels) {
	goto L5;
    }
L4:
    io___60.ciunit = *iou;
    s_wsfe(&io___60);
    e_wsfe();
    *ind = 1;
    *inp = 0;
    goto L10;
L5:
    *inp = inp1;
    if (*icont == 1) {
	goto L10;
    }
    inp1 = newn[*inp];
    if (inp1 <= 0) {
	goto L4;
    }
    *inp = inp1;
L10:
    if (*nou > 0 && *nou <= *nsec) {
	goto L20;
    }
    *ind = 1;
    io___61.ciunit = *iou;
    s_wsfe(&io___61);
    e_wsfe();
L20:
    return 0;
} /* trfin2_ */

/* Subroutine */ int normfd_(nels, net, val, valn, r0, omega0)
integer *nels, *net;
doublereal *val, *valn, *r0, *omega0;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ityp, i;

/*     ***************** */
/* IMPEDANCNI A KMITOCTOVE NORMOVANI */
/*     20.5.1981 */
    /* Parameter adjustments */
    --valn;
    --val;
    net -= 6;

    /* Function Body */
    i__1 = *nels;
    for (i = 1; i <= i__1; ++i) {
	valn[i] = val[i];
	ityp = net[i * 5 + 1];
	if (ityp <= 0 || ityp >= 17) {
	    goto L50;
	}
	switch ((int)ityp) {
	    case 1:  goto L12;
	    case 2:  goto L10;
	    case 3:  goto L50;
	    case 4:  goto L50;
	    case 5:  goto L50;
	    case 6:  goto L10;
	    case 7:  goto L50;
	    case 8:  goto L50;
	    case 9:  goto L12;
	    case 10:  goto L50;
	    case 11:  goto L50;
	    case 12:  goto L50;
	    case 13:  goto L14;
	    case 14:  goto L16;
	    case 15:  goto L50;
	    case 16:  goto L16;
	}
L10:
	valn[i] *= *r0;
	goto L50;
L12:
	valn[i] /= *r0;
	goto L50;
L14:
	valn[i] = valn[i] * *r0 * *omega0;
	goto L50;
L16:
	valn[i] *= *omega0 / *r0;
	goto L50;
L50:
	;
    }
    return 0;
} /* normfd_ */

/* Subroutine */ int rincd_(nels, net, n, b, val, ind, inp, iou)
integer *nels, *net, *n;
doublereal *b, *val;
integer *ind, *inp, *iou;
{
    /* Format strings */
    static char fmt_100[] = "(/12x,\002начальные условия\002//12x,\002элем\
ент\002,6x,\002величина\002)";
    static char fmt_110[] = "(i5,f9.5)";
    static char fmt_120[] = "(10x,i5,3x,1pd14.5)";
    static char fmt_130[] = "(/\002 ошибка : элемент номер\002,i3,\002 не за\
дан\002)";
    static char fmt_140[] = "(/\002 ошибка : элемент номер\002,i3,\002 не C \
и не L\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
    static integer ityp, i;
    static doublereal value;
    static integer n1, n2, ne;
    static doublereal xi;
    static integer iel;

    /* Fortran I/O blocks */
    static cilist io___64 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___66 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___69 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___75 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___76 = { 0, 0, 0, fmt_140, 0 };


/*     **************** */
/* READING IN INITIAL CONDITIONS */
/*     29.9.1981 */
    /* Parameter adjustments */
    --val;
    --b;
    net -= 6;

    /* Function Body */
    *ind = 0;
    io___64.ciunit = *iou;
    s_wsfe(&io___64);
    e_wsfe();
    i__1 = *nels;
    for (i = 1; i <= i__1; ++i) {
	io___66.ciunit = *inp;
	s_rsfe(&io___66);
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&value, (ftnlen)sizeof(doublereal));
	e_rsfe();
/* CHECK END OF DATA */
	if (iel == 0) {
	    goto L99;
	}
	io___69.ciunit = *iou;
	s_wsfe(&io___69);
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&value, (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (iel < 0 || iel > *nels) {
	    goto L90;
	}
	ityp = net[iel * 5 + 1];
	if (ityp == 0) {
	    goto L90;
	}
	if (ityp != 13 && ityp != 14) {
	    goto L92;
	}
/* C OR L ELEMENT */
	ne = net[iel * 5 + 5];
/* SET INITIAL SOURCE */
	n1 = net[iel * 5 + 2];
	n2 = net[iel * 5 + 3];
	xi = val[iel] * value;
	if (ne != 0) {
	    goto L20;
	}
/* WITHOUT CURRENT EQ. */
	b[n1] += xi;
	b[n2] -= xi;
	goto L70;
/* WITH CURRENT EQ. */
L20:
	if (ityp == 14) {
	    xi = -xi;
	}
	b[ne] += xi;
	goto L70;
/* BLOCKS */
/* L50: */
/* ERROR MESSAGES */
L90:
	io___75.ciunit = *iou;
	s_wsfe(&io___75);
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	e_wsfe();
	goto L95;
L92:
	io___76.ciunit = *iou;
	s_wsfe(&io___76);
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	e_wsfe();
L95:
	*ind = 1;
L70:
	;
    }
L99:
    return 0;
} /* rincd_ */

/* Subroutine */ int critfd_(icont, tole, e1, irow1, irow2, icol, nels, net, 
	val, idep, temp, nfun, npar, iadr, parf, n, ndim, x, a0, a1, b0, b1, 
	nw, wr, wi, wk, int_, ind, list, l0, l1, iou)
integer *icont;
doublereal *tole, *e1;
integer *irow1, *irow2, *icol, *nels, *net;
doublereal *val;
integer *idep;
doublereal *temp;
integer *nfun, *npar, *iadr;
doublereal *parf;
integer *n, *ndim;
doublereal *x, *a0, *a1, *b0, *b1;
integer *nw;
doublereal *wr, *wi, *wk;
integer *int_, *ind, *list, *l0, *l1, *iou;
{
    /* Format strings */
    static char fmt_100[] = "(1x,\002ошибка : матрицу системы не удалось ред\
уцировать\002)";

    /* System generated locals */
    integer a0_dim1, a0_offset, a1_dim1, a1_offset, i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dmat_(), nuld_();
    static integer i;
    extern /* Subroutine */ int fordd_(), eigvd_(), defld1_(), forbld_();

    /* Fortran I/O blocks */
    static cilist io___78 = { 0, 0, 0, fmt_100, 0 };


/*     ***************** */
/*     VYPOCET KRITICKYCH KMITOCTU */
/*     1.11.1981 */
/* FORMULACE POPISU SOUSTAVY */
    /* Parameter adjustments */
    --int_;
    --wi;
    --wr;
    --b1;
    --b0;
    a1_dim1 = *ndim;
    a1_offset = a1_dim1 + 1;
    a1 -= a1_offset;
    a0_dim1 = *ndim;
    a0_offset = a0_dim1 + 1;
    a0 -= a0_offset;
    --x;
    --parf;
    iadr -= 4;
    --idep;
    --val;
    net -= 6;

    /* Function Body */
    nuld_(n, n, ndim, &a0[a0_offset]);
    nuld_(n, n, ndim, &a1[a1_offset]);
    if (*icont == 1) {
	fordd_(&c_b170, nels, &net[6], &val[1], &idep[1], temp, nfun, npar, &
		iadr[4], &parf[1], ndim, &x[1], &a0[a0_offset], &a1[a1_offset]
		);
    }
    if (*icont == 2) {
	forbld_(nels, ndim, &c_b170, &val[1], &net[6], nfun, npar, &iadr[4], &
		parf[1], &x[1], &a0[a0_offset], &a1[a1_offset]);
    }
    if (*irow1 <= 0) {
	goto L11;
    }
/*     ZAPIS JEDNOTKOVEHO VSTUPU V RADKU IROW */
    i__1 = *n;
    for (i = 1; i <= i__1; ++i) {
	b0[i] = 0.;
	if (i == *irow1) {
	    b0[i] = 1.;
	}
	if (i == *irow2) {
	    b0[i] = -1.;
	}
	b1[i] = 0.;
/* L10: */
    }
L11:
/*     NAHRADA VYSTUPNIHO SLOUPCE ICOL VEKTOREM */
/*     VSTUPNI PRAVE STRANY */
    if (*icol <= 0) {
	goto L21;
    }
    i__1 = *n;
    for (i = 1; i <= i__1; ++i) {
	a0[i + *icol * a0_dim1] = b0[i];
	a1[i + *icol * a1_dim1] = b1[i];
/* L20: */
    }
L21:
    if (*list < *l1) {
	goto L25;
    }
    dmat_(n, n, ndim, &a0[a0_offset], "A0      ", iou, 8L);
    dmat_(n, n, ndim, &a1[a1_offset], "A1      ", iou, 8L);
    dmat_(&c__1, n, &c__1, &b0[1], "B0      ", iou, 8L);
    dmat_(&c__1, n, &c__1, &b1[1], "B1      ", iou, 8L);
L25:
/*     REDUKCE ULOHY CHARAKTERISTICKYCH CISEL NA STANDARTNI TVAR */
    defld1_(tole, e1, n, ndim, &a1[a1_offset], &a0[a0_offset], &wr[1], &wi[1],
	     nw, wk);
    if (*wk != 0.) {
	goto L30;
    }
    *ind = 100;
    io___78.ciunit = *iou;
    s_wsfe(&io___78);
    e_wsfe();
    *nw = 0;
    return 0;
L30:
    if (*list >= *l0) {
	dmat_(n, n, ndim, &a0[a0_offset], "A0R     ", iou, 8L);
    }
    if (*nw == 0) {
	return 0;
    }
/*     VYPOCET CHARAKTERISTICKYCH CISEL */
    eigvd_(nw, ndim, &a0[a0_offset], &wr[1], &wi[1], &int_[1], ind);
    return 0;
} /* critfd_ */

/* Subroutine */ int fvald2_(nf, npar, iadr, parf, num, x, y, dy)
integer *nf, *npar, *iadr;
doublereal *parf;
integer *num;
doublereal *x, *y, *dy;
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double exp(), log(), sin(), cos(), atan(), pow_dd(), d_int(), pow_di(), 
	    d_mod();

    /* Local variables */
    static doublereal e;
    static integer i, k, n;
    static doublereal t, f2;
    static integer ia, jt, ix;
    static doublereal xkonst;

/*     **************** */
/* COMPUTATION OF FUNCTION VALUE */
/*     30.9.1981 */
/* SET ADRESS AND PARAMETER */
    /* Parameter adjustments */
    --parf;
    iadr -= 4;

    /* Function Body */
    ia = iadr[*num * 3 + 1];
    jt = iadr[*num * 3 + 2];
    n = iadr[*num * 3 + 3];
    switch ((int)jt) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
    }
/* EXPRESION */
L100:
    t = (*x - parf[ia + 2]) / parf[ia + 3];
    xkonst = parf[ia + 1] * parf[ia + 4] / parf[ia + 3];
    switch ((int)n) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
	case 6:  goto L60;
	case 7:  goto L70;
	case 8:  goto L80;
    }
L10:
    *y = abs(t);
    f2 = 1.;
    if (t < 0.) {
	f2 = -1.;
    }
    goto L90;
L20:
    *y = exp(t);
    f2 = *y;
    goto L90;
L30:
    *y = t;
    f2 = 1.;
    goto L90;
L40:
    if (t <= 0.) {
	t = 1e-30;
    }
    *y = log(t);
    f2 = 1. / t;
    goto L90;
L50:
    *y = sin(t);
    f2 = cos(t);
    goto L90;
L60:
    *y = cos(t);
    f2 = -sin(t);
    goto L90;
L70:
    *y = sin(t) / cos(t);
/* Computing 2nd power */
    d__1 = cos(t);
    f2 = 1. / (d__1 * d__1);
    goto L90;
L80:
    *y = atan(t);
/* Computing 2nd power */
    d__1 = t;
    f2 = 1. / (d__1 * d__1 + 1.);
L90:
    *dy = xkonst * f2;
    e = parf[ia + 4];
    if (e != 1.) {
	d__1 = e - 1.;
	*dy = xkonst * f2 * pow_dd(y, &d__1);
    }
    if (d_int(&e) == e) {
	i__1 = (integer) e;
	*y = pow_di(y, &i__1);
    }
    if (d_int(&e) != e) {
	*y = pow_dd(y, &e);
    }
    *y = parf[ia] + parf[ia + 1] * *y;
    goto L990;
/* POLYNOMIALS */
L200:
    *y = 0.;
    *dy = (float)0.;
    if (n == 0) {
	goto L240;
    }
    i__1 = n;
    for (i = 1; i <= i__1; ++i) {
	ix = ia + n + 1 - i;
	*y = *x * (parf[ix] + *y);
	if (i == n) {
	    goto L230;
	}
/* L210: */
	*dy = *x * ((doublereal) (ix - ia) * parf[ix] + *dy);
    }
L230:
    *dy += parf[ia + 1];
L240:
    *y += parf[ia];
    goto L990;
/* TABLES */
L300:
/* SET T TO FUNDAMENTAL PERIOD */
    t = *x;
    if (parf[ia] != 0.) {
	t = d_mod(x, &parf[ia]);
    }
    k = ia + 3;
    if (t <= parf[ia + 1]) {
	goto L320;
    }
/* FIND  CURRENT INTERVAL */
    i__1 = n;
    for (i = 2; i <= i__1; ++i) {
	k = ia + (i << 1) - 1;
/* L310: */
	if (t <= parf[k]) {
	    goto L320;
	}
    }
L320:
    *dy = (parf[k + 1] - parf[k - 1]) / (parf[k] - parf[k - 2]);
    *y = parf[k - 1] + *dy * (t - parf[k - 2]);
L990:
    return 0;
} /* fvald2_ */

/* Subroutine */ int eigvd_(n, ndim, a, wr, wi, int_, ind)
integer *n, *ndim;
doublereal *a, *wr, *wi;
integer *int_, *ind;
{
    /* System generated locals */
    integer a_dim1, a_offset;

    /* Local variables */
    extern /* Subroutine */ int hessd_(), baland_(), qrvald_();
    static integer igh, low;

/*     **************** */
/* VYPOCET CHARAKTERISTICKYCH CISEL REALNE MATICE */
/*     28.1.1980 */
/* VYVAZENI MATICE */
    /* Parameter adjustments */
    --int_;
    --wi;
    --wr;
    a_dim1 = *ndim;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    baland_(n, ndim, &a[a_offset], &low, &igh, &wr[1]);
/* REDUKCE MATICE NA HORNI HESSENBERGOVU FORMU */
    hessd_(n, ndim, &a[a_offset], &low, &igh, &int_[1]);
/* VYPOCET CHARAKTERISTICKYCH CISEL */
    qrvald_(n, ndim, &a[a_offset], &low, &igh, &wr[1], &wi[1], ind);
    return 0;
} /* eigvd_ */

/* Subroutine */ int fordd_(p, nels, net, val, idep, temp, nfun, npar, iadr, 
	parf, ndim, x, a0, a1)
doublereal *p;
integer *nels, *net;
doublereal *val;
integer *idep;
doublereal *temp;
integer *nfun, *npar, *iadr;
doublereal *parf;
integer *ndim;
doublereal *x, *a0, *a1;
{
    /* System generated locals */
    integer a0_dim1, a0_offset, a1_dim1, a1_offset, i__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer ncel, nceq, ityp, j;
    extern /* Subroutine */ int diodd_(), fvald_();
    static doublereal value, dummy;
    static integer n1, n2, na, nb, nc, nd;
    static doublereal vd;
    static integer nc1, nc2, neq;
    static doublereal val1;

/*     **************** */

/*     2.11.1981 */
    /* Parameter adjustments */
    a1_dim1 = *ndim;
    a1_offset = a1_dim1 + 1;
    a1 -= a1_offset;
    a0_dim1 = *ndim;
    a0_offset = a0_dim1 + 1;
    a0 -= a0_offset;
    --x;
    --parf;
    iadr -= 4;
    --idep;
    --val;
    net -= 6;

    /* Function Body */
    i__1 = *nels;
    for (j = 1; j <= i__1; ++j) {
	ityp = net[j * 5 + 1];
	if (ityp <= 0 || ityp > 21) {
	    goto L8900;
	}
	neq = net[j * 5 + 5];
	n1 = net[j * 5 + 2];
	n2 = net[j * 5 + 3];
	value = val[j];
	if (idep[j] > 0) {
	    fvald_(nfun, npar, &iadr[4], &parf[1], &idep[j], p, &value, &
		    dummy);
	}
	vd = x[n2] - x[n1];
	ncel = net[j * 5 + 4];
	if (ncel < 0) {
	    goto L8900;
	} else if (ncel == 0) {
	    goto L20;
	} else {
	    goto L10;
	}
L10:
	nc1 = net[ncel * 5 + 2];
	nc2 = net[ncel * 5 + 3];
	nceq = net[ncel * 5 + 5];
L20:
	if (neq != 0) {
	    goto L1000;
	}

/*              R    G    J    E   ER   IV   II   VV */
/*             VI    0    N   OA    C    L    K    M */
/*              D   CD   CB   RI   GV */
	switch ((int)ityp) {
	    case 1:  goto L100;
	    case 2:  goto L110;
	    case 3:  goto L8900;
	    case 4:  goto L8900;
	    case 5:  goto L8900;
	    case 6:  goto L150;
	    case 7:  goto L160;
	    case 8:  goto L8900;
	    case 9:  goto L8900;
	    case 10:  goto L190;
	    case 11:  goto L8900;
	    case 12:  goto L8900;
	    case 13:  goto L220;
	    case 14:  goto L8900;
	    case 15:  goto L1240;
	    case 16:  goto L1250;
	    case 17:  goto L260;
	    case 18:  goto L270;
	    case 19:  goto L280;
	    case 20:  goto L8900;
	    case 21:  goto L300;
	}
/* REZISTOR */
L100:
	value = 1. / value;
/* KONDUKTOR */
L110:
	goto L6980;
/* IV */
L150:
	nc = nc1;
	nd = nc2;
	goto L6990;
/* II */
L160:
	na = n1;
	nb = n2;
	nc = nceq;
	goto L7005;
/* NULATOR */
L190:
	a0[nceq + n1 * a0_dim1] += 1.;
	a0[nceq + n2 * a0_dim1] += -1.;
	goto L8900;
/* KAPACITOR */
L220:
	value *= *p;
	a1[n1 + n1 * a1_dim1] += value;
	a1[n1 + n2 * a1_dim1] -= value;
	a1[n2 + n1 * a1_dim1] -= value;
	a1[n2 + n2 * a1_dim1] += value;
	goto L8900;
/* DIODA */
L260:
	d__1 = -vd;
	diodd_(&c__1, &value, temp, &d__1, &value, &val1);
	goto L6980;
/* DIFUZNI KAPACITA */
L270:
	goto L8900;
/* BARIEROVA KAPACITA */
L280:
	goto L8900;
/* NELINEARITA TYPU GV */
L300:
	d__1 = -vd;
	fvald_(nfun, npar, &iadr[4], &parf[1], &net[j * 5 + 4], &d__1, &val1, 
		&value);
	goto L6980;

L1000:
/*              R    G    J    E   ER   IV   II   VV */
/*             VI    0    N   OA    C    L    K    M */
/*              D   CD   CB   RI   GV */
	switch ((int)ityp) {
	    case 1:  goto L1100;
	    case 2:  goto L1110;
	    case 3:  goto L1120;
	    case 4:  goto L1130;
	    case 5:  goto L8900;
	    case 6:  goto L1150;
	    case 7:  goto L1160;
	    case 8:  goto L1170;
	    case 9:  goto L1180;
	    case 10:  goto L8900;
	    case 11:  goto L7060;
	    case 12:  goto L1210;
	    case 13:  goto L1220;
	    case 14:  goto L1230;
	    case 15:  goto L1240;
	    case 16:  goto L1250;
	    case 17:  goto L1260;
	    case 18:  goto L1270;
	    case 19:  goto L1280;
	    case 20:  goto L1290;
	    case 21:  goto L1300;
	}
/* REZISTOR */
L1100:
	val1 = value;
	value = 1.;
	goto L7040;
/* KONDUKTOR */
L1110:
	val1 = 1.;
	goto L7040;
/* NERIZENY ZDROJ PROUDU */
L1120:
	a0[neq + neq * a0_dim1] += 1.;
	goto L7055;
/* NERIZENY ZDROJ NAPETI */
L1130:
	value = 1.;
	goto L7045;
/* IV */
L1150:
	a0[neq + neq * a0_dim1] += -1.;
	na = nc1;
	nb = nc2;
	goto L7050;
/* II */
L1160:
	a0[neq + nceq * a0_dim1] += value;
	a0[neq + neq * a0_dim1] += -1.;
	goto L7055;
/* VV */
L1170:
	na = nc2;
	nb = nc1;
	a0[neq + n1 * a0_dim1] += 1.;
	a0[neq + n2 * a0_dim1] += -1.;
	goto L7050;
/* VI */
L1180:
	a0[neq + nceq * a0_dim1] -= value;
	value = 1.;
	goto L7045;
/* OPERACNI ZESILOVAC */
L1210:
	a0[neq + nc1 * a0_dim1] += 1.;
	a0[neq + nc2 * a0_dim1] += -1.;
	goto L7060;
/* KAPACITOR */
L1220:
	value *= *p;
	a0[neq + neq * a0_dim1] += -1.;
	a1[neq + n1 * a1_dim1] += value;
	a1[neq + n2 * a1_dim1] -= value;
	goto L7045;
/* INDUKTOR */
L1230:
	value *= *p;
	a1[neq + neq * a1_dim1] -= value;
	value = 1.;
	goto L7045;
/* CINITEL VAZBY */
L1240:
	value *= sqrt(val[n1] * val[n2]);
/* VZAJEMNA INDUKTIVNI VAZBA */
L1250:
	n1 = net[n1 * 5 + 5];
	n2 = net[n2 * 5 + 5];
	value *= *p;
	a1[n1 + n2 * a1_dim1] -= value;
	a1[n2 + n1 * a1_dim1] -= value;
	goto L8900;
/* DIODA */
L1260:
	d__1 = -vd;
	diodd_(&c__1, &value, temp, &d__1, &value, &val1);
	val1 = 1.;
	goto L7040;
/* CD */
L1270:
	goto L8900;
/* CB */
L1280:
	goto L8900;
/* RI */
L1290:
	fvald_(nfun, npar, &iadr[4], &parf[1], &net[j * 5 + 4], &x[neq], &
		value, &val1);
	value = 1.;
	goto L7040;
/* GV */
L1300:
	d__1 = -vd;
	fvald_(nfun, npar, &iadr[4], &parf[1], &net[j * 5 + 4], &d__1, &val1, 
		&value);
	val1 = 1.;
	goto L7040;
L6980:
	nc = n1;
	nd = n2;
L6990:
	na = n1;
	nb = n2;
/* L7000: */
	a0[na + nd * a0_dim1] -= value;
	a0[nb + nd * a0_dim1] += value;
L7005:
	a0[na + nc * a0_dim1] += value;
	a0[nb + nc * a0_dim1] -= value;
/* L7010: */
	goto L8900;
L7040:
	a0[neq + neq * a0_dim1] -= val1;
L7045:
	na = n1;
	nb = n2;
L7050:
	a0[neq + na * a0_dim1] += value;
	a0[neq + nb * a0_dim1] -= value;
L7055:
L7060:
	a0[n1 + neq * a0_dim1] += 1.;
	a0[n2 + neq * a0_dim1] += -1.;
L8900:
	;
    }
    return 0;
} /* fordd_ */

/* Subroutine */ int forbld_(nels, ndim, p, val, net, npar, nfun, iadr, parf, 
	xold, a0, a1)
integer *nels, *ndim;
doublereal *p, *val;
integer *net, *npar, *nfun, *iadr;
doublereal *parf, *xold, *a0, *a1;
{
    /* System generated locals */
    integer a0_dim1, a0_offset, a1_dim1, a1_offset, i__1, i__2;

    /* Local variables */
    static doublereal fder, save;
    static integer ityp, ityp1, i, j, k;
    extern /* Subroutine */ int fvald_();
    static integer n0, n1, n2;
    static doublereal ra, va;
    static integer ni;
    static doublereal xf[2], xi, fu0;
    static integer noi[2], noi1, noi2;

/*     ***************** */


/*     30.9.1981 */
    /* Parameter adjustments */
    a1_dim1 = *ndim;
    a1_offset = a1_dim1 + 1;
    a1 -= a1_offset;
    a0_dim1 = *ndim;
    a0_offset = a0_dim1 + 1;
    a0 -= a0_offset;
    --xold;
    --parf;
    iadr -= 4;
    net -= 6;
    --val;

    /* Function Body */
    i__1 = *nels;
    for (i = 1; i <= i__1; ++i) {
	ityp = net[i * 5 + 1];
	if (ityp < 101 || ityp > 108) {
	    goto L99;
	}
	ityp1 = ityp - 100;
	switch ((int)ityp1) {
	    case 1:  goto L10;
	    case 2:  goto L20;
	    case 3:  goto L30;
	    case 4:  goto L40;
	    case 5:  goto L50;
	    case 6:  goto L60;
	    case 7:  goto L70;
	    case 8:  goto L80;
	}
/* NACTENI SUMATORU DO OBVODOVE MATICE */
L10:
	a0[i + i * a0_dim1] = 1.;
	va = val[i];
	for (j = 2; j <= 4; ++j) {
	    if (j >= 3) {
		va = 1.;
	    }
	    if ((i__2 = net[j + i * 5]) < 0) {
		goto L11;
	    } else if (i__2 == 0) {
		goto L14;
	    } else {
		goto L13;
	    }
L11:
	    ni = -net[j + i * 5];
	    a0[i + ni * a0_dim1] = va;
	    goto L14;
L13:
	    ni = net[j + i * 5];
	    a0[i + ni * a0_dim1] = -va;
L14:
	    ;
	}
	goto L99;
/* NACTENI NELINEARNICH FUNKCI DO MATICE A0 A B0 */
L20:
	a0[i + i * a0_dim1] = 1.;
	for (j = 2; j <= 3; ++j) {
	    k = j - 1;
	    if ((i__2 = net[j + i * 5]) < 0) {
		goto L21;
	    } else if (i__2 == 0) {
		goto L25;
	    } else {
		goto L23;
	    }
L21:
	    noi[k - 1] = -net[j + i * 5];
	    n0 = noi[k - 1];
	    xf[k - 1] = -xold[n0];
	    goto L24;
L25:
	    xf[1] = 0.;
	    noi[1] = 0;
	    goto L24;
L23:
	    noi[k - 1] = net[j + i * 5];
	    n1 = noi[k - 1];
	    xf[k - 1] = xold[n1];
L24:
	    ;
	}
	xi = xf[0] * val[i] + xf[1];
	fvald_(nfun, npar, &iadr[4], &parf[1], &net[i * 5 + 4], &xi, &fu0, &
		fder);
	noi1 = noi[0];
	a0[i + noi1 * a0_dim1] = -fder * val[i];
	noi2 = noi[1];
	if (noi[1] == 0) {
	    goto L99;
	}
	a0[i + noi2 * a0_dim1] = -fder;
/* NACTENI INTEGRATORU DO MATIC A0 A B0 */
L30:
	a1[i + i * a1_dim1] = *p;
	va = val[i];
	for (j = 2; j <= 4; ++j) {
	    if (j >= 3) {
		va = 1.;
	    }
	    if ((i__2 = net[j + i * 5]) < 0) {
		goto L33;
	    } else if (i__2 == 0) {
		goto L36;
	    } else {
		goto L35;
	    }
L33:
	    ni = -net[j + i * 5];
	    a0[i + ni * a0_dim1] = va;
	    goto L36;
L35:
	    ni = net[j + i * 5];
	    a0[i + ni * a0_dim1] = -va;
L36:
	    ;
	}
	goto L99;
/* NACTENI NASOBICKY DO MATIC A0 A B0 */
L40:
	n1 = (i__2 = net[i * 5 + 2], abs(i__2));
	n2 = (i__2 = net[i * 5 + 3], abs(i__2));
	a0[i + i * a0_dim1] = 1.;
	if ((i__2 = net[i * 5 + 2] * net[i * 5 + 3]) < 0) {
	    goto L41;
	} else if (i__2 == 0) {
	    goto L200;
	} else {
	    goto L43;
	}
L41:
	ra = 1.;
	goto L44;
L43:
	ra = -1.;
L44:
	a0[i + n1 * a0_dim1] = ra * val[i] * xold[n2];
	a0[i + n2 * a0_dim1] = ra * val[i] * xold[n1];
	goto L99;
/* NACTENI DELICKY DO MATIC A0 A B0 */
L50:
	a0[i + i * a0_dim1] = 1.;
	n1 = (i__2 = net[i * 5 + 2], abs(i__2));
	n2 = (i__2 = net[i * 5 + 3], abs(i__2));
	if ((i__2 = net[i * 5 + 2] * net[i * 5 + 3]) < 0) {
	    goto L51;
	} else if (i__2 == 0) {
	    goto L200;
	} else {
	    goto L53;
	}
L51:
	ra = 1.;
	goto L54;
L53:
	ra = -1.;
L54:
	save = xold[n2];
	if (abs(save) <= 1e-30) {
	    save = 1.;
	}
	a0[i + n1 * a0_dim1] = ra * val[i] / save;
	a0[i + n2 * a0_dim1] = ra * (-val[i]) * xold[n1] / (save * save);
	goto L99;
/* NACTENI  ZDROJE "GENE" */
L60:
	a0[i + i * a0_dim1] = 1.;
	goto L99;
/* NACTENI ZDROJE "RAMP" */
L70:
	a0[i + i * a0_dim1] = 1.;
	goto L99;
/* NACTENI DERIVATORU DO MATIC A0 A B0 */
L80:
	a0[i + i * a0_dim1] = 1.;
	va = val[i];
	for (j = 2; j <= 4; ++j) {
	    if (j >= 3) {
		va = 1.;
	    }
	    if ((i__2 = net[j + i * 5]) < 0) {
		goto L83;
	    } else if (i__2 == 0) {
		goto L86;
	    } else {
		goto L85;
	    }
L83:
	    ni = -net[j + i * 5];
	    a1[i + ni * a1_dim1] = va * *p;
	    goto L86;
L85:
	    ni = net[j + i * 5];
	    a1[i + ni * a1_dim1] = -va * *p;
L86:
	    ;
	}
L99:
	;
    }
L200:
    return 0;
} /* forbld_ */

/* Subroutine */ int diodd_(init, sat, temp, vd, gd, curd)
integer *init;
doublereal *sat, *temp, *vd, *gd, *curd;
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double exp(), log();

    /* Local variables */
    static doublereal expd, theta, vexli, rs, emc, vdd;

/*     **************** */
/* FORMULACE LINEARIZOVANEHO STATICKEHO MODELU */
/* POLOVODICOVE DIODY */
/*     1.11.1981 */
/* PARAMETRY MODELU DIODY */
    emc = 1.04;
    vdd = *vd;
    theta = 11610. / (emc * *temp);
    rs = 1.;
/* TEPLOTNI ZAVISLOST SATURACNIHO PROUDU DIODY */
/* Computing 3rd power */
    d__1 = *temp / 290., d__2 = d__1;
    *sat = *sat * (d__2 * (d__1 * d__1)) * exp((*temp - 290.) * 1.4e4 / (*
	    temp * 290.));
/* VYPOCET NAPETI PRECHODU Z EXPONENCIALNI */
/* CHARAKTERISTIKY NA LINEARNI */
    vexli = 1. / theta * (-log(rs * theta * *sat));
/* VOLBA POCATECNIHO NAPETI DIODY */
    if (*init == 0) {
	vdd = vexli / 2.;
    }
/* VYMEZENI PRACOVNI OBLASTI DIODY */
    if (vdd <= 0.) {
	vdd = 0.;
    }
    if (vdd >= vexli) {
	vdd = vexli;
    }
/* FORMULACE MODELU DIODY */
    expd = exp(theta * vdd);
    *gd = *sat * theta * expd;
    *curd = *sat * expd * (1. - theta * vdd) - *sat;
    return 0;
} /* diodd_ */

