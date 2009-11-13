/* Input class, key bindings and upper casing vector definitions.

	Copyright (C) 1993-1998 Sebastiano Vigna 
	Copyright (C) 1999-2009 Todd M. Lewis and Sebastiano Vigna

	This file is part of ne, the nice editor.

	This program is free software; you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the
	Free Software Foundation; either version 2, or (at your option) any
	later version.
	
	This program is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	General Public License for more details.
	
	You should have received a copy of the GNU General Public License along
	with this program; see the file COPYING.  If not, write to the Free
	Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
	02111-1307, USA.  */


#include "ne.h"

const char *input_class_names[INPUT_CLASS_COUNT] = {
	"ALPHA", "COMMAND", "RETURN", "TAB", "IGNORE", "INVALID"
}; 

/* This vector contains all key bindings. Each entry points to a command line
	to be executed when the corresponding keystroke is input. The index
	correspond to the ASCII code, and to the codes defined in keycodes.h for the
	special keys. Note that it is nonsense to specify a binding for a key whose
	class is not COMMAND. */

#ifndef SHELLKEYS
  #define PICK(A,B) A
#else
  #define PICK(A,B) B
#endif

const char *key_binding[NUM_KEYS] = {

	/* Control-letter bindings (Ctrl-X)*  0..31  0..1f */

	/* ^@ */      MARKVERT_ABBREV,
	/* ^a */      MOVESOL_ABBREV,
	/* ^b */      MARK_ABBREV,
	/* ^c */      COPY_ABBREV,
	/* ^d */ PICK(NEWDOC_ABBREV,       NULL),
	/* ^e */      MOVEEOL_ABBREV,
	/* ^f */      FIND_ABBREV,
	/* ^g */      REPEATLAST_ABBREV,

	/* ^h */      BACKSPACE_ABBREV,
	/* ^i */      NULL,
	/* ^j */      GOTOLINE_ABBREV,
	/* ^k */      EXEC_ABBREV,
	/* ^l */      REFRESH_ABBREV,
	/* ^m */      NULL,
	/* ^n */ PICK(NEXTPAGE_ABBREV,     PAGEDOWN_ABBREV),
	/* ^o */      OPEN_ABBREV,

	/* ^p */ PICK(PREVPAGE_ABBREV,     PAGEUP_ABBREV),
	/* ^q */      CLOSEDOC_ABBREV,
	/* ^r */      REPLACE_ABBREV,
	/* ^s */      SAVE_ABBREV,
	/* ^t */      RECORD_ABBREV,
	/* ^u */      UNDELLINE_ABBREV,
	/* ^v */      PASTE_ABBREV,
	/* ^w */      PASTEVERT_ABBREV,

	/* ^x */      CUT_ABBREV,
	/* ^y */      DELETELINE_ABBREV,
	/* ^z */      SUSPEND_ABBREV,
	/* ^[ */      ESCAPE_ABBREV,
	/* ^\ */      NULL,
	/* ^] */      MATCHBRACKET_ABBREV,
	/* ^^ */      ADJUSTVIEW_ABBREV,
	/* ^_ */      FINDREGEXP_ABBREV,
       
   /* These keys map to strings, not commands. 31..126  20..7e */
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* space ! " # $ % & ' ( ) * + , - . /  */
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /*     0 1 2 3 4 5 6 7 8 9 : ; < = > ?  */

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* @ A B C D E F G H I J K L M N O  */ 
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* P Q R S T U V W X Y Z [ \ ] ^ _  */
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* ` a b c d e f g h i j k l m n o  */
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,        /* p q r s t u v w x y z { | } ~    */
   DELETECHAR_ABBREV,                         /*  127  7f */

	/* Control-meta-letter bindings (Ctrl-Alt-X)  128..159 80..9f */

	/* Ctrl-Alt-@ */ NULL, 
	/* Ctrl-Alt-a */ MOVESOF_ABBREV, 
	/* Ctrl-Alt-b */ PREVWORD_ABBREV, 
	/* Ctrl-Alt-c */ CENTERVIEW_ABBREV, 
	/* Ctrl-Alt-d */ NEXTDOC_ABBREV, 
	/* Ctrl-Alt-e */ MOVEEOF_ABBREV, 
	/* Ctrl-Alt-f */ NEXTWORD_ABBREV, 
	/* Ctrl-Alt-g */ GOTOBOOKMARK_ABBREV, 
	/* Ctrl-Alt-h */ NULL, 
	/* Ctrl-Alt-i */ AUTOINDENT_ABBREV, 
	/* Ctrl-Alt-j */ GOTOCOLUMN_ABBREV, 
	/* Ctrl-Alt-k */ SETBOOKMARK_ABBREV, 
	/* Ctrl-Alt-l */ TOLOWER_ABBREV, 
	/* Ctrl-Alt-m */ PLAYONCE_ABBREV, 
	/* Ctrl-Alt-n */ OPENNEW_ABBREV, 
	/* Ctrl-Alt-o */ OPENCLIP_ABBREV,

	/* Ctrl-Alt-p */ PARAGRAPH_ABBREV, 
	/* Ctrl-Alt-q */ QUIT_ABBREV, 
	/* Ctrl-Alt-r */ REDO_ABBREV, 
	/* Ctrl-Alt-s */ SAVECLIP_ABBREV, 
	/* Ctrl-Alt-t */ THROUGH_ABBREV, 
	/* Ctrl-Alt-u */ UNDO_ABBREV, 
	/* Ctrl-Alt-v */ TOUPPER_ABBREV, 
	/* Ctrl-Alt-w */ WORDWRAP_ABBREV, 
	/* Ctrl-Alt-x */ EXIT_ABBREV, 
	/* Ctrl-Alt-y */ DELETEEOL_ABBREV, 
	/* Ctrl-Alt-z */ CRLF_ABBREV, 
	/* Ctrl-Alt-[ */ NULL, 
	/* Ctrl-Alt-\ */ NULL, 
	/* Ctrl-Alt-] */ NULL, 
	/* Ctrl-Alt-^ */ NULL,
	/* Ctrl-Alt-_ */ NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* 160..175  A0..AF */
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* 176..191  B0..BF */

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* 192..207  C0..CF */
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* 207..223  D0..DF */
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* 224..239  E0..EF */
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* 240..255  F0..FF */


	/* The following bindings are for the terminfo extended codes (see keycodes.h). */

	/* Cursor movement keys 256..271  100..10F */
	NULL, 
	LINEUP_ABBREV, 
	LINEDOWN_ABBREV, 
	MOVELEFT_ABBREV, 
	MOVERIGHT_ABBREV, 
	MOVEINCUP_ABBREV, 
	MOVEINCDOWN_ABBREV, 
	PICK(NEXTPAGE_ABBREV,PAGEDOWN_ABBREV),
	PICK(PREVPAGE_ABBREV,PAGEUP_ABBREV), 
	LINEDOWN_ABBREV, 
	LINEUP_ABBREV, 
	NULL, 
	NULL, 
	NULL, 
	NULL, 
	NULL,

	/* Editing keys   272..287   110..11F */
	DELETEEOL_ABBREV, 
	NULL, 
	BACKSPACE_ABBREV, 
	DELETELINE_ABBREV, 
	UNDELLINE_ABBREV, 
	DELETECHAR_ABBREV, 
	INSERT_ABBREV, 
	NULL,
	CLEAR_ABBREV, 
	NULL, 
	NULL, 
	NULL, 
	NULL, 
	NULL, 
	NULL, 
	NULL,

	/* Keypad keys and fake (simulated) menu key  288..303  120..12F */
	MOVESOF_ABBREV, 
	PREVPAGE_ABBREV, 
	TOGGLESEOL_ABBREV, 
	MOVEEOF_ABBREV, 
	NEXTPAGE_ABBREV, 
	EXEC_ABBREV, 
	NULL, 
	NULL,
	NULL, 
	NULL, 
	NULL, 
	NULL, 
	NULL, 
	NULL, 
	NULL, 
	NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* 304..319  130..13F */

	/* Function keys   320..335  140..14F  */
	/*  F0 */ ESCAPE_ABBREV, 
	/*  F1 */ ESCAPE_ABBREV, 
	/*  F2 */ NEXTDOC_ABBREV, 
	/*  F3 */ PREVDOC_ABBREV, 
	/*  F4 */ SELECTDOC_ABBREV, 
	/*  F5 */ UNDO_ABBREV, 
	/*  F6 */ REDO_ABBREV, 
	/*  F7 */ PREVWORD_ABBREV,
	/*  F8 */ NEXTWORD_ABBREV, 
	/*  F9 */ PLAYONCE_ABBREV, 
	/* F10 */ HELP_ABBREV, 
	/* F11 */ NULL,
	/* F12 */ NULL,
	/* F13 */ NULL,
	/* F14 */ NULL,
	/* F15 */ NULL,

	NULL,                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, DELETEPREVWORD_ABBREV,  /* 336..351  150..15F */
	DELETENEXTWORD_ABBREV, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,                   /* 352..367  160..16F */
	NULL,                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,                   /* 368..383  170..17F */

	/* Prefix-simulated META (ESC Ctrl-a)  384..416  180..1A0 */

	/* ESC Ctrl-@ */ NULL, 
	/* ESC Ctrl-a */ MOVESOF_ABBREV, 
	/* ESC Ctrl-b */ PREVWORD_ABBREV, 
	/* ESC Ctrl-c */ CENTERVIEW_ABBREV, 
	/* ESC Ctrl-d */ NEXTDOC_ABBREV, 
	/* ESC Ctrl-e */ MOVEEOF_ABBREV, 
	/* ESC Ctrl-f */ NEXTWORD_ABBREV, 
	/* ESC Ctrl-g */ GOTOBOOKMARK_ABBREV, 
	/* ESC Ctrl-h */ NULL, 
	/* ESC Ctrl-i */ AUTOINDENT_ABBREV, 
	/* ESC Ctrl-j */ GOTOCOLUMN_ABBREV, 
	/* ESC Ctrl-k */ SETBOOKMARK_ABBREV, 
	/* ESC Ctrl-l */ TOLOWER_ABBREV, 
	/* ESC Ctrl-m */ PLAYONCE_ABBREV, 
	/* ESC Ctrl-n */ OPENNEW_ABBREV, 
	/* ESC Ctrl-o */ OPENCLIP_ABBREV,
	
	/* ESC Ctrl-p */ PARAGRAPH_ABBREV, 
	/* ESC Ctrl-q */ QUIT_ABBREV, 
	/* ESC Ctrl-r */ REDO_ABBREV, 
	/* ESC Ctrl-s */ SAVECLIP_ABBREV, 
	/* ESC Ctrl-t */ THROUGH_ABBREV, 
	/* ESC Ctrl-u */ UNDO_ABBREV, 
	/* ESC Ctrl-v */ TOUPPER_ABBREV, 
	/* ESC Ctrl-w */ WORDWRAP_ABBREV, 
	/* ESC Ctrl-x */ EXIT_ABBREV, 
	/* ESC Ctrl-y */ DELETEEOL_ABBREV, 
	/* ESC Ctrl-z */ CRLF_ABBREV, 
	/* ESC Ctrl-[ */ NULL, 
	/* ESC Ctrl-\ */ NULL, 
	/* ESC Ctrl-] */ NULL, 
	/* ESC Ctrl-^ */ NULL, 
	/* ESC Ctrl-_ */ NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* 416..431  1A0..1AF */
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,  /* 432..447  1B0..1BF */

   /* Prefix-simulated META (ESC X)  448..479   1C0..1DF */
	/* ESC @ */ NULL, 
	/* ESC A */ MOVESOF_ABBREV, 
	/* ESC B */ PREVWORD_ABBREV, 
	/* ESC C */ CENTERVIEW_ABBREV, 
	/* ESC D */ NEXTDOC_ABBREV, 
	/* ESC E */ MOVEEOF_ABBREV, 
	/* ESC F */ NEXTWORD_ABBREV, 
	/* ESC G */ GOTOBOOKMARK_ABBREV, 
	/* ESC H */ NULL, 
	/* ESC I */ AUTOINDENT_ABBREV, 
	/* ESC J */ GOTOCOLUMN_ABBREV, 
	/* ESC K */ SETBOOKMARK_ABBREV, 
	/* ESC L */ TOLOWER_ABBREV, 
	/* ESC M */ PLAYONCE_ABBREV, 
	/* ESC N */ OPENNEW_ABBREV, 
	/* ESC O */ OPENCLIP_ABBREV,

	/* ESC P */ PARAGRAPH_ABBREV, 
	/* ESC Q */ QUIT_ABBREV, 
	/* ESC R */ REDO_ABBREV, 
	/* ESC S */ SAVECLIP_ABBREV, 
	/* ESC T */ THROUGH_ABBREV, 
	/* ESC U */ UNDO_ABBREV, 
	/* ESC V */ TOUPPER_ABBREV, 
	/* ESC W */ WORDWRAP_ABBREV, 
	/* ESC X */ EXIT_ABBREV, 
	/* ESC Y */ DELETEEOL_ABBREV, 
	/* ESC Z */ CRLF_ABBREV, 
	/* ESC [ */ NULL, 
	/* ESC \ */ NULL, 
	/* ESC ] */ NULL, 
	/* ESC ^ */ NULL, 
	/* ESC _ */ NULL,


   /* Prefix-simulated META (ESC X)  480..511  1E0..1FF */
	/* ESC @ */ NULL, 
	/* ESC a */ MOVESOF_ABBREV, 
	/* ESC b */ PREVWORD_ABBREV, 
	/* ESC c */ CENTERVIEW_ABBREV, 
	/* ESC d */ NEXTDOC_ABBREV, 
	/* ESC e */ MOVEEOF_ABBREV, 
	/* ESC f */ NEXTWORD_ABBREV, 
	/* ESC g */ GOTOBOOKMARK_ABBREV, 
	/* ESC h */ NULL, 
	/* ESC i */ AUTOINDENT_ABBREV, 
	/* ESC j */ GOTOCOLUMN_ABBREV, 
	/* ESC k */ SETBOOKMARK_ABBREV, 
	/* ESC l */ TOLOWER_ABBREV, 
	/* ESC m */ PLAYONCE_ABBREV, 
	/* ESC n */ OPENNEW_ABBREV, 
	/* ESC o */ OPENCLIP_ABBREV,

	/* ESC p */ PARAGRAPH_ABBREV, 
	/* ESC q */ QUIT_ABBREV, 
	/* ESC r */ REDO_ABBREV, 
	/* ESC s */ SAVECLIP_ABBREV, 
	/* ESC t */ THROUGH_ABBREV, 
	/* ESC u */ UNDO_ABBREV, 
	/* ESC v */ TOUPPER_ABBREV, 
	/* ESC w */ WORDWRAP_ABBREV, 
	/* ESC x */ EXIT_ABBREV, 
	/* ESC y */ DELETEEOL_ABBREV, 
	/* ESC z */ CRLF_ABBREV, 
	/* ESC [ */ NULL, 
	/* ESC \ */ NULL, 
	/* ESC ] */ NULL, 
	/* ESC ^ */ NULL,
	/* ESC _ */ NULL 

};



/* This vector holds, for each ISO-8859-1 key code, its input class. */

const input_class char_class[256] = {

	/* Control-letter classes */

	/* @ a b c d e f g h i j k l m n o */
	COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, TAB, COMMAND, COMMAND, COMMAND, RETURN, COMMAND, COMMAND,

	/* p q r s t u v w x y z [ \ ] ^ _ */
	COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND,

	ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA,
	ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA,

	ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA,
	ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA,
	ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA,
	ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, COMMAND,

	/* Control-meta-letter classes
	PORTABILITY PROBLEM: on some systems, these characters are printable. In this case,
	it is a good idea to define their type as ALPHA, so that you can type them in the
	text. They are COMMAND by default because this is what happens in ISO Latin 1. */

	/* @ a b c d e f g h i j k l m n o */
	COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND,

	/* p q r s t u v w x y z [ \ ] ^ _ */
	COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND, COMMAND,

	ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA,
	ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA,

	ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA,
	ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA,
	ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA,
	ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA
};


const char meta_prefixed[128][3] = {
	{ '\x1b', 0 },
	{ '\x1b', 1 },
	{ '\x1b', 2 },
	{ '\x1b', 3 },
	{ '\x1b', 4 },
	{ '\x1b', 5 },
	{ '\x1b', 6 },
	{ '\x1b', 7 },
	{ '\x1b', 8 },
	{ '\x1b', 9 },
	{ '\x1b', 10 },
	{ '\x1b', 11 },
	{ '\x1b', 12 },
	{ '\x1b', 13 },
	{ '\x1b', 14 },
	{ '\x1b', 15 },
	{ '\x1b', 16 },
	{ '\x1b', 17 },
	{ '\x1b', 18 },
	{ '\x1b', 19 },
	{ '\x1b', 20 },
	{ '\x1b', 21 },
	{ '\x1b', 22 },
	{ '\x1b', 23 },
	{ '\x1b', 24 },
	{ '\x1b', 25 },
	{ '\x1b', 26 },
	{ '\x1b', 27 },
	{ '\x1b', 28 },
	{ '\x1b', 29 },
	{ '\x1b', 30 },
	{ '\x1b', 31 },
	{ '\x1b', 32 },
	{ '\x1b', 33 },
	{ '\x1b', 34 },
	{ '\x1b', 35 },
	{ '\x1b', 36 },
	{ '\x1b', 37 },
	{ '\x1b', 38 },
	{ '\x1b', 39 },
	{ '\x1b', 40 },
	{ '\x1b', 41 },
	{ '\x1b', 42 },
	{ '\x1b', 43 },
	{ '\x1b', 44 },
	{ '\x1b', 45 },
	{ '\x1b', 46 },
	{ '\x1b', 47 },
	{ '\x1b', 48 },
	{ '\x1b', 49 },
	{ '\x1b', 50 },
	{ '\x1b', 51 },
	{ '\x1b', 52 },
	{ '\x1b', 53 },
	{ '\x1b', 54 },
	{ '\x1b', 55 },
	{ '\x1b', 56 },
	{ '\x1b', 57 },
	{ '\x1b', 58 },
	{ '\x1b', 59 },
	{ '\x1b', 60 },
	{ '\x1b', 61 },
	{ '\x1b', 62 },
	{ '\x1b', 63 },
	{ '\x1b', 64 },
	{ '\x1b', 65 },
	{ '\x1b', 66 },
	{ '\x1b', 67 },
	{ '\x1b', 68 },
	{ '\x1b', 69 },
	{ '\x1b', 70 },
	{ '\x1b', 71 },
	{ '\x1b', 72 },
	{ '\x1b', 73 },
	{ '\x1b', 74 },
	{ '\x1b', 75 },
	{ '\x1b', 76 },
	{ '\x1b', 77 },
	{ '\x1b', 78 },
	{ '\x1b', 79 },
	{ '\x1b', 80 },
	{ '\x1b', 81 },
	{ '\x1b', 82 },
	{ '\x1b', 83 },
	{ '\x1b', 84 },
	{ '\x1b', 85 },
	{ '\x1b', 86 },
	{ '\x1b', 87 },
	{ '\x1b', 88 },
	{ '\x1b', 89 },
	{ '\x1b', 90 },
	{ '\x1b', 91 },
	{ '\x1b', 92 },
	{ '\x1b', 93 },
	{ '\x1b', 94 },
	{ '\x1b', 95 },
	{ '\x1b', 96 },
	{ '\x1b', 97 },
	{ '\x1b', 98 },
	{ '\x1b', 99 },
	{ '\x1b', 100 },
	{ '\x1b', 101 },
	{ '\x1b', 102 },
	{ '\x1b', 103 },
	{ '\x1b', 104 },
	{ '\x1b', 105 },
	{ '\x1b', 106 },
	{ '\x1b', 107 },
	{ '\x1b', 108 },
	{ '\x1b', 109 },
	{ '\x1b', 110 },
	{ '\x1b', 111 },
	{ '\x1b', 112 },
	{ '\x1b', 113 },
	{ '\x1b', 114 },
	{ '\x1b', 115 },
	{ '\x1b', 116 },
	{ '\x1b', 117 },
	{ '\x1b', 118 },
	{ '\x1b', 119 },
	{ '\x1b', 120 },
	{ '\x1b', 121 },
	{ '\x1b', 122 },
	{ '\x1b', 123 },
	{ '\x1b', 124 },
	{ '\x1b', 125 },
	{ '\x1b', 126 },
	{ '\x1b', 127 }
};