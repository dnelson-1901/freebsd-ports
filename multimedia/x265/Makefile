PORTNAME=	x265
PORTVERSION=	3.6
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265_git/downloads/ \
		http://ftp.videolan.org/pub/videolan/x265/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@virtual-estates.net
COMMENT=	H.265/High Efficiency Video Coding (HEVC) format
WWW=		https://www.x265.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC:H}/COPYING

USES=		cmake compiler:c++14-lang cpe pathfix dos2unix
CPE_VENDOR=	multicorewareinc
DOS2UNIX_FILES=	common/scaler.cpp
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DENABLE_TESTS=on -DGIT_ARCHETYPE=1
CMAKE_ON=	ENABLE_HDR10_PLUS
LDFLAGS_i386=	-Wl,-znotext
EXTRACT_AFTER_ARGS+=	--exclude compat --exclude md5\.* --strip-components=1
PATCH_WRKSRC=	${WRKSRC:H}
WRKSRC=		${WRKDIR}/source
BB_TAG=		Release_${DISTVERSION}

OPTIONS_DEFINE=			VMAF
OPTIONS_DEFINE_amd64=		SVTHEVC
OPTIONS_DEFAULT=		HI10P HI12P HI8P OPTIMIZED_FLAGS

OPTIONS_MULTI=			PIXELWIDTH
OPTIONS_MULTI_PIXELWIDTH=	HI10P HI12P HI8P
OPTIONS_RADIO=			OPTIMIZATION
OPTIONS_RADIO_OPTIMIZATION=	DEBUG OPTIMIZED_FLAGS

DEBUG_DESC=		Enable debugging (and -O0 -g)
HI10P_DESC=		Enable 10-bit pixels (may break on i386)
HI12P_DESC=		Enable 12-bit pixels (may break on i386)
HI8P_DESC=		Enable 8-bit pixel-width (you, probably, want this)
OPTIMIZED_FLAGS_DESC=	Enable O3 optimization
SVTHEVC_DESC=		HEVC encoding via SVT-HEVC
VMAF_DESC=		VMAF scores (broken: needs older VMAF)
VMAF_USES=		localbase:ldflags

DEBUG_CMAKE_ON=		-DCMAKE_ASM_NASM_FLAGS:STRING="-g -O0"
SVTHEVC_LIB_DEPENDS=	libSvtHevcEnc.so:multimedia/svt-hevc
SVTHEVC_CMAKE_ON=	-DSVT_HEVC_INCLUDE_DIR:PATH="${LOCALBASE}/include/svt-hevc"
SVTHEVC_CMAKE_BOOL=	ENABLE_SVT_HEVC
VMAF_CMAKE_ON=		-DVMAF_INCLUDE_DIR:PATH="${LOCALBASE}/include/libvmaf"
VMAF_LIB_DEPENDS=	libvmaf.so:multimedia/vmaf
VMAF_CMAKE_BOOL=	ENABLE_LIBVMAF

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64le
CMAKE_ARGS+=	-DCPU_POWER8=ON \
		-DENABLE_ALTIVEC=ON
.endif

.if !${ARCH:Mpowerpc64*} && !${ARCH:Marmv7}
BUILD_DEPENDS=	nasm:devel/nasm
.endif

DEFAULT_DEPTH=	${PORT_OPTIONS:MHI*P:O:ts/:T}
OTHER_DEPTHS=	${PORT_OPTIONS:MHI*P:N${DEFAULT_DEPTH}}

.if "${DEFAULT_DEPTH}" == "HI12P"
CMAKE_ARGS+=	-DMAIN12:BOOL=true
.endif

.if "${DEFAULT_DEPTH}" != "HI8P"
CMAKE_ARGS+=	-DHIGH_BIT_DEPTH:BOOL=true
.endif

CMAKE_OTHER_ARGS=	${CMAKE_ARGS:C/.*-D_END_CUSTOM_OPTIONS=1 +//W}

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS:=	${CFLAGS:N-O*} -O0 -g
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_FLAGS}
CFLAGS:=	${CFLAGS:N-O*} -O3
.endif

