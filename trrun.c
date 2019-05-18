/* trrun.f -- translated by f2c (version of 23 April 1993  18:34:30).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

union {
    struct {
	integer icont, ind, inp, iou, irec, irec1;
	doublereal temp;
	integer name[30], list, maxsec, nsec, msec[10], nout[10], nfun, npar, 
		iadr[30]	/* was [3][10] */;
	doublereal parf[100];
	integer maxel, nels, net[300]	/* was [5][60] */;
	doublereal val[60];
	integer nods, newn[20], ndim, neqs, intr[20];
	doublereal x[20], a0[400]	/* was [20][20] */, dx[20], xmax[20], 
		xdot[20], xout[20];
	integer maxit;
	doublereal conv, xmin, flog, stepmx, valm, feps, fluf, fpol, fmin, 
		fper;
	integer nhar, nper, iper;
	doublereal f1[64], f2[64];
	integer npf;
	doublereal tmin, tmax;
	integer npoint, maxpnt, indal, idc, kdc, isen, isect, iset, idep[60], 
		namey[20]	/* was [2][10] */, indep, namin[2], iref, iel;
	doublereal delta;
	integer nplot, mplot, iwdth, ich, ihold, mpulc[10], nstep[16];
	doublereal errk[8], sacc[8], q[340], err, err1;
	integer nq, k, k2, kmax, kmax10, kmax2;
	doublereal smin, smin1, step, step1, gama, t;
	integer ifile, init, ncon, j, i, key, ichas, imin, isec;
	doublereal tout, sout;
	integer ipoint;
    } _1;
    struct {
	integer icont, ind, inp, iou, irec, irec1;
	doublereal temp;
	integer name[30], list, maxsec, nsec, msec[10], nout[10], nfun, npar, 
		iadr[30]	/* was [3][10] */;
	doublereal parf[100];
	integer maxel, nels, net[300]	/* was [5][60] */;
	doublereal val[60];
	integer nods, newn[20], ndim, neqs, intr[20];
	doublereal x[20], a0[400]	/* was [20][20] */, b0[20], xmax[20], 
		xdot[20], xout[20];
	integer maxit;
	doublereal conv, xmin, flog, stepmx, valm, feps, fluf, fpol, fmin, 
		fper;
	integer nhar, nper, iper;
	doublereal f1[64], f2[64];
	integer npf;
	doublereal tmin, tmax;
	integer npoint, maxpnt, indal, idc, kdc, isen, isect, iset, idep[60], 
		namey[20]	/* was [2][10] */, indep, namin[2], iref, iel;
	doublereal delta;
	integer nplot, mplot, iwdth, ich, ihold, mpulc[10], nstep[16];
	doublereal errk[8], sacc[8], q[340], err, err1;
	integer nq, k, k2, kmax, kmax10, kmax2;
	doublereal smin, smin1, step, step1, p, t;
	integer ifile, init, ncon, j, i, key, ichas, imin, isec;
	doublereal tout, sout;
	integer ipoint;
    } _2;
} _BLNK__;

#define _BLNK__1 (_BLNK__._1)
#define _BLNK__2 (_BLNK__._2)

struct {
    doublereal tsw[20];
    logical pred[20], pred1[20];
} switch_;

#define switch_1 switch_

struct {
    doublereal pare[30];
    integer npare;
} c1_;

#define c1_1 c1_

/* Table of constant values */

static integer c__1 = 1;
static integer c__30 = 30;
static integer c__2 = 2;
static integer c__4 = 4;
static integer c__0 = 0;
static integer c__16 = 16;
static integer c__20 = 20;

/* Subroutine */ int tr_()
{
    /* Format strings */
    static char fmt_100[] = "(//\002 чувствительность выходных величин на эл\
емент\002,i3)";
    static char fmt_1020[] = "(//15x,30a2//)";
    static char fmt_1080[] = "(//21x,\002зависимость выходных величин от вре\
мени\002,//\002 X = время < сек >\002)";
    static char fmt_1090[] = "(//19x,\002параметрические зависимости\002/\
/\002  X = \002,2a2,i2/)";
    static char fmt_1010[] = "(/\002 после \002,i3,\002 итераций \002,\002 п\
ри T =\002,1pd12.5,5x,\002ошибка =\002,1pd12.5/)";
    static char fmt_1000[] = "(//21x,\002установившаяся рабочая точка\002)";
    static char fmt_1110[] = "(/////\002 решение \002,i2,\002. периоды\002/)";

    /* System generated locals */
    integer i__1;
    alist al__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe(), f_rew(), s_wsue(), do_uio(), e_wsue(
	    );

    /* Local variables */
    extern /* Subroutine */ int fand_(), tabd_(), secd_(), dmat_();
    extern integer ierr_();
    extern /* Subroutine */ int nuld_(), lind_(), stat_(), trin_(), pakt_(), 
	    vdel_();
    static integer kpul, n;
    extern /* Subroutine */ int bsecd_(), pertd_(), vpulc_(), forbd1_(), 
	    fortd1_(), algdfd_();
    static integer ij;
    extern /* Subroutine */ int dcalld_(), plott3_(), forlog_(), trr_();

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___4 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___5 = { 0, 0, 0, fmt_1080, 0 };
    static cilist io___6 = { 0, 0, 0, fmt_1090, 0 };
    static cilist io___7 = { 0, 0, 0, fmt_1090, 0 };
    static cilist io___8 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___9 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___10 = { 0, 0, 0, 0, 0 };
    static cilist io___12 = { 0, 0, 0, fmt_1110, 0 };


/*     ************** */

/*     10.3.1989 */




/* ввод данных секции tr */
    _BLNK__1.iset = 1;
L1:
    trr_();
    if (_BLNK__1.icont < 0 && _BLNK__1.isect != 3) {
	goto L1;
    }
    switch ((int)_BLNK__1.isect) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
    }

L10:
    goto L101;
L11:
    _BLNK__1.ind = ierr_(&_BLNK__1.icont, &_BLNK__1.ind);
    if (_BLNK__1.icont < 0) {
	goto L1;
    }
    if (_BLNK__1.nper != 0) {
	goto L20;
    }
    if (_BLNK__1.isen != 0) {
	goto L40;
    }
    goto L1;

