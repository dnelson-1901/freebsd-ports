PORTNAME=	xmlenc
PORTVERSION=	0.52
PORTREVISION=	3
CATEGORIES=	textproc java
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light-weight XML encoding library for Java
WWW=		https://xmlenc.sourceforge.net/

USES=		java:ant,run tar:tgz
JAVA_VERSION=	8

DEPRECATED=	Outdated and obsolete, last release in 2005
EXPIRATION_DATE=2025-07-31

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

ALL_TARGET=	jar
DOCS_ALL_TARGET=javadoc
PORTDOCS=	*
JARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}

.include <bsd.port.pre.mk>

JDK_API!=	(${FIND} -s ${LOCALBASE}/share/doc/jdk1.? -maxdepth 1 -name api -type d 2>/dev/null || ${ECHO_CMD}) | ${TAIL} -n 1
.if ${JDK_API} != ""
MAKE_ARGS+=	-Djavadoc.srcdir.j2se=${JDK_API}

do-configure:
	${REINPLACE_CMD} -e 's,http://java.sun.com/j2se/1.3/docs/api,${JDK_API},' ${WRKSRC}/build.xml
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/build/${JARFILE} ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"

do-install-DOCS-on:
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/build/javadoc/ \
	  && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.post.mk>
