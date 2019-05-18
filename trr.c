/* trr.f -- translated by f2c (version of 23 April 1993  18:34:30).
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
    doublereal x[20], a0[400]	/* was [20][20] */, dx[20], xmax[20], xdot[20]
	    , xout[20];
    integer maxit;
    doublereal conv, xmin, flog, stepmx, valm, feps, fluf, fpol, fmin, fper;
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
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    doublereal tsw[20];
    logical pred[20], pred1[20];
} switch_;

#define switch_1 switch_

/* Table of constant values */

static integer c__1 = 1;
static integer c__20 = 20;
static integer c__1960 = 1960;
static integer c__2 = 2;
static integer c__7 = 7;
static integer c__15 = 15;

/* Subroutine */ int trr_()
{
    /* Initialized data */

    static struct {
	char e_1[100];
	real e_2;
	} equiv_17 = { {'L', 'I', 'S', 'T', 'E', 'N', 'D', ' ', 'D', 'C', 'A',
		 'L', 'D', 'C', ' ', ' ', 'D', 'C', 'T', 'R', 'T', 'R', ' ', 
		' ', 'T', 'E', 'M', 'P', 'I', 'N', 'I', 'T', 'D', 'E', 'P', 
		'E', 'C', 'O', 'N', 'T', 'R', 'U', 'N', ' ', 'P', 'L', 'O', 
		'T', 'M', 'O', 'D', 'I', 'R', 'E', 'S', 'E', 'E', 'X', 'C', 
		'H', 'F', 'O', 'U', 'R', 'I', 'N', 'D', 'E', 'S', 'A', 'V', 
		'E', 'L', 'O', 'A', 'D', 'R', 'E', 'F', 'I', 'H', 'O', 'L', 
		'D', 'S', 'E', 'N', 'S', 'R', 'E', 'L', 'A', 'P', 'U', 'L', 
		'C', 'T', 'R', 'I', 'N'}, (float)0. };

#define con ((real *)&equiv_17)

    static struct {
	char e_1[8];
	integer e_2;
	} equiv_18 = { {'T', 'I', ' ', ' ', 'M', 'E', ' ', ' '}, 0 };

#define itime ((integer *)&equiv_18)


    /* Format strings */
    static char fmt_1030[] = "(f9.5)";
    static char fmt_1040[] = "(//1x,\002температура =\002,3pd13.3,\002 K\002)"
	    ;
    static char fmt_1060[] = "(i5,5f9.5)";
    static char fmt_1070[] = "(//15x,\002параметры для управления вычисления\
ми :\002//10x,\002MAX число итераций на одном шаге =\002,i4/10x,\002относите\
льная ошибка решения     =\002,1pd13.5/10x,\002MAX число шагов интегрировани\
я   =\002,d13.5/10x,\002логарифмич. коэфф. демпфирования =\002,e13.5/10x,\
\002MAX значение шага интегрирования =\002,d13.5)";
    static char fmt_1065[] = "(i5,f9.5,i5)";
    static char fmt_1100[] = "(//8x,\002анализ фурье\002//8x,\002число перио\
дов\002,6x,i3/8x,\002длина периода\002,5x,1pd13.5/8x,\002число гармоник\002,\
i4)";
    static char fmt_1130[] = "(//\002 вычисление чувствительности на элемен\
т\002,i3,\002дельта = \002,1pd13.5,\002%\002)";
    static char fmt_1120[] = "(\002 ошибка : не найден ожидаемый знак оконча\
ния \002)";

    /* System generated locals */
    integer i__1, i__2;
    alist al__1;

    /* Builtin functions */
    integer f_rew(), s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe(), s_wsue(
	    ), do_uio(), e_wsue(), s_rsue(), e_rsue();

    /* Local variables */
    extern /* Subroutine */ int fdep_();
#define save ((real *)&_BLNK__1)
    extern /* Subroutine */ int vars_(), nuld_();
    extern integer ierr_();
    extern /* Subroutine */ int rind_(), pulc_(), plot5_();
    static integer nomel;
    extern /* Subroutine */ int rvard_(), rlist_(), contr1_(), modifd_(), 
	    primvd_(), nul_();

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 0, 0, fmt_1030, 0 };
    static cilist io___6 = { 0, 0, 0, fmt_1040, 0 };
    static cilist io___7 = { 0, 0, 0, fmt_1060, 0 };
    static cilist io___8 = { 0, 0, 0, fmt_1070, 0 };
    static cilist io___9 = { 0, 0, 0, fmt_1060, 0 };
    static cilist io___10 = { 0, 0, 0, fmt_1065, 0 };
    static cilist io___11 = { 0, 0, 0, fmt_1100, 0 };
    static cilist io___12 = { 0, 0, 0, 0, 0 };
    static cilist io___13 = { 0, 0, 0, 0, 0 };
    static cilist io___14 = { 0, 0, 0, fmt_1065, 0 };
    static cilist io___15 = { 0, 0, 0, fmt_1130, 0 };
    static cilist io___16 = { 0, 0, 0, fmt_1120, 0 };


/*     ************** */
/* чтение в секции TR */
/*     17.3.1989 */





    if (_BLNK__1.iset == 0) {
	goto L6;
    }
/* EXTENT OF VARIABLES */
    _BLNK__1.ncon = 25;
/*     ISEGM = 0 */
/* DIMENSION OF ARRAYS */
    _BLNK__1.kmax = 6;
    _BLNK__1.kmax2 = 8;
    _BLNK__1.kmax10 = 16;
    _BLNK__1.nq = 340;
/* FIXED CONSTANTS */
    _BLNK__1.maxpnt = 260;
    _BLNK__1.npf = 129;
/* DENOTATION OF SECONDARY VARIABLES */
    i__1 = _BLNK__1.nsec;
    for (_BLNK__1.j = 1; _BLNK__1.j <= i__1; ++_BLNK__1.j) {
	if (_BLNK__1.icont == 1) {
	    vars_(&_BLNK__1.msec[_BLNK__1.j - 1], &_BLNK__1.namey[(_BLNK__1.j 
		    << 1) - 2]);
	}
	if (_BLNK__1.icont == 2) {
	    _BLNK__1.namey[(_BLNK__1.j << 1) - 2] = _BLNK__1.nout[_BLNK__1.j 
		    - 1];
	}
	nomel = (i__2 = _BLNK__1.msec[_BLNK__1.j - 1], abs(i__2));
	if (nomel < 100) {
	    goto L2;
	}
	nomel /= 100;
L2:
	_BLNK__1.namey[(_BLNK__1.j << 1) - 1] = nomel;
/* L7: */
    }
/* DEFAULT VALUES */
L1:
    _BLNK__1.ihold = 0;
    _BLNK__1.iref = 0;
    _BLNK__1.indep = 0;
    _BLNK__1.nper = 0;
    _BLNK__1.namin[0] = itime[0];
    _BLNK__1.namin[1] = itime[1];
    _BLNK__1.list = 0;
    _BLNK__1.ich = 0;
    _BLNK__1.temp = (float)300.;
    _BLNK__1.maxit = 25;
    _BLNK__1.conv = .001;
    _BLNK__1.xmin = (float)1e5;
    _BLNK__1.flog = (float)0.;
    _BLNK__1.ifile = 0;
    _BLNK__1.init = 1;
    _BLNK__1.tmin = (float)0.;
    _BLNK__1.tmax = (float)1.;
    _BLNK__1.stepmx = (float)0.;
    _BLNK__1.npoint = 51;
    _BLNK__1.idc = 0;
    _BLNK__1.kdc = 0;
    _BLNK__1.isen = 0;
    for (_BLNK__1.i = 1; _BLNK__1.i <= 10; ++_BLNK__1.i) {
	_BLNK__1.mpulc[_BLNK__1.i - 1] = 0;
/* L22: */
    }
/* INITIALIZATION */
    nuld_(&c__1, &_BLNK__1.ndim, &c__1, _BLNK__1.x);
    nul_(&c__1, &_BLNK__1.nels, &c__1, _BLNK__1.idep);
    al__1.aerr = 0;
    al__1.aunit = _BLNK__1.irec;
    f_rew(&al__1);
    _BLNK__1.iset = 0;