L20:
    if (_BLNK__1.isen < 0) {
	io___1.ciunit = _BLNK__1.iou;
	s_wsfe(&io___1);
	do_fio(&c__1, (char *)&_BLNK__1.iel, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    goto L300;
L12:
    if (_BLNK__1.nper != 0) {
	goto L10;
    }
    _BLNK__1.isen = 0;
    goto L1;
L40:
    pertd_(_BLNK__1.name, &_BLNK__1.iel, &_BLNK__1.val[_BLNK__1.iel - 1], &
	    _BLNK__1.delta, &_BLNK__1.isen, &_BLNK__1.nsec, _BLNK__1.namey, &
	    _BLNK__1.npoint, &_BLNK__1.tmin, &_BLNK__1.tmax, &_BLNK__1.irec, &
	    _BLNK__1.iou);
    _BLNK__1.isen = -1;
    goto L1;
L30:
    return 0;


L101:
    if (_BLNK__1.ihold == 0 && _BLNK__1.isen == 0) {
	al__1.aerr = 0;
	al__1.aunit = _BLNK__1.irec;
	f_rew(&al__1);
    }
    for (ij = 1; ij <= 20; ++ij) {
/* L107: */
	switch_1.tsw[ij - 1] = 0.;
    }
    _BLNK__1.ifile = 0;
    if (_BLNK__1.list >= 2) {
	_BLNK__1.ifile = _BLNK__1.iou;
    }
    _BLNK__1.smin = (_BLNK__1.tmax - _BLNK__1.tmin) / _BLNK__1.xmin;
    if (_BLNK__1.stepmx == 0.) {
	_BLNK__1.stepmx = _BLNK__1.tmax - _BLNK__1.tmin;
    }
    n = _BLNK__1.neqs;
    _BLNK__1.ipoint = 1;
    _BLNK__1.init = 1;
    _BLNK__1.k = 0;
    _BLNK__1.indal = 1;
    _BLNK__1.step = _BLNK__1.smin;
    _BLNK__1.t = _BLNK__1.tmin;
    _BLNK__1.tout = _BLNK__1.tmin;
    _BLNK__1.sout = (_BLNK__1.tmax - _BLNK__1.tmin) / (real) (_BLNK__1.npoint 
	    - 1);

    if (_BLNK__1.nper != 0) {
	goto L120;
    }
    io___4.ciunit = _BLNK__1.iou;
    s_wsfe(&io___4);
    do_fio(&c__30, (char *)&_BLNK__1.name[0], (ftnlen)sizeof(integer));
    e_wsfe();
    if (_BLNK__1.kdc == 1 || _BLNK__1.kdc == 2) {
	goto L120;
    }
    if (_BLNK__1.indep < 0) {
	goto L113;
    } else if (_BLNK__1.indep == 0) {
	goto L112;
    } else {
	goto L114;
    }
L112:
    io___5.ciunit = _BLNK__1.iou;
    s_wsfe(&io___5);
    e_wsfe();
    goto L120;
L113:
    io___6.ciunit = _BLNK__1.iou;
    s_wsfe(&io___6);
    do_fio(&c__2, (char *)&_BLNK__1.namin[0], (ftnlen)sizeof(integer));
    e_wsfe();
    goto L120;
L114:
    io___7.ciunit = _BLNK__1.iou;
    s_wsfe(&io___7);
    do_fio(&c__2, (char *)&_BLNK__1.namin[0], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&_BLNK__1.indep, (ftnlen)sizeof(integer));
    e_wsfe();

L120:
    i__1 = n;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
/* L130: */
	_BLNK__1.xmax[_BLNK__1.j - 1] = 1e-20;
    }
    if (_BLNK__1.idc == 0) {
	goto L160;
    }
L140:
    algdfd_();
    switch ((int)_BLNK__1.indal) {
	case 1:  goto L200;
	case 2:  goto L145;
	case 3:  goto L145;
	case 4:  goto L150;
	case 5:  goto L160;
	case 6:  goto L141;
    }
L141:
    forlog_(&_BLNK__1.nels, _BLNK__1.net, _BLNK__1.val, &_BLNK__1.ndim, &
	    _BLNK__1.t, _BLNK__1.x, _BLNK__1.xdot);
    goto L140;
L145:

    nuld_(&n, &n, &_BLNK__1.ndim, _BLNK__1.a0);
    nuld_(&c__1, &n, &c__1, _BLNK__1.dx);
    if (_BLNK__1.indep < 0) {
	_BLNK__1.temp = _BLNK__1.t;
    }
    if (_BLNK__1.indep == 0) {
	goto L147;
    }
    _BLNK__1.gama = 0.;
    nuld_(&c__1, &n, &c__1, _BLNK__1.xdot);
    _BLNK__1.x[_BLNK__1.ndim - 1] = (float)0.;
    _BLNK__1.xdot[_BLNK__1.ndim - 1] = (float)0.;
L147:
    if (_BLNK__1.icont == 1) {
	fortd1_();
    }
/* формирование уравнений блок! */
    if (_BLNK__1.icont == 2) {
	forbd1_();
    }
    _BLNK__1.init = 0;

    if (_BLNK__1.list < 3) {
	goto L148;
    }
    dmat_(&n, &n, &_BLNK__1.ndim, _BLNK__1.a0, "A       ", &_BLNK__1.iou, 8L);
    dmat_(&c__1, &n, &c__1, _BLNK__1.dx, "B       ", &_BLNK__1.iou, 8L);

L148:
    lind_(&n, &_BLNK__1.ndim, _BLNK__1.a0, _BLNK__1.dx, _BLNK__1.intr, &
	    _BLNK__1.list, &c__4, &_BLNK__1.iou);
    if (_BLNK__1.intr[n - 1] != 0) {
	goto L140;
    }
    _BLNK__1.ind = 1;
    goto L11;

L150:
    io___8.ciunit = _BLNK__1.iou;
    s_wsfe(&io___8);
    do_fio(&c__1, (char *)&_BLNK__1.maxit, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&_BLNK__1.t, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&_BLNK__1.err, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L140;

L160:
    if (_BLNK__1.icont == 1) {
	secd_(&_BLNK__1.nsec, _BLNK__1.msec, &_BLNK__1.nels, _BLNK__1.net, &n,
		 _BLNK__1.x, _BLNK__1.xout);
    }
    if (_BLNK__1.icont == 2) {
	bsecd_(&_BLNK__1.nsec, _BLNK__1.msec, &n, _BLNK__1.newn, _BLNK__1.x, 
		_BLNK__1.xout);
    }
    if (_BLNK__1.nper != 0) {
	goto L190;
    }
    if (_BLNK__1.kdc == 0 || _BLNK__1.kdc == 3) {
	goto L185;
    }

    io___9.ciunit = _BLNK__1.iou;
    s_wsfe(&io___9);
    e_wsfe();
    tabd_("TEMP", &c__0, &_BLNK__1.temp, &_BLNK__1.nsec, _BLNK__1.namey, 
	    _BLNK__1.xout, &_BLNK__1.ipoint, &_BLNK__1.iou, 4L);
    if (_BLNK__1.kdc == 2) {
	dcalld_(_BLNK__1.net, &_BLNK__1.nels, &n, _BLNK__1.newn, &
		_BLNK__1.nods, _BLNK__1.x, &_BLNK__1.iou);
    }
    _BLNK__1.kdc = 0;
    goto L200;

L185:
    tabd_("X   ", &c__0, &_BLNK__1.tout, &_BLNK__1.nsec, _BLNK__1.namey, 
	    _BLNK__1.xout, &_BLNK__1.ipoint, &_BLNK__1.iou, 4L);

L190:
    io___10.ciunit = _BLNK__1.irec;
    s_wsue(&io___10);
    i__1 = _BLNK__1.nsec;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	do_uio(&c__1, (char *)&_BLNK__1.xout[_BLNK__1.j - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsue();
    _BLNK__1.tout += _BLNK__1.sout;
    ++_BLNK__1.ipoint;
    goto L140;

L200:
    if (_BLNK__1.list >= 1) {
	stat_(_BLNK__1.nstep, &_BLNK__1.iou);
    }

    if (_BLNK__1.kdc == 3) {
	trin_(_BLNK__1.net, &_BLNK__1.nels, &_BLNK__1.neqs, _BLNK__1.newn, &
		_BLNK__1.nods, _BLNK__1.x, &_BLNK__1.iou);
    }

    pakt_(_BLNK__1.namey, &_BLNK__1.nsec, &_BLNK__1.npoint, &_BLNK__1.nels, 
	    _BLNK__1.net, &_BLNK__1.irec, &_BLNK__1.iou);

    vdel_(_BLNK__1.namey, &_BLNK__1.nsec, &_BLNK__1.npoint, &_BLNK__1.nels, 
	    _BLNK__1.net, &_BLNK__1.irec, &_BLNK__1.iou);

    for (_BLNK__1.i = 1; _BLNK__1.i <= 1; ++_BLNK__1.i) {
	kpul = _BLNK__1.mpulc[_BLNK__1.i - 1];
/* L220: */
    }
    if (kpul != 0) {
	vpulc_(_BLNK__1.mpulc, _BLNK__1.namey, &_BLNK__1.nsec, &
		_BLNK__1.npoint, &_BLNK__1.nels, _BLNK__1.net, &_BLNK__1.iou, 
		&_BLNK__1.irec);
    }
/* период IPER  FFT */
    if (_BLNK__1.nper != 0) {
	io___12.ciunit = _BLNK__1.iou;
	s_wsfe(&io___12);
	do_fio(&c__1, (char *)&_BLNK__1.iper, (ftnlen)sizeof(integer));
	e_wsfe();
    }
/* L1100: */
    goto L11;


L300:
    if (_BLNK__1.nper != 0) {
	goto L310;
    }
    plott3_(&_BLNK__1.ich, _BLNK__1.name, _BLNK__1.namin, &_BLNK__1.indep, &
	    _BLNK__1.ihold, _BLNK__1.namey, &_BLNK__1.npoint, &_BLNK__1.nsec, 
	    &_BLNK__1.tmin, &_BLNK__1.tmax, &_BLNK__1.iwdth, &_BLNK__1.mplot, 
	    &_BLNK__1.nplot, &_BLNK__1.iou, &_BLNK__1.irec);
    _BLNK__1.ich = 0;
    _BLNK__1.ihold = 0;
    goto L320;
/* PLOT OUT ONE PERIOD OF OUTPUT WAVEFORM */
L310:
    i__1 = -_BLNK__1.npoint;
    plott3_(&c__0, _BLNK__1.name, _BLNK__1.namin, &_BLNK__1.indep, &
	    _BLNK__1.ihold, _BLNK__1.namey, &i__1, &_BLNK__1.nsec, &
	    _BLNK__1.tmin, &_BLNK__1.tmax, &_BLNK__1.iwdth, &_BLNK__1.mplot, &
	    _BLNK__1.nplot, &_BLNK__1.iou, &_BLNK__1.irec);
    i__1 = _BLNK__1.npf / 2;
    fand_(&_BLNK__1.nsec, &i__1, &_BLNK__1.nhar, _BLNK__1.f1, _BLNK__1.f2, &
	    _BLNK__1.iou, &_BLNK__1.irec);
/* COMPUTE FOURIER COEFFICIENTS AND HARMONIC DISTORTION */
    ++_BLNK__1.iper;
    if (_BLNK__1.iper > _BLNK__1.nper) {
	_BLNK__1.nper = 0;
    }
L320:
    goto L12;
} /* tr_ */

/* Subroutine */ int lind_(n, ndim, a, b, int_, list, l0, iout)
integer *n, *ndim;
doublereal *a, *b;
integer *int_, *list, *l0, *iout;
{
    /* Format strings */
    static char fmt_100[] = "(1x,\002матрица системы - сингулярна\002)";

    /* System generated locals */
    integer a_dim1, a_offset;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dmat_(), sold_();
    static integer iou;
    extern /* Subroutine */ int decd_();

    /* Fortran I/O blocks */
    static cilist io___13 = { 0, 0, 0, fmt_100, 0 };


/*     *************** */


/*     1.10.1981 */
/* ROZKLAD MATICE SOUSTAVY NA TROJUHELNIKOVE MATICE */
    /* Parameter adjustments */
    --int_;
    --b;
    a_dim1 = *ndim;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    decd_(n, ndim, &a[a_offset], &int_[1]);
    if (int_[*n] != 0) {
	goto L10;
    }
    io___13.ciunit = *iout;
    s_wsfe(&io___13);
    e_wsfe();
    return 0;
/* VYPOCET RESENI */
L10:
    sold_(n, ndim, &a[a_offset], &b[1], &int_[1]);
/* KONTROLNI TISK RESENI */
    if (*list >= *l0) {
	dmat_(&c__1, n, &c__1, &b[1], "X       ", &iou, 8L);
    }
    return 0;
} /* lind_ */

/* Subroutine */ int decd_(n, ndim, a, int_)
integer *n, *ndim;
doublereal *a;
integer *int_;
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;
    doublereal d__1, d__2;

    /* Local variables */
    static integer i, j, k, m;
    static doublereal t;
    static integer kp1;

/*     *************** */
/* ROZKLAD LU REALNE MATICE */
/*     7.1.1981 */
    /* Parameter adjustments */
    --int_;
    a_dim1 = *ndim;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    int_[*n] = 1;
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	if (k == *n) {
	    goto L5;
	}
	kp1 = k + 1;
/* VYBER KLICOVEHO PRVKU */
	m = k;
	i__2 = *n;
	for (i = kp1; i <= i__2; ++i) {
	    if ((d__1 = a[i + k * a_dim1], abs(d__1)) > (d__2 = a[m + k * 
		    a_dim1], abs(d__2))) {
		m = i;
	    }
/* L1: */
	}
	int_[k] = m;
	if (m != k) {
	    int_[*n] = -int_[*n];
	}
	t = a[m + k * a_dim1];
	a[m + k * a_dim1] = a[k + k * a_dim1];
	a[k + k * a_dim1] = t;
	if (t == 0.) {
	    goto L5;
	}
/* ROZKLAD MATICE */
	i__2 = *n;
	for (i = kp1; i <= i__2; ++i) {
/* L2: */
	    a[i + k * a_dim1] = -a[i + k * a_dim1] / t;
	}
	i__2 = *n;
	for (j = kp1; j <= i__2; ++j) {
	    t = a[m + j * a_dim1];
	    a[m + j * a_dim1] = a[k + j * a_dim1];
	    a[k + j * a_dim1] = t;
	    if (t == 0.) {
		goto L4;
	    }
	    i__3 = *n;
	    for (i = kp1; i <= i__3; ++i) {
/* L3: */
		a[i + j * a_dim1] += a[i + k * a_dim1] * t;
	    }
L4:
	    ;
	}
L5:
	if (a[k + k * a_dim1] == 0.) {
	    int_[*n] = 0;
	}
/* L6: */
    }
    return 0;
} /* decd_ */

/* Subroutine */ int sold_(n, ndim, a, b, int_)
integer *n, *ndim;
doublereal *a, *b;
integer *int_;
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    static integer i, k, m;
    static doublereal t;
    static integer km, kp, nm1, kp1;

/*     *************** */
/* RESENI SOUSTAVY LINEARNICH ALGEBRAICKYCH ROVNIC */
/* S ROZLOZENOU MATICI SOUSTAVY */
/*     1.10.1981 */
/* RESENI DOLNI TROJUHELNIKOVE SOUSTAVY */
    /* Parameter adjustments */
    --int_;
    --b;
    a_dim1 = *ndim;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    if (*n == 1) {
	goto L3;
    }
    nm1 = *n - 1;
    i__1 = nm1;
    for (k = 1; k <= i__1; ++k) {
	kp1 = k + 1;
	m = int_[k];
	t = b[m];
	b[m] = b[k];
	b[k] = t;
	i__2 = *n;
	for (i = kp1; i <= i__2; ++i) {
/* L1: */
	    b[i] += a[i + k * a_dim1] * t;
	}
    }
/* RESENI HORNI TROJUHELNIKOVE SOUSTAVY */
    i__2 = nm1;
    for (kp = 1; kp <= i__2; ++kp) {
	km = *n - kp;
	k = km + 1;
	b[k] /= a[k + k * a_dim1];
	t = -b[k];
	i__1 = km;
	for (i = 1; i <= i__1; ++i) {
/* L2: */
	    b[i] += a[i + k * a_dim1] * t;
	}
    }
L3:
    b[1] /= a[a_dim1 + 1];
    return 0;
} /* sold_ */

