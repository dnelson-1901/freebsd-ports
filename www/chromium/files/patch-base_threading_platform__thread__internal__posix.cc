--- base/threading/platform_thread_internal_posix.cc.orig	2025-02-19 07:43:18 UTC
+++ base/threading/platform_thread_internal_posix.cc
@@ -43,7 +43,7 @@ ThreadPriorityForTest NiceValueToThreadPriorityForTest
 }
 
 int GetCurrentThreadNiceValue() {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
   return 0;
 #else