L6:
    for (_BLNK__1.i = 1; _BLNK__1.i <= 20; ++_BLNK__1.i) {
	switch_1.pred[_BLNK__1.i - 1] = FALSE_;
/* L23: */
	switch_1.pred1[_BLNK__1.i - 1] = FALSE_;
    }
    nuld_(&c__1, &c__20, &c__1, switch_1.tsw);
/* CONTROL BY COMANDS */
    for (_BLNK__1.i = 1; _BLNK__1.i <= 40; ++_BLNK__1.i) {
	contr1_(&_BLNK__1.ncon, con, &_BLNK__1.key, &_BLNK__1.inp, &
		_BLNK__1.iou);
	if (_BLNK__1.key != 0) {
	    goto L8;
	}
	_BLNK__1.key = ierr_(&_BLNK__1.icont, &_BLNK__1.ncon);
	goto L990;
L8:
	switch ((int)_BLNK__1.key) {
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
	    case 11:  goto L110;
	    case 12:  goto L320;
	    case 13:  goto L300;
	    case 14:  goto L1;
	    case 15:  goto L310;
	    case 16:  goto L330;
	    case 17:  goto L350;
	    case 18:  goto L360;
	    case 19:  goto L370;
	    case 20:  goto L380;
	    case 21:  goto L390;
	    case 22:  goto L400;
	    case 23:  goto L410;
	    case 24:  goto L420;
	    case 25:  goto L430;
	}
/* EXTENT OF DIAGNOSTIC PRINTOUT */
L10:
	rlist_(&_BLNK__1.inp, &_BLNK__1.iou, &_BLNK__1.list);
	goto L990;
/* END OF TR */
L20:
	_BLNK__1.isect = 3;
	return 0;
/* MODE DCALL */
L30:
	_BLNK__1.kdc = 2;
	goto L42;
/* MODE DC */
L40:
	_BLNK__1.kdc = 1;
L42:
	_BLNK__1.idc = 1;
	goto L64;
/* MODE DCTR */
L50:
	_BLNK__1.idc = 1;
	goto L62;
/* MODE TR */
L60:
	_BLNK__1.idc = 0;
L62:
	_BLNK__1.kdc = 0;
/* READ  INTERVAL OF INDEPENDENT VARIABLE */
	rvard_(&_BLNK__1.tmin, &_BLNK__1.tmax, &_BLNK__1.npoint, &
		_BLNK__1.maxpnt, &_BLNK__1.ind, &_BLNK__1.inp, &_BLNK__1.iou);
L64:
	_BLNK__1.nper = 0;
	_BLNK__1.isen = 0;
	_BLNK__1.ihold = 0;
	goto L980;
/* READ  TEMPERATURE */
L70:
	io___5.ciunit = _BLNK__1.inp;
	s_rsfe(&io___5);
	do_fio(&c__1, (char *)&_BLNK__1.temp, (ftnlen)sizeof(doublereal));
	e_rsfe();
	io___6.ciunit = _BLNK__1.iou;
	s_wsfe(&io___6);
	do_fio(&c__1, (char *)&_BLNK__1.temp, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L990;
/* INITIALIZATION OF VECTOR X */
L80:
	primvd_(&_BLNK__1.icont, &_BLNK__1.nels, _BLNK__1.net, &_BLNK__1.nods,
		 _BLNK__1.newn, _BLNK__1.x, &_BLNK__1.ndim, &_BLNK__1.ind, &
		_BLNK__1.inp, &_BLNK__1.iou);
	goto L970;
/* READ  PARAMETRIC DEPENDENT ELEMENTS */
L90:
	fdep_(_BLNK__1.idep, &_BLNK__1.nels, &_BLNK__1.nfun, &_BLNK__1.ind, &
		_BLNK__1.inp, &_BLNK__1.iou);
	goto L970;
/* READ  CONTROL VARIABLES */
L100:
	io___7.ciunit = _BLNK__1.inp;
	s_rsfe(&io___7);
	do_fio(&c__1, (char *)&_BLNK__1.maxit, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.conv, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&_BLNK__1.xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&_BLNK__1.flog, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&_BLNK__1.stepmx, (ftnlen)sizeof(doublereal));
	e_rsfe();
	io___8.ciunit = _BLNK__1.iou;
	s_wsfe(&io___8);
	do_fio(&c__1, (char *)&_BLNK__1.maxit, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.conv, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&_BLNK__1.xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&_BLNK__1.flog, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&_BLNK__1.stepmx, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L990;
/* RUN */
L110:
	_BLNK__1.isect = 1;
	return 0;
/* MODIFICATION OF ELEMENT VALUES */
L300:
	modifd_(&_BLNK__1.nels, _BLNK__1.net, _BLNK__1.val, &_BLNK__1.ind, &
		_BLNK__1.inp, &_BLNK__1.iou);
	goto L980;
/* READ INDEPENDENT VARIABLE IN PLOT */
L310:
	io___9.ciunit = _BLNK__1.inp;
	s_rsfe(&io___9);
	do_fio(&c__1, (char *)&_BLNK__1.ich, (ftnlen)sizeof(integer));
	e_rsfe();
	if (_BLNK__1.ich > _BLNK__1.nsec || _BLNK__1.ich < 0) {
	    _BLNK__1.ich = 0;
	}
	goto L990;

L320:
	plot5_(&_BLNK__1.nsec, &_BLNK__1.ihold, &_BLNK__1.iwdth, &
		_BLNK__1.mplot, &_BLNK__1.nplot, &_BLNK__1.inp, &_BLNK__1.iou)
		;
	_BLNK__1.isect = 2;
	return 0;
/* READ  CONTROL PARAMETERS FOR FFT */
L330:
	io___10.ciunit = _BLNK__1.inp;
	s_rsfe(&io___10);
	do_fio(&c__1, (char *)&_BLNK__1.nper, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.fper, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&_BLNK__1.nhar, (ftnlen)sizeof(integer));
	e_rsfe();
	io___11.ciunit = _BLNK__1.iou;
	s_wsfe(&io___11);
	do_fio(&c__1, (char *)&_BLNK__1.nper, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.fper, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&_BLNK__1.nhar, (ftnlen)sizeof(integer));
	e_wsfe();
/* SET PARAMETERS */
	_BLNK__1.tmin = (float)0.;
	_BLNK__1.tmax = _BLNK__1.fper;
	_BLNK__1.npoint = _BLNK__1.npf;
	_BLNK__1.ihold = 0;
	_BLNK__1.idc = 0;
	_BLNK__1.kdc = 0;
	_BLNK__1.iper = 1;
	goto L990;
/* READ  INDEPENDENT VARIABLE */
L350:
	rind_(_BLNK__1.net, &_BLNK__1.nels, &_BLNK__1.indep, _BLNK__1.namin, &
		_BLNK__1.inp, &_BLNK__1.iou);
	_BLNK__1.ihold = 0;
	goto L990;
/* SAVE */
L360:
	io___12.ciunit = _BLNK__1.irec1;
	s_wsue(&io___12);
	do_uio(&c__1960, (char *)&save[0], (ftnlen)sizeof(real));
	e_wsue();
	goto L375;
/* LOAD */
L370:
	io___13.ciunit = _BLNK__1.irec1;
	s_rsue(&io___13);
	do_uio(&c__1960, (char *)&save[0], (ftnlen)sizeof(real));
	e_rsue();
L375:
	al__1.aerr = 0;
	al__1.aunit = _BLNK__1.irec1;
	f_rew(&al__1);
	goto L990;
/* REFORMULATION OF INTEGRATORS */
L380:
	_BLNK__1.iref = 1;
	goto L990;
L390:
	++_BLNK__1.ihold;
	goto L990;
/* SENSITIVITIES */
L400:
	_BLNK__1.isen = 1;
	goto L415;
/* RELATIVE SENSITIVITIES */
L410:
	_BLNK__1.isen = 2;
L415:
	io___14.ciunit = _BLNK__1.inp;
	s_rsfe(&io___14);
	do_fio(&c__1, (char *)&_BLNK__1.iel, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.delta, (ftnlen)sizeof(doublereal));
	e_rsfe();
	io___15.ciunit = _BLNK__1.iou;
	s_wsfe(&io___15);
	do_fio(&c__1, (char *)&_BLNK__1.iel, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&_BLNK__1.delta, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L990;
/* чтение номеров эл-ов,на кот.вычисл.пульс.напряж. */
L420:
	pulc_(&_BLNK__1.nsec, _BLNK__1.namey, &_BLNK__1.nels, _BLNK__1.net, 
		_BLNK__1.mpulc, &_BLNK__1.ind, &_BLNK__1.inp, &_BLNK__1.iou);
	_BLNK__1.nper = 0;
	_BLNK__1.isen = 0;
	_BLNK__1.ihold = 0;
	goto L980;
/* TRIN - печать TR- */
L430:
	_BLNK__1.kdc = 3;
	goto L980;
/* ERROR MESSAGE IF LIST EXCEEDED */
L970:
	if (_BLNK__1.ind == 20) {
	    io___16.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___16);
	    e_wsfe();
	}
/* ERROR TEST */
L980:
	_BLNK__1.ind = ierr_(&_BLNK__1.icont, &_BLNK__1.ind);
L990:
	;
    }
/* EXCEEDING NUMBER OF COMMANDS */
    _BLNK__1.ind = 10;
    return 0;
} /* trr_ */

#undef save
#undef itime
#undef con


/* Subroutine */ int rvard_(xmin, xmax, npoint, maxpnt, ind, inp, iprnt)
doublereal *xmin, *xmax;
integer *npoint, *maxpnt, *ind, *inp, *iprnt;
{
    /* Format strings */
    static char fmt_100[] = "(2f9.5,i5)";
    static char fmt_200[] = "(//\002 интервал изменения\002,\002 независимой\
 переменной :\002//\002 минимум =\002,1pd12.5,4x,\002максимум =\002,1pd12.5,\
4x,\002число точек =\002,i3)";
    static char fmt_300[] = "(//\002 внимание : число точек исправлено на\
\002,i3)";
    static char fmt_400[] = "(//\002 ошибка : заданный минимум больше максим\
ума\002)";

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();

    /* Fortran I/O blocks */
    static cilist io___19 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___20 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___21 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___22 = { 0, 0, 0, fmt_400, 0 };


/*     **************** */

/*     19.3.1981 */
    *ind = 0;
    io___19.ciunit = *inp;
    s_rsfe(&io___19);
    do_fio(&c__1, (char *)&(*xmin), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*xmax), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*npoint), (ftnlen)sizeof(integer));
    e_rsfe();
    io___20.ciunit = *iprnt;
    s_wsfe(&io___20);
    do_fio(&c__1, (char *)&(*xmin), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*xmax), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*npoint), (ftnlen)sizeof(integer));
    e_wsfe();
    if (*npoint > *maxpnt || *npoint <= 1) {
	io___21.ciunit = *iprnt;
	s_wsfe(&io___21);
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
	io___22.ciunit = *iprnt;
	s_wsfe(&io___22);
	e_wsfe();
    }
    return 0;
} /* rvard_ */