/* Last correction : Date 11/04/89  Time 00:55:10C */

/* Subroutine */ int algdfd_()
{
    /* Format strings */
    static char fmt_1[] = "(/\002 ALGDIF TEST 1:\002,2i6,1p3e13.5/(i5,1p4e13\
.5))";
    static char fmt_295[] = "(/\002 ALGDIF TEST 2:\002,/,8i5/8i5,/(i5,1p3e13\
.5))";
    static char fmt_296[] = "(/(2x,10l2))";
    static char fmt_299[] = "(/(2x,5(i3,1pe13.5)))";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();
    double d_sign(), log(), pow_dd();

    /* Local variables */
    static doublereal alfa, beta, dpol;
    static integer knew, n, ihelp, kbest, nkmax;
    static doublereal d1;
    static real stepo;
    static integer k1, jj;
    static doublereal ax;
    static integer jq;
    static doublereal err2;

    /* Fortran I/O blocks */
    static cilist io___30 = { 0, 0, 0, fmt_1, 0 };
    static cilist io___35 = { 0, 0, 0, fmt_295, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_296, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_299, 0 };
    static cilist io___38 = { 0, 0, 0, fmt_299, 0 };


/*     *************************************************************** */
/* AN UNIFIED ALGORITHM FOR STIFF ALGEBRAIC-DIFFERENTIAL */
/* SYSTEMS F(X,XDOT,T)=0,NONSTIFF DIFFERENTIAL SYSTEMS */
/* F(X,T)+XDOT=0 OR SEQUENTIAL ALGEBRAIC SYSTEMS F(X,T)=0.D0 */
/*     10.3.1989 */




/* BEGIN ALGDIF SELECT BY  INDALICATOR INDAL */
    n = _BLNK__1.neqs;
    if (_BLNK__1.list >= 2) {
	io___30.ciunit = _BLNK__1.iou;
	s_wsfe(&io___30);
	do_fio(&c__1, (char *)&_BLNK__1.indal, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.k, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.t, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&_BLNK__1.step, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&_BLNK__1.err, (ftnlen)sizeof(doublereal));
	i__1 = n;
	for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	    do_fio(&c__1, (char *)&_BLNK__1.j, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&_BLNK__1.x[_BLNK__1.j - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&_BLNK__1.xdot[_BLNK__1.j - 1], (ftnlen)
		    sizeof(doublereal));
	    do_fio(&c__1, (char *)&_BLNK__1.dx[_BLNK__1.j - 1], (ftnlen)
		    sizeof(doublereal));
	    do_fio(&c__1, (char *)&_BLNK__1.xmax[_BLNK__1.j - 1], (ftnlen)
		    sizeof(doublereal));
	}
	e_wsfe();
    }
    switch ((int)_BLNK__1.indal) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L210;
	case 4:  goto L290;
	case 5:  goto L400;
	case 6:  goto L280;
    }
/* INITIALIZATION */
L100:
    if (_BLNK__1.k > 0) {
	goto L410;
    }
    _BLNK__1.sacc[0] = 0.;
    _BLNK__1.sacc[1] = _BLNK__1.step;
    _BLNK__1.kmax = 6;
    _BLNK__1.kmax2 = 8;
    _BLNK__1.kmax10 = 16;
    _BLNK__1.nq = 200;
    _BLNK__1.err1 = 1.;
    _BLNK__1.valm = (float)1e-20;
    _BLNK__1.feps = 5.;
    _BLNK__1.fluf = 1.;
    _BLNK__1.fpol = 1.;
    _BLNK__1.fmin = 2.;
    _BLNK__1.gama = 0.;
    _BLNK__1.k2 = 1;
    _BLNK__1.smin1 = _BLNK__1.smin;
    _BLNK__1.k = 0;
    nkmax = n * (_BLNK__1.kmax + 2);
    i__1 = nkmax;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
/* L110: */
	_BLNK__1.q[_BLNK__1.j - 1] = 0.;
    }
    i__1 = n;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	if (_BLNK__1.xmax[_BLNK__1.j - 1] == 0.) {
	    _BLNK__1.xmax[_BLNK__1.j - 1] = _BLNK__1.valm;
	}
/* L120: */
	_BLNK__1.xdot[_BLNK__1.j - 1] = 0.;
    }
    i__1 = _BLNK__1.kmax10;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
/* L130: */
	_BLNK__1.nstep[_BLNK__1.j - 1] = 0;
    }
    _BLNK__1.indal = 2;
    if (_BLNK__1.idc == 1) {
	goto L999;
    }
/* TIME RESPONSE */
L150:
    _BLNK__1.t += _BLNK__1.step;
    _BLNK__1.gama = 1. / _BLNK__1.step;
    i__1 = n;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	_BLNK__1.q[_BLNK__1.j - 1] = _BLNK__1.x[_BLNK__1.j - 1];
/* L170: */
	if ((d__1 = _BLNK__1.x[_BLNK__1.j - 1], abs(d__1)) > _BLNK__1.xmax[
		_BLNK__1.j - 1]) {
	    _BLNK__1.xmax[_BLNK__1.j - 1] = (d__2 = _BLNK__1.x[_BLNK__1.j - 1]
		    , abs(d__2));
	}
    }
    _BLNK__1.idc = 0;
    _BLNK__1.indal = 2;
    goto L999;
/* FINDAL ERROR. CHECK ERROR AND STEP */
L200:
    ++_BLNK__1.nstep[4];
L210:
    ++_BLNK__1.nstep[1];
    _BLNK__1.err = 0.;
    i__1 = n;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	d1 = (d__1 = _BLNK__1.dx[_BLNK__1.j - 1], abs(d__1)) / _BLNK__1.xmax[
		_BLNK__1.j - 1];
/* L220: */
	if (d1 > _BLNK__1.err) {
	    _BLNK__1.err = d1;
	}
    }
/* CHECK ERROR AND STEP */
    if (_BLNK__1.err <= _BLNK__1.feps * _BLNK__1.conv) {
	goto L248;
    }
    if (_BLNK__1.step <= _BLNK__1.smin1) {
	goto L230;
    }
/* REJECTION */
    ++_BLNK__1.nstep[6];
    _BLNK__1.t -= _BLNK__1.step;
    _BLNK__1.step /= 2.;
    goto L422;
/* ITERATIONS */
L230:
    ++_BLNK__1.nstep[0];
    if (_BLNK__1.nstep[0] < _BLNK__1.maxit) {
	goto L240;
    }
