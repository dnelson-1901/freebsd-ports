PORTNAME=	slepc4py
DISTVERSION=	3.22.2
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SLEPc for Python
WWW=		https://bitbucket.org/slepc/slepc4py

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}petsc4py>0:math/py-petsc4py@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
LIB_DEPENDS=	libmpich.so:net/mpich \
		libpetsc.so:science/PETSc \
		libslepc.so:math/slepc
RUN_DEPENDS=	${PYNUMPY}

USES=		fortran python
USE_PYTHON=	autoplist cython3 distutils pytest

MAKE_ENV=	PETSC_DIR=${LOCALBASE} SLEPC_DIR=${LOCALBASE}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/slepc4py/lib/SLEPc${PYTHON_TAG}.so

.include <bsd.port.mk>