/* Subroutine */ int primvd_(icont, nels, net, n, newn, x, ndim, ind, inp, 
	iou)
integer *icont, *nels, *net, *n, *newn;
doublereal *x;
integer *ndim, *ind, *inp, *iou;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_43 = { {'V', 'N', ' ', ' '}, 0 };

#define ivn (*(integer *)&equiv_43)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_44 = { {'Y', ' ', ' ', ' '}, 0 };

#define iy (*(integer *)&equiv_44)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_45 = { {'I', ' ', ' ', ' '}, 0 };

#define ii (*(integer *)&equiv_45)

    static struct {
	char e_1[8];
	integer e_2;
	} equiv_46 = { {'B', 'L', ' ', ' ', 'O', 'K', ' ', ' '}, 0 };

#define ibl ((integer *)&equiv_46)

    static struct {
	char e_1[8];
	integer e_2;
	} equiv_47 = { {'U', 'Z', ' ', ' ', 'E', 'L', ' ', ' '}, 0 };

#define ino ((integer *)&equiv_47)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_48 = { {' ', ' ', ' ', ' '}, 0 };

#define iend (*(integer *)&equiv_48)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_49 = { {'F', ' ', ' ', ' '}, 0 };

#define nf (*(integer *)&equiv_49)


    /* Format strings */
    static char fmt_100[] = "(//\002 начальные условия :\002//)";
    static char fmt_200[] = "(a2,i5,f9.5)";
    static char fmt_300[] = "(5x,a2,i3,\002 = \002,1pd13.5)";
    static char fmt_600[] = "(\002 ошибка : из-за неправильного обозначения\
 \002,\002начальное условие игнорируется\002)";
    static char fmt_400[] = "(\002 ошибка : \002,2a2,\002 номер \002,i2,\002\
 не был определен\002)";
    static char fmt_500[] = "(\002 ошибка : элементу номер \002,i2,\002 нель\
зя приписать\002,\002 начальный ток\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
    static integer ityp, i, j, k, jj, iw[2];
    static doublereal val;

    /* Fortran I/O blocks */
    static cilist io___30 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___32 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_600, 0 };
    static cilist io___40 = { 0, 0, 0, fmt_400, 0 };
    static cilist io___42 = { 0, 0, 0, fmt_500, 0 };


/*     ***************** */

/*     6.10.1987 */
    /* Parameter adjustments */
    --x;
    --newn;
    net -= 6;

    /* Function Body */
    io___30.ciunit = *iou;
    s_wsfe(&io___30);
    e_wsfe();
    i__1 = *ndim;
    for (i = 1; i <= i__1; ++i) {
/* L11: */
	x[i] = 0.;
    }
    i__1 = *ndim;
    for (i = 1; i <= i__1; ++i) {
	io___32.ciunit = *inp;
	s_rsfe(&io___32);
	do_fio(&c__1, (char *)&ityp, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&val, (ftnlen)sizeof(doublereal));
	e_rsfe();
	if (ityp == iend) {
	    return 0;
	}
	io___36.ciunit = *iou;
	s_wsfe(&io___36);
	do_fio(&c__1, (char *)&ityp, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&val, (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (*icont == 2) {
	    goto L2;
	}
	if (ityp == ii) {
	    goto L40;
	}
	if (ityp == ivn) {
	    goto L5;
	}
	if (ityp == nf) {
	    goto L1;
	}
	goto L3;

L1:
	if (j > 20) {
	    goto L60;
	}
	switch_1.pred[j - 1] = TRUE_;
	switch_1.pred1[j - 1] = TRUE_;
	goto L60;
L2:
	if (ityp == iy) {
	    goto L4;
	}
L3:
	io___37.ciunit = *iou;
	s_wsfe(&io___37);
	e_wsfe();
	goto L60;
L4:
	if (j < 0 || j > *nels) {
	    goto L20;
	}
	k = newn[j];
	if (k == 0) {
	    goto L20;
	}
	goto L30;

L5:
	i__2 = *n;
	for (k = 1; k <= i__2; ++k) {
	    if (j == newn[k]) {
		goto L30;
	    }
/* L10: */
	}

L20:
	iw[0] = ino[0];
	iw[1] = ino[1];
	if (ityp == iy) {
	    iw[0] = ibl[0];
	}
	if (ityp == iy) {
	    iw[1] = ibl[1];
	}
	io___40.ciunit = *iou;
	s_wsfe(&io___40);
	do_fio(&c__2, (char *)&iw[0], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	e_wsfe();
	goto L60;
L30:
	x[k] = val;
	goto L60;

L40:
	if (j > *nels || j < 0) {
	    goto L50;
	}
	jj = net[j * 5 + 5];
	if (jj == 0 || net[j * 5 + 1] == 0) {
	    goto L50;
	}
	x[jj] = val;
	goto L60;

L50:
	io___42.ciunit = *iou;
	s_wsfe(&io___42);
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	e_wsfe();
L60:
	;
    }
    *ind = 20;
    return 0;
} /* primvd_ */

#undef nf
#undef iend
#undef ino
#undef ibl
#undef ii
#undef iy
#undef ivn


/* Subroutine */ int rind_(net, nels, indep, namin, inp, iou)
integer *net, *nels, *indep, *namin, *inp, *iou;
{
    /* Initialized data */

    static struct {
	char e_1[8];
	integer e_2;
	} equiv_57 = { {'T', 'E', ' ', ' ', 'M', 'P', ' ', ' '}, 0 };

#define itemp ((integer *)&equiv_57)

    static struct {
	char e_1[8];
	integer e_2;
	} equiv_58 = { {'T', 'I', ' ', ' ', 'M', 'E', ' ', ' '}, 0 };

#define itime ((integer *)&equiv_58)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_59 = { {' ', ' ', ' ', ' '}, 0 };

#define ib (*(integer *)&equiv_59)


    /* Format strings */
    static char fmt_100[] = "(i5)";
    static char fmt_110[] = "(//\002 независимая переменная = \002,2a2,i2)";
    static char fmt_120[] = "(//\002 ошибка : элемент номер \002,i3,3x,\002н\
е существует\002/)";

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();

    /* Local variables */
    extern integer ncode_();

    /* Fortran I/O blocks */
    static cilist io___53 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___54 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___55 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___56 = { 0, 0, 0, fmt_110, 0 };


/*     *************** */

/*     12.01.1984 */
    /* Parameter adjustments */
    --namin;
    net -= 6;

    /* Function Body */
    io___53.ciunit = *inp;
    s_rsfe(&io___53);
    do_fio(&c__1, (char *)&(*indep), (ftnlen)sizeof(integer));
    e_rsfe();
L10:
    if (*indep != 0) {
	goto L12;
    }
    namin[1] = itime[0];
    namin[2] = itime[1];
L12:
    if (*indep >= 0) {
	goto L13;
    }
    namin[1] = itemp[0];
    namin[2] = itemp[1];
L13:
    if (*indep > 0) {
	goto L14;
    }
    io___54.ciunit = *iou;
    s_wsfe(&io___54);
    do_fio(&c__2, (char *)&namin[1], (ftnlen)sizeof(integer));
    e_wsfe();
    goto L99;
L14:
    if (*indep > *nels) {
	goto L15;
    }
    if (net[*indep * 5 + 1] != 0) {
	goto L20;
    }
/* INDEPENDENT VARIABLE WRONG */
L15:
    io___55.ciunit = *iou;
    s_wsfe(&io___55);
    e_wsfe();
    *indep = 0;
    goto L10;
L20:
/* PRINT OUT INDEPENDENT VARIABLE */
    namin[1] = ncode_(&net[*indep * 5 + 1], &c__1);
    namin[2] = ib;
    io___56.ciunit = *iou;
    s_wsfe(&io___56);
    do_fio(&c__2, (char *)&namin[1], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*indep), (ftnlen)sizeof(integer));
    e_wsfe();
L99:
    return 0;
} /* rind_ */

#undef ib
#undef itime
#undef itemp


/* Subroutine */ int vars_(ivar, ivars)
integer *ivar, *ivars;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_64 = { {'V', ' ', ' ', ' '}, 0 };

#define iv (*(integer *)&equiv_64)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_65 = { {'I', ' ', ' ', ' '}, 0 };

#define ii (*(integer *)&equiv_65)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_66 = { {'P', ' ', ' ', ' '}, 0 };

#define ip (*(integer *)&equiv_66)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_67 = { {'V', 'D', ' ', ' '}, 0 };

#define ivd (*(integer *)&equiv_67)


/*     *************************** */
/* символическое обозначениевыходных величин <I>,<V>,<P>,<VD> */
/*     21.01.1987 (dorabotal - cyrulxnik a.a.) */
    *ivars = iv;
    if (*ivar >= 100) {
	*ivars = ivd;
    }
    if (*ivar < 0) {
	goto L10;
    }
    return 0;
L10:
    *ivars = ii;
    if (*ivar <= -100) {
	*ivars = ip;
    }
    return 0;
} /* vars_ */

