/* da.f -- translated by f2c (version of 23 April 1993  18:34:30).
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
static integer c__2 = 2;
static integer c__28 = 28;
static integer c__30 = 30;
static integer c__10 = 10;
static integer c__100 = 100;
static integer c__5 = 5;
static integer c__3 = 3;

/*     программа  **** ДАВИД=ИВЭП **** */
/*     IBM-версия  (DOUBLE PRECISION) */
/*     10.3.1989 */
/* Main program */ MAIN__()
{
    /* Initialized data */

    static struct {
	char e_1[24];
	real e_2;
	} equiv_13 = { {'?', 'C', 'I', 'R', '?', 'P', 'Z', ' ', '?', 'R', 'E',
		 'S', '?', 'E', 'N', 'D', '?', 'T', 'R', ' ', '?', 'B', 'L', 
		'O'}, (float)0. };

#define con ((real *)&equiv_13)


    /* Format strings */
    static char fmt_100[] = "(\0021\002,9x,46(\002*\002)/10x,\002*\002,44x\
,\002*\002/10x,\002*  \" Д А В И Д - ИВЭП \"   версия: 10-89-IBM\002,3x,\002*\
\002/10x,\002*\002,44x,\002*\002/10x,46(\002*\002)/)";
    static char fmt_140[] = "(/\002 внимание : ошибка в задании команд\002/)";
    static char fmt_150[] = "(//\002 вычисления прерваны \002/)";
    static char fmt_160[] = "(//\002 ошибка : много секций \002/)";
    static char fmt_170[] = "(//\002 ошибка : см индикатор \002/)";

    /* System generated locals */
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe(), s_rsfe(), e_rsfe(), f_open();
    /* Subroutine */ int s_stop();
    integer f_clos();

    /* Local variables */
    extern /* Subroutine */ int bloc_();
    static integer icpu;
    extern integer ierr_();
    extern /* Subroutine */ int resp_();
    static char fname[64];
    extern /* Subroutine */ int contr1_(), tr_(), cir_(), pzn_();

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 6, 0, "(A)", 0 };
    static cilist io___4 = { 0, 5, 0, "(A)", 0 };
    static cilist io___6 = { 0, 6, 0, "(A)", 0 };
    static cilist io___7 = { 0, 5, 0, "(A)", 0 };
    static cilist io___8 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___9 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___10 = { 0, 0, 0, fmt_150, 0 };
    static cilist io___11 = { 0, 0, 0, fmt_160, 0 };
    static cilist io___12 = { 0, 0, 0, fmt_170, 0 };







    icpu = 0;
/* каналы ввода- */
    _BLNK__1.inp = 5;
    _BLNK__1.iou = 6;
    _BLNK__1.irec = 14;
    _BLNK__1.irec1 = 15;
/*    s_wsfe(&io___3);
    do_fio(&c__1, " \224\200\211\213 \204\200\215\215\233\225 ?", 14L);
    e_wsfe();
    s_rsfe(&io___4);
    do_fio(&c__1, fname, 64L);
    e_rsfe();*/
    o__1.oerr = 0;
    o__1.ounit = 5;
    o__1.ofnmlen = 64;
    o__1.ofnm = "d1.dat";//fname;
    o__1.orl = 0;
    o__1.osta = "old";
    o__1.oacc = "sequential";
    o__1.ofm = "formatted";
    o__1.oblnk = 0;
    f_open(&o__1);
/* 	WRITE(*,'(A)') 'ОТЛАДОЧНЫЙ ФАЙЛ ?' */
/* 	READ(*,'(A)') FNAME */
    o__1.oerr = 0;
    o__1.ounit = 6;
    o__1.ofnmlen = 7;
    o__1.ofnm = "COX.DAV";
    o__1.orl = 0;
    o__1.osta = "rw";
    o__1.oacc = "sequential";
    o__1.ofm = "formatted";
    o__1.oblnk = 0;
    f_open(&o__1);
/*    s_wsfe(&io___6);
    do_fio(&c__1, " \202\233\225\216\204\215\216\211 \204\200\215\215\233\
\225 ?", 18L);
    e_wsfe();
    s_rsfe(&io___7);
    do_fio(&c__1, fname, 64L);
    e_rsfe();*/
    o__1.oerr = 0;
    o__1.ounit = 14;
    o__1.ofnmlen = 64;
    o__1.ofnm = /*fname*/"f.out";
    o__1.orl = 96;
    o__1.osta = "rw";
    o__1.oacc = "direct";
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    _BLNK__1.maxel = 60;
    _BLNK__1.maxsec = 10;
    _BLNK__1.ndim = 20;
    _BLNK__1.ncon = 25;
/* установка индикации; */
    _BLNK__1.ind = 0;
    io___8.ciunit = _BLNK__1.iou;
    s_wsfe(&io___8);
    e_wsfe();
/*      CALL TIME (TT) */
/*      WRITE (IOU,180) (TT(I),I=1,8) */

    for (_BLNK__1.i = 1; _BLNK__1.i <= 50; ++_BLNK__1.i) {
	contr1_(&_BLNK__1.ncon, con, &_BLNK__1.key, &_BLNK__1.inp, &
		_BLNK__1.iou);
	if (_BLNK__1.key != 0) {
	    goto L5;
	}
	_BLNK__1.key = ierr_(&_BLNK__1.icont, &_BLNK__1.ncon);
	goto L90;
L5:
	switch ((int)_BLNK__1.key) {
	    case 1:  goto L10;
	    case 2:  goto L20;
	    case 3:  goto L30;
	    case 4:  goto L99;
	    case 5:  goto L40;
	    case 6:  goto L50;
	}
L10:
	cir_();
	goto L90;
L20:
	pzn_();
	goto L90;
L30:
	resp_();
	goto L90;
L40:
	tr_();
	goto L90;
L50:
	bloc_();
L90:
	if (_BLNK__1.ind == 10) {
	    goto L97;
	}
	if (_BLNK__1.icont <= 0) {
	    io___9.ciunit = _BLNK__1.iou;
	    s_wsfe(&io___9);
	    e_wsfe();
	}
	if (_BLNK__1.icont > -10) {
	    goto L95;
	}
	io___10.ciunit = _BLNK__1.iou;
	s_wsfe(&io___10);
	e_wsfe();
	goto L99;
L95:
	;
    }
    io___11.ciunit = _BLNK__1.iou;
    s_wsfe(&io___11);
    e_wsfe();
    goto L99;
L97:
    io___12.ciunit = _BLNK__1.iou;
    s_wsfe(&io___12);
    e_wsfe();
L99:
/*      CALL TIME (TT) */
/*      WRITE (IOU,190) (TT(I),I=1,8) */
    s_stop("", 0L);
/* L110: */
/* L120: */
/* L180: */
/* L190: */
    cl__1.cerr = 0;
    cl__1.cunit = 5;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 6;
    cl__1.csta = 0;
    f_clos(&cl__1);
    s_stop("", 0L);
} /* MAIN__ */

#undef con


doublereal dint_(x)
doublereal *x;
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    static integer i;

/* ********************************* */
    i = (integer) (*x);
    ret_val = (doublereal) i;
    return ret_val;
} /* dint_ */

doublereal dfloat_(i)
integer *i;
{
    /* System generated locals */
    doublereal ret_val;

/*        ********************************** */
    ret_val = (doublereal) (*i);
    return ret_val;
} /* dfloat_ */

integer ierr_(i, j)
integer *i, *j;
{
    /* System generated locals */
    integer ret_val;

/*     ************* */

    ret_val = 0;
    if (*j == 0) {
	return ret_val;
    }
    if (*i <= 0) {
	--(*i);
    }
    if (*i > 0) {
	*i = -1;
    }
    return ret_val;
} /* ierr_ */