/* NO CONVERGENCE */
    _BLNK__1.indal = 4;
    if (_BLNK__1.idc == 0) {
	_BLNK__1.smin1 *= _BLNK__1.fmin;
    }
    ++_BLNK__1.nstep[8];
    goto L999;
/* LOGARITHMIC DAMPING IF DIVERGENCE */
L240:
    if (_BLNK__1.err <= _BLNK__1.err1 || _BLNK__1.flog <= 0.) {
	goto L250;
    }
    ++_BLNK__1.nstep[7];
    i__1 = n;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
/* L242: */
	_BLNK__1.dx[_BLNK__1.j - 1] = d_sign(&_BLNK__1.xmax[_BLNK__1.j - 1], &
		_BLNK__1.dx[_BLNK__1.j - 1]) / _BLNK__1.flog * log(
		_BLNK__1.flog * (d__1 = _BLNK__1.dx[_BLNK__1.j - 1], abs(d__1)
		) / _BLNK__1.xmax[_BLNK__1.j - 1] + 1.);
    }
    goto L252;
/* SET SMIN1 AND ERR1 */
L248:
    _BLNK__1.smin1 = _BLNK__1.smin;
L250:
    _BLNK__1.err1 = _BLNK__1.err;
/* CORRECTIONS: X, XDOT AND XMAX */
L252:
    i__1 = n;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	_BLNK__1.x[_BLNK__1.j - 1] += _BLNK__1.dx[_BLNK__1.j - 1];
	_BLNK__1.xdot[_BLNK__1.j - 1] += _BLNK__1.gama * _BLNK__1.dx[
		_BLNK__1.j - 1];
	ax = (d__1 = _BLNK__1.x[_BLNK__1.j - 1], abs(d__1));
	if (ax > _BLNK__1.xmax[_BLNK__1.j - 1]) {
	    _BLNK__1.xmax[_BLNK__1.j - 1] = ax;
	}
	if (_BLNK__1.idc == 1 && ax > _BLNK__1.valm) {
	    _BLNK__1.xmax[_BLNK__1.j - 1] = ax;
	}
/* L260: */
	_BLNK__1.dx[_BLNK__1.j - 1] = _BLNK__1.x[_BLNK__1.j - 1];
    }
    if (_BLNK__1.err > _BLNK__1.feps * _BLNK__1.conv) {
	goto L999;
    }
    _BLNK__1.indal = 6;
    return 0;
L280:
/* STEP IS COMPLETED */
L290:
    ++_BLNK__1.nstep[2];
    ++_BLNK__1.nstep[_BLNK__1.k + 9];
    _BLNK__1.nstep[0] = 0;
    knew = _BLNK__1.k2;
    if (_BLNK__1.idc == 1) {
	_BLNK__1.indal = 5;
    }
    if (_BLNK__1.idc == 1) {
	goto L999;
    }
    if (_BLNK__1.list < 3) {
	goto L300;
    }
    io___35.ciunit = _BLNK__1.iou;
    s_wsfe(&io___35);
    do_fio(&c__16, (char *)&_BLNK__1.nstep[0], (ftnlen)sizeof(integer));
    i__1 = n;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	do_fio(&c__1, (char *)&_BLNK__1.j, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.x[_BLNK__1.j - 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&_BLNK__1.dx[_BLNK__1.j - 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&_BLNK__1.xdot[_BLNK__1.j - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    io___36.ciunit = _BLNK__1.iou;
    s_wsfe(&io___36);
    do_fio(&c__20, (char *)&switch_1.pred[0], (ftnlen)sizeof(logical));
    e_wsfe();
    if (_BLNK__1.list < 5) {
	goto L300;
    }
    io___37.ciunit = _BLNK__1.iou;
    s_wsfe(&io___37);
    i__1 = _BLNK__1.k2;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	do_fio(&c__1, (char *)&_BLNK__1.j, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.errk[_BLNK__1.j - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    io___38.ciunit = _BLNK__1.iou;
    s_wsfe(&io___38);
    i__1 = nkmax;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	do_fio(&c__1, (char *)&_BLNK__1.j, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.q[_BLNK__1.j - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
/* UPDATE BACKWARD SCALED DIFFERENCES */
L300:
    jq = 0;
    err2 = (float)1e35;
    dpol = 1.;
    alfa = 1.;
    _BLNK__1.sacc[_BLNK__1.k2] = 1.;
    i__1 = _BLNK__1.k2;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	_BLNK__1.err1 = 0.;
	i__2 = n;
	for (jj = 1; jj <= i__2; ++jj) {
	    ++jq;
	    d1 = _BLNK__1.dx[jj - 1] - alfa * _BLNK__1.q[jq - 1];
	    _BLNK__1.q[jq - 1] = _BLNK__1.dx[jj - 1];
	    _BLNK__1.dx[jj - 1] = d1;
	    d1 = abs(d1) / _BLNK__1.xmax[jj - 1];
/* L320: */
	    if (d1 > _BLNK__1.err1) {
		_BLNK__1.err1 = d1;
	    }
	}
/* INTERPOLATION ERRORS */
	_BLNK__1.errk[_BLNK__1.j - 1] = _BLNK__1.err1;
	_BLNK__1.err1 *= dpol;
	if (err2 < _BLNK__1.err1) {
	    goto L330;
	}
	err2 = _BLNK__1.err1;
	kbest = _BLNK__1.j;
L330:
	alfa = alfa * (_BLNK__1.step + _BLNK__1.sacc[_BLNK__1.j - 1]) / 
		_BLNK__1.sacc[_BLNK__1.j];
/* L332: */
	dpol *= _BLNK__1.fpol;
    }
/* SAVE K + 2 DIFFERENCE */
    i__1 = n;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	++jq;
/* L340: */
	_BLNK__1.q[jq - 1] = _BLNK__1.dx[_BLNK__1.j - 1];
    }
/* SET BEST NEW ORDER */
    if (kbest < knew) {
	knew = kbest;
    }
/* SHIFT ACCUMMULATED STEPS */
/* L390: */
    i__1 = _BLNK__1.k2;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	ihelp = _BLNK__1.k2 - _BLNK__1.j + 1;
/* L392: */
	_BLNK__1.sacc[ihelp] = _BLNK__1.sacc[ihelp - 1] + _BLNK__1.step;
    }
/* CHECK OUTPUT */
L400:
    if (_BLNK__1.idc == 1) {
	goto L150;
    }
    _BLNK__1.indal = 5;
    _BLNK__1.step1 = _BLNK__1.tout - _BLNK__1.t;
    k1 = _BLNK__1.k + 1;
    if (_BLNK__1.step1 <= _BLNK__1.smin) {
	goto L500;
    }
/* CHECK END POINT */
L410:
    _BLNK__1.indal = 1;
    if (_BLNK__1.t >= _BLNK__1.tmax - _BLNK__1.smin) {
	goto L999;
    }
/* SET INDALICATOR */
    _BLNK__1.indal = 3;
    if (_BLNK__1.err >= _BLNK__1.fluf * _BLNK__1.conv || _BLNK__1.err <= 
	    _BLNK__1.conv / _BLNK__1.fluf) {
	_BLNK__1.indal = 2;
    }
    if (_BLNK__1.err <= _BLNK__1.conv / _BLNK__1.fluf) {
	++_BLNK__1.nstep[5];
    }
/* SET NEW STEP AND ORDER */
    d1 = _BLNK__1.conv / _BLNK__1.feps;
    kbest = 1;
    i__1 = knew;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	if (_BLNK__1.errk[_BLNK__1.j - 1] < d1) {
	    _BLNK__1.errk[_BLNK__1.j - 1] = d1;
	}
	d__1 = _BLNK__1.conv / _BLNK__1.errk[_BLNK__1.j - 1];
	d__2 = 1. / (real) _BLNK__1.j;
	_BLNK__1.errk[_BLNK__1.j - 1] = pow_dd(&d__1, &d__2);
/* L420: */
	if (_BLNK__1.errk[_BLNK__1.j - 1] > _BLNK__1.errk[kbest - 1]) {
	    kbest = _BLNK__1.j;
	}
    }
    stepo = _BLNK__1.step;
    _BLNK__1.step *= _BLNK__1.errk[kbest - 1];
    if (_BLNK__1.step / stepo > 4.) {
	_BLNK__1.step = stepo * 4.;
    }
    _BLNK__1.k = kbest - 1;
L422:
    if (_BLNK__1.step < _BLNK__1.smin1) {
	_BLNK__1.step = _BLNK__1.smin1;
    }
    if (_BLNK__1.step > _BLNK__1.stepmx) {
	_BLNK__1.step = _BLNK__1.stepmx;
    }
    _BLNK__1.err1 = 1.;
    k1 = _BLNK__1.k;
    _BLNK__1.k2 = _BLNK__1.k + 2;
    if (_BLNK__1.k >= _BLNK__1.kmax) {
	_BLNK__1.k2 = _BLNK__1.k + 1;
    }
/* SET NEW TIME */
    _BLNK__1.t += _BLNK__1.step;
    if (_BLNK__1.t + _BLNK__1.step <= _BLNK__1.tmax) {
	goto L440;
    }
    if (_BLNK__1.t < _BLNK__1.tmax) {
	goto L430;
    }
    _BLNK__1.step = _BLNK__1.tmax - _BLNK__1.t + _BLNK__1.step;
    _BLNK__1.t = _BLNK__1.tmax;
    goto L440;
L430:
    _BLNK__1.step = (_BLNK__1.tmax - _BLNK__1.t + _BLNK__1.step) / 2.;
    _BLNK__1.t = _BLNK__1.tmax - _BLNK__1.step;
L440:
    _BLNK__1.step1 = _BLNK__1.step;
    _BLNK__1.gama = 1. / _BLNK__1.step;
/* PREDICT VALUES OR INTERPOLATE OUTPUT POINTS */
L500:
    jq = 0;
    i__1 = n;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	++jq;
	_BLNK__1.x[_BLNK__1.j - 1] = _BLNK__1.q[jq - 1];
/* L510: */
	_BLNK__1.xdot[_BLNK__1.j - 1] = 0.;
    }
    if (k1 <= 0) {
	goto L999;
    }
/* ADD HIGHER ORDER TERMS */
    alfa = 1.;
    beta = 0.;
    if (_BLNK__1.indal != 5) {
	_BLNK__1.gama = 0.;
    }
    i__1 = k1;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	d1 = _BLNK__1.step1 + _BLNK__1.sacc[_BLNK__1.j - 1];
	beta = (alfa + d1 * beta) / _BLNK__1.sacc[_BLNK__1.j];
	alfa = alfa * d1 / _BLNK__1.sacc[_BLNK__1.j];
	if (_BLNK__1.indal != 5) {
	    _BLNK__1.gama += 1. / d1;
	}
	i__2 = n;
	for (jj = 1; jj <= i__2; ++jj) {
	    ++jq;
	    _BLNK__1.x[jj - 1] += alfa * _BLNK__1.q[jq - 1];
/* L520: */
	    _BLNK__1.xdot[jj - 1] += beta * _BLNK__1.q[jq - 1];
	}
    }
/* END ALGDIF */
L999:
    return 0;
} /* algdfd_ */

/* Subroutine */ int tabd_(namex1, namex2, x, l, namey, y, ipoint, iout)
integer *namex1, *namex2;
doublereal *x;
integer *l, *namey;
doublereal *y;
integer *ipoint, *iout;
{
    /* Format strings */
    static char fmt_100[] = "(\002 точка\002,2x,a4,i2,4(7x,a4,i2),10(/10x,6(\
7x,a4,i2)))";
    static char fmt_1000[] = "(\002 точка\002,2x,a4,i2,10(7x,a4,i2))";
    static char fmt_101[] = "(\002 точка\002,4x,a4,4(7x,a4,i2),10(/10x,6(7x,\
a4,i2)))";
    static char fmt_1010[] = "(\002 точка\002,4x,a4,10(7x,a4,i2))";
    static char fmt_105[] = "(\002 \002)";
    static char fmt_110[] = "(1x,i3,1p5d13.3,10(/13x,1p7d13.3))";
    static char fmt_1100[] = "(1x,i3,1p11d13.3)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer i, j, iwdth;

    /* Fortran I/O blocks */
    static cilist io___50 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___53 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___54 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___55 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___56 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___57 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___58 = { 0, 0, 0, fmt_1100, 0 };


/*     *************** */
/* печать таблиц зависимостей Y[i] от  X */
/*     2.11.1981 */
/* задание ширины печати: */
/* IWDTH=0 => */
/* IWDTH=1 => */
    /* Parameter adjustments */
    --y;
    namey -= 3;

    /* Function Body */
    iwdth = 1;
    if (*l <= 4) {
	iwdth = 0;
    }
    if (*ipoint != 1) {
	goto L10;
    }
    if (*namex2 != 0 && iwdth == 1) {
	io___50.ciunit = *iout;
	s_wsfe(&io___50);
	do_fio(&c__1, (char *)&(*namex1), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*namex2), (ftnlen)sizeof(integer));
	i__1 = *l;
	for (j = 1; j <= i__1; ++j) {
	    for (i = 1; i <= 2; ++i) {
		do_fio(&c__1, (char *)&namey[i + (j << 1)], (ftnlen)sizeof(
			integer));
	    }
	}
	e_wsfe();
    }
    if (*namex2 != 0 && iwdth == 0) {
	io___53.ciunit = *iout;
	s_wsfe(&io___53);
	do_fio(&c__1, (char *)&(*namex1), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*namex2), (ftnlen)sizeof(integer));
	i__1 = *l;
	for (j = 1; j <= i__1; ++j) {
	    for (i = 1; i <= 2; ++i) {
		do_fio(&c__1, (char *)&namey[i + (j << 1)], (ftnlen)sizeof(
			integer));
	    }
	}
	e_wsfe();
    }
    if (*namex2 == 0 && iwdth == 1) {
	io___54.ciunit = *iout;
	s_wsfe(&io___54);
	do_fio(&c__1, (char *)&(*namex1), (ftnlen)sizeof(integer));
	i__1 = *l;
	for (j = 1; j <= i__1; ++j) {
	    for (i = 1; i <= 2; ++i) {
		do_fio(&c__1, (char *)&namey[i + (j << 1)], (ftnlen)sizeof(
			integer));
	    }
	}
	e_wsfe();
    }
    if (*namex2 == 0 && iwdth == 0) {
	io___55.ciunit = *iout;
	s_wsfe(&io___55);
	do_fio(&c__1, (char *)&(*namex1), (ftnlen)sizeof(integer));
	i__1 = *l;
	for (j = 1; j <= i__1; ++j) {
	    for (i = 1; i <= 2; ++i) {
		do_fio(&c__1, (char *)&namey[i + (j << 1)], (ftnlen)sizeof(
			integer));
	    }
	}
	e_wsfe();
    }
    io___56.ciunit = *iout;
    s_wsfe(&io___56);
    e_wsfe();