#undef ivd
#undef ip
#undef ii
#undef iv


/* Subroutine */ int fdep_(idep, nels, nf, ind, inp, iou)
integer *idep, *nels, *nf, *ind, *inp, *iou;
{
    /* Format strings */
    static char fmt_100[] = "(//1x,\002зависимые элементы :\002//8x,\002элем\
ент\002,5x,\002функция\002/)";
    static char fmt_110[] = "(2i5)";
    static char fmt_140[] = "(10x,i2,10x,i2)";
    static char fmt_120[] = "(//\002 ошибка : элемент номер \002,i3,3x,\002н\
е существует\002/)";
    static char fmt_130[] = "(//\002 ощибка : функция номер \002,i3,3x,\002н\
е определена\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
    static integer ifun, i, iel;

    /* Fortran I/O blocks */
    static cilist io___69 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___70 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___73 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___74 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___75 = { 0, 0, 0, fmt_130, 0 };


/*     *************** */
/*  23.5.87 */

    /* Parameter adjustments */
    --idep;

    /* Function Body */
    *ind = 0;
    i__1 = *nels;
    for (i = 1; i <= i__1; ++i) {
/* L10: */
	idep[i] = 0;
    }
    io___69.ciunit = *iou;
    s_wsfe(&io___69);
    e_wsfe();
    i__1 = *nels;
    for (i = 1; i <= i__1; ++i) {
	io___70.ciunit = *inp;
	s_rsfe(&io___70);
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ifun, (ftnlen)sizeof(integer));
	e_rsfe();
	if (iel == 0) {
	    return 0;
	}
	io___73.ciunit = *iou;
	s_wsfe(&io___73);
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ifun, (ftnlen)sizeof(integer));
	e_wsfe();
	if (iel > 0 && iel <= *nels) {
	    goto L20;
	}

	io___74.ciunit = *iou;
	s_wsfe(&io___74);
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	e_wsfe();
	*ind = 1;
L20:
	if (ifun > 0 && ifun <= *nf) {
	    goto L40;
	}

	io___75.ciunit = *iou;
	s_wsfe(&io___75);
	do_fio(&c__1, (char *)&ifun, (ftnlen)sizeof(integer));
	e_wsfe();
/* L30: */
	*ind = 1;
L40:
	if (*ind == 0) {
	    idep[iel] = ifun;
	}
/* L50: */
    }
    *ind = 20;
    return 0;
} /* fdep_ */

