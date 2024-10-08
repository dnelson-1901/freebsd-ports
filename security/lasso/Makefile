PORTNAME=	lasso
PORTVERSION=	2.8.2
CATEGORIES=	security
MASTER_SITES=	https://dev.entrouvert.org/releases/lasso/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Free Liberty Alliance Implementation
WWW=		https://lasso.entrouvert.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libxmlsec1-openssl.so:security/xmlsec1
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cpe gmake gnome libtool pathfix pkgconfig python ssl
CPE_VENDOR=	entrouvert
USE_GNOME=	glib20 libxml2 libxslt
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-java \
		--disable-php5 \
		--with-zlib

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS PERL PYTHON
OPTIONS_SUB=	yes

PERL_USES=			perl5
PERL_CONFIGURE_ENABLE=		perl
PYTHON_CONFIGURE_ENABLE=	python

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,(xmlsec1-openssl >= 1\.2\.6) openssl,\1,' \
		${CONFIGURE_WRKSRC}/configure
# Fix build with new xmlsec1 as this function was deprecated
	@${REINPLACE_CMD} -e 's|BAD_CAST XMLSEC_CRYPTO|BAD_CAST xmlSecGetDefaultCrypto()|g' \
		${WRKSRC}/lasso/lasso.c

.include <bsd.port.mk>
