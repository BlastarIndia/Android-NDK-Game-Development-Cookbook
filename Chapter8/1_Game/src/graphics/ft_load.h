/*
 * Copyright (C) 2013 Sergey Kosarevsky (sk@linderdaum.com)
 * Copyright (C) 2013 Viktor Latypov (vl@linderdaum.com)
 * Based on Linderdaum Engine http://www.linderdaum.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must display the names 'Sergey Kosarevsky' and
 *    'Viktor Latypov'in the credits of the application, if such credits exist.
 *    The authors of this work must be notified via email (sk@linderdaum.com) in
 *    this case of redistribution.
 *
 * 3. Neither the name of copyright holders nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#if defined(_WIN32)
#  include <windows.h>
#endif

#include "ft.h"

#undef FT_STATIC_LINK

#if defined(ANDROID) || defined(OS_MACOSX)
#  define FT_STATIC_LINK
#endif

/**
   One more dynamic linking wrapper for FreeType library

   Why on Earth such an excellent project does NOT provide autogenerated function prototypes for dynamic linking possibility ?
*/
typedef FT_Error ( *FT_Init_FreeType_func )( FT_Library* alibrary );
typedef FT_Error ( *FT_Done_FreeType_func )( FT_Library  library );

typedef FT_Error ( *FT_Activate_Size_func )( FT_Size  size );

typedef FT_Error ( *FT_New_Face_func )( FT_Library library, const char* filepathname, FT_Long face_index, FT_Face* aface );
typedef FT_Error ( *FT_New_Memory_Face_func )( FT_Library library, const FT_Byte* file_base, FT_Long file_size, FT_Long face_index, FT_Face* aface );

typedef void     ( *FT_Glyph_Get_CBox_func )( FT_Glyph glyph, FT_UInt bbox_mode, FT_BBox* acbox );
typedef FT_Error ( *FT_Get_Kerning_func )( FT_Face face, FT_UInt left_glyph, FT_UInt right_glyph, FT_UInt kern_mode, FT_Vector* akerning );

typedef FT_Error ( *FTC_Manager_New_func )( FT_Library library, FT_UInt max_faces, FT_UInt max_sizes, FT_ULong max_bytes, FTC_Face_Requester requester, FT_Pointer req_data, FTC_Manager* amanager );
typedef void     ( *FTC_Manager_Done_func )( FTC_Manager manager );

typedef FT_Error ( *FTC_ImageCache_New_func )( FTC_Manager manager, FTC_ImageCache* acache );
typedef FT_Error ( *FTC_ImageCache_Lookup_func )( FTC_ImageCache cache, FTC_ImageType type, FT_UInt gindex, FT_Glyph* aglyph, FTC_Node* anode );

typedef FT_Error ( *FTC_CMapCache_New_func )( FTC_Manager manager, FTC_CMapCache* acache );
typedef FT_UInt  ( *FTC_CMapCache_Lookup_func )( FTC_CMapCache cache, FTC_FaceID face_id, FT_Int cmap_index, FT_UInt32 char_code );

typedef void     ( *FTC_Node_Unref_func )( FTC_Node node, FTC_Manager manager );

typedef FT_Error ( *FTC_Manager_LookupFace_func )( FTC_Manager manager, FTC_FaceID face_id, FT_Face* aface );
typedef FT_Error ( *FTC_Manager_LookupSize_func )( FTC_Manager manager, FTC_Scaler scaler,  FT_Size* asize );

extern FT_Init_FreeType_func FT_Init_FreeTypePTR;

extern FT_Activate_Size_func FT_Activate_SizePTR;
extern FT_Done_FreeType_func FT_Done_FreeTypePTR;

extern FT_New_Face_func FT_New_FacePTR;
extern FT_New_Memory_Face_func FT_New_Memory_FacePTR;

extern FT_Glyph_Get_CBox_func FT_Glyph_Get_CBoxPTR;
extern FT_Get_Kerning_func FT_Get_KerningPTR;

extern FTC_Manager_New_func FTC_Manager_NewPTR;
extern FTC_Manager_Done_func FTC_Manager_DonePTR;

extern FTC_ImageCache_New_func FTC_ImageCache_NewPTR;
extern FTC_ImageCache_Lookup_func FTC_ImageCache_LookupPTR;

extern FTC_CMapCache_New_func FTC_CMapCache_NewPTR;
extern FTC_CMapCache_Lookup_func FTC_CMapCache_LookupPTR;

extern FTC_Node_Unref_func FTC_Node_UnrefPTR;

extern FTC_Manager_LookupFace_func FTC_Manager_LookupFacePTR;
extern FTC_Manager_LookupSize_func FTC_Manager_LookupSizePTR;

#if defined(FT_STATIC_LINK)
extern "C"
{
	FT_Error FT_Init_FreeType( FT_Library* alibrary );
	FT_Error FT_Done_FreeType( FT_Library  library );
	FT_Error FT_Activate_Size( FT_Size  size );
	FT_Error FT_New_Face( FT_Library library, const char* filepathname, FT_Long face_index, FT_Face* aface );
	FT_Error FT_New_Memory_Face( FT_Library library, const FT_Byte* file_base, FT_Long file_size, FT_Long face_index, FT_Face* aface );
	void     FT_Glyph_Get_CBox( FT_Glyph glyph, FT_UInt bbox_mode, FT_BBox* acbox );
	FT_Error FT_Get_Kerning( FT_Face face, FT_UInt left_glyph, FT_UInt right_glyph, FT_UInt kern_mode, FT_Vector* akerning );
	FT_Error FTC_Manager_New( FT_Library library, FT_UInt max_faces, FT_UInt max_sizes, FT_ULong max_bytes, FTC_Face_Requester requester, FT_Pointer req_data, FTC_Manager* amanager );
	void     FTC_Manager_Done( FTC_Manager manager );
	FT_Error FTC_ImageCache_New( FTC_Manager manager, FTC_ImageCache* acache );
	FT_Error FTC_ImageCache_Lookup( FTC_ImageCache cache, FTC_ImageType type, FT_UInt gindex, FT_Glyph* aglyph, FTC_Node* anode );
	FT_Error FTC_CMapCache_New( FTC_Manager manager, FTC_CMapCache* acache );
	FT_UInt  FTC_CMapCache_Lookup( FTC_CMapCache cache, FTC_FaceID face_id, FT_Int cmap_index, FT_UInt32 char_code );
	void     FTC_Node_Unref( FTC_Node node, FTC_Manager manager );
	FT_Error FTC_Manager_LookupFace( FTC_Manager manager, FTC_FaceID face_id, FT_Face* aface );
	FT_Error FTC_Manager_LookupSize( FTC_Manager manager, FTC_Scaler scaler,  FT_Size* asize );
}
#endif // Static link

bool LoadFT();
void UnloadFT();