/* Subroutine */ int modifd_(nels, net, val, ind, input, iout)
integer *nels, *net;
doublereal *val;
integer *ind, *input, *iout;
{
    /* Format strings */
    static char fmt_110[] = "(//22x,\002модифицированные элементы\002//22x\
,\002элемент\002,5x,\002параметр\002/)";
    static char fmt_120[] = "(i5,d9.5)";
    static char fmt_130[] = "(21x,a4,i2,1pd15.5)";
    static char fmt_140[] = "(1x,\002ошибка : задана модификация\002,1x,\002\
несуществующего элемента\002)";
    static char fmt_150[] = "(1x,\002 ошибка : не найден ожидаемый знак окон\
чания\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
    extern /* Subroutine */ int pars2_();
    static integer i, ielem, ipars, nelsp1;
    static doublereal valmod;

    /* Fortran I/O blocks */
    static cilist io___76 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___79 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___83 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___84 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___85 = { 0, 0, 0, fmt_150, 0 };


/*     ***************** */
/* MODIFIKACE 1. PARAMETRU PRVKU */
/*     20.5.1981 */
    /* Parameter adjustments */
    --val;
    net -= 6;

    /* Function Body */
    io___76.ciunit = *iout;
    s_wsfe(&io___76);
    e_wsfe();
    nelsp1 = *nels + 1;
    i__1 = nelsp1;
    for (i = 1; i <= i__1; ++i) {
	io___79.ciunit = *input;
	s_rsfe(&io___79);
	do_fio(&c__1, (char *)&ielem, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&valmod, (ftnlen)sizeof(doublereal));
	e_rsfe();
	if (ielem == 0) {
	    goto L20;
	}
	pars2_(nels, &net[6], &ielem, &ipars);
	io___83.ciunit = *iout;
	s_wsfe(&io___83);
	do_fio(&c__1, (char *)&ipars, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ielem, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&valmod, (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (ielem > 0 && ielem <= *nels) {
	    goto L5;
	}
	*ind = 1;
	io___84.ciunit = *iout;
	s_wsfe(&io___84);
	e_wsfe();
	goto L20;
L5:
	val[ielem] = valmod;
/* L10: */
    }
    *ind = 2;
    io___85.ciunit = *iout;
    s_wsfe(&io___85);
    e_wsfe();
L20:
    return 0;
} /* modifd_ */

/* Subroutine */ int pars2_(nels, net, ipar, ipars)
integer *nels, *net, *ipar, *ipars;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_87 = { {'T', 'E', ' ', ' '}, 0 };

#define itemp (*(integer *)&equiv_87)


    extern integer ncode_();

/*     **************** */
/*     3.9.1981 */

    /* Parameter adjustments */
    net -= 6;

    /* Function Body */
    if (*ipar <= 0) {
	goto L10;
    }
    *ipars = ncode_(&net[*ipar * 5 + 1], &c__1);
    return 0;
L10:
    *ipars = itemp;
    return 0;
} /* pars2_ */

#undef itemp


/* Subroutine */ int plot5_(nsec, ihold, iwdth, mplot, nplot, inp, iou)
integer *nsec, *ihold, *iwdth, *mplot, *nplot, *inp, *iou;
{
    /* Initialized data */

    static struct {
	char e_1[28];
	integer e_2;
	} equiv_101 = { {'\257', '\256', ' ', ' ', '\253', '\255', ' ', ' ', 
		'\353', '\251', ' ', ' ', ' ', '\253', ' ', ' ', '\250', 
		'\341', ' ', ' ', '\342', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
		0 };

#define iwd1 ((integer *)&equiv_101)

    static struct {
	char e_1[28];
	integer e_2;
	} equiv_102 = { {'\257', '\256', ' ', ' ', '\253', '\256', ' ', ' ', 
		'\242', '\250', ' ', ' ', '\255', '\240', ' ', ' ', ' ', 
		'\253', ' ', ' ', '\250', '\341', ' ', ' ', '\342', '\240', 
		' ', ' '}, 0 };

#define iwd2 ((integer *)&equiv_102)

    static struct {
	char e_1[28];
	integer e_2;
	} equiv_103 = { {'\250', '\255', ' ', ' ', '\244', '\250', ' ', ' ', 
		'\242', '\250', ' ', ' ', '\244', '\343', ' ', ' ', '\240', 
		'\253', ' ', ' ', '\354', '\255', ' ', ' ', '\353', '\251', 
		' ', ' '}, 0 };

#define mpl1 ((integer *)&equiv_103)

    static struct {
	char e_1[28];
	integer e_2;
	} equiv_104 = { {'\256', '\241', ' ', ' ', '\351', '\250', ' ', ' ', 
		'\251', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		 ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 0 };

#define mpl2 ((integer *)&equiv_104)


    /* Format strings */
    static char fmt_110[] = "(//15x,\002управление печатью графиков :\002/)";
    static char fmt_100[] = "(3i5)";
    static char fmt_120[] = "(10x,\002ширина печати\002,18(\002.\002),\002 -\
 < \002,7a2,\002 >\002)";
    static char fmt_130[] = "(10x,\002масштаб построения графиков\002,4\
(\002.\002),\002 - < \002,7a2,\002 >\002)";
    static char fmt_140[] = "(10x,\002число графиков:\002/10x,\002общее коли\
чество\002,15(\002.\002),\002 - <\002,i2,\002 >\002/10x,\002в одной систем\
е\002,1x,\002координат\002,6(\002.\002),\002 - <\002,i2,\002 >\002)";
    static char fmt_150[] = "(/\002 ошибка : неправильно задано управлени\
е\002,1x,\002печатью графиков\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
    static integer nplmax;

    /* Fortran I/O blocks */
    static cilist io___92 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___93 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___94 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___95 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___96 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___97 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___99 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___100 = { 0, 0, 0, fmt_150, 0 };


/*     **************** */

/*     25.01.1984 ( razrabotal - cyrulxnik ) */
    io___92.ciunit = *iou;
    s_wsfe(&io___92);
    e_wsfe();
    io___93.ciunit = *inp;
    s_rsfe(&io___93);
    do_fio(&c__1, (char *)&(*iwdth), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*mplot), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*nplot), (ftnlen)sizeof(integer));
    e_rsfe();
/* opredelenie {iriny pe~ati */
    if (*iwdth == 0) {
	io___94.ciunit = *iou;
	s_wsfe(&io___94);
	do_fio(&c__7, (char *)&iwd1[0], (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (*iwdth == 1) {
	io___95.ciunit = *iou;
	s_wsfe(&io___95);
	do_fio(&c__7, (char *)&iwd2[0], (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (*iwdth < 0 || *iwdth >= 2) {
	goto L80;
    }
/* opredelenie mas{taba */
    if (*mplot == 0) {
	io___96.ciunit = *iou;
	s_wsfe(&io___96);
	do_fio(&c__7, (char *)&mpl1[0], (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (*mplot == 1) {
	io___97.ciunit = *iou;
	s_wsfe(&io___97);
	do_fio(&c__7, (char *)&mpl2[0], (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (*mplot < 0 || *mplot >= 2) {
	goto L80;
    }
/* opred.MAX ~isla grafikow i w odnoj sis-me koordin. */
    nplmax = *nsec;
    if (*nplot != 0 && *ihold == 0) {
	goto L40;
    }
    if (*nplot != 0 && *ihold != 0) {
	goto L30;
    }
    if (*nplot == 0 && *ihold == 0) {
	goto L20;
    }
    *nplot = *ihold + 1;
    goto L30;
L20:
    *nplot = *nsec;
    goto L40;
L30:
    nplmax = *ihold + 1;
L40:
    io___99.ciunit = *iou;
    s_wsfe(&io___99);
    do_fio(&c__1, (char *)&nplmax, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*nplot), (ftnlen)sizeof(integer));
    e_wsfe();
    if (*nplot < 0 || *nplot > nplmax) {
	goto L80;
    }
    return 0;
L80:
    io___100.ciunit = *iou;
    s_wsfe(&io___100);
    e_wsfe();
    return 0;
} /* plot5_ */

#undef mpl2
#undef mpl1
#undef iwd2
#undef iwd1


/* Subroutine */ int pars1_(nels, net, ipar, ipars)
integer *nels, *net, *ipar, *ipars;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_106 = { {'T', 'E', ' ', ' '}, 0 };

#define itemp (*(integer *)&equiv_106)


    extern integer ncode_();

/*    ************************************* */
/*    3.9.1981 */
/*    SYMBOLICKE OZNACOVANI PARAMETRU */
    /* Parameter adjustments */
    net -= 6;

    /* Function Body */
    if (*ipar <= 0) {
	goto L10;
    }
    *ipars = ncode_(&net[*ipar * 5 + 1], &c__1);
    return 0;
L10:
    *ipars = itemp;
    return 0;
} /* pars1_ */

#undef itemp


/* Subroutine */ int pulc_(nsec, namey, nels, net, mpulc, ind, inp, iou)
integer *nsec, *namey, *nels, *net, *mpulc, *ind, *inp, *iou;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_122 = { {'V', ' ', ' ', ' '}, 0 };

#define namev (*(integer *)&equiv_122)


    /* Format strings */
    static char fmt_110[] = "(//\002 вычисление коэффициента пульсации напря\
жения на\002,1x,\002элементх :\002//25x,\002тип\002,2x,\002номер\002)";
    static char fmt_100[] = "(i4)";
    static char fmt_150[] = "(/\002 ошибка : число элементов с вычислением к\
оэф.\002,1x,\002пульсации превышает допустимое\002,i4)";
    static char fmt_120[] = "(/\002 ошибка : задано вычисление коэф. пульсац\
ии\002,1x,\002 на несуществующем элементе\002)";
    static char fmt_130[] = "(26x,a2,2x,i3)";
    static char fmt_160[] = "(/\002 ошибка : напряжение на элементе < \002,a\
2,i2,\002 > не является выходной величиной\002)";
    static char fmt_140[] = "(/\002 ошибка : не найден ожидаемывй знак оконч\
ания\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
    static integer ivar, nsec1;
    extern /* Subroutine */ int pars1_();
    static integer i, j, ielem, nomel, ipars;

    /* Fortran I/O blocks */
    static cilist io___108 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___111 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___113 = { 0, 0, 0, fmt_150, 0 };
    static cilist io___114 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___116 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___120 = { 0, 0, 0, fmt_160, 0 };
    static cilist io___121 = { 0, 0, 0, fmt_140, 0 };


/*     *************** */
/* чтение элементов,на которых выч.коэф. */
/*     18.01.1984 ( razrab. - cyrulxnik ) */
    /* Parameter adjustments */
    --mpulc;
    net -= 6;
    namey -= 3;

    /* Function Body */
    *ind = 0;
    io___108.ciunit = *iou;
    s_wsfe(&io___108);
    e_wsfe();
    nsec1 = *nsec + 1;
    i__1 = nsec1;
    for (i = 1; i <= i__1; ++i) {
	io___111.ciunit = *inp;
	s_rsfe(&io___111);
	do_fio(&c__1, (char *)&ielem, (ftnlen)sizeof(integer));
	e_rsfe();
	mpulc[i] = ielem;
	if (ielem == 0) {
	    goto L90;
	}
/* prowerka ~isla |lementow */
	if (i <= *nsec) {
	    goto L5;
	}
	*ind = 1;
	io___113.ciunit = *iou;
	s_wsfe(&io___113);
	do_fio(&c__1, (char *)&(*nsec), (ftnlen)sizeof(integer));
	e_wsfe();
	goto L90;
/* prowerka nomera |lementa */
L5:
	if (ielem > 0 && ielem <= *nels) {
	    goto L10;
	}
	*ind = 1;
	io___114.ciunit = *iou;
	s_wsfe(&io___114);
	e_wsfe();
	goto L90;
/* identifikaciq tipa |lementa */
L10:
	pars1_(nels, &net[6], &ielem, &ipars);
	io___116.ciunit = *iou;
	s_wsfe(&io___116);
	do_fio(&c__1, (char *)&ipars, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ielem, (ftnlen)sizeof(integer));
	e_wsfe();
/* qwl. li naprqv. na |l-te wyh. weli~inoj? */
	i__2 = *nsec;
	for (j = 1; j <= i__2; ++j) {
	    ivar = namey[(j << 1) + 1];
	    if (ivar != namev) {
		goto L15;
	    }
	    nomel = namey[(j << 1) + 2];
	    if (ielem == nomel) {
		goto L20;
	    }
L15:
	    ;
	}
	*ind = 1;
	io___120.ciunit = *iou;
	s_wsfe(&io___120);
	do_fio(&c__1, (char *)&ipars, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ielem, (ftnlen)sizeof(integer));
	e_wsfe();
	goto L90;
L20:
	;
    }
    *ind = 2;
    io___121.ciunit = *iou;
    s_wsfe(&io___121);
    e_wsfe();
L90:
    return 0;
} /* pulc_ */

#undef namev


/* Subroutine */ int vpulc_(mpulc, namey, nsec, npoint, nels, net, iou, irec)
integer *mpulc, *namey, *nsec, *npoint, *nels, *net, *iou, *irec;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_148 = { {'V', ' ', ' ', ' '}, 0 };

#define namev (*(integer *)&equiv_148)


    /* Format strings */
    static char fmt_100[] = "(///15x,\002оценка качества стабилизации\002,\
1x,\002напряжения\002/15x,39(\002*\002)//28x,\002относит.коэф.\002,4x,\002дв\
ойная амплитуда\002/10x,\002элемент  номер\002,4x,\002пульсации (%)    пульс\
ации ( MB )\002)";
    static char fmt_110[] = "(/13x,a2,4x,i3,8x,f7.3,9x,f10.3)";
    static char fmt_120[] = "(/\002 оценка качества стабилизации на\002,1x\
,\002элементе < \002,a2,i2,\002 > не имеет смысла\002)";

    /* System generated locals */
    integer i__1, i__2;
    alist al__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), f_rew(), s_rsue(), do_uio(), e_rsue(), do_fio(
	    );

    /* Local variables */
    static real graf[650]	/* was [65][10] */;
    static integer ivar;
    static real vmin, vmax;
    static integer nsec1;
    extern /* Subroutine */ int pars1_();
    static integer i, j, k, n, ielem;
    static real pulab;
    static integer nomel, ipars;
    static real pulot;
    static integer jj;
    static real vm, vm1, vm2;
    static doublereal buf[10];
    static real vsr;

    /* Fortran I/O blocks */
    static cilist io___124 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___126 = { 0, 0, 0, 0, 0 };
    static cilist io___146 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___147 = { 0, 0, 0, fmt_120, 0 };


/*     **************** */

/*     20.01.1984 ( razrab. - cyrulxnik ) */
    /* Parameter adjustments */
    net -= 6;
    namey -= 3;
    --mpulc;

    /* Function Body */
    io___124.ciunit = *iou;
    s_wsfe(&io___124);
    e_wsfe();
/* ~tenie naprqvenij s diska w bufer */
    al__1.aerr = 0;
    al__1.aunit = *irec;
    f_rew(&al__1);
    i__1 = *npoint;
    for (i = 1; i <= i__1; ++i) {
	io___126.ciunit = *irec;
	s_rsue(&io___126);
	i__2 = *nsec;
	for (jj = 1; jj <= i__2; ++jj) {
	    do_uio(&c__1, (char *)&buf[jj - 1], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
	i__2 = *nsec;
	for (k = 1; k <= i__2; ++k) {
	    graf[i + k * 65 - 66] = buf[k - 1];
/* L2: */
	}
/* L4: */
    }
/* cikl po |lementam, u kot.  wy~isl. ko|f. pulxsacii */
    nsec1 = *nsec + 1;
    i__1 = nsec1;
    for (n = 1; n <= i__1; ++n) {
	ielem = mpulc[n];
	if (ielem == 0) {
	    goto L90;
	}
/* ustanowlenie swqzi mevdu |lem. i nom. wyh.weli~in */
	i__2 = *nsec;
	for (j = 1; j <= i__2; ++j) {
	    ivar = namey[(j << 1) + 1];
	    if (ivar != namev) {
		goto L10;
	    }
	    nomel = namey[(j << 1) + 2];
	    if (nomel == ielem) {
		goto L20;
	    }
L10:
	    ;
	}
/* nomer wyh. weli~iny */
L20:
	k = j;
/* priswoenie na~alxnyh zna~enij */
	vm1 = (float)-1e5;
	vm2 = (float)1e5;
	vsr = (float)0.;
	i__2 = *npoint;
	for (i = 2; i <= i__2; ++i) {
	    vm = graf[i + k * 65 - 66];
	    vsr += vm;
/* wybor maksimalxnogo naprqvenniq */
	    if (vm > vm1) {
		vmax = vm;
	    }
	    vm1 = vmax;
/* wybor minimalxnogo naprqveniq */
	    if (vm < vm2) {
		vmin = vm;
	    }
	    vm2 = vmin;
/* L30: */
	}
	pars1_(nels, &net[6], &ielem, &ipars);
	vsr /= (real) (*npoint - 1);
	if (vsr == (float)0.) {
	    goto L50;
	}
	if (vsr < (float)0.) {
	    vsr = -(doublereal)vsr;
	}
	pulab = (vmax - vmin) * (float)1e3;
	pulot = (vmax - vmin) / vsr * (float)100.;
	io___146.ciunit = *iou;
	s_wsfe(&io___146);
	do_fio(&c__1, (char *)&ipars, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ielem, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&pulot, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&pulab, (ftnlen)sizeof(real));
	e_wsfe();
	goto L60;
L50:
	io___147.ciunit = *iou;
	s_wsfe(&io___147);
	do_fio(&c__1, (char *)&ipars, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ielem, (ftnlen)sizeof(integer));
	e_wsfe();
L60:
	;
    }
L90:
    return 0;
} /* vpulc_ */

#undef namev


/* Subroutine */ int dcalld_(net, nels, n, newn, nods, x, iou)
integer *net, *nels, *n, *newn, *nods;
doublereal *x;
integer *iou;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_159 = { {'V', 'N', ' ', ' '}, 0 };

#define iv (*(integer *)&equiv_159)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_160 = { {'I', ' ', ' ', ' '}, 0 };

#define ii (*(integer *)&equiv_160)


    /* Format strings */
    static char fmt_100[] = "(//7x,\002первичные величины\002//7x,\002номе\
р\002,3x,\002величина\002,5x,\002зйачение\002/)";
    static char fmt_120[] = "(7x,i3,6x,a2,i4,1pd15.5)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
    static integer nods1, i, j, jj, iii;

    /* Fortran I/O blocks */
    static cilist io___151 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___154 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___158 = { 0, 0, 0, fmt_120, 0 };


/*     ***************** */
/* печать  DC- */
/*     2.11.1981 */
    /* Parameter adjustments */
    --x;
    --newn;
    net -= 6;

    /* Function Body */
    io___151.ciunit = *iou;
    s_wsfe(&io___151);
    e_wsfe();
/* NODE VOLTAGES */
    i__1 = *nods;
    for (iii = 1; iii <= i__1; ++iii) {
	i = iii;
/* L10: */
	io___154.ciunit = *iou;
	s_wsfe(&io___154);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&iv, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&newn[i], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&x[i], (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (*n <= *nods) {
	goto L50;
    }
/* CURRENTS */
    nods1 = *nods + 1;
    i__1 = *n;
    for (iii = nods1; iii <= i__1; ++iii) {
	i = iii;
/* FIND ELEMENT */
	i__2 = *nels;
	for (jj = 1; jj <= i__2; ++jj) {
	    j = jj;
	    if (net[j * 5 + 5] == i) {
		io___158.ciunit = *iou;
		s_wsfe(&io___158);
		do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&ii, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&x[i], (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
/* L20: */
	    if (net[j * 5 + 5] == i) {
		goto L40;
	    }
	}
L40:
	;
    }
L50:
    return 0;
} /* dcalld_ */

#undef ii
#undef iv


/* Subroutine */ int stat_(nstep, iou)
integer *nstep, *iou;
{
    /* Format strings */
    static char fmt_100[] = "(//15x,\002статистика  вычислений :\002//6x,\
\002число шагов интегрирования     =\002,i5/6x,\002число отклоненных шагов  \
      =\002,i5/6x,\002число итераций                 =\002,i5/6x,\002число и\
тераций с лог. демпфир. =\002,i5//6x,\002порядок интегрирования         =   \
 0\002,6i5/6x,\002число шагов iинтегрирования    =\002,7i5/)";

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer ij;

    /* Fortran I/O blocks */
    static cilist io___161 = { 0, 0, 0, fmt_100, 0 };


/*     *************** */

/*     23.6.1987 */
    /* Parameter adjustments */
    --nstep;

    /* Function Body */
    io___161.ciunit = *iou;
    s_wsfe(&io___161);
    do_fio(&c__1, (char *)&nstep[3], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nstep[7], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nstep[2], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nstep[8], (ftnlen)sizeof(integer));
    for (ij = 1; ij <= 6; ++ij) {
	do_fio(&c__1, (char *)&ij, (ftnlen)sizeof(integer));
    }
    for (ij = 1; ij <= 7; ++ij) {
	do_fio(&c__1, (char *)&nstep[ij + 9], (ftnlen)sizeof(integer));
    }
    e_wsfe();
    return 0;
} /* stat_ */

/* Subroutine */ int trin_(net, nels, neqs, newn, nods, x, iou)
integer *net, *nels, *neqs, *newn, *nods;
doublereal *x;
integer *iou;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_172 = { {'V', 'N', ' ', ' '}, 0 };

#define iv (*(integer *)&equiv_172)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_173 = { {'I', ' ', ' ', ' '}, 0 };

#define ii (*(integer *)&equiv_173)


    /* Format strings */
    static char fmt_100[] = "(///15x,\002полный вектор решения в последней т\
очке\002/15x,\002(нач.условия для дальнейших вычислений)\002/15x,39(\002*\
\002)//14x,\002тип величины\002,13x,\002номер\002,8x,\002значение\002/9x,\
\002(узл.потенц.,ток эл-та)\002,4x,\002(узла,эл-та)\002,4x,\002( в,а  )\002/)"
	    ;
    static char fmt_120[] = "(19x,a2,19x,i3,7x,1pd12.5)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
    static integer nods1, i, j, jj;

    /* Fortran I/O blocks */
    static cilist io___165 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___167 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___171 = { 0, 0, 0, fmt_120, 0 };


/*     *************** */
/* печать TR- */
/*     12.04.1984 ( razrab. - cyrulxnik ) */
    /* Parameter adjustments */
    --x;
    --newn;
    net -= 6;

    /* Function Body */
    io___165.ciunit = *iou;
    s_wsfe(&io___165);
    e_wsfe();
/* pe~atx uzlowyh potencialow " VN " */
    i__1 = *nods;
    for (i = 1; i <= i__1; ++i) {
/* L10: */
	io___167.ciunit = *iou;
	s_wsfe(&io___167);
	do_fio(&c__1, (char *)&iv, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&newn[i], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&x[i], (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (*neqs <= *nods) {
	goto L50;
    }
/* pe~atx tokow ~erez |l-ty,u kot. wy~islqetsq tok " I " */
    nods1 = *nods + 1;
    i__1 = *neqs;
    for (i = nods1; i <= i__1; ++i) {
/* opredelenie nomera |l-ta */
	i__2 = *nels;
	for (jj = 1; jj <= i__2; ++jj) {
	    j = jj;
	    if (net[j * 5 + 5] == i) {
		io___171.ciunit = *iou;
		s_wsfe(&io___171);
		do_fio(&c__1, (char *)&ii, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&x[i], (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
/* L20: */
	    if (net[j * 5 + 5] == i) {
		goto L40;
	    }
	}
L40:
	;
    }
L50:
    return 0;
} /* trin_ */

#undef ii
#undef iv


/* Subroutine */ int pakt_(namey, nsec, npoint, nels, net, irec, iout)
integer *namey, *nsec, *npoint, *nels, *net, *irec, *iout;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_191 = { {'P', ' ', ' ', ' '}, 0 };

#define namep (*(integer *)&equiv_191)


    /* Format strings */
    static char fmt_2000[] = "(///15x,\002результаты энергетического анализ\
а\002,1x,\002схемы\002/15x,40(\002*\002)//17x,35(\002=\002)/17x,\002I  тип и\
 номер  I  активная       I\002/17x,\002I  элемента     I  мощность (вт)  \
I\002/17x,\002I===============I=================I\002)";
    static char fmt_2010[] = "(17x,\002I\002,5x,a2,i3,5x,\002I\002,3x,f9.3,5\
x,\002I\002/17x,\002I---------------I-----------------I\002)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    alist al__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), f_rew(), s_rsue(), do_uio(), e_rsue(), do_fio(
	    );

    /* Local variables */
    static real graf[650]	/* was [65][10] */;
    static integer ivar;
    static real psum;
    extern /* Subroutine */ int pars8_();
    static integer i, j, k;
    static real p;
    static integer nomel, ipars, jj, np;
    static doublereal buf[10];
    static real psr;

    /* Fortran I/O blocks */
    static cilist io___180 = { 0, 0, 0, fmt_2000, 0 };
    static cilist io___182 = { 0, 0, 0, 0, 0 };
    static cilist io___190 = { 0, 0, 0, fmt_2010, 0 };


/*     *************** */

/*     3.01.1986( razrabotal - cyrulxnik a.a.) */
    /* Parameter adjustments */
    net -= 6;
    namey -= 3;

    /* Function Body */
/* identifikaciq |lementow, u kot. wy~isl. aktiwnaq mo}nostx */
    np = 0;
    i__1 = *nsec;
    for (j = 1; j <= i__1; ++j) {
	ivar = namey[(j << 1) + 1];
	if (ivar != namep) {
	    goto L80;
	}
	nomel = namey[(j << 1) + 2];
/* nomer |lementa */
	k = j;
/* pe~atx zagolowka */
	if (np == 0) {
	    io___180.ciunit = *iout;
	    s_wsfe(&io___180);
	    e_wsfe();
	}
/* ~tenie mgnowennoj mo}nosti s diska w bufer */
	al__1.aerr = 0;
	al__1.aunit = *irec;
	f_rew(&al__1);
	i__2 = *npoint;
	for (i = 1; i <= i__2; ++i) {
	    io___182.ciunit = *irec;
	    s_rsue(&io___182);
	    i__3 = *nsec;
	    for (jj = 1; jj <= i__3; ++jj) {
		do_uio(&c__1, (char *)&buf[jj - 1], (ftnlen)sizeof(doublereal)
			);
	    }
	    e_rsue();
	    graf[i + k * 65 - 66] = buf[k - 1];
/* L20: */
	}
/* priswoenie na~alxnyh zna~enij */
	psum = (float)0.;
/* wy~isl. summarnoj mgnowennoj mo}nosti */
	i__2 = *npoint;
	for (i = 1; i <= i__2; ++i) {
	    p = graf[i + k * 65 - 66];
	    psum += p;
/* L30: */
	}
/* opredel. aktiwnoj mo}nosti */
	psr = psum / (real) (*npoint - 1);
/* pe~atx aktiwnoj mo}nosti */
	if (psr < (float)0.) {
	    psr = -(doublereal)psr;
	}
	pars8_(nels, &net[6], &nomel, &ipars);
	io___190.ciunit = *iout;
	s_wsfe(&io___190);
	do_fio(&c__1, (char *)&ipars, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nomel, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&psr, (ftnlen)sizeof(real));
	e_wsfe();
	np = j;
L80:
	;
    }
/* L90: */
    return 0;
} /* pakt_ */

#undef namep


/* Subroutine */ int pars8_(nels, net, ipar, ipars)
integer *nels, *net, *ipar, *ipars;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_193 = { {'T', 'E', ' ', ' '}, 0 };

#define itemp (*(integer *)&equiv_193)


    extern integer ncode_();

/* ************************************* */
/*      3.9.1981 */

    /* Parameter adjustments */
    net -= 6;

    /* Function Body */
    if (*ipar <= 0) {
	goto L10;
    }
    *ipars = ncode_(&net[*ipar * 5 + 1], &c__1);
    return 0;
L10:
    *ipars = itemp;
    return 0;
} /* pars8_ */

#undef itemp


/* Subroutine */ int vdel_(namey, nsec, npoint, nels, net, irec, iout)
integer *namey, *nsec, *npoint, *nels, *net, *irec, *iout;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_212 = { {'V', 'D', ' ', ' '}, 0 };

#define namevd (*(integer *)&equiv_212)


    /* Format strings */
    static char fmt_1000[] = "(///15x,\002результаты расчета действующих\002\
,1x,\002напряжений\002/15x,41(\002*\002)//17x,35(\002=\002)/17x,\002I  тип и\
 номер  I   дейст.знач.   I\002/17x,\002I  элемента     I   напряжения    \
I\002/17x,\002I===============I=================I\002)";
    static char fmt_1100[] = "(17x,\002I\002,5x,a2,i3,5x,\002I\002,3x,f11.5,\
3x,\002I\002/17x,\002I---------------I-----------------I\002)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    real r__1;
    alist al__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), f_rew(), s_rsue(), do_uio(), e_rsue();
    double sqrt();
    integer do_fio();

    /* Local variables */
    static real graf[650]	/* was [65][10] */;
    static integer ivar;
    static real vsum;
    extern /* Subroutine */ int pars8_();
    static integer i, j, k, nomel, ipars, jj;
    static real vd, vk;
    static doublereal buf[10];
    static integer nvd;
    static real vsr;

    /* Fortran I/O blocks */
    static cilist io___200 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___202 = { 0, 0, 0, 0, 0 };
    static cilist io___211 = { 0, 0, 0, fmt_1100, 0 };


/*     *************** */
/* вычисление действ.знач.напряж. */
/*     21.01.1987 (razrabotal - cyrulxnik a.a.) */
    /* Parameter adjustments */
    net -= 6;
    namey -= 3;

    /* Function Body */
/* identifikaciq |lem.,u kot.wy~isl.dejstw.zna~.naprqvenij */
    nvd = 0;
    i__1 = *nsec;
    for (j = 1; j <= i__1; ++j) {
	ivar = namey[(j << 1) + 1];
	if (ivar != namevd) {
	    goto L100;
	}
	nomel = namey[(j << 1) + 2];
/* nomer |lementa */
	k = j;
/* pe~atx zagolowka */
	if (nvd == 0) {
	    io___200.ciunit = *iout;
	    s_wsfe(&io___200);
	    e_wsfe();
	}
/* ~tenie mgnow.naprqv.s diska w bufer */
	al__1.aerr = 0;
	al__1.aunit = *irec;
	f_rew(&al__1);
	i__2 = *npoint;
	for (i = 1; i <= i__2; ++i) {
	    io___202.ciunit = *irec;
	    s_rsue(&io___202);
	    i__3 = *nsec;
	    for (jj = 1; jj <= i__3; ++jj) {
		do_uio(&c__1, (char *)&buf[jj - 1], (ftnlen)sizeof(doublereal)
			);
	    }
	    e_rsue();
	    graf[i + k * 65 - 66] = buf[k - 1];
/* L10: */
	}
/* na~.zna~enie */
	vsum = (float)0.;
/* wy~.summy kwadr.mgnow.zna~enij */
	i__2 = *npoint;
	for (i = 1; i <= i__2; ++i) {
	    vk = graf[i + k * 65 - 66];
/* Computing 2nd power */
	    r__1 = vk;
	    vk = r__1 * r__1;
	    vsum += vk;
/* L30: */
	}
/* opred.dejstw.zna~.naprqv. */
	vsr = vsum / (real) (*npoint - 1);
	vd = sqrt(vsr);
/* opred.tipa |lementa */
	pars8_(nels, &net[6], &nomel, &ipars);
/* pe~atx dejstw.naprqv. */
	io___211.ciunit = *iout;
	s_wsfe(&io___211);
	do_fio(&c__1, (char *)&ipars, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nomel, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&vd, (ftnlen)sizeof(real));
	e_wsfe();
	nvd = j;
L100:
	;
    }
    return 0;
} /* vdel_ */

#undef namevd


/* Subroutine */ int pertd_(name, iel, val, delta, isen, nsec, namey, np, 
	xmin, xmax, irec, iou)
integer *name, *iel;
doublereal *val;
real *delta;
integer *isen, *nsec, *namey, *np;
doublereal *xmin, *xmax;
integer *irec, *iou;
{
    /* Format strings */
    static char fmt_100[] = "(//\002чувствительность на параметр элемента\
\002,i3//15a4/)";

    /* System generated locals */
    integer i__1, i__2;
    alist al__1;

    /* Builtin functions */
    integer f_rew(), s_rsue(), do_uio(), e_rsue(), s_wsfe(), do_fio(), e_wsfe(
	    ), s_wsue(), e_wsue();

    /* Local variables */
    extern /* Subroutine */ int tabd_();
    static doublereal xdel;
    static integer i, j, k;
    static real o, x;
    static doublereal y[10];
    static real pertb[4000]	/* was [200][10][2] */;
    static doublereal buf[10];

    /* Fortran I/O blocks */
    static cilist io___215 = { 0, 0, 0, 0, 0 };
    static cilist io___220 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___224 = { 0, 0, 0, 0, 0 };


/*       **************************************************** */
/*  COMPUTATION OF SENSITIVITY BY MEANS OF PERTURBATIONS */
/*        6.10.81 OLIVA */

    /* Parameter adjustments */
    namey -= 3;
    --name;

    /* Function Body */
    al__1.aerr = 0;
    al__1.aunit = *irec;
    f_rew(&al__1);
    for (i = 1; i <= 2; ++i) {
	i__1 = *np;
	for (j = 1; j <= i__1; ++j) {
	    io___215.ciunit = *irec;
	    s_rsue(&io___215);
	    i__2 = *nsec;
	    for (k = 1; k <= i__2; ++k) {
		do_uio(&c__1, (char *)&buf[k - 1], (ftnlen)sizeof(doublereal))
			;
	    }
	    e_rsue();
	    i__2 = *nsec;
	    for (k = 1; k <= i__2; ++k) {
/* L5: */
		pertb[j + (k + i * 10) * 200 - 2201] = buf[k - 1];
	    }
/* L10: */
	}
    }
    al__1.aerr = 0;
    al__1.aunit = *irec;
    f_rew(&al__1);
    xdel = *xmax - *xmin;
    io___220.ciunit = *iou;
    s_wsfe(&io___220);
    do_fio(&c__1, (char *)&(*iel), (ftnlen)sizeof(integer));
    do_fio(&c__15, (char *)&name[1], (ftnlen)sizeof(integer));
    e_wsfe();
    i__1 = *np;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *nsec;
	for (k = 1; k <= i__2; ++k) {
	    y[k - 1] = (pertb[j + (k + 10) * 200 - 2201] - pertb[j + (k + 20) 
		    * 200 - 2201]) / *delta;
	    if (*isen == 2) {
		y[k - 1] = y[k - 1] * pertb[j + (k + 10) * 200 - 2201] / *val;
	    }
/* L20: */
	}
	x = *xmin + (real) (j - 1) * xdel;
	i__2 = j;
	tabd_("X   ", &o, &x, nsec, &namey[3], y, &i__2, iou, 4L);
	io___224.ciunit = *irec;
	s_wsue(&io___224);
	i__2 = *nsec;
	for (k = 1; k <= i__2; ++k) {
	    do_uio(&c__1, (char *)&y[k - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
/* L30: */
    }
    return 0;
} /* pertd_ */