.for b in ${OTHER_DEPTHS:C/HI([0-9]+)P/\1/}
EXTRA_LINK_FLAGS+=	-L${WRKSRC:H}/${b}bit

.if ${ARCH} == powerpc64le

.if ${b} != 8
ASSEMBLY=	false
.else
ASSEMBLY=	true
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/x265.h

pre-build::
	@${ECHO_MSG} "---> Building the ${b}-bit library ---"
	${MKDIR} ${WRKSRC:H}/${b}bit
	${CMAKE_BIN} -S ${WRKSRC} -B ${WRKSRC:H}/${b}bit \
		${CMAKE_OTHER_ARGS} ${b:C/1./-DHIGH_BIT_DEPTH:BOOL=true/} \
		-DMAIN${b}:BOOL=true -DENABLE_ALTIVEC=${ASSEMBLY} -DCPU_POWER8=true \
		-DEXPORT_C_API:BOOL=false -DENABLE_CLI=false
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC:H}/${b}bit ${MAKE_ARGS}
	${LN} -f ${WRKSRC:H}/${b}bit/libx265.a ${WRKSRC:H}/${b}bit/libx265_${b}bit.a
	${ECHO_MSG} "---> Built the ${b}-bit library ---"

.else
.if ((${ARCH} == i386 || ${ARCH} == armv7) && $b != 8) || ${ARCH} == powerpc || ${ARCH} == powerpc64
ASSEMBLY=	false
.else
ASSEMBLY=	true
.endif

pre-build::
	@${ECHO_MSG} "---> Building the ${b}-bit library ---"
	${MKDIR} ${WRKSRC:H}/${b}bit
	${CMAKE_BIN} -S ${WRKSRC} -B ${WRKSRC:H}/${b}bit \
		${CMAKE_OTHER_ARGS} ${b:C/1./-DHIGH_BIT_DEPTH:BOOL=true/} \
		-DMAIN${b}:BOOL=true -DENABLE_ASSEMBLY:BOOL=${ASSEMBLY} -DCPU_POWER8=false -DENABLE_ALTIVEC:BOOL=false \
		-DEXPORT_C_API:BOOL=false -DENABLE_CLI=false
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC:H}/${b}bit ${MAKE_ARGS}
	${LN} -f ${WRKSRC:H}/${b}bit/libx265.a ${WRKSRC:H}/${b}bit/libx265_${b}bit.a
	${ECHO_MSG} "---> Built the ${b}-bit library ---"
.endif
.endfor

.if "${EXTRA_LINK_FLAGS}"
CMAKE_ARGS+=	-DEXTRA_LINK_FLAGS:STRING="${EXTRA_LINK_FLAGS}"
CMAKE_ARGS+=	-DEXTRA_LIB="${OTHER_DEPTHS:C/HI([0-9]+)P/x265_\1bit/:C/ /;/gW}"
CMAKE_ARGS+=	${OTHER_DEPTHS:C/HI([0-9]+)P/-DLINKED_\1BIT:BOOL=true/}
.endif

CMAKE_ARGS+=	-DENABLE_SHARED:BOOL=true

.if ${ARCH} == i386 && ${DEFAULT_DEPTH} != "HI8P"
CMAKE_ARGS+=	-DENABLE_ASSEMBLY:BOOL=false
.else
.if !${ARCH:Mpowerpc*}
CMAKE_ARGS+=	-DENABLE_ASSEMBLY:BOOL=true
.elif ${ARCH} == powerpc64le
CMAKE_ARGS+=	-DCPU_POWER8=ON \
		-DENABLE_ALTIVEC=ON
.elif ${ARCH} == powerpc64
CMAKE_ARGS+=	-DCPU_POWER8=OFF \
		-DENABLE_ALTIVEC=OFF
.endif

do-test:
	${WRKDIR}/.build/test/TestBench
.endif

CMAKE_ARGS+=	-D_END_CUSTOM_OPTIONS=1
CMAKE_ARGS+=	-DENABLE_PIC:BOOL=true

.include <bsd.port.mk>
