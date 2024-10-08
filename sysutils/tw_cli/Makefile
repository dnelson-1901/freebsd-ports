PORTNAME=	tw_cli
DISTVERSION=	9.5.5
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://docs.broadcom.com/docs-and-downloads/raid-controllers/raid-controllers-common-files/
DISTNAME=	CLI_freebsd-from_the_10-2-2-1_9-5-5-1_codesets
DIST_SUBDIR=	3dm2

MAINTAINER=	takefu@airport.fm
COMMENT=	3ware storage controllers management CLI
WWW=		https://www.broadcom.com/support/

LICENSE=	tw_cli
LICENSE_NAME=	BROADCOM
LICENSE_TEXT=	Source recipient must acknowledge license.\
		Reproduction or redistribution prohibited.\
		See https://docs.broadcom.com/docs/12348586
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	binaries only available for i386 and amd64
USES=		zip
NO_BUILD=	yes
SUB_FILES=	407.status-3ware-raid
NO_WRKSUBDIR=	yes
PLIST_FILES=	etc/periodic/daily/407.status-3ware-raid\
		share/man/man8/tw_cli.8.gz sbin/tw_cli
PORTDOCS=	tw_cli.8.html
OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
DOWNLOAD_URL=	${MASTER_SITES}${DISTNAME}${EXTRACT_SUFX}
IGNORE?=	You must manually fetch the distribution file\
		(${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL},\
		place it in ${DISTDIR}/3dm2 and then run make again
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${ARCH:S,i386,x86,:S,amd64,x86_64,}/tw_cli\
		${STAGEDIR}${PREFIX}/sbin/tw_cli
	${INSTALL_MAN} ${WRKSRC}/tw_cli.8.nroff\
		${STAGEDIR}${PREFIX}/share/man/man8/tw_cli.8
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/407.status-3ware-raid \
		${STAGEDIR}${PREFIX}/etc/periodic/daily/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
