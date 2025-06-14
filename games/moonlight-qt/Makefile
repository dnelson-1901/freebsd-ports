PORTNAME=	moonlight
DISTVERSION=	6.1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://github.com/moonlight-stream/moonlight-qt/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-qt
DISTNAME=	MoonlightSrc-${DISTVERSIONFULL}

MAINTAINER=	lisp_25689@163.com
COMMENT=	Gamestream client
WWW=		https://github.com/moonlight-stream/moonlight-qt

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libopus.so:audio/opus \
		libva.so:multimedia/libva \
		libdrm.so:graphics/libdrm \
		libvdpau.so:multimedia/libvdpau \
		libplacebo.so:graphics/libplacebo \
		libwayland-client.so:graphics/wayland

USES=		desktop-file-utils gl localbase:ldflags pkgconfig \
		qmake:outsource sdl ssl xorg
USE_GL=		egl
USE_SDL=	sdl2 ttf2
USE_XORG=	x11

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/moonlight-qt \
		share/applications/com.moonlight_stream.Moonlight.desktop \
		share/metainfo/com.moonlight_stream.Moonlight.appdata.xml \
		share/icons/hicolor/scalable/apps/moonlight.svg \

OPTIONS_DEFAULT=	QT6
QT5_DESC=	QT 5 toolkit support
QT6_DESC=	QT 6 toolkit support
OPTIONS_SINGLE=	QT
OPTIONS_SINGLE_QT=	QT6 QT5
QT5_USES=	qt:5
QT5_USE=	qt=core,declarative,gui,network,quickcontrols2,svg,widgets,buildtools:build
QT6_USES=	qt:6
QT6_USE=	qt=base,declarative,svg

QT6_PATCH_SITES=	https://github.com/moonlight-stream/moonlight-qt/commit/
# fix errors for qt6.9
QT6_PATCHFILES+=	75359bb1c483ba9e52bba8c34a662d807e0cc3c4.patch:-p1 \
			7a769172a1f62e5198584dff9fd924e8a9e431a0.patch:-p1

post-patch:
	@${REINPLACE_CMD} -e 's@Exec=moonlight.*@Exec=${PORTNAME}${PKGNAMESUFFIX}@' \
		${WRKSRC}/app/deploy/linux/com.moonlight_stream.Moonlight.desktop
	@${REINPLACE_CMD} -e 's@^    TARGET = moonlight.*@    TARGET = ${PORTNAME}${PKGNAMESUFFIX}@' \
		${WRKSRC}/app/app.pro

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.mk>
