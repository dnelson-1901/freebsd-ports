--- src/slic3r/GUI/UnsavedChangesDialog.cpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/GUI/UnsavedChangesDialog.cpp
@@ -32,7 +32,7 @@ using boost::optional;
 
 using boost::optional;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define wxLinux true
 #else
 #define wxLinux false
@@ -112,7 +112,7 @@ ModelNode::ModelNode(ModelNode* parent, const wxString
     UpdateIcons();
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 wxIcon ModelNode::get_bitmap(const wxString& color)
 #else
 wxBitmap ModelNode::get_bitmap(const wxString& color)
@@ -121,7 +121,7 @@ wxBitmap ModelNode::get_bitmap(const wxString& color)
     wxBitmap bmp = get_solid_bmp_bundle(64, 16, into_u8(color))->GetBitmapFor(m_parent_win);
     if (!m_toggle)
         bmp = bmp.ConvertToDisabled();
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
     return bmp;
 #else
     wxIcon icon;
@@ -225,7 +225,7 @@ void ModelNode::UpdateIcons()
     if (!m_toggle)
         bmp = bmp.ConvertToDisabled();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     m_icon.CopyFromBitmap(bmp);
 #else
     m_icon = bmp;
@@ -377,7 +377,7 @@ void DiffModel::GetValue(wxVariant& variant, const wxD
     case colToggle:
         variant = node->m_toggle;
         break;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     case colIconText:
         variant << wxDataViewIconText(node->m_text, node->m_icon);
         break;
@@ -420,7 +420,7 @@ bool DiffModel::SetValue(const wxVariant& variant, con
     case colToggle:
         node->m_toggle = variant.GetBool();
         return true;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     case colIconText: {
         wxDataViewIconText data;
         data << variant;
@@ -648,7 +648,7 @@ void DiffViewCtrl::AppendBmpTextColumn(const wxString&
 void DiffViewCtrl::AppendBmpTextColumn(const wxString& label, unsigned model_column, int width, bool set_expander/* = false*/)
 {
     m_columns_width.emplace(this->GetColumnCount(), width);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxDataViewIconTextRenderer* rd = new wxDataViewIconTextRenderer();
 #ifdef SUPPORTS_MARKUP
     rd->EnableMarkup(true);