L10:
    if (iwdth == 1) {
	io___57.ciunit = *iout;
	s_wsfe(&io___57);
	do_fio(&c__1, (char *)&(*ipoint), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*x), (ftnlen)sizeof(doublereal));
	i__1 = *l;
	for (i = 1; i <= i__1; ++i) {
	    do_fio(&c__1, (char *)&y[i], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }
    if (iwdth == 0) {
	io___58.ciunit = *iout;
	s_wsfe(&io___58);
	do_fio(&c__1, (char *)&(*ipoint), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*x), (ftnlen)sizeof(doublereal));
	i__1 = *l;
	for (i = 1; i <= i__1; ++i) {
	    do_fio(&c__1, (char *)&y[i], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }
    return 0;
} /* tabd_ */

/* Subroutine */ int fortd1_()
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(), exp(), tanh(), sqrt();

    /* Local variables */
    static integer ncel, nceq;
    static doublereal curd, tder;
    static integer ityp;
    static doublereal y;
    extern /* Subroutine */ int fvald_();
    static doublereal theta, value, c0;
    static integer n1, n2;
    extern /* Subroutine */ int diodd1_();
    static doublereal y1, fd, gd;
    static integer na, nb, nc;
    static doublereal co;
    static integer nd, kl;
    static doublereal vd, pk, dy, wk, sq, rs, zk, fi0;
    static integer nc1, nc2;
    static doublereal dy1, fi01, emc, hih;
    static integer neq;
    static doublereal sat, ron;
    static integer ixp;
    static real wwk;
    static doublereal val1, val2;

/*     ***************** */

/*     6.10.1988 */





    _BLNK__2.x[_BLNK__2.ndim - 1] = (float)0.;
    _BLNK__2.xdot[_BLNK__2.ndim - 1] = (float)0.;
    i__1 = _BLNK__2.nels;
    for (_BLNK__2.j = 1; _BLNK__2.j <= i__1; ++_BLNK__2.j) {
	ixp = 0;
	ityp = _BLNK__2.net[_BLNK__2.j * 5 - 5];
	if (ityp <= 0 || ityp > 38) {
	    goto L8900;
	}
	neq = _BLNK__2.net[_BLNK__2.j * 5 - 1];
	n1 = _BLNK__2.net[_BLNK__2.j * 5 - 4];
	n2 = _BLNK__2.net[_BLNK__2.j * 5 - 3];
	value = _BLNK__2.val[_BLNK__2.j - 1];
	tder = 0.;

	if (_BLNK__2.j == _BLNK__2.indep) {
	    value = _BLNK__2.t;
	}
	if (_BLNK__2.idep[_BLNK__2.j - 1] <= 0) {
	    goto L5;
	}

	fvald_(&_BLNK__2.nfun, &_BLNK__2.npar, _BLNK__2.iadr, _BLNK__2.parf, &
		_BLNK__2.idep[_BLNK__2.j - 1], &_BLNK__2.t, &value, &tder);
	if (ityp > 28) {
	    goto L5;
	}
	if (ityp < 3 || ityp > 5) {
	    value *= _BLNK__2.val[_BLNK__2.j - 1];
	}
L5:
	vd = _BLNK__2.x[n2 - 1] - _BLNK__2.x[n1 - 1];
	ncel = _BLNK__2.net[_BLNK__2.j * 5 - 2];
	if (ityp >= 22 && ityp <= 25) {
	    goto L30;
	}
	if (ncel < 0) {
	    goto L8900;
	} else if (ncel == 0) {
	    goto L20;
	} else {
	    goto L10;
	}
L10:
	if (ncel < 0 || ncel > _BLNK__2.nels) {
	    goto L20;
	}
	nc1 = _BLNK__2.net[ncel * 5 - 4];
	nc2 = _BLNK__2.net[ncel * 5 - 3];
	nceq = _BLNK__2.net[ncel * 5 - 1];
L20:
	if (ityp >= 26) {
	    goto L1000;
	}
	if (neq != 0) {
	    goto L1000;
	}
L30:
/* ****************** элементы без вычисления тока ****************** 
*/
/*             R    G    J    E   ER   IV   II   VV */
/*             VI    0    N   OA    C    L    K    M */
/*              D   CD   CB   RI   GV   PNP  NPN  NM  PM */
	switch ((int)ityp) {
	    case 1:  goto L100;
	    case 2:  goto L110;
	    case 3:  goto L120;
	    case 4:  goto L8900;
	    case 5:  goto L140;
	    case 6:  goto L150;
	    case 7:  goto L160;
	    case 8:  goto L8900;
	    case 9:  goto L8900;
	    case 10:  goto L8900;
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
	    case 22:  goto L400;
	    case 23:  goto L400;
	    case 24:  goto L500;
	    case 25:  goto L500;
	}
/* --R--- */
L100:
	value = 1. / value;
/* --G--- */
L110:
	val1 = value * (-vd);
	goto L6980;
/* --J--- */
L120:
	val1 = value;
	na = n1;
	nb = n2;
	goto L7010;
/* --ER-- */
L140:
	if (_BLNK__2.net[ncel * 5 - 1] == 0) {
	    goto L145;
	}
/*  ... */
	_BLNK__2.b0[nceq - 1] += value;
	goto L8900;
/*  ... */
L145:
	val1 = value / _BLNK__2.val[ncel - 1];
	nb = nc1;
	na = nc2;
	goto L7010;
/* --IV-- */
L150:
	nc = nc1;
	nd = nc2;
	val1 = value * (_BLNK__2.x[nc1 - 1] - _BLNK__2.x[nc2 - 1]);
	goto L6990;
/* --II-- */
L160:
	na = n1;
	nb = n2;
	nc = nceq;
	val1 = value * _BLNK__2.x[nceq - 1];
	goto L7005;
/* --C--- */
L220:
	val1 = value * (_BLNK__2.xdot[n1 - 1] - _BLNK__2.xdot[n2 - 1]) - tder 
		* vd;
	value = value * _BLNK__2.p + tder;
	goto L6980;
/* --D--- */
L260:
	if (ncel != 0) {
	    goto L262;
	}
	rs = (float).01;
	goto L265;
L262:
	rs = c1_1.pare[ncel - 1];
L265:
	d__1 = -vd;
	diodd1_(&_BLNK__2.init, &value, &rs, &_BLNK__2.temp, &d__1, &gd, &
		val1);
	value = gd;
	goto L6980;
/* --CD-- */
L270:
/* параметры модели : */
/* - */
	fd = value;
/* - */
	emc = 1.04;
	theta = 11610. / (emc * _BLNK__2.temp);
	rs = (float).01;
	sat = _BLNK__2.val[ncel - 1];
	vd = _BLNK__2.x[nc1 - 1] - _BLNK__2.x[nc2 - 1];
	d__1 = -vd;
	diodd1_(&_BLNK__2.init, &sat, &rs, &_BLNK__2.temp, &d__1, &gd, &curd);
/* значение "CD" */
	value = theta * .1592 * (curd + sat) / fd;
/* вычисление матрицы- */
L275:
	val1 = value * (_BLNK__2.xdot[nc1 - 1] - _BLNK__2.xdot[nc2 - 1]) - 
		tder * vd;
	value = value * _BLNK__2.p + tder;
	goto L6980;
/* --CB-- */
L280:
/* параметры модели: */
/* - */
	c0 = value;
/* - */
	fi0 = .3;
/* - */
	emc = 1.04;
	theta = 11610. / (emc * _BLNK__2.temp);
	fi01 = fi0 - 2. / theta;
/* - */
	pk = .5;

	vd = _BLNK__2.x[nc1 - 1] - _BLNK__2.x[nc2 - 1];
	if (vd > fi01) {
	    goto L285;
	}
/* значение " CB " */
	d__1 = fi0 - vd;
	value = fi0 * c0 / pow_dd(&d__1, &pk);
	goto L275;
L285:
	d__1 = fi0 - fi01;
	value = c0 / pow_dd(&d__1, &pk);
	goto L275;
/* --GV-- */
L300:
	d__1 = -vd;
	fvald_(&_BLNK__2.nfun, &_BLNK__2.npar, _BLNK__2.iadr, _BLNK__2.parf, &
		_BLNK__2.net[_BLNK__2.j * 5 - 2], &d__1, &val1, &value);
	goto L6980;
/* транзистор NPN и PNP */
L400:
/* изменение знака для PNP */
	if (ityp == 22) {
	    vd = -vd;
	}
	rs = .01;
	value = 1e-6;
	if (neq != 0) {
	    value = c1_1.pare[neq - 1];
	}

	d__1 = -vd;
	diodd1_(&_BLNK__2.init, &value, &rs, &_BLNK__2.temp, &d__1, &gd, &
		val1);
	if (ityp == 22) {
	    val1 = -val1;
	}
	value = gd;
	ixp = 1;
	goto L6980;

L410:
	value = gd * _BLNK__2.val[_BLNK__2.j - 1];
	_BLNK__2.a0[n2 + n2 * 20 - 21] -= value;
	_BLNK__2.a0[n2 + n1 * 20 - 21] += value;
	_BLNK__2.a0[ncel + n1 * 20 - 21] -= value;
	_BLNK__2.a0[ncel + n2 * 20 - 21] += value;
	n1 = ncel;
	vd = _BLNK__2.x[n2 - 1] - _BLNK__2.x[n1 - 1];
	if (ityp == 22) {
	    vd = -vd;
	}
	rs = .01;
	value = 1e-6;
	if (neq != 0) {
	    value = c1_1.pare[neq];
	}
	d__1 = -vd;
	diodd1_(&_BLNK__2.init, &value, &rs, &_BLNK__2.temp, &d__1, &gd, &
		val2);
	ixp = 0;
	if (ityp == 22) {
	    val1 = -val1;
	}
	val1 = val2 - _BLNK__2.val[_BLNK__2.j - 1] * val1;
	if (ityp == 22) {
	    val1 = -val1;
	}
	value = gd;
	goto L6980;

L500:
	fd = (float).7;
	emc = (float)2.72;
	fi0 = (float)10.;
	theta = (float)1.;
	if (neq == 0) {
	    goto L550;
	}
	fd = c1_1.pare[neq - 1];
	emc = c1_1.pare[neq];
	fi0 = c1_1.pare[neq + 1];
L550:
	if (ityp == 25) {
	    theta = (float)-1.;
	}
	theta *= (float)1.;
	wk = emc * (_BLNK__2.x[n1 - 1] - _BLNK__2.x[ncel - 1] - fi0) / value;
	zk = (exp(wk) - exp(-wk)) / (float)2.;
	wwk = wk;
	wwk = tanh(wwk);
	co = (doublereal) wwk;
	c0 = value * (co + 1.);
/* Computing 2nd power */
	d__1 = emc;
	curd = emc * (1. - exp(-fd * emc * (_BLNK__2.x[n2 - 1] - _BLNK__2.x[
		ncel - 1]) / c0)) / zk + exp(-fd * emc * (_BLNK__2.x[n2 - 1] 
		- _BLNK__2.x[ncel - 1]) / c0) * fd * (d__1 * d__1) * (
		_BLNK__2.x[n1 - 1] - _BLNK__2.x[ncel - 1]) / zk / c0;
	fi01 = fd * emc * exp(-fd * emc * (_BLNK__2.x[n2 - 1] - _BLNK__2.x[
		ncel - 1]) / c0);
/* Computing 2nd power */
	d__1 = emc;
	pk = -emc / zk * (1. - exp(-fd * emc * (_BLNK__2.x[n2 - 1] - 
		_BLNK__2.x[ncel - 1]) / c0)) + exp(-fd * emc * (_BLNK__2.x[n2 
		- 1] - _BLNK__2.x[ncel - 1]) / c0) * (fd * (d__1 * d__1) * (
		_BLNK__2.x[n2 - 1] - _BLNK__2.x[ncel - 1]) / zk - fd * emc * 
		c0) / c0;
	val1 = c0 * ((float)1. - exp(-fd * (_BLNK__2.x[n2 - 1] - _BLNK__2.x[
		ncel - 1]) * emc / c0));
	fi0 *= theta;
	fi01 *= theta;
	pk *= theta;
	_BLNK__2.a0[n1 + n1 * 20 - 21] += fi0;
	_BLNK__2.a0[n2 + n1 * 20 - 21] += fi01;
	_BLNK__2.a0[ncel + n1 * 20 - 21] += pk;
	_BLNK__2.a0[n1 + n2 * 20 - 21] -= fi0;
	_BLNK__2.a0[n2 + n2 * 20 - 21] -= fi01;
	_BLNK__2.a0[ncel + n2 * 20 - 21] -= pk;
	val1 *= theta;
	_BLNK__2.b0[n2 - 1] -= val1;
	_BLNK__2.b0[ncel - 1] += val1;
	goto L8901;
/* ****************** элементы с вычислением тока ****************** 
*/
L1000:
/*              R    G    J    E   ER   IV   II   VV */
/*             VI    0    N   OA    C    L    K    M */
/*              D   CD   CB   RI   GV   NP   PN   NM */
/*             PM   DD   ZD   T */
/*             KT   KV   KI   T1   T2   T3  T4  T5  T6   PI */
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
	    case 10:  goto L1190;
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
	    case 22:  goto L8900;
	    case 23:  goto L8900;
	    case 24:  goto L8900;
	    case 25:  goto L8900;
	    case 26:  goto L8900;
	    case 27:  goto L8900;
	    case 28:  goto L1500;
	    case 29:  goto L1005;
	    case 30:  goto L1003;
	    case 31:  goto L1005;
	    case 32:  goto L1600;
	    case 33:  goto L1600;
	    case 34:  goto L1600;
	    case 35:  goto L1600;
	    case 36:  goto L1600;
	    case 37:  goto L1600;
	    case 38:  goto L8900;
	}
/*  ключ,управляемый VD или I или f(T) */
L1003:
	if (switch_1.pred[ncel - 1]) {
	    goto L1007;
	}
	goto L1006;
/* --KT-KI-- */
L1005:
	if (value > 0.) {
	    goto L1006;
	}
/*   ключ замкнут = переход на R=0 */
L1007:
	value = 0.;
	goto L1100;
/*   ключ разомкнут = переход на G=0 */
L1006:
	_BLNK__2.a0[neq + neq * 20 - 21] += -1.;
	_BLNK__2.b0[neq - 1] += _BLNK__2.x[neq - 1];
	goto L8900;
/* --R-- */
L1100:
	val1 = value;
	val2 = vd + value * _BLNK__2.x[neq - 1];
	value = 1.;
	goto L7040;
/* --G-- */
L1110:
	val1 = 1.;
	val2 = value * vd + _BLNK__2.x[neq - 1];
	goto L7040;
/* --J-- */
L1120:
	_BLNK__2.a0[neq + neq * 20 - 21] += 1.;
	val2 = -_BLNK__2.x[neq - 1] + value;
	goto L7055;
/* --E-- */
L1130:
	val2 = value + vd;
	value = 1.;
	goto L7045;
/* --IV-- */
L1150:
	_BLNK__2.a0[neq + neq * 20 - 21] += -1.;
	na = nc1;
	nb = nc2;
	val2 = value * (_BLNK__2.x[nc2 - 1] - _BLNK__2.x[nc1 - 1]) + 
		_BLNK__2.x[neq - 1];
	goto L7050;
/* --II-- */
L1160:
	_BLNK__2.a0[neq + nceq * 20 - 21] += value;
	_BLNK__2.a0[neq + neq * 20 - 21] += -1.;
	val2 = -value * _BLNK__2.x[nceq - 1] + _BLNK__2.x[neq - 1];
	goto L7055;
/* --VV-- */
L1170:
	na = nc2;
	nb = nc1;
	_BLNK__2.a0[neq + n1 * 20 - 21] += 1.;
	_BLNK__2.a0[neq + n2 * 20 - 21] += -1.;
	val2 = vd + value * (_BLNK__2.x[nc1 - 1] - _BLNK__2.x[nc2 - 1]);
	goto L7050;
/* --VI-- */
L1180:
	_BLNK__2.a0[neq + nceq * 20 - 21] -= value;
	val2 = value * _BLNK__2.x[nceq - 1] + vd;
	value = 1.;
	goto L7045;
/* --0--- */
L1190:
	_BLNK__2.a0[nceq + n1 * 20 - 21] += 1.;
	_BLNK__2.a0[nceq + n2 * 20 - 21] += -1.;
	_BLNK__2.b0[nceq - 1] += vd;
	goto L8900;
/* --OA-- */
L1210:
	_BLNK__2.a0[neq + nc1 * 20 - 21] += 1.;
	_BLNK__2.a0[neq + nc2 * 20 - 21] += -1.;
	_BLNK__2.b0[neq - 1] = _BLNK__2.b0[neq - 1] + _BLNK__2.x[nc2 - 1] - 
		_BLNK__2.x[nc1 - 1];
	goto L7060;
/* --C-- */
L1220:
	val2 = _BLNK__2.x[neq - 1] + value * (_BLNK__2.xdot[n2 - 1] - 
		_BLNK__2.xdot[n1 - 1]) + tder * vd;
	value = value * _BLNK__2.p + tder;
	val1 = 1.;
	goto L7040;
/* --L-- */
L1230:
	val2 = vd + value * _BLNK__2.xdot[neq - 1] + tder * _BLNK__2.x[neq - 
		1];
	val1 = _BLNK__2.p * value;
	value = 1.;
	goto L7040;
/* --K-- */
L1240:
	sq = sqrt(_BLNK__2.val[n1 - 1] * _BLNK__2.val[n2 - 1]);
	tder *= sq;
	value *= sq;
/* --M---взаимно- */
L1250:
	n1 = _BLNK__2.net[n1 * 5 - 1];
	n2 = _BLNK__2.net[n2 * 5 - 1];
	_BLNK__2.b0[n1 - 1] = _BLNK__2.b0[n1 - 1] + value * _BLNK__2.xdot[n2 
		- 1] + tder * _BLNK__2.x[n2 - 1];
	_BLNK__2.b0[n2 - 1] = _BLNK__2.b0[n2 - 1] + value * _BLNK__2.xdot[n1 
		- 1] + tder * _BLNK__2.x[n1 - 1];
	value *= _BLNK__2.p;
	_BLNK__2.a0[n1 + n2 * 20 - 21] = _BLNK__2.a0[n1 + n2 * 20 - 21] - 
		value - tder;
	_BLNK__2.a0[n2 + n1 * 20 - 21] = _BLNK__2.a0[n2 + n1 * 20 - 21] - 
		value - tder;
	goto L8900;
/* --D--- */
L1260:
	if (ncel != 0) {
	    goto L1262;
	}
	rs = (float).01;
	goto L1264;
L1262:
	rs = c1_1.pare[ncel - 1];
L1264:
	d__1 = -vd;
	diodd1_(&_BLNK__2.init, &value, &rs, &_BLNK__2.temp, &d__1, &gd, &
		val2);
L1265:
	value = gd;
	val1 = 1.;
	val2 = -val2 + _BLNK__2.x[neq - 1];
	goto L7040;
/* --CD-- */
L1270:
	fd = value;
	emc = 1.04;
	theta = 11610. / (emc * _BLNK__2.temp);
	rs = (float).01;
	sat = _BLNK__2.val[ncel - 1];
	vd = _BLNK__2.x[nc1 - 1] - _BLNK__2.x[nc2 - 1];
	d__1 = -vd;
	diodd1_(&_BLNK__2.init, &sat, &rs, &_BLNK__2.temp, &d__1, &gd, &curd);
	value = theta * .1592 * (curd + sat) / fd;
L1275:
	val2 = _BLNK__2.x[neq - 1] + value * (_BLNK__2.xdot[nc2 - 1] - 
		_BLNK__2.xdot[nc1 - 1]) + tder * vd;
	value = value * _BLNK__2.p + tder;
	val1 = 1.;
	goto L7040;
/* --CB-- */
L1280:
	c0 = value;
	fi0 = .3;
	emc = 1.04;
	theta = 11610. / (emc * _BLNK__2.temp);
	fi01 = fi0 - 2. / theta;
	pk = .5;
	vd = _BLNK__2.x[nc1 - 1] - _BLNK__2.x[nc2 - 1];
	if (vd > fi01) {
	    goto L1285;
	}
	d__1 = fi0 - vd;
	value = fi0 * c0 / pow_dd(&d__1, &pk);
	goto L1275;
L1285:
	d__1 = fi0 - fi01;
	value = c0 / pow_dd(&d__1, &pk);
	goto L1275;
/* --RI-- */
L1290:
	fvald_(&_BLNK__2.nfun, &_BLNK__2.npar, _BLNK__2.iadr, _BLNK__2.parf, &
		_BLNK__2.net[_BLNK__2.j * 5 - 2], &_BLNK__2.x[neq - 1], &val2,
		 &val1);
	val2 += vd;
	value = 1.;
	goto L7040;
/* --GV-- */
L1300:
	d__1 = -vd;
	fvald_(&_BLNK__2.nfun, &_BLNK__2.npar, _BLNK__2.iadr, _BLNK__2.parf, &
		_BLNK__2.net[_BLNK__2.j * 5 - 2], &d__1, &val2, &value);
	val1 = 1.;
	val2 = -val2 + _BLNK__2.x[neq - 1];
	goto L7040;
/* --T-- */
L1500:
	if (ncel != 0) {
	    goto L1510;
	}
	ron = (float).01;
	hih = (float).01;
	goto L1520;
L1510:
	ron = c1_1.pare[ncel - 1];
	hih = c1_1.pare[ncel];
L1520:
	if (_BLNK__2.idep[_BLNK__2.j - 1] <= 0) {
	    goto L1522;
	}
	if (value / _BLNK__2.val[_BLNK__2.j - 1] > .5) {
	    goto L1530;
	}
	if (_BLNK__2.x[neq - 1] >= hih) {
	    goto L1530;
	}
/* режим OFF - ROFF = 1M */
L1522:
	value = 1e-6;
	goto L1110;
L1530:
	sat = _BLNK__2.val[_BLNK__2.j - 1];
	d__1 = -vd;
	diodd1_(&_BLNK__2.init, &sat, &ron, &_BLNK__2.temp, &d__1, &gd, &val2)
		;
	goto L1265;
/* --T1-T6--transformator */
L1600:
	if (ityp == 32) {
	    kl = neq - 1;
	}
	val1 = value * _BLNK__2.p;
	val2 = vd + value * _BLNK__2.xdot[kl - 1];
	_BLNK__2.a0[neq + kl * 20 - 21] -= val1;
	_BLNK__2.a0[neq + n1 * 20 - 21] += 1.;
	_BLNK__2.a0[neq + n2 * 20 - 21] += -1.;
	_BLNK__2.a0[kl + neq * 20 - 21] -= value;
	_BLNK__2.b0[kl - 1] += _BLNK__2.x[neq - 1] * value;
	if (ityp == 32) {
	    goto L7020;
	}
	if (ityp == 33) {
	    goto L7030;
	}
	goto L7055;
L7020:
	fvald_(&_BLNK__2.nfun, &_BLNK__2.npar, _BLNK__2.iadr, _BLNK__2.parf, &
		ncel, &_BLNK__2.x[kl - 1], &y, &dy);
	_BLNK__2.a0[kl + kl * 20 - 21] += 1 / y;
	_BLNK__2.b0[kl - 1] -= _BLNK__2.x[kl - 1] / y;
	goto L7055;
L7030:
	fvald_(&_BLNK__2.nfun, &_BLNK__2.npar, _BLNK__2.iadr, _BLNK__2.parf, &
		ncel, &_BLNK__2.xdot[kl - 1], &y1, &dy1);
	_BLNK__2.a0[kl + kl * 20 - 21] += _BLNK__2.p / y1;
	_BLNK__2.b0[kl - 1] -= _BLNK__2.xdot[kl - 1] / y1;
	goto L7055;
/* заполнение матриц "A0" и "B0" для эл- */
L6980:
	nc = n1;
	nd = n2;
L6990:
	na = n1;
	nb = n2;
/* L7000: */
	_BLNK__2.a0[na + nd * 20 - 21] -= value;
	_BLNK__2.a0[nb + nd * 20 - 21] += value;
L7005:
	_BLNK__2.a0[na + nc * 20 - 21] += value;
	_BLNK__2.a0[nb + nc * 20 - 21] -= value;
L7010:
	_BLNK__2.b0[na - 1] -= val1;
	_BLNK__2.b0[nb - 1] += val1;
	goto L8900;
/* заполнение матриц "A0" и "B0" для эл- */
L7040:
	_BLNK__2.a0[neq + neq * 20 - 21] -= val1;
L7045:
	na = n1;
	nb = n2;
L7050:
	_BLNK__2.a0[neq + na * 20 - 21] += value;
	_BLNK__2.a0[neq + nb * 20 - 21] -= value;
L7055:
	_BLNK__2.b0[neq - 1] += val2;
L7060:
	_BLNK__2.a0[n1 + neq * 20 - 21] += 1.;
	_BLNK__2.a0[n2 + neq * 20 - 21] += -1.;
	_BLNK__2.b0[n1 - 1] -= _BLNK__2.x[neq - 1];
	_BLNK__2.b0[n2 - 1] += _BLNK__2.x[neq - 1];
L8900:
	if (ixp == 1) {
	    goto L410;
	}
L8901:
	;
    }
    return 0;
} /* fortd1_ */

