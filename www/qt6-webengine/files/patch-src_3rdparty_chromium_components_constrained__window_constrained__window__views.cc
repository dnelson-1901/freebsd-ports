--- src/3rdparty/chromium/components/constrained_window/constrained_window_views.cc.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/components/constrained_window/constrained_window_views.cc
@@ -372,7 +372,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
