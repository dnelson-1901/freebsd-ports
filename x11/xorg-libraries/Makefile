PORTNAME=	xorg-libraries
DISTVERSION=	7.7
PORTREVISION=	6
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org libraries meta-port
WWW=		https://www.x.org/

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/fontenc.pc:x11-fonts/libfontenc \
		${LOCALBASE}/libdata/pkgconfig/ice.pc:x11/libICE \
		${LOCALBASE}/libdata/pkgconfig/libfs.pc:x11-fonts/libFS \
		${LOCALBASE}/libdata/pkgconfig/pixman-1.pc:x11/pixman \
		${LOCALBASE}/libdata/pkgconfig/sm.pc:x11/libSM \
		${LOCALBASE}/libdata/pkgconfig/x11.pc:x11/libX11 \
		${LOCALBASE}/libdata/pkgconfig/xau.pc:x11/libXau \
		${LOCALBASE}/libdata/pkgconfig/xaw7.pc:x11-toolkits/libXaw \
		${LOCALBASE}/libdata/pkgconfig/xcomposite.pc:x11/libXcomposite \
		${LOCALBASE}/libdata/pkgconfig/xcursor.pc:x11/libXcursor \
		${LOCALBASE}/libdata/pkgconfig/xdamage.pc:x11/libXdamage \
		${LOCALBASE}/libdata/pkgconfig/xdmcp.pc:x11/libXdmcp \
		${LOCALBASE}/libdata/pkgconfig/xext.pc:x11/libXext \
		${LOCALBASE}/libdata/pkgconfig/xfixes.pc:x11/libXfixes \
		${LOCALBASE}/libdata/pkgconfig/xfont2.pc:x11-fonts/libXfont2 \
		${LOCALBASE}/libdata/pkgconfig/xft.pc:x11-fonts/libXft \
		${LOCALBASE}/libdata/pkgconfig/xi.pc:x11/libXi \
		${LOCALBASE}/libdata/pkgconfig/xinerama.pc:x11/libXinerama \
		${LOCALBASE}/libdata/pkgconfig/xkbfile.pc:x11/libxkbfile \
		${LOCALBASE}/libdata/pkgconfig/xmu.pc:x11-toolkits/libXmu \
		${LOCALBASE}/libdata/pkgconfig/xpm.pc:x11/libXpm \
		${LOCALBASE}/libdata/pkgconfig/xrandr.pc:x11/libXrandr \
		${LOCALBASE}/libdata/pkgconfig/xrender.pc:x11/libXrender \
		${LOCALBASE}/libdata/pkgconfig/xres.pc:x11/libXres \
		${LOCALBASE}/libdata/pkgconfig/xscrnsaver.pc:x11/libXScrnSaver \
		${LOCALBASE}/libdata/pkgconfig/xt.pc:x11-toolkits/libXt \
		${LOCALBASE}/libdata/pkgconfig/xtrans.pc:x11/xtrans \
		${LOCALBASE}/libdata/pkgconfig/xtst.pc:x11/libXtst \
		${LOCALBASE}/libdata/pkgconfig/xv.pc:x11/libXv \
		${LOCALBASE}/libdata/pkgconfig/xvmc.pc:x11/libXvMC \
		${LOCALBASE}/libdata/pkgconfig/xxf86dga.pc:x11/libXxf86dga \
		${LOCALBASE}/libdata/pkgconfig/xxf86vm.pc:x11/libXxf86vm

USES=		metaport

.include <bsd.port.mk>