/* Subroutine */ int diodd1_(idiod, sat, rs, temp, vd, gd, curd)
integer *idiod;
doublereal *sat, *rs, *temp, *vd, *gd, *curd;
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double exp(), log();

    /* Local variables */
    static doublereal expd, theta, vexli, emc;

/*     ***************** */
/* formirowanie linearizowannoj stati~eskoj modeli p/p dioda */
/*     6.10.1981 */

    emc = 1.04;
    theta = 11610. / (emc * *temp);

/* Computing 3rd power */
    d__1 = *temp / 293., d__2 = d__1;
    *sat = *sat * (d__2 * (d__1 * d__1)) * exp((*temp - 293.) * 1.4e4 / (*
	    temp * 293.));
/* вычисление точки перехода от экспоненциальной хар- */
    vexli = 1. / theta * (-log(*rs * theta * *sat));

    if (*idiod == 1) {
	*vd = vexli / 2.;
    }

    if (*vd > 0.) {
	goto L10;
    }
/* линейная область : VD < 0. */
    *gd = *sat * theta;
    *curd = *gd * *vd;
    return 0;
L10:
    if (*vd > vexli) {
	goto L20;
    }
/* экспоненциальная область : 0. < VD < VEXLI */
    expd = exp(theta * *vd);
    *gd = *sat * theta * expd;
    *curd = *sat * (expd - 1.);
    return 0;
