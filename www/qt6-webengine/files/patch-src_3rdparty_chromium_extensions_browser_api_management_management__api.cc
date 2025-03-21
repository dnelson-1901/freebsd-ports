--- src/3rdparty/chromium/extensions/browser/api/management/management_api.cc.orig	2024-02-23 21:04:38 UTC
+++ src/3rdparty/chromium/extensions/browser/api/management/management_api.cc
@@ -279,7 +279,7 @@ bool PlatformSupportsApprovalFlowForExtensions() {
 #if BUILDFLAG(IS_CHROMEOS)
   // ChromeOS devices have this feature already shipped.
   return true;
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       supervised_user::kEnableExtensionsPermissionsForSupervisedUsersOnDesktop);
 #else
