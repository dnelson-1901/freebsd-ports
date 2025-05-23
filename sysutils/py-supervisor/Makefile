PORTNAME=	supervisor
PORTVERSION=	4.2.5
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	System for controlling process state under UNIX
WWW=		http://supervisord.org/

LICENSE=	BSD3CLAUSE MEDUSA REPOZE
LICENSE_COMB=	multi
LICENSE_NAME_MEDUSA=	Medusa License
LICENSE_NAME_REPOZE=	Repoze License
LICENSE_FILE=	${WRKSRC}/LICENSES.txt
LICENSE_PERMS_MEDUSA=	dist-mirror pkg-mirror auto-accept
LICENSE_PERMS_REPOZE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0.5.0:devel/py-mock@${PY_FLAVOR}

USES=		cpe python shebangfix
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	supervisord
SHEBANG_FILES=	supervisor/scripts/*.py supervisor/tests/fixtures/*.py
python_OLD_CMD=	"<<PYTHON>>"

CPE_VENDOR=	supervisord

NO_ARCH=	yes
SUB_LIST=	PIDDIR=${PIDDIR} \
		PYTHON_CMD=${PYTHON_CMD}

PLIST_DIRS=	${PIDDIR}
PLIST_FILES=	'@sample etc/supervisord.conf.sample'
PLIST_SUB=	PIDDIR=${PIDDIR}

PORTDOCS=	*.rst *.txt

OPTIONS_DEFINE=	DOCS

PIDDIR?=	/var/run/supervisor

post-patch:
	@${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!' ${WRKSRC}/supervisor/options.py \
		${WRKSRC}/supervisor/tests/test_options.py

post-install:
	${INSTALL_DATA} ${FILESDIR}/supervisord.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL} -d ${STAGEDIR}${PIDDIR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
