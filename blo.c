/* blo.f -- translated by f2c (version of 23 April 1993  18:34:30).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer icont, ind, inp, iou, irec, irec1;
    real temp;
    integer name[30], maxsec, nsec, msec[10], nout[10], nfun, npar, iadr[30]	
	    /* was [3][10] */;
    doublereal parf[100];
    integer maxel, nels, net[300]	/* was [5][60] */;
    doublereal val[60];
    integer nods, newn[20], ndim, neqs, intr[20];
    doublereal x[20];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__30 = 30;
static integer c__10 = 10;
static integer c__100 = 100;
static integer c__5 = 5;
static integer c__1 = 1;
static integer c__3 = 3;

/* Subroutine */ int bloc_()
{
    /* Initialized data */

    static struct {
	char e_1[24];
	real e_2;
	} equiv_8 = { {'L', 'I', 'S', 'T', 'P', 'R', 'O', 'B', 'B', 'L', 'O', 
		'C', 'O', 'U', 'T', 'P', 'E', 'N', 'D', ' ', 'F', 'U', 'N', 
		'C'}, (float)0. };

#define con ((real *)&equiv_8)


    /* Format strings */
    static char fmt_100[] = "(30a2)";
    static char fmt_110[] = "(//1x,30a2)";

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dmat_(), imat_();
    static integer ncon;
    extern integer ierr_();
    static integer list, i;
    extern /* Subroutine */ int block_(), rfund_(), testb_(), rlist_(), 
	    bseci1_(), contr1_(), bloind_();
    static integer key;

    /* Fortran I/O blocks */
    static cilist io___6 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___7 = { 0, 0, 0, fmt_110, 0 };


/*     *************** */
/*     6.10.1981 */
/* READING IN AND PROCESSING BLOCK DIAGRAM STRUCTURE */
/* AND OUTPUT VARIABLES */




/* CHARACTER STRINGS */
/* EXTENT OF VARIABLES */
    ncon = 6;
/* DEFAULT VALUES */
    _BLNK__1.icont = 2;
    _BLNK__1.maxel = 20;
    list = 0;
    _BLNK__1.nsec = 10;
    _BLNK__1.nfun = 0;
    _BLNK__1.npar = 0;
/* CONTROL BY COMMANDS */
    for (i = 1; i <= 20; ++i) {
	contr1_(&ncon, con, &key, &_BLNK__1.inp, &_BLNK__1.iou);
	if (key != 0) {
	    goto L8;
	}
	key = ierr_(&_BLNK__1.icont, &ncon);
	goto L95;
L8:
	switch ((int)key) {
	    case 1:  goto L10;
	    case 2:  goto L20;
	    case 3:  goto L30;
	    case 4:  goto L40;
	    case 5:  goto L99;
	    case 6:  goto L60;
	}
/* READING IN LIST */
L10:
	rlist_(&_BLNK__1.inp, &_BLNK__1.iou, &list);
	goto L95;
/* READING IN TITLE PROBLEM */
L20:
	io___6.ciunit = _BLNK__1.inp;
	s_rsfe(&io___6);
	do_fio(&c__30, (char *)&_BLNK__1.name[0], (ftnlen)sizeof(integer));
	e_rsfe();
	io___7.ciunit = _BLNK__1.iou;
	s_wsfe(&io___7);
	do_fio(&c__30, (char *)&_BLNK__1.name[0], (ftnlen)sizeof(integer));
	e_wsfe();
	goto L95;
/* READING IN BLOCK DIAGRAM STRUCTURE */
L30:
	bloind_(&_BLNK__1.ndim, _BLNK__1.net, _BLNK__1.val, &_BLNK__1.nels, &
		_BLNK__1.ind, &_BLNK__1.inp, &_BLNK__1.iou);
	_BLNK__1.ind = ierr_(&_BLNK__1.icont, &_BLNK__1.ind);
	block_(&_BLNK__1.nels, _BLNK__1.net, _BLNK__1.val, &_BLNK__1.neqs, 
		_BLNK__1.newn, &_BLNK__1.ind, &_BLNK__1.iou);
	goto L90;
/* READING IN REQUIRED OUTPUT VARIABLES */
L40:
	bseci1_(&c__10, &_BLNK__1.nsec, _BLNK__1.msec, _BLNK__1.nout, &
		_BLNK__1.ind, &_BLNK__1.inp, &_BLNK__1.iou);
	goto L90;
L60:
	rfund_(&c__10, &_BLNK__1.nfun, _BLNK__1.iadr, &c__100, &_BLNK__1.npar,
		 _BLNK__1.parf, &_BLNK__1.ind, &_BLNK__1.inp, &_BLNK__1.iou);
L90:
	_BLNK__1.ind = ierr_(&_BLNK__1.icont, &_BLNK__1.ind);
L95:
	;
    }
    _BLNK__1.ind = 10;
L99:
    testb_(&_BLNK__1.nels, _BLNK__1.net, &_BLNK__1.neqs, _BLNK__1.newn, &
	    _BLNK__1.nsec, _BLNK__1.msec, &_BLNK__1.ind, &_BLNK__1.iou);
    _BLNK__1.ind = ierr_(&_BLNK__1.icont, &_BLNK__1.ind);
/* DIAGNOSTIC PRINTOUT */
    if (list >= 1) {
	imat_(&c__5, &_BLNK__1.nels, &c__5, _BLNK__1.net, "NET ", &
		_BLNK__1.iou, 4L);
    }
    if (list >= 2) {
	dmat_(&c__1, &_BLNK__1.nels, &c__1, _BLNK__1.val, "VAL     ", &
		_BLNK__1.iou, 8L);
    }
    if (list >= 3) {
	imat_(&c__1, &_BLNK__1.nsec, &c__1, _BLNK__1.msec, "MSEC", &
		_BLNK__1.iou, 4L);
    }
    if (list < 4) {
	goto L1000;
    }
    imat_(&c__1, &_BLNK__1.nels, &c__1, _BLNK__1.newn, "NEWN", &_BLNK__1.iou, 
	    4L);
    if (_BLNK__1.nfun == 0) {
	goto L1000;
    }
    imat_(&c__3, &_BLNK__1.nfun, &c__3, _BLNK__1.iadr, "IADR", &_BLNK__1.iou, 
	    4L);
    dmat_(&c__1, &_BLNK__1.npar, &c__1, _BLNK__1.parf, "PARF    ", &
	    _BLNK__1.iou, 8L);
L1000:
    return 0;
} /* bloc_ */

