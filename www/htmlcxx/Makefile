PORTNAME=	htmlcxx
PORTVERSION=	0.87
CATEGORIES=	www textproc
MASTER_SITES=	SF/htmlcxx/v${PORTVERSION} \
		https://github.com/bonitao/htmlcxx/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML and CSS APIs for C++
WWW=		https://htmlcxx.sourceforge.net/ \
		https://github.com/bonitao/htmlcxx

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LGPL_V2

USES=		bison:alias compiler:c++14-lang iconv libtool localbase:ldflags pathfix

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB}|' ${WRKSRC}/configure

.include <bsd.port.mk>
