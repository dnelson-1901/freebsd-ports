PORTNAME=	l2tpd
PORTVERSION=	0.69
PORTREVISION=	12
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/L2TPd/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of the layer two tunneling protocol

BROKEN_armv6=	fails to link: undefined reference to check_control
BROKEN_armv7=	fails to link: undefined reference to check_control

USES=		compiler:nestedfct cpe
CFLAGS+=	-fcommon \
		-fpermissive

PORTDOCS=	README
ETCDIR=		${PREFIX}/etc/l2tp

OPTIONS_DEFINE=	DOCS

do-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/doc/l2tpd.8 \
		${WRKSRC}/doc/l2tpd.conf.sample ${WRKSRC}/doc/l2tp-secrets.5 \
		${WRKSRC}/doc/l2tpd.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/l2tpd ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/l2tpd.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/l2tp-secrets.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/l2tpd.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/l2tpd.conf.sample ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/l2tp-secrets.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
