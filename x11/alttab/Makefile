PORTNAME=	alttab
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Task switcher for minimalistic window managers
WWW=		https://github.com/sagb/alttab

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash
LIB_DEPENDS=	libpng.so:graphics/png

USES=		localbase pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	sagb
USE_XORG=	x11 xft xpm xrandr xrender
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/alttab \
		share/man/man1/alttab.1.gz

PORTDOCS=	README \
		alttab.ad \
		wm-setup.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