/* линейная область : VD > VEXLI */
L20:
    *gd = 1. / *rs;
    *curd = *gd * (1. / theta + *vd - vexli) - *sat;
    return 0;
} /* diodd1_ */

/* Subroutine */ int secd_(nsec, isec, nels, net, n, x, y)
integer *nsec, *isec, *nels, *net, *n;
doublereal *x, *y;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i, m, iseci, n1, n2, ix;

/*     *************** */

/*     2.11.1981 */
    /* Parameter adjustments */
    --y;
    --x;
    net -= 6;
    --isec;

    /* Function Body */
    i__1 = *nsec;
    for (i = 1; i <= i__1; ++i) {
	iseci = isec[i];
	if (iseci <= -100) {
	    goto L5;
	}
	if (iseci <= 0) {
	    goto L10;
	}
	if (iseci < 100) {
	    goto L2;
	}
	iseci /= 100;

L2:
	n1 = net[iseci * 5 + 2];
	n2 = net[iseci * 5 + 3];
	y[i] = x[n1] - x[n2];
	goto L20;

L5:
	iseci = -(iseci / 100);
	n1 = net[iseci * 5 + 2];
	n2 = net[iseci * 5 + 3];
	ix = net[iseci * 5 + 5];
	y[i] = (x[n1] - x[n2]) * x[ix];
	goto L20;

L10:
	m = -iseci;
	ix = net[m * 5 + 5];
	y[i] = x[ix];
L20:
	;
    }
    return 0;
} /* secd_ */