#undef con


/* Subroutine */ int testb_(nels, net, n, newn, nsec, msec, ind, iou)
integer *nels, *net, *n, *newn, *nsec, *msec, *ind, *iou;
{
    /* Initialized data */

    static integer ninp[8] = { 3,2,3,3,3,2,0,3 };

    /* Format strings */
    static char fmt_100[] = "(1x,\002ОШИБКА : у блока номер\002,i3,\002задан\
 неверный вход\002,i3)";
    static char fmt_110[] = "(1x,\002ошибка : выходная величина номер\002,\
i3,\002задана на несуществующем блоке номер\002,i3)";

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer i_sign(), s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer ityp, i, j, k, l, ihelp, i1, ix, iy, iup;

    /* Fortran I/O blocks */
    static cilist io___17 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___21 = { 0, 0, 0, fmt_110, 0 };


/*     **************** */
/* TEST OF CONECTION OF BLOCKS AND TEST OF OUTPUTS */
/*      16.7.1981 */
    /* Parameter adjustments */
    --msec;
    --newn;
    net -= 6;

    /* Function Body */
    *ind = 0;
    i__1 = *n;
    for (i = 1; i <= i__1; ++i) {
	ityp = net[i * 5 + 1] - 100;
	if (ityp == 7) {
	    goto L50;
	}
	iup = ninp[ityp - 1] + 1;
	i__2 = iup;
	for (j = 2; j <= i__2; ++j) {
	    ix = (i__3 = net[j + i * 5], abs(i__3));
	    if (ix > *nels) {
		goto L10;
	    }
	    if (ix == 0) {
		goto L40;
	    }
	    iy = newn[ix];
	    if (iy == 0) {
		goto L10;
	    }
	    if (net[iy * 5 + 1] == 0) {
		goto L10;
	    }
	    net[j + i * 5] = i_sign(&iy, &net[j + i * 5]);
	    goto L40;
/* INVALID INPUT */
L10:
	    i__3 = *nels;
	    for (l = 1; l <= i__3; ++l) {
		if (i == newn[l]) {
		    goto L30;
		}
/* L20: */
	    }
L30:
	    io___17.ciunit = *iou;
	    s_wsfe(&io___17);
	    do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	    e_wsfe();
	    *ind = 1;
L40:
	    ;
	}
L50:
	;
    }
/* TESTING OF OUTPUTS */
    ihelp = 0;
    i__1 = *nsec;
    for (i1 = 1; i1 <= i__1; ++i1) {
	i = i1;
	k = msec[i];
	if (k < 0 || k > *nels) {
	    goto L60;
	}
	l = newn[k];
	if (l == 0) {
	    goto L60;
	}
	l = net[l * 5 + 1];
	if (l == 0) {
	    goto L60;
	}
	goto L80;
/* ERROR MESSAGE */
L60:
	io___21.ciunit = *iou;
	s_wsfe(&io___21);
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	e_wsfe();
	*ind = 1;
L80:
	;
    }
    return 0;
} /* testb_ */