/* Subroutine */ int contr1_(nc, con, key, input, iout)
integer *nc;
real *con;
integer *key, *input, *iout;
{
    /* Format strings */
    static char fmt_100[] = "(30a2)";
    static char fmt_105[] = "(1x,30a2)";
    static char fmt_110[] = "(/\002 ошибка : команда неизвестна \002,2a2)";

    /* System generated locals */
    integer i__1;
    static real equiv_0[1];

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();

    /* Local variables */
    static shortint line[28];
#define word (equiv_0)
    static integer i;
#define iw ((shortint *)equiv_0)

    /* Fortran I/O blocks */
    static cilist io___17 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___19 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___21 = { 0, 0, 0, fmt_110, 0 };


/*     ***************** */

/*     11.9.1981 */
    /* Parameter adjustments */
    --con;

    /* Function Body */
    *key = 0;
    io___17.ciunit = *input;
    s_rsfe(&io___17);
    do_fio(&c__2, (char *)&iw[0], (ftnlen)sizeof(shortint));
    do_fio(&c__28, (char *)&line[0], (ftnlen)sizeof(shortint));
    e_rsfe();
    io___19.ciunit = *iout;
    s_wsfe(&io___19);
    do_fio(&c__2, (char *)&iw[0], (ftnlen)sizeof(shortint));
    do_fio(&c__28, (char *)&line[0], (ftnlen)sizeof(shortint));
    e_wsfe();
    i__1 = *nc;
    for (i = 1; i <= i__1; ++i) {
	if (*word == con[i]) {
	    goto L20;
	}
/* L10: */
    }
    io___21.ciunit = *iout;
    s_wsfe(&io___21);
    do_fio(&c__2, (char *)&iw[0], (ftnlen)sizeof(shortint));
    e_wsfe();
    return 0;
L20:
    *key = i;
    return 0;
} /* contr1_ */

#undef iw
#undef word


/* Subroutine */ int rlist_(input, iout, list)
integer *input, *iout, *list;
{
    /* Format strings */
    static char fmt_100[] = "(i0)";
    static char fmt_101[] = "(/\002 тип контрольной печати =\002,i2)";

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();

    /* Fortran I/O blocks */
    static cilist io___22 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_101, 0 };


/*     **************** */

/*     18.10.1978 */
    io___22.ciunit = *input;
    s_rsfe(&io___22);
    do_fio(&c__1, (char *)&(*list), (ftnlen)sizeof(integer));
    e_rsfe();
    io___23.ciunit = *iout;
    s_wsfe(&io___23);
    do_fio(&c__1, (char *)&(*list), (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;
} /* rlist_ */

/* Subroutine */ int nul_(m, n, mdim, k)
integer *m, *n, *mdim, *k;
{
    /* System generated locals */
    integer k_dim1, k_offset, i__1, i__2;

    /* Local variables */
    static integer i, j;

/*     ************** */
/* обнуление матрицы типа INTEGER */
/*     7.5.1980 */
    /* Parameter adjustments */
    k_dim1 = *mdim;
    k_offset = k_dim1 + 1;
    k -= k_offset;

    /* Function Body */
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *m;
	for (i = 1; i <= i__2; ++i) {
/* L10: */
	    k[i + j * k_dim1] = 0;
	}
    }
    return 0;
} /* nul_ */

/* Subroutine */ int nuld_(m, n, mdim, a)
integer *m, *n, *mdim;
doublereal *a;
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    static integer i, j;

/*     *************** */
/* обнуление матрицы типа DOUBLE PRECISION */
/*     25.3.1980 */
    /* Parameter adjustments */
    a_dim1 = *mdim;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *m;
	for (i = 1; i <= i__2; ++i) {
/* L10: */
	    a[i + j * a_dim1] = 0.;
	}
    }
    return 0;
} /* nuld_ */

/* Subroutine */ int dmat_(m, n, mdim, a, dname, iout, dname_len)
integer *m, *n, *mdim;
doublereal *a;
char *dname;
integer *iout;
ftnlen dname_len;
{
    /* Format strings */
    static char fmt_100[] = "(\002 матрица \002,a8,\002 =\002)";
    static char fmt_101[] = "(1x,1p10d11.4)";

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer i, j;

    /* Fortran I/O blocks */
    static cilist io___28 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___30 = { 0, 0, 0, fmt_101, 0 };


/*     *************** */
/* печать матрицы типа DOUBLE PRECISION */
/*     6.2.1980 */
    /* Parameter adjustments */
    a_dim1 = *mdim;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    io___28.ciunit = *iout;
    s_wsfe(&io___28);
    do_fio(&c__1, dname, 4L);
    e_wsfe();
    i__1 = *m;
    for (i = 1; i <= i__1; ++i) {
/* L1: */
	io___30.ciunit = *iout;
	s_wsfe(&io___30);
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&a[i + j * a_dim1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
    }
    return 0;
} /* dmat_ */

/* Subroutine */ int cir_()
{
    /* Initialized data */

    static struct {
	char e_1[28];
	real e_2;
	} equiv_40 = { {'L', 'I', 'S', 'T', 'P', 'R', 'O', 'B', 'E', 'L', 'E',
		 'M', 'O', 'U', 'T', 'P', 'E', 'N', 'D', ' ', 'F', 'U', 'N', 
		'C', 'M', 'O', 'D', 'E'}, (float)0. };

#define con ((real *)&equiv_40)


    /* Format strings */
    static char fmt_1000[] = "(30a2)";
    static char fmt_1010[] = "(//1x,30a2//)";
    static char fmt_1030[] = "(1x,\002 внимание : тест выходных величин не п\
роведен\002,1x,\002из-за отсутствия описания схемы\002)";
    static char fmt_1020[] = "(1x,\002 ошибка : число заданных элементов рав\
но нулю`\002)";
    static char fmt_1040[] = "(1x,\002 ошибка : не заданы выходные величины\
 \002)";

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int node_();
    static integer maxn;
    extern integer ierr_();
    extern /* Subroutine */ int neqd_(), imat_(), dmat_(), test1_(), ntabl_();
    static integer mpare;
    extern /* Subroutine */ int rpard_(), rfund_(), rlist_(), secin2_(), 
	    contr1_(), netind_();

    /* Fortran I/O blocks */
    static cilist io___35 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_1030, 0 };
    static cilist io___38 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_1040, 0 };


/*     ************** */
/* READING IN AND PROCESSING CIRCUIT STRUCTURE AND OUTPUT */
/* VARIABLES */
/*     10.3.1989 */





    _BLNK__2.ncon = 7;

    maxn = 99;
    _BLNK__2.icont = 1;
    _BLNK__2.list = 0;
    _BLNK__2.nels = 0;
    _BLNK__2.neqs = 0;
    _BLNK__2.nsec = 0;
    _BLNK__2.nfun = 0;
    _BLNK__2.npar = 0;
    mpare = 30;

    for (_BLNK__2.i = 1; _BLNK__2.i <= 10; ++_BLNK__2.i) {
	contr1_(&_BLNK__2.ncon, con, &_BLNK__2.key, &_BLNK__2.inp, &
		_BLNK__2.iou);
	if (_BLNK__2.key != 0) {
	    goto L5;
	}
	_BLNK__2.key = ierr_(&_BLNK__2.icont, &_BLNK__2.ncon);
	goto L95;
L5:
	switch ((int)_BLNK__2.key) {
	    case 1:  goto L10;
	    case 2:  goto L20;
	    case 3:  goto L30;
	    case 4:  goto L40;
	    case 5:  goto L99;
	    case 6:  goto L50;
	    case 7:  goto L60;
	}

L10:
	rlist_(&_BLNK__2.inp, &_BLNK__2.iou, &_BLNK__2.list);
	goto L95;

L20:
	io___35.ciunit = _BLNK__2.inp;
	s_rsfe(&io___35);
	do_fio(&c__30, (char *)&_BLNK__2.name[0], (ftnlen)sizeof(integer));
	e_rsfe();
	if (_BLNK__2.list <= 1) {
	    io___36.ciunit = _BLNK__2.iou;
	    s_wsfe(&io___36);
	    do_fio(&c__30, (char *)&_BLNK__2.name[0], (ftnlen)sizeof(integer))
		    ;
	    e_wsfe();
	}
	goto L95;
/* чтение команды ELEM */
L30:
	netind_(&_BLNK__2.maxel, _BLNK__2.net, _BLNK__2.val, &_BLNK__2.nels, &
		_BLNK__2.ind, &_BLNK__2.inp, &_BLNK__2.iou, &_BLNK__2.list);
	_BLNK__2.ind = ierr_(&_BLNK__2.icont, &_BLNK__2.ind);

	node_(_BLNK__2.net, &_BLNK__2.nels, &_BLNK__2.ndim, _BLNK__2.newn, &
		maxn, &_BLNK__2.nods, &_BLNK__2.ind, &_BLNK__2.iou);
	_BLNK__2.ind = ierr_(&_BLNK__2.icont, &_BLNK__2.ind);
	neqd_(&_BLNK__2.nels, _BLNK__2.net, _BLNK__2.val, &_BLNK__2.nods, &
		_BLNK__2.ndim, &_BLNK__2.neqs, &_BLNK__2.ind, &_BLNK__2.iou);
	_BLNK__2.ind = ierr_(&_BLNK__2.icont, &_BLNK__2.ind);

	ntabl_(_BLNK__2.net, &_BLNK__2.nels, &_BLNK__2.ndim, _BLNK__2.newn, &
		_BLNK__2.nods, &_BLNK__2.ind, &_BLNK__2.iou, &_BLNK__2.list);
	goto L93;
/* чтение команды OUTP */
L40:
	secin2_(&_BLNK__2.maxsec, &_BLNK__2.nsec, _BLNK__2.msec, &
		_BLNK__2.ind, &_BLNK__2.inp, &_BLNK__2.iou, &_BLNK__2.list);
	_BLNK__2.ind = ierr_(&_BLNK__2.icont, &_BLNK__2.ind);

	if (_BLNK__2.nels > 0) {
	    goto L42;
	}
	io___37.ciunit = _BLNK__2.iou;
	s_wsfe(&io___37);
	e_wsfe();
	goto L95;
L42:
	test1_(&_BLNK__2.nels, _BLNK__2.net, &_BLNK__2.nsec, _BLNK__2.msec, &
		_BLNK__2.ndim, &_BLNK__2.neqs, &_BLNK__2.ind, &_BLNK__2.iou);
	goto L93;
/* чтение команды FUNC */
L50:
	rfund_(&c__10, &_BLNK__2.nfun, _BLNK__2.iadr, &c__100, &_BLNK__2.npar,
		 _BLNK__2.parf, &_BLNK__2.ind, &_BLNK__2.inp, &_BLNK__2.iou, &
		_BLNK__2.list);
	goto L93;
L60:
	rpard_(&_BLNK__2.nels, _BLNK__2.net, &mpare, &c1_1.npare, c1_1.pare, &
		_BLNK__2.inp, &_BLNK__2.iou);
L93:
	_BLNK__2.ind = ierr_(&_BLNK__2.icont, &_BLNK__2.ind);
L95:
	;
    }

    _BLNK__2.ind = 10;
