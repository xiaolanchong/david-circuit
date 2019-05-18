/* tr7.f -- translated by f2c (version of 23 April 1993  18:34:30).
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

/* Subroutine */ int forbd1_()
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    double pow_ri(), pow_dd();

    /* Local variables */
    static doublereal fder, save;
    static integer ityp;
    static real time;
    static integer ityp1;
    static doublereal f0;
    static integer n0, n1, n2;
    extern /* Subroutine */ int fvald1_();
    static doublereal ra, va;
    static integer ni;
    static doublereal ti, xf[2], xi, fu0;
    static integer ire, noi[2], nst, noi1, noi2;

/*     ***************** */
/* îééêåàêéÇÄçàÖ ¨†‚‡®Ê A0 i B0 */

/*     23.3.89 */





/*     /NW,WK,WR(20),WI(20),COEFD(20), */
/*     /NZ,ZK,ZR(20),ZI(20),COEFN(20), */

    i__1 = _BLNK__1.nels;
    for (_BLNK__1.i = 1; _BLNK__1.i <= i__1; ++_BLNK__1.i) {
	ityp = _BLNK__1.net[_BLNK__1.i * 5 - 5];
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
	_BLNK__1.a0[_BLNK__1.i + _BLNK__1.i * 20 - 21] = 1.;
	_BLNK__1.b0[_BLNK__1.i - 1] = -_BLNK__1.x[_BLNK__1.i - 1];
	va = _BLNK__1.val[_BLNK__1.i - 1];
	for (_BLNK__1.j = 2; _BLNK__1.j <= 4; ++_BLNK__1.j) {
	    if (_BLNK__1.j >= 3) {
		va = 1.;
	    }
	    if ((i__2 = _BLNK__1.net[_BLNK__1.j + _BLNK__1.i * 5 - 6]) < 0) {
		goto L11;
	    } else if (i__2 == 0) {
		goto L14;
	    } else {
		goto L13;
	    }
L11:
	    ni = -_BLNK__1.net[_BLNK__1.j + _BLNK__1.i * 5 - 6];
	    _BLNK__1.a0[_BLNK__1.i + ni * 20 - 21] = va;
	    _BLNK__1.b0[_BLNK__1.i - 1] -= _BLNK__1.x[ni - 1] * va;
	    goto L14;
L13:
	    ni = _BLNK__1.net[_BLNK__1.j + _BLNK__1.i * 5 - 6];
	    _BLNK__1.a0[_BLNK__1.i + ni * 20 - 21] = -va;
	    _BLNK__1.b0[_BLNK__1.i - 1] += _BLNK__1.x[ni - 1] * va;
L14:
	    ;
	}
	goto L99;
/* NACTENI NELINEARNICH FUNKCI DO MATICE A0 A B0 */
L20:
	_BLNK__1.a0[_BLNK__1.i + _BLNK__1.i * 20 - 21] = 1.;
	_BLNK__1.b0[_BLNK__1.i - 1] = -_BLNK__1.x[_BLNK__1.i - 1];
	for (_BLNK__1.j = 2; _BLNK__1.j <= 3; ++_BLNK__1.j) {
	    _BLNK__1.k = _BLNK__1.j - 1;
	    if ((i__2 = _BLNK__1.net[_BLNK__1.j + _BLNK__1.i * 5 - 6]) < 0) {
		goto L21;
	    } else if (i__2 == 0) {
		goto L25;
	    } else {
		goto L23;
	    }
L21:
	    noi[_BLNK__1.k - 1] = -_BLNK__1.net[_BLNK__1.j + _BLNK__1.i * 5 - 
		    6];
	    n0 = noi[_BLNK__1.k - 1];
	    xf[_BLNK__1.k - 1] = -_BLNK__1.x[n0 - 1];
	    goto L24;
L25:
	    xf[1] = (float)0.;
	    noi[1] = 0;
	    goto L24;
L23:
	    noi[_BLNK__1.k - 1] = _BLNK__1.net[_BLNK__1.j + _BLNK__1.i * 5 - 
		    6];
	    n1 = noi[_BLNK__1.k - 1];
	    xf[_BLNK__1.k - 1] = _BLNK__1.x[n1 - 1];
L24:
	    ;
	}
	xi = xf[0] * _BLNK__1.val[_BLNK__1.i - 1] + xf[1];
	fvald1_(&_BLNK__1.nfun, &_BLNK__1.npar, _BLNK__1.iadr, _BLNK__1.parf, 
		&_BLNK__1.net[_BLNK__1.i * 5 - 2], &xi, &fu0, &fder);
	noi1 = noi[0];
	_BLNK__1.a0[_BLNK__1.i + noi1 * 20 - 21] = -fder * _BLNK__1.val[
		_BLNK__1.i - 1];
	noi2 = noi[1];
	if (noi[1] == 0) {
	    goto L27;
	}
	_BLNK__1.a0[_BLNK__1.i + noi2 * 20 - 21] = -fder;
L27:
	_BLNK__1.b0[_BLNK__1.i - 1] += fu0;
	goto L99;
/* NACTENI INTEGRATORU DO MATIC A0 A B0 */
L30:
	if (nst <= 1 && ire == 1) {
	    goto L90;
	}
	_BLNK__1.a0[_BLNK__1.i + _BLNK__1.i * 20 - 21] = _BLNK__1.gama;
	_BLNK__1.b0[_BLNK__1.i - 1] = -_BLNK__1.xdot[_BLNK__1.i - 1];
	va = _BLNK__1.val[_BLNK__1.i - 1];
	for (_BLNK__1.j = 2; _BLNK__1.j <= 4; ++_BLNK__1.j) {
	    if (_BLNK__1.j >= 3) {
		va = 1.;
	    }
	    if ((i__2 = _BLNK__1.net[_BLNK__1.j + _BLNK__1.i * 5 - 6]) < 0) {
		goto L33;
	    } else if (i__2 == 0) {
		goto L36;
	    } else {
		goto L35;
	    }
L33:
	    ni = -_BLNK__1.net[_BLNK__1.j + _BLNK__1.i * 5 - 6];
	    _BLNK__1.a0[_BLNK__1.i + ni * 20 - 21] = va;
	    _BLNK__1.b0[_BLNK__1.i - 1] -= _BLNK__1.x[ni - 1] * va;
	    goto L36;
L35:
	    ni = _BLNK__1.net[_BLNK__1.j + _BLNK__1.i * 5 - 6];
	    _BLNK__1.a0[_BLNK__1.i + ni * 20 - 21] = -va;
	    _BLNK__1.b0[_BLNK__1.i - 1] += _BLNK__1.x[ni - 1] * va;
L36:
	    ;
	}
	goto L99;
/* NACTENI NASOBICKY DO MATIC A0 A B0 */
L40:
	n1 = (i__2 = _BLNK__1.net[_BLNK__1.i * 5 - 4], abs(i__2));
	n2 = (i__2 = _BLNK__1.net[_BLNK__1.i * 5 - 3], abs(i__2));
	_BLNK__1.a0[_BLNK__1.i + _BLNK__1.i * 20 - 21] = 1.;
	_BLNK__1.b0[_BLNK__1.i - 1] = -_BLNK__1.x[_BLNK__1.i - 1];
	if ((i__2 = _BLNK__1.net[_BLNK__1.i * 5 - 4] * _BLNK__1.net[
		_BLNK__1.i * 5 - 3]) < 0) {
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
	_BLNK__1.a0[_BLNK__1.i + n1 * 20 - 21] = ra * _BLNK__1.val[_BLNK__1.i 
		- 1] * _BLNK__1.x[n2 - 1];
	_BLNK__1.a0[_BLNK__1.i + n2 * 20 - 21] = ra * _BLNK__1.val[_BLNK__1.i 
		- 1] * _BLNK__1.x[n1 - 1];
	_BLNK__1.b0[_BLNK__1.i - 1] -= _BLNK__1.x[n1 - 1] * _BLNK__1.x[n2 - 1]
		 * _BLNK__1.val[_BLNK__1.i - 1] * ra;
	goto L99;
/* NACTENI DELICKY DO MATIC A0 A B0 */
L50:
	_BLNK__1.a0[_BLNK__1.i + _BLNK__1.i * 20 - 21] = 1.;
	_BLNK__1.b0[_BLNK__1.i - 1] = -_BLNK__1.x[_BLNK__1.i - 1];
	n1 = (i__2 = _BLNK__1.net[_BLNK__1.i * 5 - 4], abs(i__2));
	n2 = (i__2 = _BLNK__1.net[_BLNK__1.i * 5 - 3], abs(i__2));
	if ((i__2 = _BLNK__1.net[_BLNK__1.i * 5 - 4] * _BLNK__1.net[
		_BLNK__1.i * 5 - 3]) < 0) {
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
	save = _BLNK__1.x[n2 - 1];
	if (abs(save) < 1e-20) {
	    save = 1.;
	}
	_BLNK__1.a0[_BLNK__1.i + n1 * 20 - 21] = ra * _BLNK__1.val[_BLNK__1.i 
		- 1] / save;
	_BLNK__1.a0[_BLNK__1.i + n2 * 20 - 21] = ra * (-_BLNK__1.val[
		_BLNK__1.i - 1]) * _BLNK__1.x[n1 - 1] / (save * save);
	_BLNK__1.b0[_BLNK__1.i - 1] -= _BLNK__1.val[_BLNK__1.i - 1] * ra * 
		_BLNK__1.x[n1 - 1] / save;
	goto L99;
/* NACTENI ZDROJE "GENE" */
L60:
	_BLNK__1.a0[_BLNK__1.i + _BLNK__1.i * 20 - 21] = 1.;
	ti = _BLNK__1.val[_BLNK__1.i - 1] * time;
	fvald1_(&_BLNK__1.nfun, &_BLNK__1.npar, _BLNK__1.iadr, _BLNK__1.parf, 
		&_BLNK__1.net[_BLNK__1.i * 5 - 2], &ti, &f0, _BLNK__1.f1);
	_BLNK__1.b0[_BLNK__1.i - 1] = f0 - _BLNK__1.x[_BLNK__1.i - 1];
	goto L99;
/* NACTENI ZDROJE "RAMP" */
L70:
	_BLNK__1.a0[_BLNK__1.i + _BLNK__1.i * 20 - 21] = 1.;
	if (dabs(time) <= 1e-20 && _BLNK__1.net[_BLNK__1.i * 5 - 2] < 0) {
	    _BLNK__1.b0[_BLNK__1.i - 1] = _BLNK__1.val[_BLNK__1.i - 1] - 
		    _BLNK__1.x[_BLNK__1.i - 1];
	}
	if (_BLNK__1.net[_BLNK__1.i * 5 - 2] == 0) {
	    _BLNK__1.b0[_BLNK__1.i - 1] = _BLNK__1.val[_BLNK__1.i - 1] - 
		    _BLNK__1.x[_BLNK__1.i - 1];
	}
	if (_BLNK__1.net[_BLNK__1.i * 5 - 2] < 10 && dabs(time) > 1e-20 && 
		_BLNK__1.net[_BLNK__1.i * 5 - 2] != 0) {
	    _BLNK__1.b0[_BLNK__1.i - 1] = _BLNK__1.val[_BLNK__1.i - 1] * 
		    pow_ri(&time, &_BLNK__1.net[_BLNK__1.i * 5 - 2]) - 
		    _BLNK__1.x[_BLNK__1.i - 1];
	}
	if (_BLNK__1.net[_BLNK__1.i * 5 - 2] >= 10) {
	    d__1 = (doublereal) time;
	    d__2 = (doublereal) _BLNK__1.net[_BLNK__1.i * 5 - 2] / 1e3;
	    _BLNK__1.b0[_BLNK__1.i - 1] = _BLNK__1.val[_BLNK__1.i - 1] * 
		    pow_dd(&d__1, &d__2) - _BLNK__1.x[_BLNK__1.i - 1];
	}
	goto L99;
/* NACTENI DERIVATORU DO MATIC A0 A B0 */
L80:
	_BLNK__1.a0[_BLNK__1.i + _BLNK__1.i * 20 - 21] = 1.;
	_BLNK__1.b0[_BLNK__1.i - 1] = -_BLNK__1.x[_BLNK__1.i - 1];
	va = _BLNK__1.val[_BLNK__1.i - 1];
	for (_BLNK__1.j = 2; _BLNK__1.j <= 4; ++_BLNK__1.j) {
	    if (_BLNK__1.j >= 3) {
		va = 1.;
	    }
	    if ((i__2 = _BLNK__1.net[_BLNK__1.j + _BLNK__1.i * 5 - 6]) < 0) {
		goto L83;
	    } else if (i__2 == 0) {
		goto L86;
	    } else {
		goto L85;
	    }
L83:
	    ni = -_BLNK__1.net[_BLNK__1.j + _BLNK__1.i * 5 - 6];
	    _BLNK__1.a0[_BLNK__1.i + ni * 20 - 21] = va * _BLNK__1.gama;
	    _BLNK__1.b0[_BLNK__1.i - 1] -= _BLNK__1.xdot[ni - 1] * va;
	    goto L86;
L85:
	    ni = _BLNK__1.net[_BLNK__1.j + _BLNK__1.i * 5 - 6];
	    _BLNK__1.a0[_BLNK__1.i + ni * 20 - 21] = -va * _BLNK__1.gama;
	    _BLNK__1.b0[_BLNK__1.i - 1] += _BLNK__1.xdot[ni - 1] * va;
L86:
	    ;
	}
	goto L99;
L90:
	_BLNK__1.a0[_BLNK__1.i + _BLNK__1.i * 20 - 21] = 1.;
L99:
	;
    }
L200:
    return 0;
} /* forbd1_ */

/* Subroutine */ int bsecd_(nsec, msec, n, newn, x, xout)
integer *nsec, *msec, *n, *newn;
doublereal *x, *xout;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i, ix;

/*     **************** */
/* COMPUTATION OF OUTPUT VALUES XOUT FROM SOLUTION VECTOR X */
/*     2.11.1981 */
    /* Parameter adjustments */
    --xout;
    --x;
    --newn;
    --msec;

    /* Function Body */
    i__1 = *nsec;
    for (i = 1; i <= i__1; ++i) {
	ix = msec[i];
	ix = newn[ix];
	xout[i] = x[ix];
/* L50: */
    }
    return 0;
} /* bsecd_ */

/* Subroutine */ int fvald1_(nf, npar, iadr, parf, num, x, y, dy)
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
} /* fvald1_ */

