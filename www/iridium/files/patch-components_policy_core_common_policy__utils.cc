--- components/policy/core/common/policy_utils.cc.orig	2025-05-07 06:48:23 UTC
+++ components/policy/core/common/policy_utils.cc
@@ -22,7 +22,7 @@ bool IsPolicyTestingEnabled(PrefService* pref_service,
     return true;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   if (channel == version_info::Channel::DEV) {
     return true;
   }