/* Subroutine */ int fvald_(nf, npar, iadr, parf, num, x, y, dy)
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

/*     30.9.1981 */

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
/* функция, */
L300:
/* если периодическая, */
    t = *x;
    if (parf[ia] != 0.) {
	t = d_mod(x, &parf[ia]);
    }
    k = ia + 3;
    if (t <= parf[ia + 1]) {
	goto L320;
    }

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
} /* fvald_ */

/* Subroutine */ int forlog_(nels, net, val, ndim, t, x, xdot)
integer *nels, *net;
doublereal *val;
integer *ndim;
doublereal *t, *x, *xdot;
{
    /* Format strings */
    static char fmt_72[] = "(2x,\002запрещенное состояние триггера\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    static integer ncel, ityp;
    static logical pred2;
    static integer i, j, n1, n2, nc1, nc2, ng1, ng2, ind, iou;
    static doublereal val1, val2;

    /* Fortran I/O blocks */
    static cilist io___132 = { 0, 0, 0, fmt_72, 0 };


/* ************************************************** */
    /* Parameter adjustments */
    --xdot;
    --x;
    --val;
    net -= 6;

    /* Function Body */
    i__1 = *nels;
    for (j = 1; j <= i__1; ++j) {
	ityp = net[j * 5 + 1];
	if (ityp <= 38) {
	    goto L8900;
	}
	ityp += -38;
	n1 = net[j * 5 + 2];
	if (ityp == 2 || ityp == 3) {
	    n2 = net[j * 5 + 3];
	}
	ncel = net[j * 5 + 4];
	nc1 = net[n1 * 5 + 2];
	nc2 = net[n1 * 5 + 3];
/* *****************логические элементы*************** */
/*            PR,AN,OR,NO,ST,PP,RS,DC,TT,JK */
	switch ((int)ityp) {
	    case 1:  goto L10;
	    case 2:  goto L20;
	    case 3:  goto L30;
	    case 4:  goto L40;
	    case 5:  goto L50;
	    case 6:  goto L60;
	    case 7:  goto L70;
	    case 8:  goto L80;
	    case 9:  goto L90;
	    case 10:  goto L100;
	}
L10:
	n2 = net[j * 5 + 3];
	if (n2 == 0) {
	    goto L12;
	}
	ng1 = net[n2 * 5 + 2];
	ng2 = net[n2 * 5 + 3];
	val2 = x[ng1] - x[ng2] + val[j];
	goto L13;
L12:
	val2 = val[j];
L13:
	switch_1.pred1[ncel - 1] = TRUE_;
	val1 = x[nc1] - x[nc2];
	if (val1 < val2) {
	    goto L11;
	}
	switch_1.pred1[ncel - 1] = FALSE_;
L11:
	goto L8900;
L20:
	switch_1.pred1[ncel - 1] = switch_1.pred1[n1 - 1] && switch_1.pred1[
		n2 - 1];
	goto L8900;
L30:
	switch_1.pred1[ncel - 1] = switch_1.pred1[n1 - 1] || switch_1.pred1[
		n2 - 1];
	goto L8900;
L40:
	switch_1.pred1[ncel - 1] = ! switch_1.pred1[n1 - 1];
	goto L8900;
L50:
	switch_1.pred1[ncel - 1] = switch_1.pred[ncel - 1];
	switch_1.pred[ncel - 1] = switch_1.pred1[n1 - 1];
	if (switch_1.pred[ncel - 1] == switch_1.pred1[ncel - 1]) {
	    goto L51;
	}
	if (switch_1.tsw[ncel - 1] == 0.) {
	    switch_1.tsw[ncel - 1] = *t;
	}
	if (switch_1.tsw[ncel - 1] + val[j] >= *t) {
	    goto L51;
	}
	switch_1.pred1[ncel - 1] = switch_1.pred[ncel - 1];
	switch_1.tsw[ncel - 1] = 0.;
L51:
	goto L8900;
L60:
	switch_1.pred1[n1 - 1] = FALSE_;
	switch_1.pred1[n2 - 1] = TRUE_;
	if (xdot[nc1] - xdot[nc2] < val[j]) {
	    goto L8900;
	}
	switch_1.pred1[n1 - 1] = TRUE_;
	switch_1.pred1[n2 - 1] = FALSE_;
	goto L8900;
L70:
	if (switch_1.pred1[n1 - 1] == TRUE_ && switch_1.pred1[n2 - 1] == 
		TRUE_) {
	    goto L71;
	}
	switch_1.pred1[ncel - 1] = switch_1.pred1[n1 - 1] || ! switch_1.pred1[
		n2 - 1] && switch_1.pred[ncel - 1];
	goto L8900;
L71:
	io___132.ciunit = iou;
	s_wsfe(&io___132);
	e_wsfe();
	ind = 11;
L80:
	goto L8900;
L90:
	pred2 = ! switch_1.pred[n1 - 1];
	pred2 = pred2 && switch_1.pred1[n1 - 1];
	if (pred2) {
	    switch_1.pred1[ncel - 1] = ! switch_1.pred1[ncel - 1];
	}
L100:
	goto L8900;
L8900:
	;
    }
    for (i = 1; i <= 20; ++i) {
	switch_1.pred[i - 1] = switch_1.pred1[i - 1];
/* L1: */
    }
    return 0;
} /* forlog_ */

