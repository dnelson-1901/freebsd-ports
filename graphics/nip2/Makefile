PORTNAME=	nip2
PORTVERSION=	8.7.1
PORTREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/libvips/${PORTNAME}/releases/download/v${PORTVERSION}/

PATCH_SITES=	https://github.com/libvips/${PORTNAME}/commit/
PATCHFILES+=	8bdb1459bc2.patch:-p1 # https://github.com/libvips/nip2/pull/96

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical user interface for VIPS
WWW=		https://github.com/jcupitt/nip2

LICENSE=	GPLv2

BUILD_DEPENDS=	xdg-open:devel/xdg-utils
LIB_DEPENDS=	libvips.so:graphics/vips \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		bison cpe desktop-file-utils dos2unix gettext gmake gnome pkgconfig \
		shared-mime-info
CPE_VENDOR=	${PORTNAME}_project

DOS2UNIX_GLOB=	*.def
USE_GNOME=	cairo gdkpixbuf gtk20 libxml2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=	--disable-update-desktop
LDFLAGS+=	-lm

SUB_FILES=	run-nip2.sh

OPTIONS_DEFINE=		DOCS FFTW GRAPHVIZ GSF GSL
OPTIONS_DEFAULT=	FFTW GRAPHVIZ GSF GSL

FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3
FFTW_CONFIGURE_WITH=	fftw3
GRAPHVIZ_DESC=		Use libgvc to show workspace dependency graphs
GRAPHVIZ_LIB_DEPENDS=	libgvc.so:graphics/graphviz
GRAPHVIZ_CONFIGURE_WITH=	libgvc
GSF_DESC=		Use libgsf to save plots to files
GSF_USE=		gnome=libgsf
GSF_CONFIGURE_WITH=	libgsf
GSL_DESC=		Use gsl for numeric functions
GSL_LIB_DEPENDS=	libgsl.so:math/gsl
GSL_CONFIGURE_WITH=	gsl

post-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} run-nip2.sh \
		${STAGEDIR}/${PREFIX}/bin)

test check: build
	#
	# Checks currently require ImageMagick's convert to be available
	# and aren't enabled by default. They take a long time -- tail
	# the log-file:
	#	${WRKSRC}/test/test_all.sh.log
	#
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check)

.include <bsd.port.mk>