/* Subroutine */ int bloind_(maxel, net, val, nels, ind, input, iout)
integer *maxel, *net;
doublereal *val;
integer *nels, *ind, *input, *iout;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	real e_2;
	} equiv_40 = { {' ', ' ', ' ', ' '}, (float)0. };

#define end (*(real *)&equiv_40)


    /* Format strings */
    static char fmt_100[] = "(///22x,\002 элементы блок-схемы\002//7x,\002ти\
п  номер  вход 1  вход 2  V3/FUN      параметр\002/)";
    static char fmt_110[] = "(2a2,4i5,f9.5)";
    static char fmt_120[] = "(1x,\002ошибка : номер блока\002,i5,2x,\002недо\
пустим\002)";
    static char fmt_130[] = "(1x,\002опущена строка\002,5x,2a2,2x,4i5,1pe15.\
5)";
    static char fmt_140[] = "(1x,\002ошибка : под номером\002,i5,2x,\002зада\
но много блоков\002)";
    static char fmt_150[] = "(7x,2a2,2x,i3,4x,3(i3,5x),1pe14.5)";
    static char fmt_160[] = "(1x,\002ошибка : нет знака окончания\002)";

    /* System generated locals */
    integer i__1;
    static real equiv_0[6];

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
    static integer ielm;
#define line ((integer *)equiv_0)
    extern /* Subroutine */ int nuld_();
#define word (equiv_0)
    static integer melp1, i, j;
    static doublereal value;
    static integer iel, iou;
    extern /* Subroutine */ int nul_();

    /* Fortran I/O blocks */
    static cilist io___26 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___29 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___33 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___35 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_150, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_160, 0 };


/*     ***************** */

/*     6.10.1981 */
    /* Parameter adjustments */
    --val;
    net -= 6;

    /* Function Body */
/* NULOVANI POLI A PROMENNYCH */
    nul_(&c__5, maxel, &c__5, &net[6]);
    nuld_(&c__1, maxel, &c__1, &val[1]);
    *nels = 0;
    ielm = 0;
    *ind = 0;
