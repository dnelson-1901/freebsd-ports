PORTNAME=	prboom-plus
PORTVERSION=	2.5.1.3
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	thiagohero501@gmail.com
COMMENT=	Fork of the prboom Doom game engine
WWW=		http://prboom-plus.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsmpeg.so:multimedia/smpeg \
		libpng.so:graphics/png \
		libmad.so:audio/libmad \
		libfluidsynth.so:audio/fluidsynth \
		libvorbisfile.so:audio/libvorbis

USES=		gmake localbase sdl
USE_GL=		gl
USE_SDL=	image mixer net sdl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-waddir=${DATADIR}

DATADIR=	${DMDIR}

OPTIONS_DEFINE=	DOCS OPENGL
OPTIONS_DEFAULT=OPENGL

OPENGL_USES=	gl
OPENGL_USE=	GL=glu
OPENGL_CONFIGURE_ENABLE=	gl

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e '/^gamesdir/s|/games|/bin|' \
		-e '/^docdir/s/@PACKAGE@-@VERSION@/@PACKAGE@/'

.include "${.CURDIR}/Makefile.include"

.include <bsd.port.mk>
