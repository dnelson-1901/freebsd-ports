PORTNAME=	Config-Model-Tester
PORTVERSION=	4.007
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test framework for Config::Model
WWW=		https://metacpan.org/release/Config-Model-Tester

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Config-Model>=0:devel/p5-Config-Model \
		p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-Log-Log4perl>=1.11:devel/p5-Log-Log4perl \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-File-Contents>=0:devel/p5-Test-File-Contents \
		p5-Test-Log-Log4perl>=0:devel/p5-Test-Log-Log4perl \
		p5-Test-Memory-Cycle>=0:devel/p5-Test-Memory-Cycle \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