/* NACTENI A TISK TABULKY PRVKU BLOKOVEHO SCHEMATU */
    io___26.ciunit = *iout;
    s_wsfe(&io___26);
    e_wsfe();
    melp1 = *maxel + 1;
    i__1 = melp1;
    for (i = 1; i <= i__1; ++i) {
	io___29.ciunit = *input;
	s_rsfe(&io___29);
	for (j = 1; j <= 6; ++j) {
	    do_fio(&c__1, (char *)&line[j - 1], (ftnlen)sizeof(integer));
	}
	do_fio(&c__1, (char *)&value, (ftnlen)sizeof(doublereal));
	e_rsfe();
	iel = line[2];
	if (*word == end) {
	    goto L50;
	}
	if (iel > 0 && iel <= *maxel) {
	    goto L20;
	}
	*ind = 1;
	io___33.ciunit = *iout;
	s_wsfe(&io___33);
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	e_wsfe();
	io___34.ciunit = *iout;
	s_wsfe(&io___34);
	for (j = 1; j <= 6; ++j) {
	    do_fio(&c__1, (char *)&line[j - 1], (ftnlen)sizeof(integer));
	}
	do_fio(&c__1, (char *)&value, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L40;
L20:
	if (net[iel * 5 + 1] == 0) {
	    goto L30;
	}
	io___35.ciunit = *iout;
	s_wsfe(&io___35);
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	e_wsfe();
	io___36.ciunit = *iout;
	s_wsfe(&io___36);
	for (j = 1; j <= 6; ++j) {
	    do_fio(&c__1, (char *)&line[j - 1], (ftnlen)sizeof(integer));
	}
	do_fio(&c__1, (char *)&value, (ftnlen)sizeof(doublereal));
	e_wsfe();
	*ind = 2;
	goto L40;
L30:
	net[iel * 5 + 1] = line[0];
	net[iel * 5 + 2] = line[3];
	net[iel * 5 + 3] = line[4];
	net[iel * 5 + 4] = line[5];
	val[iel] = value;
	ielm = max(ielm,iel);
	++(*nels);
	io___37.ciunit = *iout;
	s_wsfe(&io___37);
	do_fio(&c__1, (char *)&line[0], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&line[1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&iel, (ftnlen)sizeof(integer));
	for (j = 2; j <= 4; ++j) {
	    do_fio(&c__1, (char *)&net[j + iel * 5], (ftnlen)sizeof(integer));
	}
	do_fio(&c__1, (char *)&val[iel], (ftnlen)sizeof(doublereal));
	e_wsfe();
L40:
	;
    }
    io___39.ciunit = iou;
    s_wsfe(&io___39);
    e_wsfe();
    *ind = 10;
L50:
    *nels = ielm;
    return 0;
} /* bloind_ */

#undef word
#undef line
#undef end


integer ncodb1_(name, key)
integer *name, *key;
{
    /* Initialized data */

    static struct {
	char e_1[32];
	integer e_2;
	} equiv_44 = { {'S', 'U', ' ', ' ', 'F', 'U', ' ', ' ', 'I', 'N', ' ',
		 ' ', 'M', 'U', ' ', ' ', 'D', 'I', ' ', ' ', 'G', 'E', ' ', 
		' ', 'R', 'A', ' ', ' ', 'D', 'E', ' ', ' '}, 0 };

#define ichar ((integer *)&equiv_44)


    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer i, ina;

/*     *************** */
/* PREVOD ZNAKU BLOK. DIAGRAMU NA CISLA A NAOPAK */
/*     3.9.1981 */
/* PRIRAZENI CISEL ZNAKUM */
    if (*key != 0) {
	goto L20;
    }
    for (i = 1; i <= 8; ++i) {
	ina = ichar[i - 1];
	if (*name == ina) {
	    goto L10;
	}
/* L5: */
    }
    *key = -1;
    ret_val = *name;
    goto L30;
L10:
    ret_val = i + 100;
    goto L30;
/* PRIRAZENI ZNAKU CISLUM */
L20:
    if (*name < 101 || *name > 108) {
	goto L25;
    }
    *name += -100;
    ret_val = ichar[*name - 1];
    goto L30;
L25:
    *key = -1;
    ret_val = *name;
L30:
    return ret_val;
} /* ncodb1_ */

#undef ichar


/* Subroutine */ int bseci1_(mxsc, nsec, msec, nout, ind, inp, iou)
integer *mxsc, *nsec, *msec, *nout, *ind, *inp, *iou;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_58 = { {' ', ' ', ' ', ' '}, 0 };

#define iend (*(integer *)&equiv_58)


    /* Format strings */
    static char fmt_100[] = "(//7x,\002           ВЫХОДНЫЕ ВЕЛИЧИНЫ:\002/\
/\002 имя  \002,3x,\002номер  ном.бло\002/)";
    static char fmt_110[] = "(a2,2i5)";
    static char fmt_120[] = "(2x,a2,5x,i3,7x,i3)";
    static char fmt_130[] = "(1x,\002ошибка : несравнимость. исправлено на \
:\002)";
    static char fmt_140[] = "(1x,\002ошибка: нет знака окончания\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
    static integer i, i1, m1, ia, ib, ic;

    /* Fortran I/O blocks */
    static cilist io___46 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___50 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___54 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___55 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___56 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___57 = { 0, 0, 0, fmt_140, 0 };


/*     ***************** */

/*     3.9.1981 */
    /* Parameter adjustments */
    --nout;
    --msec;

    /* Function Body */
    io___46.ciunit = *iou;
    s_wsfe(&io___46);
    e_wsfe();
    m1 = *mxsc + 1;
    i__1 = m1;
    for (i1 = 1; i1 <= i__1; ++i1) {
	i = i1;
	io___50.ciunit = *inp;
	s_rsfe(&io___50);
	do_fio(&c__1, (char *)&ia, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ib, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ic, (ftnlen)sizeof(integer));
	e_rsfe();
	if (ia == iend) {
	    goto L20;
	}
	io___54.ciunit = *iou;
	s_wsfe(&io___54);
	do_fio(&c__1, (char *)&ia, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ib, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ic, (ftnlen)sizeof(integer));
	e_wsfe();
	if (ib != i) {
	    io___55.ciunit = *iou;
	    s_wsfe(&io___55);
	    e_wsfe();
	}
	if (ib != i) {
	    io___56.ciunit = *iou;
	    s_wsfe(&io___56);
	    do_fio(&c__1, (char *)&ia, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&ic, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	msec[i] = ic;
	nout[i] = ia;
/* L10: */
    }
    *ind = 10;
    io___57.ciunit = *iou;
    s_wsfe(&io___57);
    e_wsfe();
    return 0;
L20:
    *nsec = i - 1;
    return 0;
} /* bseci1_ */

#undef iend


/* Subroutine */ int block_(nels, net, val, n, newn, ind, iou)
integer *nels, *net;
doublereal *val;
integer *n, *newn, *ind, *iou;
{
    /* Format strings */
    static char fmt_200[] = "(1x,\002ошибка : ошибочный блок\002,\002номе\
р\002,i3)";
    static char fmt_100[] = "(1x,\002ошибка: неизвестный код блока\002,a4\
,\002 номер\002,i3)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer ityp, i, l, i2;
    extern integer ncodb1_();
    static integer key;
    extern /* Subroutine */ int nul_();

    /* Fortran I/O blocks */
    static cilist io___62 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___64 = { 0, 0, 0, fmt_100, 0 };


/*     **************** */

/*     10.9.1981 */
    /* Parameter adjustments */
    --newn;
    --val;
    net -= 6;

    /* Function Body */
    *ind = 0;
    *n = 0;
    nul_(&c__1, nels, &c__1, &newn[1]);
    i__1 = *nels;
    for (i2 = 1; i2 <= i__1; ++i2) {
	i = i2;
	ityp = net[i * 5 + 1];
	if (ityp == 0) {
	    io___62.ciunit = *iou;
	    s_wsfe(&io___62);
	    do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (ityp == 0) {
	    goto L50;
	}

	key = 0;
	net[i * 5 + 1] = ncodb1_(&ityp, &key);
	if (key == 0) {
	    goto L20;
	}
	io___64.ciunit = *iou;
	s_wsfe(&io___64);
	do_fio(&c__1, (char *)&ityp, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	e_wsfe();
	*ind = 1;
	net[i * 5 + 1] = 0;
	goto L50;
L20:
	++(*n);
	if (*n == i) {
	    goto L40;
	}
/* исключение разреженности NET */
	for (l = 1; l <= 5; ++l) {
	    net[l + *n * 5] = net[l + i * 5];
/* L30: */
	}
/* исключение разреженности VAL */
	val[*n] = val[i];
L40:

	newn[i] = *n;
L50:
	;
    }
    return 0;
} /* block_ */

