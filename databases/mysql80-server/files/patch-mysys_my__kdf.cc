--- mysys/my_kdf.cc.orig	2024-07-12 19:15:25 UTC
+++ mysys/my_kdf.cc
@@ -57,7 +57,7 @@ int create_kdf_key(const unsigned char *key, const uns
   std::unique_ptr<Key_derivation_function> kdf_function;
 
   if (kdf_name == "hkdf") {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     kdf_function = std::make_unique<Key_hkdf_function>(kdf_options);
 #else
     return 1;
@@ -72,7 +72,7 @@ int create_kdf_key(const unsigned char *key, const uns
   return kdf_function->derive_key(key, key_length, rkey, rkey_size);
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 Key_hkdf_function::Key_hkdf_function(vector<string> *kdf_options) {
   kdf_options_ = {kdf_options};
 }
