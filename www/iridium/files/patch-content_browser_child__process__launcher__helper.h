--- content/browser/child_process_launcher_helper.h.orig	2024-12-22 12:24:29 UTC
+++ content/browser/child_process_launcher_helper.h
@@ -304,7 +304,7 @@ class ChildProcessLauncherHelper
   std::optional<base::ProcessId> process_id_ = std::nullopt;
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The priority of the process. The state is stored to avoid changing the
   // setting repeatedly.
   std::optional<base::Process::Priority> priority_;
