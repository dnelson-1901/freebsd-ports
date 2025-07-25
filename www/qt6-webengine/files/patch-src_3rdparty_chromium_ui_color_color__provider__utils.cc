--- src/3rdparty/chromium/ui/color/color_provider_utils.cc.orig	2024-08-26 12:06:38 UTC
+++ src/3rdparty/chromium/ui/color/color_provider_utils.cc
@@ -187,7 +187,7 @@ std::string_view SystemThemeName(ui::SystemTheme syste
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
       return "kDefault";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
       return "kGtk";
     case ui::SystemTheme::kQt:
