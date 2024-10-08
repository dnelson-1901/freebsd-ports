PORTNAME=	spooles
PORTVERSION=	2.2
PORTREVISION=	16
CATEGORIES=	math
MASTER_SITES=	NETLIB/linalg/spooles
.ifdef WITH_MPI
PKGNAMESUFFIX=	-mpich
.endif
DISTNAME=	${PORTNAME}.${PORTVERSION}
DIST_SUBDIR=	spooles
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SParse Object Oriented Linear Equations Solver
WWW=		https://www.netlib.org/linalg/spooles/spooles.2.2.html

LICENSE=	PD

.if defined(WITH_MPI)
LIB_DEPENDS=	libmpich.so:net/mpich
.endif

USES=		gmake tar:tgz

.if defined(WITH_MPI)
CONFLICTS=	spooles-2*
PLIST_SUB=	MPI="" MT="@comment "
.else
CONFLICTS=	spooles-mpich-2*
PLIST_SUB=	MPI="@comment " MT=""
.endif

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} AllInOne.ps.gz Eigen.ps.gz \
		Install.ps.gz LinSol.ps.gz Ordering.ps.gz \
		PP99.ps.gz ReferenceManual.ps.gz

PICFLAG?=	-fpic

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.SILENT:

pre-everything::
.if !defined(WITH_MPI)
	${ECHO_MSG} "make WITH_MPI=yes for mpich version"
.endif

do-extract:
	${MKDIR} ${WRKSRC} ; cd ${WRKSRC} ; ${TAR} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}

post-patch:
	${MKDIR} ${WRKSRC}_SHARED ; ${CP} -r ${WRKSRC}/* ${WRKSRC}_SHARED
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' \
		-e 's+%%CFLAGS%%+${CFLAGS}+g;' \
		-e 's+%%CC%%+${CC}+g;' ${WRKSRC}/Make.inc
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' \
		-e 's+%%CFLAGS%%+${CFLAGS} ${PICFLAG}+g;' \
		-e 's+%%CC%%+${CC}+g;' ${WRKSRC}_SHARED/Make.inc

do-build:
.if defined(WITH_MPI)
	@(cd ${WRKSRC}/MPI/src ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f makeGlobalLib)
	@(cd ${WRKSRC}_SHARED/MPI/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f makeGlobalLib)
	@(cd ${WRKSRC}_SHARED ; ld -Bshareable -o libspooles.so.1 -x -soname libspooles.so.1 --whole-archive spooles.a )

.else
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} global -f makefile)
	@(cd ${WRKSRC}/MT/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f makeGlobalLib)
	@(cd ${WRKSRC}_SHARED; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} global -f makefile)
	@(cd ${WRKSRC}_SHARED/MT/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f makeGlobalLib)
	@(cd ${WRKSRC}_SHARED ; ld -Bshareable -o libspooles.so.1 -x -soname libspooles.so.1 --whole-archive spooles.a )
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/spooles
	${INSTALL_DATA} ${WRKSRC}/spooles.a ${STAGEDIR}${PREFIX}/lib/libspooles.a
	${INSTALL_DATA} ${WRKSRC}_SHARED/libspooles.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libspooles.so.1 ${STAGEDIR}${PREFIX}/lib/libspooles.so

.if defined(WITH_MPI)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/spooles/MPI
	${INSTALL_DATA} ${WRKSRC}/MPI/*.h ${STAGEDIR}${PREFIX}/include/spooles/MPI
.else
	${MKDIR} ${STAGEDIR}${PREFIX}/include/spooles/MT
	${INSTALL_DATA} ${WRKSRC}/MT/*.h ${STAGEDIR}${PREFIX}/include/spooles/MT
.endif
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/spooles/
.for i in A2 BPG Chv ChvList ChvManager Coords DenseMtx DSTree Drand \
	DV ETree FrontMtx GPart Graph I2Ohash IIheap IV IVL Ideq InpMtx \
	Lock MSMD PatchAndGoInfo Pencil SolveMap SubMtx SubMtxList SubMtxManager \
	SymbFac Tree Utilities ZV misc
	${MKDIR} ${STAGEDIR}${PREFIX}/include/spooles/${i}
	${INSTALL_DATA} ${WRKSRC}/${i}/*.h ${STAGEDIR}${PREFIX}/include/spooles/${i}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/AllInOne.ps.gz	${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Eigen.ps.gz		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Install.ps.gz		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/LinSol.ps.gz		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Ordering.ps.gz	${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/PP99.ps.gz		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/ReferenceManual.ps.gz	${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
