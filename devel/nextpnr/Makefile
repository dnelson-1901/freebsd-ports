PORTNAME=	nextpnr
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.7
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/YosysHQ/nextpnr/commit/
PATCHFILES=	f085950383155a745cf2e3c0f28c468d01ff5fd7.patch:-p1

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	Portable FPGA place and route tool
WWW=		https://github.com/YosysHQ/nextpnr

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	clang segfault

BUILD_DEPENDS=	${LOCALBASE}/share/trellis/database:devel/trellis \
		${LOCALBASE}/share/icebox:devel/icestorm
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		${PY_BOOST}

USES=		compiler:c++17-lang cmake qt:5 eigen:3 python gl
USE_QT=		buildtools:build core gui opengl qmake:build widgets
USE_GL=		gl glu
USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ
GH_TUPLE=	YosysHQ:nextpnr-tests:00c55a9e:tests/tests

BINARY_ALIAS=	python3=${PYTHON_CMD}

CMAKE_ARGS=	-DARCH="ice40;ecp5" -DTRELLIS_ROOT=${LOCALBASE}/share/trellis/
CMAKE_ON=	BUILD_GUI

PLIST_FILES=	bin/nextpnr-ecp5 \
		bin/nextpnr-ice40

# Don't create __pycache__ directory when executing blueprint-compiler
# This is a workaround to avoid filesystem violations during poudriere build
MAKE_ENV=	PYTHONDONTWRITEBYTECODE=1

.include <bsd.port.mk>
