PORTNAME=	tmuxinator
PORTVERSION=	3.3.4
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Manage complex tmux sessions easily
WWW=		https://github.com/tmuxinator/tmuxinator

LICENSE=	MIT

RUN_DEPENDS=	rubygem-erubi>=1.7<2:www/rubygem-erubi \
		rubygem-thor>=1.3.0<1.4:devel/rubygem-thor \
		rubygem-xdg2>=2.2.5<3:devel/rubygem-xdg2

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/tmuxinator \
		etc/bash_completion.d/_tmuxinator.bash \
		share/zsh/site-functions/_tmuxinator

OPTIONS_SINGLE=	TMUX
OPTIONS_SINGLE_TMUX=	TMUX TMUX23
OPTIONS_DEFAULT=TMUX
TMUX_DESC=	Use tmux 3.x from sysutils/tmux
TMUX23_DESC=	Use tmux 2.3 from sysutils/tmux23

TMUX_RUN_DEPENDS=	tmux:sysutils/tmux
TMUX23_RUN_DEPENDS=	tmux:sysutils/tmux23

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completion/tmuxinator.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/_tmuxinator.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completion/tmuxinator.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_tmuxinator

.include <bsd.port.mk>