L99:
    if (_BLNK__2.nels > 0) {
	goto L100;
    }
    io___38.ciunit = _BLNK__2.iou;
    s_wsfe(&io___38);
    e_wsfe();
    goto L105;
L100:
    if (_BLNK__2.nsec > 0) {
	goto L110;
    }
    io___39.ciunit = _BLNK__2.iou;
    s_wsfe(&io___39);
    e_wsfe();
L105:
    _BLNK__2.icont = -100;
    goto L900;
L110:

    if (_BLNK__2.list >= 3) {
	imat_(&c__5, &_BLNK__2.nels, &c__5, _BLNK__2.net, "NET ", &
		_BLNK__2.iou, 4L);
    }
    if (_BLNK__2.list >= 3) {
	imat_(&c__1, &_BLNK__2.nsec, &c__1, _BLNK__2.msec, "MSEC", &
		_BLNK__2.iou, 4L);
    }
    if (_BLNK__2.list >= 3) {
	dmat_(&c__1, &_BLNK__2.nels, &c__1, _BLNK__2.val, "VAL ", &
		_BLNK__2.iou, 4L);
    }
    if (_BLNK__2.list < 4) {
	goto L900;
    }
    imat_(&c__1, &_BLNK__2.neqs, &c__1, _BLNK__2.newn, "NEWN", &_BLNK__2.iou, 
	    4L);
    if (_BLNK__2.nfun == 0) {
	goto L900;
    }
    imat_(&c__3, &_BLNK__2.nfun, &c__3, _BLNK__2.iadr, "IADR", &_BLNK__2.iou, 
	    4L);
    dmat_(&c__1, &_BLNK__2.npar, &c__1, _BLNK__2.parf, "PARF ", &_BLNK__2.iou,
	     5L);
L900:
    return 0;
} /* cir_ */

#undef con


/* Subroutine */ int rpard_(nels, net, mpare, npare, pare, inp, iou)
integer *nels, *net, *mpare, *npare;
doublereal *pare;
integer *inp, *iou;
{
    /* Format strings */
    static char fmt_100[] = "(10i5)";
    static char fmt_110[] = "(1x,\002 ошибка : элементу номер \002,i3,\002 н\
ельзя\002,1x,\002приписать параметры\002/)";
    static char fmt_120[] = "(10f9.5)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();

    /* Local variables */
    static integer ityp, i, j, l, ihelp[10], j1, j2, ie, mup, nup;

    /* Fortran I/O blocks */
    static cilist io___42 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___48 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___52 = { 0, 0, 0, fmt_120, 0 };


/*     **************** */
/* READING IN PARAMETERS FOR NONLINEAR ELEMENTS */
/*     2.10.1981 */
    /* Parameter adjustments */
    --pare;
    net -= 6;

    /* Function Body */
    *npare = 1;
    for (l = 1; l <= 100; ++l) {
	io___42.ciunit = *inp;
	s_rsfe(&io___42);
	do_fio(&c__1, (char *)&mup, (ftnlen)sizeof(integer));
	i__1 = mup;
	for (i = 1; i <= i__1; ++i) {
	    do_fio(&c__1, (char *)&ihelp[i - 1], (ftnlen)sizeof(integer));
	}
	e_rsfe();
	if (mup == 0) {
	    goto L90;
	}
	i__1 = mup;
	for (i = 1; i <= i__1; ++i) {
	    ie = ihelp[i - 1];
	    if (ie <= 0 || ie > *nels) {
		goto L50;
	    }
	    ityp = net[ie * 5 + 1];
	    if (ityp == 17) {
		goto L10;
	    }
	    if (ityp == 28) {
		goto L20;
	    }
	    if (ityp >= 22 && ityp <= 25) {
		goto L30;
	    }
/* ERROR MESSAGE */
	    io___48.ciunit = *iou;
	    s_wsfe(&io___48);
	    do_fio(&c__1, (char *)&ie, (ftnlen)sizeof(integer));
	    e_wsfe();
	    goto L50;
L10:
/* DIODE */
	    nup = 1;
	    goto L40;
L20:
/* TYRISTOR */
	    nup = 2;
	    goto L40;
L30:
/* TRANZISTOR */
	    nup = 3;
L40:
/* READ  PARAMETERS */
	    j1 = *npare;
	    j2 = *npare + nup - 1;
	    io___52.ciunit = *inp;
	    s_rsfe(&io___52);
	    i__2 = j2;
	    for (j = j1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&pare[j], (ftnlen)sizeof(doublereal));
	    }
	    e_rsfe();
	    *npare = j2 + 1;
	    if (ityp >= 22 && ityp <= 25) {
		net[ie * 5 + 5] = j1;
	    }
	    if (ityp < 22 || ityp > 25) {
		net[ie * 5 + 4] = j1;
	    }
L50:
	    ;
	}
/* L80: */
    }
L90:
    return 0;
} /* rpard_ */

/* Subroutine */ int test1_(nels, net, nsec, msec, ndim, neqs, ind, iou)
integer *nels, *net, *nsec, *msec, *ndim, *neqs, *ind, *iou;
{
    /* Format strings */
    static char fmt_9080[] = "(1x,\002 ошибка : выходная величина номер \002\
,i5,3x,\002задана на несущесьвующем элементе номер \002,i5/9x,\002исправлено\
 на элемент номер \002,i5)";
    static char fmt_9090[] = "(1x,\002 ошибка : выходная величина номер\002,\
i5,3x,\002задана на недопустимом элементе номер\002,i5/9x,\002исправлено на \
элемент номер\002,i5)";
    static char fmt_9100[] = "(1x,\002 ошибка : число уравнений\002,i5,3x\
,\002превышает допустимое число\002,i5)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer i, j, k, l, m, ii;

    /* Fortran I/O blocks */
    static cilist io___60 = { 0, 0, 0, fmt_9080, 0 };
    static cilist io___61 = { 0, 0, 0, fmt_9090, 0 };
    static cilist io___62 = { 0, 0, 0, fmt_9100, 0 };


/*     *************** */

/*     24.6.1980 */
/* выходной элемент ? */
    /* Parameter adjustments */
    --msec;
    net -= 6;

    /* Function Body */
    i__1 = *nels;
    for (i = 1; i <= i__1; ++i) {
	j = *nels - i + 1;
	if (net[j * 5 + 1] > 14) {
	    goto L910;
	}
	if (net[j * 5 + 1] == 5) {
	    goto L910;
	}
	l = j;
	goto L920;
L910:
	;
    }
    *ind = 7;
L920:
    i__1 = *nsec;
    for (ii = 1; ii <= i__1; ++ii) {
	i = ii;
	k = msec[i];
	j = abs(k);
	if (j < 100) {
	    goto L925;
	}
	j /= 100;
L925:
	if (j > *nels) {
	    goto L930;
	}
	m = net[j * 5 + 1];
	if (m == 15) {
	    goto L940;
	}
	if (m == 16) {
	    goto L940;
	}
	if (m > 21 && m < 26) {
	    goto L940;
	}
	if (k < 0) {
	    goto L960;
	}
	if (k > 0) {
	    goto L980;
	}
L930:
	io___60.ciunit = *iou;
	s_wsfe(&io___60);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
	e_wsfe();
	msec[i] = l;
	goto L980;
L940:
	io___61.ciunit = *iou;
	s_wsfe(&io___61);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
	e_wsfe();
	msec[i] = l;
	goto L980;
L960:
/* при вычисл. вых. */
	if (net[j * 5 + 5] != 0) {
	    goto L980;
	}
	++(*neqs);
	net[j * 5 + 5] = *neqs;
L980:
	;
    }
/* тест превыш. допуст. */
    if (*neqs < *ndim) {
	goto L1000;
    }
    io___62.ciunit = *iou;
    s_wsfe(&io___62);
    do_fio(&c__1, (char *)&(*neqs), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*ndim), (ftnlen)sizeof(integer));
    e_wsfe();
    *ind = 8;
