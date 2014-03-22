#ifndef QKIDE_GLOBAL_H
#define QKIDE_GLOBAL_H

#include <QtGlobal>
#include <QFont>

class QString;

const QString SLASH = "/";
const QString QK_IDE_DOMAIN_STR = "qkthings.com";
const QString QK_IDE_NAME_STR = "qkide";
const QString QK_IDE_C_DEF_STR = "my_board.c";
const QString QK_IDE_H_DEF_STR = "my_board.h";

const QString EDITOR_FONT_NAME = "DejaVuSansMono";
const int     EDITOR_FONT_SIZE = 9;

const QString CTAGS_EXE = "/resources/tools/ctags/ctags";
const QString TOOLCHAIN_DIR = "/resources/embedded/toolchain";
const QString QKPROGRAM_DIR = "/resources/embedded/qkprogram";
const QString QKPROGRAM_INC_DIR = QKPROGRAM_DIR + "/include";
const QString QKPROGRAM_LIB_DIR = QKPROGRAM_DIR + "/lib";
const QString QKPROGRAM_DOC_DIR = QKPROGRAM_DIR + "/doc";
const QString TEMP_DIR = "/temp";
const QString TAGS_DIR = TEMP_DIR + "/tags";

#ifdef Q_OS_WIN
const QString GNUWIN_DIR = "/resources/gnuwin";
#endif

#endif // QKIDE_GLOBAL_H
