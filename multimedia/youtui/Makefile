PORTNAME=	youtui
DISTVERSIONPREFIX=	youtui/v
DISTVERSION=	0.0.25
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TUI and API for YouTube music
WWW=		https://github.com/nick42d/youtui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	nick42d

RUSTFLAGS=	${ARCH:S/i386/YES/:C/^[a-z].*//:S/YES/-C target-feature=+sse,+sse2/} # add sse sse2 target-features only on i386

CARGO_CRATES=	ab_glyph-0.2.29 \
		ab_glyph_rasterizer-0.1.8 \
		addr2line-0.24.2 \
		adler2-2.0.0 \
		aes-0.8.4 \
		ahash-0.8.12 \
		aho-corasick-1.1.3 \
		aligned-vec-0.5.0 \
		allocator-api2-0.2.21 \
		alsa-0.9.1 \
		alsa-sys-0.3.1 \
		android-activity-0.6.0 \
		android-properties-0.2.2 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anstream-0.6.19 \
		anstyle-1.0.11 \
		anstyle-parse-0.2.7 \
		anstyle-query-1.1.3 \
		anstyle-wincon-3.0.9 \
		anyhow-1.0.98 \
		arbitrary-1.4.1 \
		arg_enum_proc_macro-0.3.4 \
		arrayref-0.3.9 \
		arrayvec-0.7.6 \
		as-raw-xcb-connection-1.0.1 \
		async-broadcast-0.5.1 \
		async-channel-2.3.1 \
		async-compression-0.4.23 \
		async-executor-1.13.2 \
		async-fs-1.6.0 \
		async-io-1.13.0 \
		async-io-2.4.1 \
		async-lock-2.8.0 \
		async-lock-3.4.0 \
		async-process-1.8.1 \
		async-recursion-1.1.1 \
		async-signal-0.2.11 \
		async-task-4.7.1 \
		async-trait-0.1.88 \
		async_cell-0.2.2 \
		atomic-waker-1.1.2 \
		autocfg-1.4.0 \
		av1-grain-0.2.4 \
		avif-serialize-0.8.3 \
		backtrace-0.3.75 \
		base64-0.21.7 \
		base64-0.22.1 \
		bindgen-0.70.1 \
		bit_field-0.10.2 \
		bitflags-1.3.2 \
		bitflags-2.9.1 \
		bitstream-io-2.6.0 \
		block-0.1.6 \
		block-buffer-0.10.4 \
		block-padding-0.3.3 \
		block2-0.5.1 \
		blocking-1.6.1 \
		boa_ast-0.20.0 \
		boa_engine-0.20.0 \
		boa_gc-0.20.0 \
		boa_interner-0.20.0 \
		boa_macros-0.20.0 \
		boa_parser-0.20.0 \
		boa_profiler-0.20.0 \
		boa_string-0.20.0 \
		built-0.7.7 \
		bumpalo-3.18.1 \
		bytemuck-1.23.0 \
		bytemuck_derive-1.9.3 \
		byteorder-1.5.0 \
		byteorder-lite-0.1.0 \
		bytes-1.10.1 \
		calloop-0.13.0 \
		calloop-wayland-source-0.3.0 \
		cassowary-0.3.0 \
		castaway-0.2.3 \
		cbc-0.1.2 \
		cc-1.2.26 \
		cesu8-1.1.0 \
		cexpr-0.6.0 \
		cfg-expr-0.15.8 \
		cfg-if-1.0.0 \
		cfg_aliases-0.2.1 \
		chrono-0.4.41 \
		cipher-0.4.4 \
		clang-sys-1.8.1 \
		clap-4.5.39 \
		clap_builder-4.5.39 \
		clap_complete-4.5.52 \
		clap_derive-4.5.32 \
		clap_lex-0.7.4 \
		claxon-0.4.3 \
		cocoa-0.24.1 \
		cocoa-foundation-0.1.2 \
		color_quant-1.1.0 \
		colorchoice-1.0.4 \
		combine-4.6.7 \
		compact_str-0.8.1 \
		concurrent-queue-2.5.0 \
		const_format-0.2.34 \
		const_format_proc_macros-0.2.34 \
		cookie-0.18.1 \
		cookie_store-0.21.1 \
		core-foundation-0.9.4 \
		core-foundation-sys-0.8.7 \
		core-graphics-0.22.3 \
		core-graphics-0.23.2 \
		core-graphics-types-0.1.3 \
		coreaudio-rs-0.11.3 \
		coreaudio-sys-0.2.16 \
		cpal-0.15.3 \
		cpufeatures-0.2.17 \
		crc32fast-1.4.2 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		crossterm-0.28.1 \
		crossterm_winapi-0.9.1 \
		crunchy-0.2.3 \
		crypto-common-0.1.6 \
		cssparser-0.31.2 \
		cssparser-macros-0.6.1 \
		cursor-icon-1.2.0 \
		darling-0.20.11 \
		darling_core-0.20.11 \
		darling_macro-0.20.11 \
		dashmap-6.1.0 \
		dasp_sample-0.11.0 \
		deranged-0.4.0 \
		derivative-2.2.0 \
		derive_more-0.99.20 \
		derive_more-1.0.0 \
		derive_more-impl-1.0.0 \
		diff-0.1.13 \
		digest-0.10.7 \
		directories-6.0.0 \
		dirs-sys-0.5.0 \
		dispatch-0.2.0 \
		displaydoc-0.2.5 \
		dlib-0.5.2 \
		document-features-0.2.11 \
		downcast-rs-1.2.1 \
		dpi-0.1.2 \
		dtoa-1.0.10 \
		dtoa-short-0.3.5 \
		dyn-clone-1.0.19 \
		ego-tree-0.6.3 \
		either-1.15.0 \
		encoding_rs-0.8.35 \
		enumflags2-0.7.11 \
		enumflags2_derive-0.7.11 \
		equivalent-1.0.2 \
		errno-0.3.12 \
		event-listener-2.5.3 \
		event-listener-3.1.0 \
		event-listener-5.4.0 \
		event-listener-strategy-0.5.4 \
		exr-1.73.0 \
		extended-0.1.0 \
		fast-float2-0.2.3 \
		fastrand-1.9.0 \
		fastrand-2.3.0 \
		fdeflate-0.3.7 \
		filedescriptor-0.8.3 \
		flate2-1.1.1 \
		fnv-1.0.7 \
		foldhash-0.1.5 \
		foreign-types-0.3.2 \
		foreign-types-0.5.0 \
		foreign-types-macros-0.2.3 \
		foreign-types-shared-0.1.1 \
		foreign-types-shared-0.3.1 \
		form_urlencoded-1.2.1 \
		format_num_pattern-0.9.3 \
		fs-err-3.1.1 \
		futf-0.1.5 \
		futures-0.3.31 \
		futures-channel-0.3.31 \
		futures-core-0.3.31 \
		futures-executor-0.3.31 \
		futures-io-0.3.31 \
		futures-lite-1.13.0 \
		futures-lite-2.6.0 \
		futures-macro-0.3.31 \
		futures-sink-0.3.31 \
		futures-task-0.3.31 \
		futures-util-0.3.31 \
		fxhash-0.2.1 \
		gag-1.0.0 \
		generic-array-0.14.7 \
		gethostname-0.4.3 \
		getopts-0.2.21 \
		getrandom-0.2.16 \
		getrandom-0.3.3 \
		gif-0.13.1 \
		gimli-0.31.1 \
		glob-0.3.2 \
		h2-0.4.10 \
		half-2.6.0 \
		hashbrown-0.14.5 \
		hashbrown-0.15.3 \
		heck-0.5.0 \
		hermit-abi-0.3.9 \
		hermit-abi-0.5.1 \
		hex-0.4.3 \
		hound-3.5.1 \
		html5ever-0.27.0 \
		http-1.3.1 \
		http-body-1.0.1 \
		http-body-util-0.1.3 \
		httparse-1.10.1 \
		hyper-1.6.0 \
		hyper-rustls-0.27.7 \
		hyper-tls-0.6.0 \
		hyper-util-0.1.14 \
		iana-time-zone-0.1.63 \
		iana-time-zone-haiku-0.1.2 \
		icu_collections-1.5.0 \
		icu_collections-2.0.0 \
		icu_locale_core-2.0.0 \
		icu_locid-1.5.0 \
		icu_locid_transform-1.5.0 \
		icu_locid_transform_data-1.5.1 \
		icu_normalizer-1.5.0 \
		icu_normalizer-2.0.0 \
		icu_normalizer_data-1.5.1 \
		icu_normalizer_data-2.0.0 \
		icu_properties-1.5.1 \
		icu_properties-2.0.1 \
		icu_properties_data-1.5.1 \
		icu_properties_data-2.0.1 \
		icu_provider-1.5.0 \
		icu_provider-2.0.0 \
		icu_provider_macros-1.5.0 \
		icy_sixel-0.1.3 \
		ident_case-1.0.1 \
		idna-1.0.3 \
		idna_adapter-1.2.1 \
		image-0.25.6 \
		image-webp-0.2.1 \
		imgref-1.11.0 \
		indexmap-2.9.0 \
		indoc-2.0.6 \
		inout-0.1.4 \
		instability-0.3.7 \
		instant-0.1.13 \
		interpolate_name-0.2.4 \
		intrusive-collections-0.9.7 \
		io-lifetimes-1.0.11 \
		ipnet-2.11.0 \
		iri-string-0.7.8 \
		is_terminal_polyfill-1.70.1 \
		iset-0.3.1 \
		itertools-0.12.1 \
		itertools-0.13.0 \
		itertools-0.14.0 \
		itoa-1.0.15 \
		jni-0.21.1 \
		jni-sys-0.3.0 \
		jobserver-0.1.33 \
		jpeg-decoder-0.3.1 \
		js-sys-0.3.77 \
		lazy_static-1.5.0 \
		lebe-0.5.2 \
		lewton-0.10.2 \
		libc-0.2.172 \
		libfuzzer-sys-0.4.9 \
		libloading-0.8.8 \
		libredox-0.1.3 \
		linux-raw-sys-0.3.8 \
		linux-raw-sys-0.4.15 \
		linux-raw-sys-0.9.4 \
		litemap-0.7.5 \
		litemap-0.8.0 \
		litrs-0.4.1 \
		lock_api-0.4.13 \
		log-0.4.27 \
		loop9-0.1.5 \
		lru-0.12.5 \
		lru-slab-0.1.2 \
		m3u8-rs-6.0.0 \
		mac-0.1.1 \
		mach2-0.4.2 \
		malloc_buf-0.0.6 \
		markup5ever-0.12.1 \
		maybe-rayon-0.1.1 \
		memchr-2.7.4 \
		memmap2-0.9.5 \
		memoffset-0.7.1 \
		memoffset-0.9.1 \
		mime-0.3.17 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.8.8 \
		mio-1.0.4 \
		native-tls-0.2.14 \
		ndk-0.8.0 \
		ndk-0.9.0 \
		ndk-context-0.1.1 \
		ndk-sys-0.5.0+25.2.9519653 \
		ndk-sys-0.6.0+11769913 \
		new_debug_unreachable-1.0.6 \
		nix-0.26.4 \
		nom-7.1.3 \
		noop_proc_macro-0.3.0 \
		nu-ansi-term-0.46.0 \
		num-bigint-0.4.6 \
		num-conv-0.1.0 \
		num-derive-0.4.2 \
		num-integer-0.1.46 \
		num-rational-0.4.2 \
		num-traits-0.2.19 \
		num_enum-0.7.3 \
		num_enum_derive-0.7.3 \
		num_threads-0.1.7 \
		objc-0.2.7 \
		objc-sys-0.3.5 \
		objc2-0.5.2 \
		objc2-app-kit-0.2.2 \
		objc2-cloud-kit-0.2.2 \
		objc2-contacts-0.2.2 \
		objc2-core-data-0.2.2 \
		objc2-core-image-0.2.2 \
		objc2-core-location-0.2.2 \
		objc2-encode-4.1.0 \
		objc2-foundation-0.2.2 \
		objc2-link-presentation-0.2.2 \
		objc2-metal-0.2.2 \
		objc2-quartz-core-0.2.2 \
		objc2-symbols-0.2.2 \
		objc2-ui-kit-0.2.2 \
		objc2-uniform-type-identifiers-0.2.2 \
		objc2-user-notifications-0.2.2 \
		object-0.36.7 \
		oboe-0.6.1 \
		oboe-sys-0.6.1 \
		ogg-0.8.0 \
		once_cell-1.21.3 \
		once_cell_polyfill-1.70.1 \
		openssl-0.10.73 \
		openssl-macros-0.1.1 \
		openssl-probe-0.1.6 \
		openssl-sys-0.9.109 \
		option-ext-0.2.0 \
		orbclient-0.3.48 \
		ordered-stream-0.2.0 \
		overload-0.1.1 \
		owned_ttf_parser-0.25.0 \
		parking-2.2.1 \
		parking_lot-0.11.2 \
		parking_lot-0.12.4 \
		parking_lot_core-0.8.6 \
		parking_lot_core-0.9.11 \
		paste-1.0.15 \
		percent-encoding-2.3.1 \
		phf-0.10.1 \
		phf-0.11.3 \
		phf_codegen-0.10.0 \
		phf_codegen-0.11.3 \
		phf_generator-0.10.0 \
		phf_generator-0.11.3 \
		phf_macros-0.11.3 \
		phf_shared-0.10.0 \
		phf_shared-0.11.3 \
		pin-project-1.1.10 \
		pin-project-internal-1.1.10 \
		pin-project-lite-0.2.16 \
		pin-utils-0.1.0 \
		piper-0.2.4 \
		pkg-config-0.3.32 \
		png-0.17.16 \
		polling-2.8.0 \
		polling-3.8.0 \
		pollster-0.3.0 \
		pollster-0.4.0 \
		portable-atomic-1.11.1 \
		potential_utf-0.1.2 \
		powerfmt-0.2.0 \
		ppv-lite86-0.2.21 \
		precomputed-hash-0.1.1 \
		pretty_assertions-1.4.1 \
		proc-macro-crate-1.3.1 \
		proc-macro-crate-3.3.0 \
		proc-macro2-1.0.95 \
		profiling-1.0.16 \
		profiling-procmacros-1.0.16 \
		psl-types-2.0.11 \
		publicsuffix-2.3.0 \
		pure-rust-locales-0.8.1 \
		qoi-0.4.1 \
		quick-error-2.0.1 \
		quick-xml-0.37.5 \
		quinn-0.11.8 \
		quinn-proto-0.11.12 \
		quinn-udp-0.5.12 \
		quote-1.0.40 \
		r-efi-5.2.0 \
		rand-0.8.5 \
		rand-0.9.1 \
		rand_chacha-0.3.1 \
		rand_chacha-0.9.0 \
		rand_core-0.6.4 \
		rand_core-0.9.3 \
		rat-cursor-1.2.0 \
		rat-event-1.2.3 \
		rat-focus-1.0.1 \
		rat-reloc-1.1.2 \
		rat-scrolled-1.1.1 \
		rat-text-1.0.4 \
		ratatui-0.29.0 \
		ratatui-image-8.0.1 \
		rav1e-0.7.1 \
		ravif-0.11.12 \
		raw-window-handle-0.6.2 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		redox_syscall-0.2.16 \
		redox_syscall-0.4.1 \
		redox_syscall-0.5.12 \
		redox_users-0.5.0 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		regress-0.10.3 \
		reqwest-0.12.19 \
		reqwest-middleware-0.3.3 \
		reqwest-retry-0.6.1 \
		retry-policies-0.4.0 \
		rgb-0.8.50 \
		ring-0.17.14 \
		rodio-0.20.1 \
		ropey-1.6.1 \
		rustc-demangle-0.1.24 \
		rustc-hash-1.1.0 \
		rustc-hash-2.1.1 \
		rustix-0.37.28 \
		rustix-0.38.44 \
		rustix-1.0.7 \
		rustls-0.23.27 \
		rustls-pki-types-1.12.0 \
		rustls-webpki-0.103.3 \
		rustversion-1.0.21 \
		ryu-1.0.20 \
		ryu-js-1.0.2 \
		same-file-1.0.6 \
		schannel-0.1.27 \
		scoped-tls-1.0.1 \
		scopeguard-1.2.0 \
		scraper-0.20.0 \
		sctk-adwaita-0.10.1 \
		security-framework-2.11.1 \
		security-framework-sys-2.14.0 \
		selectors-0.25.0 \
		serde-1.0.219 \
		serde_derive-1.0.219 \
		serde_json-1.0.140 \
		serde_qs-0.13.0 \
		serde_repr-0.1.20 \
		serde_spanned-0.6.9 \
		serde_urlencoded-0.7.1 \
		servo_arc-0.3.0 \
		sha1-0.10.6 \
		sharded-slab-0.1.7 \
		shlex-1.3.0 \
		signal-hook-0.3.18 \
		signal-hook-mio-0.2.4 \
		signal-hook-registry-1.4.5 \
		simd-adler32-0.3.7 \
		simd_helpers-0.1.0 \
		siphasher-0.3.11 \
		siphasher-1.0.1 \
		slab-0.4.9 \
		smallvec-1.15.0 \
		smithay-client-toolkit-0.19.2 \
		smol_str-0.2.2 \
		socket2-0.4.10 \
		socket2-0.5.10 \
		souvlaki-0.8.2 \
		sptr-0.3.2 \
		stable_deref_trait-1.2.0 \
		static_assertions-1.1.0 \
		str_indices-0.4.4 \
		strict-num-0.1.1 \
		string_cache-0.8.9 \
		string_cache_codegen-0.5.4 \
		strsim-0.11.1 \
		strum-0.26.3 \
		strum_macros-0.26.4 \
		subtle-2.6.1 \
		symphonia-0.5.4 \
		symphonia-bundle-flac-0.5.4 \
		symphonia-bundle-mp3-0.5.4 \
		symphonia-codec-aac-0.5.4 \
		symphonia-codec-adpcm-0.5.4 \
		symphonia-codec-pcm-0.5.4 \
		symphonia-codec-vorbis-0.5.4 \
		symphonia-core-0.5.4 \
		symphonia-format-isomp4-0.5.4 \
		symphonia-format-riff-0.5.4 \
		symphonia-metadata-0.5.4 \
		symphonia-utils-xiph-0.5.4 \
		syn-1.0.109 \
		syn-2.0.101 \
		sync_wrapper-1.0.2 \
		synstructure-0.13.2 \
		system-configuration-0.6.1 \
		system-configuration-sys-0.6.0 \
		system-deps-6.2.2 \
		tap-1.0.1 \
		target-lexicon-0.12.16 \
		tempfile-3.20.0 \
		tendril-0.4.3 \
		thin-vec-0.2.14 \
		thiserror-1.0.69 \
		thiserror-2.0.12 \
		thiserror-impl-1.0.69 \
		thiserror-impl-2.0.12 \
		thread_local-1.1.8 \
		tiff-0.9.1 \
		time-0.3.41 \
		time-core-0.1.4 \
		time-macros-0.2.22 \
		tiny-skia-0.11.4 \
		tiny-skia-path-0.11.4 \
		tinystr-0.7.6 \
		tinystr-0.8.1 \
		tinyvec-1.9.0 \
		tinyvec_macros-0.1.1 \
		tokio-1.45.1 \
		tokio-macros-2.5.0 \
		tokio-native-tls-0.3.1 \
		tokio-rustls-0.26.2 \
		tokio-stream-0.1.17 \
		tokio-util-0.7.15 \
		toml-0.8.23 \
		toml_datetime-0.6.11 \
		toml_edit-0.19.15 \
		toml_edit-0.22.27 \
		toml_write-0.1.2 \
		tower-0.5.2 \
		tower-http-0.6.6 \
		tower-layer-0.3.3 \
		tower-service-0.3.3 \
		tracing-0.1.41 \
		tracing-attributes-0.1.29 \
		tracing-core-0.1.34 \
		tracing-log-0.2.0 \
		tracing-subscriber-0.3.19 \
		try-lock-0.2.5 \
		ttf-parser-0.25.1 \
		tui-logger-0.14.5 \
		typenum-1.18.0 \
		uds_windows-1.1.0 \
		unicode-display-width-0.3.0 \
		unicode-ident-1.0.18 \
		unicode-segmentation-1.12.0 \
		unicode-truncate-1.1.0 \
		unicode-width-0.1.14 \
		unicode-width-0.2.0 \
		unicode-xid-0.2.6 \
		untrusted-0.9.0 \
		url-2.5.4 \
		urlencoding-2.1.3 \
		utf-8-0.7.6 \
		utf16_iter-1.0.5 \
		utf8_iter-1.0.4 \
		utf8parse-0.2.2 \
		v_frame-0.3.8 \
		valuable-0.1.1 \
		vcpkg-0.2.15 \
		version-compare-0.2.0 \
		version_check-0.9.5 \
		waker-fn-1.2.0 \
		walkdir-2.5.0 \
		want-0.3.1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasi-0.14.2+wasi-0.2.4 \
		wasm-bindgen-0.2.100 \
		wasm-bindgen-backend-0.2.100 \
		wasm-bindgen-futures-0.4.50 \
		wasm-bindgen-macro-0.2.100 \
		wasm-bindgen-macro-support-0.2.100 \
		wasm-bindgen-shared-0.2.100 \
		wasm-timer-0.2.5 \
		wayland-backend-0.3.10 \
		wayland-client-0.31.10 \
		wayland-csd-frame-0.3.0 \
		wayland-cursor-0.31.10 \
		wayland-protocols-0.32.8 \
		wayland-protocols-plasma-0.3.8 \
		wayland-protocols-wlr-0.3.8 \
		wayland-scanner-0.31.6 \
		wayland-sys-0.31.6 \
		web-sys-0.3.77 \
		web-time-1.1.0 \
		webpki-roots-1.0.0 \
		weezl-0.1.10 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.9 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.44.0 \
		windows-0.54.0 \
		windows-0.58.0 \
		windows-core-0.54.0 \
		windows-core-0.58.0 \
		windows-core-0.61.2 \
		windows-implement-0.58.0 \
		windows-implement-0.60.0 \
		windows-interface-0.58.0 \
		windows-interface-0.59.1 \
		windows-link-0.1.1 \
		windows-registry-0.5.2 \
		windows-result-0.1.2 \
		windows-result-0.2.0 \
		windows-result-0.3.4 \
		windows-strings-0.1.0 \
		windows-strings-0.4.2 \
		windows-sys-0.45.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.42.2 \
		windows-targets-0.48.5 \
		windows-targets-0.52.6 \
		windows-targets-0.53.0 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_gnullvm-0.53.0 \
		windows_aarch64_msvc-0.42.2 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.6 \
		windows_aarch64_msvc-0.53.0 \
		windows_i686_gnu-0.42.2 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnu-0.53.0 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_gnullvm-0.53.0 \
		windows_i686_msvc-0.42.2 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.6 \
		windows_i686_msvc-0.53.0 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnu-0.53.0 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_gnullvm-0.53.0 \
		windows_x86_64_msvc-0.42.2 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.6 \
		windows_x86_64_msvc-0.53.0 \
		winit-0.30.11 \
		winnow-0.5.40 \
		winnow-0.7.10 \
		wit-bindgen-rt-0.39.0 \
		write16-1.0.0 \
		writeable-0.5.5 \
		writeable-0.6.1 \
		x11-dl-2.21.0 \
		x11rb-0.13.1 \
		x11rb-protocol-0.13.1 \
		xcursor-0.3.8 \
		xdg-home-1.3.0 \
		xkbcommon-dl-0.4.2 \
		xkeysym-0.2.1 \
		yansi-1.0.1 \
		yoke-0.7.5 \
		yoke-0.8.0 \
		yoke-derive-0.7.5 \
		yoke-derive-0.8.0 \
		youtui-vendored-rusty_ytdl-0.7.4-youtui-vendored.2 \
		zbus-3.15.2 \
		zbus_macros-3.15.2 \
		zbus_names-2.6.1 \
		zerocopy-0.8.25 \
		zerocopy-derive-0.8.25 \
		zerofrom-0.1.6 \
		zerofrom-derive-0.1.6 \
		zeroize-1.8.1 \
		zerotrie-0.2.2 \
		zerovec-0.10.4 \
		zerovec-0.11.2 \
		zerovec-derive-0.10.3 \
		zerovec-derive-0.11.1 \
		zune-core-0.4.12 \
		zune-inflate-0.2.54 \
		zune-jpeg-0.4.16 \
		zvariant-3.15.2 \
		zvariant_derive-3.15.2 \
		zvariant_utils-1.0.1

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/${PORTNAME}

do-install:
	# binaries (workaround for error: found a virtual manifest at `xx` instead of a package manifest)
	echo ">> find"
	find ${WRKDIR}/target
	echo "<< find"
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