L1000:
    return 0;
} /* test1_ */

/* Subroutine */ int imat_(m, n, mdim, ia, name, iout)
integer *m, *n, *mdim, *ia, *name, *iout;
{
    /* Format strings */
    static char fmt_100[] = "(1x,/,20x,\002matrica  \002,2a2,\002 =\002/)";
    static char fmt_101[] = "(15x,30i4,//)";

    /* System generated locals */
    integer ia_dim1, ia_offset, i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer i, j;

    /* Fortran I/O blocks */
    static cilist io___63 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___65 = { 0, 0, 0, fmt_101, 0 };


/*     *************** */
/* TISK MATICE TYPU INTEGER */
/*     7.6.1977 */
    /* Parameter adjustments */
    --name;
    ia_dim1 = *mdim;
    ia_offset = ia_dim1 + 1;
    ia -= ia_offset;

    /* Function Body */
    io___63.ciunit = *iout;
    s_wsfe(&io___63);
    do_fio(&c__2, (char *)&name[1], (ftnlen)sizeof(integer));
    e_wsfe();
    i__1 = *m;
    for (i = 1; i <= i__1; ++i) {
/* L1: */
	io___65.ciunit = *iout;
	s_wsfe(&io___65);
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&ia[i + j * ia_dim1], (ftnlen)sizeof(
		    integer));
	}
	e_wsfe();
    }
    return 0;
} /* imat_ */

/* Subroutine */ int netind_(maxel, net, val, nels, ind, input, iout, list)
integer *maxel, *net;
doublereal *val;
integer *nels, *ind, *input, *iout, *list;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_84 = { {' ', ' ', ' ', ' '}, 0 };

#define iend (*(integer *)&equiv_84)


    /* Format strings */
    static char fmt_100[] = "(//22x,\002ЭЛЕМЕНТЫ ЦЕПИ\002//7x,\002тип номер \
  узел+ узел-   управление\002,6x,\002параметр 1\002/)";
    static char fmt_110[] = "(a2,4i5,f9.5)";
    static char fmt_120[] = "(1x,\002 ошибка : номер элемента\002,i5,2x,\002\
недопустим\002)";
    static char fmt_130[] = "(1x,\002 игнорирована строка :\002,25x,a2,2x,4i\
5,1pe19.9)";
    static char fmt_140[] = "(1x,\002ошибка : под номером\002,i5,2x,\002зада\
но много элементов\002)";
    static char fmt_150[] = "(8x,a2,2x,i2,5x,i3,3x,i3,6x,i3,7x,1pe17.9)";
    static char fmt_160[] = "(1x,\002 ошибка :нет знака окончания \002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
    static integer ielm, line[5], melp1, i, j;
    static doublereal value;
    static integer iel, iou;
    extern /* Subroutine */ int nul_();

    /* Fortran I/O blocks */
    static cilist io___70 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___72 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___77 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___78 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___79 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___80 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___81 = { 0, 0, 0, fmt_150, 0 };
    static cilist io___83 = { 0, 0, 0, fmt_160, 0 };


/*     ***************** */

