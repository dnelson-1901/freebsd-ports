PORTNAME=	instant-meshes
DISTVERSION=	0.0-42
DISTVERSIONSUFFIX=	-g4a083f4
PORTREVISION=	15
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive field-aligned mesh generator
WWW=		https://igl.ethz.ch/projects/instant-meshes/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libglfw.so:graphics/glfw
RUN_DEPENDS=	zenity:x11/zenity

USES=		cmake compiler:c++14-lang eigen:3 gl localbase:ldflags \
		magick:6,build pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	wjakob
GH_TUPLE=	wjakob:nanogui:2a61f03:nanogui/ext/nanogui \
		wjakob:nanovg:ac15b84:nanovg/ext/nanogui/ext/nanovg \
		wjakob:dset:7967ef0:dset/ext/dset \
		wjakob:tbb:141b0e3:tbb/ext/tbb \
		wjakob:pcg32:0ef13e6:pcg32/ext/pcg32 \
		wjakob:pss:a91da33:pss/ext/pss  # x11-toolkits/nanogui should be a port dependency, but current versions aren't compatible
USE_GL=		gl
USE_XORG=	x11 xcursor xi xinerama xrandr xxf86vm
CMAKE_ON=	NANOGUI_BUILD_PYTHON

post-build:
	@convert -verbose -resize 500x500 -gravity center -background none -extent 512x512 \
		${WRKSRC}/resources/icon.png ${WRKDIR}/icon_512x512.png
.for size in 128x128 192x192 256x256
	@convert -verbose -resize ${size} ${WRKDIR}/icon_512x512.png ${WRKDIR}/icon_${size}.png
.endfor
.for size in 16x16 24x24 32x32 48x48 64x64 96x96
	@convert -verbose -resize ${size} ${WRKDIR}/icon_512x512.png -unsharp 0x6 ${WRKDIR}/icon_${size}.png
.endfor

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/include ${STAGEDIR}${PREFIX}/lib
.for size in 16x16 24x24 32x32 48x48 64x64 96x96 128x128 192x192 256x256 512x512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps
	${INSTALL_DATA} ${WRKDIR}/icon_${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps/${PORTNAME}.png
.endfor
	${INSTALL_PROGRAM} ${CONFIGURE_WRKSRC}/"Instant Meshes" ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