/*     19.9.1981 */
    /* Parameter adjustments */
    --val;
    net -= 6;

    /* Function Body */

    nul_(&c__5, maxel, &c__5, &net[6]);
    i__1 = *maxel;
    for (i = 1; i <= i__1; ++i) {
/* L10: */
	val[i] = (float)0.;
    }
    *nels = 0;
    ielm = 0;
    *ind = 0;

    if (*list != 1) {
	io___70.ciunit = *iout;
	s_wsfe(&io___70);
	e_wsfe();
    }
    melp1 = *maxel + 1;
    i__1 = melp1;
    for (i = 1; i <= i__1; ++i) {
	io___72.ciunit = *input;
	s_rsfe(&io___72);
	for (j = 1; j <= 5; ++j) {
	    do_fio(&c__1, (char *)&line[j - 1], (ftnlen)sizeof(integer));
	}
	do_fio(&c__1, (char *)&value, (ftnlen)sizeof(doublereal));
	e_rsfe();
	iel = line[1];
	if (line[0] == iend) {
	    goto L50;
	}
	if (iel > 0 && iel <= *maxel) {
	    goto L20;
	}
	*ind = 1;
	io___77.ciunit = *iout;
	s_wsfe(&io___77);
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	e_wsfe();
	io___78.ciunit = *iout;
	s_wsfe(&io___78);
	for (j = 1; j <= 5; ++j) {
	    do_fio(&c__1, (char *)&line[j - 1], (ftnlen)sizeof(integer));
	}
	do_fio(&c__1, (char *)&value, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L40;
L20:
	if (net[iel * 5 + 1] == 0) {
	    goto L30;
	}
	io___79.ciunit = *iout;
	s_wsfe(&io___79);
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	e_wsfe();
	io___80.ciunit = *iout;
	s_wsfe(&io___80);
	for (j = 1; j <= 5; ++j) {
	    do_fio(&c__1, (char *)&line[j - 1], (ftnlen)sizeof(integer));
	}
	do_fio(&c__1, (char *)&value, (ftnlen)sizeof(doublereal));
	e_wsfe();
	*ind = 2;
	goto L40;
L30:
	net[iel * 5 + 1] = line[0];
	net[iel * 5 + 2] = line[2];
	net[iel * 5 + 3] = line[3];
	net[iel * 5 + 4] = line[4];
	val[iel] = value;
	ielm = max(ielm,iel);
	++(*nels);
	io___81.ciunit = *iout;
	s_wsfe(&io___81);
	do_fio(&c__1, (char *)&net[iel * 5 + 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	for (j = 2; j <= 4; ++j) {
	    do_fio(&c__1, (char *)&net[j + iel * 5], (ftnlen)sizeof(integer));
	}
	do_fio(&c__1, (char *)&val[iel], (ftnlen)sizeof(doublereal));
	e_wsfe();
L40:
	;
    }
    io___83.ciunit = iou;
    s_wsfe(&io___83);
    e_wsfe();
    *ind = 4;
L50:
    *nels = ielm;
    return 0;
} /* netind_ */

#undef iend


/* Subroutine */ int secin2_(maxsec, nsec, msec, ind, inp, iou, list)
integer *maxsec, *nsec, *msec, *ind, *inp, *iou, *list;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_104 = { {'I', ' ', ' ', ' '}, 0 };

#define namei (*(integer *)&equiv_104)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_105 = { {'V', ' ', ' ', ' '}, 0 };

#define namev (*(integer *)&equiv_105)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_106 = { {'P', ' ', ' ', ' '}, 0 };

#define namep (*(integer *)&equiv_106)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_107 = { {' ', ' ', ' ', ' '}, 0 };

#define iend (*(integer *)&equiv_107)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_108 = { {'V', 'D', ' ', ' '}, 0 };

#define namevd (*(integer *)&equiv_108)


    /* Format strings */
    static char fmt_100[] = "(//20x,\002ВЫХОДНЫЕ ВЕЛИЧИНЫ\002//19x,\002ти\
п\002,2x,\002номер\002,3x,\002элемент\002)";
    static char fmt_110[] = "(a2,2i5)";
    static char fmt_160[] = "(20x,a2,2x,i3,4x,i5)";
    static char fmt_150[] = "(1x,\002  ошибка : задано больше выходных велич\
ин чем\002,i5,1x,\002-\002,1x,\002игнорируется\002)";
    static char fmt_120[] = "(1x,\002  ошибка : недопустимый тип выходной\
 \002,\002величины\002,2x,a2,2x,1x,\002-\002,1x,\002исправлено :\002)";
    static char fmt_130[] = "(1x,\002 ошибка : номер не соответствует типу\
 \002,\002величины\002,i5,1x,\002-\002,1x,\002исправлено :\002)";
    static char fmt_140[] = "(1x,\002  ошибка : номер элемента\002,i5,2x,\
\002недопустим - исправлено :\002)";
    static char fmt_170[] = "(1x,\002  ошибка : нет знака окончания \002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
    static integer ivar, i, j, no, nel;

    /* Fortran I/O blocks */
    static cilist io___90 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___93 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___97 = { 0, 0, 0, fmt_160, 0 };
    static cilist io___98 = { 0, 0, 0, fmt_150, 0 };
    static cilist io___99 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___100 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___101 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___102 = { 0, 0, 0, fmt_160, 0 };
    static cilist io___103 = { 0, 0, 0, fmt_170, 0 };


/*     ***************** */

/*     12.01.1984 */
    /* Parameter adjustments */
    --msec;

    /* Function Body */
    if (*list < 1) {
	io___90.ciunit = *iou;
	s_wsfe(&io___90);
	e_wsfe();
    }
    *nsec = 0;
    for (i = 1; i <= 20; ++i) {
	j = 0;
	io___93.ciunit = *inp;
	s_rsfe(&io___93);
	do_fio(&c__1, (char *)&ivar, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&no, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nel, (ftnlen)sizeof(integer));
	e_rsfe();

	if (ivar == iend) {
	    return 0;
	}
	if (*list <= 1) {
	    io___97.ciunit = *iou;
	    s_wsfe(&io___97);
	    do_fio(&c__1, (char *)&ivar, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&no, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&nel, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (i <= *maxsec) {
	    goto L5;
	}
	io___98.ciunit = *iou;
	s_wsfe(&io___98);
	do_fio(&c__1, (char *)&(*maxsec), (ftnlen)sizeof(integer));
	e_wsfe();
	goto L60;
L5:
	if (ivar == namei || ivar == namev || ivar == namep || ivar == namevd)
		 {
	    goto L10;
	}
	io___99.ciunit = *iou;
	s_wsfe(&io___99);
	do_fio(&c__1, (char *)&ivar, (ftnlen)sizeof(integer));
	e_wsfe();
	ivar = namev;
	j = 1;
L10:

	if (no == i) {
	    goto L20;
	}
	io___100.ciunit = *iou;
	s_wsfe(&io___100);
	do_fio(&c__1, (char *)&no, (ftnlen)sizeof(integer));
	e_wsfe();
	no = i;
	j = 2;
L20:

	if (nel >= 0) {
	    goto L30;
	}
	io___101.ciunit = *iou;
	s_wsfe(&io___101);
	do_fio(&c__1, (char *)&nel, (ftnlen)sizeof(integer));
	e_wsfe();
	nel = -nel;
	j = 3;
L30:
	*nsec = i;
	if (ivar == namei) {
	    msec[i] = -nel;
	}
	if (ivar == namev) {
	    msec[i] = nel;
	}
	if (ivar == namevd) {
	    msec[i] = nel * 100;
	}
	if (ivar == namep) {
	    msec[i] = -(nel * 100);
	}
	if (j != 0) {
	    io___102.ciunit = *iou;
	    s_wsfe(&io___102);
	    do_fio(&c__1, (char *)&ivar, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&no, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&nel, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
L60:
	;
    }
    io___103.ciunit = *iou;
    s_wsfe(&io___103);
    e_wsfe();
    *ind = 1;
    return 0;
} /* secin2_ */

#undef namevd
#undef iend
#undef namep
#undef namev
#undef namei


/* Subroutine */ int rfund_(mf, nf, iadr, mpar, npar, parf, ind, inp, iou, 
	list)
integer *mf, *nf, *iadr, *mpar, *npar;
doublereal *parf;
integer *ind, *inp, *iou, *list;
{
    /* Initialized data */

    static struct {
	char e_1[12];
	integer e_2;
	} equiv_147 = { {'E', 'X', 'P', 'R', 'P', 'O', 'L', 'Y', 'T', 'A', 
		'B', 'L'}, 0 };

#define ityp ((integer *)&equiv_147)

    static struct {
	char e_1[32];
	integer e_2;
	} equiv_148 = { {'A', 'B', 'S', ' ', 'E', 'X', 'P', ' ', 'L', 'I', 
		'N', ' ', 'L', 'O', 'G', ' ', 'S', 'I', 'N', ' ', 'C', 'O', 
		'S', ' ', 'T', 'A', 'N', ' ', 'A', 'T', 'A', 'N'}, 0 };

#define itypf ((integer *)&equiv_148)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_149 = { {' ', ' ', ' ', ' '}, 0 };

#define iend (*(integer *)&equiv_149)


    /* Format strings */
    static char fmt_100[] = "(a4,i5)";
    static char fmt_140[] = "(//\002 ошибка : неправильная нумерация\002/)";
    static char fmt_230[] = "(/1x,\002функциональная зависимость \002,a4,i3)";
    static char fmt_160[] = "(//\002  ошибка : неизвестный тип функции\002/)";
    static char fmt_170[] = "(//\002  ошибка : превышено число параметров\
\002/)";
    static char fmt_110[] = "(a4,5f9.5)";
    static char fmt_180[] = "(/\002 Y =\002,1pe10.3,\002+\002,1pe10.3,\002*\
 \002,a4,\002((X-\002,1pe10.3,\002)/\002,1pe10.3,\002)**\002,1pe10.3)";
    static char fmt_120[] = "(i5)";
    static char fmt_130[] = "(5f9.5)";
    static char fmt_190[] = "(/20x,\002Y =   \002,1pe12.5,\002 * X **  0\002)"
	    ;
    static char fmt_195[] = "(24x,\002+ \002,1pe12.5,\002 * X ** \002,i2)";
    static char fmt_200[] = "(/18x,\002функция задана таблицей\002/)";
    static char fmt_210[] = "(18x,\002период = \002,1pe15.5/)";
    static char fmt_240[] = "(21x,\002X\002,14x,\002Y\002/(15x,1pe12.5,3x,e1\
2.5))";
    static char fmt_150[] = "(//\002 ошибка : число функций больше чем\002,i\
3/)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();

    /* Local variables */
    static integer iajf1, iajf2, i, j, n;
    static doublereal x, y;
    static integer i1;
    static doublereal xlast;
    static integer j1, j2, j3, n1, ia, jf, jj, it, jt, mfp1;

    /* Fortran I/O blocks */
    static cilist io___115 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___118 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___119 = { 0, 0, 0, fmt_230, 0 };
    static cilist io___121 = { 0, 0, 0, fmt_160, 0 };
    static cilist io___122 = { 0, 0, 0, fmt_170, 0 };
    static cilist io___126 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___128 = { 0, 0, 0, fmt_180, 0 };
    static cilist io___131 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___133 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___135 = { 0, 0, 0, fmt_190, 0 };
    static cilist io___136 = { 0, 0, 0, fmt_195, 0 };
    static cilist io___137 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___139 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___144 = { 0, 0, 0, fmt_210, 0 };
    static cilist io___145 = { 0, 0, 0, fmt_240, 0 };
    static cilist io___146 = { 0, 0, 0, fmt_150, 0 };


/*     **************** */
/*     30.9.1981 */

    /* Parameter adjustments */
    --parf;
    iadr -= 4;

    /* Function Body */

    ia = 1;
    *nf = 0;
    *ind = 0;
    mfp1 = *mf + 1;
    i__1 = mfp1;
    for (i = 1; i <= i__1; ++i) {

	io___115.ciunit = *inp;
	s_rsfe(&io___115);
	do_fio(&c__1, (char *)&it, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&i1, (ftnlen)sizeof(integer));
	e_rsfe();
	if (it == iend) {
	    goto L95;
	}
	if (i == mfp1) {
	    goto L80;
	}
	if (i != i1) {
	    io___118.ciunit = *iou;
	    s_wsfe(&io___118);
	    e_wsfe();
	}
	if (i != i1) {
	    goto L90;
	}
	if (*list >= 2) {
	    io___119.ciunit = *iou;
	    s_wsfe(&io___119);
	    do_fio(&c__1, (char *)&it, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&i1, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
/* декодир. типа функц. завис. */
	for (jt = 1; jt <= 3; ++jt) {
/* L10: */
	    if (it == ityp[jt - 1]) {
		goto L20;
	    }
	}
L15:
	io___121.ciunit = *iou;
	s_wsfe(&io___121);
	e_wsfe();
	goto L90;
L20:
	if (jt > 1) {
	    goto L40;
	}
/* ввод сьанд. */
	if (ia + 4 <= *mpar) {
	    goto L27;
	}
L25:
	io___122.ciunit = *iou;
	s_wsfe(&io___122);
	e_wsfe();
	goto L90;
L27:
	j1 = ia;
	j2 = ia + 4;
	j3 = ia + 2;
	io___126.ciunit = *inp;
	s_rsfe(&io___126);
	do_fio(&c__1, (char *)&it, (ftnlen)sizeof(integer));
	i__2 = j2;
	for (j = j1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&parf[j], (ftnlen)sizeof(doublereal));
	}
	e_rsfe();
	io___128.ciunit = *iou;
	s_wsfe(&io___128);
	do_fio(&c__1, (char *)&parf[ia], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&parf[ia + 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&it, (ftnlen)sizeof(integer));
	i__2 = j2;
	for (j = j3; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&parf[j], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
/* декодир. */
	n1 = 5;
	for (jf = 1; jf <= 8; ++jf) {
/* L30: */
	    if (it == itypf[jf - 1]) {
		goto L60;
	    }
	}
	goto L15;

L40:
	if (jt == 3) {
	    goto L50;
	}
	io___131.ciunit = *inp;
	s_rsfe(&io___131);
	do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
	e_rsfe();
	n1 = n + 1;
	if (ia + n1 > *mpar) {
	    goto L25;
	}
	j1 = ia;
	j2 = ia + n;
	io___133.ciunit = *inp;
	s_rsfe(&io___133);
	i__2 = j2;
	for (j = j1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&parf[j], (ftnlen)sizeof(doublereal));
	}
	e_rsfe();
	jj = 1;
	io___135.ciunit = *iou;
	s_wsfe(&io___135);
	do_fio(&c__1, (char *)&parf[ia], (ftnlen)sizeof(doublereal));
	e_wsfe();
	j1 = ia + 1;
	i__2 = j2;
	for (j = j1; j <= i__2; ++j) {
	    io___136.ciunit = *iou;
	    s_wsfe(&io___136);
	    do_fio(&c__1, (char *)&parf[j], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&jj, (ftnlen)sizeof(integer));
	    e_wsfe();
/* L45: */
	    ++jj;
	}
	jf = n;
	goto L60;

L50:
	if (*list < 1) {
	    io___137.ciunit = *iou;
	    s_wsfe(&io___137);
	    e_wsfe();
	}
	jf = 1;
	xlast = -1e35;
L52:
	if (ia + jf > *mpar) {
	    goto L25;
	}
	io___139.ciunit = *inp;
	s_rsfe(&io___139);
	do_fio(&c__1, (char *)&x, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y, (ftnlen)sizeof(doublereal));
	e_rsfe();
	if (x < xlast) {
	    goto L55;
	}
	iajf1 = ia + jf;
	iajf2 = ia + jf + 1;
	parf[iajf1] = x;
	parf[iajf2] = y;
	xlast = x;
	jf += 2;
	goto L52;
L55:
	parf[ia] = y;
	if (y != 0.) {
	    io___144.ciunit = *iou;
	    s_wsfe(&io___144);
	    do_fio(&c__1, (char *)&y, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	n1 = jf;
	j1 = ia + 1;
	j2 = ia + jf - 1;
	io___145.ciunit = *iou;
	s_wsfe(&io___145);
	i__2 = j2;
	for (j = j1; j <= i__2; j += 2) {
	    do_fio(&c__1, (char *)&parf[j], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&parf[j + 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	jf = (jf - 1) / 2;

L60:
	iadr[i * 3 + 1] = ia;
	iadr[i * 3 + 2] = jt;
	iadr[i * 3 + 3] = jf;

/* L70: */
	ia += n1;
    }
L80:
    io___146.ciunit = *iou;
    s_wsfe(&io___146);
    do_fio(&c__1, (char *)&(*mf), (ftnlen)sizeof(integer));
    e_wsfe();
L90:
    *ind = 1;
    return 0;

L95:
    *nf = i - 1;
    *npar = ia - 1;
    return 0;
} /* rfund_ */

#undef iend
#undef itypf
#undef ityp


/* Subroutine */ int node_(net, nels, ndim, newn, maxn, nods, ind, iou)
integer *net, *nels, *ndim, *newn, *maxn, *nods, *ind, *iou;
{
    /* Format strings */
    static char fmt_100[] = "(1x,\002 ошибка : у элемента номер\002,i3,1x\
,\002задан недопустимый номер узла\002,2i5)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static logical help[100];
    static integer nodm, izer, ityp, i;
    extern integer ncode_();
    static integer l1, l2, ii;

    /* Fortran I/O blocks */
    static cilist io___158 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___159 = { 0, 0, 0, fmt_100, 0 };


/*     *************** */
/* декодир. элем. и опр. */
/*     17.9.1981 */

    /* Parameter adjustments */
    --newn;
    net -= 6;

    /* Function Body */
    *nods = 0;
    nodm = 0;
    i__1 = *maxn;
    for (i = 1; i <= i__1; ++i) {
	help[i - 1] = TRUE_;
/* L10: */
    }

    i__1 = *nels;
    for (ii = 1; ii <= i__1; ++ii) {
	i = ii;
	izer = 0;
	ityp = ncode_(&net[i * 5 + 1], &izer);
	net[i * 5 + 1] = ityp;
/* исключение M K */
	if (ityp >= 39) {
	    goto L50;
	}
	if (ityp == 15 || ityp == 16) {
	    goto L50;
	}
	l1 = net[i * 5 + 2];
	l2 = net[i * 5 + 3];
	if (l1 >= 100 || l2 >= 100) {
	    goto L25;
	}
	if (l1 >= 0 && l2 >= 0) {
	    goto L30;
	}
L25:
	io___158.ciunit = *iou;
	s_wsfe(&io___158);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&l1, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&l2, (ftnlen)sizeof(integer));
	e_wsfe();
	net[i * 5 + 1] = 0;
	*ind = 1;
	goto L50;
L30:
/* Computing MAX */
	i__2 = max(nodm,l1);
	nodm = max(i__2,l2);
	if (l1 != 0) {
	    help[l1 - 1] = FALSE_;
	}
	if (l2 != 0) {
	    help[l2 - 1] = FALSE_;
	}
/* исключение узлов транз. */
	if (ityp < 22 || ityp > 25) {
	    goto L50;
	}
	l1 = net[i * 5 + 4];
	if (l1 < 100 && l1 >= 0) {
	    goto L40;
	}
	io___159.ciunit = *iou;
	s_wsfe(&io___159);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&l1, (ftnlen)sizeof(integer));
	e_wsfe();
	net[i * 5 + 1] = 0;
	*ind = 1;
	goto L50;
L40:
	nodm = max(nodm,l1);
	if (l1 != 0) {
	    help[l1 - 1] = FALSE_;
	}
L50:
	;
    }
    i__1 = nodm;
    for (i = 1; i <= i__1; ++i) {
	if (help[i - 1]) {
	    goto L70;
	}
	++(*nods);
	newn[*nods] = i;
L70:
	;
    }
    return 0;
} /* node_ */

/* Subroutine */ int ntabl_(net, nels, ndim, newn, nods, ind, iou, list)
integer *net, *nels, *ndim, *newn, *nods, *ind, *iou, *list;
{
    /* Format strings */
    static char fmt_140[] = "(/1x,\002 ошибка : задан только узел номер \"\
 0 \"\002)";
    static char fmt_100[] = "(/20x,\002ТАБЛИЦА СОЕДИНЕНИЙ\002//7x,\002узе\
л\002,5x,\002элементы\002)";
    static char fmt_110[] = "(/\002 ошибка : проверьте соединение элементов \
в узле \"0\"\002)";
    static char fmt_120[] = "(/7x,i3,5(6x,a2,2x,i2)/(10x,5(6x,a2,2x,i2)))";
    static char fmt_130[] = "(/\002 ошибка : к узлу номер \002,i4,\002 подхо\
дит один элемент\002)";

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
    static integer nodc[100]	/* was [2][50] */, nnod, izer, ityp, nods1, i,
	     j, l, m, n;
    extern integer ncode_();
    static integer i1, ic, nc;
    static logical con;
    static integer nod, iup;

    /* Fortran I/O blocks */
    static cilist io___160 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___162 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___176 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___177 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___180 = { 0, 0, 0, fmt_130, 0 };


/*     **************** */

/*     17.9.1981 */

    /* Parameter adjustments */
    --newn;
    net -= 6;

    /* Function Body */
    if (*nods > 0) {
	goto L10;
    }
    io___160.ciunit = *iou;
    s_wsfe(&io___160);
    e_wsfe();
    *ind = 2;
    return 0;
L10:
    nods1 = *nods + 1;
    if (*list >= 5) {
	io___162.ciunit = *iou;
	s_wsfe(&io___162);
	e_wsfe();
    }
    nod = 0;
    i__1 = nods1;
    for (i1 = 1; i1 <= i__1; ++i1) {
	i = i1 - 1;
	nc = 0;
	if (i != 0) {
	    nod = newn[i];
	}
	nnod = i;
	if (nnod == 0) {
	    nnod = *ndim;
	}
	i__2 = *nels;
	for (j = 1; j <= i__2; ++j) {
/* исключение M K */
	    izer = 0;
	    ityp = net[j * 5 + 1];
	    if (ityp >= 39) {
		goto L60;
	    }
	    if (ityp == 0) {
		goto L60;
	    }
	    if (ityp == 15 || ityp == 16) {
		goto L60;
	    }
	    iup = 3;
	    if (ityp >= 22 && ityp <= 25) {
		iup = 4;
	    }
/* установка узлов для ER */
	    if (ityp == 5) {
		goto L25;
	    }
	    if (ityp == 18 || ityp == 19) {
		goto L25;
	    }
	    goto L30;
L25:
	    ic = net[j * 5 + 4];
	    net[j * 5 + 2] = net[ic * 5 + 2];
	    net[j * 5 + 3] = net[ic * 5 + 3];
L30:
/* нахождение элементов, подсоедин. k I- */
	    con = FALSE_;
	    i__3 = iup;
	    for (l = 2; l <= i__3; ++l) {
		if (net[l + j * 5] != nod) {
		    goto L40;
		}
		con = TRUE_;
/* перенумерация узла I */
		net[l + j * 5] = nnod;
L40:
		;
	    }
	    if (! con) {
		goto L60;
	    }
	    ++nc;
	    l = 1;
	    nodc[(nc << 1) - 2] = ncode_(&net[j * 5 + 1], &l);
	    nodc[(nc << 1) - 1] = j;
L60:
	    ;
	}
/* печать элементов, подсоединенных к I' */
	if (nc != 0) {
	    goto L70;
	}
	io___176.ciunit = *iou;
	s_wsfe(&io___176);
	e_wsfe();
	*ind = 1;
	goto L80;
L70:
	if (*list >= 5) {
	    io___177.ciunit = *iou;
	    s_wsfe(&io___177);
	    do_fio(&c__1, (char *)&nod, (ftnlen)sizeof(integer));
	    i__2 = nc;
	    for (n = 1; n <= i__2; ++n) {
		for (m = 1; m <= 2; ++m) {
		    do_fio(&c__1, (char *)&nodc[m + (n << 1) - 3], (ftnlen)
			    sizeof(integer));
		}
	    }
	    e_wsfe();
	}
	if (nc == 1) {
	    io___180.ciunit = *iou;
	    s_wsfe(&io___180);
	    do_fio(&c__1, (char *)&nod, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
L80:
	;
    }
    return 0;
} /* ntabl_ */

integer ncode_(name, key)
integer *name, *key;
{
    /* Initialized data */

    static struct {
	char e_1[192];
	integer e_2;
	} equiv_184 = { {'R', ' ', ' ', ' ', 'G', ' ', ' ', ' ', 'J', ' ', 
		' ', ' ', 'E', ' ', ' ', ' ', 'E', 'R', ' ', ' ', 'I', 'V', 
		' ', ' ', 'I', 'I', ' ', ' ', 'V', 'V', ' ', ' ', 'V', 'I', 
		' ', ' ', '0', ' ', ' ', ' ', 'N', ' ', ' ', ' ', 'O', 'A', 
		' ', ' ', 'C', ' ', ' ', ' ', 'L', ' ', ' ', ' ', 'K', ' ', 
		' ', ' ', 'M', ' ', ' ', ' ', 'D', ' ', ' ', ' ', 'C', 'D', 
		' ', ' ', 'C', 'B', ' ', ' ', 'R', 'I', ' ', ' ', 'G', 'V', 
		' ', ' ', 'N', 'P', ' ', ' ', 'P', 'N', ' ', ' ', 'N', 'M', 
		' ', ' ', 'P', 'M', ' ', ' ', 'D', 'D', ' ', ' ', 'Z', 'D', 
		' ', ' ', 'T', ' ', ' ', ' ', 'K', 'T', ' ', ' ', 'K', 'V', 
		' ', ' ', 'K', 'I', ' ', ' ', 'T', '1', ' ', ' ', 'T', '2', 
		' ', ' ', 'T', '3', ' ', ' ', 'T', '4', ' ', ' ', 'T', '5', 
		' ', ' ', 'T', '6', ' ', ' ', 'T', '7', ' ', ' ', 'P', 'R', 
		' ', ' ', 'A', 'N', ' ', ' ', 'O', 'R', ' ', ' ', 'N', 'O', 
		' ', ' ', 'S', 'T', ' ', ' ', 'P', 'P', ' ', ' ', 'R', 'S', 
		' ', ' ', 'D', 'C', ' ', ' ', 'T', 'T', ' ', ' ', 'J', 'K', 
		' ', ' '}, 0 };

#define ichar ((integer *)&equiv_184)

    static integer nel = 48;

    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer i;

/*     *************** */

/*     3.9.1981 */
    if (*key != 0) {
	goto L20;
    }

    i__1 = nel;
    for (i = 1; i <= i__1; ++i) {
	if (*name == ichar[i - 1]) {
	    goto L10;
	}
/* L5: */
    }
    *key = -1;
    ret_val = *name;
    return ret_val;
L10:
    ret_val = i;
    return ret_val;

L20:
    if (*name > nel) {
	goto L25;
    }
    ret_val = ichar[*name - 1];
    return ret_val;
L25:
    *key = -1;
    ret_val = *name;
    return ret_val;
} /* ncode_ */

#undef ichar


/* Subroutine */ int neqd_(nels, net, val, nods, ndim, neqs, ind, iou)
integer *nels, *net;
doublereal *val;
integer *nods, *ndim, *neqs, *ind, *iou;
{
    /* Format strings */
    static char fmt_9000[] = "(1x,\002 ошибка : в описании схемы прповерьте \
элемент\002,\002 номер\002,i5)";
    static char fmt_9010[] = "(1x,\002 ошибка : недопустимый код\002,3x,a2,5\
x,\002у элемента номер\002,i5,3x,\002- элемент игнорируется\002)";
    static char fmt_9080[] = "(1x,\002 ошибка : в задании у элемента номе\
р\002,i5,3x,\002одинакрвые номера узлов\002)";
    static char fmt_9090[] = "(1x,\002 ошибка : в задании у \"k\",\"m\" но\
мер\002,i5,3x,\002одинаковые номера индуктивностей\002)";
    static char fmt_9060[] = "(1x,\002 ошибка : у элементов типа \"k\",\"m\"\
 номер\002,i5,3x,\002есть ссылка на элемент номер\002,i5,3x,\002, который не\
 является \"L\"\002)";
    static char fmt_9070[] = "(1x,\002 ошибка : в задании у элемента \"k\" н\
омер\002,i5,3x,\002есть связь L(\002,i3,\002) * L(\002,i3,\002) <= 0.\002)";
    static char fmt_9020[] = "(1x,\002 ошибка : у неуправляемого элемента но\
мер\002,i5,3x,\002задано управление\002,\002 - управление игнорируется\002)";
    static char fmt_9030[] = "(1x,\002 ошибка : в задании у управляемого эле\
мента\002,\002номер\002,i5,3x,\002неправильно задано управление\002)";
    static char fmt_9050[] = "(1x,\002 ошибка : в задании у элемента номе\
р\002,i5,3x,\002номер управляющего элемента\002,i5,3x,\002превышает число за\
данных элементов\002,i5)";
    static char fmt_9040[] = "(1x,\002 ошибка : в задании у элемента номе\
р\002,i5,3x,\002неправильный тип управляемого элемента номер\002,i5)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer ityp, i, j, k;
    static doublereal value;
    static integer k1, ii;

    /* Fortran I/O blocks */
    static cilist io___188 = { 0, 0, 0, fmt_9000, 0 };
    static cilist io___189 = { 0, 0, 0, fmt_9010, 0 };
    static cilist io___190 = { 0, 0, 0, fmt_9080, 0 };
    static cilist io___191 = { 0, 0, 0, fmt_9090, 0 };
    static cilist io___194 = { 0, 0, 0, fmt_9060, 0 };
    static cilist io___195 = { 0, 0, 0, fmt_9060, 0 };
    static cilist io___197 = { 0, 0, 0, fmt_9070, 0 };
    static cilist io___198 = { 0, 0, 0, fmt_9020, 0 };
    static cilist io___199 = { 0, 0, 0, fmt_9030, 0 };
    static cilist io___200 = { 0, 0, 0, fmt_9050, 0 };
    static cilist io___202 = { 0, 0, 0, fmt_9040, 0 };


/*     *************** */

/*     19.9.1981 */
    /* Parameter adjustments */
    --val;
    net -= 6;

    /* Function Body */
    *neqs = *nods;
    i__1 = *nels;
    for (ii = 1; ii <= i__1; ++ii) {
	i = ii;
	ityp = net[i * 5 + 1];

	if (ityp != 0) {
	    goto L10;
	}
	io___188.ciunit = *iou;
	s_wsfe(&io___188);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	e_wsfe();
	goto L900;
L10:

	if (ityp > 0 && ityp < 49) {
	    goto L20;
	}
	io___189.ciunit = *iou;
	s_wsfe(&io___189);
	do_fio(&c__1, (char *)&ityp, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	e_wsfe();
	goto L900;
L20:
	if (ityp == 5) {
	    goto L30;
	}
	if (ityp == 18 || ityp == 19) {
	    goto L30;
	}
	if (ityp >= 22 && ityp <= 25) {
	    goto L30;
	}
	if (net[i * 5 + 2] != net[i * 5 + 3]) {
	    goto L30;
	}
	if (ityp == 15 || ityp == 16) {
	    goto L25;
	}
	if (ityp == 32 || ityp == 33) {
	    goto L30;
	}
	io___190.ciunit = *iou;
	s_wsfe(&io___190);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	e_wsfe();
	goto L30;
L25:
	io___191.ciunit = *iou;
	s_wsfe(&io___191);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	e_wsfe();
L30:
/*              R    G    J    E   ER   IV   II   VV */
/*             VI    0    N   OA    C    L    K    M */
/*              D   CD   CB   RI   GV   NPN  PNP NMOS */
/*            PMOS  DD   ZD   T    KT   KV   KI   T1 */
/*             T2   T3   T4   T5   T6   PI   PR   AN */
/*             OR   NOT  ST  PP  RS    DC   TT   JK */
	switch ((int)ityp) {
	    case 1:  goto L300;
	    case 2:  goto L300;
	    case 3:  goto L300;
	    case 4:  goto L110;
	    case 5:  goto L120;
	    case 6:  goto L130;
	    case 7:  goto L140;
	    case 8:  goto L150;
	    case 9:  goto L160;
	    case 10:  goto L170;
	    case 11:  goto L300;
	    case 12:  goto L150;
	    case 13:  goto L300;
	    case 14:  goto L110;
	    case 15:  goto L190;
	    case 16:  goto L190;
	    case 17:  goto L300;
	    case 18:  goto L200;
	    case 19:  goto L200;
	    case 20:  goto L110;
	    case 21:  goto L900;
	    case 22:  goto L900;
	    case 23:  goto L900;
	    case 24:  goto L900;
	    case 25:  goto L900;
	    case 26:  goto L300;
	    case 27:  goto L300;
	    case 28:  goto L110;
	    case 29:  goto L110;
	    case 30:  goto L110;
	    case 31:  goto L110;
	    case 32:  goto L350;
	    case 33:  goto L350;
	    case 34:  goto L350;
	    case 35:  goto L350;
	    case 36:  goto L350;
	    case 37:  goto L350;
	    case 38:  goto L300;
	    case 39:  goto L900;
	    case 40:  goto L900;
	    case 41:  goto L900;
	    case 42:  goto L900;
	    case 43:  goto L900;
	    case 44:  goto L900;
	    case 45:  goto L900;
	    case 46:  goto L900;
	    case 47:  goto L900;
	    case 48:  goto L900;
	}
/* E,L,RI - */
L110:
	if (net[i * 5 + 5] != 0) {
	    goto L300;
	}
	++(*neqs);
	net[i * 5 + 5] = *neqs;
	if (ityp >= 29) {
	    goto L900;
	}
	if (ityp == 20) {
	    goto L900;
	}
	goto L300;
/* ER */
L120:
	k = net[i * 5 + 4];
	if (k == 0) {
	    goto L810;
	}

	if (net[k * 5 + 1] != 1) {
	    goto L850;
	}
	goto L900;

/* IV */
L130:
	k = net[i * 5 + 4];
	if (k == 0) {
	    goto L810;
	}
	goto L820;
/* II */
L140:
	k = net[i * 5 + 4];
	if (k == 0) {
	    goto L810;
	}
	if (k == i) {
	    goto L850;
	}
	if (net[k * 5 + 5] != 0) {
	    goto L820;
	}

	++(*neqs);
	net[k * 5 + 5] = *neqs;
	goto L820;
/* VV */
L150:
	k = net[i * 5 + 4];
	if (k == 0) {
	    goto L810;
	}
	if (k == i) {
	    goto L850;
	}
	if (net[i * 5 + 5] != 0) {
	    goto L820;
	}
	++(*neqs);
	net[i * 5 + 5] = *neqs;
	goto L820;
/* VI */
L160:
	k = net[i * 5 + 4];
	if (k == 0) {
	    goto L810;
	}
	if (net[i * 5 + 5] != 0) {
	    goto L165;
	}
	++(*neqs);
	net[i * 5 + 5] = *neqs;
L165:
	if (net[k * 5 + 5] != 0) {
	    goto L820;
	}
	++(*neqs);
	net[k * 5 + 5] = *neqs;
	goto L820;

L170:
	k = net[i * 5 + 4];
	if (k == 0) {
	    goto L810;
	}
	if (net[k * 5 + 1] != 11) {
	    goto L850;
	}
	if (net[k * 5 + 5] != 0) {
	    goto L820;
	}
	++(*neqs);
	net[k * 5 + 5] = *neqs;
	goto L820;
/* K,M */
L190:
	k1 = net[i * 5 + 2];
	if (net[k1 * 5 + 1] == 14) {
	    goto L192;
	}
	io___194.ciunit = *iou;
	s_wsfe(&io___194);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&k1, (ftnlen)sizeof(integer));
	e_wsfe();
	*ind = 5;
L192:
	k = net[i * 5 + 3];
	if (net[k * 5 + 1] == 14) {
	    goto L194;
	}
	io___195.ciunit = *iou;
	s_wsfe(&io___195);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	e_wsfe();
	*ind = 5;
	goto L900;
L194:
	if (ityp == 16) {
	    goto L300;
	}
	value = val[k1] * val[k];
	if (value > 0.) {
	    goto L300;
	}
	io___197.ciunit = *iou;
	s_wsfe(&io___197);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&k1, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	e_wsfe();
	*ind = 6;
	goto L900;
/* CD,CB */
L200:
	k = net[i * 5 + 4];
	if (k == 0) {
	    goto L810;
	}
	if (net[k * 5 + 1] != 17) {
	    goto L850;
	}
	goto L820;
/* R,G,J,C,D,DD,ZD */
L300:
	if (net[i * 5 + 4] != 0) {
	    goto L800;
	}
	if (net[i * 5 + 1] != 1) {
	    goto L900;
	}

	if (val[i] != 0.) {
	    goto L900;
	}
	++(*neqs);
	net[i * 5 + 5] = *neqs;
	goto L900;
/* T1,T2,T3,T4,T5,T6 */
L350:
	if (net[i * 5 + 1] == 32) {
	    ++(*neqs);
	}
	++(*neqs);
	net[i * 5 + 5] = *neqs;
	goto L900;

L800:
	io___198.ciunit = *iou;
	s_wsfe(&io___198);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	e_wsfe();
	net[i * 5 + 4] = 0;
	goto L900;

L810:
	io___199.ciunit = *iou;
	s_wsfe(&io___199);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	e_wsfe();
	*ind = 2;
	goto L900;


L820:
	if (k <= *nels) {
	    goto L830;
	}
	io___200.ciunit = *iou;
	s_wsfe(&io___200);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*nels), (ftnlen)sizeof(integer));
	e_wsfe();
	*ind = 3;
	goto L900;

L830:
	if (ityp > 9) {
	    goto L900;
	}
	j = net[k * 5 + 1];
	if (j != 15 || j != 16) {
	    goto L840;
	}
	goto L850;
L840:
	if (j <= 22 || j >= 25) {
	    goto L900;
	}
L850:

	io___202.ciunit = *iou;
	s_wsfe(&io___202);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	e_wsfe();
	*ind = 4;
L900:
	;
    }
    return 0;
} /* neqd_ */

